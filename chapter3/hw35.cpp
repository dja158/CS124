File Edit Options Buffers Tools C++ Help
/***********************************************************************
* Program:
*    Assignment 35, Advanced Conditionals
*    Brother Comeau, CS124
* Author:
*    Derek Anderson
* Summary:
*    This program will demonstrate switch statements and conditional
     operators. In this program, the user will be prompted for a number
     grade, and the number will be returned as a letter grade.
*
*    Estimated:  2.0 hrs
*    Actual:     3.0 hrs
*      The most difficult part of the assignment for me was figuring out
       how to return the asterisk symbol for grade signs that weren't a
       plus or minus.
************************************************************************/

#include <iostream>
#include <iomanip>
using namespace std;

/**********************************************************************
* computeLetterGrade will prompt for a number grade and return a letter
* grade.
***********************************************************************/
char computeLetterGrade(int numberGrade)
{
   char letterGrade;

   switch (numberGrade / 10)
   {
      case 10:
      case 9:
         letterGrade = 'A';
         break;
      case 8:
         letterGrade = 'B';
         break;
         letterGrade = 'B';
         break;
      case 7:
         letterGrade = 'C';
         break;
      case 6:
         letterGrade = 'D';
         break;
      default:
         letterGrade = 'F';
   }

   return letterGrade;
}

/**********************************************************************
* computeGradeSign will return a grade sign from the number grade from
* computeLetterGrade.
***********************************************************************/
char computeGradeSign(int numberGrade)
{
   int secondDigit = (numberGrade % 10);

   if (numberGrade > 93 || numberGrade < 60)
      return '*';

   char gradeSign = (secondDigit >= 7) ? '+': '-';

   if (secondDigit > 2 && secondDigit < 7)
      return '*';

   return gradeSign;
}

/**********************************************************************
* main will prompt the user for a number graded then display the letter
* grade.
***********************************************************************/
int main()
{
   int numberGrade;

   cout << "Enter number grade: ";
   cin >> numberGrade;

   computeLetterGrade(numberGrade);
   char gradeSign = computeGradeSign(numberGrade);

   cout << numberGrade << "% is " << computeLetterGrade(numberGrade);

   if (gradeSign != '*')
      cout << gradeSign;

   cout << "\n";

   return 0;
}
