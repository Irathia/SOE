#pragma once

#include <wx/wx.h>
#include <wx/dialog.h>
#include <wx/textctrl.h>
#include <string>
#include <wx/grid.h>
#include "../../Resource/User.h"

class LoadGame : public wxDialog
{
public:
	LoadGame(wxWindow* parent,struct USERS* users,int wight, int height);
	~LoadGame(void);

	void OnButtonLoadGame(wxCommandEvent& event);
	void OnButtonCancel(wxCommandEvent& event);
	std::string GetNameOfUser();

	//void OnPaint(wxPaintEvent& event);
private:
	wxButton* load;
	wxButton* cancel;
	wxStaticText* text;
	wxListBox* table;

	USERS* users;

	DECLARE_EVENT_TABLE()
};

