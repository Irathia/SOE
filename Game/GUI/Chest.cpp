#include "Chest.h"

Chest::Chest(wxWindow* parent, Inventory* inv):wxDialog(parent,wxID_ANY,"Chest")
{
	this->inv = inv;
	//invItems = inv->GetItems();
	for (int i = 0; i < 4; i++)
	{
		if (rand()%3 == 0)
		{
			Item* it = new Item(this,"Empty",true);
			chestItems.push_back(it);
		}
		else
		{
			Item* it = new Item(this,true);
			chestItems.push_back(it);
		}
	}
	this->Connect(wxEVT_PAINT, wxPaintEventHandler(Chest::OnPaint));
}

void Chest::OnPaint(wxPaintEvent& event)
{
	wxGridSizer* g = new wxGridSizer(2,2,0,0);
	g->Clear();
	for (int i = 0; i < 4; i++)
	{
		g->Add(chestItems[i],1,wxALL|wxEXPAND,5);
		chestItems[i]->Show();
	}
	SetSizer(g);
	//Fit();
	Layout();
}

void Chest::Shift(int id)
{
	int a = -1;
	for(int i = 0; i < 4; i++)
	{
		if (id == chestItems.at(i)->GetId())
		{
			a = i;
			break;
		}
	}
	if (a != -1)
	{
		if (inv->AddItem(chestItems.at(a)) == false)
			return;
		chestItems.at(a)->SetType("Empty");
		this->Refresh();
	}
}