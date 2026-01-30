/***************************************************************
  Student Name:Trenton Peterson
  File Name: FileReader.hpp
  Assignment number DSA 2 Project 1

  Header File for FileReader Class where all declarations are stored 
***************************************************************/




#ifndef FILEREADER_HPP
#define FILEREADER_HPP
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include "hash.hpp"

using namespace std;


//This is the FileReader class, it has 4 methods, a constructor, hashtable return, and two testing methods that will be important
//for the validating the functinoality of the project

class FileReader {
    private:

    //Not the most inspired cipher key but it works for this project + the inclusion of 'a' in the second character
    //lets me check if the cipher works as 'a' as the cipher key makes the original password return the encrypted character 
    //for that index to the same character.

        ifstream nameFile;
        ofstream outFile;
        ofstream encOutFile;
       
        istringstream ss;
        string cipherKey= "passwords";
        HashTable userTable{1500};
        ifstream rawDataFile;

    //I believe some of these if and of streams are not necessary but i left them as they work as identifiers for when i look at the code


    public:


        FileReader(string fileName);
        HashTable getUserTable();
        void Tester(string testFileName);
        void FailTester(string testFileName);
        
           
};


#endif
