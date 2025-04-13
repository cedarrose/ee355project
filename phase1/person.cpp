#include "person.h"
using namespace std;

Person::Person(){
    // I'm already done! 
    set_person();
}


Person::~Person(){
    // TODO: complete the method! - done
    delete birthdate;
    delete email;
    delete phone;
    
}


Person::Person(string f_name, string l_name, string b_date, string email_str, string phone_str) {
    // TODO: Complete this method! - done i think??
    // phone and email strings are in full version
    // Storing the names directly as strings
    this->f_name = f_name;
    this->l_name = l_name;

    birthdate = new Date(b_date);
    birthdate->convert_date(b_date);

    email = new Email("work", email_str);
    phone = new Phone("home", phone_str);
    
    // initializing LL pointers
    next = nullptr;
    prev = nullptr;
}

Person::Person(string filename){
    set_person(filename);
}

void Person::set_person(){
    // prompts for the information of the user from the terminal
    // first/last name can have spaces!
    // date format must be "M/D/YYYY"
    // We are sure user enters info in correct format.
    // TODO: complete this method!
    
    string temp;
    string type;

    cout << "First Name: ";
    // pay attention to how we read first name, as it can have spaces!
    std::getline(std::cin,f_name);

	cout << "Last Name: ";
    std::getline(std::cin,l_name);

    cout << "Birthdate (M/D/YYYY): ";
    std::getline(std::cin,temp);
    // pay attention to how we passed argument to the constructor of a new object created dynamically using new command
    birthdate = new Date(temp); 

    cout << "Type of email address: ";
    std::getline(std::cin, type);
    cout << "Email address: ";
    std::getline(std::cin, temp);
    email = new Email(type, temp);

    cout << "Type of phone number: ";
    std::getline(std::cin, type);
    cout << "Phone number: ";
    std::getline(std::cin, temp);
    phone = new Phone(type, temp);

    // Initialize linked list pointers
    next = nullptr;
    prev = nullptr;
}


void Person::set_person(string filename){
    // reads a Person from a file
    // Look at person_template files as examples.     
    // Phone number in files can have '-' or not.
    // TODO: Complete this method!
    

}


bool Person::operator==(const Person& rhs){
    // TODO: Complete this method!
    // Note: you should check first name, last name and birthday between two persons
    // refer to bool Date::operator==(const Date& rhs)
    if (this->f_name != rhs->f_name)
        return false;
    if (this->l_name != rhs->l_name)
        return false;
    if (this->birthdate != rhs->birthdate)
        return false;
    
    return true; //temporary
}

bool Person::operator!=(const Person& rhs){ 
    // TODO: Complete this method!
    if (this == rhs) // This line might be wrong - Grish
        return false;
    return true; //temporary
}


void Person::print_person(){
    // Already implemented for you! Do not change!
	cout << l_name <<", " << f_name << endl;
	birthdate->print_date("Month D, YYYY");
    phone->print();
    email->print();
}
