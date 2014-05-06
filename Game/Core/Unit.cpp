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

int Unit::GetFactor(int i) const
{
	switch(i)
	{
	case 0:
		return chs.health;
		break;
	case 1:
		return chs.mana;
		break;
	case 2:
		return chs.strength;
		break;
	case 3:
		return chs.magic;
		break;
	case 4:
		return chs.agility;
		break;
	case 5:
		return chs.notUsed;
		break;
	default:
		break;
	}
	return 0;
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

int Unit::GetBonus(int i) const
{
	switch(i)
	{
	case 0:
		return bonushealth;
		break;
	case 1:
		return bonusmana;
		break;
	case 2:
		return bonusstrength;
		break;
	case 3:
		return bonusmagic;
		break;
	case 4:
		return bonusagility;
		break;
	case 5:
		return bonusdefense;
		break;
	default:
		break;
	}
	return 0;
}


void Unit::HealthUp(int value)
{
	if (health+value >= (chs.health)*100  + GetBonus(0))
		health = (chs.health)*100 + + GetBonus(0);
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
	if (mana+value >= (chs.mana)*80 + + GetBonus(1))
		mana = (chs.mana)*80 + + GetBonus(1);
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

void Unit::SetBonus(int i, int value)
{
	int diff = 0;
	switch(i)
	{
	case 0:
		bonushealth = value;
		break;
	case 1:
		bonusmana = value;
		break;
	case 2:
		bonusstrength = value;
		diff = value - bonusstrength;
		SetDamage(GetDamage() + diff);
		break;
	case 3:
		bonusmagic = value;
		//int diff = value - bonusstrength;
		//SetDamage(GetDamage() + diff);
		break;
	case 4:
		bonusagility = value;
		diff = value - bonusagility;
		SetSpeed(GetSpeed() + diff);
		break;
	case 5:
		bonusdefense = value;
		SetDefence(bonusdefense);
		break;
	default:
		break;
	}
}

void Unit::SetMana(int value)
{
	mana = value;
}

void Unit::SetLevelOfEx(int value)
{
	level = value;
}

void Unit::SetFactor(int i,int value)
{
	switch(i)
	{
	case 0:
		chs.health = value;
		break;
	case 1:
		chs.mana = value;
		break;
	case 2:
		chs.strength = value;
		SetDamage(value*10);
		break;
	case 3:
		chs.magic = value;
		break;
	case 4:
		chs.agility = value;
		SetSpeed(value*2);
		break;
	case 5:
		chs.notUsed = value;
		break;
	default:
		break;
	}
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
