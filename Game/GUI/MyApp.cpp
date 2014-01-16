#include "MyApp.h"
#include "MainWindow.h"

IMPLEMENT_APP(MyApp)

bool MyApp::OnInit()
{

	MainWindow* mw = new MainWindow("Text/English.lng");
	return true;
}
