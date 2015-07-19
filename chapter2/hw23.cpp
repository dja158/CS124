/***********************************************************************
* Program:
*    Assignment 23, Loop Syntax
*    Brother Comeau, CS124
* Author:
*    Derek Anderson
* Summary:
*    The program will practice loop syntax. In this program, the user will
     add up multiples that are less than 100.
*
*    Estimated:  1.0 hrs
*    Actual:     0.0 hrs
*      Please describe briefly what was the most difficult part.
************************************************************************/

#include <iostream>
using namespace std;

/**********************************************************************
 * getMultiple will prompt user for multiple to be added
 ***********************************************************************/
int getMultiple()
{
   int number;

   cout << "What multiples are we adding? ";
   cin >> number;

   return number;
}

/**********************************************************************
 * loopSum will add the input from getMultiple until the loop is complete
 * and display the sum
 ***********************************************************************/
void loopSum(int number)
{
   int sum = 0;

   for (int i = number; i < 100; i += number)
   {
      sum = sum + i;
   }

   cout << "The sum of multiples of " << number;
   cout << " less than 100 are: " << sum << endl;

   return;
}

/**********************************************************************
 * main will call the getMultiple and loopSum functions
 ***********************************************************************/
int main()
{
   int multiple = getMultiple();

   loopSum(multiple);

   return 0;
}
