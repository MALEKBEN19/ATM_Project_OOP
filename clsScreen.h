#pragma once
#include"clsInputValidate.h"
#include"clsDate.h"
#include"Global.h"
class clsScreen
{
public:

	static void DrawHeaderScreen(string Title,string SubTitle="") {
		cout << "\t\t\t\t----------------------------------------------------------------------------------\n\n";
		cout << "\t\t\t\t\t\t\t\t    " << Title << endl;
		if (SubTitle != "") {
			cout << "\t\t\t\t\t\t\t\t   " << SubTitle << endl;
		}
		cout << "\n\t\t\t\t----------------------------------------------------------------------------------\n";
		cout << "\t\t\t\t Date/Time : " << clsDate::GetSystemDateTimeString() << endl;
		cout << "\t\t\t\t Client : " << CurrentClient.FullName()<<endl;

	}


};

