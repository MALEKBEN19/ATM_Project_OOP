#pragma once
#include<iostream>
#include<string>
#include<cctype>
#include<vector>
using namespace std;






class clsString
{
private:
	
	char _CharValue;
	string _Value;
	string _ValueReplace;
	string _ValueReplaceTo;
	string _Delim;
	vector<string> _Vwords;

public:
	

	clsString() {
		_Value = "";
		_CharValue = ' ';
		_Delim = " ";
		_Vwords.push_back("");
		_ValueReplace="";
		_ValueReplaceTo="";
	}
	clsString(string Value) {
		_Value = Value;
	}

	//setter & Getter : 

	void SetValue(string Value) {
		_Value = Value;
	}
	string GetValue() {
		return _Value;
	}
	_declspec(property(get = GetValue, put = SetValue))string Value  ; 

	void SetCharValue(char  CharValue) {
		_CharValue = CharValue;
	}
	char GetCharValue() {
		return _CharValue;
	}

	_declspec(property(get = GetCharValue, put = SetCharValue))char CharValue;

	void SetDelim(string Delim) {
		_Delim = Delim;
	}
	string GetDelim() {
		return _Delim;
	}
	_declspec(property(get = GetDelim, put = SetDelim))string Delim;

	void SetWords(string Word) {
		_Vwords.push_back(Word);
	}
	vector<string> GetWords() {
		return _Vwords;
	}
	_declspec(property(get = GetWords, put = SetWords))vector<string> Word;


	void SetValueReplace(string ValueReplace) {
		_ValueReplace = ValueReplace;
	}
	string GetValueReplace() {
		return _ValueReplace;
	}
	_declspec(property(get = GetValueReplace, put = SetValueReplace))string ValueReplace;


	void SetValueReplaceTo(string ReplaceTo) {
		_ValueReplaceTo = ReplaceTo;
	}
	string GetValueReplaceTo() {
		return _ValueReplaceTo;
	}
	_declspec(property(get = GetValueReplaceTo, put = SetValueReplaceTo))string ReplaceTo;









	//String Methods :



	



	static void PrintEachFirstLetterFromAString(string &GetString) {
		bool FirstLetter = true;
		for (int x = 0; x < GetString.length(); x++) {
			if (GetString[x] != ' ' && FirstLetter) {
				cout << GetString.at(x) << endl;
			}
			FirstLetter = (GetString[x] == ' ' ? true : false);
		}
	}
	void PrintEachFirstLetterFromAString() {
		PrintEachFirstLetterFromAString(_Value);
	}

	static void MakeEachFirstLetterToUpper(string & GetString) {
		bool firstLetter = true;
		for (short y = 0; y < GetString.length(); y++) {
			if (GetString[y] != ' ' && firstLetter) {

				GetString[y] = toupper(GetString[y]);

			}
			firstLetter = (GetString[y] == ' ' ? true : false);

		}
	}
	 void MakeEachFirstLetterToUpper() {
		 MakeEachFirstLetterToUpper(_Value);
	}

	 static void MakeEachFirstLetterToLower(string & GetString) {
		 bool firstLetter = true;
		 for (short y = 0; y < GetString.length(); y++) {
			 if (GetString[y] != ' ' && firstLetter) {

				 GetString[y] = tolower(GetString[y]);

			 }
			 firstLetter = (GetString[y] == ' ' ? true : false);

		 }
	 }

	 void MakeEachFirstLetterToLower() {
		 MakeEachFirstLetterToLower(_Value);
	 }


	 static string ConvertAllLetterToUpper(string  letter) {
		 for (short f = 0; f < letter.length(); f++) {
			 if (letter[f] != ' ') {
				 letter[f] = toupper(letter[f]);
			 }
		 }
		 return letter;
	 }

	 string ConvertAllLetterToUpper() {
		 _Value = ConvertAllLetterToUpper(_Value);
		 return _Value;
	 }




