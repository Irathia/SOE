#pragma once
#include <wx/panel.h>
#include "../Core/Level.h"

class GameScene: public wxPanel
{
public:
	GameScene(wxWindow* parent);
	void DrawScene(int x, int y, int m, int n);
	void OnPaint(wxPaintEvent& event);
	void OnPressKeyboard(wxKeyEvent& event);
private:
	Level* level;
	int starti;
	int startj;
	int pointPX;
	int pointPY;
	int step;
};