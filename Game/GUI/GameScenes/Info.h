#pragma once

#include <wx/panel.h>
#include <wx/statbmp.h>
#include <wx/stattext.h>
#include "../../Core/Player.h"

class Info: public wxPanel
{
public:
	Info(wxWindow* parent, Player* player, wxString name);
	void OnPaint(wxPaintEvent& event);
	bool Information();
private:
	Player* player;
	wxString name;

	wxStaticBitmap* Icon;
	wxStaticBitmap* LVL;
	wxStaticText* Name;
	wxStaticText* TextHealth;
	wxStaticText* TextMana;
	wxStaticBitmap* Exp;
	wxStaticBitmap* Health;
	wxStaticBitmap* Mana;
	wxStaticText* t_Exp;
	wxStaticText* t_Health;
	wxStaticText* t_Mana;

	int lvlc;
	int expc;
	int manac;
	int healthc;

};