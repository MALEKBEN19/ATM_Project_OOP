#pragma once
#include"clsString.h"
#include<ctime>
#pragma warning(disable:4996)

class clsDate
{
private:

	static tm* _TodaysDate() {
		time_t t = time(0);
		tm* now = localtime(&t);
		return now;
	}
	short _AddDaysToDate;
	short _DayOrderInYear;
	short _DayWeekOrder;
	short _Year;
	short _Month;
	short _Day;
	short _Hours;
	short _Minutes;
	short _Seconds;
public:


	//constructors: 

	clsDate() {
		
		_AddDaysToDate = 0;
		_DayOrderInYear = 0;
		_DayWeekOrder = 0;
		_Year = _TodaysDate()->tm_year + 1900;
		_Month = _TodaysDate()->tm_mon + 1;
		_Day = _TodaysDate()->tm_mday;
		_Hours = _TodaysDate()->tm_hour ;
		_Minutes = _TodaysDate()->tm_min + 1;
		_Seconds = _TodaysDate()->tm_sec;
	}




	clsDate(string Date) {
		clsDate date = ConvertStringToClassDate(Date);
		_Year = date.Year;
		_Month = date.Month;
		_Day = date.Day;
	}




	clsDate(short day, short month, short year) {
		
		_Year = year;
		_Month = month;
		_Day = day;
	
	}
	clsDate(short Day, short Year) {
		*this = GetDateFromDayOrderInYear(Day, Year);
	}


	//set & Get 
	void SetYear(short Year) {
		_Year = Year;
	}
	short GetYear() {
		return _Year;
	}

	_declspec(property(get = GetYear, put = SetYear))short Year;

	void SetMonth(short Month) {
		_Month = Month;
	}
	short GetMonth() {
		return _Month;
	}

	_declspec(property(get = GetMonth, put = SetMonth))short Month;

	void SetDay(short Day) {
		_Day = Day;
	}
	short GetDay() {
		return _Day;
	}

	_declspec(property(get = GetDay, put = SetDay))short Day;


	void SetDayWeekOrder(short Day) {
		_DayWeekOrder = Day;
	}
	short GetDayWeekOrder() {
		return _DayWeekOrder;
	}

	_declspec(property(get = GetDayWeekOrder, put = SetDayWeekOrder))short DayWeekOrder;


	void SetDayOrderInYear(short Day) {
		_DayOrderInYear = Day;
	}
	short GetDayOrderInYear() {
		return _DayOrderInYear;
	}

	_declspec(property(get = GetDayOrderInYear, put = SetDayOrderInYear))short DayOrderInYear;

	void SetAddDaysToDate(short days) {
		_AddDaysToDate = days;
	}


	clsDate GetFullDate() {
		return *this;
	}

	//Methods : 

	static short NumberOfDaysInAYear(short Year)
	{
		return isLeapYear(Year) ? 366 : 365;
	}
	short NumberOfDaysInAYear()
	{
		return NumberOfDaysInAYear(_Year);
	}

	static short NumberOfHoursInAYear(short Year)
	{
		return NumberOfDaysInAYear(Year) * 24;
	}
	short NumberOfHoursInAYear()
	{
		return NumberOfHoursInAYear(_Year);
	}

	static int NumberOfMinutesInAYear(short Year)
	{
		return NumberOfHoursInAYear(Year) * 60;
	}
	int NumberOfMinutesInAYear()
	{
		return NumberOfMinutesInAYear(_Year);
	}

	static int NumberOfSecondsInAYear(short Year)
	{
		return NumberOfMinutesInAYear(Year) * 60;
	}
	int NumberOfSecondsInAYear()
	{
		return NumberOfMinutesInAYear(_Year);
	}



	static short NumberOfDaysInAMonth(short Month, short Year)
	{
		if (Month < 1 || Month>12)
			return 0;
		int NumberOfDays[12] = { 31,28,31,30,31,30,31,31,30,31,30,31
		};
		return (Month == 2) ? (isLeapYear(Year) ? 29 : 28) :
			NumberOfDays[Month - 1];
	}
	short NumberOfDaysInAMonth()
	{
		return NumberOfDaysInAMonth(_Month, _Year);
	}

	static short NumberOfHoursInAMonth(short Month, short Year)
	{
		return NumberOfDaysInAMonth(Month, Year) * 24;
	}
	short NumberOfHoursInAMonth()
	{
		return NumberOfHoursInAMonth(_Month, _Year);
	}

