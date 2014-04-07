#include "Inventory.h"

Inventory::Inventory(wxWindow* parent):wxDialog(parent,wxID_ANY,"Inventory")
{
	
	for (int i = 0; i < 25; i++)
	{
		wxPanel* panel = new wxPanel(this,wxID_ANY,wxPoint(0,0),wxSize(0,0));
		panel->SetBackgroundColour(*wxBLACK);
		items.push_back(panel);
	}
	this->Connect(wxEVT_PAINT, wxPaintEventHandler(Inventory::OnPaint));
}

void Inventory::OnPaint(wxPaintEvent& event)
{
	wxGridSizer* gridsizer = new wxGridSizer(5,5,0,0);
	for (int i = 0; i < 25; i++)
	{
		gridsizer->Add(items[i],1,wxALL|wxEXPAND,5);
	}
	SetSizer(gridsizer);
}

std::vector <wxString> Inventory::GetItems() const
{
	return names;
}

wxString Inventory::GetItem(int i) const
{
	return names[i];
}