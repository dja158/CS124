/***********************************************************************
* Program:
*    Assignment 12, Monthly Income
*    Brother Comeau, CS124
* Author:
*    Derek Anderson
* Summary:
*    The program will practice using inputs and variables. In this program,
     the program will prompt the user for his or her income and display
     the result on the screen.
*
*    Estimated:  0.5 hrs
*    Actual:     0.5 hrs
*      As with assignment 11, the most difficult part of the assignment
       was making sure that each line was properly aligned, tabbed, and
       spaced.
************************************************************************/

#include <iostream>
#include <iomanip>
using namespace std;

/**********************************************************************
 * main will prompt user for monthly income and display the income.
 ***********************************************************************/
int main()
{
   //format output to display money
   cout.setf(ios::fixed);
   cout.setf(ios::showpoint);
   cout.precision(2);

   //declare variables
   double income;

   //prompt user for income
   cout << "\tYour monthly income: ";
   cin >> income;

   //display monthly income
   cout << "Your income is: ";
   cout << "$" << setw(9) << income << endl;

   return 0;
}
