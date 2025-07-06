#pragma once
#include <iostream>
#include <fstream>
using namespace std;



class Date
{
    int year, month, day;
    public:
    
    Date():year(0),month(0),day(0){}

    int leap_year(){                       // this is to check whether the the given year is a leap year or not.
    if((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
       return 1;
    return 0;
    }
 

    void change_date(int Year, int Month, int Day) {
        year = Year;
        month = Month;
        day = Day;
    }

    int invalid_date(){                    // this function is for checking the validity of the date.

    return year < 1 || year > 2023 || month< 1 || month> 12 || day < 1 || day > 31 ||
    (month==2 && day > 29)||
    (!leap_year() && month == 2 && day > 28);
    }



    void add_date(){                         ///creates the date of the new member      
        
        
        cout<< "Enter date of birth(yy/mm/dd): ";
        cin >> year >> month >> day;
        fflush(stdin);
        
        

        while(invalid_date())
        {  
            cout<< "Invalid Date, Please enter the date again: ";
            cin.clear();
            cin >> year >> month  >> day ;
            fflush(stdin);
           
        }

    }

    void show(){
        cout << "Date of Birth: " << year << "/" << month << "/" << day << endl;
    }

    void save_to_file(ofstream& outFile) {
    outFile << year << "/" << month << "/" << day << ",";
    }
    

    
};