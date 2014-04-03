#pragma once

#include "Unit.h"
#include "Monster.h"
#include <vector>

class Player : public Unit
{
public:
	Player(wxPoint first, Level* level);
	virtual int Move(int direction);
	void Fight(int a,std::vector <Monster*>* units);
	virtual void Death();
	virtual void LevelUp();

	int GetDirection() const;
	void SetDirection(int value);

	int GetFight() const;
	void SetFight(int value);

	int GetExp() const;
	void SetExp(int value);

	bool GetDead() const;
private:
	int direction;
	int fight;
	int exp;
	bool dead;
};