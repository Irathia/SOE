#include "Level.h"

Level::Level(int _n, int _m, int _chest_n, bool _sealed)
{
	int wall = 1;
	int back = 0;
	int teleport = 2;
	int chest = 3;
	int ladder = 4;

	n = _n;
	m = _m;
	int chest_n = _chest_n;
	sealed = _sealed;
	arr = new int*[m];

	for (int i = 0; i < m; i++)
	{
		arr[i] = new int[n];
	}
	//создание внешних стен
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			arr[i][j] = 0;
			if (i == 0 || i == m-1)
				arr[i][j] = wall;
			if (j == 0 || j == n-1)
				arr[i][j] = wall;

		}
	}
	// создание уровней
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (i%2 == 0)
				arr[i][j] = wall;

		}
	}
	//создание перегородок в уровнях
	for (int i = 1; i < m-1; i++)
	{
		for (int j = 1; j < n-1; j++)
		{
			int a = rand()%10;
			if (a == 0)
			{
				if (arr[i][j] == back)
					arr[i][j] = wall;
			}
		}
	}

	int enter = rand()%(n-2)+1;
	int exit = rand()%(n-2)+1;

	arr[0][enter] = ladder;
	arr[1][enter] = ladder;
	arr[1][enter-1] = back;
	arr[m-1][exit] = ladder;
	arr[m-2][exit] = back;

	// создание переходов между уровнями
	for (int i = 1; i < m-1; i++)
	{
		for (int j = 1; j < n-1; j++)
		{
			int count = 0;
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
				int a = rand()%2;
				if (a == 0)
				{
					if (i+1 != m-1)
						arr[i+1][j] = back;

					while (arr[i][j] != wall)
						j++;
				}
				else
				{
					while (arr[i][j] != wall)
						j++;

					if (i+1 != m-1 && j-1 != 0)
						arr[i+1][j-1] = back;
				}

			}
		}
	}

	//создание лестниц
	for (int i = 1; i < m-1; i++)
	{
		for (int j = 1; j < n-1; j++)
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

	//создание телепорта
	int teleport_x = rand()%(n-2)+1;
	int teleport_y = rand()%(m-2)+1;

	if (arr[teleport_y][teleport_x] == back)
		arr[teleport_y][teleport_x] = teleport;
	else
	{
		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (arr[(teleport_y+i)%(m-2)+1][(teleport_x+j)%(n-2)+1] == back)
				{
					teleport_x = (teleport_x + j)%(n-2)+1;
					teleport_y = (teleport_y + i)%(m-2)+1;
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

	//создание сундуков

	int count = 0;
	while (count != chest_n)
	{
		for (int i = 1; i < m-1; i++)
		{
			for (int j = 1; j < n-1; j++)
			{
				if (count == chest_n)
					break;

				int a  = rand()%(m*n);

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


}

Level::Level(string file_name)
{
	ifstream file(file_name.c_str());
	string type;
	file >> type;

	file >> n >> m;
	int a, b, c;
	file >> a;

	arr = new int*[m];

	for (int i = 0; i < m; i++)
	{
		arr[i] = new int[n];
	}

	int i = 0, j = 0;
	while (1)
	{
		file >> a >> b >> c;

		if (a == 255 && b == 255 && c == 255)
		{
			arr[i][j] = 0;
			j++;
		}
		else if (a == 0 && b == 0 && c == 0)
		{
			arr[i][j] = 1;
			j++;
		}
		else if (a == 0 && b == 0 && c == 255)
		{
			arr[i][j] = 2;
			j++;
		}
		else if (a == 0 && b == 255 && c == 0)
		{
			arr[i][j] = 3;
			j++;
		}
		else if (a == 255 && b == 0 && c == 0)
		{
			arr[i][j] = 4;
			j++;
		}
		if (j == n)
		{
			j = 0;
			i++;
		}
		if (i == m)
			break;
	}

	file.close();

	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << arr[i][j];

		}
		cout << endl;
	}
	sealed = false;
}
void Level::Save(string file_name) const
{
	ofstream file(file_name.c_str());
	file << "P3" << endl;
	file << n << " " << m << endl;
	file << 255 << endl;
	//file <<	255 << " " << 0 << " " << 0 << endl;
	//file <<	0 << " " << 255 << " " << 0 << endl;
	//file <<	0 << " " << 0 << " " << 255 << endl;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			switch(arr[i][j])
			{
			case 0: file << "255 255 255" << endl; break;
			case 1: file << "0 0 0" << endl; break;
			case 2: file << "0 0 255" << endl; break;
			case 3: file << "0 255 0" << endl; break;
			case 4: file << "255 0 0" << endl; break;
			default: break;
			}
			
		}
		//file << endl;
	}
	file.close();
}
Level::~Level(void)
{
	for (int i = 0; i < m; i++)
	{
		delete [] arr[i];
	}

	delete [] arr;
}


wxImageList* Level::CreateScene()
{
	int wall = 1;
	int back = 0;
	int teleport = 2;
	int chest = 3;
	int ladder = 4;
	wxBitmap b(20,20);
	wxImageList* scene= new wxImageList(this->m*20,this->n*20);
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			switch (arr[i][j])
			{
			case 1: 
				b.LoadFile("/Game/GUI/Image/SandBlock.bmp",wxBITMAP_TYPE_BMP);
				scene->Add(b);
				break;
			default: 
				b.LoadFile("/Game/GUI/Image/SandBlockBehind.bmp",wxBITMAP_TYPE_BMP);
				scene->Add(b);//scene.GetSubImage(wxRect(i*20,j*20,20,20)).SetMaskColour(0,255,0);//LoadFile("C:/Users/Админ/Documents/Visual Studio 2010/Projects/testWidgets/testWidgets/Game/Core/SandBlockBehind.bmp",wxBITMAP_TYPE_BMP);
				break;
			/*case back: scene.GetSubImage(i*20,j*20).LoadFile("SandBlock.bmp");
				break;
			case wall: scene.GetSubImage(i*20,j*20).LoadFile("SandBlock.bmp");
				break;
			case wall: scene.GetSubImage(i*20,j*20).LoadFile("SandBlock.bmp");
				break;*/
			}
		}
	}
	//wxImage im;
	//im.SaveFile("Level.bmp");
	return scene;
}