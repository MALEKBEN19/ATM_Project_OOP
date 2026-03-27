#pragma once
#include"clsUtil.h"
#include<cmath>
using namespace std;

class clsInputValidate
{
public:
	static bool IsNumberBetween(int from, int to, int CheckNumber ) {
		return (CheckNumber >= from && CheckNumber <= to);
	}
	static bool IsNumberBetween( double from, double to ,double CheckNumber ) {
		return (CheckNumber >= from && CheckNumber <= to);
	}

	static bool IsDateBetween(clsDate FirstDate,clsDate SecondDate,clsDate DateToCheck) {
		return (clsDate::IsDateInPeriod(FirstDate, SecondDate, DateToCheck) ||
			clsDate::IsDateInPeriod(SecondDate, FirstDate, DateToCheck));
	}


	static int ReadIntNumber(string Message = "",string InvalidMessage="") {
		return clsUtil::EnterANumber(Message , InvalidMessage);
	}

	static double ReadDoubleNumber(string Message = "", string InvalidMessage = "") {
		double Check = 0;
		cout << Message << " ";
		cin >> Check;
		while (cin.fail()) {
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cout << InvalidMessage << " ";
			cin >> Check;
		}
		return Check;
	}
	static float ReadFloatNumber(string Message = "", string InvalidMessage = "") {
		float Check = 0;
		cout << Message << " ";
		cin >> Check;
		while (cin.fail()) {
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cout << InvalidMessage << " ";
			cin >> Check;
		}
		return Check;
	}
	
	static int ReadNumberBetween(int From,int To,string message = "",string InvalidMessage = "") {
		int Number = ReadIntNumber(message, InvalidMessage);
		while (!IsNumberBetween(From, To, Number)){
			Number=ReadIntNumber(message, InvalidMessage);
		}
		return Number;
	}


	static double ReadNumberBetween(double From, double To, string message = "", string InvalidMessage = "") {
		double Number = ReadDoubleNumber(message, InvalidMessage);
		while (!IsNumberBetween(From, To, Number)) {
			Number = ReadDoubleNumber(message, InvalidMessage);
		}
		return Number;
	}


	static bool IsValidDate(clsDate Date) {
		return clsDate::IsValidDate(Date);
	}



	static string ReadString(string Message = "") {
		string Text="";
		cout << Message << " ";
		getline(cin >> ws, Text);
		return Text;
	}

	static char ReadChar(string Message = "") {
		char MyChar = ' ';
		cout << Message << " ";
		cin >> MyChar;
		return MyChar;
	}



	static string ReadText(string Message="", string InvalidMessage="") {
		string Text = "";
		cout << Message << " ";
		getline(cin >> ws, Text);
		while (Text.length()==0) {
			cout << InvalidMessage << " ";
			getline(cin >> ws, Text);
		}
		return Text;
	}

};

