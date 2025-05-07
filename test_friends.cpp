#include <iostream>
#include "person.h"

int main() {
    // Create three people
    Person p1("Alice", "Smith", "1/1/1990", "(Work) alice@work.com", "(Home) 123-456-7890");
    Person p2("Bob", "Jones", "2/2/1991", "(Work) bob@work.com", "(Home) 234-567-8901");
    Person p3("Charlie", "Brown", "3/3/1992", "(Work) charlie@work.com", "(Home) 345-678-9012");
    Person p4("Grishma", "Shukla", "3/3/1992", "(Work) charlie@work.com", "(Home) 345-678-9012");
    Person p5("Gorilla", "Anna", "3/3/1992", "(Work) charlie@work.com", "(Home) 345-678-9012");
    Person p6("Charlotte", "Chang", "3/3/1992", "(Work) charlie@work.com", "(Home) 345-678-9012");
    Person p7("Grassma", "Shukla", "3/3/1992", "(Work) charlie@work.com", "(Home) 345-678-9012");

    // Make them friends
    p1.makeFriend(&p2);
    p1.makeFriend(&p3);
    p1.makeFriend(&p4);
    p1.makeFriend(&p5);
    p1.makeFriend(&p6);
    p1.makeFriend(&p7);

    // Print p1's friends
    cout << "Alice's friends:\n";
    p1.print_friends();

    return 0;
} 