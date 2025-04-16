#ifndef DATE_H
#define DATE_H

#include <string>
#include <iostream>
#include "contact.h"
#include <fstream>

using namespace std;

class Date { 
    private:
        string formatted_date;
        string original_date;  // Store the original M/D/YYYY format for main menu class
    public:
        Date();
        Date(string date_str); 
        ~Date();
        string convert_date(string date_bad_format);
        void print_date(string format);
        string get_date() const { return formatted_date;} // getter for the formatted date
        string get_original_date() const { return original_date;} // getter for the original date (for main menu class)
        bool operator==(const Date& rhs);
        bool operator!=(const Date& rhs);
}; 

#endif