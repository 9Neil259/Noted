#ifndef MAINFRAME_HPP
#define MAINFRAME_HPP

#include "AnotherFrame.hpp"
#include "ThirdFrame.hpp"
#include <wx/wx.h>

class MainFrame : public wxFrame
{
public:
    MainFrame(const wxString& title);

private:
    void OnButtonADDClicked(wxCommandEvent& event);
    void OnButtonDELETEClicked(wxCommandEvent& event);
    void OnButtonSEARCHClicked(wxCommandEvent& event);

    wxButton* m_buttonadd;
    wxButton* m_buttondelete;
    wxButton* m_buttonsearch;
};

#endif // MAINFRAME_HPP
