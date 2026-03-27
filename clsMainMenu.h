#pragma once
#include "clsScreen.h"
#include"clsQuickWithDrawScreen.h"
#include"clsClient.h"
#include"clsNormalWithDrawScreen.h"
#include"clsDepositScreen.h"
#include"clsBalanceScreen.h"
class clsMainMenu :
    protected clsScreen
{
private:
    enum eMenuOption{eQuickWithDraw=1,eNormalWithDraw=2,eDeposit=3,eBalance=4,eLogout=5};

   static short _ReadMenuOption() {
        cout << "\t\t\t\t\tWhat Do You want to Choose From [1] To [5]";
        short Input = clsInputValidate::ReadIntNumber();
        return Input;
    }

    
   static void ShowQuickWithDrawScreen() {
       /*cout << "Quick WithDraw Will Be here!\n";*/
       clsQuickWithDrawScreen::ShowQuickWithDrawScreen();
   }
   static void ShowNormalWithDrawScreen() {
       /*cout << "Normal WithDraw Will Be here!\n";*/
       clsNormalWithDrawScreen::ShowNormalWithdrawScreen();
   }
   static void ShowDepositScreen() {
       /*cout << "Deposit Will Be here!\n";*/
       clsDepositScreen::ShowDepositScreen();
   }
   static void ShowBalanceScreen() {
      /* cout << "Balance Will Be here!\n";*/
       clsBalanceScreen::ShowBalanceScreen();
   }
   static void ShowLoginScreen() {
      /* cout << "Login Will Be here!\n";*/
       CurrentClient = clsClient::Find("", "");
   }



   static void GoBackToMainMenu() {
       cout << "\n\n  Press Any Key To Go Back To Main Menu...";
       system("pause>0");
       ShowMainMenuScreen();
   }
    static void _PerformMenuOption(eMenuOption Option) {
        switch (Option) 
        {
        case eMenuOption::eQuickWithDraw: {
            system("cls");
            ShowQuickWithDrawScreen();
            GoBackToMainMenu();
            break;
        }
        case eMenuOption::eNormalWithDraw: {
            system("cls");
            ShowNormalWithDrawScreen();
            GoBackToMainMenu();
            break;
        }
        case eMenuOption::eDeposit: {
            system("cls");
            ShowDepositScreen();
            GoBackToMainMenu();
            break;
        }
        case eMenuOption::eBalance: {
            system("cls");
            ShowBalanceScreen();
            GoBackToMainMenu();
            break;
        }
        case eMenuOption::eLogout: {
            system("cls");
            ShowLoginScreen();
            break;
        }
        }
    }


public:

    static void ShowMainMenuScreen() {
        system("cls");
        DrawHeaderScreen(" Welcome To","ATM Menu Screen");
        cout << "\n\t\t\t\t\t============================================================\n";
        cout << "\t\t\t\t\t\t\t      Main Menu Screen\n";
        cout << "\t\t\t\t\t============================================================\n\n";
        cout << "\t\t\t\t\t  [1] Quick WithDraw." << endl;
        cout << "\t\t\t\t\t  [2] Normal WithDraw." << endl;
        cout << "\t\t\t\t\t  [3] Deposit." << endl;
        cout << "\t\t\t\t\t  [4] Balance." << endl;
        cout << "\t\t\t\t\t  [5] Logout." << endl;
        cout << "\n\t\t\t\t\t============================================================\n";
        _PerformMenuOption(eMenuOption(_ReadMenuOption()));
    }





};

