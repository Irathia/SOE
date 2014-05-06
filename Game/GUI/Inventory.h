#pragma once

#include <wx/dialog.h>
#include <wx/sizer.h>
#include <vector>
#include <wx/menu.h>

#include "../Core/Item.h"
#include "../Core/Player.h"

class Item;
class Inventory: public wxDialog
{
public:
	Inventory(wxWindow* parent, Player* player);
	void OnPaint(wxPaintEvent& event);
	bool AddItem(Item* itm);
	std::vector <Item*> GetItems() const;
	wxString GetItem(int i) const;

	void Delete(int id);
	void Use(int id);
private:
	std::vector <Item*> items;
	std::vector <wxString> names;
	Player* player;
};