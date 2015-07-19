/***********************************************************************
* Program:
*    Assignment 32, Strings
*    Brother Comeau, CS124
* Author:
*    Derek Anderson
* Summary:
*    This program will practice traversing a string. In this first part of
     a two part assignment, the program will count the number of letters in
     a string.
*
*    Estimated:  2.0 hrs
*    Actual:     2.0 hrs
*      The most difficult part of the assignment for me was making sure
       that the for loop was correctly adding the numbers in the string.
************************************************************************/

#include <iostream>
using namespace std;

/**********************************************************************
* countLetters will return the number of letters in a string.
***********************************************************************/
int countLetters(char letter, char text[])
{
   char numLetter = 0;

   for (int i = 0; text[i] != '\0'; i++)
   {
      if (letter == text[i])
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
