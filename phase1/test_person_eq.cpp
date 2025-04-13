
#include <iostream>
#include "person.h"

int main(){

    // Test the constructor we just implemented
    Person p1("John", "Doe", "3/15/1990", "john@usc.edu", "213-555-0123");
    cout << "Testing Person p1:" << endl;
    p1.print_person();
    cout << "----------------\n";

    // -----
    // Person c1;
    // c1.print_person();
    // cout << "----------------\n";


    // Person c2("person_template.txt");
    // c2.print_person();
    // cout << "----------------\n";

    // cout << "Is c1 equal to c2: " << (c1==c2) << endl;
    // cout << "Is c1 not equal to c2: " << (c1!=c2) << endl;

    return 0;
}