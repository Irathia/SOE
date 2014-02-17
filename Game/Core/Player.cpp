#include "Player.h"

Player::Player(wxPoint first)
{
	wxImage::AddHandler(new wxPNGHandler);
	SetPosition(first);
	wxBitmap* bmp = new wxBitmap("Image/Player.png", wxBITMAP_TYPE_PNG);
	SetImage(bmp);
	SetCurrentImage(GetImage()->GetSubBitmap(wxRect(60,0,20,30)));
	SetSpeed(5);
}
bool Player::Move(int direction, Level* level)
{
	/*
	RIGHT = 1
	LEFT = 2
	UP = 3
	DOWN = 4
	*/
	int x = 0;
	int y = 0;
	wxPoint newP(0,0);
	bool p = GetP();
	switch(direction)
	{
	case 1:
		newP = GetPosition()+wxSize(0,GetSpeed());
		y = (newP.y + 20) % 20;
		if (y == 0)
			y = newP.y / 20;
		else
			y = (int)((newP.y + 20) / 20);
		x = (int)(newP.x / 20);
		if (level->GetArr()[x][y] != 1)
		{
			SetPosition(GetPosition()+=wxSize(0,GetSpeed()));
			if (p == true)
				SetCurrentImage(GetImage()->GetSubBitmap(wxRect(0,0,20,30)));
			else
				SetCurrentImage(GetImage()->GetSubBitmap(wxRect(20,0,20,30)));

			return true;
		}
		return false;
		break;
	case 2:
		newP = GetPosition()+wxSize(0,-GetSpeed());
		y = (int)(newP.y / 20);
		x = (int)(newP.x / 20);
		if (level->GetArr()[x][y] != 1)
		{
			SetPosition(GetPosition()+=wxSize(0,-GetSpeed()));
			if (p == true)
				SetCurrentImage(GetImage()->GetSubBitmap(wxRect(100,0,20,30)));
			else
				SetCurrentImage(GetImage()->GetSubBitmap(wxRect(120,0,20,30)));

			return true;
		}
		return false;
		break;
	case 3:
		newP = GetPosition()+wxSize(-GetSpeed(),0);
		y = newP.y % 20;
		if (y != 0)
			return false;
		y = (newP.y / 20);
		x = (int)(newP.x / 20);
		if (level->GetArr()[x][y] != 1)
		{
			SetPosition(GetPosition()+=wxSize(-GetSpeed(),0));
			if (p == true)
				SetCurrentImage(GetImage()->GetSubBitmap(wxRect(60,0,20,30)));
			else
				SetCurrentImage(GetImage()->GetSubBitmap(wxRect(80,0,20,30)));

			return true;
		}
		return false;
		break;
	case 4:
		newP = GetPosition()+wxSize(GetSpeed(),0);
		y = newP.y % 20;
		if (y != 0)
			return false;
		y = (newP.y / 20);
		x = (int)((newP.x +30) / 20);
		if (level->GetArr()[x][y] != 1)
		{
			SetPosition(GetPosition()+=wxSize(GetSpeed(),0));
			if (p == true)
				SetCurrentImage(GetImage()->GetSubBitmap(wxRect(80,0,20,30)));
			else
				SetCurrentImage(GetImage()->GetSubBitmap(wxRect(60,0,20,30)));

			return true;
		}
		else
		{
			SetPosition(wxPoint(x*20-30,GetPosition().y));
			return true;
		}
		return false;
		break;
	default:
		break;
	}
}

void Player::Fight()
{
}

void Player::Death()
{
}

void Player::LevelUp()
{

}

bool Player::GetP()
{
	bool t = p;
	if (p == true)
		p = false;
	else
		p = true;
	return t;
}
