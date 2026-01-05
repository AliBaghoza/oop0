#pragma once
#pragma warning(disable : 4996)
#include <iostream>
#include<vector>
#include <ctime> 
#include<string>
#include"clsString.h"

using namespace std;

class clsDate
{
	
	short _Day, _Month, _Year;


public:

	clsDate(short Day, short Month, short Year) 
	{
		_Day = Day;
		_Month = Month;
		_Year = Year;
	}

	clsDate() 
	{
		*this = GetSystemDate();
	}
	clsDate(string DateString)
	{
		*this = StringToDate(DateString);
	}
	clsDate(short DateOrderInYear, short Year)
	{
		*this = GetDateFromDayOrderInYear(DateOrderInYear, Year);
	}

	void SetDay(short Day) { _Day = Day;}
	short GetDay() { return _Day; }
	__declspec(property(get = GetDay, put = SetDay)) short Day;

	void SetMonth(short Month) { _Month = Month; }
	short GetMonth() { return _Month; }
	__declspec(property(get = GetMonth, put = SetMonth)) short Month;

	void SetYear(short Year) { _Year = Year; }
	short GetYear() { return _Year; }
	__declspec(property(get = GetYear, put = SetYear)) short Year;

public:

	void Print()
	{
		cout << DateToString() << endl;
	}

	static bool IsLeapYear(short Year)
	{
		// if year is divisible by 4 AND not divisible by 100
		// OR if year is divisible by 400 
		// then it is a leap year 
		return (Year % 4 == 0 && Year % 100 != 0) ||
			(Year % 400 == 0);
	}
	bool IsLeapYear()   
	{
		return IsLeapYear(_Year);
	}
	static short ReadYear()
	{
		short Year = 0;

		cout << "\nPlease enter a year ? ";
		cin >> Year;

		return Year;
	}
	static short ReadMonth()
	{
		short Month = 0;

		cout << "\nPlease enter a Month ? ";
		cin >> Month;

		return Month;
	}
	static short ReadDay()
	{
		short Day = 0;

		cout << "\nPlease enter a Day ? ";
		cin >> Day;

		return Day;
	}
	static clsDate ReadFullDate()
	{
		short Day, Month, Year;

		Day = ReadDay();
		Month = ReadMonth();
		Year = ReadYear();

		return clsDate(Day, Month, Year);
	}
	static clsDate GetSystemDate()
	{
		short Day, Month, Year;

		time_t t = time(0);
		tm* now = localtime(&t);
		
		Year = now->tm_year + 1900;
		Month = now->tm_mon + 1;
		Day = now->tm_mday;

		return clsDate(Day, Month, Year);
	}

	//  Number of Days – Hours – Minutes – Seconds in a Year
	static short NumberOfDaysInAYear(short Year)
	{
		return IsLeapYear(Year) ? 366 : 365;
	}
	short NumberOfDaysInAYear()
	{
		return NumberOfDaysInAYear(Year);
	}
	static short NumberOfDaysInAYear(clsDate Date)
	{
		return IsLeapYear(Date.Year) ? 366 : 365;
	}
	static short NumberOfHoursInAYear(short Year)
	{
		return NumberOfDaysInAYear(Year) * 24;
	}
	short NumberOfHoursInAYear()
	{
		return NumberOfHoursInAYear(Year);
	}
	static int NumberOfMinutesInAYear(short Year)
	{
		return NumberOfHoursInAYear(Year) * 60;
	}
	short NumberOfMinutesInAYear()
	{
		return NumberOfMinutesInAYear(Year);
	}
	static int NumberOfSecondsInAYear(short Year)
	{
		return NumberOfMinutesInAYear(Year) * 60;
	}
	short NumberOfSecondsInAYear()
	{
		return NumberOfSecondsInAYear(Year);
	}

