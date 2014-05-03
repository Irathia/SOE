#pragma once
#include <vector>
#include <wx/dialog.h>
#include "../Core/Item.h"
#include "Inventory.h"
class Item;
class Inventory;
class Chest: public wxDialog
{
	public:
	Chest(wxWindow* parent, Inventory* inv);
	void OnPaint(wxPaintEvent& event);
	
	void Shift(int id);
	//std::vector <wxString> GetItems() const;
	//wxString GetItem(int i) const;
private:

	Inventory* inv;
	std::vector <Item*> chestItems;
};