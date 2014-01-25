#pragma once

#include "Unit.h"

class Player : public Unit
{
public:
	Player(wxPoint first);
	virtual void Move(int direction);
	virtual void Fight();
	virtual void Death();
	virtual void LevelUp();
	int GetTypeI() const;
	void SetTypeI(int value);
	bool GetP();
private:
	int typeI;
	bool p;
};