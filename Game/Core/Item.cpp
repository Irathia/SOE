#include "Item.h"
//int Item::ALL = 0;
Item::Item(wxWindow* parent, int inchest):wxStaticBitmap(parent,wxID_ANY,wxNullBitmap)
{
	//ID = ALL;
	//ALL++;
	
	this->Hide();
	wxImage::AddHandler(new wxPNGHandler);
	wxBitmap bitmap("Image/items.png",wxBITMAP_TYPE_PNG);
	this->SetBackgroundColour(*wxBLACK);
	menu = new wxMenu();
	menu->Append(1,"Use");
	//menu->Append(2,"Fast key");
	menu->Append(2,"Destroy");
	this->Connect(wxEVT_COMMAND_MENU_SELECTED,wxCommandEventHandler(Item::SelectItem));
	this->inchest = inchest;

	int a = rand()%5;
	int b = 0;
	int nq = 0;
	int sq = rand()%5;

	switch(sq)
	{
	case 0:
		if (rand()%2 == 0)
			quality << "+" << rand()%10 + 1 << " health" << " ";
		else
			quality << "-" << rand()%10 + 1 << " health" << " ";
		break;
	case 1:
		if (rand()%2 == 0)
			quality << "+" << rand()%10 + 1 << " mana" << " ";
		else
			quality << "-" << rand()%10 + 1 << " mana" << " ";
		break;
	case 2:
		if (rand()%2 == 0)
			quality << "+" << rand()%10 + 1 << " strength" << " ";
		else
			quality << "-" << rand()%10 + 1 << " strength" << " ";
		break;
	case 3:
		if (rand()%2 == 0)
			quality << "+" << rand()%5 + 1 << " agility" << " ";
		else
			quality << "-" << rand()%5 + 1 << " agility" << " ";
		break;
	case 4:
		if (rand()%2 == 0)
			quality << "+" << rand()%10 + 1 << " magic" << " ";
		else
			quality << "-" << rand()%10 + 1 << " magic" << " ";
		break;
	default:
		break;
	}

	switch(a)
	{
	case 0://type == apparel
		type = "Apparel";
		b = rand()%4;
		switch(b)
		{
		case 0:
			subtype = "Helm";
			//quality = "";
			nq = rand()%10 + 1;
			if (rand()%2 == 0)
				quality << "+" << nq << " defense" << " ";
			else
				quality << "-" << nq << " defense" << " ";
			bmp = bitmap.GetSubBitmap(wxRect(120,0,40,40));
			break;
		case 1:
			subtype = "Mail";
			//quality = "";
			nq = rand()%10 + 1;
			if (rand()%2 == 0)
				quality << "+" << nq << " defense" << " ";
			else
				quality << "-" << nq << " defense" << " ";
			bmp = bitmap.GetSubBitmap(wxRect(0,0,40,40));
			break;
		case 2:
			subtype = "Pants";
			//quality = "";
			nq = rand()%10 + 1;
			if (rand()%2 == 0)
				quality << "+" << nq << " defense" << " ";
			else
				quality << "-" << nq << " defense" << " ";
			bmp = bitmap.GetSubBitmap(wxRect(40,0,40,40));
			break;
		case 3:
			subtype = "Boots";
			//quality = "";
			nq = rand()%10 + 1;
			if (rand()%2 == 0)
				quality << "+" << nq << " defense" << " ";
			else
				quality << "-" << nq << " defense" << " ";
			bmp = bitmap.GetSubBitmap(wxRect(80,0,40,40));
			break;
		default:
			break;
		}
		break;
	case 1://type == sword
		type = "Weapon";
		b = rand()%3;
		switch(b)
		{
		case 0:
			subtype = "Sword";
			nq = rand()%10 + 1;
			if (rand()%2 == 0)
				quality << "+" << nq << " strength" << " ";
			else
				quality << "-" << nq << " strength" << " ";
			bmp = bitmap.GetSubBitmap(wxRect(80,0,40,40));
			bmp = bitmap.GetSubBitmap(wxRect(0,40,40,40));
			break;
		case 1:
			subtype = "Sword";
			nq = rand()%10 + 1;
			if (rand()%2 == 0)
				quality << "+" << nq << " strength" << " ";
			else
				quality << "-" << nq << " strength" << " ";
			bmp = bitmap.GetSubBitmap(wxRect(40,40,40,40));
			break;
		case 2:
			subtype = "Sword";
			nq = rand()%10 + 1;
			if (rand()%2 == 0)
				quality << "+" << nq << " strength" << " ";
			else
				quality << "-" << nq << " strength" << " ";
			bmp = bitmap.GetSubBitmap(wxRect(80,40,40,40));
			break;
		default:
			break;
		}
		break;
	case 2://type == accassory
		type = "Accassory";
		b = rand()%4;
		switch(b)
		{
		case 0:
			subtype = "Ring";
			bmp = bitmap.GetSubBitmap(wxRect(0,80,40,40));
			break;
		case 1:
			subtype = "Ring";
			bmp = bitmap.GetSubBitmap(wxRect(40,80,40,40));
			break;
		case 2:
			subtype = "Ring";
			bmp = bitmap.GetSubBitmap(wxRect(80,80,40,40));
			break;
		case 3:
			subtype = "Gloves";
			nq = rand()%5 + 1;
			if (rand()%2 == 0)
				quality << "+" << nq << " defense" << " ";
			else
				quality << "-" << nq << " defense" << " ";
			bmp = bitmap.GetSubBitmap(wxRect(120,80,40,40));
			break;
		default:
			break;
		}
		break;
	case 3://type == other
		type = "Other";
		b = rand()%7;
		switch(b)
		{
		case 0:
			subtype = "Scroll";
			switch(rand()%7)
			{
			case 0:
				quality = "";
				quality << "teleport left" << " -40 mana  "; 
				break;
			case 1:
				quality = "";
				quality << "teleport right" << " -40 mana  "; 
				break;
			case 2:
				quality = "";
				quality << "teleport up" << " -40 mana  "; 
				break;
			case 3:
				quality = "";
				quality << "teleport down" << " -40 mana  "; 
				break;
			case 4:
				quality = "";
				quality << "Heal" << " -40 mana +20 health "; 
				break;
			case 5:
				quality = "";
				quality << "Kill" << "-80 mana  "; 
				break;
			default:
					break;
			}
			bmp = bitmap.GetSubBitmap(wxRect(0,120,40,40));
			break;
		case 1:
			subtype = "Scroll";
			switch(rand()%7)
			{
			case 0:
				quality = "";
				quality << "teleport left" << " -40 mana  "; 
				break;
			case 1:
				quality = "";
				quality << "teleport right" << " -40 mana  "; 
				break;
			case 2:
				quality = "";
				quality << "teleport up" << " -40 mana  "; 
				break;
			case 3:
				quality = "";
				quality << "teleport down" << " -40 mana  "; 
				break;
			case 4:
				quality = "";
				quality << "Heal" << " -40 mana +20 health "; 
				break;
			case 5:
				quality = "";
				quality << "Kill" << "-80 mana  "; 
				break;
			default:
					break;
			}
			bmp = bitmap.GetSubBitmap(wxRect(40,120,40,40));
			break;
		case 2:
			subtype = "Scroll";
			switch(rand()%7)
			{
			case 0:
				quality = "";
				quality << "teleport left" << " -40 mana  "; 
				break;
			case 1:
				quality = "";
				quality << "teleport right" << " -40 mana  "; 
				break;
			case 2:
				quality = "";
				quality << "teleport up" << " -40 mana  "; 
				break;
			case 3:
				quality = "";
				quality << "teleport down" << " -40 mana  "; 
				break;
			case 4:
				quality = "";
				quality << "Heal" << " -40 mana +20 health "; 
				break;
			case 5:
				quality = "";
				quality << "Kill" << "-80 mana  "; 
				break;
			default:
					break;
			}
			bmp = bitmap.GetSubBitmap(wxRect(80,120,40,40));
			break;
		case 3:
			subtype = "Scroll";
			switch(rand()%7)
			{
			case 0:
				quality = "";
				quality << "teleport left" << " -40 mana  "; 
				break;
			case 1:
				quality = "";
				quality << "teleport right" << " -40 mana  "; 
				break;
			case 2:
				quality = "";
				quality << "teleport up" << " -40 mana  "; 
				break;
			case 3:
				quality = "";
				quality << "teleport down" << " -40 mana  "; 
				break;
			case 4:
				quality = "";
				quality << "Heal" << " -40 mana +20 health "; 
				break;
			case 5:
				quality = "";
				quality << "Kill" << "-80 mana  "; 
				break;
			default:
					break;
			}
			bmp = bitmap.GetSubBitmap(wxRect(120,120,40,40));
			break;
		case 4:
			subtype = "Mana potion";
			quality = "";
			quality << "Mana" << " +50 mana  "; 
			bmp = bitmap.GetSubBitmap(wxRect(160,120,40,40));
			break;
		case 5:
			subtype = "Health potion";
			quality = "";
			quality << "Health" << " +100 health  "; 
			bmp = bitmap.GetSubBitmap(wxRect(200,120,40,40));
			break;
		case 6:
			subtype = "Money";
			quality = "";
			quality << "+" <<rand()%20 + 1 << "money  "; 
			bmp = bitmap.GetSubBitmap(wxRect(240,120,40,40));
			break;
		default:
			break;
		}
		break;
	case 4://type == other
		type = "Other";
		b = rand()%7;
		switch(b)
		{
		case 0:
			subtype = "Scroll";
			switch(rand()%7)
			{
			case 0:
				quality = "";
				quality << "teleport left" << " -40 mana  "; 
				break;
			case 1:
				quality = "";
				quality << "teleport right" << " -40 mana  "; 
				break;
			case 2:
				quality = "";
				quality << "teleport up" << " -40 mana  "; 
				break;
			case 3:
				quality = "";
				quality << "teleport down" << " -40 mana  "; 
				break;
			case 4:
				quality = "";
				quality << "Heal" << " -40 mana +20 health "; 
				break;
			case 5:
				quality = "";
				quality << "Kill" << "-80 mana  "; 
				break;
			default:
					break;
			}
			bmp = bitmap.GetSubBitmap(wxRect(0,120,40,40));
			break;
		case 1:
			subtype = "Scroll";
			switch(rand()%7)
			{
			case 0:
				quality = "";
				quality << "teleport left" << " -40 mana  "; 
				break;
			case 1:
				quality = "";
				quality << "teleport right" << " -40 mana  "; 
				break;
			case 2:
				quality = "";
				quality << "teleport up" << " -40 mana  "; 
				break;
			case 3:
				quality = "";
				quality << "teleport down" << " -40 mana  "; 
				break;
			case 4:
				quality = "";
				quality << "Heal" << " -40 mana +20 health "; 
				break;
			case 5:
				quality = "";
				quality << "Kill" << "-80 mana  "; 
				break;
			default:
					break;
			}
			bmp = bitmap.GetSubBitmap(wxRect(40,120,40,40));
			break;
		case 2:
			subtype = "Scroll";
			switch(rand()%7)
			{
			case 0:
				quality = "";
				quality << "teleport left" << " -40 mana  "; 
				break;
			case 1:
				quality = "";
				quality << "teleport right" << " -40 mana  "; 
				break;
			case 2:
				quality = "";
				quality << "teleport up" << " -40 mana  "; 
				break;
			case 3:
				quality = "";
				quality << "teleport down" << " -40 mana  "; 
				break;
			case 4:
				quality = "";
				quality << "Heal" << " -40 mana +20 health "; 
				break;
			case 5:
				quality = "";
				quality << "Kill" << "-80 mana  "; 
				break;
			default:
					break;
			}
			bmp = bitmap.GetSubBitmap(wxRect(80,120,40,40));
			break;
		case 3:
			subtype = "Scroll";
			switch(rand()%7)
			{
			case 0:
				quality = "";
				quality << "teleport left" << " -40 mana  "; 
				break;
			case 1:
				quality = "";
				quality << "teleport right" << " -40 mana  "; 
				break;
			case 2:
				quality = "";
				quality << "teleport up" << " -40 mana  "; 
				break;
			case 3:
				quality = "";
				quality << "teleport down" << " -40 mana  "; 
				break;
			case 4:
				quality = "";
				quality << "Heal" << " -40 mana +20 health "; 
				break;
			case 5:
				quality = "";
				quality << "Kill" << "-80 mana  "; 
				break;
			default:
					break;
			}
			bmp = bitmap.GetSubBitmap(wxRect(120,120,40,40));
			break;
		case 4:
			subtype = "Mana potion";
			quality = "";
			quality << "Mana" << " +50 mana  "; 
			bmp = bitmap.GetSubBitmap(wxRect(160,120,40,40));
			break;
		case 5:
			subtype = "Health potion";
			quality = "";
			quality << "Health" << " +100 health  "; 
			bmp = bitmap.GetSubBitmap(wxRect(200,120,40,40));
			break;
		case 6:
			subtype = "Money";
			quality = "";
			quality <<  "+" <<rand()%20 + 1 << "money  "; 
			bmp = bitmap.GetSubBitmap(wxRect(240,120,40,40));
			break;
		default:
			break;
		}
		break;
	default:
		break;
	}
	this->SetBitmap(bmp);
	//CreateInfo();
}

