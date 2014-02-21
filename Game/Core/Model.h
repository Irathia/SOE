#pragma once

#include <wx/bitmap.h>
#include <wx/timer.h>
#include <vector>
#include "Level.h"
#include "Player.h"
#include "Monster.h"

using namespace std;

class Model : public wxEvtHandler
{
public:
	Model();
	wxBitmap GetImage() const;
	wxPoint FindPositionForPlayer(bool direction);//0 - from top, 1 - from bottom
	void SetSize(wxSize size);
	wxPoint FindStartForImage() const;
	void update(wxPoint point, wxBitmap set);
	void CreateImage();
	void OnPressKeyboard(int key);
	wxBitmap CreateSubImage(wxPoint start, wxPoint end);
	void OnTimer(wxTimerEvent& event);
private:
	wxBitmap* img;
	
	vector <Level*> levels;
	vector <Monster*> monsters;
	Player* player;
	int currentLevel;

	wxSize size;
	wxTimer* timer;

	int counter;
};