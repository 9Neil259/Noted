#ifndef DELETEFRAME_HPP
#define DELETEFRAME_HPP

#include <wx/wx.h>
#include <sqlite3.h>

class DeleteFrame : public wxFrame
{
public:
	DeleteFrame(const wxString& title);
private:
    void OnDeleteButtonClicked(wxCommandEvent& event);

    wxTextCtrl* m_textCtrl1;
    wxTextCtrl* m_textCtrl2;
    wxTextCtrl* m_textCtrl3;
    wxButton* m_deleteButton;
    sqlite3* m_db;

};

#endif // DELETEFRAME_HPP