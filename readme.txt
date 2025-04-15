Cedar Rose Leach
6063811438
cdleach@usc.edu
Grishma Shukla 
8028101818
grishmas@usc.edu
Katherine Zhou 
---
@usc.edu


EE355 Final Project

* PHASE 1 *
In phase 1, we 


## File Overview
# File --> Purpose
contact.cpp & contact.h --> Defines `Contact` abstract class + `Email`, 'Phone'
date.cpp & date.h --> `Date` class with conversion & comparison
misc.cpp/.h --> Prints banners and other utility output
person.cpp/.h --> `Person` class definition and file parsing
network.cpp/.h --> `Network` class as a doubly-linked list of `Person`
networkDB.txt --> Sample database with multiple people
person_template.txt --> Example file for loading a single person
test_network.cpp --> Main interactive driver with CLI menu
test_person_eq.cpp --> Unit test for `==` and `!=` operators on `Person`

We used the material learned in lectures and past labs, as well as online websites like Geeks for Geeks, in order to achieve all tasks from Phase 1. I used claude to help me remove the "-" from the phone number and it taught me to write: val.erase(remove(val.begin(), val.end(), '-'), val.end());
