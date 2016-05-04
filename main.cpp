#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include "sorting.h"

using namespace std;

int main() {
    inventory inven; // Making inven instance of inventory
    
    inven.menu();
    while (true) {
        string title = "";
        string amount = "";
        string input = "";
        cin>>input;
        cin.ignore(1000, '\n');
        if (input == "?") {
            inven.menu();
        }
        if (input == "1") {
            inven.read_file();
            cout<<"File read."<<endl;
        }
        if (input == "2") {
            inven.print_list();
        }
        if (input == "3") {
            cout<<"What is your ingredient name:"<<endl;
            getline(cin,title);
            if (inven.find(title) == true) {
                ing * node = inven.find_node(title);
                cout<<"Ingredient "<<node -> title<<" has "<<node -> quantity<<" ingredients"<<endl;
            }
            else
                cout<<"Could not find "<<title<<endl;
        }
        if (input == "4") {
            cout<<"What ingredient do you want to insert in the inventory?"<<endl;
            getline(cin,title);
            cout<<"What is the quantity of the ingredient?"<<endl;
            getline(cin,amount);
            istringstream buffer(amount);
            int value;
            buffer >> value;
            inven.insert(title,value);
        }
        if (input == "5") {
            cout<<"What ingredient do you want to use in the inventory?"<<endl;
            getline(cin,title);
            cout<<"How much are you going to use of that ingredient?"<<endl;
            getline(cin,amount);
            istringstream buffer(amount);
            int value;
            buffer >> value;
            inven.use(title,value);
        }
        if (input == "6") {
            cout<<"What ingredient do you want to remove from your inventory?"<<endl;
            getline(cin,title);
            inven.delete_from_list(title);
        }
        if (input == "7") {
            cout<<"Removing all ingredients from your inventory...."<<endl;
            inven.new_list();
        }
        if (input == "8") {
            inven.operation_menu();
            while (true) {
                string sub_input = "";
                string sub_amount = "";
                cin>>sub_input;
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                if (sub_input == "?") {
                    inven.operation_menu();
                }
                if (sub_input == "1") {
                    cout<<"Add a value to all ingredients:"<<endl;
                    getline(cin,sub_amount);
                    istringstream buffer(sub_amount);
                    int value;
                    buffer >> value;
                    inven.plus_all(value);
                }
                if (sub_input == "2") {
                    cout<<"Multiply a value to all ingredients:"<<endl;
                    getline(cin,sub_amount);
                    istringstream buffer(sub_amount);
                    int value;
                    buffer >> value;
                    inven.mult_all(value);
                }
                if (sub_input == "3") {
                    cout<<"Divied a value to all ingredients:"<<endl;
                    getline(cin,sub_amount);
                    istringstream buffer(sub_amount);
                    int value;
                    buffer >> value;
                    inven.div_all(value);
                }
                if (sub_input == "4") {
                    inven.total_count();
                }
                if (sub_input == "5") {
                    cout<<"Going back to main menu..."<<endl;
                    inven.menu();
                    break;
                }
            }
        }
        if (input == "9") {
            cout<<"Saving ingredients to file...."<<endl;
            inven.write_file();
            cout<<"Good Bye!"<<endl;
            break;
        }
        
    }
    
    
    
    /*
    //inven.write_file();
    //inven.key_maker("aaaa");
    inven.insert("abc",5);
    inven.insert("abc",6);
    inven.insert("acb",6);
    inven.insert("bca",14);
    inven.insert("ab",1);
    inven.insert("ba",13);
    //inven.print_list();
   // inven.write_file();
    //inven.read_file();
    inven.write_file();
    //inven.print_list();
  //  inven.find("acb");
   // ing * x = inven.find_node("acb");
   // cout<<x -> title<<endl;
    inven.use("acb",2);
   // inven.delete_from_list("acb");
   // inven.new_list();
    //inven.insert("meow",10);
    inven.plus_all(5);
    inven.print_list();
    inven.total_count();
     */
    
    return 0;
}
