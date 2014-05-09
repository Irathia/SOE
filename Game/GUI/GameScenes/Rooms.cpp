#include "Rooms.h"
#include <wx/sizer.h>
#include "../Game.h"
Rooms::Rooms(wxWindow* parent, int n):wxPanel(parent)
{
	this->n = n;

	l0 = new wxButton(this,10,"0");
	l0->Disable();
	l1 = new wxButton(this,11,"1");
	l1->Disable();
	l2 = new wxButton(this,12,"2");
	l2->Disable();
	l3 = new wxButton(this,13,"3");
	l3->Disable();
	l4 = new wxButton(this,14,"4");
	l4->Disable();
	l5 = new wxButton(this,15,"5");
	l5->Disable();
	l6 = new wxButton(this,16,"6");
	l6->Disable();
	l7 = new wxButton(this,17,"7");
	l7->Disable();
	l8 = new wxButton(this,18,"8");
	l8->Disable();
	l9 = new wxButton(this,19,"9");
	l9->Disable();
	this->Connect(wxEVT_PAINT, wxPaintEventHandler(Rooms::OnPaint));
}

void Rooms::OnPaint(wxPaintEvent& event)
{
	wxGridSizer* g = new wxGridSizer(5,2,0,0);
	
	g->Add(l0,wxALL|wxEXPAND|wxCENTER,5);
	g->Add(l1,wxALL|wxEXPAND|wxCENTER,5);
	g->Add(l2,wxALL|wxEXPAND|wxCENTER,5);
	g->Add(l3,wxALL|wxEXPAND|wxCENTER,5);
	g->Add(l4,wxALL|wxEXPAND|wxCENTER,5);
	g->Add(l5,wxALL|wxEXPAND|wxCENTER,5);
	g->Add(l6,wxALL|wxEXPAND|wxCENTER,5);
	g->Add(l7,wxALL|wxEXPAND|wxCENTER,5);
	g->Add(l8,wxALL|wxEXPAND|wxCENTER,5);
	g->Add(l9,wxALL|wxEXPAND|wxCENTER,5);
	this->SetSizer(g);
	Layout();
}

void Rooms::Activate(int a)
{
	switch(a)
	{
	case 0:
		l0->Enable();
		break;
	case 1:
		l1->Enable();
		break;
	case 2:
		l2->Enable();
		break;
	case 3:
		l3->Enable();
		break;
	case 4:
		l4->Enable();
		break;
	case 5:
		l5->Enable();
		break;
	case 6:
		l6->Enable();
		break;
	case 7:
		l7->Enable();
		break;
	case 8:
		l8->Enable();
		break;
	case 9:
		l9->Enable();
		break;
	default:
		break;
	}
}

void Rooms::OnButton0(wxCommandEvent& event)
{
	((Game*)GetParent())->TeleportToLevel(10*n+0);
}
void Rooms::OnButton1(wxCommandEvent& event)
{
	((Game*)GetParent())->TeleportToLevel(10*n+1);
}

void Rooms::OnButton2(wxCommandEvent& event)
{
	((Game*)GetParent())->TeleportToLevel(10*n+2);
}

void Rooms::OnButton3(wxCommandEvent& event)
{
	((Game*)GetParent())->TeleportToLevel(10*n+3);
}

void Rooms::OnButton4(wxCommandEvent& event)
{
	((Game*)GetParent())->TeleportToLevel(10*n+4);
}

void Rooms::OnButton5(wxCommandEvent& event)
{
	((Game*)GetParent())->TeleportToLevel(10*n+5);
}

void Rooms::OnButton6(wxCommandEvent& event)
{
	((Game*)GetParent())->TeleportToLevel(10*n+6);
}

void Rooms::OnButton7(wxCommandEvent& event)
{
	((Game*)GetParent())->TeleportToLevel(10*n+7);
}

void Rooms::OnButton8(wxCommandEvent& event)
{
	((Game*)GetParent())->TeleportToLevel(10*n+8);
}

void Rooms::OnButton9(wxCommandEvent& event)
{
	((Game*)GetParent())->TeleportToLevel(10*n+9);
}


BEGIN_EVENT_TABLE(Rooms, wxPanel)
	EVT_BUTTON(10,	Rooms::OnButton0)
	EVT_BUTTON(11,	Rooms::OnButton1)
	EVT_BUTTON(12,	Rooms::OnButton2)
	EVT_BUTTON(13,	Rooms::OnButton3)
	EVT_BUTTON(14,	Rooms::OnButton4)
	EVT_BUTTON(15,	Rooms::OnButton5)
	EVT_BUTTON(16,	Rooms::OnButton6)
	EVT_BUTTON(17,	Rooms::OnButton7)
	EVT_BUTTON(18,	Rooms::OnButton8)
	EVT_BUTTON(19,	Rooms::OnButton9)
END_EVENT_TABLE()