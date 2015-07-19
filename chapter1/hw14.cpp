/***********************************************************************
* Program:
*    Assignment 14, Functions
*    Brother Comeau, CS124
* Author:
*    Derek Anderson
* Summary:
*    This program will practice the use of functions. In this program,
     the function questionPeter will be called, display a message, and
     return a response from the function responseLord.
*
*    Estimated:  0.5 hrs
*    Actual:     0.5 hrs
*      The most difficult part of the assignment was making sure that the
       functions were being called correctly by main.
************************************************************************/

#include <iostream>
using namespace std;

/**********************************************************************
 * questionPeter will display Peter's question.
 ***********************************************************************/
void questionPeter()
{
   cout << "Lord, how oft shall my brother sin against me, and I forgive ";
   cout << "him?\n";
   cout << "Till seven times?" << endl;

   return;
}

/**********************************************************************
 * responseLord will return the Lord's response.
 ***********************************************************************/
int responseLord()
{
   return 7 * 70;
}

/**********************************************************************
 * main will call questionPeter and responseLord functions.
 ***********************************************************************/
int main()
{
   questionPeter();

   cout << "Jesus saith unto him, I say not unto thee, Until seven\n";
   cout << "times: but, Until " << responseLord() << "." << endl;

   return 0;
}
