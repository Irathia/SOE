#include "Inventory.h"

Inventory::Inventory(wxWindow* parent):wxDialog(parent,wxID_ANY,"Inventory")
{
	
	for (int i = 0; i < 25; i++)
	{
		Item* panel = new Item(this,"Empty");
		//panel->Hide();
		items.push_back(panel);
	}
	this->Connect(wxEVT_PAINT, wxPaintEventHandler(Inventory::OnPaint));
	//this->Connect(wxEVT_RIGHT_DOWN,wxMouseEventHandler(Inventory::ShowMenu));
	//this->Refresh();
}

void Inventory::OnPaint(wxPaintEvent& event)
{
	//this->ClearBackground();
	wxGridSizer* gridsizer = new wxGridSizer(5,5,0,0);
	//this->GetSizer()->Detach(true);

	//gridsizer->Clear();
	for (int i = 24; i >= 0; i--)
	{
		gridsizer->Add(items[i],1,wxALL|wxEXPAND,5);
		items[i]->Show();
	}
	SetSizer(gridsizer);
	Layout();
}
bool Inventory::AddItem(Item* itm)
{
	int j = -1;
	for(int i = 0; i < 25; i++)
	{
		if (items[i]->GetType() == "Empty")
		{
			j = i;
			break;
		}
	}
	if (j != -1)
	{
		Item* it = new Item(this,1,itm->GetType(),itm->GetSubType(),itm->GetQuality(),false);
		it->SetBitmap(itm->GetBitmap());
		//itm->SetParent(this);
		//itm->SetInChest();
		items.erase(items.begin()+j);
		items.push_back(it);
		//this->Refresh();
		return true;
	}
	else
		return false;
	
}
std::vector <Item*> Inventory::GetItems() const
{
	return items;
}

wxString Inventory::GetItem(int i) const
{
	return names[i];
}
