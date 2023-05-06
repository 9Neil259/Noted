#include "App.h"

#include <wx/wx.h>

#include "MainFrame.hpp"

bool App::OnInit() {
    MainFrame* mainFrame = new MainFrame("Hauptfenster");
    mainFrame->Show();
    return true;
}

wxIMPLEMENT_APP(App);