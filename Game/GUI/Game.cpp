#include "Game.h"
#include <wx/sizer.h>
#include <wx/panel.h>
#include <wx/colour.h>
#include <wx/animate.h>

Game::Game(wxFrame* parent, string name) : wxFrame(parent, 1, "Game", wxDefaultPosition, wxDefaultSize)
{
	inv = new Inventory(this);
	model = new Model(this);
	chs = new Characteristic(this,model->GetPlayer());
	this->ShowFullScreen(true);
	this->name = name;
	this->Connect(wxEVT_PAINT, wxPaintEventHandler(Game::OnPaint));
	//this->Connect(wxEVT_KEY_DOWN, wxKeyEventHandler(Game::OnPressKeyboard));
	//this->SetFocusIgnoringChildren();
	this->SetFocus();
}

void Game::OnPaint(wxPaintEvent& event)
{
	wxImage::AddHandler(new wxPNGHandler);
	
	wxBoxSizer* BoxSizer4;
	wxBoxSizer* BoxSizer2;
	wxBoxSizer* BoxSizer1;
	wxBoxSizer* BoxSizer3;
	wxBoxSizer* BoxSizer5;
	wxBoxSizer* BoxSizer6;
	wxBoxSizer* BoxSizer7;
	wxBoxSizer* BoxSizer8;
	wxBoxSizer* BoxSizer9;
	wxBoxSizer* BoxSizer10;
	wxBoxSizer* BoxSizer11;
	wxBoxSizer* BoxSizer12;
	
	wxBitmap bexp;
	wxBitmap bhealth;
	wxBitmap bmana;
	bexp.LoadFile("Image/Exp1.png",wxBITMAP_TYPE_PNG);
	bhealth.LoadFile("Image/Health1.png",wxBITMAP_TYPE_PNG);
	bmana.LoadFile("Image/Mana1.png",wxBITMAP_TYPE_PNG);
    Map = new wxPanel(this);
	Map->SetBackgroundColour(*wxBLACK);
	Info = new wxPanel(this);
	Info->SetBackgroundColour(*wxYELLOW);  
	
    BoxSizer9 = new wxBoxSizer(wxHORIZONTAL);
	Icon = new wxStaticBitmap(Info,wxID_ANY, wxBitmap("Image/Icon.png",wxBITMAP_TYPE_PNG));
    //LVL = new wxStaticBitmap(Info,wxID_ANY,   wxBitmap("Image/Lvl.png",wxBITMAP_TYPE_PNG));
	int a = model->GetPlayer()->GetLevelOfEx()/10;
	int b = model->GetPlayer()->GetLevelOfEx() - a*10;
	lvlc = model->GetPlayer()->GetLevelOfEx();
	expc = model->GetPlayer()->GetExp();
	manac = model->GetPlayer()->GetMana();
	healthc = model->GetPlayer()->GetHealth();
	wxBitmap l;
	l.Create(40,40);
	wxMemoryDC mc(l);
	wxBitmap Numlvl;
	Numlvl.LoadFile("Image/NumLvl.png",wxBITMAP_TYPE_PNG);

	mc.DrawBitmap(Numlvl.GetSubBitmap(wxRect(a*40,0,40,40)),0,0,true);
	mc.DrawBitmap(Numlvl.GetSubBitmap(wxRect(b*40,40,40,40)),0,0,true);
	l.SaveFile("Image/Test.png",wxBITMAP_TYPE_PNG);
	LVL = new wxStaticBitmap(Info,wxID_ANY,   wxBitmap("Image/Test.png",wxBITMAP_TYPE_PNG));
	//Icon = new wxPanel(this);
	//LVL = new wxPanel(this);
	BoxSizer9->Add(Icon, 2, wxALL|wxEXPAND, 0);
    BoxSizer9->Add(LVL, 1, wxALL|wxEXPAND, 0);

	BoxSizer10 = new wxBoxSizer(wxVERTICAL);
	Name = new wxStaticText(Info, wxID_ANY, name);
    Exp = new wxStaticBitmap(Info, wxID_ANY,wxBitmap(/*bexp.GetSubBitmap(wxRect(0,0,100,20))*/));
	t_Exp = new wxStaticText(Info,wxID_ANY,"");
	BoxSizer10->Add(Name, 1, wxALL|wxEXPAND, 2);
    BoxSizer10->Add(Exp, 2, wxALL|wxEXPAND, 2);
	BoxSizer10->Add(t_Exp, 1, wxALIGN_CENTER, 2);

	BoxSizer6 = new wxBoxSizer(wxHORIZONTAL);
	BoxSizer6->Add(BoxSizer9, 1, wxALL|wxEXPAND, 0);
	BoxSizer6->Add(BoxSizer10, 2, wxALL|wxEXPAND, 0);

	BoxSizer7 = new wxBoxSizer(wxHORIZONTAL);
    TextHealth = new wxStaticText(Info, wxID_ANY, "Health:");

    Health = new wxStaticBitmap(Info, wxID_ANY, wxBitmap(/*bhealth.GetSubBitmap(wxRect(0,2000,100,20))*/));
	t_Health = new wxStaticText(Info,wxID_ANY,"");
	BoxSizer11 = new wxBoxSizer(wxVERTICAL);
	BoxSizer11->Add(Health,1, wxALL|wxEXPAND, 2);
	BoxSizer11->Add(t_Health,2,wxALIGN_CENTER, 2);

	BoxSizer7->Add(TextHealth, 1, wxALL|wxEXPAND, 2);
    BoxSizer7->Add(BoxSizer11, 2, wxALL|wxEXPAND, 2);

	BoxSizer8 = new wxBoxSizer(wxHORIZONTAL);
    TextMana = new wxStaticText(Info, wxID_ANY, "Mana:");
    Mana = new wxStaticBitmap(Info, wxID_ANY, wxBitmap(/*bmana.GetSubBitmap(wxRect(0,2000,100,20))*/));
	t_Mana = new wxStaticText(Info,wxID_ANY,"");
	BoxSizer12 = new wxBoxSizer(wxVERTICAL);
	BoxSizer12->Add(Mana,1, wxEXPAND, 2);
	BoxSizer12->Add(t_Mana,2, wxALIGN_CENTER, 2);
	BoxSizer8->Add(TextMana, 1, wxALL|wxEXPAND, 2);
    BoxSizer8->Add(BoxSizer12, 2, wxALL|wxEXPAND, 2);

	BoxSizer5 = new wxBoxSizer(wxVERTICAL);
	BoxSizer5->Add(BoxSizer6, 1, wxALL|wxEXPAND, 0);
	BoxSizer5->Add(BoxSizer7, 1, wxALL|wxEXPAND, 0);
	BoxSizer5->Add(BoxSizer8, 1, wxALL|wxEXPAND, 0);
	Info->SetSizer(BoxSizer5);
    //BoxSizer5->Fit(Info);
    //BoxSizer5->SetSizeHints(Info);

	BoxSizer4 = new wxBoxSizer(wxVERTICAL);
	BoxSizer4->Add(Map, 1, wxALL | wxEXPAND, 2);
    BoxSizer4->Add(Info, 1, wxALL | wxEXPAND, 2);

	BoxSizer2 = new wxBoxSizer(wxHORIZONTAL);
    GameW = new GameScene(this, model,this);
	GameW->SetBackgroundColour(*wxWHITE);
    BoxSizer2->Add(GameW, 3, wxALL | wxEXPAND, 5);
    BoxSizer2->Add(BoxSizer4, 1,wxALL | wxEXPAND, 0);

	BoxSizer3 = new wxBoxSizer(wxHORIZONTAL);
    Inv = new wxPanel(this);
	Inv->SetBackgroundColour(*wxBLUE);
	Magic = new wxPanel(this);
	Magic->SetBackgroundColour(*wxGREEN);
	Task = new wxPanel(this);
	Task->SetBackgroundColour(*wxRED);
    BoxSizer3->Add(Inv, 1, wxALL | wxEXPAND, 5);
    BoxSizer3->Add(Magic, 1, wxALL | wxEXPAND, 5);
    BoxSizer3->Add(Task, 1, wxALL | wxEXPAND, 5);

	BoxSizer1 = new wxBoxSizer(wxVERTICAL);
    BoxSizer1->Add(BoxSizer2, 3, wxALL | wxEXPAND, 0);
    BoxSizer1->Add(BoxSizer3, 1, wxALL | wxEXPAND, 0);

    SetSizer(BoxSizer1);
	Layout();
	double a1 = (double)healthc/((double)model->GetPlayer()->GetFactor(0)*lvlc*100);
	double a2 = (double)manac/((double)model->GetPlayer()->GetFactor(1)*lvlc*80);
	double a3 = (double)expc/((double)lvlc*1000);
	for (int i = 0; i < 100; i++)
	{
		double i1 = (double)i/(double)100;
		double i2 = ((double)(i + 1))/(double)100;
		if (a1 >= i1 && a1 <= i2)
		{
			Health->SetBitmap(wxBitmap(bhealth.GetSubBitmap(wxRect(0,(i+1)*20,100,20))));
		}
		if (a2 >= i1 && a2 <= i2)
		{
			Mana->SetBitmap(wxBitmap(bmana.GetSubBitmap(wxRect(0,(i+1)*20,100,20))));
		}
		if (a3 >= i1 && a3 <= i2)
		{
			Exp->SetBitmap(wxBitmap(bexp.GetSubBitmap(wxRect(0,(i+1)*20,100,20))));
		}
	}
	wxString tt;
	tt<< healthc<< "/" << model->GetPlayer()->GetFactor(0)*lvlc*100;
	t_Health->SetLabel(tt);
	wxString tt1;
	tt1 <<manac<<"/"<<model->GetPlayer()->GetFactor(1)*lvlc*80;
	t_Mana->SetLabel(tt1);
	wxString tt2;
	tt2 <<expc<<"/"<<lvlc*1000;
	t_Exp->SetLabel(tt2);
	wxString tt3 = t_Exp->GetLabelText();
}

