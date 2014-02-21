#pragma once

#include <wx/bitmap.h>
#include <wx/position.h>
#include "Level.h"

class Unit
{
public:
	virtual void Fight(int a) = 0;
	virtual void Death() = 0;
	virtual int Move(int direction) = 0;
	int GetHealth() const;
	int GetDamage() const;
	int GetSpeed() const;
	int GetMana() const;
	int GetDefence() const;
	int GetFactor() const;
	wxPoint GetPosition() const;
	wxBitmap* GetImage() const;
	wxBitmap GetCurrentImage() const;
	Level* GetCurrentLevel() const;
	bool GetP();

	void HealthUp(int value);
	void HealthDown(int value);
	void ManaUp(int value);
	bool ManaDown(int value);
	void SetSpeed(int value);
	void SetDamage(int value);
	void SetDefence(int value);
	void SetImage(wxBitmap* value);
	void SetCurrentImage(wxBitmap bmp);
	void SetPosition(wxPoint value);
	void SetCurrentLevel(Level* value);
private:
	bool p;
	int k;
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