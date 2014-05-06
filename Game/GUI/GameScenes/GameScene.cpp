#include "GameScene.h"
#include <wx/dcbuffer.h>
#include <wx/dcclient.h>
#include <wx/dcmemory.h>
#include <wx/thread.h>
#include <wx/wx.h>
#define TIMER_ID 1000

GameScene::GameScene(wxWindow* parent, Model* model, Game* game):wxPanel(parent),timer(this, TIMER_ID)
{
	this->parent = game;
	wxImage::AddHandler(new wxPNGHandler);
	this->model  = model;
	//image = model->GetImage());
	this->Connect(wxEVT_PAINT, wxPaintEventHandler(GameScene::OnPaint));
	this->Connect(wxEVT_KEY_DOWN, wxKeyEventHandler(GameScene::OnPressKeyboard));
	
}




void GameScene::OnPaint(wxPaintEvent& event)
{
	if (parent->Information() == true)
	{
		parent->Refresh();
	}
	//this->ClearBackground();
	if (timer.IsRunning() == false)
		timer.Start(100);
	int h = 0, w = 0;
	this->GetSize(&w,&h);
	if (w == 0 || h == 0)
		return;
	this->model->SetSize(wxSize(w,h));
	wxBufferedPaintDC dc(this);
	wxBitmap image = model->GetImage();
	dc.Clear();
	dc.DrawBitmap(image,0,0);
}
	



void GameScene::OnPressKeyboard(wxKeyEvent& event)
{
}

void GameScene::OnTimer(wxTimerEvent& event)
{
	if (model->GetStatusOfPlayer() == true)
	{
		timer.Stop();
		//parent->WeAreDead();
		
	//msg->SetYesNoLabels((language->getValue("exitMessageDialogYes")).c_str(), (language->getValue("exitMessageDialogNo")).c_str());
	}
	else
		this->Refresh();
}

void GameScene::OnEraseBackground(wxEraseEvent & event)
{
}
BEGIN_EVENT_TABLE(GameScene, wxPanel)
	EVT_TIMER(TIMER_ID, GameScene::OnTimer)
	EVT_ERASE_BACKGROUND(GameScene::OnEraseBackground)
END_EVENT_TABLE()