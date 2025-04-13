
#include "contact.h"
#include "ctype.h"
#include <iostream>
#include <string>
using namespace std;
// TODO: Add needed libraries! 

Email::Email(string type, string email_addr){
    // TODO: Complete me!
    this->type = type; 
    // this->type refers to the protected "type" variable from Contact class in contact.h
    this->email_addr = email_addr;
}


void Email::set_contact(){
    // TODO: Do not change the prompts!
	
    cout << "Enter the type of email address: ";
    // some code here
    cin >> type;
    cout << "Enter email address: ";
    // some code here
    cin >> email_addr;
}


string Email::get_contact(string style){
    // Note: We have default argument in declaration and not in definition!
    if (style=="full")
	    return "(" + type + ") " + email_addr;
    else 
        return email_addr;
}


void Email::print(){
    // Note: get_contact is called with default argument
	cout << get_contact() << endl;
}

//////////////////////////////////////////////////////////////////////////////////////////////////
Phone::Phone(string type, string num){
    // TODO: It is possible that num includes "-" or not, manage it!
    // TODO: Complete this method!
    // Note: We don't want to use C++11! stoi is not valid!
    this->type = type;

    phone_num = ""; // clear string first
    
    int count = 0;
    for (char c : num)
    {
        // Only adding them if they are digits
        if (isdigit(c))
        {
            phone_num += c;
            count++;
        }
        if (count == 3 || count == 6)
            phone_num += '-';
    }
    cout << endl << "TYPE = " << this->type << endl;
    cout << endl << "phone_num = " << this->phone_num << endl << endl;
}


void Phone::set_contact(){
    // TODO: Complete this method
    // Use the same prompts as given!
	cout <<"Enter the type of phone number: ";
    cin >> type;
	cout << "Enter the phone number: ";
    string num;
    cin >> num;

    // Only entering phone number without dashes
    // Note: same code as constructor Phone::Phone(string type, string num)
    int count = 0;
    for (char c : num)
    {
        // Only adding them if they are digits
        if (isdigit(c))
        {
            phone_num += c;
            count++;
        }
        if (count == 3 || count == 6)
            phone_num += '-';
    }
}


string Phone::get_contact(string style){
    // TODO: Complete this method, get hint from Email 
    if (style=="full")
	    return "(" + type + ") " + phone_num;
    else 
        return phone_num;
}


void Phone::print(){
    // Note: get_contact is called with default argument
	cout << get_contact() << endl;
}

