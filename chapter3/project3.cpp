/***********************************************************************
* Program:
*    Project 3, Mad Lib
*    Brother Comeau, CS124
* Author:
*    Derek Anderson
* Summary:
*    This program will implement a Mad Lib game. The program will prompt the
     user for the file that describes the Mad Lib, play the game, and ask
     the user if they want to play another.
*
*    Estimated:  5.0 hrs
*    Actual:     10.0 hrs
*      The hardest part for me was to correctly display the story, which I
*      was unable to figure out by the due date.
************************************************************************/

#include <iostream>
#include <fstream>
using namespace std;

void getFileName(char fileName[]);
int readFile(char story[][32]);
void askQuestion(char text[], int count);
void isPunc(char punc[]);
void displaystory(char story[][32],
                  int length);

/**********************************************************************
 * getFileName prompts user for file name.
 ***********************************************************************/
void getFileName(char fileName[])
{
   cout << "Please enter the filename of the Mad Lib: ";
   cin >> fileName;
   cin.ignore();

   return;
}

/**********************************************************************
 * readFile reads data in file, and substitute words from user input.
 ***********************************************************************/
int readFile(char story[][32])
{
   char fileName[256];
   getFileName(fileName);

   ifstream fin(fileName);

   if (fin.fail())
   {
      cout << "Unable to open file " << fileName << endl;
      return -1;
   }

   int count = 0;
   int numWords = 0;
   while (numWords < 256 && fin >> story[numWords])
   {
      if (story[numWords][0] == '<' && isalpha(story[numWords][1]))
      {
         askQuestion(story[numWords], count);
         count++;
      }
      else if (story[numWords][0] == '<' && !isalpha(story[numWords][2]))
      {
         isPunc(story[numWords]);
         numWords++;
      }
   }
   fin.close();

   return numWords;
}

/**********************************************************************
 * askQuestion prompts user for words in Mad Lib file.
 ***********************************************************************/
void askQuestion(char text[], int count)
{
   cout << "\t" << (char)toupper(text[1]);

   for (int i = 2; text[i] != '>'; i++)
   {
      if (text[i] == '_')
         cout << " ";
      else
      {
         cout << (char)tolower(text[i]);
      }
   }

   cout << ": ";

   if (count == 0)
   {
      cin.ignore();
      cin.getline(text, 256);
   }
   else if (count > 0)
   {
      cin.getline(text, 256);
   }

   return;
}

/**********************************************************************
 * isPunc changes tokens to more readable form.
 ***********************************************************************/
void isPunc(char punc[])
{
   switch (punc[1])
   {
      case '#':
         punc[0] = '\n';
         punc[1] = '\0';
         break;
      case '{':
         punc[0] = ' ';
         punc[1] = '\"';
         punc[2] = '\0';
         break;
      case '}':
         punc[0] = '\"';
         punc[1] = '\'';
         punc[2] = '\0';
         break;
      case '[':
         punc[0] = ' ';
         punc[1] = '\'';
         punc[2] = '\0';
         break;
      case ']':
         punc[0] = '\'';
         punc[1] = ' ';
         punc[2] = '\0';
   }

   return;
}

/**********************************************************************
 * displayStory will display the completed story with substitute words.
 ***********************************************************************/
void displayStory(char story[][32], int numWords)
{
   for (int i = 0; i < numWords; i++)
   {
      if (i == 0)
         cout << story[i];
      else if (story[i] == "." || story[i] == ",")
         cout << story[i];
      else
         cout << " " << story[i];
   }
   return;
}

/**********************************************************************
 * main runs the program.
 ***********************************************************************/
int main()
{
   char story[256][32];
   int numWords;

   char yesOrNo;
   bool playAgain = true;

   while (playAgain)
   {
      numWords = readFile(story);
      displayStory(story, numWords);

      cout << "Do you want to play again (y/n)? ";
      cin >> yesOrNo;

      if (yesOrNo == 'n')
      {
         playAgain = false;
         cout << "Thank you for playing." << endl;
      }
      else if (yesOrNo == 'y')
         playAgain = true;
      else if (yesOrNo != 'y' || yesOrNo != 'n')
      {
         cout << "Invalid entry. Do you want to play again (y/n)? ";
         cin >> yesOrNo;
         if (yesOrNo == 'n')
         {
            playAgain = false;
            cout << "Thank you for playing." << endl;
         }
      }
   }

   return 0;
}
