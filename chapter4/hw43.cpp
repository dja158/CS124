/***********************************************************************
* Program:
*    Assignment 43, Command Line
*    Brother Comeau, CS124
* Author:
*    Derek Anderson
* Summary:
*    The program will convert feet to meters. In this program, the input
     will be numbers passed on a command line.
*
*    Estimated:  1.0 hrs
*    Actual:     1.0 hrs
*      Not many difficulties for this one.
************************************************************************/

#include <iostream>
#include <cstdlib>
using namespace std;

/**********************************************************************
 * main will pass the user input on the command line and convert feet to
 * meters.
 ***********************************************************************/
int main(int argc, char * argv[])
{
   cout.setf(ios::fixed);
   cout.precision(1);
   for (int i = 1; i < argc; i++)
   {
      float feet = atof(argv[i]);
      float meters = atof(argv[i]) * 0.3048;
      cout << feet << " feet is " << meters << " meters\n";
   }

   return 0;
}
