#include "Info.h"
#include <wx/sizer.h>
#include <wx/dcmemory.h>

Info::Info(wxWindow* parent, Player* player, wxString name):wxPanel(parent)
{
	this->player = player;
	this->name = name;
	lvlc = player->GetLevelOfEx();
	expc = player->GetExp();
	manac = player->GetMana();
	healthc = player->GetHealth();

	Icon = new wxStaticBitmap(this,wxID_ANY, wxBitmap("Image/Icon.png",wxBITMAP_TYPE_PNG));
	LVL = new wxStaticBitmap(this,wxID_ANY,   wxBitmap("Image/Test.png",wxBITMAP_TYPE_PNG));
	Name = new wxStaticText(this, wxID_ANY, name);
    Exp = new wxStaticBitmap(this, wxID_ANY,wxBitmap());
	t_Exp = new wxStaticText(this,wxID_ANY,"");
	TextHealth = new wxStaticText(this, wxID_ANY, "Health:");
	Health = new wxStaticBitmap(this, wxID_ANY, wxBitmap());
	t_Health = new wxStaticText(this,wxID_ANY,"");
	TextMana = new wxStaticText(this, wxID_ANY, "Mana:");
	Mana = new wxStaticBitmap(this, wxID_ANY, wxBitmap());
	t_Mana = new wxStaticText(this,wxID_ANY,"");
	this->Connect(wxEVT_PAINT, wxPaintEventHandler(Info::OnPaint));
}

