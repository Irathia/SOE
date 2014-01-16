#pragma once

#include <string>
#include <map>

using namespace std;

class Language
{
public:
	Language(string name);
	void changeLanguage(string name);
	string getValue(string name) const;
private:
	map <string, string> variables;
	//string newGameButton;
	//string loadGameButton;
	//string settingsButton;
	//string exitButton;
	//string exitMessageDialogMessage;
	//string exitMessageDialogTitle;
	//string exitMessageDialogYes;
	//string exitMessageDialogNo;
	//string dialogForInputNewNameTitle;
	//string dialogForInputNewNameText;
	//string dialogForInputNewNameOkButton;
	//string dialogForInputNewNameCancelButton;
	//string dialogForInputNewNameErrorName;
	//string dialogForNewGameTitle;
	

};