Item::Item(wxWindow* parent, wxString type, int inchest):wxStaticBitmap(parent,wxID_ANY,wxNullBitmap)
{
	//ID = ALL;
	//ALL++;
	/*info = new wxMenu();
	info->Append(3,"-");*/
	this->Hide();
	wxImage::AddHandler(new wxPNGHandler);
	wxBitmap bitmap("Image/items.png",wxBITMAP_TYPE_PNG);
	menu = new wxMenu();
	menu->Append(1,"Use");
	//menu->Append(2,"Fast key");
	menu->Append(2,"Destroy");
	this->Connect(wxEVT_COMMAND_MENU_SELECTED,wxCommandEventHandler(Item::SelectItem));
	this->type = type;

	this->inchest = inchest;
	int a = 0;
	if (type == "Apparel")
		a = 0;
	if (type == "Weapon")
		a = 1;
	if (type == "Accessory")
		a = 2;
	if (type == "Other")
		a = 3;
	if (type == "Empty")
	{
		subtype = "";
		quality = "";
		bmp = wxNullBitmap;

		this->SetBitmap(bmp);
		this->SetBackgroundColour(*wxBLACK);
		//CreateInfo();
		return;
	}
	this->SetBackgroundColour(*wxBLACK);
	int b = 0;
	int nq = 0;
	int sq = rand()%5;

	switch(sq)
	{
	case 0:
		if (rand()%2 == 0)
			quality << "+" << rand()%10 + 1 << " health" << " ";
		else
			quality << "-" << rand()%10 + 1 << " health" << " ";
		break;
	case 1:
		if (rand()%2 == 0)
			quality << "+" << rand()%10 + 1 << " mana" << " ";
		else
			quality << "-" << rand()%10 + 1 << " mana" << " ";
		break;
	case 2:
		if (rand()%2 == 0)
			quality << "+" << rand()%10 + 1 << " strength" << " ";
		else
			quality << "-" << rand()%10 + 1 << " strength" << " ";
		break;
	case 3:
		if (rand()%2 == 0)
			quality << "+" << rand()%5 + 1 << " agility" << " ";
		else
			quality << "-" << rand()%5 + 1 << " agility" << " ";
		break;
	case 4:
		if (rand()%2 == 0)
			quality << "+" << rand()%10 + 1 << " magic" << " ";
		else
			quality << "-" << rand()%10 + 1 << " magic" << " ";
		break;
	default:
		break;
	}

	switch(a)
	{
	case 0://type == apparel
		type = "Apparel";
		b = rand()%4;
		switch(b)
		{
		case 0:
			subtype = "Helm";
			//quality = "";
			nq = rand()%10 + 1;
			if (rand()%2 == 0)
				quality << "+" << nq << " defense" << " ";
			else
				quality << "-" << nq << " defense" << " ";
			bmp = bitmap.GetSubBitmap(wxRect(120,0,40,40));
			break;
		case 1:
			subtype = "Mail";
			//quality = "";
			nq = rand()%10 + 1;
			if (rand()%2 == 0)
				quality << "+" << nq << " defense" << " ";
			else
				quality << "-" << nq << " defense" << " ";
			bmp = bitmap.GetSubBitmap(wxRect(0,0,40,40));
			break;
		case 2:
			subtype = "Pants";
			//quality = "";
			nq = rand()%10 + 1;
			if (rand()%2 == 0)
				quality << "+" << nq << " defense" << " ";
			else
				quality << "-" << nq << " defense" << " ";
			bmp = bitmap.GetSubBitmap(wxRect(40,0,40,40));
			break;
		case 3:
			subtype = "Boots";
			//quality = "";
			nq = rand()%10 + 1;
			if (rand()%2 == 0)
				quality << "+" << nq << " defense" << " ";
			else
				quality << "-" << nq << " defense" << " ";
			bmp = bitmap.GetSubBitmap(wxRect(80,0,40,40));
			break;
		default:
			break;
		}
		break;
	case 1://type == sword
		type = "Weapon";
		b = rand()%3;
		switch(b)
		{
		case 0:
			subtype = "Sword";
			nq = rand()%10 + 1;
			if (rand()%2 == 0)
				quality << "+" << nq << " strength" << " ";
			else
				quality << "-" << nq << " strength" << " ";
			bmp = bitmap.GetSubBitmap(wxRect(80,0,40,40));
			bmp = bitmap.GetSubBitmap(wxRect(0,40,40,40));
			break;
		case 1:
			subtype = "Sword";
			nq = rand()%10 + 1;
			if (rand()%2 == 0)
				quality << "+" << nq << " strength" << " ";
			else
				quality << "-" << nq << " strength" << " ";
			bmp = bitmap.GetSubBitmap(wxRect(40,40,40,40));
			break;
		case 2:
			subtype = "Sword";
			nq = rand()%10 + 1;
			if (rand()%2 == 0)
				quality << "+" << nq << " strength" << " ";
			else
				quality << "-" << nq << " strength" << " ";
			bmp = bitmap.GetSubBitmap(wxRect(80,40,40,40));
			break;
		default:
			break;
		}
		break;
	case 2://type == accassory
		type = "Accassory";
		b = rand()%4;
		switch(b)
		{
		case 0:
			subtype = "Ring";
			bmp = bitmap.GetSubBitmap(wxRect(0,80,40,40));
			break;
		case 1:
			subtype = "Ring";
			bmp = bitmap.GetSubBitmap(wxRect(40,80,40,40));
			break;
		case 2:
			subtype = "Ring";
			bmp = bitmap.GetSubBitmap(wxRect(80,80,40,40));
			break;
		case 3:
			subtype = "Gloves";
			nq = rand()%5 + 1;
			if (rand()%2 == 0)
				quality << "+" << nq << " defense" << " ";
			else
				quality << "-" << nq << " defense" << " ";
			bmp = bitmap.GetSubBitmap(wxRect(120,80,40,40));
			break;
		default:
			break;
		}
		break;
	case 3://type == other
		type = "Other";
		b = rand()%7;
		switch(b)
		{
		case 0:
			subtype = "Scroll";
			switch(rand()%7)
			{
			case 0:
				quality = "";
				quality << "teleport left" << " -40 mana  "; 
				break;
			case 1:
				quality = "";
				quality << "teleport right" << " -40 mana  "; 
				break;
			case 2:
				quality = "";
				quality << "teleport up" << " -40 mana  "; 
				break;
			case 3:
				quality = "";
				quality << "teleport down" << " -40 mana  "; 
				break;
			case 4:
				quality = "";
				quality << "Heal" << " -40 mana +20 health "; 
				break;
			case 5:
				quality = "";
				quality << "Kill" << "-80 mana  "; 
				break;
			default:
					break;
			}
			bmp = bitmap.GetSubBitmap(wxRect(0,120,40,40));
			break;
		case 1:
			subtype = "Scroll";
			switch(rand()%7)
			{
			case 0:
				quality = "";
				quality << "teleport left" << " -40 mana  "; 
				break;
			case 1:
				quality = "";
				quality << "teleport right" << " -40 mana  "; 
				break;
			case 2:
				quality = "";
				quality << "teleport up" << " -40 mana  "; 
				break;
			case 3:
				quality = "";
				quality << "teleport down" << " -40 mana  "; 
				break;
			case 4:
				quality = "";
				quality << "Heal" << " -40 mana +20 health "; 
				break;
			case 5:
				quality = "";
				quality << "Kill" << "-80 mana  "; 
				break;
			default:
					break;
			}
			bmp = bitmap.GetSubBitmap(wxRect(40,120,40,40));
			break;
		case 2:
			subtype = "Scroll";
			switch(rand()%7)
			{
			case 0:
				quality = "";
				quality << "teleport left" << " -40 mana  "; 
				break;
			case 1:
				quality = "";
				quality << "teleport right" << " -40 mana  "; 
				break;
			case 2:
				quality = "";
				quality << "teleport up" << " -40 mana  "; 
				break;
			case 3:
				quality = "";
				quality << "teleport down" << " -40 mana  "; 
				break;
			case 4:
				quality = "";
				quality << "Heal" << " -40 mana +20 health "; 
				break;
			case 5:
				quality = "";
				quality << "Kill" << "-80 mana  "; 
				break;
			default:
					break;
			}
			bmp = bitmap.GetSubBitmap(wxRect(80,120,40,40));
			break;
		case 3:
			subtype = "Scroll";
			switch(rand()%7)
			{
			case 0:
				quality = "";
				quality << "teleport left" << " -40 mana  "; 
				break;
			case 1:
				quality = "";
				quality << "teleport right" << " -40 mana  "; 
				break;
			case 2:
				quality = "";
				quality << "teleport up" << " -40 mana  "; 
				break;
			case 3:
				quality = "";
				quality << "teleport down" << " -40 mana  "; 
				break;
			case 4:
				quality = "";
				quality << "Heal" << " -40 mana +20 health "; 
				break;
			case 5:
				quality = "";
				quality << "Kill" << "-80 mana  "; 
				break;
			default:
					break;
			}
			bmp = bitmap.GetSubBitmap(wxRect(120,120,40,40));
			break;
		case 4:
			subtype = "Mana potion";
			quality = "";
			quality << "Mana" << " +50 mana  "; 
			bmp = bitmap.GetSubBitmap(wxRect(160,120,40,40));
			break;
		case 5:
			subtype = "Health potion";
			quality = "";
			quality << "Health" << " +100 health  "; 
			bmp = bitmap.GetSubBitmap(wxRect(200,120,40,40));
			break;
		case 6:
			subtype = "Money";
			quality = "";
			quality <<  "+" <<rand()%20 + 1 << "money  "; 
			bmp = bitmap.GetSubBitmap(wxRect(240,120,40,40));
			break;
		default:
			break;
		}
		break;
	case 4://type == other
		type = "Other";
		b = rand()%7;
		switch(b)
		{
		case 0:
			subtype = "Scroll";
			switch(rand()%7)
			{
			case 0:
				quality = "";
				quality << "teleport left" << " -40 mana  "; 
				break;
			case 1:
				quality = "";
				quality << "teleport right" << " -40 mana  "; 
				break;
			case 2:
				quality = "";
				quality << "teleport up" << " -40 mana  "; 
				break;
			case 3:
				quality = "";
				quality << "teleport down" << " -40 mana  "; 
				break;
			case 4:
				quality = "";
				quality << "Heal" << " -40 mana +20 health "; 
				break;
			case 5:
				quality = "";
				quality << "Kill" << "-80 mana  "; 
				break;
			default:
					break;
			}
			bmp = bitmap.GetSubBitmap(wxRect(0,120,40,40));
			break;
		case 1:
			subtype = "Scroll";
			switch(rand()%7)
			{
			case 0:
				quality = "";
				quality << "teleport left" << " -40 mana  "; 
				break;
			case 1:
				quality = "";
				quality << "teleport right" << " -40 mana  "; 
				break;
			case 2:
				quality = "";
				quality << "teleport up" << " -40 mana  "; 
				break;
			case 3:
				quality = "";
				quality << "teleport down" << " -40 mana  "; 
				break;
			case 4:
				quality = "";
				quality << "Heal" << " -40 mana +20 health "; 
				break;
			case 5:
				quality = "";
				quality << "Kill" << "-80 mana  "; 
				break;
			default:
					break;
			}
			bmp = bitmap.GetSubBitmap(wxRect(40,120,40,40));
			break;
		case 2:
			subtype = "Scroll";
			switch(rand()%7)
			{
			case 0:
				quality = "";
				quality << "teleport left" << " -40 mana  "; 
				break;
			case 1:
				quality = "";
				quality << "teleport right" << " -40 mana  "; 
				break;
			case 2:
				quality = "";
				quality << "teleport up" << " -40 mana  "; 
				break;
			case 3:
				quality = "";
				quality << "teleport down" << " -40 mana  "; 
				break;
			case 4:
				quality = "";
				quality << "Heal" << " -40 mana +20 health "; 
				break;
			case 5:
				quality = "";
				quality << "Kill" << "-80 mana  "; 
				break;
			default:
					break;
			}
			bmp = bitmap.GetSubBitmap(wxRect(80,120,40,40));
			break;
		case 3:
			subtype = "Scroll";
			switch(rand()%7)
			{
			case 0:
				quality = "";
				quality << "teleport left" << " -40 mana  "; 
				break;
			case 1:
				quality = "";
				quality << "teleport right" << " -40 mana  "; 
				break;
			case 2:
				quality = "";
				quality << "teleport up" << " -40 mana  "; 
				break;
			case 3:
				quality = "";
				quality << "teleport down" << " -40 mana  "; 
				break;
			case 4:
				quality = "";
				quality << "Heal" << " -40 mana +20 health "; 
				break;
			case 5:
				quality = "";
				quality << "Kill" << "-80 mana  "; 
				break;
			default:
					break;
			}
			bmp = bitmap.GetSubBitmap(wxRect(120,120,40,40));
			break;
		case 4:
			subtype = "Mana potion";
			quality = "";
			quality << "Mana" << " +50 mana  "; 
			bmp = bitmap.GetSubBitmap(wxRect(160,120,40,40));
			break;
		case 5:
			subtype = "Health potion";
			quality = "";
			quality << "Health" << " +100 health  "; 
			bmp = bitmap.GetSubBitmap(wxRect(200,120,40,40));
			break;
		case 6:
			subtype = "Money";
			quality = "";
			quality << "+" <<rand()%20 + 1 << "money  "; 
			bmp = bitmap.GetSubBitmap(wxRect(240,120,40,40));
			break;
		default:
			break;
		}
		break;
	default:
		break;
	}
	
	this->SetBitmap(bmp);
}

