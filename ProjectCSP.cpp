#include <iostream>
#include <Windows.h>
#include <string>
#include <conio.h>

using namespace std;

std::string passwd;
string passwdChecker;
std::string usrname;
string usrChecker;

char c;

int pin;
int pinChecker;

bool loginScreen;

void usrVaildator();
void Password();
void Username();
void Pincode();

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
		if (pin >= 10000)
		{
			cout << "Not a valid length\n";
			system("pause");
		}
		if (pin <= 999)
		{
			cout << "Not a valid length\n";
			system("pause");
		}
	}
}
