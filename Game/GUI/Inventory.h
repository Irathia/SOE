#pragma once

#include <wx/dialog.h>
#include <wx/panel.h>
#include <wx/sizer.h>
#include <vector>

class Inventory: public wxDialog
{
public:
	Inventory(wxWindow* parent);
	void OnPaint(wxPaintEvent& event);
private:
	std::vector <wxPanel*> items;
	std::vector <wxString> names;
};