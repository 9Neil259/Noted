#ifndef SEARCHFRAME_HPP
#define SEARCHFRAME_HPP

#include <wx/wx.h>
#include <sqlite3.h>

class SearchFrame : public wxFrame
{
public:
    SearchFrame(const wxString& title);
    ~SearchFrame();
private:
    void OnSearchButtonClicked(wxCommandEvent& event);

    wxTextCtrl* m_textCtrl1;
    wxTextCtrl* m_textCtrl2;
    wxTextCtrl* m_textCtrl3;
    wxButton* m_searchButton;
    wxTextCtrl* m_outputTextCtrl;
    sqlite3* m_db;
};

#endif // SEARCHFRAME_HPP
