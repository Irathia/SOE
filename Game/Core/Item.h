#pragma once

#include <wx/string.h>
#include <wx/statbmp.h>
#include <wx/menu.h>
#include <wx/cshelp.h>
#include "../GUI/Chest.h"
#include "../GUI/Inventory.h"
class Chest;
class Inventory;

class Item : public wxStaticBitmap
{
public:
	Item(wxWindow* parent, int inchest = false);
	Item(wxWindow* parent, wxString type, int inchest = false);
	Item(wxWindow* parent,int level, wxString type, wxString subtype, wxString quality, int inchest = false);
	wxString GetName() const;
	int GetLevel() const;
	wxString GetType() const;
	wxString GetSubType() const;
	wxString GetQuality() const;
	//int GetID() const;
	int GetCost() const;
	wxBitmap GetBitmap() const;

	void SetInChest();
	bool AmIInChest();

	void CreateInfo();

	void ShowMenu(wxMouseEvent& event);
	void ShowInfo(wxMouseEvent& event);
	void Shift(wxMouseEvent& event);
private:
//	static int ALL;
//	int ID;
	bool inchest;
	//Chest* chest;
	wxString name;
	int level;
	wxString type;
	wxString subtype;
	wxString quality;
	int cost;
	wxBitmap bmp;

	wxMenu* menu;
	wxMenu* info;

	DECLARE_EVENT_TABLE()
};

