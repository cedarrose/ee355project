#ifndef PERSON_H
#define PERSON_H

#include "date.h"
#include "contact.h"
#include "fstream"
#include <vector>
#include "misc.h"
class Person{
    friend class Network;

private:
	string f_name;
	string l_name;
    string code_name;
	Date *birthdate;
    Email *email;
    Phone *phone;
    // the following to attributes are used in the linked list.
    Person* next;
    Person* prev;
    // added in Phase 2:
    vector<Person*> myfriends;

public: 
    Person();
    ~Person();
    Person(string filename);
    Person(string f_name, string l_name, string b_date, string email, string phone);
    string get_firstName();
    string get_lastName();
    void set_codeName(string codeName);
	void print_person();
	void set_person();
	void set_person(string filename);
    bool operator==(const Person& rhs);
    bool operator!=(const Person& rhs);
    // added in Phase 2:
    void makeFriend(Person* newFriend);
    void print_friends();
};


#endif