#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <wx/image.h>
#include <wx/imaglist.h>
#include <wx/bitmap.h>
using namespace std;

class Level
{
public:
	Level(int _n, int _m, int _chest_n, bool _sealed);
	Level(string file_name);
	void Save(string file_name) const;
	int** GetArr() const;
	int GetW() const;
	int GetH() const;
	~Level(void);
private:
	int** map;
	int h;
	int w;
	bool sealed;
};

