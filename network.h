#ifndef NETWORK_H
#define NETWORK_H

#include "person.h"
#include "date.h"
#include <stdlib.h>
#include <dirent.h>
#include <fstream>
#include <string>
using namespace std;

class Network{
    private:
        Person* head;
        Person* tail;
        int count; 
        Person* search(Person* searchEntry);
        Person* search(string fname, string lname);
        void loadDB(string filename);
        void saveDB(string filename);

    public:
        Network();
        Network(string fileName);
        ~Network();
        void printDB();
        void push_front(Person* newEntry);
        void push_back(Person* newEntry);
        bool remove(string fname, string lname);
        void showMenu();
};

#endif