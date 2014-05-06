#include "Inventory.h"

Inventory::Inventory(wxWindow* parent, Player* player):wxDialog(parent,wxID_ANY,"Inventory")
{
	this->player = player;
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
		items.erase(items.begin()+j);
		items.push_back(it);
		return true;
	}
	else
		return false;
	
}

void Inventory::Delete(int id)
{
	int a = -1;
	for(int i = 0; i < 25; i++)
	{
		if (id == items.at(i)->GetId())
		{
			a = i;
			break;
		}
	}
	if (a != -1)
	{
		items.at(a)->SetType("Empty");
		this->Refresh();
	}
}

void Inventory::Use(int id)
{
	
	int a = -1;
	for(int i = 0; i < 25; i++)
	{
		if (id == items.at(i)->GetId())
		{
			a = i;
			break;
		}
	}
	if (a != -1)
	{
		if (items[a]->GetType() == "Other")
		{
			if (items[a]->GetSubType() == "Mana potion")
			{
				player->ManaUp(50);
				items.at(a)->SetType("Empty");
			}
			if (items[a]->GetSubType() == "Health potion")
			{
				player->HealthUp(100);
				items.at(a)->SetType("Empty");
			}
			if (items[a]->GetSubType() == "Scroll")
			{
				//player->Teleport();
				items.at(a)->SetType("Empty");
			}
		}
		if (items[a]->GetType() == "Apparel")
		{
			
			if (items[a]->GetSubType() == "Helm")
			{
				if (items[a]->GetBackgroundColour() == *wxYELLOW)
				{
					items[a]->SetBackgroundColour(*wxBLACK);
					player->Quality(items[a]->GetQuality(),false);
					this->Refresh();
					//quality-
					return;
				}
				int b = -1;
				for(int i = 0; i < 25; i++)
				{
					if (items[i]->GetSubType() == "Helm" && items[i]->GetId() != id && items[i]->GetBackgroundColour() == *wxYELLOW)
					{
						b = i;
						break;
					}
				}
				if (b == -1)
				{
					items[a]->SetBackgroundColour(*wxYELLOW);
					player->Quality(items[a]->GetQuality(),true);
					//quality+
				}
				else
				{
					items[b]->SetBackgroundColour(*wxBLACK);
					player->Quality(items[b]->GetQuality(),false);
					//quality-
					items[a]->SetBackgroundColour(*wxYELLOW);
					player->Quality(items[a]->GetQuality(),true);
					//quality+
				}
			}
			if (items[a]->GetSubType() == "Mail")
			{
				if (items[a]->GetBackgroundColour() == *wxYELLOW)
				{
					items[a]->SetBackgroundColour(*wxBLACK);
					player->Quality(items[a]->GetQuality(),false);
					this->Refresh();
					//quality-
					return;
				}
				int b = -1;
				for(int i = 0; i < 25; i++)
				{
					if (items[i]->GetSubType() == "Mail" && items[i]->GetId() != id && items[i]->GetBackgroundColour() == *wxYELLOW)
					{
						b = i;
						break;
					}
				}
				if (b == -1)
				{
					items[a]->SetBackgroundColour(*wxYELLOW);
					player->Quality(items[a]->GetQuality(),true);
					//quality+
				}
				else
				{
					items[b]->SetBackgroundColour(*wxBLACK);
					player->Quality(items[b]->GetQuality(),false);
					//quality-
					items[a]->SetBackgroundColour(*wxYELLOW);
					player->Quality(items[a]->GetQuality(),true);
					//quality+
				}
			}
			if (items[a]->GetSubType() == "Pants")
			{
				if (items[a]->GetBackgroundColour() == *wxYELLOW)
				{
					items[a]->SetBackgroundColour(*wxBLACK);
					player->Quality(items[a]->GetQuality(),false);
					this->Refresh();
					//quality-
					return;
				}
				int b = -1;
				for(int i = 0; i < 25; i++)
				{
					if (items[i]->GetSubType() == "Pants" && items[i]->GetId() != id && items[i]->GetBackgroundColour() == *wxYELLOW)
					{
						b = i;
						break;
					}
				}
				if (b == -1)
				{
					items[a]->SetBackgroundColour(*wxYELLOW);
					player->Quality(items[a]->GetQuality(),true);
					//quality+
				}
				else
				{
					items[b]->SetBackgroundColour(*wxBLACK);
					player->Quality(items[b]->GetQuality(),false);
					//quality-
					items[a]->SetBackgroundColour(*wxYELLOW);
					player->Quality(items[a]->GetQuality(),true);
					//quality+
				}
			}
			if (items[a]->GetSubType() == "Boots")
			{
				if (items[a]->GetBackgroundColour() == *wxYELLOW)
				{
					items[a]->SetBackgroundColour(*wxBLACK);
					player->Quality(items[a]->GetQuality(),false);
					this->Refresh();
					//quality-
					return;
				}
				int b = -1;
				for(int i = 0; i < 25; i++)
				{
					if (items[i]->GetSubType() == "Boots" && items[i]->GetId() != id && items[i]->GetBackgroundColour() == *wxYELLOW)
					{
						b = i;
						break;
					}
				}
				if (b == -1)
				{
					items[a]->SetBackgroundColour(*wxYELLOW);
					player->Quality(items[a]->GetQuality(),true);
					//quality+
				}
				else
				{
					items[b]->SetBackgroundColour(*wxBLACK);
					player->Quality(items[b]->GetQuality(),false);
					//quality-
					items[a]->SetBackgroundColour(*wxYELLOW);
					player->Quality(items[a]->GetQuality(),true);
					//quality+
				}
			}
		}
		if (items[a]->GetType() == "Accassory")
		{
			if (items[a]->GetSubType() == "Ring")
			{
				if (items[a]->GetBackgroundColour() == *wxYELLOW)
				{
					items[a]->SetBackgroundColour(*wxBLACK);
					player->Quality(items[a]->GetQuality(),false);
					this->Refresh();
					
					//quality-
					return;
				}
				int b = -1;
				int count = 0;
				for(int i = 0; i < 25; i++)
				{
					if (items[i]->GetSubType() == "Ring" && items[i]->GetId() != id && items[i]->GetBackgroundColour() == *wxYELLOW)
					{
						count++;
						if (count == 2)
						{
							b = i;
							break;
						}
					}
				}
				if (b == -1)
				{
					items[a]->SetBackgroundColour(*wxYELLOW);
					player->Quality(items[a]->GetQuality(),true);
					//quality+
				}
				else
				{
					items[b]->SetBackgroundColour(*wxBLACK);
					player->Quality(items[b]->GetQuality(),false);
					//quality-
					items[a]->SetBackgroundColour(*wxYELLOW);
					player->Quality(items[a]->GetQuality(),true);
					//quality+
				}
			}

			if (items[a]->GetSubType() == "Gloves")
			{
				if (items[a]->GetBackgroundColour() == *wxYELLOW)
				{
					items[a]->SetBackgroundColour(*wxBLACK);
					player->Quality(items[a]->GetQuality(),false);
					this->Refresh();
					//quality-
					return;
				}
				int b = -1;
				for(int i = 0; i < 25; i++)
				{
					if (items[i]->GetSubType() == "Gloves" && items[i]->GetId() != id && items[i]->GetBackgroundColour() == *wxYELLOW)
					{
						b = i;
						break;
					}
				}
				if (b == -1)
				{
					items[a]->SetBackgroundColour(*wxYELLOW);
					player->Quality(items[a]->GetQuality(),true);
					//quality+
				}
				else
				{
					items[b]->SetBackgroundColour(*wxBLACK);
					player->Quality(items[b]->GetQuality(),false);
					//quality-
					items[a]->SetBackgroundColour(*wxYELLOW);
					player->Quality(items[a]->GetQuality(),true);
					//quality+
				}
			}
		}
		
		this->Refresh();
	}
}
std::vector <Item*> Inventory::GetItems() const
{
	return items;
}

wxString Inventory::GetItem(int i) const
{
	return names[i];
}
