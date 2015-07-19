/***********************************************************************
* Program:
*    Project 2, Calendar Program
*    Brother Comeau, CS124
* Author:
*    Derek Anderson
* Summary:
*    The program will create a calendar for any month of any year from
     1753 onward. The user will be prompted for the month and year to
     be displayed.
*
*    Estimated:  7.0 hrs
*    Actual:     7.0 hrs
*      The most difficult part of the project was programming the offset
       so that it would display in the calendar correctly.
************************************************************************/

#include <iostream>
#include <iomanip>
#include <cassert>
using namespace std;

/**********************************************************************
 * isLeapYear will determine if the year is a leap year.
 ***********************************************************************/
bool isLeapYear(int year)
{
   assert (year >= 1753);

   if (year % 4 != 0)
      return false;

   if (year % 100 != 0)
      return true;

   if (year % 400 == 0)
      return true;

   return false;
}

/**********************************************************************
 * numDaysMonth determines number of days in given month.
 ***********************************************************************/
int numDaysMonth(int month, int year)
{
   const int days[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

   if (month == 2 && isLeapYear(year))
      return 29;

   assert(month > 0 && month < 13);

   return days[month];
}

/**********************************************************************
 * numDaysYear determines number of days in given year.
 ***********************************************************************/
int numDaysYear(int year)
{
   assert(year >= 1753);

   return isLeapYear (year) ? 366 : 365;
}

#define yearSeed

/**********************************************************************
 * computeOffset will offset number of days from given month and year.
 * It is the offset since Monday.
 ***********************************************************************/
int computeOffset(int month, int year)
{
   int days = 0;

   assert(month >= 1 && month <= 12);
   assert(year >= 1753);

   for (int cYear = 1753; cYear < year; cYear++)
   {
      assert(numDaysYear(cYear) == 366 || numDaysYear(cYear) == 365);
      days += numDaysYear(cYear);
   }

   for (int cMonth = 1; cMonth < month; cMonth++)
   {
      assert(numDaysMonth(cMonth, year) >= 28 && numDaysMonth(cMonth, year)
             <= 31);
      days += numDaysMonth(cMonth, year);
   }
   assert((days % 7 >= 0) && (days % 7 <= 6));

   return days % 7;
}

/**********************************************************************
 * displayHeader will create calendar header.
 ***********************************************************************/
void displayHeader(int month, int year)
{
   cout << endl;

   assert(month >= 1 && month <= 12);
   assert(year >= 1753);

   switch (month)
   {
      case 1:
         cout << "January";
         break;
      case 2:
         cout << "February";
         break;
      case 3:
         cout << "March";
         break;
      case 4:
         cout << "April";
         break;
      case 5:
         cout << "May";
         break;
      case 6:
         cout << "June";
         break;
      case 7:
         cout << "July";
         break;
      case 8:
         cout << "August";
         break;
      case 9:
         cout << "September";
         break;
      case 10:
         cout << "October";
         break;
      case 11:
         cout << "November";
         break;
      case 12:
         cout << "December";
         break;
      default:
         assert(false);
   }

   cout << ", " << year << endl;

   return;
}

/**********************************************************************
 * displayTable will create a calendar from the given number of days and
 * the offset.
 ***********************************************************************/
void displayTable(int numDays, int offset)
{
   assert(offset >= 0 && offset <= 6);

   if (offset == 6)
      offset = -1;

   cout << "  Su  Mo  Tu  We  Th  Fr  Sa\n";

   int dow = 0;

   for (int dom = -offset;
        dom <= numDays;
        dom++ ,
           dow++)
   {
      if (dom > 0)
         cout << setw(4) << dom;
      else
         cout << "    ";
      if (dow % 7 == 6)
         cout << endl;
   }

   if (dow % 7 != 0)
      cout << endl;

   return;
}

/**********************************************************************
 * display will create a calendar
 ***********************************************************************/
void display(int month, int year, int offset)
{
   assert(year >= 1753);
   assert(month >= 1 && month <= 6);
   assert(offset >= 0 && offset <= 6);

   displayHeader(month, year);

   displayTable(numDaysMonth(month, year), offset);

   return;
}

/**********************************************************************
 * getYear prompts user for year.
 ***********************************************************************/
int getYear()
{
   int year;

   do
   {
      cout << "Enter year: ";
      cin >> year;

      if (year < 1753)
      {
         cout << "Year must be 1753 or later.\n";
      }
   }
   while (year < 1753);
   assert(year >= 1753);

   return year;
}

/**********************************************************************
 * getMonth prompts user for month.
 ***********************************************************************/
int getMonth()
{
   int month;
   while (true)
   {
      cout << "Enter a month number: ";
      cin >> month;

      if (month <= 12 && month >= 1)
         return month;
      cout << "Month must be between 1 and 12.\n";
   }

   return 1;
}

/**********************************************************************
 * main will run the calendar program.
 ***********************************************************************/
int main()
{
   int month = getMonth();
   int year = getYear();

   int offset = computeOffset(month, year);

   display(month, year, offset);

   return 0;
}
