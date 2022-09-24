#include "upDate.h"
#include <string>
#include <iostream>
using namespace std;

int Greg2Julian(int month, int day, int year)
{
	int I = year;
	int J = month;
	int K = day;

	int JD = K - 32075 + 1461 * (I + 4800 + (J - 14) / 12) / 4 + 367 * (J - 2 - (J - 14) / 12 * 12)
		/ 12 - 3 * ((I + 4900 + (J - 14) / 12) / 100) / 4;

	return JD;
}

// Converts a Julian date to a Gregorian date.
void Julian2Greg(int JD, int& month, int& day, int& year)
{
	int I;
	int J;
	int K;

	int L = JD + 68569;
	int N = 4 * L / 146097;
	L = L - (146097 * N + 3) / 4;
	I = 4000 * (L + 1) / 1461001;
	L = L - 1461 * I / 4 + 31;
	J = 80 * L / 2447;
	K = L - 2447 * J / 80;
	L = J / 11;
	J = J + 2 - 12 * L;
	I = 100 * (N - 49) + I + L;

	year = I;
	month = J;
	day = K;
}

// Variable that keeps track of how many upDate objects currently exist.
int upDate::dateCount = 0;

// Default constructor that initializes a date as 5/11/1959
upDate::upDate()
{
	// array that allocates memory to store the month, day, and year
	ptr = new int[3];

	*ptr = 5;
	*(ptr + 1) = 11;
	*(ptr + 2) = 1959;

	dateCount++;
}

// Determines whether a year is a leap year. If Feburary has 28 or 29 days in the year depending on if its a leap year.
bool isLeapYear(int years)
{
	if (years % 4 == 0)
	{
		if (years % 100 == 0)
		{
			if (years % 400 == 0)
			{
				return true;
			}
			return false;
		}
		return true;
	}
	return false;
}

// Overloaded constructor
upDate::upDate(int M, int D, int Y)
{
	ptr = new int[3];

	// determine if leapyear
	bool leapYear = isLeapYear(Y);

	// Feburary
	if (M == 2)
	{
		if (D > 29)
		{
			*ptr = 5;
			*(ptr + 1) = 11;
			*(ptr + 2) = 1959;
		}
		else if (D == 29 && leapYear == false)
		{
			*ptr = 5;
			*(ptr + 1) = 11;
			*(ptr + 2) = 1959;
		}
		else
		{
			*ptr = M;
			*(ptr + 1) = D;
			*(ptr + 2) = Y;
		}
	}
	// months with 31 days
	else if (M == 1 || M == 3 || M == 5 || M == 7 || M == 8 || M == 10 || M == 12)
	{
		if (D > 31 || Y < -4712)
		{
			*ptr = 5;
			*(ptr + 1) = 11;
			*(ptr + 2) = 1959;
		}
		else
		{
			*ptr = M;
			*(ptr + 1) = D;
			*(ptr + 2) = Y;
		}

	}
	// months with 30 days
	else if (M == 4 || M == 6 || M == 9 || M == 11)
	{
		if (D > 30 || Y < -4712)
		{
			*ptr = 5;
			*(ptr + 1) = 11;
			*(ptr + 2) = 1959;
		}
		else
		{
			*ptr = M;
			*(ptr + 1) = D;
			*(ptr + 2) = Y;
		}
	}
	else
	{
		*ptr = 5;
		*(ptr + 1) = 11;
		*(ptr + 2) = 1959;
	}

	dateCount++;
}

// Overloaded constructor that initalizes a date based on the julian date.
upDate::upDate(int JD)
{
	ptr = new int[3];

	Julian2Greg(JD, *ptr, *(ptr + 1), *(ptr + 2));

	dateCount++;
}

// Destructor
upDate::~upDate()
{
	dateCount--;
	delete [] ptr;
}

