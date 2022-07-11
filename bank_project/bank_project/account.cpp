#include "account.h"
#include<string>
#include<iostream>
#include<fstream>
#include<stdio.h>
using namespace std;

//developer samuel Quenwon
void account::menu()
{
	system("cls");
	system("color 00");
	cout << "\n\t\tWELCOME TO INDIA BANK SYSTEM";
	cout << "\n\t__________________________________________";
	cout << "\n\n\t\t\tMENU";
	cout << "\n\n\tPRESS 1: TO CREATE YOUR ACCOUNT";
	cout << "\n\n\tPRESS 2: TO LONGIN YOUR ACCOUNT";
	cout << "\n\n\tPRESS 3: IF YOU FORGOT YOUR ACCOUNT NUMBER";
	cout << "\n\n\tPRESS 4: FOR EXIST";
	cout << "\n\n\tENTER...";
	int enter;
	cin >> enter;
	//these are the switch stement
	switch (enter)
	{
	case 1:
		account::create_account();
		break;
	case 2:
		account::longin();
		break;
	case 3:
		account::forgot_account_number();
		break;
	case 4:
		account::exist();
		break;
	default:
		system("cls");
		cout << "you enter wrong option";
	}

}

void account::exist()
{
	system("cls");
	//system("color A0");
	int one;
	cout << "\n\tTHANK YOU FOR YOUR VISIT!!";
	cout << "\n\n\tPRESS 1: FOR MENU";
	cout << "\n\n\tPRESS 2: TO EXIST";
	cout << "\n\n\tENTER...";
	cin >> one;
	if (one == 1)
	{
		account::menu();
	}
	else if (one == 2)
	{

	}
	else 
	{

	}
}

void account::create_account()
{
	account data;
	system("cls");
	char yes;
	cout << "\n\t\t______create your account______";
	cout << "\n\n\tdo you want to create account with us?__y/n...";
	cin >> yes;
	if (yes == 'y')
	{
		int found = 0;
		fstream file;    
		file.open("password_data.txt", ios::app);
		cout << "\n\n\tCRATE YOUR OWN USER NAME...";
		cin >> data.user_name;
		file << data.user_name << endl;
		cout << "\n\n\tCREATE YOUR OWN ACCOUNT NUMBER...";
		cin >> data.pasword;
		file << data.pasword << endl;
		cout << "\n\n\tENTER DEPOSIT AMOUNT ...$";
		cin >> data.deposit;
		file << data.deposit << endl;
		if (!file)
		{
			cout << "\n\tfile does not esist";
		}
		else
		{
			system("cls");
			found = 1;
			int one;
			cout << "\n\tyour account is created successfully!!";
			cout << "\n\n\tPRESS 1: FOR MENU";
			cout << "\n\n\tPRESS 2: FOR EXIST";
			cout << "\n\n\tENTER...";
			cin >> one;
			if (one == 1)
			{
			  account::menu();
			}
			else if (one == 2)
			{
				account::exist();
			}
			else
			{

			}
			file.close();
			
		}
	}
	else
	{
		account::exist();
	}
	
}

void account::longin()
{
	system("cls");
	char yes;
	cout << "\n\n\tdo you have account with us?__y/n...";
	cin >> yes;
	if (yes == 'y')
	{
		string name;
		ifstream file;
		string c;
		int found = 0;
		int p, a;
		file.open("password_data.txt");
		int account_number;
		cout << "\n\n\tENTER YOUR USER NAME...";
		cin >> name;
		cout << "\n\n\tENTER YOUR ACCOUNT NUMBER...";
		cin >> account_number;
		while (file >> c >> p >> a)
		{
			if (c == name && p == account_number)
			{
				system("cls");
				found = 1;
				int enter;
		cout << "\n\t_________longin successfully___________";
				cout << "\n\n\t\tHOW MAY WE HELP YOU?";
				cout << "\n\n\tpress 1: to deposit";
				cout << "\n\n\tpress 2: to withedeaw";
				cout << "\n\n\tpress 3: to check your balance";
				cout << "\n\n\tpress 4: for MENU";
				cout << "\n\n\tENTER...";
				cin >> enter;
				switch (enter)
				{
				case 1:
					break;
				case 2:
					break;
				case 3:
					break;
				case 4:
					break;

				}
			}
			if(!found)
			{
			system("cls");
				int one;
				cout << "\n\taccout not found";
				cout << "\n\n\tpress 1: to try again";
				cout << "\n\n\tpress 2: to MENU";
				cout << "\n\n\tENTER...";
				cin >> one;
				if (one == 1)
				{
					account::longin();
				}
				else if (one == 2)
				{
					account::menu();
				}
				else
				{

				}

			}
		}
		file.close();
	}
	else
	{
		int one;
		cout << "\n\tpress 1: to create account with us";
		cout << "\n\n\tprsee 2: for MENU";
		cout << "\n\n\tpress 3: for exist";
		cout << "\n\n\tENTER...";
		cin >> one;
		if (one == 1)
		{
			account::create_account();
		}
		else if (one == 2)
		{
			account::menu();
		}
		else if (one == 3)
		{
			account::exist();
		}
		else
		{

		}
	}





}

void account::forgot_account_number()
{
	system("cls");
	char yes;
	cout << "\n\tdid you forget your password?__y/n...";
	cin >> yes;
	if (yes == 'y')
	{
		//ifstream file;
		string usre_name;
		string name;
		int account_number, deposit;
		int found = 0;
		cout << "\n\tDO NOT WORRY  WE  GOT YOU";
		cout << "\n\n\tenter your user name...";
		cin >> usre_name;
		ifstream fp("password_data.txt");
		while (fp>> name >> account_number >> deposit)  
		{
			if ( usre_name == name )
			{
				found = 1;
				system("cls");
				int one;
				cout << "\n\tyour account number is :" << account_number;
				cout << "\n\n\tthank you mr./madan   :" << name;
				cout << "\n\n\tpress 1: for MENU";
				cout << "\n\n\tpress 2: to longin your account";
				cout << "\n\n\tENTER...";
				cin >> one;
				if (one == 1)
				{
					account::menu();
				}
				else if (one == 2)
				{
					account::longin();
				}
				else
				{

				}
			}
			if(!found)
			{
				system("cls");
				char yes;
				cout << "\n\tusre name is not found!!";
		cout << "\n\n\tdid you forget your user_name?__y/n...";
		cin >> yes;
		if (yes == 'y')
		{
			int one;
			cout << "\n\tkindly visit anly nearby india bank";
			cout << "\n\n\tpress 1: for MENU";
			cout << "\n\n\tpress 2: for exist";
			cin >> one;
			if (one == 1)
			{
				account::menu();
			}
			else if (one == 2)
			{
				account::exist();
			}
			else
			{

			}
		}
		else
		{
			int one;
			cout << "\n\tpress 1: to try again";
			cout << "\n\n\tpress 2: for MENU";
			cin >> one;
			if (one == 1)
			{
				account::forgot_account_number();
			}
			else if (one == 2)
			{
				account::menu();
			}
			else
			{

			}
		}
			}
		}
		fp.close();

	}
	else
	{
		int one;
		cout << "\n\t press 1: for MENU";
		cout << "\n\n\t press 2: to longin your account";
		cout << "\n\n\tENTER...";
		cin >> one;
		if (one == 1)
		{
			account::menu();
		}
		else if(one == 2)
		{
			account::longin();
		}



	}














}
