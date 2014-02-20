#include "Model.h"
#include <wx/dcmemory.h>
#include <wx/event.h>

Model::Model()
{
	wxImage::AddHandler(new wxPNGHandler);
	this->size = size;
	Level* zl = new Level(21,50,15, false);// zerro level h = 21*2-1 w = 50
	levels.push_back(zl);
	currentLevel = 0;
	wxPoint p = FindPositionForPlayer(0);
	player = new Player(p);
	img = new wxBitmap(levels[0]->GetW()*20, levels[0]->GetH()*20);
	CreateImage();
}

void Model::SetSize(wxSize size)
{
	this->size = size;
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
		Endx = (int)((P.x + 20)/ 20)+1;
		Endy = (int)((P.y  + 30)/ 20)+1;
		if(player->Move(3,levels[currentLevel]))
		{
			P = player->GetPosition();
			Startx = (int)(P.x / 20);
			Starty = (int)(P.y / 20);
			update(wxPoint(Startx*20, Starty*20),CreateSubImage(wxPoint(Startx,Starty),wxPoint(Endx, Endy)));
		}
		break;
	case WXK_CONTROL_A:
		P = player->GetPosition();
		Endx = (int)((P.x + 20)/ 20)+1;
		Endy = (int)((P.y  + 30)/ 20)+1;
		if(player->Move(2,levels[currentLevel]))
		{
			P = player->GetPosition();
			Starty = (int)(P.y / 20);
			Startx = (int)(P.x / 20);
			update(wxPoint(Startx*20, Starty*20),CreateSubImage(wxPoint(Startx,Starty),wxPoint(Endx, Endy)));
		}
		break;
	case WXK_CONTROL_S:
		P = player->GetPosition();
		Starty = (int)(P.y / 20);
		Startx = (int)(P.x / 20);
		if(player->Move(4,levels[currentLevel]))
		{
			P = player->GetPosition();
			Endx = (int)((P.x + 20) / 20)+1;
			Endy = (int)((P.y + 30) / 20)+1;
			update(wxPoint(Startx*20, Starty*20),CreateSubImage(wxPoint(Startx,Starty),wxPoint(Endx, Endy)));
		}
		break;
	case WXK_CONTROL_D:
		P = player->GetPosition();
		Starty = (int)(P.y / 20);
		Startx = (int)(P.x / 20);
		if(player->Move(1,levels[currentLevel]))
		{
			P = player->GetPosition();
			Endx = (int)((P.x + 20) / 20)+1;
			Endy = (int)((P.y + 30) / 20)+1;
			update(wxPoint(Startx*20, Starty*20),CreateSubImage(wxPoint(Startx,Starty),wxPoint(Endx, Endy)));
		}
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
	default:
		break;
	}
}

