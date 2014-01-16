#include "User.h"
#include <fstream>

bool LoadUsers(struct USERS* users)
{
	ifstream file("Text/Data.users");
	if (file.is_open()== false)
		return false;
	while (!file.eof())
	{
		string name;
		file >> name;
		users->name.push_back(name);
	}
	file.close();
	return true;
}

bool SaveUsers(struct USERS* users)
{
	ofstream file("Text/Data.users");
	if (file.is_open()== false)
		return false;
	int i  = 0;
	while (i != users->name.size())
	{
		if (users->name.at(i) != "@" && users->name.at(i) != "")
			file << users->name.at(i) << endl;
		i++;
	}
	file.close();
	return true;
}

bool FindUser(string name,struct USERS* users)
{
	int i = 0;
	while(i != users->name.size())
	{
		if (users->name.at(i) == name)
			return true;
		i++;
	}
	return false;
}
bool DeleteUser(string name,struct USERS* users)
{
	int i = 0;
	while(i != users->name.size())
	{
		if (users->name.at(i) == name)
		{
			users->name.at(i) = "@";
			return true;
		}
		i++;
	}
	return false;
}
bool AddUser(string name,struct USERS* users)
{
	users->name.push_back(name);
	return false;
}
