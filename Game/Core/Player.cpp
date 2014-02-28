#include "Player.h"

Player::Player(wxPoint first, Level* level):direction(0),fight(0),dead(false)
{
	wxImage::AddHandler(new wxPNGHandler);
	SetDamage(10);
	SetPosition(first);
	SetHealth(20);
	wxBitmap* bmp = new wxBitmap("Image/Player.png", wxBITMAP_TYPE_PNG);
	SetImage(bmp);
	SetCurrentImage(GetImage()->GetSubBitmap(wxRect(60,0,20,30)));
	SetSpeed(5);
	SetCurrentLevel(level);
	
}
int Player::Move(int direction)
{
	Level* level = GetCurrentLevel();
	int const RIGHT = 1;
	int const LEFT = 2;
	int const UP = 3;
	int const DOWN = 4;
	
	int x = 0;
	int y = 0;
	wxPoint newP(0,0);
	bool p = GetP();

	switch(direction)
	{
	case RIGHT:
		newP = GetPosition()+wxSize(GetSpeed(),0);
		if ((newP.y + 10) % 20 != 0)
			return false;
		if (newP.x % 20 == 0)
		{
			SetPosition(GetPosition()+=wxSize(GetSpeed(),0));
			if (p == true)
				SetCurrentImage(GetImage()->GetSubBitmap(wxRect(0,0,20,30)));
			else
				SetCurrentImage(GetImage()->GetSubBitmap(wxRect(20,0,20,30)));

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
					SetCurrentImage(GetImage()->GetSubBitmap(wxRect(0,0,20,30)));
				else
					SetCurrentImage(GetImage()->GetSubBitmap(wxRect(20,0,20,30)));

				return true;
			}
		}
		return false;
		break;
	case LEFT:
		newP = GetPosition()+wxSize(-GetSpeed(),0);
		if ((newP.y + 10) % 20 != 0)
			return false;
		if (newP.x % 20 == 0)
		{
			SetPosition(GetPosition()+=wxSize(-GetSpeed(),0));
			if (p == false)
				SetCurrentImage(GetImage()->GetSubBitmap(wxRect(100,0,20,30)));
			else
				SetCurrentImage(GetImage()->GetSubBitmap(wxRect(120,0,20,30)));

			return true;
		}
		else
		{
			x = (int)(newP.x / 20);
			y = (int)(newP.y / 20);

			if (level->GetArr()[y + 1][x] == 0 && level->GetArr()[y + 2][y] == 0)
				return false;
			if (level->GetArr()[y + 1][x] != 1)
			{
				SetPosition(GetPosition()+=wxSize(-GetSpeed(),0));
				if (p == false)
					SetCurrentImage(GetImage()->GetSubBitmap(wxRect(100,0,20,30)));
				else
					SetCurrentImage(GetImage()->GetSubBitmap(wxRect(120,0,20,30)));


				return true;
			}
		}
		return false;
		break;
	case UP:
		newP = GetPosition()+wxSize(0,-GetSpeed());
		if (newP.x % 20 != 0)
			return false;
		if (newP.y % 20 == 0)
		{
			SetPosition(GetPosition()+=wxSize(0,-GetSpeed()));
			if (p == true)
				SetCurrentImage(GetImage()->GetSubBitmap(wxRect(60,0,20,30)));
			else
				SetCurrentImage(GetImage()->GetSubBitmap(wxRect(80,0,20,30)));

			return true;
		}
		else
		{
			x = newP.x / 20;
			y = (int)((newP.y + 30) / 20);
			if (level->GetArr()[y][x] == 4 || (level->GetArr()[y][x] == 1 && level->GetArr()[y - 1][x] == 4))
			{
				SetPosition(GetPosition()+=wxSize(0,-GetSpeed()));
				if (p == true)
					SetCurrentImage(GetImage()->GetSubBitmap(wxRect(60,0,20,30)));
				else
					SetCurrentImage(GetImage()->GetSubBitmap(wxRect(80,0,20,30)));


				return true;
			}
		}
		break;
	case DOWN:
		newP = GetPosition()+wxSize(0,GetSpeed());
		if (newP.x % 20 != 0)
			return false;
		if ((newP.y + 30) % 20 == 0)
		{
			SetPosition(GetPosition()+=wxSize(0,GetSpeed()));
			if (p == true)
				SetCurrentImage(GetImage()->GetSubBitmap(wxRect(60,0,20,30)));
			else
				SetCurrentImage(GetImage()->GetSubBitmap(wxRect(80,0,20,30)));

			return true;
		}
		else
		{
			x = newP.x / 20 ;
			y = (int)((newP.y + 30) / 20);
			if (level->GetArr()[y][x] != 1)
			{
				SetPosition(GetPosition()+=wxSize(0,GetSpeed()));
				if (p == true)
					SetCurrentImage(GetImage()->GetSubBitmap(wxRect(60,0,20,30)));
				else
					SetCurrentImage(GetImage()->GetSubBitmap(wxRect(80,0,20,30)));


				return true;
			}
		}
		return false;
		break;
	default:
		break;
	}
}

void Player::Fight(int a, std::vector <Monster*>* units)
{
	switch(a)
	{
	case 1:
		if (direction == -1)
		{
			SetCurrentImage(GetImage()->GetSubBitmap(wxRect(140,0,20,30)));
		}
		if (direction == -2)
		{
			SetCurrentImage(GetImage()->GetSubBitmap(wxRect(160,0,20,30)));
		}
		break;
	case 2:
		if (direction == -1)
		{
			SetCurrentImage(GetImage()->GetSubBitmap(wxRect(0,0,20,30)));

			for (int i = 0; i < units->size(); i++)
			{
				if (GetPosition().y == units->at(i)->GetPosition().y)
				{
					if (units->at(i)->GetPosition().x + 3 >= GetPosition().x + 14 && units->at(i)->GetPosition().x + 3 <= GetPosition().x + 20)
					{
						if (units->at(i)->HealthDown(this->GetDamage()) == false)
							units->erase(units->begin() + i);
						break;

						
					}
				}
			}
		}
		if (direction == -2)
		{
			SetCurrentImage(GetImage()->GetSubBitmap(wxRect(120,0,20,30)));

			for (int i = 0; i < units->size(); i++)
			{
				if (GetPosition().y == units->at(i)->GetPosition().y)
				{
					if (units->at(i)->GetPosition().x + 17 >= GetPosition().x && units->at(i)->GetPosition().x + 17 <= GetPosition().x + 6)
					{
						if (units->at(i)->HealthDown(this->GetDamage()) == false)
							units->erase(units->begin() + i);
						break;
					}
				}
			}
		}
		break;
	case 3:
		if (direction == -1)
		{
			SetCurrentImage(GetImage()->GetSubBitmap(wxRect(40,0,20,30)));
		}
		if (direction == -2)
		{
			SetCurrentImage(GetImage()->GetSubBitmap(wxRect(180,0,20,30)));
		}
		break;
	default:
		break;
	}
}

void Player::Death()
{
	dead = true;
}

void Player::LevelUp()
{

}

int Player::GetDirection() const
{
	return direction;
}

void Player::SetDirection(int value)
{
	direction = value;
}

int Player::GetFight() const
{
	return fight;
}

void Player::SetFight(int value)
{
	fight = value;
}

bool Player::GetDead() const
{
	return dead;
}