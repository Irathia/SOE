#pragma once
#include <wx/panel.h>
#include <wx/timer.h>
#include "../Core/Model.h"

class GameScene: public wxPanel
{
public:
	GameScene(wxWindow* parent, Model* model);
	void OnPaint(wxPaintEvent& event);
	void OnPressKeyboard(wxKeyEvent& event);
	void OnEraseBackground(wxEraseEvent & event);
	void OnTimer(wxTimerEvent& event);
private:
	Model* model;
	wxBitmap* image;
	wxTimer timer;

	DECLARE_EVENT_TABLE()
};