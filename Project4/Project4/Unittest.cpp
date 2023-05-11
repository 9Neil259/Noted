#include <cppunit/extensions/HelperMacros.h>

// Include the necessary headers for the MainFrame and wxWidgets
#include "MainFrame.hpp"
#include <wx/app.h>
#include <wx/event.h>

// Define a TestFixture for the MainFrame class
class MainFrameTest : public CppUnit::TestFixture
{
    CPPUNIT_TEST_SUITE(MainFrameTest);
    CPPUNIT_TEST(testSearchButtonClicked);
    CPPUNIT_TEST_SUITE_END();

public:
    void testSearchButtonClicked()
    {
        // Create a wxApp instance
        wxApp* app = new wxApp();

        // Initialize the wxWidgets framework
        wxApp::SetInstance(app);
        wxEntryStart(0, nullptr);

        // Create an instance of MainFrame
        MainFrame* frame = new MainFrame(wxT("Test Frame"));
        frame->Show();

        // Simulate button click event
        wxCommandEvent event(wxEVT_BUTTON, frame->GetSearchButton()->GetId());
        frame->OnSearchButtonClicked(event);

        // Ensure that the output text control contains the expected output
        wxString expectedOutput = "ID: 1\nValue1: Test1\nValue2: Test2\nValue3: Test3\n\n";
        CPPUNIT_ASSERT_EQUAL(expectedOutput, frame->GetOutputTextCtrl()->GetValue());

        // Clean up
        frame->Destroy();
        wxEntryCleanup();
        delete app;
    }
};

// Register the test suite
CPPUNIT_TEST_SUITE_REGISTRATION(MainFrameTest);
