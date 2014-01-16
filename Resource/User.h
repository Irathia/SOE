#pragma once
#include <string>
#include <vector>

using namespace std;

struct USERS
{
	vector <string> name;
};

bool LoadUsers(struct USERS* users);
bool SaveUsers(struct USERS* users);

bool FindUser(string name,struct USERS* users);
bool DeleteUser(string name,struct USERS* users);
bool AddUser(string name,struct USERS* users);