void Game::OnPressKeyboard(wxKeyEvent& event)
{
	/*
	RIGHT = 1
	LEFT = 2
	UP = 3
	DOWN = 4
	*/
	//this->Connect(wxEVT_KEY_DOWN, wxKeyEventHandler(Game::OnPressKeyboard));
	
	switch(event.GetKeyCode())
	{
	case WXK_ESCAPE:
		this->GetParent()->Show();
		this->Close(true);
		break;
	case WXK_CONTROL_I + 64:
		if (inv->IsActive() == false)
		{
			inv->SetFocus();
			inv->Refresh();
			if (inv->ShowModal() == wxID_CANCEL)
			{
				this->SetFocus();
				this->Refresh();
			}
		}
		
		break;
	case WXK_CONTROL_U + 64:
		if (chs->IsActive() == false)
		{
			chs->SetFocus();
			chs->Refresh();
			if (chs->ShowModal() == 1)
			{
				this->SetFocus();
				this->Refresh();
			}
		}
		
		break;
	default:
		model->OnPressKeyboard(event.GetKeyCode());
		break;
	}
	
}

void Game::Information()
{
	if (expc != model->GetPlayer()->GetExp())
		this->Refresh();
	if (manac != model->GetPlayer()->GetMana())
		this->Refresh();
	if (healthc != model->GetPlayer()->GetHealth())
		this->Refresh();
	if (lvlc != model->GetPlayer()->GetLevelOfEx())
		this->Refresh();
	
}
void Game::WeAreDead()
{
	wxMessageDialog* msg = new wxMessageDialog(this, "DEATH", "You are died!", wxYES_DEFAULT);
	int a = msg->ShowModal();
	if (a == wxID_YES)
		this->Close(true);
}

BEGIN_EVENT_TABLE(Game, wxFrame)
	EVT_CHAR_HOOK (	Game::OnPressKeyboard)
END_EVENT_TABLE()


