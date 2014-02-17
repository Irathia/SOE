#pragma once

#include "Unit.h"
#include "Level.h"

class Player : public Unit
{
public:
	Player(wxPoint first);
	bool Move(int direction, Level* level);
	virtual void Fight();
	virtual void Death();
	virtual void LevelUp();
	bool GetP();
private:
	bool p;
};