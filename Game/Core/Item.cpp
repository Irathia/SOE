#include "Item.h"

Item::Item()
{
}

Item::Item(wxString type)
{
	this->type = type;
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