#include "AddFrame.hpp"

AddFrame::AddFrame(const wxString& title)
    : wxFrame(nullptr, wxID_ANY, title)
{
    m_textCtrl1 = new wxTextCtrl(this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize);
    m_textCtrl2 = new wxTextCtrl(this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize);
    m_textCtrl3 = new wxTextCtrl(this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize);
    m_saveButton = new wxButton(this, wxID_ANY, wxT("Speichern"), wxDefaultPosition, wxDefaultSize);
    m_saveButton->Bind(wxEVT_BUTTON, &AddFrame::OnSaveButtonClicked, this);

    wxBoxSizer* sizer = new wxBoxSizer(wxVERTICAL);
    sizer->Add(m_textCtrl1, wxSizerFlags().Border(wxALL, 10).Expand());
    sizer->Add(m_textCtrl2, wxSizerFlags().Border(wxALL, 10).Expand());
    sizer->Add(m_textCtrl3, wxSizerFlags().Border(wxALL, 10).Expand());
    sizer->Add(m_saveButton, wxSizerFlags().Border(wxALL, 10).Center());

    SetSizerAndFit(sizer);

    sqlite3_open("example.db", &m_db);
    sqlite3_exec(m_db, "CREATE TABLE IF NOT EXISTS data (id INTEGER PRIMARY KEY, value1 TEXT, value2 TEXT, value3 TEXT)", nullptr, nullptr, nullptr);
}

void AddFrame::OnSaveButtonClicked(wxCommandEvent& event)
{
    wxString data1 = m_textCtrl1->GetValue();
    wxString data2 = m_textCtrl2->GetValue();
    wxString data3 = m_textCtrl3->GetValue();

    sqlite3_stmt* stmt;
    sqlite3_prepare_v2(m_db, "INSERT INTO data (value1, value2, value3) VALUES (?, ?, ?)", -1, &stmt, nullptr);
    sqlite3_bind_text(stmt, 1, data1.ToUTF8().data(), -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 2, data2.ToUTF8().data(), -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 3, data3.ToUTF8().data(), -1, SQLITE_STATIC);
    sqlite3_step(stmt);
    sqlite3_finalize(stmt);

    m_textCtrl1->Clear();
    m_textCtrl2->Clear();
    m_textCtrl3->Clear();
}


