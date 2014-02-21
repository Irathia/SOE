#pragma once

#include "Unit.h"
#include <vector>

class Monster : public Unit
{
public:
	Monster(Level* level, wxString type, std::vector <Monster*> monster);
	virtual int Move(int direction);
	virtual void Fight(int a);
	virtual void Death();
	virtual void LevelUp();

	void SetDirection();

	wxPoint FindPosition(std::vector <Monster*> monsters);
private:
	wxString type;
	int direction;
};