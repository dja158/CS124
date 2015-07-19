/***********************************************************************
* Program:
*    Project 4, Sudoku
*    Brother Comeau, CS124
* Author:
*    Derek Anderson
* Summary:
*    The program will prompt the user for the filename of the Sudoku game
     and display the board on screen. The user will interact with the game
     by selecting which square they wish to change. While the program will
     not solve the game for the user, the program will check to make sure the
     user has not selected an invalid number. When the user is done, the
     program will save the board to a given filename and exit.
*
*    Estimated:  7.0 hrs
*    Actual:     10.0 hrs
*      The most difficult part of the project was writing the board correctly
       to the destination file.
************************************************************************/

#include <iostream>
#include <fstream>
using namespace std;

string getFileRead();
string getFileWrite();
bool readFile(string filename, int sudokuBoard[][9]);
bool writeFile(string filename, int sudokuBoard[][9]);
bool interact(int sudokuBoard[][9]);
string promptPos(int sudokuBoard[][9]);
void displayHelp();
void displayBoard(int sudokuBoard[][9]);
bool computeValues(string loc, int sudokuBoard[][9], int checkVal = 0);
void editOneSquare(string pos, int sudokuBoard[][9]);

/**********************************************************************
 * main runs a game of sudoku by reading a sudoku board from a file, and
 * writing the updated board to a file when user is done playing.
 ***********************************************************************/
int main()
{
   int sudokuBoard[9][9];

   readFile(getFileRead(), sudokuBoard);
   displayHelp();
   displayBoard(sudokuBoard);

   while (interact(sudokuBoard))
   {
   }

   return 0;
}

/**********************************************************************
 * getFileRead prompts user for filename of game board to read.
 ***********************************************************************/
string getFileRead()
{
   string filename;
   cout << "Where is your board located? ";
   cin >> filename;
   return filename;
}

/**********************************************************************
 * getFileRead prompts user for filename of game board to read.
 ***********************************************************************/
string getFileWrite()
{
   string filename;
   cout << "What file would you like to write your board to: ";
   cin >> filename;
   return filename;
}

/**********************************************************************
 * readFile reads file from given filename and puts board data into a
 * multi-dimensional array.
 ***********************************************************************/
bool readFile(string filename, int sudokuBoard[][9])
{
   ifstream fin(filename.c_str());
   if (fin.fail())
      return false;

   for (int row = 0; row < 9; row++)
   {
      for (int col = 0; col < 9; col++)
      {
         fin >> sudokuBoard[row][col];
         if (fin.fail())
         {
            fin.close();
            return false;
         }
      }
   }
   fin.close();
   return true;
}

/**********************************************************************
 * writeFile writes the sudoku board data to the given filename.
 ***********************************************************************/
bool writeFile(string filename, int sudokuBoard[][9])
{
   ofstream fout(filename.c_str());
   if (fout.fail())
      return false;

   for (int row = 0; row < 9; row++)
   {
      for (int col = 0; col < 9; col++)
      {
         fout << sudokuBoard[row][col];
         if (col < 8)
            fout << " ";
      }
      fout << endl;
   }
   fout.close();
   return true;
}

/**********************************************************************
 * interact prompts user to select from a list of commands.
 ***********************************************************************/
bool interact(int sudokuBoard[][9])
{
   cout << "\n> ";
   char command;
   cin >> command;

   switch (command)
   {
      case '?':
         displayHelp();
         break;
      case 'D':
         displayBoard(sudokuBoard);
         break;
      case 'E':
         editOneSquare(promptPos(sudokuBoard), sudokuBoard);
         break;
      case 'S':
         computeValues(promptPos(sudokuBoard), sudokuBoard);
         break;
      case 'Q':
         if (writeFile(getFileWrite(), sudokuBoard))
            cout << "Board written successfully\n";
         return false;
      default:
         cout << "ERROR: Invalid command\n";
         return true;
   }
   return true;
}

/**********************************************************************
 * promptPos prompts user for coordinates of square user wants to edit.
 ***********************************************************************/
