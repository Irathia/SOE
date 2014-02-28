#include "Model.h"
#include <wx/dcmemory.h>
#include <wx/event.h>

Model::Model():wxEvtHandler()
{
	wxImage::AddHandler(new wxPNGHandler);
	this->size = size;
	Level* zl = new Level(21,70,20, false);// zerro level h = 21*2-1 w = 50
	levels.push_back(zl);
	currentLevel = 0;
	wxPoint p = FindPositionForPlayer(0);
	player = new Player(p,levels[currentLevel]);
	img = new wxBitmap(levels[0]->GetW()*20, levels[0]->GetH()*20);
	CreateImage();
	int numer = 30;
	for(int i = 0; i < numer; i++)
	{
		int t = rand()%2;
		if (t == 0)
		{
			Monster* m = new Monster(levels[currentLevel],wxString("Zomby"),monsters);
			monsters.push_back(m);
		}
		else
		{
			Monster* m = new Monster(levels[currentLevel],wxString("Mummy"),monsters);
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

void Model::OnTimerPlayer(wxTimerEvent& event)
{
	if (player->GetDead() == true)
	{
		//MonsterTimer->Stop();
		PlayerTimer->Stop();
	}
	else
	{
		if (player->GetDirection() > 0)
		{
			player->Move(player->GetDirection());
			int startx = (int)((player->GetPosition().x - player->GetSpeed())/20);
			int starty = (int)((player->GetPosition().y - player->GetSpeed())/20);
			int endx = (int)((player->GetPosition().x + 40 + player->GetSpeed())/20);
			int endy = (int)((player->GetPosition().y + player->GetSpeed() + 60)/20);
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
			update(wxPoint(startx*20,starty*20),CreateSubImage(wxPoint(startx,starty),wxPoint(endx,endy)));
		}
	}
	
	
}
wxBitmap Model::GetImage() const
{
	wxPoint start = FindStartForImage();

	return img->GetSubBitmap(wxRect(start.x,start.y,size.x,size.y));
}

wxPoint Model::FindStartForImage() const
{
	wxPoint point = player->GetPosition();
	wxPoint finish(levels[currentLevel]->GetW()*20,levels[currentLevel]->GetH()*20);

	wxRect ret(point.x - size.x / 2, point.y - size.y /2 , point.x + size.x / 2, point.y + size.y /2);

	if (ret.x < 0)
		ret.x = 0;

	if (ret.y < 0)
		ret.y = 0;

	if (ret.x + ret.width > finish.x)
		ret.x = finish.x - size.x;

	if (ret.y + ret.height > finish.y)
		ret.y = finish.y - size.y;

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

void Model::CreateImage()
{
	wxMemoryDC mc(*img);
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
				break;
			}
		}
		break;
	case WXK_SPACE - 64:
		if (player->GetFight() == 0)
			player->SetFight(3);
		break;
	default:
		break;
	}
}

bool Model::GetStatusOfPlayer() const
{
	return player->GetDead();
}

wxBEGIN_EVENT_TABLE(Model, wxEvtHandler)
    EVT_TIMER(1, Model::OnTimerMonster)
	EVT_TIMER(2, Model::OnTimerPlayer)
wxEND_EVENT_TABLE()