// setDate method that works like the overloaded constructor
void upDate::setDate(int M, int D, int Y)
{
	// determine if leapyear
	bool leapYear = isLeapYear(Y);

	// Feburary
	if (M == 2)
	{
		if (D > 29)
		{
			*ptr = 5;
			*(ptr + 1) = 11;
			*(ptr + 2) = 1959;
		}
		else if (D == 29 && leapYear == false)
		{
			*ptr = 5;
			*(ptr + 1) = 11;
			*(ptr + 2) = 1959;
		}
		else
		{
			*ptr = M;
			*(ptr + 1) = D;
			*(ptr + 2) = Y;
		}
	}
	// months with 31 days
	else if (M == 1 || M == 3 || M == 5 || M == 7 || M == 8 || M == 10 || M == 12)
	{
		if (D > 31 || Y < -4712)
		{
			*ptr = 5;
			*(ptr + 1) = 11;
			*(ptr + 2) = 1959;
		}
		else
		{
			*ptr = M;
			*(ptr + 1) = D;
			*(ptr + 2) = Y;
		}

	}
	// months with 30 days
	else if (M == 4 || M == 6 || M == 9 || M == 11)
	{
		if (D > 30 || Y < -4712)
		{
			*ptr = 5;
			*(ptr + 1) = 11;
			*(ptr + 2) = 1959;
		}
		else
		{
			*ptr = M;
			*(ptr + 1) = D;
			*(ptr + 2) = Y;
		}
	}
	else
	{
		*ptr = 5;
		*(ptr + 1) = 11;
		*(ptr + 2) = 1959;
	}
}

// getMonth() method that gets the current month of an object.
int upDate::getMonth()
{
	return *ptr;
}

// getDay() method that gets the current day of an object.
int upDate::getDay()
{
	return *(ptr + 1);
}

// getYear() method that gets the current year of an object.
int upDate::getYear()
{
	return *(ptr + 2);
}

