#pragma once
#pragma warning(disable : 4996)
#include<iostream>
#include<iomanip>
#include<string>
#include "classString.h"
using namespace std;


class clsDate
{
	short _day = 1, _month = 1, _year = 1900;
public:
	clsDate() {
		time_t t = time(0);
		tm* now = localtime(&t);
		_day = now->tm_mday;
		_month = now->tm_mon + 1;
		_year = now->tm_year + 1900;
	}

	clsDate(string stringDate) {
		clsDate date = convertStringToDate(stringDate);
		this->_day = date._day;
		this->_month = date._month;
		this->_year = date._year;
	}

	clsDate(int day, int month, int year) {
		_day = day;
		_month = month;
		_year = year;
	}

	clsDate(int daysNumber, int year) {
		clsDate date = GetDateFromDayOrderInYear(daysNumber, year);
		this->_day = date._day;
		this->_month = date._month;
		this->_year = date._year;
	}

	short getDay() {
		return _day;
	}

	void setDay(int day) {
		_day = day;
	}

	__declspec(property(get = getDay, put = setDay))short day;

	short getMonth() {
		return _month;
	}

	void setMonth(int month) {
		_month = month;
	}

	__declspec(property(get = getMonth, put = setMonth))short month;

	short getYear() {
		return _year;
	}

	void setYear(int year) {
		_year = year;
	}

	__declspec(property(get = getYear, put = setYear))short year;


	static clsDate convertStringToDate(string stringDate) {
		clsDate date;
		vector<string> vec(3);
		vec = ClassString::splitString(stringDate, "/");
		date._day = stoi(vec[0]);
		date._month = stoi(vec[1]);
		date._year = stoi(vec[2]);
		return date;
	}

	void Print() {
		cout << day << "/" << month << "/" << year; // is interpreted as: cout << getDay() << "/" << getMonth() << "/" << getYear();
	}

	static bool isLeapYear(int year) {
		return (year % 400 == 0) || (year % 100 != 0 && year % 4 == 0);
	}

	bool isLeapYear() {
		return isLeapYear(this->year); //here I need an object to access the property because I am calling a static method even if I am in a non static method
	}

	static bool isDateValid(clsDate date) {
		if (date.day > NumberOfDaysInAMonth(date.year, date.month) || (date.month > 12 || date.month < 1)) {
			return false;
		}
		return true;
	}

	bool isDateValid() {
		return isDateValid(*this);
	}


	static short NumberOfDaysInAYear(short Year)
	{
		return isLeapYear(Year) ? 366 : 365;
	}

	short NumberOfDaysInAYear() {
		return  NumberOfDaysInAYear(_year);
	}

	static short NumberOfHoursInAYear(short Year)
	{
		return NumberOfDaysInAYear(Year) * 24;
	}

	short NumberOfHoursInAYear() {
		return NumberOfHoursInAYear(year);
	}

	static int NumberOfMinutesInAYear(short Year)
	{
		return NumberOfHoursInAYear(Year) * 60;
	}

	int NumberOfMinutesInAYear() {
		return  NumberOfMinutesInAYear(year);
	}

	static int NumberOfSecondsInAYear(short Year)
	{
		return NumberOfMinutesInAYear(Year) * 60;
	}

	int NumberOfSecondsInAYear()
	{
		return NumberOfSecondsInAYear(year);
	}

	static short NumberOfDaysInAMonth(short year, short month) {
		if (month < 1 || month > 12) {
			return 0;
		}
		return (month == 4 || month == 6 || month == 9 || month == 11) ? 30 : (month == 2) ? (isLeapYear(year) ? 29 : 28) : 31;
	}

	short NumberOfDaysInAMonth() {
		return NumberOfDaysInAMonth(year, month);
	}

	static short NumberOfHoursInAMonth(short year, short month) {
		return NumberOfDaysInAMonth(year, month) * 24;
	}

	short NumberOfHoursInAMonth() {
		return NumberOfDaysInAMonth(year, month) * 24;
	}

