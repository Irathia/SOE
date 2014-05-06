#pragma once

#include <wx/bitmap.h>
#include <wx/position.h>
#include "Level.h"

struct CHARACTERISTICS
{
	int health;
	int mana;
	int strength;
	int magic;
	int agility;
	int notUsed;
};

class Unit
{
public:
	//virtual void Fight(int a, std::vector <Unit*> units) = 0;
	virtual void Death() = 0;
	virtual int Move(int direction) = 0;
	int GetHealth() const;
	int GetBonus(int i) const;
	int GetDamage() const;
	int GetSpeed() const;
	int GetMana() const;
	int GetDefence() const;
	int GetFactor(int i) const;
	int GetLevelOfEx() const;
	//int GetHealth() const;
	wxPoint GetPosition() const;
	wxBitmap* GetImage() const;
	wxBitmap GetCurrentImage() const;
	Level* GetCurrentLevel() const;
	bool GetP();

	void HealthUp(int value);
	bool HealthDown(int value);
	void ManaUp(int value);
	bool ManaDown(int value);
	void SetSpeed(int value);
	void SetDamage(int value);
	void SetDefence(int value);
	void SetHealth(int value);
	void SetBonus(int i, int value);
	void SetMana(int value);
	void SetLevelOfEx(int value);
	void SetFactor(int i,int value);
	void SetImage(wxBitmap* value);
	void SetCurrentImage(wxBitmap bmp);
	void SetPosition(wxPoint value);
	void SetCurrentLevel(Level* value);
private:
	bool p;
	CHARACTERISTICS chs;

	int bonushealth;
	int bonusmana;
	int bonusagility;
	int bonusstrength;
	int bonusmagic;
	int bonusdefense;

	int health;
	int speed;
	int damage;
	int level;
	int mana;
	int defence;
	wxBitmap* image;
	wxBitmap currentImage;
	wxPoint coordinate;
	Level* currentLevel;
};