string promptPos(int sudokuBoard[][9])
{
   string pos;
   cout << "What are the coordinates of the square: ";
   cin >> pos;

   int row = pos[1] - '1';
   int col = pos[0] - (isupper(pos[0]) ? 'A' : 'a');

   if (!isalpha(pos[0]) || (!isdigit(pos[1]) || pos.length() > 2)
      || row + 1 > 9 || row + 1 < 1 || col + 1 > 9 || col + 1 < 1)
   {
      cout << "ERROR: Square '" << pos << "' is invalid\n";
      return "";
   }

   if (sudokuBoard[row][col] > 0)
   {
      cout << "ERROR: Square '" << pos << "' is filled\n";
      return "";
   }

   return pos;
}

/**********************************************************************
 * displayHelp displays list of options user can select.
 ***********************************************************************/
void displayHelp()
{
   cout << "Options:\n"
        << "   ?  Show these instructions\n"
        << "   D  Display the board\n"
        << "   E  Edit one square\n"
        << "   S  Show the possible values for a square\n"
        << "   Q  Save and Quit\n\n";
}

/**********************************************************************
 * displayBoard displays sudoku board user is currently viewing.
 ***********************************************************************/
void displayBoard(int sudokuBoard[][9])
{
   cout << "   A B C D E F G H I\n";
   for (int r = 0; r < 9; r++)
   {
      cout << (r + 1) << "  ";
      for (int c = 0; c < 9; c++)
      {
         if (sudokuBoard[r][c] != 0)
            cout << sudokuBoard[r][c];
         else
            cout << " ";
         if (c == 8)
            continue;
         cout << ((c + 1) % 3 == 0 ? '|' : ' ');
      }
      cout << endl;

      if (r != 8 && (r + 1) % 3 == 0)
         cout << "   -----+-----+-----\n";
   }
}

/**********************************************************************
 * computeValues computes possible values user can enter into a square
 * on sudoku board.
 ***********************************************************************/
bool computeValues(string loc, int sudokuBoard[][9], int checkVal)
{
   if (loc ==  "")
      return false;

   short numBooleans = 0b111111111;
   int row = loc[1] - '1';
   int col = loc[0] - (isupper(loc[0]) ? 'A' : 'a');
   int blockR = row / 3;
   int blockC = col / 3;

   for (int c = 0; c < 9; c++)
      if (sudokuBoard[row][c] > 0)
         numBooleans = numBooleans & ~(1 << (sudokuBoard[row][c] - 1));


   for (int r = 0; r < 9; r++)
      if (sudokuBoard[r][col] > 0)
         numBooleans = numBooleans & ~(1 << (sudokuBoard[r][col] - 1));

   for (int r = blockR * 3; r < blockR * 3 + 3; r++)
      for (int c = blockC * 3; c < blockC * 3 + 3; c++)
         if (sudokuBoard[r][c] > 0)
            numBooleans = numBooleans & ~(1 << (sudokuBoard[r][c] - 1));

   if (checkVal == 0)
   {
      cout << "The possible values for '" << loc << "' are: ";
      int count = 0;
      for (int i = 0; i < 9; i++)
         if (numBooleans & (1 << i))
         {
            if (count > 0)
               cout << ", ";
            cout << i + 1;
            count++;
         }
      cout << endl;
   }
   else
      return numBooleans & (1 << (checkVal - 1));

   return false;
}

/**********************************************************************
 * editOneSquare allows user to enter value into a square to complete
 * sudoku board.
 ***********************************************************************/
void editOneSquare(string pos, int sudokuBoard[][9])
{
   if (pos == "")
      return;

   int val;
   cout << "What is the value at '" << pos << "': ";
   cin >> val;

   if (val > 9 || val < 1 || !(computeValues(pos, sudokuBoard, val)))
   {
      cout << "ERROR: Value '" << val << "' in square '"
           << pos << "' is invalid\n";
      return;
   }

   int row = pos[1] - '1';
   int col = pos[0] - (isupper(pos[0]) ? 'A' : 'a');

   sudokuBoard[row][col] = val;
}
