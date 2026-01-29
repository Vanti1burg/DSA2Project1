#ifndef HASH_HPP
#define HASH_HPP
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <fstream>
using namespace std;

//hash table class the uses open addressing with linked lists to handle collisions


class HashTable {


    private :

    //node structure that is the beating hear of our linked lists 

    struct node {
            string name;
            string pword;
            string encPword;
            node* next;
        };
        
        vector<node*> table;
        int tableSize;
        int hashFunction(const string& key);


    public:
    
        //Hashtable constructor, insertion function, view function (for debugging), node data retrieval functions

        HashTable(int size);
        void insert(const string& name, const string& pword, const string& encPword);
        void view();
        void getNodeContents(const string& name);    
        string getEncryptedPassword(const string& name);
        string getName(string& name);
        
             
};

#endif