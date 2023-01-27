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
int i = 0;
int m = 0;
int counter = 0;
int transactionsRecorded = 0;

int pin;
int pinChecker;
int choice;
int lastTrans;
int test = 1;
int test2 = 1;
float balance = 100;
float deposit;
float withdraw;
float lastAction;
string moneyMovement;

struct Transaction {
	string moneyMovement;
	float amount;
	bool updated = false;
};

Transaction transactions[6];

string MM[6];
float transaction[6];

bool loginScreen;
bool bankMenu = true;
bool validator = true;
bool pinLock;
bool transactionMenu;
bool firDep = true;

void usrVaildator();
void PinValidator();
void Password();
void Username();
void Pincode();
void BankMenu();

void pushDownTransactions() {
	for (int z = 0; z < 5; z++) {
		transactions[z + 1] = transactions[z];
	}
	struct Transaction resetTransaction;
	transactions[0] = resetTransaction;
}

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
		pinLock = false;
		system("cls");
		cout << "Welcome " << usrChecker << "\n";
		cout << "Balance: $" << balance << "\n\n";
		cout << "1. Deposit\n";
		cout << "2. Withdraw\n";
		cout << "3. Transaction Log\n\n";
		cin >> choice;
		if (choice == 1)
		{
			pinLock = true;
			system("cls");
			while (pinLock)
			{
				PinValidator();
			}
			system("cls");
			cout << "How much would you like to deposit\n\n";
			cout << "Amount: ";
			cin >> deposit;
			balance = balance + deposit;
			lastAction = deposit;
			if (firDep == true)
			{
				firDep = false;
			}
			else
			{
				counter = counter + 1;
				transactionsRecorded = counter;
			}
			if (counter >= (sizeof(transactions) / sizeof(Transaction))) {
				counter = 0;
				pushDownTransactions();
			}
				struct Transaction transact;
				transact.amount = deposit;
				transact.moneyMovement = " desposit ";
				transact.updated = true;
				transactions[counter] = transact;
			test = test + 1;
			if (test > 5)
			{
				test = 1;
			}
			for (m; m <= test2; m++)
			{
				MM[m] = moneyMovement;
			}
			if (m > 5)
			{
				m = 0;
			}
			test2 = test2 + 1;
			if (test2 > 5)
			{
				test2 = 1;
			}
			Sleep(500);
			system("cls");
			cout << "Deposit was successful\n";
			system("pause");
		}
		if (choice == 2)
		{
			system("cls");
			pinLock = true;
			while (pinLock)
			{
				PinValidator();
			}
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
				lastAction = withdraw;
				if (firDep)
				{
					counter = 0;
					firDep = false;
				}
				else
				{
					counter = counter + 1;
					transactionsRecorded = counter;
				}
				for (i; i <= test; i++)
				{
					struct Transaction transact;
					transact.amount = lastAction;
					transact.moneyMovement = " withdraw ";
					transactions[i] = transact;
					//transaction[i] = lastAction;
				}
				if (i > 5)
				{
					i = 0;
				}
				test = test + 1;
				if (test > 5)
				{
					test = 1;
				}
				for (m = 0; m <= test2; m++)
				{
					MM[m] = moneyMovement;
				}
				if (m > 5)
				{
					m = 0;
				}
				test2 = test2 + 1;
				if (test2 > 5)
				{
					test2 = 1;
				}
			}
		}
		if (choice == 3)
		{
			transactionMenu = true;
			while (transactionMenu)
			{
				system("cls");
				for (int k = 0; k <= transactionsRecorded; k++)
				{
					/*
					if (counter >= 1)
					{
						cout << usrChecker << MM[0] << "$" << transaction[0] << endl;
						if (counter >= 2)
						{
							cout << usrChecker << MM[1] << "$" << transaction[1] << endl;
							if (counter >= 3)
							{
								cout << usrChecker << MM[2] << "$" << transaction[2] << endl;
								if (counter >= 4)
								{
									cout << usrChecker << MM[3] << "$" << transaction[3] << endl;
									if (counter >= 5)
									{
										cout << usrChecker << MM[4] << "$" << transaction[4] << endl;
									}
								}
							}
						}
					}*/
					Transaction transact = transactions[k];
					cout << usrChecker << transact.moneyMovement << "$" << transact.amount << endl;
				}
				cout << "\n1. Back\n";
				cin >> choice;
				if (choice == 1)
				{
					transactionMenu = false;
				}
				if (choice >= 2)
				{
					system("cls");
					cout << "Not valued input\n";
					system("pause");
				}
			}
		}
	}
}

void PinValidator()
{
	system("cls");
	cout << "Pin: ";
	cin >> pin;
	if (pin != pinChecker)
	{
		cout << "\nIncorrected Pin\n";
		system("pause");
	}
	if (pin == pinChecker)
	{
		pinLock = false;
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

		if (pin < 1000 || pin > 9999)
		{
			pinNum = false;
			break;
		}
		else
		{
			break;
		}


	}
	if (!pinNum)
	{
		Pincode();
		return;
	}
	pinChecker = pin;
}
