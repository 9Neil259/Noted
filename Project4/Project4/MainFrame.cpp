#include "MainFrame.hpp"

MainFrame::MainFrame(const wxString& title)
    : wxFrame(nullptr, wxID_ANY, title)
{
    m_buttonadd = new wxButton(this, wxID_ANY, wxT("Add"), wxDefaultPosition, wxDefaultSize);
    m_buttonadd->Bind(wxEVT_BUTTON, &MainFrame::OnButtonADDClicked, this);

    m_buttondelete = new wxButton(this, wxID_ANY, wxT("Delete"), wxDefaultPosition, wxDefaultSize);
    m_buttondelete->Bind(wxEVT_BUTTON, &MainFrame::OnButtonDELETEClicked, this);

    m_buttonsearch = new wxButton(this, wxID_ANY, wxT("Search"), wxDefaultPosition, wxDefaultSize);
    m_buttonsearch->Bind(wxEVT_BUTTON, &MainFrame::OnButtonSEARCHClicked, this);

    wxBoxSizer* sizer = new wxBoxSizer(wxVERTICAL);
    sizer->Add(m_buttonadd, wxSizerFlags().Border(wxALL, 10));
    sizer->Add(m_buttondelete, wxSizerFlags().Border(wxALL, 10));
    sizer->Add(m_buttonsearch, wxSizerFlags().Border(wxALL, 10));

    SetSizerAndFit(sizer);
}

void MainFrame::OnButtonADDClicked(wxCommandEvent& event)
{
    Hide();

    AddFrame* anotherFrame = new AddFrame("Add");
    addFrame->Show();
}

void MainFrame::OnButtonDELETEClicked(wxCommandEvent& event)
{
    Hide();

    DeleteFrame* deleteFrame = new DeleteFrame("Delete");
    deleteFrame->Show();
}

void MainFrame::OnButtonSEARCHClicked(wxCommandEvent& event)
{
    Hide();

    SearchFrame* SearchFrame = new SearchFrame("Search");
    SearchFrame->Show();
}
