#include "DialogForNewGame.h"
#include <wx/event.h>


DialogForNewGame::DialogForNewGame(wxWindow* parent,struct USERS* users) : wxDialog(parent, 1, "Create a new game", wxDefaultPosition, wxDefaultSize)
{
	this->Show(true);
	this->GetSize(&height, &wight);
	/*okButton = new wxButton(this, 2, language->getValue("OkButton"), wxPoint(height/6, 7*wight/10), wxSize(height/6, wight/10));
	cancelButton = new wxButton(this, 3, language->getValue("CancelButton"), wxPoint(4*height/6, 7*wight/10), wxSize(height/6, wight/10));
	text = new wxTextCtrl(this,wxID_ANY, wxT(""),wxPoint(height/6, 3*wight/10), wxSize(4*height/6, wight/10));
	textUnder = new wxStaticText(this, wxID_ANY, language->getValue("dialogForInputNewNameTextUnder"),wxPoint(height/6, wight/10), wxSize(4*height/6, wight/10),wxTE_READONLY);
	textError = new wxTextCtrl(this, 5, wxT(""),wxPoint(height/6, 5*wight/10), wxSize(4*height/6, wight/10),wxTE_READONLY);*/
	okButton = new wxButton(this, 2, "Ok", wxPoint(height/6, 7*wight/10), wxSize(height/6, wight/10));
	cancelButton = new wxButton(this, 3, "Cancel", wxPoint(4*height/6, 7*wight/10), wxSize(height/6, wight/10));
	text = new wxTextCtrl(this,wxID_ANY, wxT(""),wxPoint(height/6, 3*wight/10), wxSize(4*height/6, wight/10));
	textUnder = new wxStaticText(this, wxID_ANY, "Input name:",wxPoint(height/6, wight/10), wxSize(4*height/6, wight/10),wxTE_READONLY);
	textError = new wxTextCtrl(this, 5, wxT(""),wxPoint(height/6, 5*wight/10), wxSize(4*height/6, wight/10),wxTE_READONLY);
	this->users = users;
}

void DialogForNewGame::OnButtonOk(wxCommandEvent& event)
{
	if (FindUser(this->text->GetValue().ToStdString(),users) == false)
		this->EndModal(1);
	else
	{
		this->textError->SetValue("This user is already exist!");
	}
}

void DialogForNewGame::OnButtonCancel(wxCommandEvent& event)
{
	this->EndModal(0);
}

std::string DialogForNewGame::GetNameOfUser()
{
	return this->text->GetValue();
}
void DialogForNewGame::OnText(wxCommandEvent& event)
{
}
BEGIN_EVENT_TABLE(DialogForNewGame, wxDialog)
	EVT_BUTTON   (2,        DialogForNewGame::OnButtonOk)
	EVT_BUTTON   (3,        DialogForNewGame::OnButtonCancel)
END_EVENT_TABLE()
