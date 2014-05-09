#pragma once

//#include "Player.h"
#include "Unit.h"
#include <vector>

class Monster : public Unit
{
public:
	Monster(Level* level, wxString type, std::vector <Monster*> monster, int nl);
	~Monster();
	virtual int Move(int direction);
	void Fight(Unit* player);
	virtual void Death();
	virtual void LevelUp();

	void SetDirection();

	wxPoint FindPosition(std::vector <Monster*> monsters);
private:
	wxString type;
	int direction;
};