void Info::OnPaint(wxPaintEvent& event)
{
	wxBoxSizer* BoxSizer1;
	wxBoxSizer* BoxSizer2;
	wxBoxSizer* BoxSizer3;
	wxBoxSizer* BoxSizer4;
	wxBoxSizer* BoxSizer5;
	wxBoxSizer* BoxSizer6;
	wxBoxSizer* BoxSizer7;
	wxBoxSizer* BoxSizer8;

	wxBitmap bexp;
	wxBitmap bhealth;
	wxBitmap bmana;
	bexp.LoadFile("Image/Exp1.png",wxBITMAP_TYPE_PNG);
	bhealth.LoadFile("Image/Health1.png",wxBITMAP_TYPE_PNG);
	bmana.LoadFile("Image/Mana1.png",wxBITMAP_TYPE_PNG);

    BoxSizer1 = new wxBoxSizer(wxHORIZONTAL);
	//Icon = new wxStaticBitmap(this,wxID_ANY, wxBitmap("Image/Icon.png",wxBITMAP_TYPE_PNG));

	int a = player->GetLevelOfEx()/10;
	int b = player->GetLevelOfEx() - a*10;
	lvlc = player->GetLevelOfEx();
	expc = player->GetExp();
	manac = player->GetMana();
	healthc = player->GetHealth();
	wxBitmap l;
	l.Create(40,40);
	wxMemoryDC mc(l);
	wxBitmap Numlvl;
	Numlvl.LoadFile("Image/NumLvl.png",wxBITMAP_TYPE_PNG);

	mc.DrawBitmap(Numlvl.GetSubBitmap(wxRect(a*40,0,40,40)),0,0,true);
	mc.DrawBitmap(Numlvl.GetSubBitmap(wxRect(b*40,40,40,40)),0,0,true);
	l.SaveFile("Image/Test.png",wxBITMAP_TYPE_PNG);
	//LVL = new wxStaticBitmap(this,wxID_ANY,   wxBitmap("Image/Test.png",wxBITMAP_TYPE_PNG));
	BoxSizer1->Add(Icon, 2, wxALL|wxEXPAND, 0);
    BoxSizer1->Add(LVL, 1, wxALL|wxEXPAND, 0);

	BoxSizer2 = new wxBoxSizer(wxVERTICAL);
	/*Name = new wxStaticText(this, wxID_ANY, name);
    Exp = new wxStaticBitmap(this, wxID_ANY,wxBitmap());*/
	wxString tt2 = "";
	tt2 <<expc<<"/"<<player->GetLevelOfEx()*1000;
	//t_Exp = new wxStaticText(this,wxID_ANY,tt2);
	t_Exp->SetLabel(tt2);
	BoxSizer2->Add(Name, 1, wxALL|wxEXPAND, 2);
    BoxSizer2->Add(Exp, 2, wxALL|wxEXPAND, 2);
	BoxSizer2->Add(t_Exp, 1, wxALIGN_CENTER, 2);

	BoxSizer3 = new wxBoxSizer(wxHORIZONTAL);
	BoxSizer3->Add(BoxSizer1, 1, wxALL|wxEXPAND, 0);
	BoxSizer3->Add(BoxSizer2, 2, wxALL|wxEXPAND, 0);

	BoxSizer4 = new wxBoxSizer(wxHORIZONTAL);
    //TextHealth = new wxStaticText(this, wxID_ANY, "Health:");

    /*Health = new wxStaticBitmap(this, wxID_ANY, wxBitmap());
	wxString tt = "";
	tt.Clear();
	tt<< healthc<< "/" << player->GetFactor(0)*100+player->GetBonus(0);
	//t_Health->SetLabel(tt);
	t_Health = new wxStaticText(this,wxID_ANY,"");
	//t_Health->SetLabelText(tt);
	t_Health->SetLabel(tt);*/
	wxString tt = "";
	tt<< healthc<< "/" << player->GetFactor(0)*100+player->GetBonus(0);
	t_Health->SetLabel(tt);
	BoxSizer5 = new wxBoxSizer(wxVERTICAL);
	BoxSizer5->Add(Health,1, wxALL|wxEXPAND, 2);
	BoxSizer5->Add(t_Health,2,wxALIGN_CENTER, 2);

	BoxSizer4->Add(TextHealth, 1, wxALL|wxEXPAND, 2);
    BoxSizer4->Add(BoxSizer5, 2, wxALL|wxEXPAND, 2);

	BoxSizer6 = new wxBoxSizer(wxHORIZONTAL);
   // TextMana = new wxStaticText(this, wxID_ANY, "Mana:");
 //   Mana = new wxStaticBitmap(this, wxID_ANY, wxBitmap());
	wxString tt1 = "";
	tt1 <<manac<<"/"<<player->GetFactor(1)*80 + player->GetBonus(1);
//	t_Mana = new wxStaticText(this,wxID_ANY,"--------------");
	t_Mana->SetLabel(tt1);
	BoxSizer7 = new wxBoxSizer(wxVERTICAL);
	BoxSizer7->Add(Mana,1, wxEXPAND, 2);
	BoxSizer7->Add(t_Mana,2, wxALIGN_CENTER, 2);
	BoxSizer6->Add(TextMana, 1, wxALL|wxEXPAND, 2);
    BoxSizer6->Add(BoxSizer7, 2, wxALL|wxEXPAND, 2);

	BoxSizer8 = new wxBoxSizer(wxVERTICAL);
	BoxSizer8->Add(BoxSizer3, 1, wxALL|wxEXPAND, 0);
	BoxSizer8->Add(BoxSizer4, 1, wxALL|wxEXPAND, 0);
	BoxSizer8->Add(BoxSizer6, 1, wxALL|wxEXPAND, 0);
	
	double a1 = (double)healthc/((double)player->GetFactor(0)*100+player->GetBonus(0));
	double a2 = (double)manac/((double)player->GetFactor(1)*80+player->GetBonus(1));
	double a3 = (double)expc/((double)player->GetLevelOfEx()*1000);
	for (int i = 0; i < 100; i++)
	{
		double i1 = (double)i/(double)100;
		double i2 = ((double)(i + 1))/(double)100;
		if (a1 >= i1 && a1 <= i2)
		{
			if (a1 == i1)
				Health->SetBitmap(wxBitmap(bhealth.GetSubBitmap(wxRect(0,i*20,100,20))));
			else
			{
				if (a1 == i2)
					Health->SetBitmap(wxBitmap(bhealth.GetSubBitmap(wxRect(0,(i+1)*20,100,20))));
				else
					Health->SetBitmap(wxBitmap(bhealth.GetSubBitmap(wxRect(0,(i+1)*20,100,20))));
			}
		}
		if (a2 >= i1 && a2 <= i2)
		{
			if (a2 == i1)
				Mana->SetBitmap(wxBitmap(bmana.GetSubBitmap(wxRect(0,i*20,100,20))));
			else
			{
				if (a2 == i2)
					Mana->SetBitmap(wxBitmap(bmana.GetSubBitmap(wxRect(0,(i+1)*20,100,20))));
				else
					Mana->SetBitmap(wxBitmap(bmana.GetSubBitmap(wxRect(0,(i+1)*20,100,20))));
			}
		}
		if (a3 >= i1 && a3 <= i2)
		{
			if (a3 == i1)
				Exp->SetBitmap(wxBitmap(bexp.GetSubBitmap(wxRect(0,i*20,100,20))));
			else
			{
				if (a3 == i2)
					Exp->SetBitmap(wxBitmap(bexp.GetSubBitmap(wxRect(0,(i+1)*20,100,20))));
				else
					Exp->SetBitmap(wxBitmap(bexp.GetSubBitmap(wxRect(0,(i+1)*20,100,20))));
			}
		}
	}

	this->SetSizer(BoxSizer8);
	Layout();
}

bool Info::Information()
{
	bool a = false;
	if (expc != player->GetExp())
		a = true;
	if (manac != player->GetMana())
		a = true;
	if (healthc != player->GetHealth())
		a = true;
	if (lvlc != player->GetLevelOfEx())
		a = true;
	if (a == true)
		return true;
	return false;
}