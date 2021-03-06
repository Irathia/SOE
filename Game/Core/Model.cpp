#include "Model.h"
#include <wx/dcmemory.h>
#include <wx/event.h>
#include <wx/wx.h>
#include <wx/file.h>

Model::Model(Game* game):wxEvtHandler()
{
	this->game = game;
	wxImage::AddHandler(new wxPNGHandler);
	this->size = size;
	Level* zl = new Level(11,20,5, false);// zerro level h = 21*2-1 w = 50
	//Level* zl = new Level();
	levels.push_back(zl);
	currentLevel = 0;
	wxPoint p = FindPositionForPlayer(0);
	player = new Player(p,levels[currentLevel]);
	img = new wxBitmap(levels[0]->GetW()*20, levels[0]->GetH()*20);
	CreateImage(1);
	int numer = 10;
	for(int i = 0; i < numer; i++)
	{
		int t = rand()%2;
		if (t == 0)
		{
			Monster* m = new Monster(levels[currentLevel],wxString("Zomby"),monsters,currentLevel);
			monsters.push_back(m);
		}
		else
		{
			Monster* m = new Monster(levels[currentLevel],wxString("Mummy"),monsters,currentLevel);
			monsters.push_back(m);
		}

		
	}
	MonsterTimer = new wxTimer(this,1);
	MonsterTimer->Start(1000);

	PlayerTimer = new wxTimer(this,2);
	PlayerTimer->Start(200);
	counter = 0;
}

Model::Model(Game* game, bool flag, std::string name):wxEvtHandler()
{
	this->game = game;
	wxImage::AddHandler(new wxPNGHandler);
	this->size = size;
	int i = 0;
	while(wxFile::Exists("Save/"+name+"/"+std::to_string(i)+".png"))
	{
		Level* lv = new Level("Save/"+name+"/"+std::to_string(i)+".png");
		levels.push_back(lv);
		i++;
	}
	player = new Player(name);
	ifstream f("Save/"+name+"/Player.chs");
	f >> name;
	int b;
	f >> b;
	f.close();
	currentLevel = b;
	player->SetCurrentLevel(levels[currentLevel]);
	img = new wxBitmap(levels[currentLevel]->GetW()*20, levels[currentLevel]->GetH()*20);
	CreateImage(1);
	int numer = 10;
	for(int i = 0; i < numer + currentLevel*5; i++)
	{
		int t = rand()%2;
		if (t == 0)
		{
			Monster* m = new Monster(levels[currentLevel],wxString("Zomby"),monsters,currentLevel);
			monsters.push_back(m);
		}
		else
		{
			Monster* m = new Monster(levels[currentLevel],wxString("Mummy"),monsters,currentLevel);
			monsters.push_back(m);
		}

		
	}
	MonsterTimer = new wxTimer(this,1);
	MonsterTimer->Start(1000);

	PlayerTimer = new wxTimer(this,2);
	PlayerTimer->Start(200);
	counter = 0;
}
void Model::SetSize(wxSize size)
{
	this->size = size;
}

void Model::OnTimerMonster(wxTimerEvent& event)
{
	if (player->GetDead() == true)
	{
		MonsterTimer->Stop();
	}
	else
	{
		for(int i = 0; i < monsters.size(); i++)
		{
			monsters[i]->Move(0);
			monsters[i]->Fight(player);
			update(wxPoint(((int)((monsters[i]->GetPosition().x-monsters[i]->GetSpeed())/20))*20,((int)((monsters[i]->GetPosition().y-10)/20))*20),CreateSubImage(wxPoint((int)((monsters[i]->GetPosition().x-monsters[i]->GetSpeed())/20),(int)((monsters[i]->GetPosition().y-10)/20)),wxPoint((int)((monsters[i]->GetPosition().x+20+monsters[i]->GetSpeed())/20)+1,(int)((monsters[i]->GetPosition().y+30)/20))));
		}
	}
	
	
}

