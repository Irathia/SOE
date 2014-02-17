#include "GameScene.h"
#include <wx/dcclient.h>
#include <wx/dcmemory.h>
#include <wx/thread.h>
#define TIMER_ID 1000

GameScene::GameScene(wxWindow* parent, Model* model):wxPanel(parent),timer(this, TIMER_ID)
{
	wxImage::AddHandler(new wxPNGHandler);
	wxImage::AddHandler(new wxGIFHandler);
	//step = 0;
	starti = 0;
	startj = 0;
	this->model  = model;
	image = model->GetImage();
	/*level = new Level(21,50,15, false);
	level->Save("Image/Level.png");
	image = new wxBitmap(level->GetH()*20,level->GetW()*20);
	CreateImage();
	wxPoint p = FindStartPositionForPlayer();
	player = new Player(p);*/
	this->Connect(wxEVT_PAINT, wxPaintEventHandler(GameScene::OnPaint));
	this->Connect(wxEVT_KEY_DOWN, wxKeyEventHandler(GameScene::OnPressKeyboard));
	timer.Start(100);
}



void GameScene::OnPaint(wxPaintEvent& event)
{
	wxPaintDC dc(this);
	int h = 0, w = 0;
	this->GetSize(&h,&w);
	image = model->GetImage();
		dc.Clear();
		/*int endi = level->GetW();
		int endj = level->GetH();
		if (starti+(w/20) > endi)
			starti = endi-(w/20);
		if (startj+(h/20) >endj)
			startj = endj-(h/20);
		if (starti < 0)
			starti = 0;
		if (startj < 0)
			startj = 0;*/
		//wxBitmap sub = image->GetSubBitmap(wxRect(0,0,w,h));
		wxMemoryDC mc(*image);
		dc.Blit(0,0,h,w,&mc,startj*20,starti*20);

		/*step = 2;
	}
	if (step == 2)
	{*/
		/*switch(player->GetTypeI())
		{
		case 1:
			if (player->GetP() == false)
				dc.DrawBitmap(player->GetImage()->GetSubImage(wxRect(0,0,20,30)),(player->GetPosition().y-startj)*20,(player->GetPosition().x-starti)*20-10,true);
			else
				dc.DrawBitmap(player->GetImage()->GetSubImage(wxRect(20,0,20,30)),(player->GetPosition().y-startj)*20,(player->GetPosition().x-starti)*20-10,true);
			break;
		case 2:
			if (player->GetP() == false)
				dc.DrawBitmap(player->GetImage()->GetSubImage(wxRect(120,0,20,30)),(player->GetPosition().y-startj)*20,(player->GetPosition().x-starti)*20-10,true);
			else
				dc.DrawBitmap(player->GetImage()->GetSubImage(wxRect(100,0,20,30)),(player->GetPosition().y-startj)*20,(player->GetPosition().x-starti)*20-10,true);
			break;
		case 3:
			if (player->GetP() == false)
				dc.DrawBitmap(player->GetImage()->GetSubImage(wxRect(80,0,20,30)),(player->GetPosition().y-startj)*20,(player->GetPosition().x-starti)*20-10,true);
			else
				dc.DrawBitmap(player->GetImage()->GetSubImage(wxRect(60,0,20,30)),(player->GetPosition().y-startj)*20,(player->GetPosition().x-starti)*20-10,true);
			break;
		case 4:
			if (player->GetP() == false)
				dc.DrawBitmap(player->GetImage()->GetSubImage(wxRect(80,0,20,30)),(player->GetPosition().y-startj)*20,(player->GetPosition().x-starti)*20-10,true);
			else
				dc.DrawBitmap(player->GetImage()->GetSubImage(wxRect(60,0,20,30)),(player->GetPosition().y-startj)*20,(player->GetPosition().x-starti)*20-10,true);
			break;
		default:
			break;
		}
	//}*/
	
/*
	wxBitmap b("Image/Player.png",wxBITMAP_TYPE_PNG);
	//bckimage = new wxBitmap();
	p1 = new wxStaticBitmap(this,wxID_ANY,b.GetSubBitmap(wxRect(0,0,20,30)),wxPoint(10,10));
	p1->SetBackgroundColour(wxTRANSPARENT);*/
}
	



void GameScene::OnPressKeyboard(wxKeyEvent& event)
{
	switch(event.GetKeyCode())
	{
	case WXK_LEFT:
		startj -= 1;
		this->Refresh();
		//step = 0;
		break;
	case WXK_RIGHT:
		startj += 1; 
		//step = 0;
		this->Refresh();
		
		break;
	case WXK_UP:
		starti -= 1; 
		//step = 0;
		this->Refresh();
		break;
	case WXK_DOWN:
		starti += 1;
		//step = 0;
		this->Refresh();
		break;
	default:
		break;

	}

	/*switch(event.GetKeyCode()-64)
	{
		case WXK_CONTROL_W:
		player->Move(3);
		if (!MovingPlayer())
			player->Move(4);
		break;
	case WXK_CONTROL_A:
		player->Move(2);
		if (!MovingPlayer())
			player->Move(1);
		break;
	case WXK_CONTROL_D:
		player->Move(1);
		if (!MovingPlayer())
			player->Move(2);
		break;
	case WXK_CONTROL_S:
		player->Move(4);
		if (!MovingPlayer())
			player->Move(3);
		break;
	default:
		break;
	}*/
	
	
	
	
}

/*bool GameScene::MovingPlayer()
{

	if (player->GetPosition().x < 0 || player->GetPosition().y < 0 || player->GetPosition().x >= level->GetW() || player->GetPosition().y >= level->GetH())
		return false;
	if (player->GetTypeI() == 3)
	{
		
		if (level->GetArr()[player->GetPosition().x+1][player->GetPosition().y] == 4 &&  level->GetArr()[player->GetPosition().x][player->GetPosition().y] == 0)
		{
			player->SetTypeI(1);
			this->Refresh();
			return true;
		}
		if (level->GetArr()[player->GetPosition().x][player->GetPosition().y] != 4)
		{
			return false;
		}
	}
	if (player->GetTypeI() == 1 || player->GetTypeI() == 2)
	{
		if (level->GetArr()[player->GetPosition().x][player->GetPosition().y] == 0 && level->GetArr()[player->GetPosition().x+1][player->GetPosition().y] == 0)
			return false;
	}
	if (level->GetArr()[player->GetPosition().x][player->GetPosition().y] != 1)
	{
		//step = 2;
		this->Refresh();
		return true;
	}
	return false;
}

wxPoint GameScene::FindStartPositionForPlayer()
{
	for(int i = 0; i < level->GetH(); i++)
	{
		if (level->GetArr()[0][i] != 1)
			return wxPoint(1,i);
	}
}

Player* GameScene::GetPlayer() const
{
	return player;
}

void GameScene::CreateImage()
{
	wxMemoryDC mc(*image);
	wxBitmap* texture = new wxBitmap("Image/Texture.png",wxBITMAP_TYPE_PNG);
	int** arr = level->GetArr();
	for (int i = 0; i < level->GetW(); i++)
	{
		for (int j = 0; j < level->GetH(); j++)
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
				
			default: 
				break;
			}
	}

	}
	image->SaveFile("Image/Map.png",wxBITMAP_TYPE_PNG);
}*/

void GameScene::OnTimer(wxTimerEvent& event)
{
	this->Refresh();
}
BEGIN_EVENT_TABLE(GameScene, wxPanel)
	EVT_TIMER(TIMER_ID, GameScene::OnTimer)
END_EVENT_TABLE()