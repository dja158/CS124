/***********************************************************************
* Program:
*    Assignment 25, Calender Display
*    Brother Comeau, CS124
* Author:
*    Derek Anderson
* Summary:
*    The program will display a calendar on screen with two parameters.
     The first parameter will be the number of days in a month, while the
     second parameter will be the offset from Monday.
*
*    Estimated:  2.0 hrs
*    Actual:     2.0 hrs
*      The most difficult part of this assignment was understanding
       how the various loops worked.
************************************************************************/

#include <iostream>
#include <iomanip>
using namespace std;

/**********************************************************************
* displayTable will display the number of days in a month and the offset
* from the user's input.
***********************************************************************/
void displayTable (int numDays, int offset)
{
   if (offset == 6)
      offset = -1;

   //print the days of the week
   std::cout << "  Su  Mo  Tu  We  Th  Fr  Sa" << endl;

   int dayOfWeek = 0;
   for (int date = -offset;
        date <= numDays;
        date++ ,
        dayOfWeek++)
   {
   
      if (date > 0)
      {
         std::cout << std::setw(4) << date;
      }
      else
      {
         std::cout << "    ";
      }

       //New line every Saturday, unless it is last day of month
      if (dayOfWeek % 7 == 6 && date != numDays)
         std::cout << endl;
   }

   std::cout << endl;
}

/**********************************************************************
* main will accept input from user and call the displayTable function to
* display the number of days in a month and the offset showing where the
* month begins.
***********************************************************************/
int main()
{
   int days;
   int offset;

   std::cout << "Number of days: ";
   std::cin >> days;

   std::cout << "Offset: ";
   std::cin >> offset;

   displayTable(days, offset);

   return 0;
}