void Model::GoToLevel(int value, bool teleport)
{
	//clear all
	
	if (value == 30)
	{
		PlayerTimer->Stop();
		MonsterTimer->Stop();
		monsters.clear();
		Level* zl = new Level();
		levels.push_back(zl);
		currentLevel = value;
		wxPoint p = FindPositionForPlayer(0);
		player->SetPosition(p);
		player->SetCurrentLevel(levels.at(currentLevel));
		PlayerTimer->Start(200);
		wxMemoryDC mc(*img);
		mc.Clear();
		wxBitmap b("Image/FinishLevelP.png",wxBITMAP_TYPE_PNG);
		mc.DrawBitmap(b,0,0);
		counter = 0;
		player->SetDirection(-1*player->GetDirection());
		return;
	}
	
	if (teleport == false)
	{
		PlayerTimer->Stop();
		MonsterTimer->Stop();
		int nofm = monsters.size();
		monsters.clear();
		if (value < levels.size())
		{
			wxPoint p;
			int nn = 0;
			if (currentLevel < value)
			{
				currentLevel = value;
				p = FindPositionForPlayer(0);
				player->SetPosition(p);
				nn = nofm - currentLevel*5;
			}
			else
			{
				currentLevel = value;
				p = FindPositionForPlayer(1);
				player->SetPosition(p-wxSize(0,30));
				nn = nofm + currentLevel*5;
			}
		
		
		
			player->SetCurrentLevel(levels.at(currentLevel));
			for(int i = 0; i < nn; i++)
			{
				int t = rand()%2;
				if (t == 0)
				{
					Monster* m = new Monster(levels[currentLevel],wxString("Zomby"),monsters,currentLevel);
					monsters.push_back(m);
				}
				else
				{
					Monster* m = new Monster(levels[currentLevel],wxString("Mummy"),monsters,currentLevel);
					monsters.push_back(m);
				}

		
			}
			MonsterTimer->Start(1000);
			PlayerTimer->Start(200);
			CreateImage();
			counter = 0;
			player->SetDirection(-1*player->GetDirection());
		}
		else
		{
			currentLevel = value;
			if (currentLevel%2 == 0)
			{//11,20,5
				Level* zl = new Level(11+currentLevel*5,20+currentLevel*5,5+currentLevel*5, false);
				levels.push_back(zl);
			}
			else
			{
				Level* zl = new Level(11+currentLevel*4,20+(currentLevel-1)*5,5+currentLevel*5, false);
				levels.push_back(zl);
			}
	
			wxPoint p = FindPositionForPlayer(0);
			player->SetPosition(p);
			player->SetCurrentLevel(levels.at(currentLevel));
			img = new wxBitmap(levels[currentLevel]->GetW()*20, levels[currentLevel]->GetH()*20);
		
			for(int i = 0; i < nofm + currentLevel*5; i++)
			{
				int t = rand()%2;
				if (t == 0)
				{
					Monster* m = new Monster(levels[currentLevel],wxString("Zomby"),monsters,currentLevel);
					monsters.push_back(m);
				}
				else
				{
					Monster* m = new Monster(levels[currentLevel],wxString("Mummy"),monsters,currentLevel);
					monsters.push_back(m);
				}

		
			}
			//MonsterTimer = new wxTimer(this,1);
			MonsterTimer->Start(1000);

			//PlayerTimer = new wxTimer(this,2);
			PlayerTimer->Start(200);
			CreateImage();
			counter = 0;
			player->SetDirection(-1*player->GetDirection());
		}
	}
	else//teleporting
	{
		wxPoint ct = levels[currentLevel]->GetCT();
		wxPoint nct = levels[value]->GetCT();

		wxPoint p = player->GetPosition();
		int x = (int)p.x/20;
		int y = (int)(p.y+10)/20;
		if (ct.x == -1 || ct.y == -1)
			return;
		if (x - 1 <= ct.x && x + 1 >= ct.x && y - 1 <= ct.y && y + 1 >= ct.y)
		{
			PlayerTimer->Stop();
			MonsterTimer->Stop();
			int nofm = monsters.size();
			monsters.clear();
			int nn = 0;
			if (currentLevel < value)
			{
				currentLevel = value;
				nn = nofm - currentLevel*5;
			}
			else
			{
				currentLevel = value;
				nn = nofm + currentLevel*5;
			}
			player->SetCurrentLevel(levels.at(currentLevel));
			player->SetPosition(wxPoint(nct.x*20,nct.y*20-10));
			for(int i = 0; i < nn; i++)
			{
				int t = rand()%2;
				if (t == 0)
				{
					Monster* m = new Monster(levels[currentLevel],wxString("Zomby"),monsters,currentLevel);
					monsters.push_back(m);
				}
				else
				{
					Monster* m = new Monster(levels[currentLevel],wxString("Mummy"),monsters,currentLevel);
					monsters.push_back(m);
				}

		
			}
			MonsterTimer->Start(1000);
			PlayerTimer->Start(200);
			CreateImage();
			counter = 0;
			player->SetDirection(-1*player->GetDirection());
			
		}
		
	}
	
}
void Model::OnTimerPlayer(wxTimerEvent& event)
{
	if (player->GetDead() == true)
	{
		//MonsterTimer->Stop();
		PlayerTimer->Stop();

		wxMessageDialog* msg = new wxMessageDialog(game, "DEATH", "You are died!", wxYES_DEFAULT);
		int a = msg->ShowModal();
	}
	else
	{
		if (player->GetDirection() > 0)
		{
			int a = player->Move(player->GetDirection());
			if (a == 2)
			{//next level
					//if (currentLevel + 1 != 31)
					//{
						this->GoToLevel(currentLevel+1);
						return;
					//}
			}
			if (a == 3)//previous
					if (currentLevel - 1 != -1)
					{
						this->GoToLevel(currentLevel-1);
						return;
					}
			int startx = (int)((player->GetPosition().x - player->GetSpeed())/20);
			int starty = (int)((player->GetPosition().y - player->GetSpeed())/20);
			int endx = (int)((player->GetPosition().x + 40 + player->GetSpeed())/20);
			int endy = (int)((player->GetPosition().y + player->GetSpeed() + 60)/20);
			if (startx < 0)
				startx = 0;
			if (starty < 0)
				starty = 0;
			if (endx > levels[currentLevel]->GetW())
				endx = levels[currentLevel]->GetW();
			if (endy > levels[currentLevel]->GetH())
				endy = levels[currentLevel]->GetH();
			counter++;
	
			update(wxPoint(startx*20,starty*20),CreateSubImage(wxPoint(startx,starty),wxPoint(endx,endy)));
		}
	
		if (counter == 2)
		{
			counter = 0;
			player->SetDirection(-1*player->GetDirection());
		}

		if (player->GetFight() != 0)
		{
			player->Fight(player->GetFight(),&monsters);
			player->SetFight(player->GetFight()-1);

			int startx = (int)((player->GetPosition().x)/20-1);
			int starty = (int)((player->GetPosition().y)/20);
			int endx = (int)((player->GetPosition().x)/20 + 3);
			int endy = (int)((player->GetPosition().y + 30)/20);
			if (startx < 0)
				startx = 0;
			if (starty < 0)
				starty = 0;
			if (endx > levels[currentLevel]->GetH())
				endx = levels[currentLevel]->GetH();
			if (endy > levels[currentLevel]->GetW())
				endy = levels[currentLevel]->GetW();
			update(wxPoint(startx*20,starty*20),CreateSubImage(wxPoint(startx,starty),wxPoint(endx,endy)));
		}
	}
	
	
}
wxBitmap Model::GetImage() const
{
	wxPoint start = FindStartForImage();
	if (size.x > img->GetSize().x)
	{
		if (size.y > img->GetSize().y)
		{
			return img->GetSubBitmap(wxRect(start.x,start.y,img->GetSize().x,img->GetSize().y));
		}
		else
		{
			return img->GetSubBitmap(wxRect(start.x,start.y,img->GetSize().x,size.y));
		}
	}
	else
	{
		if (size.y > img->GetSize().y)
		{
			return img->GetSubBitmap(wxRect(start.x,start.y,size.x,img->GetSize().y));
		}
		else
		{
			return img->GetSubBitmap(wxRect(start.x,start.y,size.x,size.y));
		}
	}
}