	static int NumberOfMinutesInAMonth(short Month, short Year)
	{
		return NumberOfHoursInAMonth(Month, Year) * 60;
	}
	int NumberOfMinutesInAMonth()
	{
		return NumberOfMinutesInAMonth(_Month, _Year);
	}

	static int NumberOfSecondsInAMonth(short Month, short Year)
	{
		return NumberOfMinutesInAMonth(Month, Year) * 60;
	}
	int NumberOfSecondsInAMonth()
	{
		return NumberOfSecondsInAMonth(_Month, _Year);
	}

	static short DayOfWeekOrder(short Day, short Month, short Year)
	{
		short a, y, m;
		a = (14 - Month) / 12;
		y = Year - a;
		m = Month + (12 * a) - 2;
		// Gregorian:
		//0:sun, 1:Mon, 2:Tue...etc
		return (Day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m)
			/ 12)) % 7;
	}
	short DayOfWeekOrder() {
		return DayOfWeekOrder(_Day, _Month, _Year);
	}

	static string DayShortName(short DayOfWeekOrder)
	{
		string arrDayNames[] = {
		"Sun","Mon","Tue","Wed","Thu","Fri","Sat" };
		return arrDayNames[DayOfWeekOrder];
	}

	string DayShortName() {
		return DayShortName(_DayWeekOrder);
	}

	static string MonthShortName(short MonthNumber)
	{
		string Months[12] = { "Jan", "Feb", "Mar",
		"Apr", "May", "Jun",
		"Jul", "Aug", "Sep",
		"Oct", "Nov", "Dec"
		};
		return (Months[MonthNumber - 1]);
	}

	string MonthShortName() {
		return MonthShortName(_Month);
	}

	static void PrintMonthCalendar(short Month, short Year)
	{
		int NumberOfDays;
		int current = DayOfWeekOrder(1, Month, Year);
		NumberOfDays = NumberOfDaysInAMonth(Month, Year);

		printf("\n _______________%s_________________\n\n",
			MonthShortName(Month).c_str());

		printf("  Sun Mon Tue Wed Thu Fri Sat\n");

		int i;
		for (i = 0; i < current; i++)
			printf("  ");
		for (int j = 1; j <= NumberOfDays; j++)
		{
			printf("%5d", j);
			if (++i == 7)
			{
				i = 0;
				printf("\n");
			}
		}
		printf("\n ___________________________________\n");
	}

	void PrintMonthCalendar() {
		PrintMonthCalendar(_Month, _Year);
	}

	static void PrintYearCalendar(int Year)
	{
		printf("\n _________________________________\n\n");
		printf(" Calendar - %d\n", Year);
		printf(" _________________________________\n");
		for (int i = 1; i <= 12; i++)
		{
			PrintMonthCalendar(i, Year);
		}
		return;
	}
	void PrintYearCalendar() {
		PrintYearCalendar(_Year);
	}


	static short NumberOfDaysFromTheBeginingOfTheYear(short Day, short Month, short Year)
	{
		short TotalDays = 0;
		for (int i = 1; i <= Month - 1; i++)
		{
			TotalDays += NumberOfDaysInAMonth(i, Year);
		}
		TotalDays += Day;
		return TotalDays;
	}

	short NumberOfDaysFromTheBeginingOfTheYear() {
		return NumberOfDaysFromTheBeginingOfTheYear(_Day, _Month, _Year);
	}


	static clsDate GetDateFromDayOrderInYear(short DayOrderInYear, short Year)
	{
		clsDate Date;
		short RemainingDays = DayOrderInYear;
		short MonthDays = 0;
		Date.Year = Year;
		Date.Month = 1;
		while (true)
		{
			MonthDays = NumberOfDaysInAMonth(Date.Month, Year);
			if (RemainingDays > MonthDays)
			{
				RemainingDays -= MonthDays;
				Date.Month++;
			}
			else
			{
				Date.Day = RemainingDays;
				break;
			}
		}
		return Date;
	}

	clsDate GetDateFromDayOrderInYear() {
		return GetDateFromDayOrderInYear(_DayOrderInYear, _Year);
	}




	static clsDate DateAddDays(short Days, clsDate Date)
	{
		short RemainingDays = Days +
			NumberOfDaysFromTheBeginingOfTheYear(Date.Day, Date.Month,
				Date.Year);
		short MonthDays = 0;
		Date.Month = 1;
		while (true)
		{
			MonthDays = NumberOfDaysInAMonth(Date.Month, Date.Year);
			if (RemainingDays > MonthDays)
			{
				RemainingDays -= MonthDays;
				Date.Month++;
				if (Date.Month > 12)
				{
					Date.Month = 1;
					Date.Year++;
				}
			}
			else
			{
				Date.Day = RemainingDays;
				break;
			}
		}
		return Date;
	}
	void DateAddDays() {
		*this = DateAddDays(_AddDaysToDate, *this);
	}

	static bool IsLastDayInMonth(clsDate Date) {
		return (Date.Day == NumberOfDaysInAMonth(Date.Month, Date.Year));
	}
	bool IsLastDayInMonth() {
		return IsLastDayInMonth(*this);
	}

	static bool IsLastMonthInYear(short Month) {
		return (Month == 12);
	}

	bool IsLastMonthInYear() {
		return IsLastMonthInYear(Month);
	}
	static clsDate GetSystemDate()
	{
		clsDate Date;
		time_t t = time(0);
		tm* now = localtime(&t);
		Date._Year = now->tm_year + 1900;
		Date._Month = now->tm_mon + 1;
		Date._Day = now->tm_mday;

		return Date;
	}

	static bool isLeapYear(short Year)
	{
		return (Year % 4 == 0 && Year % 100 != 0) || (Year % 400 == 0);
	}

	bool isLeapYear()
	{
		return isLeapYear(_Year);
	}

	static bool IsDate1BeforeDate2(clsDate Date1, clsDate Date2)
	{
		return (Date1.Year < Date2.Year) ? true : ((Date1.Year ==
			Date2.Year) ? (Date1.Month < Date2.Month ? true : (Date1.Month ==
				Date2.Month ? Date1.Day < Date2.Day : false)) : false);
	}
	bool IsDateBeforeDate2(clsDate Date2)
	{
		return IsDate1BeforeDate2(*this, Date2);
	}

	static bool IsDate1EqualDate2(clsDate Date1, clsDate Date2)
	{
		return (Date1.Year == Date2.Year) ? ((Date1.Month ==
			Date2.Month) ? ((Date1.Day == Date2.Day) ? true : false) : false)
			: false;
	}
	bool IsDateEqualDate2(clsDate Date2)
	{
		return IsDate1EqualDate2(*this, Date2);

	}

	static bool IsDateAfterDate2(clsDate Date1, clsDate Date2)
	{
		return (!IsDate1BeforeDate2(Date1, Date2) &&
			!IsDate1EqualDate2(Date1, Date2));
	}
	bool IsDateAfterDate2(clsDate Date2)
	{
		return (!IsDate1BeforeDate2(*this, Date2) &&
			!IsDate1EqualDate2(*this, Date2));
	}



	//Incress Date ↓↓ : 

	static clsDate IncressDateByOneDay(clsDate Date) {
		if (IsLastDayInMonth(Date)) {
			if (IsLastMonthInYear(Date.Month)) {
				Date.Day = 1;
				Date.Month = 1;
				Date.Year++;
			}
			else {
				Date.Day = 1;
				Date.Month++;
			}

		}
		else {
			Date.Day++;
		}
		return Date;
	}
	void IncressDateByOneDay() {
		*this = IncressDateByOneDay(*this);
	}


	static clsDate IncressDateByXDays(short Days, clsDate date) {
		for (short x = 1; x <= Days; x++)
			date = IncressDateByOneDay(date);
		return date;
	}

	void IncressDateByXDays(short Days) {
		*this = IncressDateByXDays(Days, *this);
	}


	static clsDate IncressDateBy1week(clsDate date) {
		for (short x = 1; x <= 7; x++)
			date = IncressDateByOneDay(date);
		return date;
	}
	void IncressDateBy1week() {
		*this = IncressDateBy1week(*this);
	}


	static clsDate IncressDateByXweeks(short Weeks, clsDate date) {
		for (short x = 1; x <= Weeks; x++)
			date = IncressDateBy1week(date);
		return date;
	}
	void IncressDateByXweeks(short Weeks) {
		*this = IncressDateByXweeks(Weeks, *this);
	}


	static clsDate IncressDateBy1Month(clsDate date) {

		if (date.Month == 12) {
			date.Month = 1;
			date.Year++;
		}
		else {
			date.Month++;
		}
		short DaysInCurrentMonth = NumberOfDaysInAMonth(date.Month, date.Year);
		if (date.Day > DaysInCurrentMonth) {
			date.Day = DaysInCurrentMonth;
		}
		return date;
	}


	void IncressDateBy1Month() {
		*this = IncressDateBy1Month(*this);
	}

	static clsDate IncressDateByXMonths(short month, clsDate& date) {
		for (short x = 1; x <= month; x++)
			date = IncressDateBy1Month(date);
		return date;
	}

	void IncressDateByXMonths(short month) {
		*this = IncressDateByXMonths(month, *this);
	}

	static clsDate FixFeb29(clsDate& Date) {
		if (Date.Month == 2 && Date.Day == 29 && !isLeapYear(Date.Year)) {
			Date.Day = 28;
		}
		return Date;
	}
	void FixFeb29() {
		*this = FixFeb29(*this);
	}

	static clsDate IncressDateBy1Year(clsDate& date) {
		date.Year++;
		FixFeb29(date);
		return date;
	}
	void IncressDateBy1Year() {
		*this = IncressDateBy1Year(*this);
	}

	static clsDate IncressDateByXYear(short years, clsDate date) {
		for (short x = 1; x <= years; x++)
			date = IncressDateBy1Year(date);
		return date;
	}
	void IncressDateByXYear(short years) {
		*this = IncressDateByXYear(years, *this);
	}

	static clsDate IncressDateByXYearsFaster(short Years, clsDate date) {
		date.Year += Years;
		FixFeb29(date);
		return date;
	}
	void  IncressDateByXYearsFaster(short Years) {
		*this = IncressDateByXYearsFaster(Years, *this);
	}

	static clsDate IncressDateBy1Decade(clsDate date) {
		date.Year += 10;
		FixFeb29(date);
		return date;
	}
	void IncressDateBy1Decade() {
		*this = IncressDateBy1Decade(*this);
	}

	static clsDate IncressDateByXDecades(short Years, clsDate date) {
		for (short x = 1; x <= Years * 10; x++)
			date = IncressDateBy1Year(date);
		return date;
	}
	void IncressDateByXDecades(short Years) {
		*this = IncressDateByXDecades(Years, *this);
	}

	static clsDate IncressDateByXDecadesFaster(short Years, clsDate date) {
		date.Year += Years * 10;
		FixFeb29(date);
		return date;
	}
	void IncressDateByXDecadesFaster(short Years) {
		*this = IncressDateByXDecadesFaster(Years, *this);
	}

	static clsDate IncressDateBy1Century(clsDate date) {
		date.Year += 100;
		FixFeb29(date);
		return date;
	}

	void IncressDateBy1Century() {
		*this = IncressDateBy1Century(*this);
	}

	static clsDate IncressDateBy1Millennuim(clsDate date) {

		date.Year += 1000;
		FixFeb29(date);
		return date;
	}
	void  IncressDateBy1Millennuim() {
		*this = IncressDateBy1Millennuim(*this);
	}

	//

	//Decress Date ↓↓ : 

	static bool IsFirstDayInMonth(clsDate Date) {
		return  Date.Day == 1;
	}
	bool IsFirstDayInMonth() {
		return IsFirstDayInMonth(*this);
	}

	static bool IsFirstMonthInYear(short Month) {
		return (Month == 1);
	}
	bool IsFirstMonthInYear() {
		return IsFirstMonthInYear(Month);
	}

	static clsDate DecressDateByOneDay(clsDate Date) {
		if (IsFirstDayInMonth(Date)) {
			if (IsFirstMonthInYear(Date.Month)) {
				Date.Month = 12;
				Date.Day = 31;
				--Date.Year;
			}
			else {
				Date.Month--;
				Date.Day = NumberOfDaysInAMonth(Date.Month, Date.Year);
			}
		}
		else {
			Date.Day -= 1;
		}
		FixFeb29(Date);
		return Date;
	}
	void DecressDateByOneDay() {
		*this = DecressDateByOneDay(*this);
	}


	static clsDate  DecressByXDays(short Days, clsDate date) {
		for (short x = 1; x <= Days; x++)
			date = DecressDateByOneDay(date);
		FixFeb29(date);
		return date;
	}

	void DecressByXDays(short Days) {
		*this = DecressByXDays(Days, *this);
	}

	static clsDate DecressDateBy1week(clsDate date) {
		for (short x = 1; x <= 7; x++)
			date = DecressDateByOneDay(date);
		FixFeb29(date);
		return date;
	}


	void DecressDateBy1week() {
		*this = DecressDateBy1week(*this);
	}

	static clsDate DecressDateByXweeks(short Weeks, clsDate date) {
		for (short x = 1; x <= Weeks; x++)
			date = DecressDateBy1week(date);
		FixFeb29(date);
		return date;
	}

	void DecressDateByXweeks(short Weeks) {
		*this = DecressDateByXweeks(Weeks, *this);
	}

	static clsDate DecressDateBy1Month(clsDate date) {

		if (date.Month == 1) {
			date.Month = 12;
			date.Year--;
		}
		else {
			date.Month--;
		}
		short DaysInCurrentMonth = NumberOfDaysInAMonth(date.Month, date.Year);
		if (date.Day > DaysInCurrentMonth) {
			date.Day = DaysInCurrentMonth;
		}
		FixFeb29(date);
		return date;
	}

	void DecressDateBy1Month() {
		*this = DecressDateBy1Month(*this);
	}

	static clsDate DecressDateByXMonths(short month, clsDate date) {
		for (short x = 1; x <= month; x++)
			date = DecressDateBy1Month(date);
		FixFeb29(date);
		return date;
	}
	void DecressDateByXMonths(short month) {
		*this = DecressDateByXMonths(month, *this);
	}

	static clsDate DecressDateBy1Year(clsDate date) {
		date.Year--;
		FixFeb29(date);
		return date;
	}
	void DecressDateBy1Year() {
		*this = DecressDateBy1Year(*this);
	}

	static clsDate DecressDateByXYear(short years, clsDate date) {
		for (short x = 1; x <= years; x++)
			date = DecressDateBy1Year(date);
		FixFeb29(date);
		return date;
	}
	void DecressDateByXYear(short years) {
		*this = DecressDateByXYear(years, *this);
	}


	static clsDate DecressDateByXYearsFaster(short Years, clsDate date) {
		date.Year -= Years;
		FixFeb29(date);
		return date;
	}
	void DecressDateByXYearsFaster(short Years) {
		*this = DecressDateByXYearsFaster(Years, *this);
	}

	static clsDate DecressDateBy1Decade(clsDate date) {
		date.Year -= 10;
		FixFeb29(date);
		return date;
	}
	void DecressDateBy1Decade() {
		*this = DecressDateBy1Decade(*this);
	}

	static clsDate DecressDateByXDecades(short Years, clsDate date) {
		for (short x = 1; x <= Years * 10; x++)
			date = DecressDateBy1Year(date);
		FixFeb29(date);
		return date;
	}

	void DecressDateByXDecades(short Years) {
		*this = DecressDateByXDecades(Years, *this);
	}

	static clsDate DecressDateByXDecadesFaster(short Years, clsDate date) {
		date.Year -= Years * 10;
		FixFeb29(date);
		return date;
	}

	void DecressDateByXDecadesFaster(short Years) {
		*this = DecressDateByXDecadesFaster(Years, *this);
	}

	static clsDate DecressDateBy1Century(clsDate date) {
		date.Year -= 100;
		FixFeb29(date);
		return date;
	}

	void DecressDateBy1Century() {
		*this = DecressDateBy1Century(*this);
	}



	static clsDate DecressDateBy1Millennuim(clsDate date) {

		date.Year -= 1000;
		FixFeb29(date);
		return date;
	}

	void DecressDateBy1Millennuim() {
		*this = DecressDateBy1Millennuim(*this);
	}


	//



	static bool IsEndOfWeek(clsDate date) {
		return (DayOfWeekOrder(date.Day, date.Month, date.Year) == 6);
	}

	bool IsEndOfWeek() {
		return  IsEndOfWeek(*this);

	}

	static bool IsWeekEnd(clsDate date) {

		short IndexDay = DayOfWeekOrder(date.Day, date.Month, date.Year);
		return (IndexDay == 6 || IndexDay == 5);
	}

	bool IsWeekEnd() {
		return  IsWeekEnd(*this);

	}


	static bool IsBusinessDay(clsDate date) {
		return !IsWeekEnd(date);
	}

	bool IsBusinessDay() {
		return IsBusinessDay(*this);
	}

	static short DaysUntillEndOfWeek(clsDate date) {
		return (6 - DayOfWeekOrder(date.Day, date.Month, date.Year));

	}

	short DaysUntillEndOfWeek() {
		return DaysUntillEndOfWeek(*this);
	}

	static int GetDifferenceInDays(clsDate Date1, clsDate Date2, bool
		IncludeEndDay = false)
	{
		int Days = 0;
		while (IsDate1BeforeDate2(Date1, Date2))
		{
			Days++;
			Date1 = IncressDateByOneDay(Date1);
		}
		return IncludeEndDay ? ++Days : Days;
	}

	int GetDifferenceInDays(clsDate Date2, bool IncludeEndDay = false) {
		return GetDifferenceInDays(*this, Date2, IncludeEndDay);
	}



	static short DaysUntilTheEndOfMonth(clsDate Date1)
	{
		clsDate EndOfMontDate;
		EndOfMontDate.Day = NumberOfDaysInAMonth(Date1.Month, Date1.Year);
		EndOfMontDate.Month = Date1.Month;
		EndOfMontDate.Year = Date1.Year;
		return GetDifferenceInDays(Date1, EndOfMontDate, true);
	}

	short DaysUntilTheEndOfMonth() {
		return DaysUntilTheEndOfMonth(*this);
	}


	static short DaysUntilTheEndOfYear(clsDate Date1)
	{
		clsDate EndOfYearDate;
		EndOfYearDate.Day = 31;
		EndOfYearDate.Month = 12;
		EndOfYearDate.Year = Date1.Year;
		return GetDifferenceInDays(Date1, EndOfYearDate, true);
	}

	short DaysUntilTheEndOfYear() {
		return  DaysUntilTheEndOfYear(*this);
	}



	static short CalaculateVacationDays(clsDate Datefrom, clsDate Dateto) {
		return CalaculateBusinessDays(Datefrom, Dateto);
	}

	short CalaculateVacationDays(clsDate Dateto) {
		return CalaculateVacationDays(*this, Dateto);
	}

	static short CalaculateBusinessDays(clsDate Datefrom, clsDate Dateto) {
		short BusinessDays = 0;
		while (IsDate1BeforeDate2(Datefrom, Dateto)) {
			if (IsBusinessDay(Datefrom))
				BusinessDays++;
			Datefrom = IncressDateByOneDay(Datefrom);
		}
		return BusinessDays;
	}

	short CalaculateBusinessDays(clsDate Dateto) {
		return CalaculateBusinessDays(*this, Dateto);
	}

	static clsDate CalaculateVacationReturnDate(clsDate date,short VacationDays) {
		short WeekEnd = 0;
		while (IsWeekEnd(date)) {
			date = IncressDateByOneDay(date);
		}

		for (short x = 0; x < VacationDays + WeekEnd; x++) {
			if (IsWeekEnd(date))
				WeekEnd++;
			date = IncressDateByOneDay(date);
		}
		if (IsWeekEnd(date)) {
			date = IncressDateByOneDay(date);
		}

		return date;

	}


	clsDate CalaculateVacationReturnDate( short VacationDays) {
		return CalaculateVacationReturnDate(*this,VacationDays);
	}

	//.....


	static bool IsValidDay(clsDate date) {
		short NumberOfDays = date.Day;
		return (NumberOfDays>0&&NumberOfDays<=NumberOfDaysInAMonth(date.Month,date.Year));
	}
	bool IsValidDay() {
		return IsValidDay(*this);
	}

	static bool IsValidMonth(clsDate date) {
		short month = date.Month;
		return (month > 0 && month <= 12);
	}
	bool IsValidMonth() {
		return IsValidMonth(*this);
	}


	static bool IsValidDate(clsDate date) {
		return (IsValidMonth(date) && IsValidDay(date) && date.Year> 0);
	}
	bool IsValidDate() {
		return IsValidDate(*this);
	}


	enum enDateCompare { Before = -1, Equal = 0,After=1 };

	static enDateCompare CompareDates(clsDate date1, clsDate date2) {

		if (IsDate1BeforeDate2(date1, date2)) {
			return enDateCompare::Before;
		}
		if (IsDate1EqualDate2(date1, date2)) {
			return enDateCompare::Equal;
		}
		return enDateCompare::After;
	}

	enDateCompare CompareDates(clsDate date2) {
		return CompareDates(*this,date2);
	}


	static clsDate IsOverLap() {

	}





	static string DateToString(clsDate date) {
		return  to_string(date._Day) + "/" + to_string(date._Month) + "/" + to_string(date._Year);
	}

	string DateToString() {
		return DateToString(*this);
	}

	static string TimeToString(clsDate date) {
		return  to_string(date._Hours) + ":" + to_string(date._Minutes) + ":" + to_string(date._Seconds);
	}
		

	void Print() {
		cout <<DateToString()<< endl;
	}

	

	static bool IsOverlapPeriods(clsDate Period1start, clsDate Period1End, clsDate Period2start, clsDate Period2End )
	{
		if (
			CompareDates(Period2End , Period1start) ==
			enDateCompare::Before
			||
			CompareDates(Period2start, Period1End) ==
			enDateCompare::After
			)
			return false;
		else
			return true;
	}

	static short PeriodLength(clsDate Date1,clsDate Date2,bool IncludeLastDay=false) {
		return GetDifferenceInDays(Date1,Date2, IncludeLastDay);
	}

	short PeriodLength(clsDate Date) {
		return PeriodLength(*this,Date);
	}



	static bool IsDateInPeriod(clsDate Date1, clsDate Date2, clsDate DateToCheck) {
		return !(CompareDates(DateToCheck, Date1) == enDateCompare::Before || CompareDates(DateToCheck, Date2) == enDateCompare::After);
	}

	bool IsDateInPeriod(clsDate Date1, clsDate Date2) {
		return IsDateInPeriod(Date1,Date2,*this);
	}

	static short CountOverLapDays(clsDate Period1start, clsDate Period1End, clsDate Period2start, clsDate Period2End) {

		short Peroid1Length = PeriodLength(Period1start, Period1End,true);
		short Peroid2Length = PeriodLength(Period2start, Period2End, true);
		short OverLapDays = 0;
		if (!IsOverlapPeriods(Period1start, Period1End, Period2start, Period2End)) {
			return 0;
		}
		if (Peroid1Length < Peroid2Length) {
			while (IsDate1BeforeDate2(Period1start, Period1End)) {
				if (IsDateInPeriod(Period2start, Period2End, Period1start)) {
					OverLapDays++;
				}
				Period1start = IncressDateByOneDay(Period1start);
			}
		}
		else {
			while (IsDate1BeforeDate2(Period2start, Period2End)) {
				if (IsDateInPeriod(Period1start, Period1End, Period2start)) {
					OverLapDays++;
				}
				Period2start = IncressDateByOneDay(Period2start);
			}
		}
		return OverLapDays;
	}




	static clsDate ConvertStringToClassDate(string Text,string sperator= "/") {
		vector <string> vDate;
		clsDate Date;
		vDate = clsString::Split(Text, sperator);
		Date.Day = stoi(vDate[0]);
		Date.Month = stoi(vDate[1]);
		Date.Year = stoi(vDate[2]);
		return Date;
	}



	static string FormatDate(clsDate Date,string Format="dd/mm/yyyy") {
		string FormatingDate = "";
		FormatingDate = clsString::ReplaceWordInStringUsingBuildInFunction(Format, "dd", to_string(Date.Day));
		FormatingDate = clsString::ReplaceWordInStringUsingBuildInFunction(FormatingDate, "mm", to_string(Date.Month));
		FormatingDate = clsString::ReplaceWordInStringUsingBuildInFunction(FormatingDate, "yyyy", to_string(Date.Year));
		return FormatingDate;
	}



	static string GetSystemDateTimeString() {
		time_t t = time(0);
		tm* tim = localtime(&t);

		short Days, Months, Years, Hours, Minutes, Seconds;
		Years = tim->tm_year + 1900;
		Months = tim->tm_mon + 1;
		Days = tim->tm_mday;
		Hours = tim->tm_hour;
		Minutes = tim->tm_min;
		Seconds = tim->tm_sec;

		return (to_string(Days) + "/" + to_string(Months) + "/" + to_string(Years) + " - " +
			to_string(Hours) + ":" + to_string(Minutes) + ":" + to_string(Seconds)
			);



	}





};

