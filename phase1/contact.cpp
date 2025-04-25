
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
    cin >> type;
    cout << "Enter email address: ";
    cin >> email_addr;
}


string Email::get_contact(string style){
    // default argument in declaration and not in definition
    if (style=="full") {
	    return "(" + type + ") " + email_addr;
    }
    else {
        return email_addr;
    }
}

void Email::print(){
	// Note: get_contact is called with default argument
	cout << get_contact() << endl;
}

// --------------------

Phone::Phone(string type, string num){
    // TODO: It is possible that num includes "-" or not, manage it!
    // TODO: Complete this method!
    // Note: We don't want to use C++11! stoi is not valid!
    this->type = type;

    string digits = ""; // cleared set of digits first
    for (char c : num) {
        if (isdigit(c)) {
            digits += c;
        }
    }
    // format with dashes if we have at least 10 digits
    if (digits.length() >= 10) {
        phone_num = digits.substr(0, 3) + "-" + 
                   digits.substr(3, 3) + "-" + 
                   digits.substr(6);
    } else {
        // otherwise, just use whatever digits we have
        phone_num = digits;
    }
}


void Phone::set_contact(){
    // TODO: Complete this method
    // Use the same prompts as given!
	cout <<"Enter the type of phone number: ";
    cin >> type;
	cout << "Enter the phone number: ";
    string num;
    cin >> num;

    // Note: same code as constructor Phone::Phone(string type, string num)
    // clear phone_num and extract only the digits
    phone_num = "";
    string digits = "";
    for (char c : num) {
        if (isdigit(c)) {
            digits += c;
        }
    }
    // format with dashes if we have at least 10 digits
    if (digits.length() >= 10) {
        phone_num = digits.substr(0, 3) + "-" + 
                   digits.substr(3, 3) + "-" + 
                   digits.substr(6);
    } else {
        // otherwise, use whatever digits we have
        phone_num = digits;
    }
}


string Phone::get_contact(string style){
    // TODO: Complete this method, get hint from Email 
    if (style=="full"){
	    return "(" + type + ") " + phone_num;
    }
    else {    
        return phone_num; 
    }
}

void Phone::print(){
    // Note: get_contact is called with default argument
	cout << get_contact() << endl;
}

