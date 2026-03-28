#pragma once
#include "clsScreen.h"
class clsBalanceScreen :
    protected clsScreen
{

public:

    static void ShowBalanceScreen() {
        DrawHeaderScreen("Balance Screen");
        cout << "\n\t\t\t\t\t============================================================\n\n";
        cout << "\t\t\t\t\t\t\t Your Balance Is : "<<CurrentClient.balance<<endl<<endl;
        cout << "\t\t\t\t\t\t\t" << clsUtil::NumberToText(CurrentClient.balance) << endl << endl;
        cout << "\t\t\t\t\t============================================================\n\n";
    }





};