	 static string ConvertAllLetterToLower(string &letter) {
		 for (short f = 0; f < letter.length(); f++) {
			 if (letter[f] != ' ') {
				 letter[f] = tolower(letter[f]);
			 }
		 }
		 return letter;
	 }

	 string ConvertAllLetterToLower() {
		 _Value=ConvertAllLetterToLower(_Value);
		 return _Value;
	 }

	 static char InvertCharacter(char  & Charact) {
		 Charact = isupper(Charact) ? tolower(Charact) : toupper(Charact);
		 return Charact;
	 }

	 char  InvertCharacter() {
		return InvertCharacter(_CharValue);
	 }

	 static string ConvertLowerToUpperAndUpperToLower(string Text) {
		 for (int b = 0; b < Text.length(); b++) {
			 Text[b] = InvertCharacter(Text[b]);
		 }
		 return Text;
	 }

	 string  ConvertLowerToUpperAndUpperToLower() {
		 _Value = ConvertLowerToUpperAndUpperToLower(Value);
			 return _Value; 
	 }

	static short CountAllCapitalLetterInString(string Text) {
		 short counter = 0;
		 for (int b = 0; b < Text.length(); b++) {
			 if (isupper(Text[b])) {
				 counter++;
			 }
		 }
		 return counter;
	 }

	 short CountAllCapitalLetterInString() {
		 return CountAllCapitalLetterInString(_Value);
	 }


	static short CountAllSmallerLetterInString(string Text) {
		 short counter = 0;
		 for (int b = 0; b < Text.length(); b++) {
			 if (islower(Text[b])) {
				 counter++;
			 }
		 }
		 return counter;
	 }

	 short CountAllSmallerLetterInString() {
		 return CountAllSmallerLetterInString(_Value);
	 }

	 static short Length(string letter) {
			 return letter.length();
	 }

	 short Length() {
		 return Length(_Value);
	 }

	 static short CountCharInText(string Text, char character) {
		 short count = 0;
		 for (short h = 0; h < Text.length(); h++) {
			 if (Text[h] == character) {
				 count++;
			 }
		 }
		 return count;

	 }

	 short CountCharInText() {
		 return CountCharInText(_Value,_CharValue);
	}

	 static short CountSpecificLetterInText(string Mystring, char MyChar,bool MatchCase=true) {
		 short counter = 0;
		 for (short g = 0; g < Mystring.length(); g++) {
			 if (MatchCase) {
				 if (Mystring[g] == MyChar || Mystring[g] == toupper(MyChar)) {
					 counter++;
				 }
			 }
			 else {
				 if (Mystring[g] == MyChar) {
					 counter++;
				 }
			 }
		
		 }
		 return counter;
	 }

	 short CountSpecificLetterInText(bool MatchCase=true) {
		 return CountSpecificLetterInText(_Value, _CharValue, MatchCase);
	 }

	static bool CheckIfCharIsVowel(char ToCheck) {
		 char Vowels[5]{ 'a','i','e','o','u' };
		 for (short x = 0; x < 5; x++) {
			 if (ToCheck == Vowels[x]) {
				 return 1;
			 }
		 }
		 return 0;
	 }
	 bool CheckIfCharIsVowel() {
		 return CheckIfCharIsVowel(_CharValue);
	 }

	 static short CountVowelsInText(string Text) {

		 short Counter = 0;
		 for (short b = 0; b < Text.length(); b++) {
			 if (CheckIfCharIsVowel(Text[b]))
			 {
				 Counter++;
			 }
		 }
		 return Counter;
	 }
	 short CountVowelsInText() {
		 return CountVowelsInText(_Value);
	 }

	 static void PrintAlLVowelsInText(string Text) {

		 short Counter = 0;
		 for (short b = 0; b < Text.length(); b++) {
			 if (CheckIfCharIsVowel(Text[b]))
			 {
				 cout << Text[b] << " ";
			 }
		 }

	 }
	void PrintAlLVowelsInText() {
		PrintAlLVowelsInText(_Value);
	}

