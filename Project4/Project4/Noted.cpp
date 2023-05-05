#include "Noted.hpp"
#include <wx/wx.h>


NotedFrame::NotedFrame(const wxString& title)
    : wxFrame(nullptr, wxID_ANY, title) {


}

void NotedFrame::OnButtonPress(wxCommandEvent& event)
{
    wxButton* button = dynamic_cast<wxButton*>(event.GetEventObject());

}


