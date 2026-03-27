#pragma once
#include"clsDate.h"
#include<cstdlib>
#include<cctype>
#include<iomanip>

using namespace std;

class clsUtil
{
public:
	enum enTypeofinput {
		SmallLetter = 1, CapitalLetter = 2,  Digit = 3, SpecialCharacter = 4, MixChar=5
	};

	static char GetRandomCharInRange(short start  ,short end ) {
		short Mychar = RandomNumber(start, end);
		if (Mychar >= 57 && Mychar <= 64 || Mychar >= 90 && Mychar <= 122) {
			return GetRandomCharInRange(start,end);
		}
		return char(Mychar);
	}


	static void Srand() {
		srand((unsigned)time(NULL));
	}
	
	static int RandomNumber(int from, int to) {
		int rnd = rand() % (to - from + 1) + from;
		return rnd;
	}

	static void FillArrayWithRandomNumbers(int Arr[], int Length,int from, int to) {
		for (int f = 0; f < Length; f++) {
				Arr[f] = RandomNumber(from,to);
		}
	}
	static void PrintArrayElements(int Arr[], int Length) {
		for (int f = 0; f < Length; f++) {
			cout<<Arr[f]<<" "  ;
		}
	}
	static void PrintArrayElements(string Arr[], int Length) {
		for (int f = 0; f < Length; f++) {
			cout << Arr[f] << endl;
		}
	}

	static void FillMatrixWithRandomNumbers(int Matrix[3][3], int Colum,int Row,int from, int to) {
		for (int f = 0; f < Row; f++) {
			for (int x = 0; x < Colum; x++) {
				Matrix[f][x] = RandomNumber(from, to);
			}
			
		}
	}
	static void PrintMatrixWithRandomNumber(int Matrix[3][3], int row, int colm) {
		cout << "The matrix element :\n";
		for (int a = 0; a < row; a++) {
			for (int b = 0; b < colm; b++) {
				cout << setw(3) << Matrix[a][b] << "  ";
			}
			cout << endl;
		}
	}


	static int RowSum(int Matrix[3][3], int FixRow, int colm) {
		int sum = 0;
		for (int j = 0; j < colm; j++) {
			sum += Matrix[FixRow][j];
		}
		return sum;
	}
	static void PrintSumOfEachRow(int Matrix[3][3], int Row, int Colm) {
		for (int x = 0; x < Row; x++) {
			cout << "Row" << x + 1 << " sum = " << RowSum(Matrix, x, Colm) << endl;
		}
	}

	static void StoreTheSumInMatrix(int Matrix[3][3], int Arr[9], int Row, int Colm) {

		for (int x = 0; x < Row; x++) {
			Arr[x] = RowSum(Matrix, x, Colm);
		}

	}

	static int SumColumn(int arr[3][3], int Rows, int FixColm) {
		int sum = 0;
		for (int x = 0; x < Rows; x++) {
			sum += arr[x][FixColm];
		}
		return sum;
	}

	static void PrintSumInEachColumnInMatrix(int arr[3][3], int Rows, int Colm) {
		cout << "\nThe sum of each column is : \n\n";
		for (int x = 0; x < Rows; x++) {
			cout << "Column " << x + 1 << " Sum = " << SumColumn(arr, Rows, x) << endl;
		}
	}


	static void FillArrayWithColumnOfMatrix(int arr[3][3], int arr2[5], int Rows, int Colm) {
		for (int a = 0; a < Rows; a++) {
			arr2[a] = SumColumn(arr, Rows, a);
		}
	}


	static void FillArrayWithOrderedNumbers(int Matrix[3][3], int Rows, int Colm) {
		int counter = 0;
		for (int f = 0; f < Rows; f++) {
			for (int g = 0; g < Colm; g++) {
				counter++;
				Matrix[f][g] = counter;
			}
		}
	}

	static void TransposedMatrix(int Matrix[3][3], int MatrixTransposed[3][3], short Rows, short Colm) {
		for (int x = 0; x < Rows; x++) {
			for (int h = 0; h < Colm; h++) {
				Matrix[x][h] = MatrixTransposed[h][x];
			}
		}
	}

