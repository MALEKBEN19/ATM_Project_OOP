#pragma once
#include "clsScreen.h"
class clsDepositScreen :
    protected clsScreen
{
private:

    static int _ReadAmount() {
        int  Amount = 0;
        cout << "\nPlease Enter An Amount To Deposit ";
        cin >> Amount;
        while (Amount <= 0) {
            cout << "\nWrong Amount, Please Enter A Positve Amount ";
            cin >> Amount;
        }
        return Amount;
    }

public:

    static void ShowDepositScreen() {
        DrawHeaderScreen("Deposit Screen");
        int Amount = _ReadAmount();
        cout << "\nAre You Sure You Want To Perform This Operation Y/N ";
        char Answer = clsInputValidate::ReadChar();
        if (toupper(Answer) == 'Y') {
            if (CurrentClient.Deposit(Amount)) {
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

