#pragma once

#include <wx/string.h>
#include <wx/statbmp.h>
#include <wx/menu.h>
#include <wx/cshelp.h>

class Item : public wxStaticBitmap
{
public:
	Item(wxWindow* parent);
	Item(wxWindow* parent, wxString type);
	Item(wxWindow* parent,int level, wxString type, wxString subtype, wxString quality);
	wxString GetName() const;
	int GetLevel() const;
	wxString GetType() const;
	wxString GetSubType() const;
	wxString GetQuality() const;
	int GetCost() const;
	wxBitmap GetBitmap() const;

	void CreateInfo();

	void ShowMenu(wxMouseEvent& event);
	void ShowInfo(wxMouseEvent& event);
	void Shift(wxMouseEvent& event);
private:
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