#include <iostream>
#include <string>

using namespace std;


// Making ing the short name to ingredient because I will use the struct ing a lot
struct ing {
    string title; // The name of the ingredient
    int quantity; // The quantity of the ingredient
    bool root = false; // If this is false that means there is no link list or its a node connected to the root
    ing * next = NULL;
    ing * prev = NULL;
    ing() {};
    ing(string in_title, int in_quantity) {
        title = in_title;
        quantity = in_quantity;
    }
};


// This class I will call inventory becuase it keeps track of the ingredients
class inventory {
public:
    inventory(); // Defining ing in array
    ~inventory(); // De-allocate the memory
    int key_maker(string title); // Makes keys for the hash table
    void read_file(); // Read a file
    void write_file(); // Writes a file
    void insert(string title, int amount); // insert this ingredient if it finds same ingredient it sums it
    void print_list(); // Prints all ingredients in the list
    bool find(string title); // Find if the ingredient is in you inventory
    ing * find_node(string title); // Returns the node it found
    void use(string title, int amount); // use an amount of ingredients can go to zero
    void delete_from_list(string title); // Get rid the ingredient
    void new_list(); // Get rid of all ingredients; make a new list
    void plus_all(int value); // add all ingredients with a value
    void mult_all(int value); // mutiply all ingredients with a value
    void div_all(int value); // divied all ingredients with a value
    void total_count(); // Count the total number of ingredients
    void menu(); // Prints an amazing menu
    void operation_menu(); // A sub menu for operations (+ * / sum)
    ing* list[30]; // Contains the ingredient data
    int list_size = 30; // Size of the hash table
};