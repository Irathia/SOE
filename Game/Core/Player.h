#pragma once

#include "Unit.h"

class Player : public Unit
{
public:
	Player(wxPoint first, Level* level);
	virtual int Move(int direction);
	virtual void Fight(int a);
	virtual void Death();
	virtual void LevelUp();
	int GetDirection() const;
	void SetDirection(int value);
private:
	int direction;
};