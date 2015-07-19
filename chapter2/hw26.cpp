/***********************************************************************
* Program:
*    Assignment 26, Files
*    Brother Comeau, CS124
* Author:
*    Derek Anderson
* Summary:
*    The program will read from a file and display the results. In this
     program, the program will read from a file that has 10 grades in it
     and display the average.
*
*    Estimated:  2.0 hrs
*    Actual:     5.0 hrs
*      The most difficult part of the assignment was calculating the
       average of the data in the file.
************************************************************************/

#include <iostream>
#include <fstream>
#include <stdlib.h>
using namespace std;

/**********************************************************************
 * getFileName will prompt user for file name.
***********************************************************************/
void getFileName(char fileName[])
{
   ofstream fout;

   cout << "Please enter the filename: ";
   cin >> fileName;

   fout.open(fileName);
}

/**********************************************************************
 * readfile will read data from file.
***********************************************************************/
float readFile(char fileName[])
{
   cout.setf(ios::fixed);
   cout.precision(0);

   ifstream fin(fileName);
   if (fin.fail())
   {
      cout << "Error reading file \"" << fileName << "\"" << endl;
      exit(0);
   }

   float data;
   float count = 0;
   float sum = 0;
   float average;
   
   while (fin >> data)
   {
      sum += data;
      ++count;
   }

   if (count != 10)
   {
      cout << "Error reading file \"" << fileName << "\"" << endl;
      exit(0);
   }

   average = sum / count;

   fin.close();

   return average;
}

/**********************************************************************
 * display will display the average from file.
***********************************************************************/
void display(float average)
{
   cout << "Average Grade: " << average << "%" << endl;
}

/**********************************************************************
 * main will call the functions getFileName, readFile, and display.
***********************************************************************/
int main()
{
   char fileName[256];

   getFileName(fileName);
   float average = readFile(fileName);
   display(average);

   return 0;
}
