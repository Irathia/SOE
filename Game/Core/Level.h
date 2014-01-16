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
	wxImageList* CreateScene();
	
	~Level(void);
private:
	int** arr;
	int n;
	int m;
	bool sealed;
};

