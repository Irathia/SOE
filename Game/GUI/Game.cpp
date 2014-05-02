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

    Map = new wxPanel(this);
	Map->SetBackgroundColour(*wxBLACK);
	info = new Info(this,model->GetPlayer(),name);
	info->SetBackgroundColour(*wxYELLOW);  

	BoxSizer4 = new wxBoxSizer(wxVERTICAL);
	BoxSizer4->Add(Map, 1, wxALL | wxEXPAND, 2);
    BoxSizer4->Add(info, 1, wxALL | wxEXPAND, 2);

	BoxSizer2 = new wxBoxSizer(wxHORIZONTAL);
    GameW = new GameScene(this, model,this);
	GameW->SetBackgroundColour(*wxWHITE);
    BoxSizer2->Add(GameW, 3, wxALL | wxEXPAND, 5);
    BoxSizer2->Add(BoxSizer4, 1,wxALL | wxEXPAND, 0);

	BoxSizer3 = new wxBoxSizer(wxHORIZONTAL);
    Inv = new FastItems(this);
	Inv->SetBackgroundColour(*wxBLUE);
	Magic = new FastItems(this);
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
			//inv->Refresh();
			if (inv->ShowModal() == wxID_CANCEL)
			{
				this->SetFocus();
				//this->Refresh();
			}
		}
		
		break;
	case WXK_CONTROL_U + 64:
		if (chs->IsActive() == false)
		{
			chs->SetFocus();
			//chs->Refresh();
			if (chs->ShowModal() == 1)
			{
				this->SetFocus();
				info->Refresh();
				//this->Refresh();
			}
		}
		
		break;
	default:
		model->OnPressKeyboard(event.GetKeyCode());
		break;
	}
	
}

bool Game::Information(int a)
{
	if (a == 1)
	{
		/*this->GameW->SetBackgroundColour(*wxBLACK);
		this->GameW->Refresh();*/
		return true;
	}
	if (info->Information() == true)
	{
		this->info->Refresh();
		return true;
	}
	return false;
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


