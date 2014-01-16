#pragma once

#include <wx/wx.h>
#include <wx/frame.h>
#include <string>
#include <wx/panel.h>

using namespace std;

class Game : public wxFrame
{
public:
	Game(wxFrame* parent, string name);

	void OnPaint(wxPaintEvent& event);
	void OnPressKeyboard(wxKeyEvent& event);
private:
	/*wxPanel* gameWindow;
	wxPanel* mapOfDange;*/

        wxPanel* GameW;
        wxPanel* Map;
        wxPanel* Info;
        wxPanel* Task;
        wxPanel* Inv;
        wxPanel* Magic;

		wxStaticBitmap* Icon;
		wxStaticBitmap* LVL;
		//wxPanel* Icon;
		//wxPanel* LVL;
		wxBitmap* bitmap;
		string name;
		wxStaticText* Name;
		wxStaticText* TextHealth;
		wxStaticText* TextMana;
		wxGauge* Exp;
		wxGauge* Health;
		wxGauge* Mana;
};