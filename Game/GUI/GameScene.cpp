#include "GameScene.h"
#include <wx/dcbuffer.h>
#include <wx/dcclient.h>
#include <wx/dcmemory.h>
#include <wx/thread.h>
#define TIMER_ID 1000

GameScene::GameScene(wxWindow* parent, Model* model):wxPanel(parent),timer(this, TIMER_ID)
{
	wxImage::AddHandler(new wxPNGHandler);
	this->model  = model;
	image = model->GetImage();
	this->Connect(wxEVT_PAINT, wxPaintEventHandler(GameScene::OnPaint));
	this->Connect(wxEVT_KEY_DOWN, wxKeyEventHandler(GameScene::OnPressKeyboard));
	timer.Start(100);
}




void GameScene::OnPaint(wxPaintEvent& event)
{
	wxBufferedPaintDC dc(this);
	int h = 0, w = 0;
	this->GetSize(&h,&w);
	image = model->GetImage();
	dc.Clear();
	wxMemoryDC mc(*image);
	dc.Blit(0,0,h,w,&mc,0,0);
}
	



void GameScene::OnPressKeyboard(wxKeyEvent& event)
{
	switch(event.GetKeyCode())
	{
	case WXK_LEFT:
		this->Refresh();
		break;
	case WXK_RIGHT:
		this->Refresh();
		
		break;
	case WXK_UP:
		this->Refresh();
		break;
	case WXK_DOWN:
		this->Refresh();
		break;
	default:
		break;

	}
}

void GameScene::OnTimer(wxTimerEvent& event)
{
	this->Refresh();
}

void GameScene::OnEraseBackground(wxEraseEvent & event)
{
}
BEGIN_EVENT_TABLE(GameScene, wxPanel)
	EVT_TIMER(TIMER_ID, GameScene::OnTimer)
	EVT_ERASE_BACKGROUND(GameScene::OnEraseBackground)
END_EVENT_TABLE()