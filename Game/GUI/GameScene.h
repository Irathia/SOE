#pragma once
#include <wx/panel.h>
#include "../Core/Level.h"

class GameScene: public wxPanel
{
public:
	GameScene(wxWindow* parent);
	void DrawScene(int x, int y, int m, int n);
	void OnPaint(wxPaintEvent& event);
private:
	Level* level;
};