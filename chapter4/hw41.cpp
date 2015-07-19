/***********************************************************************
* Program:
*    Assignment 41, Allocating Memory
*    Brother Comeau, CS124
* Author:
*    Derek Anderson
* Summary:
*    The program will demonstrate the use of memory allocation. In this
     program, the user will be prompted for the number of characters in
     a string, allocate the string, prompt the user for that string and
     display it back to the user.
*
*    Estimated:  2.0 hrs
*    Actual:     1.0 hrs
*      The most difficult part of the assignment was making sure that the
       array was passed as a parameter and allocated correctly.
************************************************************************/

#include <iostream>
#include <cassert>
using namespace std;

/**********************************************************************
* numChar will prompt user for number of characters.
***********************************************************************/
int numChar()
{
   int character;

   cout << "Number of characters: ";
   cin >> character;

   return character;
}


/**********************************************************************
* allocate will allocate the user's input to memory.
***********************************************************************/
int * allocate(int character)
{
   int *p = new(nothrow) int [character];

   if (!p)
      cout << "Allocation failure!" << endl;

   return p;

}

/**********************************************************************
* main call numChar and the allocation functions, prompt the user for
* a string of text and display it back to the user.
***********************************************************************/
int main()
{
   int getNumChar =  numChar();
   assert(getNumChar > 0);

   int * list = allocate(getNumChar);
   if (list == NULL)
      return 1;

   char text[256];

   cout << "Enter Text: ";
   cin.ignore();
   cin.getline(text, getNumChar + 1);

   cout << "Text: " << text << endl;

   delete [] list;
   list = NULL;

   return 0;
}
