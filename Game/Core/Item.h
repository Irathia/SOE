#pragma once

#include <wx/string.h>
#include <wx/bitmap.h>

class Item
{
public:
	Item();
	Item(wxString type);
	wxString GetName() const;
	wxString GetType() const;
	wxString GetSubType() const;
	wxString GetQuality() const;
	wxBitmap GetBitmap() const;
private:
	wxString name;
	wxString type;
	wxString subtype;
	wxString quality;
	wxBitmap bmp;
};