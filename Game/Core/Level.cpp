#include "Level.h"

Level::Level(int _n, int _m, int _chest_n, bool _sealed)
{
	srand(time(0));
	int wall = 1;
	int back = 0;
	int teleport = 6;
	int chest = 3;
	int ladder = 4;

	h = _n;
	w = _m;
	int chest_n = _chest_n;
	sealed = _sealed;
	int** arr = new int*[h];

	for (int i = 0; i < h; i++)
	{
		arr[i] = new int[w];
	}
	//создание внешних стен
	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < w; j++)
		{
			arr[i][j] = 0;
			if (i == 0 || i == h-1)
				arr[i][j] = wall;
			if (j == 0 || j == w-1)
				arr[i][j] = wall;

		}
	}
	// создание уровней
	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < w; j++)
		{
			if (i%2 == 0)
				arr[i][j] = wall;

		}
	}
	//создание перегородок в уровнях
	for (int i = 1; i < h-1; i++)
	{
		int b = 0;
		for (int j = 1; j < w-1; j++)
		{
			int a = rand()%10;
			if (a == 0)
			{
				if (arr[i][j] == back)
				{
					arr[i][j] = wall;
					b++;
				}
			}
		}
		if (b == 0)
		{
			arr[i][rand()%(w-3)+1] = wall;
		}
	}

	

	// создание переходов между уровнями
	for (int i = 1; i < h-1; i++)
	{
		for (int j = 1; j < w-1; j++)
		{
			int count = 0;
			int s = 0;
			int f = 0;
			int b = 0;
			if (arr[i-1][j] == back)
				count++;
			if(arr[i+1][j] == back)
				count++;
			if (arr[i][j+1] == back)
				count++;
			if (arr[i][j-1] == back)
				count++;
			if (arr[i][j] == back && count < 2)
			{
				//int a = rand()%2;
				//if (a == 0)
				//{
					if (i+1 != h-1)
					{
						arr[i+1][j] = back;
						s = j;
						b++;
					}
					//**add
					if (i+1 == h-1)
					{
						arr[i-1][j] = back;
						s = j;
						b++;
					}
					
					while (arr[i][j] != wall)
						j++;
					f = j-1;
					if (i+1 != h-1 && j-1 != 0)
					{
						arr[i+1][j-1] = back;
						b++;
						
					}
					if (i+1 != h-1)
					{
						if (b == 0)
							arr[i+1][rand()%(f-s)+s] = back;
						b++;
					}
				//}

			}
			if (b == 0 && i+1 != h-1)
				arr[i+1][rand()%(w-2)+1] = back;
		}
	}

	int enter = rand()%(w-3)+2;
	int exit = rand()%(w-3)+2;

	arr[0][enter] = ladder;
	arr[1][enter] = ladder;
	arr[1][enter-1] = back;
	arr[h-1][exit] = ladder;
	arr[h-2][exit] = back;

	//создание лестниц
	for (int i = 1; i < h-1; i++)
	{
		for (int j = 1; j < w-1; j++)
		{
			int count = 0;
			if (arr[i-1][j] == back)
				count++;
			if(arr[i+1][j] == back)
				count++;
			if (arr[i][j+1] == back)
				count+=3;
			if (arr[i][j-1] == back)
				count+=3;
			if (count == 2 && arr[i][j] == back)
			{
				//arr[i-1][j] = 4;
				arr[i+1][j] = ladder;
				arr[i][j] = ladder;
			}

		}
	}
	for (int i = 1; i < h-1; i++)
	{
		for (int j = 1; j < w-1; j++)
		{
			if (arr[i][j] == ladder && arr[i+1][j] == back)
			{
				arr[i+1][j] = ladder;
			}
		}
	}
	//убирание дыр
	for (int i = 1; i < h-1; i++)
	{
		for (int j = 1; j < w-1; j++)
		{
			if (i%2 == 0 && arr[i][j] == back)
			{
				arr[i][j] = wall;
			}
		}
	}
	//создание телепорта
	int teleport_x = rand()%(w-2)+1;
	int teleport_y = rand()%(h-2)+1;

	if (arr[teleport_y][teleport_x] == back)
		arr[teleport_y][teleport_x] = teleport;
	else
	{
		for (int i = 0; i < h; i++)
		{
			for (int j = 0; j < w; j++)
			{
				if (arr[(teleport_y+i)%(h-2)+1][(teleport_x+j)%(w-2)+1] == back)
				{
					teleport_x = (teleport_x + j)%(w-2)+1;
					teleport_y = (teleport_y + i)%(h-2)+1;
					if (arr[teleport_y+1][teleport_x] == wall && arr[teleport_y-1][teleport_x] == wall)
					{
						arr[teleport_y][teleport_x] = teleport;
						break;
					}
				}
			}
			if (arr[teleport_y][teleport_x] == teleport)
				break;
		}
	}

	cteleport.x = -1;
	cteleport.y = -1;
	//создание сундуков

	int count = 0;
	while (count != chest_n)
	{
		for (int i = 1; i < h-1; i++)
		{
			for (int j = 1; j < w-1; j++)
			{
				if (count == chest_n)
					break;

				int a  = rand()%(w*h);

				if (a == 0)
				{
					if (arr[i][j] == back && arr[i-1][j] == wall && arr[i+1][j] == wall)
					{
						arr[i][j] = chest;
						count++;
					}
				}
			}
		}
	}

	
	map = new int*[2*h-1];

	for (int i = 0; i < 2*h-1; i++)
		map[i] = new int[w];
	int t = 0;
	for (int i = 0; i < h; i++)
	{
		if (i%2 != 0)
		{
			for (int j = 0; j < w; j++)
			{
				if (arr[i][j] == 3 || arr[i][j] == 5 || arr[i][j] == 2 || arr[i][j] == 6)
				{
					map[t][j] = back;
					map[t+1][j] = back;
					map[t+2][j] = arr[i][j];
				}
				else
				{
					map[t][j] = arr[i][j];
					map[t+1][j] = arr[i][j];
					map[t+2][j] = arr[i][j];
				}
				
			}
			t+=3;
		}
		else
		{
			for (int j = 0; j < w; j++)
			{
				map[t][j] = arr[i][j];
			}
			t++;
		}
		
	}
	h = 2*h-1;

}