	//  Number of Days – Hours – Minutes – Seconds in a Month
	static short NumberOfDaysInAMonth(short Month, short Year)
	{
		if (Month < 1 || Month > 12)
			return  0;

		int NumberOfDays[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };

		return (Month == 2) ? (IsLeapYear(Year) ? 29 : 28) : NumberOfDays[Month - 1];

	}
	short NumberOfDaysInAMonth()
	{
		return NumberOfDaysInAMonth(Month,Year);
	}
	static short NumberOfDaysInAMonth(clsDate Date)
	{
		if (Date.Month < 1 || Date.Month > 12)
			return  0;

		int NumberOfDays[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };

		return (Date.Month == 2) ? (IsLeapYear(Date.Year) ? 29 : 28) : NumberOfDays[Date.Month - 1];

	}
	static short NumberOfHoursInAMonth(short Month, short Year)
	{
		return NumberOfDaysInAMonth(Month, Year) *
			24;
	}
	short NumberOfHoursInAMonth()
	{
		return NumberOfHoursInAMonth(Month, Year);
	}
	static int NumberOfMinutesInAMonth(short Month, short Year)
	{
		return NumberOfHoursInAMonth(Month, Year) *
			60;
	}
	short NumberOfMinutesInAMonth()
	{
		return NumberOfMinutesInAMonth(Month, Year);
	}
	static int NumberOfSecondsInAMonth(short Month, short Year)
	{
		return NumberOfMinutesInAMonth(Month, Year)
			* 60;
	}
	short NumberOfSecondsInAMonth()
	{
		return NumberOfSecondsInAMonth(Month, Year);
	}
	
