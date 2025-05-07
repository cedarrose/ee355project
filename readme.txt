# Cedar Rose Leach
6063811438
cdleach@usc.edu
# Grishma Shukla 
8028101818
grishmas@usc.edu
# Katherine Zhou 
9600708711
ktzhou@usc.edu

EE355 Final Project

### PHASE 1
In phase 1, we implemented a netowrk of Contacts using user-defined Person, Contact, Email and Phone classes.
As outlined in the project guidelines, Our program allows users to enter new contacts manually, add new contacts from a file, save all current contacts in the current network to a file, as well as remove or add contacts to the network using a main menu.


## How to Compile & Run
** use c++11 **
Running program:
    $ g++ -std=c++11 test_network.cpp network.cpp person.cpp contact.cpp date.cpp misc.cpp -o network.out
    $ ./network.out

## File Overview
# File --> Purpose
contact.cpp & contact.h --> Defines `Contact` abstract class + `Email`, 'Phone'
date.cpp & date.h --> `Date` class with conversion & comparison
misc.cpp & misc.h --> Prints banners and other utility output
person.cpp & person.h --> `Person` class definition and file parsing
network.cpp & network.h --> `Network` class as a doubly-linked list of `Person`
networkDB.txt --> Sample database with multiple people
person_template.txt --> Example file for loading a single person
test_network.cpp --> Main interactive driver with CLI menu
test_person_eq.cpp --> Unit test for `==` and `!=` operators on `Person`

## Notes
Order of running the program: Add a person, Save them in a text file, then you can load, remove, print, etc. 

We used the material learned in lectures and past labs, as well as online websites like Geeks for Geeks, in order to achieve all tasks from Phase 1. I used claude for a specific line in helping me remove the "-" from the phone number and it taught me to write: val.erase(remove(val.begin(), val.end(), '-'), val.end());
For network.cpp, I used chatgpt to help with the showMenu opt==2 condition regarding creating and opening a directory.
I also used https://cplusplus.com/reference/ios/ios/eof/ to help with reading a file in network.cpp.
In date.cpp, I was having trouble with error handling and I used chatgpt to help me wrap my case statements in a try{} to catch errors with invalid dates.


## Extra Credit
Network Analysis Tool
Files to Run = network_analysis.py
In this part, we created a python file tahat processes user data from a CSV database, called network_database.csv. This program 
identifies connections between people based on common attributes (looking at: college, major, state) by reading the CSV file, storing the
information as nodes and then creating a graph of these nodes based on the common attributes in network_visualization.png.

The program uses the pandas library for data handling and networkx for network analysis, with visualization 
capabilities through matplotlib. Run using 'python network_analysis.py' after installing required 
packages from requirements.txt.

Source for Extra Credit:
For graphing the nodes - https://networkx.org/documentation/stable/reference/generated/networkx.drawing.nx_pylab.draw_networkx_edges.html
We also used ChatGPT to come up with some dummy data to populate our CSV database with our given specifications.
