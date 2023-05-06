#include "SearchFrame.hpp"

SearchFrame::SearchFrame(const wxString& title)
    : wxFrame(nullptr, wxID_ANY, title)
{
    m_textCtrl1 = new wxTextCtrl(this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize);
    m_textCtrl2 = new wxTextCtrl(this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize);
    m_textCtrl3 = new wxTextCtrl(this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize);
    m_searchButton = new wxButton(this, wxID_ANY, wxT("Search"), wxDefaultPosition, wxDefaultSize);
    m_searchButton->Bind(wxEVT_BUTTON, &AnotherFrame::OnSearchButtonClicked, this);
    m_outputTextCtrl = new wxTextCtrl(this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize,
        wxTE_MULTILINE | wxTE_READONLY);

    wxBoxSizer* sizer = new wxBoxSizer(wxVERTICAL);
    sizer->Add(m_textCtrl1, wxSizerFlags().Border(wxALL, 10).Expand());
    sizer->Add(m_textCtrl2, wxSizerFlags().Border(wxALL, 10).Expand());
    sizer->Add(m_textCtrl3, wxSizerFlags().Border(wxALL, 10).Expand());
    sizer->Add(m_searchButton, wxSizerFlags().Border(wxALL, 10).Center());
    sizer->Add(m_outputTextCtrl, wxSizerFlags().Border(wxALL, 10).Expand());

    SetSizerAndFit(sizer);

    sqlite3_open("example.db", &m_db);
}

void SearchFrame::OnSearchButtonClicked(wxCommandEvent& event)
{
    wxString data1 = m_textCtrl1->GetValue();
    wxString data2 = m_textCtrl2->GetValue();
    wxString data3 = m_textCtrl3->GetValue();

    wxString query = wxString::Format("SELECT * FROM data WHERE value1='%s' AND value2='%s' AND value3='%s'",
        data1, data2, data3);
    sqlite3_stmt* stmt;
    sqlite3_prepare_v2(m_db, query, -1, &stmt, nullptr);

    wxString output;
    while (sqlite3_step(stmt) == SQLITE_ROW)
    {
        int id = sqlite3_column_int(stmt, 0);
        const unsigned char* value1 = sqlite3_column_text(stmt, 1);
        const unsigned char* value2 = sqlite3_column_text(stmt, 2);
        const unsigned char* value3 = sqlite3_column_text(stmt, 3);

        output += wxString::Format("ID: %d\nValue1: %s\nValue2: %s\nValue3: %s\n\n",
            id, value1, value2, value3);
    }

    sqlite3_finalize(stmt);

    m_outputTextCtrl->SetValue(output);
}

SearchFrame::~SearchFrame()
{
    sqlite3_close(m_db);
}
}