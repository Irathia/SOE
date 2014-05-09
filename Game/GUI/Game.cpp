#include "Game.h"
#include <wx/sizer.h>
#include <wx/panel.h>
#include <wx/colour.h>
#include <wx/animate.h>
#include <wx/dir.h>

Game::Game(wxFrame* parent, string name) : wxFrame(parent, 1, "Game", wxDefaultPosition, wxDefaultSize)
{
	model = new Model(this);
	inv = new Inventory(this,model->GetPlayer());
	chs = new Characteristic(this,model->GetPlayer());
	this->ShowFullScreen(true);
	this->name = name;

	info = new Info(this,model->GetPlayer(),name);
	R1 = new Rooms(this,0);
	R2 = new Rooms(this,1);
	R3 = new Rooms(this,2);
	GameW = new GameScene(this, model,this);

	this->Connect(wxEVT_PAINT, wxPaintEventHandler(Game::OnPaint));
	//this->Connect(wxEVT_KEY_DOWN, wxKeyEventHandler(Game::OnPressKeyboard));
	//this->SetFocusIgnoringChildren();
	this->SetFocus();
}

Game::Game(wxFrame* parent, string name, bool flag) : wxFrame(parent, 1, "Game", wxDefaultPosition, wxDefaultSize)
{
	//load game
	this->name = name;
	model = new Model(this, true, name);
	inv = new Inventory(this,model->GetPlayer(), name);
	chs = new Characteristic(this,model->GetPlayer());
	
	

	info = new Info(this,model->GetPlayer(),name);
	R1 = new Rooms(this,0, name);
	R2 = new Rooms(this,1, name);
	R3 = new Rooms(this,2, name);
	GameW = new GameScene(this, model,this);
	this->ShowFullScreen(true);
	this->Connect(wxEVT_PAINT, wxPaintEventHandler(Game::OnPaint));
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
	//info = new Info(this,model->GetPlayer(),name);
	info->SetBackgroundColour(*wxYELLOW);  

	BoxSizer4 = new wxBoxSizer(wxVERTICAL);
	BoxSizer4->Add(Map, 1, wxALL | wxEXPAND, 2);
    BoxSizer4->Add(info, 1, wxALL | wxEXPAND, 2);

	BoxSizer2 = new wxBoxSizer(wxHORIZONTAL);
    //GameW = new GameScene(this, model,this);
	GameW->SetBackgroundColour(*wxWHITE);
    BoxSizer2->Add(GameW, 3, wxALL | wxEXPAND, 5);
    BoxSizer2->Add(BoxSizer4, 1,wxALL | wxEXPAND, 0);

	BoxSizer3 = new wxBoxSizer(wxHORIZONTAL);
   // R1 = new Rooms(this,0);
	R1->SetBackgroundColour(*wxGREEN);
	//R2 = new Rooms(this,1);
	R2->SetBackgroundColour(*wxBLUE);
	//R3 = new Rooms(this,2);
	R3->SetBackgroundColour(*wxRED);
    BoxSizer3->Add(R1, 1, wxALL | wxEXPAND, 5);
    BoxSizer3->Add(R2, 1, wxALL | wxEXPAND, 5);
    BoxSizer3->Add(R3, 1, wxALL | wxEXPAND, 5);

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
	
	case WXK_CONTROL_I + 64:
		if (inv->IsActive() == false)
		{
			inv->SetFocus();
			//inv->Refresh();
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
			//chs->Refresh();
			if (chs->ShowModal() == 1)
			{
				this->SetFocus();
				info->Refresh();
				//this->Refresh();
			}
		}
		
		break;
	case WXK_ESCAPE:
		{
			wxMessageDialog* msg = new wxMessageDialog(this, "Exit", "Do you want to exit?", wxYES_NO);
			msg->SetYesNoLabels("Yes","No");
			if (msg->ShowModal() == wxID_YES)
			{
				this->Save();
				this->GetParent()->Show();
				this->Close(true);
			}
		
			break;
		}
	default:
		model->OnPressKeyboard(event.GetKeyCode());
		break;
	}
	
}

void Game::OpenChest()
{
	Chest* chest = new Chest(this,inv);
	if (chest->IsActive() == false)
	{
		chest->SetFocus();
			//chs->Refresh();
		if (chest->ShowModal() == wxID_CANCEL)
		{
			this->SetFocus();
			//info->Refresh();
				//this->Refresh();
		}
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

void Game::PortalActivate(int nl)
{
	if (nl < 10)
	{
		R1->Activate(nl);
		return;
	}
	if (nl < 20)
	{
		R1->Activate(nl-10);
		return;
	}
	if (nl < 30)
	{
		R1->Activate(nl-30);
		return;
	}
}

void Game::TeleportToLevel(int nl)
{
	model->GoToLevel(nl,true);
}

void Game::Save()
{

	//Dir dir("Save/"+name);
	if (wxDir::Exists("Save/"+name) == false)
		wxDir::Make("Save/"+name,777);
	model->Save("Save/"+name+"/", name);
	inv->Save("Save/"+name+"/");
	R1->Save("Save/"+name+"/");
	R2->Save("Save/"+name+"/");
	R3->Save("Save/"+name+"/");

}
BEGIN_EVENT_TABLE(Game, wxFrame)
	EVT_CHAR_HOOK (	Game::OnPressKeyboard)
END_EVENT_TABLE()