Item::Item(wxWindow* parent,int level, wxString type, wxString subtype, wxString quality,int inchest):wxStaticBitmap(parent,wxID_ANY,wxNullBitmap)
{
	//ID = ALL;
	//ALL++;
	/*info = new wxMenu();
	info->Append(3,"-");*/
	this->Hide();
	menu = new wxMenu();
	menu->Append(1,"Use");
	//menu->Append(2,"Fast key");
	menu->Append(2,"Destroy");
	wxImage::AddHandler(new wxPNGHandler);
	wxBitmap bitmap("Image/items.png",wxBITMAP_TYPE_PNG);
	
	this->level = level;
	this->type = type;
	this->subtype = subtype;
	this->quality = quality;
	this->inchest = inchest;
	//CreateInfo();
	this->SetBackgroundColour(*wxBLACK);

	//картинка
	if (type == "Empty")
		return;
	if (type == "Apparel")
	{
		if (subtype == "Helm")
			bmp = bitmap.GetSubBitmap(wxRect(120,0,40,40));
		if (subtype == "Mail")
			bmp = bitmap.GetSubBitmap(wxRect(0,0,40,40));
		if (subtype == "Pants")
			bmp = bitmap.GetSubBitmap(wxRect(40,0,40,40));
		if (subtype == "Boots")
			bmp = bitmap.GetSubBitmap(wxRect(80,0,40,40));
		//return;
	}
	if (type == "Weapon")
	{
		int a = rand()%3;

		switch(a)
		{
		case 0:
			bmp = bitmap.GetSubBitmap(wxRect(0,40,40,40));
			break;
		case 1:
			bmp = bitmap.GetSubBitmap(wxRect(40,40,40,40));
			break;
		case 2:
			bmp = bitmap.GetSubBitmap(wxRect(80,40,40,40));
			break;
		default:
			break;
		}
		//return;
	}
	if (type == "Accassory")
	{
		if (subtype == "Ring")
		{
			int b = rand()%3;
			switch(b)
			{
			case 0:
				bmp = bitmap.GetSubBitmap(wxRect(0,80,40,40));
			break;
				case 1:
				bmp = bitmap.GetSubBitmap(wxRect(40,80,40,40));
				break;
			case 2:
				bmp = bitmap.GetSubBitmap(wxRect(80,80,40,40));
				break;
			default:
				break;
			}
		}
		if (subtype == "Gloves")
			bmp = bitmap.GetSubBitmap(wxRect(120,80,40,40));
	}
	if (type == "Other")
	{
		if (subtype == "Scroll")
			bmp = bitmap.GetSubBitmap(wxRect(120,120,40,40));

		if (subtype == "Mana potion")
			bmp = bitmap.GetSubBitmap(wxRect(160,120,40,40));

		if (subtype == "Health potion")
			bmp = bitmap.GetSubBitmap(wxRect(200,120,40,40));
		
		if (subtype == "Money")
			bmp = bitmap.GetSubBitmap(wxRect(240,120,40,40));
	}
	this->SetBitmap(bmp);
	this->Connect(wxEVT_COMMAND_MENU_SELECTED,wxCommandEventHandler(Item::SelectItem));
}

