#include <iostream>
#include <Windows.h>
#include <string>
#include <conio.h>

using namespace std;

string passwd;
string passwdChecker;
string usrname;
string usrChecker;

char c;

int pin;
int pinChecker;
int choice;
int balance = 0;
int deposit;
int withdraw;

bool loginScreen;
bool bankMenu = true;
bool validator = true;

void usrVaildator();
void Password();
void Username();
void Pincode();
void BankMenu();

int main()
{
	cout << "Create a banking profile\n\n";
	cout << "Create a Username: ";
	Username();
	cout << "Create a Password: ";
	Password();
	system("cls");
	Pincode();
	system("cls");
	cout << "Thank you for chosing ____ Banking\n\n";
	system("pause");
	loginScreen = true;
	system("cls");
	while (loginScreen)
	{
		system("cls");
		cout << "Username: ";
		cin >> usrname;
		cout << "Password: ";
		c = ' ';
		passwd = "";
		while (c != 13) // Enter Key
		{
			c = _getch();
			if (c != 13)
			{
				passwd += c;
				cout << "";
			}
		}
		usrVaildator();
	}
	BankMenu();
}

void BankMenu()
{
	while (BankMenu)
	{
		system("cls");
		cout << "Welcome " << usrChecker << "\n";
		cout << "Balance: $" << balance << "\n\n";
		cout << "1. Deposit\n";
		cout << "2. Withdraw\n\n";
		cin >> choice;
		if (choice == 1)
		{
			system("cls");
			cout << "How much would you like to deposit\n\n";
			cout << "Amount: ";
			cin >> deposit;
			balance = deposit;
			Sleep(500);
			system("cls");
			cout << "Deposit was successful\n";
			system("pause");
		}
		if (choice == 2)
		{
			system("cls");
			cout << "How much money would you like to withdraw\n\n";
			cout << "Amount: ";
			cin >> withdraw;
			if (withdraw > balance)
			{
				cout << "Insuffcient funds\n\n";
				system("pause");
			}
			else
			{
				balance = balance - withdraw;
			}
		}
	}
}

void usrVaildator()
{
	if (usrname == usrChecker)
	{
		if (passwd == passwdChecker)
		{
			loginScreen = false;
		}
		else
		{
			cout << "\nUsername or password is incorrect";
			system("pause");
		}

	}
	else
	{
		cout << "\nUsername or password is incorrect";
		system("pause");
	}
}

void Username()
{
	cin >> usrname;
	usrChecker = usrname;
}

void Password()
{
	c = ' ';
	passwd = "";
	while (c != 13) // Enter Key
	{
		c = _getch();
		if (c != 13)
		{
			passwd += c;
			cout << "";
		}
	}
	passwdChecker = passwd;
}

void Pincode()
{
	bool pinNum = true;
	while (pinNum)
	{
		system("cls");
		cout << "Create a Pin for account: ";
		cin >> pin;

		if (pin < 1000 || pin > 9999) {
			pinNum = false;
			break;
		}
		else {
			break;
		}


	}
	if (!pinNum) {
		Pincode();
		return;
	}
}
