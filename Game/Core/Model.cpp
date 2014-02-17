#include "Model.h"
#include <wx/dcmemory.h>
#include <wx/event.h>

Model::Model()
{
	wxImage::AddHandler(new wxPNGHandler);
	Level* zl = new Level(21,50,15, false);// zerro level
	levels.push_back(zl);
	currentLevel = 0;
	wxPoint p = FindPositionForPlayer(0);
	player = new Player(p);
	img = new wxBitmap(levels[0]->GetH()*20,levels[0]->GetW()*20);
	CreateImage();
}

wxBitmap* Model::GetImage() const
{
	return img;
}
void Model::update(wxPoint point, wxBitmap set)
{
	wxMemoryDC mc(*img);
	mc.DrawBitmap(set,point);
	mc.DrawBitmap(player->GetCurrentImage(),player->GetPosition().y,player->GetPosition().x, true);
	//img->SaveFile("Image/Test.png", wxBITMAP_TYPE_PNG);
}

wxPoint Model::FindPositionForPlayer(bool direction)
{
	if (direction == 0)
	{
		for(int i = 0; i < levels[currentLevel]->GetH(); i++)
		{
			if (levels[currentLevel]->GetArr()[0][i] != 1)
				return wxPoint(10,i*20);
		}
	}
	else
	{
		for(int i = 0; i < levels[currentLevel]->GetH(); i++)
		{
			if (levels[currentLevel]->GetArr()[levels[currentLevel]->GetW()-1][i] != 1)
				return wxPoint(levels[currentLevel]->GetW()*20-10,i*20);
		}
	}
	
}

void Model::CreateImage()
{
	wxMemoryDC mc(*img);
	wxBitmap* texture = new wxBitmap("Image/Texture.png",wxBITMAP_TYPE_PNG);
	int** arr = levels[currentLevel]->GetArr();
	for (int i = 0; i < levels[currentLevel]->GetW(); i++)
	{
		for (int j = 0; j < levels[currentLevel]->GetH(); j++)
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
	mc.DrawBitmap(player->GetCurrentImage(),player->GetPosition().y,player->GetPosition().x, true);
}

wxBitmap Model::CreateSubImage(wxPoint start, wxPoint end)
{
	int** arr = levels[currentLevel]->GetArr();

	wxBitmap bmp((end.y-start.y)*20,(end.x-start.x)*20);
	wxMemoryDC mc(bmp);
	wxBitmap texture;
	texture.LoadFile("Image/Texture.png",wxBITMAP_TYPE_PNG);
	int x = 0;
	int y = 0;
	for(int i = start.x; i < end.x; i++)
	{
		x = 0;
		for(int j = start.y; j < end.y; j++)
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

	
	bmp.SaveFile("Image/bmp.png",wxBITMAP_TYPE_PNG);
	return bmp;
}

void Model::OnPressKeyboard(int key)
{
	int Startx = 0, Starty = 0, Endx = 0, Endy = 0;
	wxPoint P(0,0);
	switch(key-64)
	{
	case WXK_CONTROL_W:
		P = player->GetPosition();
		Endy = (int)((P.y + 20)/ 20)+1;
		Endx = (int)((P.x  + 30)/ 20)+1;
		if(player->Move(3,levels[currentLevel]))
		{
			P = player->GetPosition();
			Starty = (int)(P.y / 20);
			Startx = (int)(P.x / 20);
			update(wxPoint(Starty*20, Startx*20),CreateSubImage(wxPoint(Startx,Starty),wxPoint(Endx, Endy)));
		}
		break;
	case WXK_CONTROL_A:
		P = player->GetPosition();
		Endy = (int)((P.y + 20)/ 20)+1;
		Endx = (int)((P.x  + 30)/ 20)+1;
		if(player->Move(2,levels[currentLevel]))
		{
			P = player->GetPosition();
			Starty = (int)(P.y / 20);
			Startx = (int)(P.x / 20);
			update(wxPoint(Starty*20, Startx*20),CreateSubImage(wxPoint(Startx,Starty),wxPoint(Endx, Endy)));
		}
		break;
	case WXK_CONTROL_S:
		P = player->GetPosition();
		Starty = (int)(P.y / 20);
		Startx = (int)(P.x / 20);
		if(player->Move(4,levels[currentLevel]))
		{
			P = player->GetPosition();
			Endy = (int)((P.y + 20) / 20)+1;
			Endx = (int)((P.x + 30) / 20)+1;
			update(wxPoint(Starty*20, Startx*20),CreateSubImage(wxPoint(Startx,Starty),wxPoint(Endx, Endy)));
		}
		break;
	case WXK_CONTROL_D:
		P = player->GetPosition();
		Starty = (int)(P.y / 20);
		Startx = (int)(P.x / 20);
		if(player->Move(1,levels[currentLevel]))
		{
			P = player->GetPosition();
			Endy = (int)((P.y + 20) / 20)+1;
			Endx = (int)((P.x + 30) / 20)+1;
			update(wxPoint(Starty*20, Startx*20),CreateSubImage(wxPoint(Startx,Starty),wxPoint(Endx, Endy)));
		}
		break;
	case WXK_CONTROL_E:
		P = player->GetPosition();
		Starty = (int)(P.y / 20);
		Startx = (int)(P.x / 20)+1;

		if (levels[currentLevel]->GetArr()[Startx][Starty] == 3)
		{
			if (levels[currentLevel]->OpenChest(wxPoint(Startx,Starty)))
			{
				Endy = (int)((P.y + 20) / 20);
				Endx = (int)((P.x + 30) / 20);
				update(wxPoint(Starty*20, Startx*20),CreateSubImage(wxPoint(Startx,Starty),wxPoint(Endx, Endy)));
				break;
			}
		}
		if (levels[currentLevel]->GetArr()[Startx][Starty] == 6)
		{
			if (levels[currentLevel]->ActivatePortal(wxPoint(Startx,Starty)))
			{
				Endy = (int)((P.y + 20) / 20);
				Endx = (int)((P.x + 30) / 20);
				update(wxPoint(Starty*20, Startx*20),CreateSubImage(wxPoint(Startx,Starty),wxPoint(Endx, Endy)));
				break;
			}
		}
		break;
	default:
		break;
	}
}

