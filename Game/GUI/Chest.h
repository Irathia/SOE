#pragma once
#include <vector>
#include <wx/dialog.h>
#include "../Core/Item.h"

class Chest: public wxDialog
{
	public:
	Chest(wxWindow* parent);
	void OnPaint(wxPaintEvent& event);
	
	//std::vector <wxString> GetItems() const;
	//wxString GetItem(int i) const;
private:
	std::vector <Item*> items;

	std::vector <Item*> chestItems;
};