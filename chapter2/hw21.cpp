
/***********************************************************************
* Program:
*    Assignment 21, Debugging
*    Brother Comeau, CS124
* Author:
*    Derek Anderson
* Summary:
*    This assignment will not have function headers for each function. This
     will practice creating stub functions.
*
*    Estimated:  1.0 hrs
*    Actual:     1.0 hrs
*      Please describe briefly what was the most difficult part.
************************************************************************/

#include <iostream>
using namespace std;

float getPeriodicCost(float devalue, float insurance, float parking)
{
   return 0.0;
}

float getUsageCost(float mileage, float gas, float repairs, float tires)
{
   return 0.0;
}

void display(float getUsageCost, float getPeriodicCost)
{
   cout << "Success\n";

   return;
}

float promptDevalue()
{
   return 0.0;
}
float promptInsurance()
{
   return 0.0;
}

float promptParking()
{
   return 0.0;
}

float promptMileage()
{
   return 0.0;
}

float promptGas()
{
   return 0.0;
}

float promptRepairs()
{
   return 0.0;
}

float promptTires()
{
   return 0.0;
}

int main()
{
   float devalue = promptDevalue();
   float insurance = promptInsurance();
   float parking = promptParking();
   float mileage = promptMileage();
   float gas = promptGas();
   float repairs = promptRepairs();
   float tires = promptTires();

   float costUsage = getUsageCost(mileage, gas, repairs, tires);
   float costPeriodic = getPeriodicCost(devalue, insurance, parking);

   display(costUsage, costPeriodic);

   return 0.0;
}