wxPoint Model::FindStartForImage() const
{
	wxPoint point = player->GetPosition();
	wxPoint finish(levels[currentLevel]->GetW()*20,levels[currentLevel]->GetH()*20);

	wxRect ret(point.x - size.x / 2, point.y - size.y /2 ,size.x,size.y);//, point.x + size.x / 2, point.y + size.y /2);

	if (ret.x < 0)
		ret.x = 0;

	if (ret.y < 0)
		ret.y = 0;

	if (ret.width > finish.x)
		ret.x = 0;

	if (ret.height > finish.y)
		ret.y = 0;
	if (ret.x + ret.width > finish.x && ret.x != 0)
		ret.x = finish.x - ret.width;

	if (ret.y + ret.height > finish.y && ret.y != 0)
		ret.y = finish.y - ret.height;

	return wxPoint(ret.x,ret.y);
}

void Model::update(wxPoint point, wxBitmap set)
{
	wxMemoryDC mc(*img);
	mc.DrawBitmap(set,point);
	mc.DrawBitmap(player->GetCurrentImage(),player->GetPosition().x,player->GetPosition().y, true);
	for(int i = 0; i < monsters.size(); i++)
		mc.DrawBitmap(monsters[i]->GetCurrentImage(),monsters[i]->GetPosition().x,monsters[i]->GetPosition().y, true);
	//img->SaveFile("Image/Test.png", wxBITMAP_TYPE_PNG);
}

