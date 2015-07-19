/***********************************************************************
* Program:
*    Assignment 30, Array Syntax
*    Brother Comeau, CS124
* Author:
*    Derek Anderson
* Summary:
*    The program will practice the use of array syntax. In this program,
     the user will be prompted for ten grades and return the result to
     main(), which will determine the average of the grades and display
     the result to the user.
*
*    Estimated:  2.0 hrs
*    Actual:     4.0 hrs
*      The most difficult part of the assignment for me was making sure
       the array was correctly used in the averageGrades function.
************************************************************************/

#include <iostream>
using namespace std;

/**********************************************************************
 * getGrades will prompt the user for ten grades.
************************************************************************/
void getGrades(int grades[], int num)
{
   for (int i = 0; i < num; i++)
   {
      cout << "Grade " << i + 1 << ": ";
      cin >> grades [i];
   }
}

/**********************************************************************
 * averageGrades will find the average of getGrades and return the answer.
************************************************************************/
void averageGrades(int grades[], int num)
{
   cout.setf(ios::fixed);
   cout.setf(ios::showpoint);
   cout.precision(0);

   int sum = 0;

   for (int i = 0; i < num; i++)
   {
      sum += grades[i];
   }

   int average = sum / 10;

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

   getGrades(grades, num);

   averageGrades(grades, num);

   return 0;
}