void Item::CreateInfo()
{
	//info->
	//info->Delete(3);
	info = new wxMenu();
	//info->Append(3,"-");
	if (this->type == "Empty")
	{
		info->Append(3,"Empty");
	}
	else
		info->Append(3,type + " - " + subtype + " " + quality);
}

wxString Item::GetName() const
{
	return name;
}

int Item::GetLevel() const
{
	return level;
}
wxString Item::GetType() const
{
	return type;
}

wxString Item::GetSubType() const
{
	return subtype;
}

wxString Item::GetQuality() const
{
	return quality;
}

/*int Item::GetID() const
{
	return ID;
}*/
int Item::GetCost() const
{
	return cost;
}
wxBitmap Item::GetBitmap() const
{
	return bmp;
}

void Item::SetInChest()
{
	if (inchest == true)
		inchest = false;
	else
		inchest = true;
}

void Item::SetType(wxString value)
{
	this->type = value;
	if (value == "Empty")
	{
		SetBitmap(wxNullBitmap);
		subtype = "";
		quality = "";
		this->SetBackgroundColour(*wxBLACK);
	}
}

bool Item::AmIInChest()
{
	return inchest;
}
void Item::ShowMenu(wxMouseEvent& event)
{
	if (type != "Empty" && inchest == false)
	{
		wxPoint p = event.GetPosition();
		this->DoPopupMenu(menu, p.x,p.y);
	}
}

void Item::ShowInfo(wxMouseEvent& event)
{
	CreateInfo();
	wxPoint p = event.GetPosition();
	this->DoPopupMenu(info, p.x,p.y);
}

void Item::Shift(wxMouseEvent& event)
{
	if (inchest == true)
	{
		if (type != "Empty")
		{
			((Chest*)(this->GetParent()))->Shift(this->GetId());
		}
	}
}

void Item::SelectItem(wxCommandEvent& event)
{
	if (event.GetSelection() == 1)
	{
		((Inventory*)(this->GetParent()))->Use(this->GetId());
	}
	if (event.GetSelection() == 2)
	{
		((Inventory*)(this->GetParent()))->Delete(this->GetId());
	}
}

/*Item::~Item()
{
	info->Destroy(3);
	menu->Destroy(1);
	menu->Destroy(2);
	delete info;
	delete menu;
}*/

BEGIN_EVENT_TABLE(Item,wxStaticBitmap)
	EVT_RIGHT_DOWN (	Item::ShowMenu)
	EVT_LEFT_DOWN (	Item::ShowInfo)
	//EVT_LEFT_DCLICK (	Item::Shift)
	EVT_MIDDLE_DOWN (	Item::Shift)
END_EVENT_TABLE()