#pragma once
#include <wx/dialog.h>
#include <wx/stattext.h>
#include "../Core/Player.h"

class Characteristic: public wxDialog
{
public:
	Characteristic(wxWindow* parent, Player* player);

	void OnPaint(wxPaintEvent& event);

	void ChangeHealth(wxSpinEvent& event);
	void ChangeMana(wxSpinEvent& event);
	void ChangeStrength(wxSpinEvent& event);
	void ChangeMagic(wxSpinEvent& event);
	void ChangeAgility(wxSpinEvent& event);
	void S(wxSpinEvent& event);

	/*void ChangeHealthUp(wxSpinEvent& event);
	void ChangeManaUp(wxSpinEvent& event);
	void ChangeStrengthUp(wxSpinEvent& event);
	void ChangeMagicUp(wxSpinEvent& event);
	void ChangeAgilityUp(wxSpinEvent& event);

	void ChangeHealthDown(wxSpinEvent& event);
	void ChangeManaDown(wxSpinEvent& event);
	void ChangeStrengthDown(wxSpinEvent& event);
	void ChangeMagicDown(wxSpinEvent& event);
	void ChangeAgilityDown(wxSpinEvent& event);*/

	void OnOkClick(wxCommandEvent& event);
private:
	wxStaticText* t_health;
	wxStaticText* t_mana;
    wxStaticText* t_strength;
    wxStaticText* t_magic;
	wxStaticText* t_agility;

	wxSpinCtrl* n_health;
    wxSpinCtrl* n_mana;
    wxSpinCtrl* n_strength;
    wxSpinCtrl* n_magic;
	wxSpinCtrl* n_agility;

    wxButton* Ok;    
    wxStaticText* t_text;
    wxStaticText* n_notUsed;

	Player* player;

	DECLARE_EVENT_TABLE()
};