Level::Level(string file_name)
{
	ifstream file(file_name.c_str());
	string type;
	file >> type;

	file >> h >> w;
	int a, b, c;
	file >> a;

	map = new int*[h];

	for (int i = 0; i < h; i++)
	{
		map[i] = new int[w];
	}

	int i = 0, j = 0;
	while (1)
	{
		file >> a >> b >> c;

		if (a == 255 && b == 255 && c == 255)
		{
			map[i][j] = 0;
			j++;
		}
		else if (a == 0 && b == 0 && c == 0)
		{
			map[i][j] = 1;
			j++;
		}
		else if (a == 0 && b == 0 && c == 255)
		{
			map[i][j] = 2;
			cteleport.x = j;
			cteleport.y = i;
			j++;
		}
		else if (a == 0 && b == 255 && c == 0)
		{
			map[i][j] = 3;
			j++;
		}
		else if (a == 255 && b == 0 && c == 0)
		{
			map[i][j] = 4;
			j++;
		}
		else if (a == 0 && b == 255 && c == 255)//open chest
		{
			map[i][j] = 5;
			j++;
		}
		else if (a == 255 && b == 0 && c == 255)//deactivate portals
		{
			map[i][j] = 6;
			cteleport.x = -1;
			cteleport.y = -1;
			j++;
		}
		if (j == w)
		{
			j = 0;
			i++;
		}
		if (i == h)
			break;
	}

	file.close();

	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < w; j++)
		{
			cout << map[i][j];

		}
		cout << endl;
	}
	sealed = false;
}

Level::Level()
{
	//create final level
	int wall = 1;
	int back = 0;
	int teleport = 6;
	int chest = 3;
	int ladder = 4;

	h = 10;
	w = 10;
	map = new int*[h];

	for (int i = 0; i < h; i++)
	{
		map[i] = new int[w];
	}
	//создание внешних стен
	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < w; j++)
		{
			map[i][j] = 0;
			if (i == 0 || i == h-1)
				map[i][j] = wall;
			if (j == 0 || j == w-1)
				map[i][j] = wall;

		}
	}

	for(int i = 0; i < h-1; i++)
		map[i][1] = ladder;

	Save("Image/FinalLevel.png");

}
void Level::Save(string file_name) const
{
	ofstream file(file_name.c_str());
	file << "P3" << endl;
	file << h << " " << w << endl;
	file << 255 << endl;
	//file <<	255 << " " << 0 << " " << 0 << endl;
	//file <<	0 << " " << 255 << " " << 0 << endl;
	//file <<	0 << " " << 0 << " " << 255 << endl;
	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < w; j++)
		{
			switch(map[i][j])
			{
			case 0: file << "255 255 255" << endl; break;
			case 1: file << "0 0 0" << endl; break;
			case 2: file << "0 0 255" << endl; break;
			case 3: file << "0 255 0" << endl; break;
			case 4: file << "255 0 0" << endl; break;
			case 5: file << "0 255 255" << endl; break;
			case 6: file << "255 0 255" << endl; break;
			default: break;
			}
			
		}
		//file << endl;
	}
	file.close();
}
Level::~Level(void)
{
	for (int i = 0; i < h; i++)
	{
		delete [] map[i];
	}

	delete [] map;
}

int Level::GetW() const
{
	return w;
}

int Level::GetH() const
{
	return h;
}
int** Level::GetArr() const
{
	return map;
}

bool Level::OpenChest(wxPoint point)
{
	this->map[point.x][point.y] = 5;
	return true;
}

bool Level::ActivatePortal(wxPoint point)
{
	this->map[point.x][point.y] = 2;
	cteleport.x = point.y;
	cteleport.y = point.x;
	return true;
}

wxPoint Level::GetCT() const
{
	return cteleport;
}