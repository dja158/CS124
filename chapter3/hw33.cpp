/***********************************************************************
* Program:
*    Assignment 33, Pointers
*    Brother Comeau, CS124
* Author:
*    Derek Anderson
* Summary:
*    This program will practice the use of pointers. In this program, two
     people will be prompted for their account balance. Whoever has more
     money in their account will pay for the purchases, which in this case
     is purchases made during a date.
*
*    Estimated:  3.0 hrs
*    Actual:     1.0 hrs
*      Surprisingly enough, this assignment wasn't too difficult. The only
       area of difficulty I had which I overcame quickly was writing the
       program with two functions instead of one.
************************************************************************/

#include <iostream>
#include <iomanip>
using namespace std;

/**********************************************************************
* void date will prompt for three numbers, add up the numbers, and subtract
* the total from whoever has the larger balance.
***********************************************************************/
void date(float *pAccount)
{
   float dinner;
   float movie;
   float iceCream;

   cout << "Cost of the date:" << endl;
   cout << "\tDinner:    ";
   cin >> dinner;

   cout << "\tMovie:     ";
   cin >> movie;

   cout << "\tIce cream: ";
   cin >> iceCream;

   *pAccount -= (dinner + movie + iceCream);
}

/**********************************************************************
* main will prompt the user for two balances, determine who has the
* larger balance, call void date(pAccount), and display the balance of
* the users.
***********************************************************************/
int main()
{
   cout.setf(ios::fixed);
   cout.setf(ios::showpoint);
   cout.precision(2);

   float balanceSam;
   float balanceSue;
   float *pAccount;

   cout << "What is Sam's balance? ";
   cin >> balanceSam;

   cout << "What is Sue's balance? ";
   cin >> balanceSue;

   if (balanceSam > balanceSue)
      pAccount = &balanceSam;
   else
      pAccount = &balanceSue;

   date(pAccount);

   cout << "Sam's balance: $" << balanceSam << endl;
   cout << "Sue's balance: $" << balanceSue << endl;

   return 0;
}
