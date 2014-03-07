#pragma once

#include <wx/wx.h>
#include <wx/dialog.h>
#include <string>
#include <wx/panel.h>
#include "GameScene.h"
#include "../Core/Player.h"
#include "Inventory.h"
class GameScene;
class Model;

using namespace std;

class Game : public wxFrame
{
public:
	Game(wxFrame* parent, string name);

	void OnPaint(wxPaintEvent& event);
	void OnPressKeyboard(wxKeyEvent& event);
	void WeAreDead();
private:
	Model* model;

    GameScene* GameW;
    wxPanel* Map;
    wxPanel* Info;
    wxPanel* Task;
    wxPanel* Inv;
    wxPanel* Magic;

	wxStaticBitmap* Icon;
	wxStaticBitmap* LVL;
	string name;
	wxStaticText* Name;
	wxStaticText* TextHealth;
	wxStaticText* TextMana;
	wxGauge* Exp;
	wxGauge* Health;
	wxGauge* Mana;

	Inventory* inv;


	DECLARE_EVENT_TABLE()
};