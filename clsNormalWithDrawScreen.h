#pragma once
#include "clsScreen.h"

class clsNormalWithDrawScreen :
    protected clsScreen
{

private:

    static int _ReadAmount() {
        int  Amount = 0;
        cout << "\nPlease Enter An Amount Multiple Of 5's ? ";
        cin >> Amount;
        while (Amount % 5 != 0) {
            cout << "\nWrong Amount, Please Enter An Amount Multiple Of 5's ? ";
            cin >> Amount;
        }
        return Amount;
    }

public:

    static void ShowNormalWithdrawScreen() {
        DrawHeaderScreen("Normal Withdraw Screen");
        int Amount = _ReadAmount();
        cout << "\nAre You Sure You Want To Perform This Operation Y/N ";
        char Answer = clsInputValidate::ReadChar();
        if (toupper(Answer) == 'Y') {
            if (CurrentClient.WithDraw(Amount)) {
                cout << "\nOperation Done Successfully :-)";
                cout << "\nYour Balance Is : " << CurrentClient.balance << endl;
            }
            else {
                cout << "\nOperation Was Cancelled :-(\n";
                return;
            }
        }
        else {
            cout << "\nOperation Was Cancelled :-(\n";
        }
    }





};

