#ifndef NOTED_HPP
#define NOTED_HPP

#include <wx/wx.h>
#include <sqlite3.h>
class NotedFrame : public wxFrame
{
public:
    NotedFrame(const wxString& title, const wxPoint& pos, const wxSize& size);
    NotedFrame(const wxString& title)
        : wxFrame(nullptr, wxID_ANY, title)
        , m_textCtrl(new wxTextCtrl(this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize(150, -1)))
    {
        auto button = new wxButton(this, wxID_ANY, wxT("Speichern"), wxDefaultPosition, wxDefaultSize);
        button->Bind(wxEVT_BUTTON, &MyFrame::OnSave, this);

        auto sizer = new wxBoxSizer(wxVERTICAL);
        sizer->Add(m_textCtrl, wxSizerFlags().Border(wxALL, 10).Expand());
        sizer->Add(button, wxSizerFlags().Border(wxALL, 10).Center());

        SetSizerAndFit(sizer);
    }

private:
    void OnSave(wxCommandEvent& event)
    {
        wxString data = m_textCtrl->GetValue();

        sqlite3* db;
        sqlite3_open("example.db", &db);
        sqlite3_exec(db, "CREATE TABLE IF NOT EXISTS data (id INTEGER PRIMARY KEY, value TEXT)", nullptr, nullptr, nullptr);
        sqlite3_stmt* stmt;
        sqlite3_prepare_v2(db, "INSERT INTO data (value) VALUES (?)", -1, &stmt, nullptr);
        sqlite3_bind_text(stmt, 1, data.ToUTF8().data(), -1, SQLITE_STATIC);
        sqlite3_step(stmt);
        sqlite3_finalize(stmt);
        sqlite3_close(db);

        m_textCtrl->Clear();
    }

    wxTextCtrl* m_textCtrl;

    void OnButtonPress(wxCommandEvent& event);

    wxTextCtrl* m_display;
};

class MainFrame : public wxFrame {
public:
    MainFrame(const wxString& title, const wxPoint& pos, const wxSize& size);
private:

    void OnButtonPress(wxCommandEvent& event);

};

#endif // NOTED_HPP
