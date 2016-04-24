#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include "sorting.h"

using namespace std;


inventory::inventory() {
    for (int i = 0; i < list_size; i++)
        list[i] = new ing();
}


inventory::~inventory() {
    for (int i = 0; i < list_size; i++) {
        ing * x = list[i];
        ing * y = list[i];
        // goes forward until NULL
        while (y) {
            x = y;
            y = x -> next;
        }
        // Then goes back until NULL and deletes every node
        while (x) {
            y = x;
            x = y -> prev;
            delete y;
        }
    }
}


int inventory::key_maker(string title) {
    int sum = 0;
    for (int i = 0; i < title.size(); i++)
        sum += title[i];
    return sum % list_size;
}


bool inventory::find(string title) {
    int key = key_maker(title);
    
    if (list[key] -> root == true) {
        bool found = false;
        ing * x = list[key] -> next;
        ing * y = list[key] -> next;
        while (y) {
            x = y;
            if (x -> title == title) {
                found = true;
                break;
            }
            y = x -> next;
        }
        if (found == true)
            return true;
        //cout<<"Found "<<x -> title<<" it has "<<x -> quantity<<" ingredients left"<<endl;
    }
    else
        return false;
    //cout<<title<<" could not be found!"<<endl;
    return false;
}


ing * inventory::find_node(string title) {
    int key = key_maker(title);
    ing * x = list[key] -> next;
    ing * y = list[key] -> next;
    while (y) {
        x = y;
        if (x -> title == title)
            return x;
        y = x -> next;
    }
    return NULL;
}


void inventory::insert(string title, int amount) {
    if (find(title) == false) {
        int key = key_maker(title);
        ing * newNode = new ing(title,amount);
        
        list[key] -> root = true;
        ing * x = list[key];
        ing * y = list[key];
        while (y) {
            x = y;
            y = x -> next;
        }
        x -> next = newNode;
        x -> next -> prev = x;
    }
    else {
        ing * node = find_node(title);
        node -> quantity += amount;
    }
}


void inventory::write_file() {
    ofstream myfile("inventory.txt");
    // Testing if it can write
    if (myfile.is_open()) {
        for (int i = 0; i < list_size; i++)
            if (list[i] -> root == true) {
                ing * x = list[i] -> next;
                ing * y = list[i] -> next;
                while (y) {
                    x = y;
                    myfile<<x -> title<<":"<<x -> quantity<<"\n";
                    y = x -> next;
                }
            }
        myfile.close();
    }
    // If it can't write
    else
        cout<<"This file cannot write!!! Check if this program has permission to write."<<endl;
}


void inventory::read_file() {
    string line;
    ifstream myfile ("inventory.txt");
    if (myfile.is_open()) {
        while (getline(myfile,line)) {
            string title = "";
            string quantity = "";
            bool pos = true; // True for the title and false for the quantity
            for (int i = 0; i < line.size(); i++) {
                if (line[i] == 0x3A)
                    pos = false;
                if (line[i] != 0x3A) {
                    if (pos == true)
                        title +=  line[i];
                    else
                        quantity += line[i];
                }
            }
            
            // Inputing into hash table
            istringstream buffer(quantity);
            int value;
            buffer >> value;
            insert(title, value);
        }
        myfile.close();
    }
    else
        cout<<"This file cannot read!!! Check if this program has permission to read."<<endl;
}


void inventory::print_list() {
    for (int i = 0; i < list_size; i++)
        if (list[i] -> root == true) {
            ing * x = list[i] -> next;
            ing * y = list[i] -> next;
            while (y) {
                x = y;
                cout<<"Ingredient: "<<x -> title<<" Quantity: "<<x -> quantity<<endl;
                y = x -> next;
            }
        }
}


void inventory::use(string title, int amount) {
    if (find(title) == true) {
        ing * node = find_node(title);
        if (node -> quantity - amount < 0)
            cout<<"You cannot use more ingredients then you have."<<endl;
        else {
            node -> quantity = node -> quantity - amount;
        }
    }
    else
        cout<<title<<" does not exist!"<<endl;
}


void inventory::delete_from_list(string title) {
    if (find(title) == true) {
        ing * node = find_node(title);
        if (node -> next == NULL) {
            node -> prev -> next = NULL;
            delete node;
        }
        else {
            node -> prev -> next = node -> next;
            node -> next -> prev = node -> prev;
            delete node;
        }
    }
    else
        cout<<title<<" does not exist!"<<endl;
}


void inventory::new_list() {
    for (int i = 0; i < list_size; i++) {
        ing * x = list[i];
        ing * y = list[i];
        // goes forward until NULL
        if (list[i] -> root == true) {
            while (y) {
                x = y;
                y = x -> next;
            }
            // Then goes back until NULL and deletes every node
            while (x) {
                y = x;
                x = y -> prev;
                if (y -> root == false) // Never changed the node root bool
                    delete y;
            }
            y -> next = NULL;
        }
    }
}


void inventory::plus_all(int value) {
    for (int i = 0; i < list_size; i++) {
        if (list[i] -> root == true) {
            ing * x = list[i] -> next;
            ing * y = list[i] -> next;
            while (y) {
                x = y;
                x -> quantity += value;
                y = x -> next;
            }
        }
    }
}


void inventory::mult_all(int value) {
    for (int i = 0; i < list_size; i++) {
        if (list[i] -> root == true) {
            ing * x = list[i] -> next;
            ing * y = list[i] -> next;
            while (y) {
                x = y;
                x -> quantity *= value;
                y = x -> next;
            }
        }
    }
}


void inventory::div_all(int value) {
    for (int i = 0; i < list_size; i++) {
        if (list[i] -> root == true) {
            ing * x = list[i] -> next;
            ing * y = list[i] -> next;
            while (y) {
                x = y;
                x -> quantity = x -> quantity / value;
                y = x -> next;
            }
        }
    }
}


void inventory::total_count() {
    int sum = 0;
    for (int i = 0; i < list_size; i++)
        if (list[i] -> root == true) {
            ing * x = list[i] -> next;
            ing * y = list[i] -> next;
            while (y) {
                x = y;
                sum += x -> quantity;
                y = x -> next;
            }
        }
    cout<<"The total sum of all your ingredients is: "<<sum<<endl;
}


void inventory::menu() {
    cout<<"To re-print the main menu, input ?"<<endl;
    cout<<"1. Read your ingredients file"<<endl;
    cout<<"2. Print your inventory"<<endl;
    cout<<"3. Find an ingredient in your inventory"<<endl;
    cout<<"4. Insert/Add an ingredient"<<endl;
    cout<<"5. Use x amout of an ingredient"<<endl;
    cout<<"6. Remove ingredient from inventory"<<endl;
    cout<<"7. Remove all ingredients from your list"<<endl;
    cout<<"8. Perform an operation on all your ingredients (+ * / sum)"<<endl;
    cout<<"9. Quit and save ingredients to a file"<<endl;
}


void inventory::operation_menu() {
    cout<<"To re-print the operation menu, input ?"<<endl;
    cout<<"1. Add x value to all ingredients"<<endl;
    cout<<"2. Multiply x value to all ingredients"<<endl;
    cout<<"3. Divied x value to all ingredients"<<endl;
    cout<<"4. Sum all ingredient values"<<endl;
    cout<<"5. Go back to main menu"<<endl;
    
}