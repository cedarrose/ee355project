#include "person.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include "misc.h"
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
    this->code_name = codeName(f_name, l_name);

    birthdate = new Date(b_date);

    // extract the type from the  the email string to extract type and address
    size_t email_start = email_str.find('(');
    size_t email_end = email_str.find(')');
    string email_type, email_addr;
    
    if (email_start != string::npos && email_end != string::npos) {
        email_type = email_str.substr(email_start + 1, email_end - email_start - 1);
        email_addr = email_str.substr(email_end + 1); // +1 to skip ")"
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
        phone_num = phone_str.substr(phone_end + 1); // +1 to skip ")"
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

    this->code_name = codeName(f_name, l_name);

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
        val.erase(std::remove(val.begin(), val.end(), '-'), val.end()); // remove dashes
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


// Updated in phase 2
void Person::print_person(){
    // Already implemented for you! Do not change!
	cout << l_name <<", " << f_name << endl;
	birthdate->print_date("Month D, YYYY");
    cout << "Email: ";
    email->print();
    cout << "Phone: ";
    phone->print();
    // Added in phase 2
    // cout << endl << endl <<"Printing friends: " << endl << endl;
    for (auto friend_ptr : myfriends) {
        // cout << codeName(friend_ptr->f_name, friend_ptr->l_name) << " ";
        cout << friend_ptr->code_name << " ";
        cout << "(" << friend_ptr->f_name << " " << friend_ptr->l_name << ")" << endl;
    }
}

// Added in phase 2
void Person::print_friends(){
    vector<Person*> sorted_friends;
    
    // First friend goes directly into the vector
    if (!myfriends.empty()) {
        sorted_friends.push_back(myfriends[0]);
    }
    
    int count;
    for (auto friend_ptr : myfriends)
    {
        count = 0;
        while (!myfriends.empty() && count < sorted_friends.size() && friend_ptr->f_name[0] >= sorted_friends[count]->f_name[0])
        {
            // If first letter is equal, check the second letter
            if (friend_ptr->f_name[0] == sorted_friends[count]->f_name[0])
            {
                // Sort based on second letter. friend_ptr should be before sorted_friends[count]
                if (friend_ptr->f_name.length() > 1 && sorted_friends[count]->f_name.length() > 1 
                    && friend_ptr->f_name[1] > sorted_friends[count]->f_name[1])
                {
                    count++;
                }
                break;
            }
            else
            {
                count ++;
            }
        }
        sorted_friends.insert(sorted_friends.begin() + count, friend_ptr);
    }
        
    // Insert remaining friends in sorted order
    // for (size_t i = 1; i < myfriends.size(); i++) {
    //     Person* friend_ptr = myfriends[i];
    //     size_t insert_pos = 0;
        
    //     // Find the correct position to insert
    //     while (insert_pos < sorted_friends.size()) {
    //         // Compare first letters
    //         if (friend_ptr->f_name[0] < sorted_friends[insert_pos]->f_name[0]) {
    //             break;
    //         }
    //         // If first letters are equal, compare second letters if they exist
    //         else if (friend_ptr->f_name[0] == sorted_friends[insert_pos]->f_name[0] &&
    //                  friend_ptr->f_name.length() > 1 && 
    //                  sorted_friends[insert_pos]->f_name.length() > 1) {
    //             if (friend_ptr->f_name[1] < sorted_friends[insert_pos]->f_name[1]) {
    //                 break;
    //             }
    //         }
    //         insert_pos++;
    //     }
        
    //     // Insert at the found position
    //     sorted_friends.insert(sorted_friends.begin() + insert_pos, friend_ptr);
    // }
    
    // Print the sorted friends
    for (auto friend_ptr : sorted_friends) {
        friend_ptr->print_person();
        cout << "----------------\n";
    }
}

string Person::get_firstName(){
    return f_name;
}

string Person::get_lastName(){
    return l_name;
}

void Person::set_codeName(string codeName){
    this->code_name = codeName;
    cout << endl << "code_name in set_codeName(): " << code_name << endl << endl;
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
