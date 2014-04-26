#include "Item.h"

Item::Item(wxWindow* parent):wxStaticBitmap(parent,wxID_ANY,wxNullBitmap)
{
	info = new wxMenu();
	info->Append(1,"BlaBla");
	menu = new wxMenu();
	menu->Append(1,"Use");
	menu->Append(2,"Fast key");
	menu->Append(3,"Destroy");
}

Item::Item(wxWindow* parent, wxString type):wxStaticBitmap(parent,wxID_ANY,wxNullBitmap)
{
	menu = new wxMenu();
	menu->Append(1,"Use");
	menu->Append(2,"Fast key");
	menu->Append(3,"Destroy");
	this->type = type;
}

Item::Item(wxWindow* parent, wxString type, wxString subtype, wxString quality):wxStaticBitmap(parent,wxID_ANY,wxNullBitmap)
{
	this->type = type;
	this->subtype = subtype;
	this->quality = quality;
}

wxString Item::GetName() const
{
	return name;
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

wxBitmap Item::GetBitmap() const
{
	return bmp;
}

void Item::ShowMenu(wxMouseEvent& event)
{
	wxPoint p = event.GetPosition();
	this->DoPopupMenu(menu, p.x,p.y);
}

void Item::ShowInfo(wxMouseEvent& event)
{
	wxPoint p = event.GetPosition();
	this->DoPopupMenu(info, p.x,p.y);
}

void Item::Shift(wxMouseEvent& event)
{

}


BEGIN_EVENT_TABLE(Item,wxStaticBitmap)
	EVT_RIGHT_DOWN (	Item::ShowMenu)
	EVT_LEFT_DOWN (	Item::ShowInfo)
	EVT_LEFT_DCLICK (	Item::Shift)
END_EVENT_TABLE()