/***********************************************************************
* Program:
*    Project 1, Monthly Budget
*    Brother Comeau, CS124
* Author:
*    Derek Anderson
* Summary:
*    The program will manage personal finances for a month. The program
     will receive the budget income and expenditures from the user, then
     how much the user actually made. A report of the user's financial
     report will then be displayed.
*
*    Estimated:  3.0 hrs
*    Actual:     2.5 hrs
*      There were two difficulties that I had for the project. The first
       was making sure the formatting of the math was correct when computing
       multiple values together. If the code wasn't formatted correctly, the
       math would not add up when the values were displayed back to the user.
       The second part I had difficulty with was making sure the display
       table was properly aligned.
************************************************************************/

#include <iostream>
#include <iomanip>
using namespace std;

/**********************************************************************
 * getIncome prompts the user for their monthly income
 ***********************************************************************/
double getIncome()
{
   double income;

   cout << "\tYour monthly income: ";
   cin >> income;

   return income;
}

/**********************************************************************
 * getBudgetLiving prompts user for their projected living expense
 ***********************************************************************/
double getBudgetLiving()
{
   double living;

   cout << "\tYour budgeted living expenses: ";
   cin >> living;

   return living;
}

/**********************************************************************
 * getActualTax prompts user for taxes withheld
 ***********************************************************************/
double getActualTax()
{
   double tax;

   cout << "\tYour actual taxes withheld: ";
   cin >> tax;

   return tax;
}

/**********************************************************************
 * getActualTithing prompts for tithing actually withheld
 ***********************************************************************/
double getActualTithing()
{
   double tithe;

   cout << "\tYour actual tithe offerings: ";
   cin >> tithe;

   return tithe;
}

/**********************************************************************
 * getActualLiving prompts user for actual living expenses
 ***********************************************************************/
double getActualLiving()
{
   double actualLiving;

   cout << "\tYour actual living expenses: ";
   cin >> actualLiving;

   return actualLiving;
}

/**********************************************************************
 * getActualOther prompts user for other expenses
 ***********************************************************************/
double getActualOther()
{
   double other;

   cout << "\tYour actual other expenses: ";
   cin >> other;

   return other;
}

/**********************************************************************
 * computeTax determines tax bracket based on given monthly income
 ***********************************************************************/
double computeTax(double income)
{
   double incomeYearly = income * 12.0;
   double taxYearly;

   if (incomeYearly < 15100.00)
      taxYearly = incomeYearly * 0.10;

   else if (incomeYearly < 61300.00)
     taxYearly = (incomeYearly - 15100.00) * 0.15 + 1510.00;

   else if (incomeYearly < 123700.00)
      taxYearly = (incomeYearly - 61300.00) * 0.25 + 8400.00;

   else if (incomeYearly < 188450.00)
      taxYearly = (incomeYearly - 123700.00) * 0.28 + 24040.00;

   else if (incomeYearly < 336550.00)
      taxYearly = (incomeYearly - 188450.00) * 0.33 + 42170.00;

   else
      taxYearly = (incomeYearly - 336550.00) * 0.35 + 91043.00;

   double taxMonthly = taxYearly / 12.0;

   return taxMonthly;
}

/**********************************************************************
 * computeTithing determines tithing amount to give to the Lord
 ***********************************************************************/
double computeTithing(double income)
{
   return income * 0.10;
}

/**********************************************************************
 * display will show the results on the screen
 ***********************************************************************/
void display(double income, double budgetLiving, double actualTax,
             double actualTithing, double actualLiving, double actualOther)
{
   cout.setf(ios::fixed);
   cout.setf(ios::showpoint);
   cout.precision(2);

   double budgetTax = computeTax(income);
   double budgetTithing = computeTithing(income);
   double budgetOther = income - budgetLiving - budgetTax - budgetTithing;
   double actualTotal = income - actualLiving - actualTax - actualTithing -
      actualOther;
   double budgetTotal = 0.00;

   cout << endl;
   cout << "The following is a report on your monthly expenses\n";
   cout << "\tItem                  Budget          Actual\n";
   cout << "\t=============== =============== ===============\n";
   cout << "\tIncome          $" << setw(11) << income << "    $"
        << setw(11) << income << endl;
   cout << "\tTaxes           $" << setw(11) << budgetTax << "    $"
        << setw(11) << actualTax << endl;
   cout << "\tTithing         $" << setw(11) << budgetTithing << "    $"
        << setw(11) << actualTithing << endl;
   cout << "\tLiving          $" << setw(11) << budgetLiving << "    $"
        << setw(11) << actualLiving << endl;
   cout << "\tOther           $" << setw(11) << budgetOther << "    $"
        << setw(11) << actualOther << endl;
   cout << "\t=============== =============== ===============\n";
   cout << "\tDifference      $" << setw(11) << budgetTotal << "    $"
        << setw(11) << actualTotal << endl;

   return;
}

/**********************************************************************
 * main keeps track of personal finances and display the results to the
 * user
 ***********************************************************************/
int main()
{
   cout << "This program keeps track of your monthly budget\n";
   cout << "Please enter the following:\n";

   double income = getIncome();
   double budgetLiving = getBudgetLiving();
   double actualLiving = getActualLiving();
   double actualTax = getActualTax();
   double actualTithing = getActualTithing();
   double actualOther = getActualOther();

   display(income, budgetLiving, actualTax, actualTithing, actualLiving,
           actualOther);

   return 0;
}
