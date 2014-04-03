#include "Unit.h"

int Unit::GetHealth() const
{
	return health;
}

int Unit::GetDamage() const
{
	return damage;
}

int Unit::GetSpeed() const
{
	return speed;
}

int Unit::GetMana() const
{
	return mana;
}

int Unit::GetDefence() const
{
	return defence;
}

int Unit::GetFactor() const
{
	return k;
}

int Unit::GetLevelOfEx() const
{
	return level;
}
wxPoint Unit::GetPosition() const
{
	return coordinate;
}

wxBitmap* Unit::GetImage() const
{
	return image;
}

wxBitmap Unit::GetCurrentImage() const
{
	return currentImage;
}

Level* Unit::GetCurrentLevel() const
{
	return currentLevel;
}

void Unit::HealthUp(int value)
{
	if (health+value >= (k*level)*100)
		health = (k*level)*100;
	else
		health += value;
}

bool Unit::HealthDown(int value)
{
	if (health - value <= 0)
		return false;
	else
		health -= value;
	return true;
}

void Unit::ManaUp(int value)
{
	if (mana+value >= (k*level)*50)
		mana = (k*level)*50;
	else
		mana += value;
}

bool Unit::ManaDown(int value)
{
	if (mana - value >= 0)
		mana -= value;
	else
		return false;
	return true;
}

void Unit::SetSpeed(int value)
{
	speed = value;
}

void Unit::SetDamage(int value)
{
	damage = value;
}

void Unit::SetDefence(int value)
{
	defence = value;
}

void Unit::SetImage(wxBitmap* value)
{
	image = value;
}

void Unit::SetHealth(int value)
{
	health = value;
}

void Unit::SetMana(int value)
{
	mana = value;
}

void Unit::SetLevelOfEx(int value)
{
	level = value;
}

void Unit::SetFactor(int value)
{
	k = value;
}
void Unit::SetPosition(wxPoint value)
{
	coordinate = value;
}


void Unit::SetCurrentImage(wxBitmap bmp)
{
	currentImage = bmp;
}

void Unit::SetCurrentLevel(Level* value)
{
	currentLevel = value;
}

bool Unit::GetP()
{
	bool t = p;
	if (p == true)
		p = false;
	else
		p = true;
	return t;
}
