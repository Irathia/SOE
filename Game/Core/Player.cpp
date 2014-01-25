#include "Player.h"

Player::Player(wxPoint first)
{
	SetPosition(first);
	SetImage(new wxImage("Image/Player.png"));
	typeI = 3;
}
void Player::Move(int direction)
{
	/*
	RIGHT = 1
	LEFT = 2
	UP = 3
	DOWN = 4
	*/
	switch(direction)
	{
	case 1:
		SetPosition(GetPosition()+=wxSize(0,1));
		typeI = 1;
		break;
	case 2:
		SetPosition(GetPosition()+=wxSize(0,-1));
		typeI = 2;
		break;
	case 3:
		SetPosition(GetPosition()+=wxSize(-1,0));
		typeI = 3;
		break;
	case 4:
		SetPosition(GetPosition()+=wxSize(1,0));
		typeI = 4;
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

int Player::GetTypeI() const
{
	return typeI;
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

void Player::SetTypeI(int value)
{
	typeI = value;
}