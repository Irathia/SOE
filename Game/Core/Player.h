#pragma once

#include "Unit.h"
#include "Monster.h"
#include <vector>

class Player : public Unit
{
public:
	Player(wxPoint first, Level* level);
	Player(std::string name);
	virtual int Move(int direction);
	void Fight(int a,std::vector <Monster*>* units);
	virtual void Death();
	virtual void LevelUp();

	int GetDirection() const;
	void SetDirection(int value);

	int GetFight() const;
	void SetFight(int value);

	int GetExp() const;
	void SetExp(int value, bool flag = false);
	void Quality(wxString data, bool type);
	bool Teleport(wxString data);
	void DestroyWall();
	bool GetDead() const;

	void Save(std::string str, std::string name, int nl);
private:
	int direction;
	int fight;
	int exp;
	bool dead;
};