#include "Inventory.h"

Inventory::Inventory(wxWindow* parent):wxDialog(parent,wxID_ANY,"Inventory")
{
	this->Connect(wxEVT_PAINT, wxPaintEventHandler(Inventory::OnPaint));
}

void Inventory::OnPaint(wxPaintEvent& event)
{
	wxGridSizer* gridsizer = new wxGridSizer(5,5,0,0);
	for (int i = 0; i < 25; i++)
	{
		wxPanel* panel = new wxPanel(this);
		panel->SetBackgroundColour(*wxBLACK);
		items.push_back(panel);
	}

	for (int i = 0; i < 25; i++)
	{
		gridsizer->Add(items[i]);
	}
}