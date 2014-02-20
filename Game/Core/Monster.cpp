#include "Monster.h"

Monster::Monster(Level* level, wxString type, std::vector <Monster*> monsters):direction(1)
{
	wxImage::AddHandler(new wxPNGHandler);
	this->type = type;
	wxBitmap* bmp = new wxBitmap("Image/"+type+".png", wxBITMAP_TYPE_PNG);
	SetImage(bmp);
	SetCurrentImage(GetImage()->GetSubBitmap(wxRect(0,0,20,30)));
	SetCurrentLevel(level);
	SetSpeed(5);
	wxPoint p = FindPosition(monsters);
	SetPosition(p);
}

int Monster::Move(int direction)
{
	bool p = GetP();
	int x = 0, y = 0;
	Level* level = GetCurrentLevel();
	wxPoint newP;
	switch(this->direction)
	{
	case 1:
		newP = GetPosition()+wxSize(-GetSpeed(),0);
			if (newP.x % 20 == 0)
		{
			SetPosition(GetPosition()+=wxSize(-GetSpeed(),0));
			if (p == true)
				SetCurrentImage(GetImage()->GetSubBitmap(wxRect(20,0,20,30)));
			else
				SetCurrentImage(GetImage()->GetSubBitmap(wxRect(0,0,20,30)));

			return true;
		}
		else
		{
			x = (int)(newP.x / 20);
			y = (int)(newP.y / 20);
			if (level->GetArr()[y + 1][x] != 1)
			{
				SetPosition(GetPosition()+=wxSize(-GetSpeed(),0));
				if (p == true)
					SetCurrentImage(GetImage()->GetSubBitmap(wxRect(20,0,20,30)));
				else
					SetCurrentImage(GetImage()->GetSubBitmap(wxRect(0,0,20,30)));
				return true;
			}
		SetDirection();
		return false;
		}
		break;
	case 2:
		newP = GetPosition()+wxSize(GetSpeed(),0);
		if (newP.x % 20 == 0)
		{
			SetPosition(GetPosition()+=wxSize(GetSpeed(),0));
			if (p == true)
				SetCurrentImage(GetImage()->GetSubBitmap(wxRect(40,0,20,30)));
			else
				SetCurrentImage(GetImage()->GetSubBitmap(wxRect(60,0,20,30)));

			return true;
		}
		else
		{
			x = (int)(newP.x / 20) + 1;
			y = (int)(newP.y / 20);

			if (level->GetArr()[y + 1][x] == 0 && level->GetArr()[y + 2][x] == 0)
				return false;
			if (level->GetArr()[y + 1][x] != 1)
			{
				SetPosition(GetPosition()+=wxSize(GetSpeed(),0));
				if (p == true)
					SetCurrentImage(GetImage()->GetSubBitmap(wxRect(40,0,20,30)));
				else
					SetCurrentImage(GetImage()->GetSubBitmap(wxRect(60,0,20,30)));

				return true;
			}
		}
		SetDirection();
		return false;
		break;
	default:
		break;
	}
	
	
	
}

wxPoint Monster::FindPosition(std::vector <Monster*> monsters)
{
	wxPoint p(rand()%GetCurrentLevel()->GetW(),rand()%GetCurrentLevel()->GetH());
	bool did = true;
	while(1)
	{
		while(1)
		{
			did = true;
			if (GetCurrentLevel()->GetArr()[p.y][p.x] == 0 && (GetCurrentLevel()->GetArr()[p.y + 1][p.x] == 0 || GetCurrentLevel()->GetArr()[p.y + 1][p.x] == 3) && (GetCurrentLevel()->GetArr()[p.y + 2][p.x] == 1 || GetCurrentLevel()->GetArr()[p.y + 2][p.x] == 4))
				break;
			else
			{
				p.x = rand()%GetCurrentLevel()->GetW();
				p.y = rand()%GetCurrentLevel()->GetH();
			}
		}


		for(int i = 0; i < monsters.size(); i++)
		{
			if (p.x*20 == monsters.at(i)->GetPosition().x && p.y*20 == monsters.at(i)->GetPosition().y)
			{
				did = false;
			}
		}

		if (did == true)
			break;

	}
	return wxPoint(p.x*20,p.y*20+10);
}

void Monster::Fight()
{
}
void Monster::Death()
{
}
void Monster::LevelUp()
{
}

void Monster::SetDirection()
{
	if (direction == 1)
		direction = 2;
	else
		direction = 1;
}