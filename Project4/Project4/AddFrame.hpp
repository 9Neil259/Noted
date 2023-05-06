#ifndef ADDFRAME_HPP
#define ADDFRAME_HPP

#include <wx/wx.h>
#include <sqlite3.h>

class AddFrame : public wxFrame
{
public:
    AddFrame(const wxString& title);

private:
    void OnSaveButtonClicked(wxCommandEvent& event);

    wxTextCtrl* m_textCtrl1;
    wxTextCtrl* m_textCtrl2;
    wxTextCtrl* m_textCtrl3;
    wxButton* m_saveButton;
    sqlite3* m_db;
};

#endif // ADDFRAME_HPP

