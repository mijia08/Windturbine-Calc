/*
Author: Yesenia Mejia

*/
#include <iostream>
#include <cmath>
bool getNameplateCapacity( double& n );
bool checkNameplateCapacity( double n );
bool getAndCheckWindSpeed( double& w );
double calcWattsGenerated( double nameplateCapacity, double windSpeed );
void printWattsGenerated( double watts );
using namespace std;
int main()
{

   double nameplateCapacity;   // max can be generated per day by windmill
   double windSpeed;           // average wind speed in mph per day
   bool goodInput;             // maxWatts or average windspeed error
   double watts;               // watts generated in one particular day


   // set precision for all output
   cout.setf( ios::showpoint | ios::fixed );
   cout.precision( 1 );

   // say hello and get maxWatts for the first time
   cout << "Welcome to the Wind Turbine Calculator.\n";
   while ( getNameplateCapacity( nameplateCapacity ) )
   {
      goodInput = checkNameplateCapacity( nameplateCapacity );

      // if good maxWatts
      if ( goodInput )
      {
         goodInput = getAndCheckWindSpeed( windSpeed );

         // if no error in maxWatts and windSpeed then 
         // calculate and print watts generated
         if( goodInput )
         {
            watts = calcWattsGenerated( nameplateCapacity, windSpeed );
            printWattsGenerated( watts );
         } // end if no input error in maxWatts and windSpeed
      }// end if good maxWatts
   } // end while maxWatts < 0

   cout << "Thank you for using the Wind Turbine Calculator.\n";
   return( 0 );
}
bool getNameplateCapacity( double& n )
{
    cout << "Please enter the generator’s nameplate capacity in watts (0 to end.): " << endl;
    cin >> n; 
    if(n != 0){
    return true;
    } // gives user ability to shut down calculator by inputting 'n'
    else{
    return false;
    }
}
bool checkNameplateCapacity( double n )
{
  if(n < 0){
        cout << "Nameplate capacity must be greater than zero." << endl;
        return false;
        }  // nameplate capacity cannot be 0
    else if (0 <= n && n < 300){
        cout << "Nameplate capacity must be between 300 and 8,000,000 watts." << endl;
        return false;
        }  // nameplate capacity should be between 300 and 8,000,000
    else if(n > 8000000){
        cout << "Nameplate capacity must be less than 8,000,000 watts." << endl;
        return false;
        } // nameplate capacity max is 8,000,0000
    else if (300 <= n && n <= 8000000){
        return true;
        } // allows program to continue if input meets requirement
} // if else statements are in place to ensure user is only inputting data that can be used to calculate wattage generated
bool getAndCheckWindSpeed( double& w ) 
{
    cout << "Please enter today’s average wind speed in miles per hour: " << endl;
    cin >> w; 
    if (w < 0){
        cout << "Wind speed must be greater than zero." << endl;
        return false;
    } // wind speed cannot be 0 
    else if(0 <= w && w < 6){
        cout << "Wind speed is not sufficient to power the generator." << endl; 
        return false;
    } // wind speed must be less than 6 mph.
    else if(w > 55){
        cout <<"Wind speeds too high. The turbine is not operating." << endl;
        return false;
    } // high speeds would cause the turbine to shut down in order to protect internals
    else{
        return true;
    }
} // if else statements to ensure that data that is input meets requirement for wind speed calculation

double calcWattsGenerated( double nameplateCapacity, double windSpeed )

{
    double w = windSpeed;
    double n = nameplateCapacity;
    double y;
    double a; // total wattage
    y = pow((w/25), 3); // formula needed to begin wattage calculation, formats windspeed
    a = y * n; // product of formatted windspeed in y and nameplate capacity
    return a;
}
void printWattsGenerated( double watts )
{
    double a = watts;
    string wattsUnit;
    if(1000 <= a && a < 1000000){
        a = a / 1000;
        wattsUnit = "kilowatts";
    } // to determine units needed is kw
    else if(a < 1000){
        wattsUnit = "watts";
    } // to determine units needed is w
    else{
        a = a / 1000000; 
        wattsUnit = "megawatts";
    } // to determine units needed is mw
    cout << "The wind turbine generated " << a << " " << wattsUnit << "." << endl;
} // returns wattage generated
