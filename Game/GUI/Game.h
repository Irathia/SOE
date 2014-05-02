#pragma once

#include <wx/wx.h>
#include <wx/dialog.h>
#include <string>
#include <wx/panel.h>
#include "GameScenes/GameScene.h"
#include "GameScenes\Info.h"
#include "GameScenes\FastItems.h"
#include "../Core/Player.h"
#include "Inventory.h"
#include "Characteristic.h"
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
	bool Information(int a = 0);
private:
	Model* model;

    GameScene* GameW;
    wxPanel* Map;
    Info* info;
    wxPanel* Task;
    FastItems* Inv;
    FastItems* Magic;
	string name;
	/*wxStaticBitmap* Icon;
	wxStaticBitmap* LVL;
	
	wxStaticText* Name;
	wxStaticText* TextHealth;
	wxStaticText* TextMana;
	wxStaticBitmap* Exp;
	wxStaticBitmap* Health;
	wxStaticBitmap* Mana;
	wxStaticText* t_Exp;
	wxStaticText* t_Health;
	wxStaticText* t_Mana;*/

	Inventory* inv;
	Characteristic* chs;

	/*int lvlc;
	int expc;
	int manac;
	int healthc;*/
	DECLARE_EVENT_TABLE()
};