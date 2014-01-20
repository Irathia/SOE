#include "Game.h"
#include <wx/sizer.h>
#include <wx/panel.h>
#include <wx/colour.h>
#include <wx/animate.h>

Game::Game(wxFrame* parent, string name) : wxFrame(parent, 1, "Game", wxDefaultPosition, wxDefaultSize)
{
	
	this->ShowFullScreen(true);
	this->name = name;
	this->Connect(wxEVT_PAINT, wxPaintEventHandler(Game::OnPaint));
}

void Game::OnPaint(wxPaintEvent& event)
{
	wxImage::AddHandler(new wxPNGHandler);
	this->Connect(wxEVT_KEY_DOWN, wxKeyEventHandler(Game::OnPressKeyboard));
	
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
	
    Map = new wxPanel(this);
	Map->SetBackgroundColour(*wxBLACK);
	Info = new wxPanel(this);
	Info->SetBackgroundColour(*wxYELLOW);  
	
    BoxSizer9 = new wxBoxSizer(wxHORIZONTAL);
	Icon = new wxStaticBitmap(Info,wxID_ANY, wxBitmap("Image/Icon.png",wxBITMAP_TYPE_PNG));
    LVL = new wxStaticBitmap(Info,wxID_ANY,   wxBitmap("Image/Lvl.png",wxBITMAP_TYPE_PNG));
	
	//Icon = new wxPanel(this);
	//LVL = new wxPanel(this);
	BoxSizer9->Add(Icon, 2, wxALL|wxEXPAND, 0);
    BoxSizer9->Add(LVL, 1, wxALL|wxEXPAND, 0);
	
	/*wxPaintDC dc(this);
	dc.DrawBitmap(*bitmap,Icon->GetPosition(),false);*/

	BoxSizer10 = new wxBoxSizer(wxVERTICAL);
	Name = new wxStaticText(Info, wxID_ANY, name);
    Exp = new wxGauge(Info, wxID_ANY, 100);
	BoxSizer10->Add(Name, 1, wxALL|wxEXPAND, 0);
    BoxSizer10->Add(Exp, 1, wxALL|wxEXPAND, 0);

	BoxSizer6 = new wxBoxSizer(wxHORIZONTAL);
	BoxSizer6->Add(BoxSizer9, 1, wxALL|wxEXPAND, 0);
	BoxSizer6->Add(BoxSizer10, 2, wxALL|wxEXPAND, 0);

	BoxSizer7 = new wxBoxSizer(wxHORIZONTAL);
    TextHealth = new wxStaticText(Info, wxID_ANY, "Health:");
    Health = new wxGauge(Info, wxID_ANY, 100);
	BoxSizer7->Add(TextHealth, 1, wxALL|wxEXPAND, 5);
    BoxSizer7->Add(Health, 2, wxALL|wxEXPAND, 5);

	BoxSizer8 = new wxBoxSizer(wxHORIZONTAL);
    TextMana = new wxStaticText(Info, wxID_ANY, "Mana:");
    Mana = new wxGauge(Info, wxID_ANY, 100);
	BoxSizer8->Add(TextMana, 1, wxALL|wxEXPAND, 5);
    BoxSizer8->Add(Mana, 2, wxALL|wxEXPAND, 5);

	BoxSizer5 = new wxBoxSizer(wxVERTICAL);
	BoxSizer5->Add(BoxSizer6, 1, wxALL|wxEXPAND, 0);
	BoxSizer5->Add(BoxSizer7, 1, wxALL|wxEXPAND, 0);
	BoxSizer5->Add(BoxSizer8, 1, wxALL|wxEXPAND, 0);
	Info->SetSizer(BoxSizer5);
    //BoxSizer5->Fit(Info);
    //BoxSizer5->SetSizeHints(Info);

	BoxSizer4 = new wxBoxSizer(wxVERTICAL);
	BoxSizer4->Add(Map, 1, wxALL | wxEXPAND, 5);
    BoxSizer4->Add(Info, 1, wxALL | wxEXPAND, 5);

	BoxSizer2 = new wxBoxSizer(wxHORIZONTAL);
    GameW = new GameScene(this);
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

	//this->Connect(wxEVT_KEY_DOWN, wxKeyEventHandler(GameScene::OnPressKeyboard));
}

void Game::OnPressKeyboard(wxKeyEvent& event)
{
	if (event.GetKeyCode() == WXK_ESCAPE)
		this->Close(true);
	GameW->OnPressKeyboard(event);
}