wxPoint Model::FindPositionForPlayer(bool direction)
{
	if (direction == 0)
	{
		for(int i = 0; i < levels[currentLevel]->GetW(); i++)
		{
			if (levels[currentLevel]->GetArr()[0][i] != 1)
				return wxPoint(i*20,10);
		}
	}
	else
	{
		for(int i = 0; i < levels[currentLevel]->GetW(); i++)
		{
			if (levels[currentLevel]->GetArr()[levels[currentLevel]->GetH()-1][i] != 1)
				return wxPoint(i*20,levels[currentLevel]->GetH()*20-10);
		}
	}
	
}

void Model::CreateImage(int a)
{
	wxMemoryDC mc(*img);
	mc.Clear();
	wxBitmap* texture = new wxBitmap("Image/Texture.png",wxBITMAP_TYPE_PNG);
	int** arr = levels[currentLevel]->GetArr();
	for (int i = 0; i < levels[currentLevel]->GetH(); i++)
	{
		for (int j = 0; j < levels[currentLevel]->GetW(); j++)
		{
			switch (arr[i][j])
			{
			case 0:
				mc.DrawBitmap(texture->GetSubBitmap(wxRect(20,0,20,20)),j*20,i*20,true);
				break;
			case 1:
				mc.DrawBitmap(texture->GetSubBitmap(wxRect(0,0,20,20)),j*20,i*20,true);
				break;
			case 2:
				mc.DrawBitmap(texture->GetSubBitmap(wxRect(20,0,20,20)),j*20,i*20,false);
				mc.DrawBitmap(texture->GetSubBitmap(wxRect(60,0,20,20)),j*20,i*20,true);
				break;
			case 3:
				mc.DrawBitmap(texture->GetSubBitmap(wxRect(20,0,20,20)),j*20,i*20,false);
				mc.DrawBitmap(texture->GetSubBitmap(wxRect(0,20,20,20)),j*20,i*20,true);
				break;
			case 4:
				mc.DrawBitmap(texture->GetSubBitmap(wxRect(20,0,20,20)),j*20,i*20,false);
				mc.DrawBitmap(texture->GetSubBitmap(wxRect(40,0,20,20)),j*20,i*20,true);
				break;
			case 5:
				mc.DrawBitmap(texture->GetSubBitmap(wxRect(20,0,20,20)),j*20,i*20,false);
				mc.DrawBitmap(texture->GetSubBitmap(wxRect(20,20,20,20)),j*20,i*20,true);
				break;
			case 6:
				mc.DrawBitmap(texture->GetSubBitmap(wxRect(20,0,20,20)),j*20,i*20,false);
				mc.DrawBitmap(texture->GetSubBitmap(wxRect(80,0,20,20)),j*20,i*20,true);
				break;
			default: 
				break;
			}
	}

	}
	img->SaveFile("Image/Map.png",wxBITMAP_TYPE_PNG);
	//draw player
	
	mc.DrawBitmap(player->GetCurrentImage(),player->GetPosition().x,player->GetPosition().y, true);
	if (a != 1)
		game->Information(1);
}

