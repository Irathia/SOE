#pragma once

#include <wx/panel.h>
#include <wx/button.h>

class Rooms: public wxPanel
{
public:
	Rooms(wxWindow* parent, int n);
	Rooms(wxWindow* parent, int n, std::string name);
	void OnPaint(wxPaintEvent& event);
	void Activate(int a);

	void OnButton0(wxCommandEvent& event);
	void OnButton1(wxCommandEvent& event);
	void OnButton2(wxCommandEvent& event);
	void OnButton3(wxCommandEvent& event);
	void OnButton4(wxCommandEvent& event);
	void OnButton5(wxCommandEvent& event);
	void OnButton6(wxCommandEvent& event);
	void OnButton7(wxCommandEvent& event);
	void OnButton8(wxCommandEvent& event);
	void OnButton9(wxCommandEvent& event);

	void Save(std::string str);
private:
	wxButton* l0;
	wxButton* l1;
	wxButton* l2;
	wxButton* l3;
	wxButton* l4;
	wxButton* l5;
	wxButton* l6;
	wxButton* l7;
	wxButton* l8;
	wxButton* l9;

	int n;

	DECLARE_EVENT_TABLE()
};