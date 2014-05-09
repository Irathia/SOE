#include "MainWindow.h"
#include "DialogForNewGame.h"
#include "LoadGame.h"
//Language* language;
#include "../Core/Level.h"
#include <wx/imaglist.h>



MainWindow::MainWindow(string name) : wxFrame(NULL, 1, "Main Window", wxDefaultPosition, wxDefaultSize)
{
	
	this->Connect(wxEVT_PAINT, wxPaintEventHandler(MainWindow::OnPaint));
	//language = new Language(name);
	this->ShowFullScreen(true);
	this->GetSize(&height, &wight);
	users = new USERS;
	LoadUsers(users);
}


void MainWindow::OnPaint(wxPaintEvent& event)
{
	wxButton* newGame;
	wxButton* loadGame;
	wxButton* settings;
	wxButton* exit;
	wxBitmap* background;

	newGame = new wxButton(this, 2, "NEW GAME"/*language->getValue("newGameButton")*/ ,wxPoint(5*height/8, 11*wight/27),wxSize(height/4, 2*wight/27));
	loadGame = new wxButton(this, 3, "LOAD GAME"/*language->getValue("loadGameButton")*/ , wxPoint(5*height/8, 15*wight/27),wxSize(height/4, 2*wight/27));
	settings = new wxButton(this, 4, "INFORAMTION"/*language->getValue("settingsButton")*/ , wxPoint(5*height/8, 19*wight/27),wxSize(height/4, 2*wight/27));
	exit = new wxButton(this, 5, "EXIT"/*language->getValue("exitButton")*/ , wxPoint(5*height/8, 23*wight/27),wxSize(height/4, 2*wight/27));
	background = new wxBitmap(wight,height);
	background->LoadFile("Image/Background.bmp",wxBITMAP_TYPE_BMP);
	this->SetBackgroundColour(wxNullColour);
	wxPaintDC dc(this);
	dc.DrawBitmap(*background,0,0,false);
}
void MainWindow::OnButtonNewGame(wxCommandEvent& event)
{
	DialogForNewGame* dialog = new DialogForNewGame(this,users);

	int a = dialog->ShowModal();
	if (a  == 1)
	{
		name = dialog->GetNameOfUser();
		dialog->Close(true);
		AddUser(name,users);
		newGame = new Game(this, name);
		this->Hide();
	}
	dialog->Close(true);
}
void MainWindow::OnButtonLoadGame(wxCommandEvent& event)
{
	LoadGame* dialog = new LoadGame(this,users,wight,height);

	int a = dialog->ShowModal();
	if (a  == 1)
	{
		name = dialog->GetNameOfUser();
		newGame = new Game(this, name, true);
		this->Hide();

	}
	dialog->Close(true);
	
}
void MainWindow::OnButtonSettings(wxCommandEvent& event)
{

}
void MainWindow::OnButtonExit(wxCommandEvent& event)
{
	SaveUsers(users);
	wxMessageDialog* msg = new wxMessageDialog(this, "Exit"/*language->getValue("exitMessageDialogMessage")*/, "Do you want to exit?"/*language->getValue("exitMessageDialogTitle")*/, wxYES_NO);
	msg->SetYesNoLabels("Yes"/*language->getValue("exitMessageDialogYes")).c_str()*/, "No"/*(language->getValue("exitMessageDialogNo")).c_str()*/);
	int a = msg->ShowModal();
	if (a == wxID_YES)
		this->Close(true);

	msg->Close(true);
}


BEGIN_EVENT_TABLE(MainWindow, wxFrame)
	EVT_BUTTON   (2,        MainWindow::OnButtonNewGame)
	EVT_BUTTON   (3,        MainWindow::OnButtonLoadGame)
	EVT_BUTTON   (4,        MainWindow::OnButtonSettings)
	EVT_BUTTON   (5,        MainWindow::OnButtonExit)
END_EVENT_TABLE()