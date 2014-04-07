#pragma once

#include <wx/panel.h>
#include <wx/statbmp.h>
#include <wx/stattext.h>

class FastItems: public wxPanel
{
public:
	FastItems(wxWindow* parent);
	void OnPaint(wxPaintEvent& event);
private:
	wxStaticText* Text1;
	wxStaticText* Text2;
	wxStaticText* Text3;
	wxStaticText* Text4;
	wxStaticText* Text5;
	wxStaticText* Text6;
	wxStaticText* Text7;
	wxStaticText* Text8;
	wxStaticText* Text9;
	wxStaticText* Text0;

	wxStaticBitmap* Bitmap1;
	wxStaticBitmap* Bitmap2;
	wxStaticBitmap* Bitmap3;
	wxStaticBitmap* Bitmap4;
	wxStaticBitmap* Bitmap5;
	wxStaticBitmap* Bitmap6;
	wxStaticBitmap* Bitmap7;
	wxStaticBitmap* Bitmap8;
	wxStaticBitmap* Bitmap9;
	wxStaticBitmap* Bitmap0;

};