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
    public:
        Date();
        Date(string date_str); 
        ~Date();
        string convert_date(string date_bad_format);
        void print_date(string format);
}; 

#endif