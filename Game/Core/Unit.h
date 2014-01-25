#pragma once

#include <wx/image.h>
#include <wx/position.h>

class Unit
{
public:
	virtual void Move(int direction) = 0;
	virtual void Fight() = 0;
	virtual void Death() = 0;

	int GetHealth() const;
	int GetDamage() const;
	int GetSpeed() const;
	int GetMana() const;
	int GetDefence() const;
	int GetFactor() const;
	wxPoint GetPosition() const;
	wxImage* GetImage() const;

	void HealthUp(int value);
	void HealthDown(int value);
	void ManaUp(int value);
	bool ManaDown(int value);
	void SetSpeed(int value);
	void SetDamage(int value);
	void SetDefence(int value);
	void SetImage(wxImage* value);
	void SetPosition(wxPoint value);
private:
	int k;
	int health;
	int speed;
	int damage;
	int level;
	int mana;
	int defence;
	wxImage* image;
	wxPoint coordinate;
};