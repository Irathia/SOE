#include "GameScene.h"
#include <wx/dcclient.h>

GameScene::GameScene(wxWindow* parent):wxPanel(parent)
{
	step = 0;
	starti = 0;
	startj = 0;
	level = new Level(21,50,15, false);
	level->Save("Image/Level.png");
	this->Connect(wxEVT_PAINT, wxPaintEventHandler(GameScene::OnPaint));
	pointPX = 0;
	pointPY = 0;
	//DrawScene(0,0,21, 50);
}

void GameScene::OnPaint(wxPaintEvent& event)
{
	this->Connect(wxEVT_KEY_DOWN, wxKeyEventHandler(GameScene::OnPressKeyboard));
	wxImage::AddHandler(new wxPNGHandler);
	wxPaintDC dc(this);
	dc.Clear();
	int h = 0, w = 0;
	this->GetSize(&h,&w);

	/*int wall = 1;
	int back = 0;
	int teleport = 2;
	int chestclose = 3;
	int chestopen = 5;
	int ladder = 4;*/
	wxBitmap *wall = new wxBitmap("Image/SandBlock.png",wxBITMAP_TYPE_PNG);
	wxBitmap *back = new wxBitmap("Image/SandBlockBehind.png",wxBITMAP_TYPE_PNG);
	wxBitmap *ladder = new wxBitmap("Image/Ladder.png",wxBITMAP_TYPE_PNG);
	wxBitmap *closechest = new wxBitmap("Image/CloseChest.png",wxBITMAP_TYPE_PNG);
	wxBitmap *openchest = new wxBitmap("Image/OpenChest.png",wxBITMAP_TYPE_PNG);
	wxBitmap *teleport = new wxBitmap("Image/Teleport.png",wxBITMAP_TYPE_PNG);
	
	int** arr = level->GetArr();
	int endi = level->GetN();
	int endj = level->GetM();
	int count = 0;
	int x = 0, y = 0;
	if (starti > endi)
		starti = endi;
	if (startj >endj)
		startj = endj;
	if (starti < 0)
		starti = 0;
	if (startj < 0)
		startj = 0;
	for (int i = starti; i < endi; i++)
	{
		x = 0;
		for (int j = startj; j < endj; j++)
		{
			switch (arr[i][j])
			{
			case 0:
				dc.DrawBitmap(*back,x,y,false);
				break;
			case 1:
				dc.DrawBitmap(*wall,x,y,false);
				break;
			case 2:
				dc.DrawBitmap(*back,x,y,false);
				dc.DrawBitmap(*teleport,x,y,true);
				break;
			case 3:
				dc.DrawBitmap(*back,x,y,false);
				dc.DrawBitmap(*closechest,x,y,true);
				break;
			case 4:
				dc.DrawBitmap(*back,x,y,false);
				dc.DrawBitmap(*ladder,x,y,true);
				break;
			case 5:
				dc.DrawBitmap(*back,x,y,false);
				dc.DrawBitmap(*openchest,x,y,true);
				break;
				
			default: 
				//dc.DrawBitmap(*back,j*20,i*20,false);
				//scene.GetSubImage(wxRect(i*20,j*20,20,20)).SetMaskColour(0,255,0);//LoadFile("C:/Users/Админ/Documents/Visual Studio 2010/Projects/testWidgets/testWidgets/Game/Core/SandBlockBehind.bmp",wxBITMAP_TYPE_BMP);
				break;
			}

			if (x > h)
				break;
			x+=20;
		}
		if (y > w)
			break;
		y+=20;
	}
	wxBitmap *people = new wxBitmap();
	if (step%2 == 0)
	{
		people->LoadFile("Image/One.png",wxBITMAP_TYPE_PNG);
		dc.DrawBitmap(*people,pointPX,pointPY,true);
		step++;
	}
	else
	{
		people->LoadFile("Image/Two.png",wxBITMAP_TYPE_PNG);
		dc.DrawBitmap(*people,pointPX,pointPY,true);
		step++;
	}
}


void GameScene::OnPressKeyboard(wxKeyEvent& event)
{
	if (event.GetKeyCode() == WXK_LEFT)
	{
		startj -= 1;//pointPX += 1;
		this->Refresh();
		//OnPaint(wxPaintEvent());
	}
	if (event.GetKeyCode() == WXK_RIGHT)
	{
		startj += 1; //pointPX -=1;
		this->Refresh();
	}
	if (event.GetKeyCode() == WXK_UP)
	{
		starti -= 1; //pointPY += 1;
		this->Refresh();
	}
	if (event.GetKeyCode() == WXK_DOWN)
	{
		starti += 1; //pointPY -= 1;
		this->Refresh();
	}

	
}
void GameScene::DrawScene(int x, int y, int m, int n)
{
	int wall = 1;
	int back = 0;
	int teleport = 2;
	int chest = 3;
	int ladder = 4;
	int** arr = level->GetArr();
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			switch (arr[i][j])
			{
			case 1:
				break;
			default: 
				//scene.GetSubImage(wxRect(i*20,j*20,20,20)).SetMaskColour(0,255,0);//LoadFile("C:/Users/Админ/Documents/Visual Studio 2010/Projects/testWidgets/testWidgets/Game/Core/SandBlockBehind.bmp",wxBITMAP_TYPE_BMP);
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
}