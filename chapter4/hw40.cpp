/***********************************************************************
* Program:
*    Assignment 40, Multi-Dimensional Arrays
*    Brother Comeau, CS124
* Author:
*    Derek Anderson
* Summary:
*    The program will practice the use of multi-dimensional arrays. In this
     program, a Tic-Tac-Toe board will be read and displayed.
*
*    Estimated:  3.0 hrs
*    Actual:     5.0 hrs
*      The most difficult part of this assignment was correctly writing
       to the file.
************************************************************************/

#include <iostream>
#include <fstream>
using namespace std;

/**********************************************************************
 * getFile prompts user for source filename.
 **********************************************************************/
void getFile(char fileOpen[])
{
   cout << "Enter source filename: ";
   cin >> fileOpen;

   return;
}

/**********************************************************************
 * fileWrite prompts user for destination filename.
 **********************************************************************/
void fileToWrite(char fileWrite[])
{
   cout << "Enter destination filename: ";
   cin >> fileWrite;
   
   return;
}

/**********************************************************************
* readFile will read the file that the user entered into the program.
***********************************************************************/
void readFile(char fileOpen[], char grid[][3])
{
   ifstream fin(fileOpen);

   for (int g = 0; g < 3; g++)
   {
      for (int m = 0; m < 3; m++)
      {
         fin >> grid[g][m];
      }
   }
   fin.close();
}

/**********************************************************************
* display will display a board from the file the user was prompted to
* enter.
***********************************************************************/
void display(char grid[][3])
{
   for (int g = 0; g < 3; g++)
   {
      for (int m = 0; m < 3; m++)
      {
         cout << " ";
         if (grid[g][m] == '.')
            cout << " ";
         else
            cout << grid[g][m];

         cout << " ";
         if (m != 2)
            cout << "|";
      }
      cout << endl;

      if (g != 2)
         cout << "---+---+---\n";
   }
   return;
}

/**********************************************************************
* writeFile will write the board to a file.
***********************************************************************/
void writeFile(char fileWrite[], char grid [][3])
{
   ofstream fout;

   fout.open(fileWrite);
   if (fout.fail())
   {
      cout << "Output file opening failed. \n";
   }
   else
      cout << "File written" << endl;

   for (int g = 0; g < 3; g++)
   {
      for (int m = 0; m < 3; m++)
      {
         fout << grid[g][m] << " ";
      }
      fout << endl;
   }
   fout.close();

   return;
}

/**********************************************************************
* main will declare ticTacToe as an array, then call the other functions
* while passing ticTacToe as an array.
 ***********************************************************************/
int main()
{
   char fileOpen[256];
   char fileWrite[256];
   char grid [3][3] = {};

   getFile(fileOpen);
   readFile(fileOpen, grid);
   display(grid);
   fileToWrite(fileWrite);
   writeFile(fileWrite, grid);

   return 0;
}
