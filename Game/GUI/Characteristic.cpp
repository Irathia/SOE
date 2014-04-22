#include "Characteristic.h"
#include <wx/sizer.h>
#include <wx/spinctrl.h>
#include <wx/button.h>

Characteristic::Characteristic(wxWindow* parent, Player* player):wxDialog(parent,wxID_ANY,"Characterictic")
{
	
	this->player = player;
	n_health = new wxSpinCtrl(this, 101,wxString::Format(wxT("%i"), player->GetFactor(0)), wxDefaultPosition, wxDefaultSize, 0, 1, 100, 1);
	n_mana = new wxSpinCtrl(this, 102,wxString::Format(wxT("%i"), player->GetFactor(1)), wxDefaultPosition, wxDefaultSize, 0, 1, 100, 1);
	n_strength = new wxSpinCtrl(this, 103,wxString::Format(wxT("%i"), player->GetFactor(2)), wxDefaultPosition, wxDefaultSize, 0, 1, 100, 1);
    n_magic = new wxSpinCtrl(this, 104, wxString::Format(wxT("%i"), player->GetFactor(3)), wxDefaultPosition, wxDefaultSize, 0, 1, 100, 1);
	n_agility = new wxSpinCtrl(this, 105, wxString::Format(wxT("%i"), player->GetFactor(4)), wxDefaultPosition, wxDefaultSize, 0, 1, 100, 1);
	this->Connect(wxEVT_PAINT, wxPaintEventHandler(Characteristic::OnPaint));
}

