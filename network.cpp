#include "network.h"
#include <limits>
#include "misc.h"
#include <fstream>

Network::Network(){
    head = NULL;
    tail = NULL;
    count = 0;
}


Network::Network(string fileName){
    // TODO: complete this method!
    // Implement it in one single line!
    // You may need to implement the load method before this!
    head = NULL;
    tail = NULL;
    count = 0;

    loadDB(fileName);
}

Network::~Network(){ 
    Person* current = head;
    while(current != nullptr){
        Person* temp = current;
        current = current->next;
        delete temp;
    }
    head = nullptr;
    tail = nullptr;
    count = 0;
}

Person* Network::search(Person* searchEntry){
    // Searches the Network for searchEntry
    // if found, returns a pointer to it, else returns NULL
    // TODO: Complete this method
    Person* current = head;
    while(current != nullptr){
        if(*current == *searchEntry){
            return current;
        }
        else{
            current = current->next;
        }
    }
    return nullptr;
}


Person* Network::search(string fname, string lname){
    // New == for Person, only based on fname and lname
    // if found, returns a pointer to it, else returns NULL
    // TODO: Complete this method
    // Note: two ways to implement this, 1st making a new Person with fname and lname and and using search(Person*), 2nd using fname and lname directly. 
    Person* current = head;
    while(current != nullptr){
        if((current->f_name == fname) && (current->l_name == lname)){
            return current;
        }
        else{
            current = current->next;
        }
    }
    return nullptr;
}




void Network::loadDB(string filename){
    // TODO: Complete this method
    while (head != NULL) {
        Person* temp = head;
        head = head->next;
        delete temp;
    }

    head = NULL;
    tail = NULL;
    count = 0;
    
    ifstream infile(filename);

    string fname;
    string lname;
    string bday;
    string email;
    string number;
    string dash;
    //c++ help
    if(infile.is_open()){
        while(!infile.eof()){
            getline(infile, fname);

            if(infile.eof()){
                break;
            }
            getline(infile, lname);
            getline(infile, bday);
            getline(infile, email);
            getline(infile, number);

            Person* newPerson = new Person(fname, lname, bday, email, number);
            push_back(newPerson);

            if(!infile.eof()){
                getline(infile, dash);
            }
        }
        infile.close();
    }
}

void Network::saveDB(string filename){
    // TODO: Complete this method
    ofstream outfile(filename);
    if(outfile.is_open()){
        Person* current = head;
        while(current != nullptr){
            // Save in format that loadDB expects
            outfile << current->f_name << endl;
            outfile << current->l_name << endl;
            outfile << current->birthdate->get_original_date() << endl;
            outfile << current->email->get_contact("full") << endl;
            outfile << current->phone->get_contact("full") << endl;
            outfile << "------------------------------" << endl;

            current = current->next;
        }
        outfile.close();
    }
}


void Network::printDB(){
    // Leave me alone! I know how to print! 
    // Note: Notice that we don't need to update this even after adding to Personattributes
    // This is a feature of OOP, classes are supposed to take care of themselves!
    cout << "Number of people: " << count << endl;
    cout << "------------------------------" << endl;
    Person* ptr = head;
    while(ptr != NULL){
        ptr->print_person();
        cout << "------------------------------" << endl;
        ptr = ptr->next;
    }
}



void Network::push_front(Person* newEntry){
    newEntry->prev = NULL;
    newEntry->next = head;

    if (head != NULL)
        head->prev = newEntry;
    else
        tail = newEntry;
    
    head = newEntry;
    count++;
}


void Network::push_back(Person* newEntry){
    // Adds a new Person (newEntry) to the back of LL
    // TODO: Complete this method
    if(head == nullptr){
        head = newEntry;
        tail = newEntry;
        newEntry->next = nullptr;
        newEntry->prev = nullptr;
    }else{
        tail->next = newEntry;
        newEntry->prev = tail;
        newEntry->next = nullptr;
        tail = newEntry;
    }
    count++;
}


bool Network::remove(string fname, string lname){
    // TODO: Complete this method
    Person* temp = search(fname, lname);
    if(temp == nullptr){
        return false;
    }
    //edge cases
    else{
        if((temp->prev != nullptr) && (temp->next != nullptr)){
            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;
        }
        else if((temp->prev != nullptr)){
            temp->prev->next = temp->next;
            tail = temp->prev;
        }
        else if((temp->next != nullptr)){
            temp->next->prev = temp->prev;
            head = temp->next;
        }
        else{
            head = nullptr;
            tail = nullptr;
        }
        delete temp;
        count--;
        return true;
    }
 
}