	static int NumberOfMinutesInAMonth(short year, short month) {
		return NumberOfHoursInAMonth(year, month) * 60;
	}

	int NumberOfMinutesInAMonth() {
		return NumberOfHoursInAMonth(year, month) * 60;
	}

	static int NumberOfSecondsInAMonth(short year, short month) {
		return NumberOfMinutesInAMonth(year, month) * 60;
	}

	int NumberOfSecondsInAMonth() {
		return NumberOfMinutesInAMonth(year, month) * 60;
	}

	static short findDayOrder(short day, short month, short year) {
		short a, y, m;
		a = (14 - month) / 12;
		y = year - a;
		m = month + 12 * a - 2;
		return (day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;
	}

	short findDayOrder() {
		return findDayOrder(day, month, year);
	}


	static string findDayName(short dayNumber) {
		string daysName[7] = { "Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat" };
		return daysName[dayNumber];
	}

	string findDayName() {
		return findDayName(findDayOrder());
	}

	static void printMonthCalendar(short year, short month) {
		short daysOfMonth = NumberOfDaysInAMonth(year, month);
		string monthName[13] = { "", "Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec" };
		cout << "\n\n  ________________" << monthName[month] << "______________  \n\n";
		string daysName[7] = { "Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat" };
		for (int i = 0; i < 7; i++) {
			cout << "  " << daysName[i];
		}
		cout << endl;
		for (int i = 0; i < 7; i++) {
			if (findDayOrder(1, month, year) == i) {
				for (int j = 1; j <= daysOfMonth; j++) {
					if (j == 1 && findDayName(findDayOrder(j, month, year)) == "Sat") {
						cout << setw(5 * i + 5) << j << endl;
					}
					else if (j != 1 && findDayName(findDayOrder(j, month, year)) == "Sat") {
						cout << setw(5) << j << endl;
					}
					else if (j != 1 && findDayName(findDayOrder(j, month, year)) != "Sat") {
						cout << setw(5) << j;
					}
					else {
						cout << setw(5 * i + 5) << j;
					}
				}
			}
		}
		cout << "\n  __________________________________  \n\n";
	}

	void printMonthCalendar() {
		return printMonthCalendar(year, month);
	}

	static void printYearCalendar(short year) {
		printf("\n _________________________________\n\n");
		printf("        Calendar - %d\n", year);
		printf(" _________________________________\n");
		for (short i = 1; i <= 12; i++) {
			printMonthCalendar(year, i);
		}
	}

	void printYearCalendar() {
		return printYearCalendar(year);
	}

	static short NumberOfDaysFromTheBeginningOfTheYear(short year, short month, short day) {
		short result = 0;
		for (short i = 1; i < month; i++) {
			result += NumberOfDaysInAMonth(year, i);
		}
		result += day;
		return result;
	}

	short NumberOfDaysFromTheBeginningOfTheYear() {
		return NumberOfDaysFromTheBeginningOfTheYear(year, month, day);
	}

	static clsDate GetDateFromDayOrderInYear(short DateOrderInYear, short Year) {
		clsDate Date;
		short RemainingDays = DateOrderInYear;
		short MonthDays = 0;
		Date.year = Year;
		Date.month = 1;
		while (true) {
			MonthDays = NumberOfDaysInAMonth(Year, Date.month);
			if (RemainingDays > MonthDays) {
				RemainingDays -= MonthDays;
				Date.month++;
			}
			else {
				Date.day = RemainingDays;
				break;
			}
		}
		return Date;
	}

	/*clsDate GetDateFromDayOrderInYear(short DateOrderInYear) {
		return  GetDateFromDayOrderInYear(DateOrderInYear, _year);
	}*/

	void addDaysToDate(short daysToAdd) {
		short remainingDays = NumberOfDaysFromTheBeginningOfTheYear(year, month, day) + daysToAdd;
		while (true) {
			if (remainingDays > NumberOfDaysInAMonth(year, month)) {
				remainingDays -= NumberOfDaysInAMonth(year, month);
				month++;
				if (month > 12) {
					month = 1;
					year++;
				}
			}
			else {
				day = remainingDays;
				break;
			}
		}
	}
	static bool IsDate1BeforeDate2(clsDate Date1, clsDate Date2) {
		return (Date1.year < Date2.year) ? true
			: ((Date1.year == Date2.year) ?
				(Date1.month < Date2.month ? true
					: (Date1.month == Date2.month ?
						Date1.day < Date2.day : false))
				: false);
	}
	bool IsDate1BeforeDate2(clsDate Date) {
		return IsDate1BeforeDate2(*this, Date);
	}

	static bool areDatesEqual(clsDate date1, clsDate date2) {
		return ((date1.year == date2.year) && (date1.month == date2.month) && (date1.day == date2.day));

	}

	bool areDatesEqual(clsDate date2) {
		return areDatesEqual(*this, date2);
	}

	static bool isDayLastInMonth(clsDate date) {
		short DaysInMonth = NumberOfDaysInAMonth(date.year, date.month);
		return (date.day == DaysInMonth);
	}

	bool isDayLastInMonth() {
		return isDayLastInMonth(*this);
	}

	static bool isMonthLastInYear(int month) {
		return (month == 12);
	}

	static clsDate increaseDateByOneDay(clsDate& date) {
		if (isDayLastInMonth(date) && isMonthLastInYear(date.month)) {
			date.day = 1;
			date.month = 1;
			date.year++;
		}
		else if (isDayLastInMonth(date) && !isMonthLastInYear(date.month)) {
			date.day = 1;
			date.month++;
		}
		else {
			date.day++;
		}
		return date;
	}

	clsDate increaseDateByOneDay() {
		return increaseDateByOneDay(*this);
	}

	static int calculateDifferenceInDays(clsDate date1, clsDate date2) {
		short date1NumOfDays = NumberOfDaysFromTheBeginningOfTheYear(date1.year, date1.month, date1.day);
		short date2NumOfDays = NumberOfDaysFromTheBeginningOfTheYear(date2.year, date2.month, date2.day);
		int differenceResult;
		int daysOfYearsInBetween = 0;
		if (date1.year == date2.year) {

			if (date1NumOfDays > date2NumOfDays) {
				differenceResult = date1NumOfDays - date2NumOfDays;
			}
			else {
				differenceResult = date2NumOfDays - date1NumOfDays;
			}
		}
		else if (date1.year < date2.year) {
			for (int i = (date1.year + 1); i < date2.year; i++) {
				daysOfYearsInBetween += (isLeapYear(i) ? 366 : 365);
			}
			differenceResult = daysOfYearsInBetween + ((isLeapYear(date1.year) ? 366 : 365) - date1NumOfDays) + date2NumOfDays;
		}
		else {
			for (int i = (date2.year + 1); i < date1.year; i++) {
				daysOfYearsInBetween += (isLeapYear(i) ? 366 : 365);
			}
			differenceResult = daysOfYearsInBetween + ((isLeapYear(date2.year) ? 366 : 365) - date2NumOfDays) + date1NumOfDays;
		}
		return differenceResult;
	}

	int calculateDifferenceInDays(clsDate date) {
		return calculateDifferenceInDays(*this, date);
	}

	static void  SwapDates(clsDate& Date1, clsDate& Date2)
	{
		clsDate TempDate;
		TempDate = Date1;
		Date1 = Date2;
		Date2 = TempDate;
	}

	static clsDate GetSystemDate()
	{
		//system date
		time_t t = time(0);
		tm* now = localtime(&t);

		short Day, Month, Year;

		Year = now->tm_year + 1900;
		Month = now->tm_mon + 1;
		Day = now->tm_mday;

		return clsDate(Day, Month, Year);
	}

	static short CalculateMyAgeInDays(clsDate DateOfBirth)
	{
		return calculateDifferenceInDays(DateOfBirth, clsDate::GetSystemDate());
	}
	//above no need to have non static function for the object because it does not depend on any data from it.


	static clsDate increaseDateByOneWeek(clsDate& date) {
		for (int i = 1; i <= 7; i++) {
			increaseDateByOneDay(date);
		}
		return date;
	}

	clsDate increaseDateByOneWeek() {
		return increaseDateByOneWeek(*this);
	}


	static clsDate increaseDateByXWeeks(clsDate& date, int weeksToAdd) {
		for (int i = 1; i <= weeksToAdd; i++) {
			for (int j = 1; j <= 7; j++) {
				increaseDateByOneDay(date);
			}
		}
		return date;
	}

	clsDate increaseDateByXWeeks(int weeksToAdd) {
		return increaseDateByXWeeks(*this, weeksToAdd);
	}


	static clsDate increaseDateByOneMonth(clsDate& date) {
		if (date.month == 12) {
			date.month = 1;
			date.year++;
		}
		else {
			date.month++;
		}
		short numberOfDaysInCurrentMonth = NumberOfDaysInAMonth(date.year, date.month);
		if (date.day > numberOfDaysInCurrentMonth) {
			date.day = numberOfDaysInCurrentMonth;
		}
		return date;
	}

	clsDate increaseDateByOneMonth() {
		return increaseDateByOneMonth(*this);
	}

	static clsDate increaseDateByXMonth(clsDate& date, int monthsToAdd) {
		for (int i = 1; i <= monthsToAdd; i++) {
			increaseDateByOneMonth(date);

		}
		return date;
	}

	clsDate increaseDateByXMonth(int monthsToAdd) {
		return increaseDateByXMonth(*this, monthsToAdd);
	}


	static clsDate increaseDateOneYear(clsDate& date) {
		if (date.month == 2) {
			short numberOfDaysInCurrentMonth = NumberOfDaysInAMonth(date.year, date.month);
			if (date.day > numberOfDaysInCurrentMonth) {
				date.day = numberOfDaysInCurrentMonth;
			}
		}
		date.year++;
		return date;
	}

	clsDate increaseDateOneYear() {
		return increaseDateOneYear(*this);
	}

	static clsDate increaseDateByXYears(clsDate& date, int yearsToAdd) {
		date.year += yearsToAdd;
		return date;
	}

	clsDate increaseDateByXYears(int yearsToAdd) {
		return increaseDateByXYears(*this, yearsToAdd);
	}

	static clsDate increaseDateByOneDecade(clsDate& date) {
		for (int i = 1; i <= 10; i++) {
			increaseDateOneYear(date);

		}
		return date;
	}

	clsDate increaseDateByOneDecade() {
		return increaseDateByOneDecade(*this);
	}

	static clsDate increaseDateByXDecades(clsDate& date, int decadesToAdd) {
		for (int i = 1; i <= decadesToAdd; i++) {
			increaseDateByOneDecade(date);

		}
		return date;
	}

	clsDate increaseDateByXDecades(int decadesToAdd) {
		return increaseDateByXDecades(*this, decadesToAdd);
	}

	static clsDate increaseDateByOneCentury(clsDate& date) {
		for (int i = 1; i <= 10; i++) {
			increaseDateByOneDecade(date);

		}
		return date;
	}

	clsDate increaseDateByOneCentury() {
		return increaseDateByOneCentury(*this);
	}

	static clsDate increaseDateByOneMillennium(clsDate& date) {
		for (int i = 1; i <= 10; i++) {
			increaseDateByOneCentury(date);

		}
		return date;
	}

	clsDate increaseDateByOneMillennium() {
		return increaseDateByOneMillennium(*this);
	}

	static bool isDayFirstInMonth(clsDate date) {
		return (date.day == 1);
	}

	bool isDayFirstInMonth() {
		return isDayFirstInMonth(*this);
	}
	static bool isMonthFirstInYear(int month) {
		return (month == 1);
	}

	static clsDate decreaseDateByOneDay(clsDate& date) {
		if (isDayFirstInMonth(date) && isMonthFirstInYear(date.month)) {
			date.day = 31;
			date.month = 12;
			date.year--;
		}
		else if (isDayFirstInMonth(date) && !isMonthFirstInYear(date.month)) {
			date.month--;
			date.day = NumberOfDaysInAMonth(date.year, date.month);
		}
		else {
			date.day--;
		}
		return date;
	}

	clsDate decreaseDateByOneDay() {
		return decreaseDateByOneDay(*this);
	}

	static clsDate decreaseDateByXDays(clsDate& date, int daysToSubtract) {
		for (int i = 1; i <= daysToSubtract; i++) {
			decreaseDateByOneDay(date);
		}
		return date;
	}

	clsDate decreaseDateByXDays(int daysToSubtract) {
		return decreaseDateByXDays(*this, daysToSubtract);
	}
	static clsDate decreaseDateByOneWeek(clsDate& date) {
		for (int i = 1; i <= 7; i++) {
			decreaseDateByOneDay(date);
		}
		return date;
	}

	clsDate decreaseDateByOneWeek() {
		return decreaseDateByOneWeek(*this);
	}

	static clsDate decreaseDateByXWeeks(clsDate& date, int weeksToSubtract) {
		for (int i = 1; i <= weeksToSubtract; i++) {
			for (int j = 1; j <= 7; j++) {
				decreaseDateByOneDay(date);
			}
		}
		return date;
	}

	clsDate decreaseDateByXWeeks(int weeksToSubtract) {
		return decreaseDateByXWeeks(*this, weeksToSubtract);
	}

	static clsDate decreaseDateByOneMonth(clsDate& date) {
		if (date.month == 1) {
			date.month = 12;
			date.year--;
		}
		else {
			date.month--;
		}
		short numberOfDaysInCurrentMonth = NumberOfDaysInAMonth(date.year, date.month);
		if (date.day > numberOfDaysInCurrentMonth) {
			date.day = numberOfDaysInCurrentMonth;
		}
		return date;
	}

	clsDate decreaseDateByOneMonth() {
		return decreaseDateByOneMonth(*this);
	}


	static clsDate decreaseDateByXMonth(clsDate& date, int monthsToSubtract) {
		for (int i = 1; i <= monthsToSubtract; i++) {
			decreaseDateByOneMonth(date);

		}
		return date;
	}

	clsDate decreaseDateByXMonth(int monthsToSubtract) {
		return decreaseDateByXMonth(*this, monthsToSubtract);
	}

	static clsDate decreaseDateOneYear(clsDate& date) {
		date.year--;
		if (date.month == 2) {
			short numberOfDaysInCurrentMonth = NumberOfDaysInAMonth(date.year, date.month);
			if (date.day > numberOfDaysInCurrentMonth) {
				date.day = numberOfDaysInCurrentMonth;
			}
		}
		return date;
	}

	clsDate decreaseDateOneYear() {
		return decreaseDateOneYear(*this);
	}


	static clsDate decreaseDateByXYears(clsDate& date, int yearsToSubtract) {
		for (int i = 1; i <= yearsToSubtract; i++) {
			decreaseDateOneYear(date);

		}
		return date;
	}

	clsDate decreaseDateByXYears(int yearsToSubtract) {
		return  decreaseDateByXYears(*this, yearsToSubtract);
	}

	static clsDate decreaseDateByOneDecade(clsDate& date) {
		for (int i = 1; i <= 10; i++) {
			decreaseDateOneYear(date);

		}
		return date;
	}

	clsDate decreaseDateByOneDecade() {
		return decreaseDateByOneDecade(*this);
	}

	static clsDate decreaseDateByXDecades(clsDate& date, int decadesToSubtract) {
		for (int i = 1; i <= decadesToSubtract; i++) {
			decreaseDateByOneDecade(date);

		}
		return date;
	}

	clsDate decreaseDateByXDecades(int decadesToSubtract) {
		return decreaseDateByXDecades(*this, decadesToSubtract);
	}


	static clsDate decreaseDateByOneCentury(clsDate& date) {
		for (int i = 1; i <= 10; i++) {
			decreaseDateByOneDecade(date);

		}
		return date;
	}

	clsDate decreaseDateByOneCentury() {
		return  decreaseDateByOneCentury(*this);
	}

	static clsDate decreaseDateByOneMillennium(clsDate& date) {
		for (int i = 1; i <= 10; i++) {
			decreaseDateByOneCentury(date);

		}
		return date;
	}

	clsDate decreaseDateByOneMillennium() {
		return decreaseDateByOneMillennium(*this);
	}

	static bool isWeekEnd(clsDate date) {
		short dayOrder = findDayOrder(date.day, date.month, date.year);
		return (dayOrder == 5 || dayOrder == 6);
	}

	bool isWeekEnd() {
		return isWeekEnd(*this);
	}

	static bool isEndOfWeek(clsDate date) {
		return findDayOrder(date.day, date.month, date.year) == 6;
	}

	bool isEndOfWeek() {
		return  isEndOfWeek(*this);
	}

	static bool isBusinessDay(clsDate date) {
		return !isWeekEnd(date);
	}

	bool isBusinessDay() {
		return  isBusinessDay(*this);
	}

	static short determineDaysUntilTheEndOfWeek(clsDate date) {
		short daysBeforeEndOfWeek = 0;
		while (date.day != 6) {
			daysBeforeEndOfWeek++;
			date.day++;
		}
		return daysBeforeEndOfWeek;
	}

	short determineDaysUntilTheEndOfWeek() {
		return determineDaysUntilTheEndOfWeek(*this);
	}


	static short determineDaysUntilTheEndOfMonth(clsDate date) {
		return NumberOfDaysInAMonth(date.year, date.month) - date.day + 1;
	}

	short determineDaysUntilTheEndOfMonth() {
		return determineDaysUntilTheEndOfMonth(*this);
	}


	static short determineDaysUntilTheEndOfYear(clsDate date) {
		short daysOfYear = (isLeapYear(date.year) ? 366 : 365);
		return daysOfYear - NumberOfDaysFromTheBeginningOfTheYear(date.year, date.month, date.day) + 1;
	}

	short determineDaysUntilTheEndOfYear() {
		return determineDaysUntilTheEndOfYear(*this);
	}

	static int calculateVacationDays(clsDate date1, clsDate date2) {
		int vacationDays = 0;
		while (IsDate1BeforeDate2(date1, date2) == true) {
			if (findDayOrder(date1.day, date1.month, date1.year) != 5 && findDayOrder(date1.day, date1.month, date1.year) != 6)
				vacationDays++;
			increaseDateByOneDay(date1);
		}
		return vacationDays;
	}


	static clsDate calculateReturnDateFromVacation(clsDate& date, short vacationDays) {
		short weekEndsDays = 0;
		for (short i = 1; i <= vacationDays + weekEndsDays; i++) {
			if (isWeekEnd(date) == true) {
				weekEndsDays++;
			}
			increaseDateByOneDay(date);
		}
		while (isWeekEnd(date)) {
			increaseDateByOneDay(date);
		}
		return date;
	}

	static bool isDate1AfterDate2(clsDate date1, clsDate date2) {
		return !IsDate1BeforeDate2(date1, date2);
	}

	bool isDate1AfterDate2(clsDate date2) {
		return isDate1AfterDate2(*this, date2);
	}

	enum enDateComparison { before = -1, equal = 0, after = 1 };

	static enDateComparison compareDates(clsDate date1, clsDate date2) {
		return IsDate1BeforeDate2(date1, date2) ? enDateComparison::before : isDate1AfterDate2(date1, date2) ? enDateComparison::after : enDateComparison::equal;
	}

	enDateComparison compareDates(clsDate date2) {
		return compareDates(*this, date2);
	}


};