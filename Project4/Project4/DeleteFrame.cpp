#include "DeleteFrame.hpp"

DeleteFrame::DeleteFrame(const wxString& title)
    : wxFrame(nullptr, wxID_ANY, title)
{

        m_textCtrl1 = new wxTextCtrl(this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize);
        m_textCtrl2 = new wxTextCtrl(this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize);
        m_textCtrl3 = new wxTextCtrl(this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize);
        m_deleteButton = new wxButton(this, wxID_ANY, wxT("Löschen"), wxDefaultPosition, wxDefaultSize);
        m_deleteButton->Bind(wxEVT_BUTTON, &DeleteFrame::OnDeleteButtonClicked, this);

        wxBoxSizer* sizer = new wxBoxSizer(wxVERTICAL);
        sizer->Add(m_textCtrl1, wxSizerFlags().Border(wxALL, 10).Expand());
        sizer->Add(m_textCtrl2, wxSizerFlags().Border(wxALL, 10).Expand());
        sizer->Add(m_textCtrl3, wxSizerFlags().Border(wxALL, 10).Expand());
        sizer->Add(m_deleteButton, wxSizerFlags().Border(wxALL, 10).Center());

        SetSizerAndFit(sizer);

        sqlite3_open("example.db", &m_db);
    }

    void DeleteFrame::OnDeleteButtonClicked(wxCommandEvent & event)
    {
        wxString data1 = m_textCtrl1->GetValue();
        wxString data2 = m_textCtrl2->GetValue();
        wxString data3 = m_textCtrl3->GetValue();

        wxString query = wxString::Format("DELETE FROM data WHERE value1='%s' AND value2='%s' AND value3='%s'",
            data1, data2, data3);

        sqlite3_exec(m_db, query, nullptr, nullptr, nullptr);

        m_textCtrl1->Clear();
        m_textCtrl2->Clear();
        m_textCtrl3->Clear();
    }