	static void PrintEverySingleWordInNewLine(string Text) {
		string Delim = " ";
		short Postion = 0;
		string word = "";
		while ((Postion = Text.find(Delim)) != std::string::npos) {
			word = Text.substr(0, Postion);
			if (word != "") {
				cout << word << endl;
			}
			Text.erase(0, Postion + Delim.length());
		}
		if (Text != "")
			cout << Text << endl;
	}
	void PrintEverySingleWordInNewLine() {
		PrintEverySingleWordInNewLine(_Value);
	}

	static short CountEachwordInText(string Text) {
		short Counter = 0;
		string Delim = " ";
		short Postion = 0;
		string Word = "";
		while ((Postion = Text.find(Delim)) != std::string::npos) {
			Word = Text.substr(0, Postion);
			if (Word != "") {
				Counter++;
			}
			Text.erase(0, Postion + Delim.length());
		}
		if (Text != "") {
			Counter++;
		}
		return Counter;
	}

	short CountEachwordInText() {
		return CountEachwordInText(_Value);
	}

	static vector<string> Split(string Text, string Delim,bool CountEmpty=false) {
		vector<string>vText;
		short Postion = 0;
		string Word = "";
		while ((Postion = Text.find(Delim)) != std::string::npos) {
			Word = Text.substr(0, Postion);
			if (CountEmpty) {
				vText.push_back(Word);
			}
			else {

				if (Word != "") {
					vText.push_back(Word);
				}
				
			}

			Text.erase(0, Postion + Delim.length());
		}

		if (Text != "") {
			vText.push_back(Text);
		}
		
		
		return vText;
	}

	vector<string> Split() {
		return Split(_Value,_Delim);
	}




	static string TrimLeft(string &Text) {

		for (short x = 0; x < Text.length(); x++) {
			if (Text[x] != ' ') {
				Text= Text.substr(x, Text.length() - x);
				return Text;
			}
		}
		return "";

	}
	string TrimLeft() {
		_Value = TrimLeft(_Value);
		return _Value;
	}


	static string TrimRight(string & Text) {

		for (short i = Text.length() - 1; i >= 0; i--) {
			if (Text[i] != ' ') {
				Text = Text.substr(0, i + 1);
				return Text;
			}
		}

		return "";

	}

	string TrimRight() {
		_Value = TrimRight(_Value);
		return _Value;
	}


	static string Trim(string &Text) {
		TrimRight(Text);
		TrimLeft(Text);
		return Text;
	}


	string Trim() {
		_Value = Trim(_Value);
		return _Value;
	}



	static string JointText(vector <string>& vWords, string Delim) {
		string ToJoin = "";
		for (string& txt : vWords) {
			ToJoin += txt + Delim;
		}
		return ToJoin.substr(0, ToJoin.length() - Delim.length());

	}

	string JointText() {
		_Value= JointText(_Vwords, _Delim);
		return _Value;
	}


	static string ReplaceWordInStringUsingBuildInFunction(string Text, string Replace, string ReplaceTo) {
		
		if (Replace.empty())
		{
			return Text;
		}
		size_t Pos = 0;

		while ((Pos = Text.find(Replace, Pos)) != std::string::npos) {
			Text.replace(Pos, Replace.length(), ReplaceTo);
			Pos += ReplaceTo.length();
		}

		return Text;
	}

	string ReplaceWordInStringUsingBuildInFunction() {

		 _Value=ReplaceWordInStringUsingBuildInFunction(_Value, _ValueReplace, _ValueReplaceTo);
		 return _Value;
	}



	static string RemovePunct(string Txt) {
		string AllString = "";
		for (short b = 0; b < Txt.length(); b++) {
			if (!ispunct(Txt[b])) {
				AllString += Txt[b];
			}
		}
		return AllString;
	}

	string RemovePunct() {
		_Value=RemovePunct(_Value);
		return _Value;
	}



};