	static void MultiplayTwoMatrixes(int Matrix1[3][3], int Matrix2[3][3], int MatrixResult[3][3], short Rows, short Colm) {
		for (int f = 0; f < Rows; f++) {
			for (int g = 0; g < Colm; g++) {
				MatrixResult[f][g] = Matrix1[f][g] * Matrix2[f][g];
			}
		}

	}

	static void PrintMilddleRow(int Arr[3][3], short Row, short colm) {
		short middleRow = Row / 2;
		for (int x = 0; x < colm; x++) {
			printf("%0*d ", 2, Arr[middleRow][x]);
		}
		cout << endl << endl;
	}


	static int SumOfMatrix(int Matrix[3][3], short Rows, short Colm) {
		int sum = 0;
		for (int f = 0; f < Rows; f++) {
			for (int g = 0; g < Colm; g++) {
				sum += Matrix[f][g];
			}
		}
		return sum;
	}

	static bool CheckIfMatricesAreEqualEachOthher(int Matrix1[3][3], int Matrix2[3][3]) {
		return(SumOfMatrix(Matrix1, 5, 5) == SumOfMatrix(Matrix2, 5, 5));
	}

	static bool CheckIfTypicalMatrices(int mtx1[3][3], int  mtx2[3][3], short row, short column) {
		for (int x = 0; x < row; x++) {
			for (int g = 0; g < column; g++) {
				if (mtx1[x][g] != mtx2[x][g]) {
					return false;
				}
			}
		}
		return true;
	}

	static bool CheckIfIdentityMatrix(int mtx1[3][3], short row, short column) {
		for (int x = 0; x < row; x++) {
			for (int g = 0; g < column; g++) {
				if (x == g && mtx1[x][g] != 1) {
					return false;
				}
				else if (x != g && mtx1[x][g] != 0) {
					return false;
				}
			}
		}
		return true;
	}






	static bool CheckIfIScalarMatrix(int mtx1[3][3], short row, short column) {
		int FirstDigitOfMatrix = mtx1[0][0];
		for (int x = 0; x < row; x++) {
			for (int g = 0; g < column; g++) {
				if (x == g && mtx1[x][g] != FirstDigitOfMatrix) {
					return false;
				}
				else if (x != g && mtx1[x][g] != 0) {
					return false;
				}

			}
		}
		return true;
	}


	static int EnterANumber(string Message = "",string InvalidMessage = "") {
		int Check = 0;
		cout << Message << " ";
		while (!(cin >> Check)) {
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cout << InvalidMessage<<" ";
		}
		return Check;
	}

	static short CountNumberRepeatInMatrix(int Matrix[3][3], short Rows, short Colm, short check) {
		short counter = 0;

		for (int a = 0; a < Rows; a++) {
			for (int x = 0; x < Colm; x++) {
				if (Matrix[a][x] == check) {
					counter++;
				}
			}
		}
		return counter;
	}

	static bool IsSparceMatrix(int Matrix[3][3], short Rows, short Colm) {

		short MatrixSize = Rows * Colm;

		return (CountNumberRepeatInMatrix(Matrix, Rows, Colm, 0) >= (MatrixSize / 2));
	}

	static bool CheckIfNumberExistInMatrix(int Matrix[3][3],short Check,short Rows, short Colm) {
		for (int a = 0; a < Rows; a++) {
			for (int x = 0; x < Colm; x++) {
				if (Matrix[a][x] == Check) {
					return true;
				}
			}
		}
		return 0;
	}

	static void PrintIntersectedNumber(int Matrix1[3][3], int Matrix2[3][3], short Rows, short Colm) {
		short Number = 0;
		for (int a = 0; a < Rows; a++) {
			for (int x = 0; x < Colm; x++) {
				Number = Matrix1[a][x];
				if (CheckIfNumberExistInMatrix(Matrix2, 3, 3, Number)) {
					cout << setw(3) << Number << " ";
				}
			}
		}
	}

