#pragma once
#include "clsPerson.h"
class clsClient :
    public clsPerson
{
private:
    enum eMode{eEmptyMode=0,eUpdateMode=1};
    eMode _Mode;
    string _AccountNumber;
    string _PinCode;
    double _Balance;



    clsClient _GetEmptyObject() {
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


};

