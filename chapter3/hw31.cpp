/***********************************************************************
* Program:
*    Assignment 31, Array Design
*    Brother Comeau, CS124
* Author:
*    Derek Anderson
* Summary:
*    The program will practice the use of array design. In this program,
     the averageGrades() function from assignment 30 will be modified so
     that grades with the value -1 will not be accepted.
*
*    Estimated:  2.5 hrs
*    Actual:     3.0 hrs
*      The most difficult part of the assignment was fulfilling the special
       case in the even that none of the grades were considered complete.
************************************************************************/

#include <iostream>
using namespace std;

/**********************************************************************
* getGrades will prompt the user for ten grades
***********************************************************************/
void getGrades(int grades[], int num)
{
   for (int i = 0; i < num; i++)
   {
      cout << "Grade " << i + 1 << ": ";
      cin >> grades [i];
   }
}

/**********************************************************************
* averageGrades will find the average of getGrades and return the answer,
* unless a grade value is equal to -1.
***********************************************************************/
void averageGrades(int grades[], int num, int value)
{
   cout.setf(ios::fixed);
   cout.setf(ios::showpoint);
   cout.precision(0);

   int sum = 0;
   int invalid = 0;

   for (int i = 0; i < num; i++)
   {
      if (value != grades[i])
         sum += grades[i];
      else
         invalid++;
   }

   int divisor = num - invalid;

   if (divisor == 0)
   {
      cout << "Average Grade: ---%" << endl;
      return;
   }

   int average = sum / divisor;

   cout << "Average Grade: " << average << "%" << endl;
}

/**********************************************************************
* main will call getGrades and averageGrades functions and display the
* result.
***********************************************************************/
int main()
{
   int grades[10];
   int num = 10;
   int value = -1;

   getGrades(grades, num);

   averageGrades(grades, num, value);

   return 0;
}