	// Day Name #7
	static short DayOfWeekOrder(short Day, short Month, short Year)
	{
		short a, y, m;

		a = (14 - Month) / 12;
		y = Year - a;
		m = Month + (12 * a) - 2;

		// Gregorian: 
		//0:sun, 1:Mon, 2:Tue...etc.  
		return (Day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;
	}
	static short DayOfWeekOrder(clsDate Date)
	{
		short a, y, m;

		a = (14 - Date.Month) / 12;
		y = Date.Year - a;
		m = Date.Month + (12 * a) - 2;

		// Gregorian: 
		//0:sun, 1:Mon, 2:Tue...etc.  
		return (Date.Day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;
	}
	short DayOfWeekOrder()
	{
		return DayOfWeekOrder(*this);
	}
	static string DayShortName(short DayOfWeekOrder)
	{
		string arrDayNames[7] = { "Sun","Mon","Tue","Wed","Thu","Fri","Sat" };
		return arrDayNames[DayOfWeekOrder];
	}
	string DayShortName()
	{
		return DayShortName(DayOfWeekOrder());
	}
	
	// Month Name
	static string MonthShortName(short MonthNumber)
	{
		string Months[12] =
		{
		 "Jan", "Feb", "Mar",
		 "Apr", "May", "Jun",
		 "Jul", "Aug", "Sep",
		 "Oct", "Nov", "Dec"
		};
		return (Months[MonthNumber - 1]);
	}
	string MonthShortName()
	{
		return MonthShortName(Month);
	}

	// Month Calendar #8
	static void PrintMonthCalendar(short Month, short Year)
	{
		int NumberOfDays;

		// Index of the day from 0 to 6 
		int current = DayOfWeekOrder(1, Month, Year);

		NumberOfDays = NumberOfDaysInAMonth(Month, Year);

		// Print the current month name 
		printf("\n _______________%s__________________\n\n",
			MonthShortName(Month).c_str());

		// Print the columns 
		printf("  Sun  Mon  Tue  Wed  Thu  Fri  Sat\n");

		// Print appropriate spaces 
		int i;
		for (i = 0; i < current; i++)
			printf("     ");

		for (int j = 1; j <= NumberOfDays; j++)
		{
			printf("%5d", j); //display 5 space befor "j"

			if (++i == 7)
			{
				i = 0;
				printf("\n");
			}
		}
		printf("\n ____________________________________\n");
	}
	void PrintMonthCalendar()
	{
		PrintMonthCalendar(Month, Year);
	}
	
	// Year Calendar  #9
	static void PrintYearCalendar(short Year)
	{
		printf("\n  _________________________________\n\n");
		printf("           Calendar - %d\n", Year);
		printf("  _________________________________\n");

		for (short i = 1; i <= 12; i++)
		{
			PrintMonthCalendar(i, Year);
		}
	}
	void PrintYearCalendar()
	{
		PrintYearCalendar(Year);
	}
	
	// Days from the beginning of Year  #10
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
	static short NumberOfDaysFromTheBeginingOfTheYear(clsDate Date)
	{
		short TotalDays = 0;

		for (int i = 1; i <= Date.Month - 1; i++)
		{
			TotalDays += NumberOfDaysInAMonth(i, Date.Year);
		}
		TotalDays += Date.Day;

		return TotalDays;
	}
	short NumberOfDaysFromTheBeginingOfTheYear()
	{
		return NumberOfDaysFromTheBeginingOfTheYear(*this);
	}
	// Date from Day Order In a Year (Date for [225] is: 13/8/2023)
	static clsDate GetDateFromDayOrderInYear(short DateOrderInYear, short Year)
	{
		short Day, Month, year;

		short RemainingDays = DateOrderInYear;
		short MonthDays = 0;
		year = Year;

		Month = 1;

		while (true)
		{
			MonthDays = NumberOfDaysInAMonth(Month, Year);

			if (RemainingDays > MonthDays)
			{
				RemainingDays -= MonthDays;
				Month++;
			}
			else
			{
				Day = RemainingDays;
				break;
			}
		}
		return clsDate(Day, Month, year);
	}
	
	//   Add Days to Date
	static clsDate AddDays(short Days, clsDate Date)
	{
		short RemainingDays = Days +
			NumberOfDaysFromTheBeginingOfTheYear(Date.Day, Date.Month, Date.Year);
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
	void AddDays(short Days)
	{
		*this = AddDays(Days, *this);
	}
	
	//  Date1 Less Than Date2// Date1 Equals To Date2 ======================================================
	static bool IsDate1BeforeDate2(clsDate Date1, clsDate Date2)
	{
		return  (Date1.Year < Date2.Year) ? true : ((Date1.Year == Date2.Year) ? (Date1.Month < Date2.Month ? true : (Date1.Month == Date2.Month ? Date1.Day < Date2.Day : false)) : false);
	}
	bool IsDate1BeforeDate2(clsDate Date2)
	{
		return IsDate1BeforeDate2(*this, Date2);
	}
	static bool IsDate1EqualDate2(clsDate Date1, clsDate Date2)
	{
		return (Date1.Year == Date2.Year) ? ((
			Date1.Month == Date2.Month) ? ((Date1.Day ==
				Date2.Day) ? true : false) : false) : false;
	}
	bool IsDate1EqualDate2(clsDate Date2)
	{
		return IsDate1EqualDate2(*this, Date2);
	}
	
	//Last Day, Last Month
	static bool IsLastDayInMonth(clsDate Date)
	{
		return (Date.Day == NumberOfDaysInAMonth(Date.Month, Date.Year));
	}
	bool IsLastDayInMonth()
	{
		return IsLastDayInMonth(*this);
	}

	static bool IsLastMonthInYear(short Month)
	{
		return (Month == 12);
	}
	bool IsLastMonthInYear()
	{
		return IsLastMonthInYear(Month);
	}
	
	// Increase Date By One Day  #16
	static clsDate AddOneDay(clsDate Date)
	{
		if (IsLastDayInMonth(Date))
		{
			if (IsLastMonthInYear(Date.Month))
			{
				Date.Month = 1;
				Date.Day = 1;
				Date.Year++;
			}
			else
			{
				Date.Day = 1;
				Date.Month++;
			}
		}
		else
		{
			Date.Day++;
		}
		return Date;
	}
	void AddOneDay()
	{
		*this = AddOneDay(*this);
	}

	//#Problem 18 : Your Age In Days
	static int CalculateMyAgeInDays(clsDate DateOfBirth)
	{
		return GetDifferenceInDays(DateOfBirth, GetSystemDate() , true);
	}
  
	//Diff In Days (Negative Days)  #17 and #19
	static void SwapDates(clsDate& Date1, clsDate& Date2)
	{
		clsDate TempDate;

		TempDate = Date1;

		Date1 = Date2;

		Date2 = TempDate;
	}
	void SwapDates(clsDate& Date2)
	{
		SwapDates(*this, Date2);
	}
	static int GetDifferenceInDays(clsDate Date1, clsDate Date2, bool IncludeEndDay = false)
	{
		int Days = 0;
		short SwapFlagValue = 1;

		if (!IsDate1BeforeDate2(Date1, Date2))
		{
			SwapDates(Date1, Date2);
			SwapFlagValue = -1;
		}

		while (IsDate1BeforeDate2(Date1, Date2))
		{
			Days++;
			Date1 = AddOneDay(Date1);
		}
		return IncludeEndDay ? ++Days * SwapFlagValue : Days * SwapFlagValue;
	}
	int GetDifferenceInDays(clsDate Date2, bool IncludeEndDay = false)
	{
		return GetDifferenceInDays(*this , Date2 , IncludeEndDay);
	}
    
	// Increase Date Problems #20-32
	static clsDate IncreaseDateByXDays(short Days, clsDate Date)
	{
		for (short i = 1; i <= Days; i++)
		{
			Date = AddOneDay(Date);
		}
		return Date;
	}
	void IncreaseDateByXDays(short Days)
	{
		IncreaseDateByXDays(Days, *this);
	}
	
	static clsDate IncreaseDateByOneWeek(clsDate Date)
	{
		for (int i = 1; i <= 7; i++)
		{
			Date = AddOneDay(Date);
		}
		return Date;
	}
	void IncreaseDateByOneWeek() 
	{
		IncreaseDateByOneWeek(*this);
	}
	static clsDate IncreaseDateByXWeeks(short Weeks, clsDate Date)
	{
		for (short i = 1; i <= Weeks; i++)
		{
			Date = IncreaseDateByOneWeek(Date);
		}
		return Date;
	}
	void IncreaseDateByXWeeks(short Weeks)
	{
		IncreaseDateByXWeeks(Weeks, *this);
	}
	
	static clsDate IncreaseDateByOneMonth(clsDate Date)
	{
		if (Date.Month == 12)
		{		 
			Date.Month = 1;
			Date.Year++;
		}
		else
		{
			Date.Month++;
		}
		//last check day in date should not exceed max days in the current month 
	   // example if date is 31/1/2022 increasing one month should not be 31 / 2 / 2022, it should
			// be 28/2/2022 
		short NumberOfDaysInCurrentMonth = NumberOfDaysInAMonth(Date.Month, Date.Year);

		if (Date.Day > NumberOfDaysInCurrentMonth)
		{
			Date.Day = NumberOfDaysInCurrentMonth;
		}
		return Date;
	}
	void IncreaseDateByOneMonth()
	{
		IncreaseDateByOneMonth(*this);
	}
	static clsDate IncreaseDateByXMonths(short Months, clsDate Date)
	{
		for (short i = 1; i <= Months; i++)
		{
			Date = IncreaseDateByOneMonth(Date);
		}
		return Date;
	}
	void IncreaseDateByXMonths(short Months)
	{
		IncreaseDateByXMonths(Months, *this);
	}
	
	static clsDate IncreaseDateByOneYear(clsDate Date)
	{
		Date.Year++;
		return Date;
	}
	void IncreaseDateByOneYear()
	{
		IncreaseDateByOneYear(*this);
	}
	static clsDate IncreaseDateByXYears(short Years, clsDate Date)
	{
		for (short i = 1; i <= Years; i++)
		{
			Date = IncreaseDateByOneYear(Date);
		}
		return Date;
	}
	void IncreaseDateByXYears(short Years)
	{
		IncreaseDateByXYears(Years, *this);
	}
	static clsDate IncreaseDateByXYearsFaster(short Years, clsDate Date)
	{
		Date.Year += Years;
		return Date;
	}
	void IncreaseDateByXYearsFaster(short Years)
	{
		IncreaseDateByXYearsFaster(Years, *this);
	}
	
	static clsDate IncreaseDateByOneDecade(clsDate Date)
	{
		//Period of 10 years 
		Date.Year += 10;
		return Date;
	}
	void IncreaseDateByOneDecade()
	{
		IncreaseDateByOneDecade(*this);
	}
	static clsDate IncreaseDateByXDecades(short Decade, clsDate Date)
	{
		for (short i = 1; i <= Decade * 10; i++)
		{
			Date = IncreaseDateByOneYear(Date);
		}
		return Date;
	}
	void IncreaseDateByXDecades(short Decade)
	{
		IncreaseDateByXDecades(Decade, *this);
	}
	static clsDate IncreaseDateByXDecadesFaster(short Decade, clsDate Date)
	{
		Date.Year += Decade * 10;
		return Date;
	}
	void IncreaseDateByXDecadesFaster(short Decade)
	{
		IncreaseDateByXDecadesFaster(Decade, *this);
	}
	
	static clsDate IncreaseDateByOneCentury(clsDate Date)
	{
		//Period of 100 years 
		Date.Year += 100;
		return Date;
	}
	void IncreaseDateByOneCentury()
	{
		IncreaseDateByOneCentury(*this);
	}
	
	static clsDate IncreaseDateByOneMillennium(clsDate Date)
	{
		//Period of 1000 years 
		Date.Year += 1000;
		return Date;
	}
	void IncreaseDateByOneMillennium()
	{
		IncreaseDateByOneMillennium(*this);
	}
	//***************************

	//Decrease Date Problems  33 to 46
	static clsDate DecreaseDateByOneDay(clsDate Date)
	{
		if (Date.Day == 1)
		{
			if (Date.Month == 1)
			{
				Date.Month = 12;
				Date.Year--;
				Date.Day = NumberOfDaysInAMonth(Date.Month, Date.Year);
			}
			else
			{
				Date.Month--;
				Date.Day = NumberOfDaysInAMonth(Date.Month, Date.Year);;
			}
		}
		else
		{
			Date.Day--;
		}
		return Date;
	}
	void DecreaseDateByOneDay()
	{
		DecreaseDateByOneDay(*this);
	}
	static clsDate DecreaseDateByXDays(short Days, clsDate Date)
	{
		for (short i = 1; i <= Days; i++)
		{
			Date = DecreaseDateByOneDay(Date);
		}
		return Date;
	}
	void DecreaseDateByXDays(short Days)
	{
		DecreaseDateByXDays(Days ,*this);
	}
	static clsDate DecreaseDateByOneWeek(clsDate Date)
	{
		for (int i = 1; i <= 7; i++)
		{
			Date = DecreaseDateByOneDay(Date);
		}
		return Date;
	}
	void DecreaseDateByOneWeek()
	{
		DecreaseDateByOneWeek(*this);
	}
	static clsDate DecreaseDateByXWeeks(short Weeks, clsDate Date)
	{
		for (short i = 1; i <= Weeks; i++)
		{
			Date = DecreaseDateByOneWeek(Date);
		}
		return Date;
	}
	void DecreaseDateByXWeeks(short Weeks)
	{
		DecreaseDateByXWeeks(Weeks, *this);
	}
	static clsDate DecreaseDateByOneMonth(clsDate Date)
	{
		if (Date.Month == 1)
		{
			Date.Month = 12;
			Date.Year--;
		}
		else
		{
			Date.Month--;
		}
		//last check day in date should not exceed max days in the current month 
	   // example if date is 31/1/2022 increasing one month should not be 31 / 2 / 2022, it should
			// be 28/2/2022 
		short NumberOfDaysInCurrentMonth =
			NumberOfDaysInAMonth(Date.Month, Date.Year);
		if (Date.Day > NumberOfDaysInCurrentMonth)
		{
			Date.Day = NumberOfDaysInCurrentMonth;
		}
		return Date;
	}
	void DecreaseDateByOneMonth()
	{
		DecreaseDateByOneMonth(*this);
	}
	static clsDate DecreaseDateByXMonths(short Months, clsDate Date)
	{
		for (short i = 1; i <= Months; i++)
		{
			Date = DecreaseDateByOneMonth(Date);
		}
		return Date;
	}
	void DecreaseDateByXMonths(short Months)
	{
		DecreaseDateByXMonths(Months, *this);
	}
	
	static clsDate DecreaseDateByOneYear(clsDate Date)
	{
		Date.Year--;
		return Date;
	}
	void DecreaseDateByOneYear()
	{
		DecreaseDateByOneYear(*this);
	}
	static clsDate DecreaseDateByXYears(short Years, clsDate Date)
	{
		for (short i = 1; i <= Years; i++)
		{
			Date = DecreaseDateByOneYear(Date);
		}
		return Date;
	}
	void DecreaseDateByXYears(short Years)
	{
		DecreaseDateByXYears(Years, *this);
	}
	static clsDate DecreaseDateByXYearsFaster(short Years, clsDate Date)
	{
		Date.Year -= Years;
		return Date;
	}
	void DecreaseDateByXYearsFaster(short Years)
	{
		DecreaseDateByXYearsFaster(Years, *this);
	}
	
	static clsDate DecreaseDateByOneDecade(clsDate Date)
	{
		Date.Year -= 10;
		return Date;
	}
	void DecreaseDateByOneDecade()
	{
		DecreaseDateByOneDecade(*this);
	}
	static clsDate DecreaseDateByXDecades(short Decade, clsDate Date)
	{
		for (short i = 1; i <= Decade * 10; i++)
		{
			Date = DecreaseDateByOneYear(Date);
		}
		return Date;
	}
	void DecreaseDateByXDecades(short Decade)
	{
		DecreaseDateByXDecades(Decade, *this);
	}
	static clsDate DecreaseDateByXDecadesFaster(short Decade, clsDate Date)
	{
		Date.Year -= Decade * 10;
		return Date;
	}
	void DecreaseDateByXDecadesFaster(short Decade)
	{
		DecreaseDateByXDecadesFaster(Decade, *this);
	}

	static clsDate DecreaseDateByOneCentury(clsDate Date)
	{
		Date.Year -= 100;
		return Date;
	}
	void DecreaseDateByOneCentury()
	{
		DecreaseDateByOneCentury(*this);
	}
	static clsDate DecreaseDateByOneMillennium(clsDate Date)
	{
		Date.Year -= 1000;
		return Date;
	}
	void DecreaseDateByOneMillennium()
	{
		DecreaseDateByOneMillennium(*this);
	}
	//=============================================================================

	// Problems 47 to 53 : More Date Problems  
	static bool IsEndOfWeek(clsDate Date)
	{
		return DayOfWeekOrder(Date) == 7;
	}
	bool IsEndOfWeek()
	{
		return IsEndOfWeek(*this);
	}
	static bool IsWeekEnd(clsDate Date)
	{
		short DayIndex = DayOfWeekOrder(Date);
		//5= fri , 6 = set
		return (DayIndex == 6 || DayIndex == 5);
	}
	bool IsWeekEnd()
	{
		return IsWeekEnd(*this);
	}
	static bool IsBusinessDay(clsDate Date)
	{
		return (!IsWeekEnd(Date));
	}
	bool IsBusinessDay()
	{
		return IsBusinessDay(*this);
	}

	static short DaysUntilTheEndOfWeek(clsDate Date)
	{
		return 7 - DayOfWeekOrder(Date);
	}
	short DaysUntilTheEndOfWeek()
	{
		return DaysUntilTheEndOfWeek(*this);
	}
	static short DaysUntilTheEndOfMonth(clsDate Date)
	{
		return NumberOfDaysInAMonth(Date) - Date.Day + 1;//+1 for today

	}
	short DaysUntilTheEndOfMonth()
	{
		return DaysUntilTheEndOfMonth(*this);
	}
	static short DaysUntilTheEndOfYear(clsDate Date)
	{
		return NumberOfDaysInAYear(Date) - NumberOfDaysFromTheBeginingOfTheYear(Date);
	}
	short DaysUntilTheEndOfYear()
	{
		return DaysUntilTheEndOfYear(*this);
	}

	//Calculate Vacation Days from date =================================================================
	static short CalculateBusinessDays(clsDate DateFrom, clsDate DateTo)
	{
		short DaysCount = 0;

		while (IsDate1BeforeDate2(DateFrom, DateTo))
		{
			if (IsBusinessDay(DateFrom))
				DaysCount++;
			DateFrom = AddOneDay(DateFrom);

		}

		return DaysCount;
	}
	static short CalculateVacationDays(clsDate DateFrom, clsDate DateTo)
	{
		CalculateBusinessDays(DateFrom , DateTo);
	}

	static clsDate CalculateVacationReturnDate(clsDate DateFrom, short VacationDays)
	{

		while (VacationDays != 0)
		{
			if (IsBusinessDay(DateFrom))
				VacationDays--;
			DateFrom = AddOneDay(DateFrom);

		}
		while (IsWeekEnd(DateFrom))
		{
			DateFrom = AddOneDay(DateFrom);
		}
		return DateFrom;
	}
	void CalculateVacationReturnDate(short VacationDays)
	{
		*this = CalculateVacationReturnDate(*this, VacationDays);
	}
	// #56
	static bool IsDate1AfterDate2(clsDate Date1, clsDate Date2)
	{
		return (!IsDate1BeforeDate2(Date1, Date2)
			&& !IsDate1EqualDate2(Date1, Date2));
	}
	bool IsDate1AfterDate2(clsDate Date2)
	{
		return IsDate1AfterDate2(*this , Date2);
	}


	static bool IsValidDate(clsDate Date)
	{
		if (Date.Day < 1 || Date.Day > 31)
			return false;

		if (Date.Month < 1 || Date.Month>12)
			return false;


		short DaysInMonth = NumberOfDaysInAMonth(Date.Month, Date.Year);

		if (Date.Day > DaysInMonth)
			return false;

		return true;

	}
	bool IsValid()
	{
		return IsValidDate(*this);
	}

	static string ReadStringDate(string Message)
	{
		string DateString;
		cout << Message;
		getline(cin >> ws, DateString);

		return DateString;
	}

	static string DateToString(clsDate Date)
	{
		return  to_string(Date.Day) + "/" +
			to_string(Date.Month) + "/" +
			to_string(Date.Year);
	}
	string DateToString()
	{
		return  DateToString(*this);
	}

	static clsDate StringToDate(string DateString)
	{
		short Day, Month, Year;
		vector <string> vDate;

		vDate = clsString::SplitPunctuationDelim(DateString);

		Day = stoi(vDate[0]);
		Month = stoi(vDate[1]);
		Year = stoi(vDate[2]);

		return clsDate(Day, Month, Year);
	}
	
	static string FormatDate(clsDate Date, string Format = "dd/mm/yyyy")
	{
		Format = clsString::ReplaceWord(Format, "dd", to_string(Date.Day));
		Format = clsString::ReplaceWord(Format, "mm", to_string(Date.Month));
		Format = clsString::ReplaceWord(Format, "yyyy", to_string(Date.Year));

		return Format;
	}
	string FormatDate(string Format = "dd/mm/yyyy")
	{
		return FormatDate(*this, Format);
	}


	enum enDateCompare {
		Before = -1, Equal = 0, After
		= 1
	};
	static enDateCompare CompareDates(clsDate Date1, clsDate Date2)
	{
		if (IsDate1BeforeDate2(Date1, Date2))
			return enDateCompare::Before;
		if (IsDate1EqualDate2(Date1, Date2))
			return enDateCompare::Equal;
		
		return enDateCompare::After;
	}

	


};

