/***********************************************************************
* Program:
*    Assignment 42, Dem Bones
*    Brother Comeau, CS124
* Author:
*    Derek Anderson
* Summary:
*    This program will display the words to the song Dem Bones by
*    using the string class.
*
*    Estimated:  1.0 hrs
*    Actual:     0.75 hrs
*      The most difficult part of the assignment was implementing strings
       correctly in the for loop to generate the song.
************************************************************************/

#include <iostream>
#include <string>
using namespace std;

/********************************************************************
 * GENERATE SONG
 * This function will generate one long string that constitutes the
 * complete song "Dem Bones."  Note that the list of bones is provided
 * by the parameter list
 ********************************************************************/
string generateSong(string list[], int num)
{
   string output;
   string CTT = "connected to the ";

   for (int i = 0; i < num - 1; i++)
   {
      output +=  list[i] + " bone " + CTT + list[i + 1] + " bone\n";
   }

   return output;
}

/**********************************************************************
 * MAIN
 * In this program, MAIN is a driver program.  It will feed to generateSong()
 * the list of bones and get back the complete song as a string.  MAIN will
 * then display the song
 ***********************************************************************/
int main()
{
   string list[9] =
   {
      "toe",
         "foot",
         "leg",
         "knee",
         "hip",
         "back",
         "neck",
         "jaw",
         "head"
         };

   // generate the song
      string song = generateSong(list, 9);

   // display the results
      cout << song;

      return 0;
   }
