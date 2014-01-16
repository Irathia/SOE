#include "Language.h"
#include <fstream>

Language::Language(string name)
{
	ifstream file(name.c_str());
	if (file.is_open())
	{
		while(!file.eof())
		{
			string nameOfValue;
			string valueOfValue;
			file >> nameOfValue >> valueOfValue;

			while (1)
			{
				size_t found = valueOfValue.find("@");
				size_t end = valueOfValue.size();
				if (found == end-1)
				{
					valueOfValue.replace(found,1,"");
					break;
				}
				valueOfValue.replace(found,1," ");
			}

			variables[nameOfValue] = valueOfValue;
/*
			if (nameOfValue == "newGameButton")
				newGameButton = valueOfValue;

			if (nameOfValue == "loadGameButton")
				loadGameButton = valueOfValue;

			if (nameOfValue == "settingsButton")
				settingsButton = valueOfValue;

			if (nameOfValue == "exitButton")
				exitButton = valueOfValue;

			if (nameOfValue == "exitMessageDialogMessage")
				exitMessageDialogMessage = valueOfValue;

			if (nameOfValue == "exitMessageDialogTitle")
				exitMessageDialogTitle = valueOfValue;

			if (nameOfValue == "exitMessageDialogYes")
				exitMessageDialogYes = valueOfValue;

			if (nameOfValue == "exitMessageDialogNo")
				exitMessageDialogNo = valueOfValue;

			if (nameOfValue == "dialogForInputNewNameTitle")
				dialogForInputNewNameTitle = valueOfValue;

			if (nameOfValue == "dialogForInputNewNameText")
				dialogForInputNewNameText = valueOfValue;

			if (nameOfValue == "dialogForInputNewNameOkButton")
				dialogForInputNewNameOkButton = valueOfValue;

			if (nameOfValue == "dialogForInputNewNameCancelButton")
				dialogForInputNewNameCancelButton = valueOfValue;

			if (nameOfValue == "dialogForInputNewNameErrorName")
				dialogForInputNewNameErrorName = valueOfValue;
		}*/
		}
	}
	file.close();
}

string Language::getValue(string name) const
{
	return variables.at(name);
}


void Language::changeLanguage(string name)
{
	ifstream file(name.c_str());
	if (file.is_open())
	{
		while(!file.eof())
		{
			string nameOfValue;
			string valueOfValue;
			file >> nameOfValue >> valueOfValue;

			while (1)
			{
				size_t found = valueOfValue.find("@");
				size_t end = valueOfValue.size();
				if (found == end-1)
				{
					valueOfValue.replace(found,1,"");
					break;
				}
				valueOfValue.replace(found,1," ");
			}

			variables[nameOfValue] = valueOfValue;

		}
	}
	file.close();
}