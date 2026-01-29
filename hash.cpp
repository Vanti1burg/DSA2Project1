#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include "hash.hpp"
using namespace std;

//Hashtable constructor resizes the bucket vector to the specified table size, I dont know if
//i was supposed to do this without vectors but the addressing method makes use of linked lists and nodes
//so i figured it was acceptable as i could display my proficiency with both concepts


HashTable:: HashTable(int size) {

    tableSize= size;
    table.resize(tableSize, nullptr);

}

//this is a hash function that adds the ascii values of the individual characters in the string key
//and then mods it by the table size to get an index that fits within the bounds of the table vector

int HashTable:: hashFunction(const string& key) {

    int hash = 0;
    for (char ch : key) {

        hash += static_cast<int> (ch);

    }

    return hash % tableSize;

}


//insert function that creates a new node with userid, password, and encrypted password
//uses hash function to find index and then adds to the linked list stored at that index

void HashTable:: insert(const string& name, const string& pword, const string& encPword) {

    int index = hashFunction(name);
    node* newNode = new node{name, pword, encPword, nullptr};


    if (table[index] == nullptr) {
        table[index] = newNode;

    } 
    
    else {

        node* current = table[index];
        while (current->next != nullptr) {

            current = current->next;

        }

        current->next = newNode;

    }

}


//This is a view function that displays hashtable contents, This is primarily for debugging and for anybody later working with this

void HashTable:: view() {

    for (int i = 0; i < tableSize; i++) {

        node* current = table[i];

        if (current != nullptr) {

            cout << "Index " << i << ": ";

            while (current != nullptr) {

                cout <<current->name <<endl;

                current = current->next;

            }
            cout << "nullptr" << endl;

        }
    }
}



//This is the function that finds the node with the specified name and displays its contents

void HashTable:: getNodeContents(const string& name) {

    int index = hashFunction(name);

    node* current = table[index];

    while (current != nullptr) {

        if (current->name == name) {

            cout<<"Found user: " << current->name << " with password: " << current->pword << " And Encrypted Password :"<< current->encPword<<endl;
            
            
          
        }

        current = current->next;
    }
}


//this function retrieves the encrypted password for a given username, **NOT THE UNENCRYPTED PASSWORD**,
//THIS IS SO THE FILEREADER CAN DECRYPT IT AND COMPARE IT TO THE RAW PASSWORD.

string HashTable:: getEncryptedPassword(const string& name) {

    int index = hashFunction(name);

    node* current = table[index];

    while (current != nullptr) {

        if (current->name == name) {

            return current->encPword;

        }

        current = current->next;

    }

    return "";

}


//Name getter for finding name in hashtable, works on the same basic principle as the other getters 

string HashTable:: getName(string& name) {

    int index = hashFunction(name);

    node* current = table[index];

    while (current != nullptr) {

        if (current->name == name) {

            return current->name;

        }

        current = current->next;

    }
    
    return "";
}