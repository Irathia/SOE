#pragma once

#include <wx/bitmap.h>
#include <vector>
#include "Level.h"
#include "Player.h"

using namespace std;

class Model
{
public:
	Model();
	wxBitmap* GetImage() const;
	wxPoint FindPositionForPlayer(bool direction);//0 - from top, 1 - from bottom
	void update(wxPoint point, wxBitmap set);
	void CreateImage();
	void OnPressKeyboard(int key);
	wxBitmap CreateSubImage(wxPoint start, wxPoint end);
private:
	wxBitmap* img;
	
	vector <Level*> levels;
	Player* player;
	int currentLevel;

};