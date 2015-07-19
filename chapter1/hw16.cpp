/***********************************************************************
* Program:
*    Assignment 16, IF Statements
*    Brother Comeau, CS124
* Author:
*    Derek Anderson
* Summary:
*    This program will practice the use of IF statements. In this program,
     the program will determine what tax bracket a user is in based off
     their income.
*
*    Estimated:  0.5 hrs
*    Actual:     0.5 hrs
*      The most difficult part of the assignment was correctly defining
       the tax bracket ranges.
************************************************************************/

#include <iostream>
using namespace std;

/**********************************************************************
 * computeTax will define tax brackets and their ranges.
 ***********************************************************************/
int computeTax(int income)
{
   if (income < 15100)
      return 10;

   else if (income >= 15100 && income < 61300)
      return 15;

   else if (income >= 61300 && income < 123700)
      return 25;

   else if (income >= 123700 && income < 188450)
      return 28;

   else if (income >= 188450 && income < 336550)
      return 33;

   else if (income >= 336550)
      return 35;

   return 0;
}

/**********************************************************************
 * main will prompt user for income, then call computeTax to determine
 * the tax bracket the user falls under.
 ***********************************************************************/
int main()
{
   int income;

   cout << "Income: ";
   cin >> income;

   cout << "Your tax bracket is " << computeTax(income) << "%\n";

   return 0;
}
