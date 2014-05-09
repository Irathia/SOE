#pragma once

#include <wx/wx.h>
#include <wx/dialog.h>
#include <string>
#include <wx/panel.h>
#include "GameScenes/GameScene.h"
#include "GameScenes\Info.h"
#include "GameScenes\Rooms.h"
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
	void OpenChest();
	void PortalActivate(int nl);
	void TeleportToLevel(int nl);
private:
	Model* model;

    GameScene* GameW;
	//Chest* chest;
    wxPanel* Map;
    Info* info;
    Rooms* R1;
    Rooms* R2;
	Rooms* R3;
	string name;

	Inventory* inv;
	Characteristic* chs;

	/*int lvlc;
	int expc;
	int manac;
	int healthc;*/
	DECLARE_EVENT_TABLE()
};