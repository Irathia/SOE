#pragma once
#include <wx/wx.h>
#include <wx/frame.h>
#include <wx/button.h>
#include <wx/bitmap.h>
#include <string>
#include <wx/dcclient.h>
#include "../../Resource/User.h"
#include "Game.h"

using namespace std;

class MainWindow : public wxFrame
{
public:
	MainWindow(string name);

	void OnButtonNewGame(wxCommandEvent& event);
	void OnButtonLoadGame(wxCommandEvent& event);
	void OnButtonSettings(wxCommandEvent& event);
	void OnButtonExit(wxCommandEvent& event);
	void OnPaint(wxPaintEvent& event);



	
private:
	int height;
	int wight;
	string name;
	USERS* users;
	
	Game* newGame;

	DECLARE_EVENT_TABLE()
};

