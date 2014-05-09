#pragma once

#include <wx/bitmap.h>
#include <wx/timer.h>
#include <wx/list.h>
#include <vector>
#include "Level.h"
#include "Player.h"
#include "Monster.h"
#include "../GUI/Game.h"
//#include "../GUI/Inventory.h"

class Game;

using namespace std;

class Model : public wxEvtHandler
{
public:
	Model(Game* game);
	wxBitmap GetImage() const;
	wxPoint FindPositionForPlayer(bool direction);//0 - from top, 1 - from bottom
	void SetSize(wxSize size);
	wxPoint FindStartForImage() const;
	void update(wxPoint point, wxBitmap set);
	void CreateImage(int a = 0);
	void OnPressKeyboard(int key);
	void GoToLevel(int value, bool teleport = false);
	wxBitmap CreateSubImage(wxPoint start, wxPoint end);
	void OnTimerMonster(wxTimerEvent& event);
	void OnTimerPlayer(wxTimerEvent& event);
	bool GetStatusOfPlayer() const;
	Player* GetPlayer() const;
private:
	wxBitmap* img;
	
	vector <Level*> levels;
	vector <Monster*> monsters;
	Player* player;
	int currentLevel;

	wxSize size;
	wxTimer* MonsterTimer;
	wxTimer* PlayerTimer;

	Game* game;
	

	int counter;

	wxDECLARE_EVENT_TABLE();
};