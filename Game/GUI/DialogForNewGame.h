#pragma once

#include <wx/wx.h>
#include <wx/dialog.h>
#include <wx/textctrl.h>
#include <string>
#include "../../Resource/User.h"

class DialogForNewGame : public wxDialog
{
public:
	DialogForNewGame(wxWindow* parent,struct USERS* users);
	void OnButtonOk(wxCommandEvent& event);
	void OnButtonCancel(wxCommandEvent& event);
	void OnText(wxCommandEvent& event);

	std::string GetNameOfUser();
private:
	wxTextCtrl* text;
	wxButton* okButton;
	wxButton* cancelButton;
	wxStaticText* textUnder;
	wxTextCtrl* textError;

	struct USERS* users;

	int height;
	int wight;



	DECLARE_EVENT_TABLE()
};