void Network::showMenu(){
    // TODO: Complete this method!
    // All the prompts are given to you, 
    // You should add code before, between and after prompts!

    int opt;
    while(1){
        cout << "\033[2J\033[1;1H";
        printMe("banner"); // from misc library
        // display menu options
        cout << "Select from below: \n";
        cout << "1. Save network database \n";
        cout << "2. Load network database \n";
        cout << "3. Add a new person \n";
        cout << "4. Remove a person \n";
        cout << "5. Print people with a specific last name \n";
        cout << "6. Connect \n";
        cout << "\nSelect an option ... ";

        // input validation/ error handling
        if (cin >> opt) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        } else {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Wrong option! " << endl;
            return;
        }
        
        // You may need these variables! Add more if you want!
        string fname, lname, fileName, bdate, email, number, temp, type;
        cout << "\033[2J\033[1;1H";

        if (opt==1){
            // TODO: Complete me!
            cout << "Saving network database \n";
            cout << "Enter the name of the save file: ";
            // Save the network database into the file with the given name,
            // with each person saved in the format the save as printing out the person info,
            // and people are delimited similar to "networkDB.txt" format
            getline(cin, fileName);
            saveDB(fileName);
            cout << "Network saved in " << fileName << endl;
        }
        else if (opt==2){
            // TODO: Complete me!
            cout << "Loading network database \n";
            // TODO: print all the files in this same directory that have "networkDB.txt" format
            // print format: one filename one line.
            // This step just shows all the available .txt file to load.
            //ai help with directory syntax
            DIR *dir;
            struct dirent *ent;
            if ((dir = opendir(".")) != NULL) {
                while ((ent = readdir(dir)) != NULL) {
                    string filename = ent->d_name;
                    if (filename.size() > 4 && 
                        filename.substr(filename.size() - 4) == ".txt") {
                        cout << filename << endl;
                    }
                }
                closedir(dir);
            }

            cout << "Enter the name of the load file: "; 
            // If file with name FILENAME does not exist: 
            getline(cin, fileName);

            ifstream fileCheck(fileName);
            if(!fileCheck.good()){
                cout << "File "<<fileName<< " does not exist!" << endl;
            }
           
            // If file is loaded successfully, also print the count of people in it: 
            else{
                fileCheck.close();
                loadDB(fileName);
                cout << "Network loaded from " << fileName << " with " << count << " people \n";
            }
        }
        else if (opt == 3){
            // TODO: Complete me!
            // TODO: use push_front, and not push_back 
            // Add a new Person ONLY if it does not exists!
            cout << "Adding a new person \n";
            cout<<"Enter first name: ";
            getline(cin, fname);
            cout<<"Enter last name: ";
            getline(cin, lname);

            if(search(fname,lname) == nullptr){
                cout << "Birthdate (M/D/YYYY): ";
                getline(cin, bdate);

                cout << "Type of email address: ";
                getline(cin, type);
                cout << "Email address: ";
                getline(cin, temp);
                email = "(" + type + ")" + temp;

                cout << "Type of phone number: ";
                getline(cin, type);
                cout << "Phone number: ";
                getline(cin, temp);
                number = "(" + type + ")"+ temp;

                Person* newPerson = new Person(fname, lname, bdate, email, number);
                push_front(newPerson);
                cout << "Person added!" << endl;
            }
            else {
                cout << "Person already exists!" << endl;
            }

        }
        else if (opt == 4){
            // TODO: Complete me!
            // if found, cout << "Remove Successful! \n";
            // if not found: cout << "Person not found! \n";
            cout << "Removing a person \n";
            cout << "First name: ";
            getline(cin, fname);
            cout << "Last name: ";
            getline(cin,lname);
            
            if(remove(fname, lname)){
                cout << "Remove Successful! \n";
            }
            else{
                cout << "Person not found! \n";
            }
        }
        else if (opt==5){
            // TODO: Complete me!
            // print the people with the given last name
            // if not found: cout << "Person not found! \n";
            cout << "Print people with last name name \n";
            cout << "Last name: ";
            getline(cin, lname);
            
            int found = 0;

            Person* current = head;

            while(current!=nullptr){
                if(current->l_name == lname){
                    current->print_person();
                    cout<<"------------------------------" << endl;
                    found = 1;
                }
                current = current->next;
            }
            if(found == 0){
                cout << "Person not found! \n";
            }
        }
        else if(opt==6){
            cout << "Make friends:" << endl;
            cout << "Person 1" << endl;
            cout << "First Name: ";
            getline(cin, fname);
            cout << "Last Name: ";
            getline(cin, lname);
            // search for the first person
            Person* p1 = search(fname, lname);
            // if they don't exist, return to main menu
            if(p1 == nullptr){
                cout << "Person not found" << endl;
            }
            // else, get other person
            else { 
                cout << "Person 2" << endl;
                cout << "First Name: ";
                getline(cin, fname);
                cout << "Last Name: ";
                getline(cin, lname);
                cout << endl;
                // search for the second person
                Person* p2 = search(fname, lname);
                // if they don't exist, return to main menu
                if(p2 == nullptr){
                cout << "\nPerson not found" << endl;
                }
                // else, print the information AND make them friends
                else {
                    // print
                    p1->print_person();
                    cout << endl;
                    p2->print_person();
                    // friendship (double sided)
                    p1->makeFriend(p2);
                    p2->makeFriend(p1);
                }
            }
        }
        
        else
            cout << "Nothing matched!\n";
        
        cin.clear();
        cout << "\n\nPress Enter key to go back to main menu ... ";
        getline (cin, temp);
        cout << "\033[2J\033[1;1H";
    }
}

