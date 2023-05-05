#include "App.h"

#include <wx/wx.h>

#include "Noted.hpp"

bool App::OnInit() {
	NotedFrame* notedFrame = new  NotedFrame("Noted");
	notedFrame->Show();
	return true;
}

wxIMPLEMENT_APP(App);