	static int GetMaxNumberInMatrix(int Matrix[3][3], short Rows, short Colm) {
		int Max = Matrix[0][0];
		for (int a = 0; a < Rows; a++) {
			for (int x = 0; x < Colm; x++) {
				if (Matrix[a][x] > Max) {
					Max = Matrix[a][x];
				}
			}
		}
		return Max;
	}

	static int GetMinNumberInMatrix(int Matrix[3][3], short Rows, short Colm) {
		int Min = Matrix[0][0];
		for (int a = 0; a < Rows; a++) {
			for (int x = 0; x < Colm; x++) {
				if (Matrix[a][x] < Min) {
					Min = Matrix[a][x];
				}
			}
		}
		return Min;
	}
	
	static bool CheckIfPalindromeMatrix(int Matrix[3][3], short row, short colm) {
		for (int x = 0; x < row; x++) {
			for (int g = 0; g < colm / 2; g++) {
				if (Matrix[x][g] != Matrix[x][colm - 1 - g]) {
					return false;
				}

			}
		}
		return true;
	}

	static void FibonacciSeries(int Number) {
		int result = 0;
		int variable1 = 0;
		int variable2 = 1;
		cout << "1 ";
		for (int x = 2; x <= Number; x++) {
			result = variable1 + variable2;
			cout << result << " ";
			variable1 = variable2;
			variable2 = result;
		}
	}

	static int reversedNumber(int num) {
		int Remiander = 0;
		int revers = 0;
		while (num > 0) {
			Remiander = num % 10;
			num = num / 10;
			revers = revers * 10 + Remiander;
		}
		return revers;
	}

	static bool CheckIfPalindromeOrNot(int num) {
		return num == reversedNumber(num);
	}

	static char GetRandomCharacter(enTypeofinput type) {
		short Number = 0;
		if (type == MixChar) {
			type =(enTypeofinput) RandomNumber(1,3);
		}
		switch (type) {
		case enTypeofinput::SmallLetter:return char(RandomNumber(97, 122));
		case enTypeofinput::CapitalLetter:return char(RandomNumber(65, 90));
		case enTypeofinput::SpecialCharacter:return char(RandomNumber(33, 47));
		case enTypeofinput::Digit:return char(RandomNumber(48, 57));
		default:
			return char(RandomNumber(65, 90));
			
		}
	}

	static string GetWord(enTypeofinput type, int lenght) {
		string word = "";
		char MyChar = ' ';
		for (int i = 1; i <= lenght; i++) {
			word = word + GetRandomCharacter(type);
		}
		return word;
	}

	static string GetKey(enTypeofinput type) {
		string key = "";
		key = GetWord(type, 4) + "-";
		key += GetWord(type, 4) + "-";
		key += GetWord(type, 4) + "-";
		key += GetWord(type, 4);
		return key;
	}

	static void GenerateKeys(short Keys,enTypeofinput Type) {
		int counter = 0;
		string Arr[100];
		for (int f = 1; f <= Keys; f++) {
			counter++;
			cout<<GetKey(Type)<<" "<<endl;
		} 
		;
	}


	static void swap(int& A, int& B) {
		int swaper = 0;
		swaper = A;
		A = B;
		B = swaper;
	}

	static void swap(double& A, double& B) {
		int swaper = 0;
		swaper = A;
		A = B;
		B = swaper;
	}

	static void swap(string& A, string& B) {
		string swaper = "";
		swaper = A;
		A = B;
		B = swaper;
	}

	static void swap(char& A, char& B) {
		char swaper = 0;
		swaper = A;
		A = B;
		B = swaper;
	}

	static void swap(bool& A, bool& B) {
		bool swaper = 0;
		swaper = A;
		A = B;
		B = swaper;
	}
	
	static void swap(clsDate& date1, clsDate& date2) {
		clsDate Dateswap;
		Dateswap.Year = date1.Year;
		Dateswap.Month = date1.Month;
		Dateswap.Day = date1.Day;

		date1.Year = date2.Year;
		date1.Month = date2.Month;
		date1.Day = date2.Day;

		date2.Year = Dateswap.Year;
		date2.Month = Dateswap.Month;
		date2.Day = Dateswap.Day;

	}