// getMonthName() method that gets the month name.
string upDate::getMonthName()
{
	string monthName[12] = { "January", "Feburary", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December" };
	return monthName[*ptr - 1];
}

// ostream operator that prints out an objects's month, day, and year
ostream& operator<<(ostream& output, const upDate& d1)
{
	return output << *d1.ptr << "/" << *(d1.ptr + 1) << "/" << *(d1.ptr + 2);	 
}

// Copy constructor that copies the contents of d1 to the current object 
upDate::upDate(const upDate& d1)
{
	ptr = new int[3];

	*ptr = *d1.ptr;
	*(ptr + 1) = *(d1.ptr + 1);
	*(ptr + 2) = *(d1.ptr + 2);

	dateCount++;
}

// Assignment operator that assigns the current object as the contents of d1.
upDate upDate::operator=(upDate d1)
{
	
	*ptr = *d1.ptr;
	*(ptr + 1) = *(d1.ptr + 1);
	*(ptr + 2) = *(d1.ptr + 2);

	return *this;
}

// += operator that increases the amount of days in a date
upDate upDate::operator+=(int days)
{

	int JD = Greg2Julian(*(ptr), *(ptr + 1), *(ptr + 2));

	JD += days;

	Julian2Greg(JD, *(ptr), *(ptr + 1), *(ptr + 2));

	return *this;
}

// -= operator that subtracts the amount of days in a date
upDate upDate::operator-=(int days)
{
	int JD = Greg2Julian(*(ptr), *(ptr + 1), *(ptr + 2));

	JD -= days;

	Julian2Greg(JD, *(ptr), *(ptr + 1), *(ptr + 2));

	return *this;
}

// + operator that increases the amount of days in d1.
upDate upDate::operator+(int days)
{
	upDate d3;

	*d3.ptr = *ptr;
	*(d3.ptr + 1) = *(ptr + 1);
	*(d3.ptr + 2) = *(ptr + 2);

	int JD = Greg2Julian(*d3.ptr, *(d3.ptr + 1), *(d3.ptr + 2));

	JD += days;

	Julian2Greg(JD, *d3.ptr, *(d3.ptr + 1), *(d3.ptr + 2));

	return d3;
}

// + operator that increases the amount of days in d1.
upDate operator+(int days, const upDate& d1)
{
	upDate d3;

	*d3.ptr = *d1.ptr;
	*(d3.ptr + 1) = *(d1.ptr + 1);
	*(d3.ptr + 2) = *(d1.ptr + 2);

	int JD = Greg2Julian(*d3.ptr, *(d3.ptr + 1), *(d3.ptr + 2));

	JD += days;

	Julian2Greg(JD, *d3.ptr, *(d3.ptr + 1), *(d3.ptr + 2));

	return d3;
}

// - operator that subtracts two dates and returns the number of days inbetween the two dates.
int operator-(const upDate& d1, const upDate& d2)
{
	int JD = Greg2Julian(*d1.ptr, *(d1.ptr + 1), *(d1.ptr + 2));
	int JD2 = Greg2Julian(*d2.ptr, *(d2.ptr + 1), *(d2.ptr + 2));

	return JD - JD2;
}

// - operator that subtracts a date with a certain amount of days
upDate upDate::operator-(int days)
{
	upDate d3;

	*d3.ptr = *ptr;
	*(d3.ptr + 1) = *(ptr + 1);
	*(d3.ptr + 2) = *(ptr + 2);

	int JD = Greg2Julian(*d3.ptr, *(d3.ptr + 1), *(d3.ptr + 2));

	JD -= days;

	Julian2Greg(JD, *d3.ptr, *(d3.ptr + 1), *(d3.ptr + 2));

	return d3;
}

// ++ postfix operator that increases the amount of days by 1 in an object
upDate operator++(upDate& d1, int days)
{
	int JD = Greg2Julian(*d1.ptr, *(d1.ptr + 1), *(d1.ptr + 2));

	JD += 1;

	Julian2Greg(JD, *d1.ptr, *(d1.ptr + 1), *(d1.ptr + 2));

	return d1;
}

// ++ prefix operator that increases the amount of days by 1 in an object
upDate operator++(upDate& d1)
{
	int JD = Greg2Julian(*d1.ptr, *(d1.ptr + 1), *(d1.ptr + 2));

	JD += 1;

	Julian2Greg(JD, *d1.ptr, *(d1.ptr + 1), *(d1.ptr + 2));

	return d1;

}

// -- postfix operator that increases the amount of days by 1 in an object
upDate operator--(upDate& d1, int days)
{
	int JD = Greg2Julian(*d1.ptr, *(d1.ptr + 1), *(d1.ptr + 2));

	JD -= 1;

	Julian2Greg(JD, *d1.ptr, *(d1.ptr + 1), *(d1.ptr + 2));

	return d1;
}

// -- prefix operator that increases the amount of days by 1 in an object
upDate operator--(upDate& d1)
{
	int JD = Greg2Julian(*d1.ptr, *(d1.ptr + 1), *(d1.ptr + 2));

	JD -= 1;

	Julian2Greg(JD, *d1.ptr, *(d1.ptr + 1), *(d1.ptr + 2));

	return d1;
}

// julian method that converts a date to a julian date
int upDate::julian()
{
	return Greg2Julian(*ptr, *(ptr + 1), *(ptr + 2));
}

// == comparison operator that determines if two dates are equal or not
bool operator==(upDate& d1, upDate& d2)
{
	if (d1.julian() == d2.julian())
	{
		return true;
	}

	return false;
}

// < comparison operator that determines if one date is less than another date
bool operator<(upDate& d1, upDate& d2)
{
	if (d1.julian() < d2.julian())
	{
		return true;
	}

	return false;
}

// > comparison operator that determines if one date is greater than another date
bool operator>(upDate& d1, upDate& d2)
{
	if (d1.julian() > d2.julian())
	{
		return true;
	}

	return false;
}

// method that returns the number of objects that are currently in the program
int upDate::GetDateCount()
{
	return dateCount;
}
