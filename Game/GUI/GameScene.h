#pragma once
#include <wx/panel.h>
#include "../Core/Level.h"
#include "../Core/Player.h"

class GameScene: public wxPanel
{
public:
	GameScene(wxWindow* parent);
	void OnPaint(wxPaintEvent& event);
	void OnPressKeyboard(wxKeyEvent& event);
	bool MovingPlayer();
	wxPoint FindStartPositionForPlayer();
	void CreateImage();
	Player* GetPlayer() const;
private:
	Level* level;
	int starti;
	int startj;
	int step;

	Player* player;

	wxBitmap* image;
};