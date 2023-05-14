#ifndef MAINFRAME_HPP
#define MAINFRAME_HPP

#include "AddFrame.hpp"
#include "DeleteFrame.hpp"
#include "SearchFrame.hpp"
#include <wx/wx.h>

class MainFrame : public wxFrame
{
public:
    MainFrame(const wxString& title);

private:
    void OnButtonAddClicked(wxCommandEvent& event);
    void OnButtonDeleteClicked(wxCommandEvent& event);
    void OnButtonSearchClicked(wxCommandEvent& event);

    wxButton* m_buttonadd;
    wxButton* m_buttondelete;
    wxButton* m_buttonsearch;
};

#endif // MAINFRAME_HPP
