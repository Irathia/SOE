#include "FastItems.h"
#include <wx/sizer.h>

FastItems::FastItems(wxWindow* parent):wxPanel(parent)
{
	this->Connect(wxEVT_PAINT, wxPaintEventHandler(FastItems::OnPaint));
}

void FastItems::OnPaint(wxPaintEvent& event)
{
	wxFont Font(16,wxSWISS,wxFONTSTYLE_NORMAL,wxNORMAL,false,wxEmptyString,wxFONTENCODING_DEFAULT);
	wxGridSizer* GridSizer1;
	GridSizer1 = new wxGridSizer(5, 4, wxDLG_UNIT(this,wxSize(0,0)).GetWidth(), wxDLG_UNIT(this,wxSize(0,0)).GetWidth());
    Text1 = new wxStaticText(this, wxID_ANY, _("1"));
	Text1->SetFont(Font);
    GridSizer1->Add(Text1, 1, wxALIGN_CENTER, 5);
    Bitmap1 = new wxStaticBitmap(this, wxID_ANY, wxNullBitmap);
    GridSizer1->Add(Bitmap1, 1, wxALL|wxEXPAND, 5);
    Text6 = new wxStaticText(this, wxID_ANY, _("6"));
	Text6->SetFont(Font);
    GridSizer1->Add(Text6, 1, wxALIGN_CENTER, 5);
    Bitmap6 = new wxStaticBitmap(this, wxID_ANY, wxNullBitmap);
    GridSizer1->Add(Bitmap6, 1, wxALL|wxEXPAND, 5);
    Text2 = new wxStaticText(this, wxID_ANY, _("2"));
	Text2->SetFont(Font);
    GridSizer1->Add(Text2, 1, wxALIGN_CENTER, 5);
    Bitmap2 = new wxStaticBitmap(this, wxID_ANY, wxNullBitmap);
    GridSizer1->Add(Bitmap2, 1, wxALL|wxEXPAND, 5);
    Text7 = new wxStaticText(this, wxID_ANY, _("7"));
	Text7->SetFont(Font);
    GridSizer1->Add(Text7, 1, wxALIGN_CENTER, 5);
    Bitmap7 = new wxStaticBitmap(this, wxID_ANY, wxNullBitmap);
    GridSizer1->Add(Bitmap7, 1, wxALL|wxEXPAND, 5);
    Text3 = new wxStaticText(this, wxID_ANY, _("3"));
	Text3->SetFont(Font);
    GridSizer1->Add(Text3, 1, wxALIGN_CENTER, 5);
    Bitmap3 = new wxStaticBitmap(this, wxID_ANY, wxNullBitmap);
    GridSizer1->Add(Bitmap3, 1, wxALL|wxEXPAND, 5);
    Text8 = new wxStaticText(this, wxID_ANY, _("8"));
	Text8->SetFont(Font);
    GridSizer1->Add(Text8, 1, wxALIGN_CENTER, 5);
    Bitmap8 = new wxStaticBitmap(this, wxID_ANY, wxNullBitmap);
    GridSizer1->Add(Bitmap8, 1, wxALL|wxEXPAND, 5);
    Text4 = new wxStaticText(this, wxID_ANY, _("4"));
	Text4->SetFont(Font);
    GridSizer1->Add(Text4, 1, wxALIGN_CENTER, 5);
    Bitmap4 = new wxStaticBitmap(this, wxID_ANY, wxNullBitmap);
    GridSizer1->Add(Bitmap4, 1, wxALL|wxEXPAND, 5);
    Text9 = new wxStaticText(this, wxID_ANY, _("9"));
	Text9->SetFont(Font);
    GridSizer1->Add(Text9, 1, wxALIGN_CENTER, 5);
    Bitmap9 = new wxStaticBitmap(this, wxID_ANY, wxNullBitmap);
    GridSizer1->Add(Bitmap9, 1, wxALL|wxEXPAND, 5);
    Text5 = new wxStaticText(this, wxID_ANY, _("5"));
	Text5->SetFont(Font);
    GridSizer1->Add(Text5, 1, wxALIGN_CENTER, 5);
    Bitmap5 = new wxStaticBitmap(this, wxID_ANY, wxNullBitmap);
    GridSizer1->Add(Bitmap5, 1, wxALL|wxEXPAND, 5);
    Text0 = new wxStaticText(this, wxID_ANY, _("0"));
	Text0->SetFont(Font);
    GridSizer1->Add(Text0, 1,wxALIGN_CENTER, 5);
    Bitmap0 = new wxStaticBitmap(this, wxID_ANY, wxNullBitmap);
    GridSizer1->Add(Bitmap0, 1, wxALL|wxEXPAND, 5);
    SetSizer(GridSizer1);
	Layout();
}