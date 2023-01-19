#include <iostream>
#include <string>
#include <windows.h>

using namespace std;

void Login();
void askForSecretPassword();

bool login = true;
string usrname;
string passwd;


int main()
{
    Login();
}

void Login()
{
    while (login)
    {
        system("cls");
        cout << "Username: ";
        cin >> usrname;
        askForSecretPassword();
    }
}

void askForSecretPassword(void) 
{
    passwd = "";
    while (!GetAsyncKeyState(VK_RETURN) & 1)
    {
        for (int i = 0x30; i < 0x5A; i++)
        {
            if (GetAsyncKeyState(i) & 1)
            {
                if (i >= 0x41 && i <= 0x5A && ((GetKeyState(VK_CAPITAL) & 1) == 0 || GetAsyncKeyState(VK_SHIFT) & 1))
                    passwd += ((char)i + 32);
                else
                    passwd += (char)i;

                cout << "*";
                Sleep(50);
            }
            else if (GetAsyncKeyState(VK_BACK) & 1)
            {
                passwd.erase(passwd.size() - 1);
                system("cls");
                for (int i = 0; i < passwd.size(); i++)
                {
                    cout << '*';
                }
                Sleep(50);
            }
        }
    }
    cout << passwd;
    Sleep(10000);
};