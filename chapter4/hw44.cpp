/***********************************************************************
* Program:
*    Assignment 44, Search Speed
*    Brother Comeau, CS124
* Author:
*    Derek Anderson
* Summary:
*    This program will determine speed of a linear versus a binary search
     in a file.
*
*    Estimated:  2.0 hrs
*    Actual:     1.0 hrs
*      The most difficult part of the assignment was properly passing
       the correct references into the linear and binary functions.
************************************************************************/

#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

int readNumbers(int numbers[], int max);
float computeAverageLinear(int numbers[], int size);
float computeAverageBinary(int numbers[], int size);
int linear(int numbers[], int size, int search);
int binary(int numbers[], int size, int search);

/**********************************************************************
 * main reads the list, determines speed of searches, and outputs the
 * results.
 ***********************************************************************/
int main()
{
   int numbers[1024];
   const int MAX = sizeof (numbers) / sizeof (numbers[0]);
   int size;

   if (!(size = readNumbers(numbers, MAX)))
      return 1;

   float averageLinear;
   averageLinear = computeAverageLinear(numbers, size);

   float averageBinary;
   averageBinary = computeAverageBinary(numbers, size);

   cout.setf(ios::fixed);
   cout.setf(ios::showpoint);
   cout.precision(1);
   cout << "Linear search: " << setw(10) << averageLinear << endl;
   cout << "Binary search: " << setw(10) << averageBinary << endl;

   return 0;
}

/**********************************************************************
 * readNumbers prompts user for filename to search the size of the numbers
 * in the file.
 ***********************************************************************/
int readNumbers (int numbers[], int max)
{
   char fileName[256];
   int size = 0;

   cout << "Enter filename of list: ";
   cin >> fileName;

   ifstream fin(fileName);
   if (fin.fail())
   {
      cout << "Unable to open file " << fileName << endl;
      return 0;
   }

   while (size < max && fin >> numbers[size])
      size++;

   fin.close();
   return size;

}

/**********************************************************************
 * computeAverageLinear determines how quickly each item is found in the
 * array in a linear search.
 ***********************************************************************/
float computeAverageLinear(int numbers[], int size)
{
   float averageLinear = 0.0;

   for (int i = 0; i < size; i++)
      averageLinear += linear(numbers, size, numbers[i]);

   return averageLinear / size;
}

/**********************************************************************
 * computeAverageLinear determines how quickly each item is found in the
 * array in a binary search.
 ***********************************************************************/
float computeAverageBinary(int numbers[], int size)
{
   float averageBinary = 0.0;

   for (int i = 0; i < size; i++)
      averageBinary += binary(numbers, size, numbers[i]);

   return averageBinary / size;
}

/**********************************************************************
 * linear searches through the number array and returns the number of
 * compares.
 ***********************************************************************/
int linear(int numbers[], int size, int search)
{
   bool found = false;
   int compares = 0;

   for (int i = 0; i < size && ! found; i++)
   {
      compares++;
      if (search == numbers[i])
         found = true;
   }

   return compares;
}

/**********************************************************************
 * binary searches through the number array and returns the number of
 * compares.
 ***********************************************************************/
int binary(int numbers[], int size, int search)
{
   bool found = false;
   int compares = 0;

   int iFirst = 0;
   int iLast = size - 1;

   while (iLast >= iFirst && !found)
   {
      compares++;

      int iMiddle = (iLast + iFirst) / 2;

      if (numbers [iMiddle] == search)
         found = true;
      else if (numbers[iMiddle] > search)
         iLast = iMiddle - 1;
      else
         iFirst = iMiddle + 1;
   }
   return compares;
}