void Characteristic::OnPaint(wxPaintEvent& event)
{
    wxBoxSizer* BoxSizer2;
    wxGridSizer* GridSizer1;
    wxBoxSizer* BoxSizer1;
    wxBoxSizer* BoxSizer3;

	


    BoxSizer1 = new wxBoxSizer(wxVERTICAL);
    GridSizer1 = new wxGridSizer(5, 2, 0, 0);
    t_health = new wxStaticText(this, wxID_ANY, _("Health"));//, wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT1"));
    GridSizer1->Add(t_health, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    
    GridSizer1->Add(n_health, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    t_mana = new wxStaticText(this, wxID_ANY, _("Mana"));//, wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT2"));
    GridSizer1->Add(t_mana, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);

    GridSizer1->Add(n_mana, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    t_strength = new wxStaticText(this, wxID_ANY, _("Strength"));//, wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT3"));
    GridSizer1->Add(t_strength, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    
    GridSizer1->Add(n_strength, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    t_magic = new wxStaticText(this, wxID_ANY, _("Magic"));//, wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT4"));
    GridSizer1->Add(t_magic, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    
   // n_magic->SetValue(_T("1"));
    GridSizer1->Add(n_magic, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    t_agility = new wxStaticText(this, wxID_ANY, _("Agility"));//, wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT5"));
    GridSizer1->Add(t_agility, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
   
    //n_agility->SetValue(_T("1"));
    GridSizer1->Add(n_agility, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer1->Add(GridSizer1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer2 = new wxBoxSizer(wxHORIZONTAL);
    BoxSizer3 = new wxBoxSizer(wxHORIZONTAL);
    t_text = new wxStaticText(this, wxID_ANY, _("Number of points"));//, wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT6"));
    BoxSizer3->Add(t_text, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    n_notUsed = new wxStaticText(this, wxID_ANY, _("0"));//, wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT7"));
    BoxSizer3->Add(n_notUsed, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer2->Add(BoxSizer3, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    Ok = new wxButton(this, 6, _("Ok"));//, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON1"));
    BoxSizer2->Add(Ok, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer1->Add(BoxSizer2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    SetSizer(BoxSizer1);

	n_health->SetValue(player->GetFactor(0));
	n_mana->SetValue(player->GetFactor(1));
	n_strength->SetValue(player->GetFactor(2));
	n_magic->SetValue(player->GetFactor(3));
	n_agility->SetValue(player->GetFactor(4));
	n_notUsed->SetLabelText(wxString::Format(wxT("%i"),player->GetFactor(5)));

    BoxSizer1->Fit(this);
    BoxSizer1->SetSizeHints(this);
	Layout();
}

void Characteristic::ChangeHealth(wxSpinEvent& event)
{
	if (event.GetPosition() - player->GetFactor(0) > 0)
	{
		if (player->GetFactor(5) > 0)
		{
			player->SetFactor(5,player->GetFactor(5) - 1);
			player->SetFactor(0,n_health->GetValue());
			this->Refresh();
		}
		else
		{
			n_health->SetValue(n_health->GetValue() - 1);
			this->Refresh();
		}
	}
	if (event.GetPosition() - player->GetFactor(0) < 0)
	{
		if (player->GetFactor(0) != 1)
		{
			player->SetFactor(5,player->GetFactor(5) + 1);
			player->SetFactor(0,n_health->GetValue());
			this->Refresh();
		}
		else
		{
			n_health->SetValue(n_health->GetValue() + 1);
			this->Refresh();
		}
	}
	
}

void Characteristic::ChangeMana(wxSpinEvent& event)
{
	if (event.GetPosition() - player->GetFactor(1) > 0)
	{
		if (player->GetFactor(5) > 0)
		{
			player->SetFactor(5,player->GetFactor(5) - 1);
			player->SetFactor(1,n_mana->GetValue());
			this->Refresh();
		}
		else
		{
			n_mana->SetValue(n_mana->GetValue() - 1);
			this->Refresh();
		}
	}
	if (event.GetPosition() - player->GetFactor(1) < 0)
	{
		if (player->GetFactor(1) != 1)
		{
			player->SetFactor(5,player->GetFactor(5) + 1);
			player->SetFactor(1,n_mana->GetValue());
			this->Refresh();
		}
		else
		{
			n_mana->SetValue(n_mana->GetValue() + 1);
			this->Refresh();
		}
	}
}

void Characteristic::ChangeStrength(wxSpinEvent& event)
{
	if (event.GetPosition() - player->GetFactor(2) > 0)
	{
		if (player->GetFactor(5) > 0)
		{
			player->SetFactor(5,player->GetFactor(5) - 1);
			player->SetFactor(2,n_strength->GetValue());
			this->Refresh();
		}
		else
		{
			n_strength->SetValue(n_strength->GetValue() - 1);
			this->Refresh();
		}
	}
	if (event.GetPosition() - player->GetFactor(2) < 0)
	{
		if (player->GetFactor(2) != 1)
		{
			player->SetFactor(5,player->GetFactor(5) + 1);
			player->SetFactor(2,n_strength->GetValue());
			this->Refresh();
		}
		else
		{
			n_strength->SetValue(n_strength->GetValue() + 1);
			this->Refresh();
		}
	}
}

void Characteristic::ChangeMagic(wxSpinEvent& event)
{
	if (event.GetPosition() - player->GetFactor(3) > 0)
	{
		if (player->GetFactor(5) > 0)
		{
			player->SetFactor(5,player->GetFactor(5) - 1);
			player->SetFactor(3,n_magic->GetValue());
			this->Refresh();
		}
		else
		{
			n_magic->SetValue(n_magic->GetValue() + 1);
			this->Refresh();
		}
	}
	if (event.GetPosition() - player->GetFactor(3) < 0)
	{
		if (player->GetFactor(3) != 1)
		{
			player->SetFactor(5,player->GetFactor(5) + 1);
			player->SetFactor(3,n_magic->GetValue());
			this->Refresh();
		}
		else
		{
			n_magic->SetValue(n_magic->GetValue() + 1);
			this->Refresh();
		}
	}
}

void Characteristic::ChangeAgility(wxSpinEvent& event)
{
	if (event.GetPosition() - player->GetFactor(4) > 0)
	{
		if (player->GetFactor(5) > 0)
		{
			player->SetFactor(5,player->GetFactor(5) - 1);
			player->SetFactor(4,n_agility->GetValue());
			this->Refresh();
		}
		else
		{
			n_agility->SetValue(n_agility->GetValue() + 1);
			this->Refresh();
		}
	}
	if (event.GetPosition() - player->GetFactor(4) < 0)
	{
		if (player->GetFactor(4) != 1)
		{
			player->SetFactor(5,player->GetFactor(5) + 1);
			player->SetFactor(4,n_agility->GetValue());
			this->Refresh();
		}
		else
		{
			n_agility->SetValue(n_agility->GetValue() + 1);
			this->Refresh();
		}
	}
}
void Characteristic::OnOkClick(wxCommandEvent& event)
{
	/*player->SetFactor(0,n_health->GetValue());
	player->SetFactor(1,n_mana->GetValue());
	player->SetFactor(2,n_strength->GetValue());
	player->SetFactor(3,n_magic->GetValue());
	player->SetFactor(4,n_agility->GetValue());*/
	this->EndModal(1);
}


BEGIN_EVENT_TABLE(Characteristic, wxDialog)
	EVT_SPINCTRL (101,	Characteristic::ChangeHealth)
	EVT_SPINCTRL (102,	Characteristic::ChangeMana)
	EVT_SPINCTRL (103,	Characteristic::ChangeStrength)
	EVT_SPINCTRL (104,	Characteristic::ChangeMagic)
	EVT_SPINCTRL (105,	Characteristic::ChangeAgility)
	EVT_BUTTON (6,	Characteristic::OnOkClick)
	
END_EVENT_TABLE()