	static void shuffle(int arr[100], int length) {
		for (int x = 0; x < length; x++) {
			swap(arr[RandomNumber(0, length - 1)], arr[RandomNumber(0, length - 1)]);
		}
	}

	static void shuffle(string arr[100], int length) {
		for (int x = 0; x < length; x++) {
			swap(arr[RandomNumber(0, length - 1)], arr[RandomNumber(0, length - 1)]);
		}
	}


	static  void FillArrayWithRandomWords(string Arr[100], short length) {
		for (short x = 0; x < length;x++) {
			Arr[x] = GetWord(enTypeofinput::MixChar, RandomNumber(5, 15));
		}
	}
	static  void FillArrayWithRandomKeys(string Arr[100], short length,enTypeofinput Type=enTypeofinput::MixChar) {
		for (short x = 0; x < length; x++) {
			Arr[x] = GetKey(Type);
		}
	}


	static string Tabs(short NumberOfTabs,bool AddSpace=false, short NumberOfSpaces=0) {
		string ReturnTab = "";
		for (short x = 0; x < NumberOfTabs; x++) {
			if (AddSpace) {
				ReturnTab += "\t" + AddSpaceToTabs(NumberOfSpaces);
			}
			else {
				ReturnTab += "\t";
			}
			
		}
		return ReturnTab;
	}

	static string AddSpaceToTabs(short NumberOfSpaces) {
		string ReturnSpace = "";
		for (short x = 0; x < NumberOfSpaces; x++) {
			
			ReturnSpace += " ";
		}
		return ReturnSpace;
	}


	static string EncryptTheName(string  Name,int  Key=2) {
		for (int i = 0; i < Name.length(); i++) {
			Name[i] = char(Name[i] + Key);
		}
		return Name;
	}
	static string DecryptedTheName(string Name, int Key=2) {
		for (int i = 0; i < Name.length(); i++) {
			Name[i] = char(Name[i] - (Key));
		}
		return Name;
	}


	static string NumberToText(int Number)
	{

		if (Number == 0)
		{
			return "";
		}

		if (Number >= 1 && Number <= 19)
		{
			string arr[] = { "", "One","Two","Three","Four","Five","Six","Seven",
		"Eight","Nine","Ten","Eleven","Twelve","Thirteen","Fourteen",
		  "Fifteen","Sixteen","Seventeen","Eighteen","Nineteen" };

			return  arr[Number] + " ";

		}

		if (Number >= 20 && Number <= 99)
		{
			string arr[] = { "","","Twenty","Thirty","Forty","Fifty","Sixty","Seventy","Eighty","Ninety" };
			return  arr[Number / 10] + " " + NumberToText(Number % 10);
		}

		if (Number >= 100 && Number <= 199)
		{
			return  "One Hundred " + NumberToText(Number % 100);
		}

		if (Number >= 200 && Number <= 999)
		{
			return   NumberToText(Number / 100) + "Hundreds " + NumberToText(Number % 100);
		}

		if (Number >= 1000 && Number <= 1999)
		{
			return  "One Thousand " + NumberToText(Number % 1000);
		}

		if (Number >= 2000 && Number <= 999999)
		{
			return   NumberToText(Number / 1000) + "Thousands " + NumberToText(Number % 1000);
		}

		if (Number >= 1000000 && Number <= 1999999)
		{
			return  "One Million " + NumberToText(Number % 1000000);
		}

		if (Number >= 2000000 && Number <= 999999999)
		{
			return   NumberToText(Number / 1000000) + "Millions " + NumberToText(Number % 1000000);
		}

		if (Number >= 1000000000 && Number <= 1999999999)
		{
			return  "One Billion " + NumberToText(Number % 1000000000);
		}
		else
		{
			return   NumberToText(Number / 1000000000) + "Billions " + NumberToText(Number % 1000000000);
		}


	}




};

