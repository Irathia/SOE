#include "LoadGame.h"


LoadGame::LoadGame(wxWindow* parent,struct USERS* users,int wight, int height) : wxDialog(parent, 1, "Load game", wxDefaultPosition, wxDefaultSize)
{
	this->SetSize(height/6,2*wight/3);
	this->users = users;
	text = new wxStaticText(this,wxID_ANY,"Choose your user",wxPoint(height/36,wight/24),wxSize(height/12,wight/24));
	text->SetWindowStyle(wxALIGN_CENTRE);
	wxArrayString choices;
	int i = 0;
	while(i != users->name.size())
	{
		choices.push_back(users->name[i]);
		i++;
	}
	table = new wxListBox(this, 2, wxPoint(height/36,wight/12),wxSize(height/10,5*wight/12),choices);

	load = new wxButton(this, 3, "Load" ,wxPoint(height/36, 7*wight/12),wxSize(height/24, wight/24));
	cancel = new wxButton(this, 4, "Cancel" ,wxPoint(height/36+height/12, 7*wight/12),wxSize(height/24, wight/24));
}

void LoadGame::OnButtonLoadGame(wxCommandEvent& event)
{
	this->EndModal(1);
}

void LoadGame::OnButtonCancel(wxCommandEvent& event)
{
	this->EndModal(0);

}

std::string LoadGame::GetNameOfUser()
{
	return users->name.at(this->table->GetSelection());
}
LoadGame::~LoadGame(void)
{
}


BEGIN_EVENT_TABLE(LoadGame, wxDialog)
	EVT_BUTTON   (3,        LoadGame::OnButtonLoadGame)
	EVT_BUTTON   (4,        LoadGame::OnButtonCancel)
END_EVENT_TABLE()
