#pragma once
#include "clsScreen.h"
#include"clsMainMenu.h"
class clsLoginScreen :
    protected clsScreen
{
public:


    static void ShowLoginScreen() {
        bool LogainFailed = false;
        string AccountN = "";
        string PinCode = "";
        do {
            system("cls");
            DrawHeaderScreen("Login Screen");
            if (LogainFailed) {
                cout << "\nWorng Account Number/PinCode >:(\n";
            }
            cout << "\nEnter Account Number : ";
            cin >> AccountN;
            cout << "Enter Pin Code : ";
            cin >> PinCode;

            CurrentClient = clsClient::Find(AccountN, PinCode);
            LogainFailed = CurrentClient.IsEmpty();

        } while (LogainFailed);
        clsMainMenu::ShowMainMenuScreen();
    }





};