wxBitmap Model::CreateSubImage(wxPoint start, wxPoint end)
{
	int** arr = levels[currentLevel]->GetArr();
	wxBitmap bmp((end.x-start.x)*20,(end.y-start.y)*20);
	wxMemoryDC mc(bmp);
	wxBitmap texture;
	texture.LoadFile("Image/Texture.png",wxBITMAP_TYPE_PNG);
	int x = 0;
	int y = 0;
	
	for(int i = start.y; i < end.y; i++)
	{
		x = 0;
		for(int j = start.x; j < end.x; j++)
		{
			switch (arr[i][j])
			{
			case 0:
				mc.DrawBitmap(texture.GetSubBitmap(wxRect(20,0,20,20)),x*20,y*20,true);
				break;
			case 1:
				mc.DrawBitmap(texture.GetSubBitmap(wxRect(0,0,20,20)),x*20,y*20,true);
				break;
			case 2:
				mc.DrawBitmap(texture.GetSubBitmap(wxRect(20,0,20,20)),x*20,y*20,false);
				mc.DrawBitmap(texture.GetSubBitmap(wxRect(60,0,20,20)),x*20,y*20,true);
				break;
			case 3:
				mc.DrawBitmap(texture.GetSubBitmap(wxRect(20,0,20,20)),x*20,y*20,false);
				mc.DrawBitmap(texture.GetSubBitmap(wxRect(0,20,20,20)),x*20,y*20,true);
				break;
			case 4:
				mc.DrawBitmap(texture.GetSubBitmap(wxRect(20,0,20,20)),x*20,y*20,false);
				mc.DrawBitmap(texture.GetSubBitmap(wxRect(40,0,20,20)),x*20,y*20,true);
				break;
			case 5:
				mc.DrawBitmap(texture.GetSubBitmap(wxRect(20,0,20,20)),x*20,y*20,false);
				mc.DrawBitmap(texture.GetSubBitmap(wxRect(20,20,20,20)),x*20,y*20,true);
				break;
			case 6:
				mc.DrawBitmap(texture.GetSubBitmap(wxRect(20,0,20,20)),x*20,y*20,false);
				mc.DrawBitmap(texture.GetSubBitmap(wxRect(80,0,20,20)),x*20,y*20,true);
				break;	
			default: 
				break;
			}
			x++;
		}
		y++;
	}
	return bmp;
}

void Model::OnPressKeyboard(int key)
{
	int Startx = 0, Starty = 0, Endx = 0, Endy = 0;
	wxPoint P(0,0);
	switch(key-64)
	{
	case WXK_CONTROL_W:
		player->SetDirection(3);
		break;
	case WXK_CONTROL_A:
		player->SetDirection(2);
		break;
	case WXK_CONTROL_S:
		player->SetDirection(4);
		break;
	case WXK_CONTROL_D:
		player->SetDirection(1);
		break;
	case WXK_CONTROL_E:
		P = player->GetPosition();
		Startx = (int)(P.x / 20);
		Starty = (int)(P.y / 20)+1;

		if (levels[currentLevel]->GetArr()[Starty][Startx] == 3)
		{
			if (levels[currentLevel]->OpenChest(wxPoint(Starty,Startx)))
			{
				Endx = (int)((P.x + 20) / 20);
				Endy = (int)((P.y + 30) / 20);
				update(wxPoint(Startx*20, Starty*20),CreateSubImage(wxPoint(Startx,Starty),wxPoint(Endx, Endy)));
				game->OpenChest();
				break;
			}
		}
		if (levels[currentLevel]->GetArr()[Starty][Startx] == 6)
		{
			if (levels[currentLevel]->ActivatePortal(wxPoint(Starty,Startx)))
			{
				Endx = (int)((P.x + 20) / 20);
				Endy = (int)((P.y + 30) / 20);
				update(wxPoint(Startx*20, Starty*20),CreateSubImage(wxPoint(Startx,Starty),wxPoint(Endx, Endy)));
				game->PortalActivate(currentLevel);
				break;
			}
		}
		break;
	case WXK_CONTROL_Q:
		player->DestroyWall();
		break;
	case WXK_SPACE - 64:
		if (player->GetFight() == 0)
			player->SetFight(3);
		break;
		//game->Connect(wxEVT_KEY_DOWN, wxKeyEventHandler(Game::OnPressKeyboard));
		break;
	default:
		break;
	}
}

bool Model::GetStatusOfPlayer() const
{
	return player->GetDead();
}

Player* Model::GetPlayer() const
{
	return player;
}

void Model::Save(std::string str, std::string name)
{
	player->Save(str,name,currentLevel);
	for(int i = 0; i < levels.size(); i++)
	{
		levels[i]->Save(str+std::to_string(i)+".png");
	}
}
wxBEGIN_EVENT_TABLE(Model, wxEvtHandler)
    EVT_TIMER(1, Model::OnTimerMonster)
	EVT_TIMER(2, Model::OnTimerPlayer)
wxEND_EVENT_TABLE()