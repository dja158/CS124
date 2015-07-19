/***********************************************************************
* Program:
*    Assignment 34, Pointer Arithmetic
*    Brother Comeau, CS124
* Author:
*    Derek Anderson
* Summary:
*    This program will practice using pointer arithmetic. In this program
     that is similar to assignment 32, the number of letters in a string
     of characters will be counted by pointers instead of arrays.
*
*    Estimated:  2.0 hrs
*    Actual:     0.5 hrs
*      Since this assignment was similar to assignment 32, it wasn't that
       difficult at all.
************************************************************************/

#include <iostream>
using namespace std;

/**********************************************************************
* countLetters will return the number of letters in a string.
***********************************************************************/
int countLetters(char letter, char * text)
{
   char numLetter = 0;

   for (char * p = text; *p != '\0'; p++)
   {
      if (letter == *p)
         numLetter++;
   }

   return numLetter;
}

/**********************************************************************
* main will prompt the user for a line of input, call countLetters(),
* and display the number of letters.
***********************************************************************/
int main()
{
   char letter;
   char text[256];

   cout << "Enter a letter: ";
   cin >> letter;

   cout << "Enter text: ";
   cin.ignore();
   cin.getline(text, 256);

   cout << "Number of '" << letter << "'s: " << countLetters(letter, text);
   cout << endl;

   return 0;
}
