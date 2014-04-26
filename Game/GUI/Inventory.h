#pragma once

#include <wx/dialog.h>
#include <wx/sizer.h>
#include <vector>
#include <wx/menu.h>

#include "../Core/Item.h"

class Inventory: public wxDialog
{
public:
	Inventory(wxWindow* parent);
	void OnPaint(wxPaintEvent& event);
	
	std::vector <wxString> GetItems() const;
	wxString GetItem(int i) const;
private:
	std::vector <Item*> items;
	std::vector <wxString> names;

};