#pragma once
#include "clsPerson.h"
#include<vector>
#include<fstream>
#include<string>
class clsClient :
    public clsPerson
{
private:
    enum eMode{eEmptyMode=0,eUpdateMode=1};
    eMode _Mode;
    string _AccountNumber;
    string _PinCode;
    double _Balance;


    static string _ConvertObjectToLine(clsClient &client,string Sperator = "#//#") {
        string line = "";
        line += client.FirstName+Sperator;
        line+= client.LastName + Sperator;
        line += client.Email + Sperator;
        line += client.Phone + Sperator;
        line += client.GetAccountNumber() + Sperator;
        line += client.PinCode + Sperator;
        line += to_string(client.balance);
        return line;
    }

    static void _SaveDataToFile(vector<clsClient>&vclient) {
        fstream Myfile;
        Myfile.open("Clients.txt", ios::out);
        if (Myfile.is_open()) {
            string Line = "";
            for (clsClient clt : vclient) {
                Line = _ConvertObjectToLine(clt);
                Myfile << Line << endl;
            }
            Myfile.close();
        }
    }
    void _UpdateObject(clsClient Client) {
        vector<clsClient>vclient = _LoadClientDataFromFile();
        for (clsClient &clt : vclient) {
            if (Client.GetAccountNumber() == clt.GetAccountNumber()) {
                clt = *this;
               
            }
        }
        _SaveDataToFile(vclient);
    }
    
    static clsClient _ConvertLineToObject(string Line,string Sperator="#//#") {
        vector<string>vWords = clsString::Split(Line, Sperator);
        return clsClient(eMode::eUpdateMode, vWords[0], vWords[1], vWords[2], vWords[3], vWords[4], vWords[5], stod(vWords[6]));
    }
    static vector<clsClient>_LoadClientDataFromFile() {
        fstream Myfile;
        vector<clsClient>vClient;
        Myfile.open("Clients.txt", ios::in);
        if (Myfile.is_open()) {
            string Line = "";
            clsClient client = _GetEmptyObject();
            while (getline(Myfile, Line)) {
                if (Line != "") {
                    client = _ConvertLineToObject(Line);
                    vClient.push_back(client);
                }
             
                    
            }
            Myfile.close();
            return vClient;
        }
        
    }



    static clsClient _GetEmptyObject() {
        return clsClient(eMode::eEmptyMode, "", "", "", "", "", "", 0);
    }


    

public:

    clsClient(eMode Mode,string FirstName,string LastName,string Email,string Phone,string AccountNumber,string PinCode,double Balance) 
        :clsPerson(FirstName,LastName,Email,Phone)
    {
        _Mode = Mode;
        _AccountNumber = AccountNumber;
        _PinCode = PinCode;
        _Balance = Balance;
    }

     string GetAccountNumber() {
        return _AccountNumber;
    }

    void SetPinCode(string PinCode) {
        _PinCode = PinCode;
    }
    string GetPinCode() {
       return _PinCode ;
    }
    _declspec(property(get = GetPinCode, put = SetPinCode)) string PinCode;

    void SetBalance(double Balance) {
        _Balance = Balance;
    }
    double GetBalance() {
        return _Balance;
    }
    _declspec(property(get = GetBalance, put = SetBalance)) double balance;

    static clsClient Find(string AccountNumber) {
        vector<clsClient>vClients = _LoadClientDataFromFile();
        for (clsClient& clt : vClients) {
            if (clt.GetAccountNumber() == AccountNumber) {
                return clt;
            }
        }
        return _GetEmptyObject();
    }

    static clsClient Find(string AccountNumber,string PinCode) {
        vector<clsClient>vClients = _LoadClientDataFromFile();
        for (clsClient& clt : vClients) {
            if (clt.GetAccountNumber() == AccountNumber && clt.GetPinCode()== PinCode) {
                return clt;
            }
        }
        return _GetEmptyObject();
    }
    
    void Update() {
        _UpdateObject(*this);
    }

    enum eChooseAmountForQuickWithdraw {
        twenty = 1, fifty = 2, OneHundared = 3, TwoHundared = 4,
        FourHundared = 5, SixHundared = 6, EightHundared = 7, OneThousand = 8, Exit = 9
    };

    bool QuickWithDraw(eChooseAmountForQuickWithdraw AmountToWithdraw) {
        switch (AmountToWithdraw) {
        case eChooseAmountForQuickWithdraw::twenty: {
            return WithDraw(20);
        }case eChooseAmountForQuickWithdraw::fifty: {
            return WithDraw(50);
        }
        case eChooseAmountForQuickWithdraw::OneHundared: {
            return WithDraw(100);
        }
        case eChooseAmountForQuickWithdraw::TwoHundared: {
            return WithDraw(200);
        }
        case eChooseAmountForQuickWithdraw::FourHundared: {
            return WithDraw(400);
        }
        case eChooseAmountForQuickWithdraw::SixHundared: {
            return WithDraw(600);
        }
        case eChooseAmountForQuickWithdraw::EightHundared: {
            return WithDraw(800);
        }
        case eChooseAmountForQuickWithdraw::OneThousand: {
            return WithDraw(1000);
        }case eChooseAmountForQuickWithdraw::Exit: {
            return false;
        }
        }
    }

    bool WithDraw(double Amount) {
        if (Amount == 0) {
            return false;
        }
        else if (Amount > balance) {
            return false;
        }
        else {
            balance -= Amount;
            Update();
            return true;
        }
    }

    bool Deposit(double Amount) {
        if (Amount == 0) {
            return false;
        }
        else {
           balance += Amount;
           Update();
        }
 
        return true;
    }


};

