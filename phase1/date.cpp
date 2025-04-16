#include "date.h"
// constructor
Date::Date() {
    formatted_date = "";
    original_date = "";
}
// constructor with string
// Date::Date(string formatted_date) {
//     this->formatted_date = formatted_date;
// }
Date::Date(string date_str) {
    original_date = date_str;
    formatted_date = convert_date(date_str);
}
// destructor
Date::~Date() { }

string Date::convert_date(string date_bad_format) {
    // Store the original format
    original_date = date_bad_format;
    
    // --- split the date into the correct format ---
    // find positions of the "/"
    size_t first = date_bad_format.find('/');
    size_t second = date_bad_format.find('/', first + 1); // search for the second after the first
    
    // Check if we found both '/' characters
    if (first == string::npos || second == string::npos) {
        return "Invalid Date Format";
    }
    
    try {
        // extract the M, D, Y
        int month = stoi(date_bad_format.substr(0,first)); // convert to int
        int day = stoi(date_bad_format.substr(first + 1, second - first - 1)); // convert to int
        int year = stoi(date_bad_format.substr(second + 1)); // convert to int
        
        
        // Format the original date as MM/DD/YYYY
        string month_str = (month < 10) ? "0" + to_string(month) : to_string(month);
        string day_str = (day < 10) ? "0" + to_string(day) : to_string(day);
        string year_str = to_string(year);
        original_date = month_str + "/" + day_str + "/" + year_str;
        
        string proper_month;

        switch(month) {
            case 1:
                proper_month = "January";
                break;
            case 2:
                proper_month = "February";
                break;
            case 3:
                proper_month = "March";
                break;
            case 4:
                proper_month = "April";
                break;
            case 5:
                proper_month = "May";
                break;
            case 6:
                proper_month = "June";
                break;
            case 7:
                proper_month = "July";
                break;
            case 8:
                proper_month = "August";
                break;
            case 9:
                proper_month = "September";
                break;
            case 10:
                proper_month = "October";
                break;
            case 11:
                proper_month = "November";
                break;
            case 12:
                proper_month = "December";
                break;
            default:
                proper_month = "Invalid Month";
                break;
        }
        string final_date = proper_month + " " + to_string(day) + ", " + to_string(year);
        return final_date;
    } catch (const std::invalid_argument& e) {
        return "Invalid Date Format";
    } catch (const std::out_of_range& e) {
        return "Date Values Out of Range";
    }
}

void Date::print_date(string format) {
    if(format == "Month D, YYYY") { 
        // do nothing for now
        cout << formatted_date << endl;
    }
}

bool Date::operator==(const Date& rhs)
{
    if (formatted_date == rhs.formatted_date)
        return true;
    return false;
}
bool Date::operator!=(const Date& rhs)
{
    return !(*this == rhs);
}