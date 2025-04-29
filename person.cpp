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
    // TODO: Complete this method! - done
    // phone and email strings are in full version
    // Storing the names directly as strings
    this->f_name = f_name;
    this->l_name = l_name;

    birthdate = new Date(b_date);

    // extract the type from the  the email string to extract type and address
    size_t email_start = email_str.find('(');
    size_t email_end = email_str.find(')');
    string email_type, email_addr;
    
    if (email_start != string::npos && email_end != string::npos) {
        email_type = email_str.substr(email_start + 1, email_end - email_start - 1);
        email_addr = email_str.substr(email_end + 2); // +2 to skip ") "
    } else {
        // fallback if format is not as expected
        email_type = "Work";
        email_addr = email_str;
    }
    email = new Email(email_type, email_addr);

    // extract the type from the  the phone string to extract type and address
    // Parse the phone string to extract type and number
    size_t phone_start = phone_str.find('(');
    size_t phone_end = phone_str.find(')');
    string phone_type, phone_num;
    
    if (phone_start != string::npos && phone_end != string::npos) {
        phone_type = phone_str.substr(phone_start + 1, phone_end - phone_start - 1);
        phone_num = phone_str.substr(phone_end + 2); // +2 to skip ") "
    } else {
        phone_type = "Home";
        phone_num = phone_str;
    }
    phone = new Phone(phone_type, phone_num);
    
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
    getline(cin,f_name);

	cout << "Last Name: ";
    getline(cin,l_name);

    cout << "Birthdate (M/D/YYYY): ";
    getline(cin,temp);
    // pay attention to how we passed argument to the constructor of a new object created dynamically using new command
    birthdate = new Date(temp); 

    cout << "Type of email address: ";
    getline(cin, type);
    cout << "Email address: ";
    getline(cin, temp);
    email = new Email(type, temp);
    cout << "Type of phone number: ";
    getline(cin, type);
    cout << "Phone number: ";
    getline(cin, temp);
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
    ifstream infile(filename);
    string line, type, val;
    // error handling
    if(!infile.is_open()) {
        cout << "Error, could not open file." << endl;
        return;
    }
    // read first line, name
    getline(infile, line);
    f_name = line;
    // Read last name
    getline(infile, line);
    l_name = line;
    // Read bday
    getline(infile, line);
    birthdate = new Date(line);

    // Read phone
    getline(infile, line);
    size_t space_pos = line.find(' ');
    space_pos = line.find(' ');
    if (space_pos != string::npos) {
        type = line.substr(1, space_pos-2);  // get first word
        val = line.substr(space_pos + 1);  // get rest of line
        val.erase(remove(val.begin(), val.end(), '-'), val.end()); // remove dashes
    }
    this->phone = new Phone(type, val);

    // Read email
    getline(infile, line);
    if (space_pos != string::npos) {
        type = line.substr(1, space_pos-2);  // get first word
        val = line.substr(space_pos + 1);  // get rest of line
    }
    this->email = new Email(type, val);

    // Initialize LL pointers
    next = nullptr;
    prev = nullptr;
    // close file
    infile.close();
}


bool Person::operator==(const Person& rhs){
    // TODO: Complete this method!
    // Note: you should check first name, last name and birthday between two persons
    // refer to bool Date::operator==(const Date& rhs)
    if (this->f_name != rhs.f_name)
        return false;
    if (this->l_name != rhs.l_name)
        return false;
    if (*(this->birthdate) != *(rhs.birthdate))
        return false;
    
    return true; //temporary
}

bool Person::operator!=(const Person& rhs){ 
    // TODO: Complete this method!
    return !(*this == rhs);
}


void Person::print_person(){
    // Already implemented for you! Do not change!
	cout << l_name <<", " << f_name << endl;
	birthdate->print_date("Month D, YYYY");
    cout << "Email: ";
    email->print();
    cout << "Phone: ";
    phone->print();
}

// Added in phase 2
void Person::makeFriend(Person* newFriend) {
    // check if the person is already a friend to avoid duplicates
    for(auto friend_ptr : myfriends) {
        if(friend_ptr == newFriend) {
            return; // already was a friend
        }
    }
    // add the friend to the vector
    myfriends.push_back(newFriend);
}
