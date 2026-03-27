#pragma once
#include "clsScreen.h"


class clsQuickWithDrawScreen :
    protected clsScreen
{
private:

    static short _ReadOptions() {
        cout << "\t\t\t\t\tPlease Choose Amount To QuickWithDraw  [1] To [8]";
        short Input = clsInputValidate::ReadNumberBetween(1,9);
        return Input;
    }

    static void _DrawMenu() {
        cout << "\n\t\t\t\t\t============================================================\n";
        cout << "\t\t\t\t\t\t\t      Quick WithDraw Menu \n";
        cout << "\t\t\t\t\t============================================================\n\n";
        cout << "\t\t\t\t\t\t  [1] $20\t\t [2] $50" << endl;
        cout << "\t\t\t\t\t\t  [3] $100\t\t [4] $200" << endl;
        cout << "\t\t\t\t\t\t  [5] $400\t\t [6] $600" << endl;
        cout << "\t\t\t\t\t\t  [7] $800\t\t [8] $1000" << endl;
        cout << "\t\t\t\t\t\t  [9] Exit." << endl;
        cout << "\n\t\t\t\t\t============================================================\n";

    }

    static void _PerformTheOperation(clsClient &Client) {
        clsClient::eChooseAmountForQuickWithdraw eOption =(clsClient::eChooseAmountForQuickWithdraw) _ReadOptions();
        if (eOption == 9) {
            return;
        }
        cout << "\n\nAre You Sure You Want To Perform This Operation? Y/N";
        char MyAnswer = clsInputValidate::ReadChar();
        if (toupper(MyAnswer) == 'Y') {
            if (Client.QuickWithDraw(eOption)) {
                cout << "\nQuickWithDraw Done Successfully.\n";
            }
            else {
                cout << "\nOperation Was Cancelled.\n";
            }
        }
        else {
            cout << "\nOperation Was Cancelled.\n";
        }

    }


public:

    static void ShowQuickWithDrawScreen() {
        DrawHeaderScreen("Quick Withdraw Screen");
        _DrawMenu();
        _PerformTheOperation(CurrentClient);
    }



};

