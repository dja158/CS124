/***********************************************************************
* Program:
*    Assignment 11, Monthly Budget
*    Brother Comeau, CS124
* Author:
*    Derek Anderson
* Summary:
*    The program will practice displaying text and numbers to the screen.
     In this program, a monthly budget will be aligned properly and
     displayed on screen.
*
*    Estimated:  0.5 hrs
*    Actual:     0.5 hrs
*      The most difficult part of the assignment for me was making sure
       that each line was properly aligned, tabbed, and spaced.
************************************************************************/

#include <iostream>
#include <iomanip>
using namespace std;

/**********************************************************************
 * main will display the monthly budget on the screen.
 ***********************************************************************/
int main()
{
   //format output to display money
   cout.setf(ios::fixed);
   cout.setf(ios::showpoint);
   cout.precision(2);

   //display the rows
   cout << "\tItem" << setw(20) << "Projected" <<  endl;
   cout << "\t=============  " << "==========" << endl;
   cout << "\tIncome" << setw(10) << "$" << setw(9) << 1000.00 << endl;
   cout << "\tTaxes" << setw(11) << "$" << setw(9) << 100.00 << endl;
   cout << "\tTithing" << setw(9) << "$" << setw(9) << 100.00 << endl;
   cout << "\tLiving" << setw(10) << "$" << setw(9) << 650.00 << endl;
   cout << "\tOther" << setw(11) << "$" << setw(9) << 90.00 << endl;
   cout << "\t=============  " << "==========" << endl;
   cout << "\tDelta" << setw(11) << "$" << setw(9) << 60.00 << endl;

   return 0;
}
