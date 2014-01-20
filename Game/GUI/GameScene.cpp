#include "GameScene.h"
#include <wx/dcclient.h>

GameScene::GameScene(wxWindow* parent):wxPanel(parent)
{
	
	level = new Level(21,50,15, false);
	level->Save("Image/Level.png");
	this->Connect(wxEVT_PAINT, wxPaintEventHandler(GameScene::OnPaint));
	//DrawScene(0,0,21, 50);
}

void GameScene::OnPaint(wxPaintEvent& event)
{
	wxImage::AddHandler(new wxPNGHandler);
	wxPaintDC dc(this);
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

	for (int i = 0; i < endi; i++)
	{
		for (int j = 0; j < endj; j++)
		{
			switch (arr[i][j])
			{
			case 0:
				dc.DrawBitmap(*back,j*20,i*20,false);
				break;
			case 1:
				dc.DrawBitmap(*wall,j*20,i*20,false);
				break;
			case 2:
				dc.DrawBitmap(*back,j*20,i*20,false);
				dc.DrawBitmap(*teleport,j*20,i*20,true);
				break;
			case 3:
				dc.DrawBitmap(*back,j*20,i*20,false);
				dc.DrawBitmap(*closechest,j*20,i*20,true);
				break;
			case 4:
				dc.DrawBitmap(*back,j*20,i*20,false);
				dc.DrawBitmap(*ladder,j*20,i*20,true);
				break;
			case 5:
				dc.DrawBitmap(*back,j*20,i*20,false);
				dc.DrawBitmap(*openchest,j*20,i*20,true);
				break;
				
			default: 
				//dc.DrawBitmap(*back,j*20,i*20,false);
				//scene.GetSubImage(wxRect(i*20,j*20,20,20)).SetMaskColour(0,255,0);//LoadFile("C:/Users/Админ/Documents/Visual Studio 2010/Projects/testWidgets/testWidgets/Game/Core/SandBlockBehind.bmp",wxBITMAP_TYPE_BMP);
				break;
			}

			if (j*20 > h)
				break;
		}
		if (i*20 > w)
			break;
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