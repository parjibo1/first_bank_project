#pragma once
#include<string>
using namespace std;
class account
{
public:
	string user_name;
	int pasword;
	int deposit;
	void menu();
	void exist();
	void create_account();
	void longin();
	void forgot_account_number();
};

