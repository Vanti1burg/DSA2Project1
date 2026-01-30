#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include "fileReader.hpp"
#include "hash.hpp"
using namespace std;


// this is the inner mechanisms of the file reader class, it is the messiest object in this project but it was the 
//most reworked as I figuring out the project requirements and functionality.
// for our purposes it does it's job well.



//FileReader constructor that reads names from the names.txt file, make the passwords for each name and then writes userid and password
//in pairs to the rawPasswords.txt file. It then reads that file and encrypts the passwords using a vignere cipher with 
//the key "passwords" and writes the id's and names to encryptedPasswords.txt

FileReader::FileReader(string fileName){
    
    //this sets the seed for random password generator

     srand(time(0));

            outFile.open("rawPasswords.txt");

            if(!outFile) {

            cerr << "Unable to open file rawPasswords.txt";
            exit(1);


            }

        nameFile.open("names.txt");

         if(!nameFile) {

             cerr << "Unable to open file names.txt";
             exit(1);

         }   


        while(!nameFile.eof()) {

            string name;
            string nameExtract;
            string password = "";


            getline(nameFile, name);
            istringstream ss(name);

            ss >> nameExtract;


           //generates 9 letter lowercase password

            for (int i=0; i<9; i++) {
                char randomChar = 'a' + rand() % 26;
                password+= randomChar;

             }

        
           //writes name and password to rawPasswords.txt

            outFile << nameExtract << " " << password << endl;  

     }

    nameFile.close();


    //this opens a new txt document for the encrypted passwords

    encOutFile.open("encryptedPasswords.txt");

            if(!encOutFile) {

            cerr << "Unable to open file encryptedPasswords.txt";
            exit(1);


            }

    //this opens the rawDataFile to read for the encryption process

    rawDataFile.open("rawPasswords.txt");

            if(!rawDataFile) {

            cout << "Unable to open file rawPasswords.txt";
            exit(1);

            }

    
//this is the encryption process that takes password and encyptes it char by char using the cipher key and shifting the ascii values
//then writes the encrypted password to the encryptedPasswords.txt file along with the userid

    while(!rawDataFile.eof()) {

        string nameFromFile;
        string passwordFromFile;

        rawDataFile >> nameFromFile >> passwordFromFile;
        encOutFile << nameFromFile <<" ";

        string encryptedPassword="";
        
        for (int j=0; j<passwordFromFile.size(); j++) {
          
            char encryptedChar= ((passwordFromFile.at(j)-'a')+ (cipherKey.at(j)-'a')) %26 + 'a';
            encryptedPassword+= encryptedChar;

        }

        encOutFile << encryptedPassword << endl;
        userTable.insert(nameFromFile, passwordFromFile, encryptedPassword);

        
    }



    rawDataFile.close();
    encOutFile.close();
  
    outFile.close();
    

  

    }

//this returns the hashtable for debugging purposes

HashTable FileReader:: getUserTable() {

    return userTable;

}


//This is the tester function that reads from rawPasswords.txt and compares to the data stored in the hashtable after a decryption process
void FileReader:: Tester(string testFileName){

    cout << "Starting Tester Function" <<endl;


    ifstream testfile;
    testfile.open(testFileName);

    if(!testfile) {

        cerr << "Unable to open file " << testFileName;
        exit(1);

    }
    //The project description only called for the 1st, 3rd, 5th, 7th, and 9th entries be tested so that what the if statement is for.

    for (int i=0; i<9; i++){

        if (i==0||i==2||i==4||i==6||i==8) {
           
        
            string testName;
            string passWord;
            string hashName;
            string hashPassword;
            string hashEncPassword;

            testfile >> testName >> passWord;
            hashName= userTable.getName(testName);
            hashEncPassword= userTable.getEncryptedPassword(testName);

        //the code above retrieves the data and sets it on a local varaible and the process below decrypts the encrypted password

        for (int j=0; j<hashEncPassword.size(); j++) {

            char unencryptedChar= ((hashEncPassword.at(j)-'a') - (cipherKey.at(j)-'a') +26) %26 + 'a';
            hashPassword+= unencryptedChar;

        }

        cout<<"Testing user: " << testName << endl;
        cout<<"Test password: " << passWord << endl;
       

        if (hashName== testName && hashPassword == passWord) {

            cout<<"Test Passed for user: " << testName <<" File Password : "<< passWord<<  " Decrypted Hash Password : " << hashPassword<<endl;
            cout<<endl;

        }

        else {

            cout<<"Test Failed for user: " <<  testName << " File Password : "<< passWord<<  " Decrypted Hash Password : " << hashPassword <<endl;
            cout<<endl;
        }

    }
    }
    
}




// This does the exact same thing as the Tester function but intentionally modifies a character in the decryption to force a fail,
//so you know i didnt just make it always pass  
//                                               O^_^O

void FileReader::FailTester(string testFileName){

cout<<"Starting Fail Tester FunctionS"<<endl;
ifstream testfile;

    testfile.open(testFileName);

    if(!testfile) {

        cerr << "Unable to open file " << testFileName;
        exit(1);

    }

    for (int i=0; i<9; i++){

        if (i==0||i==2||i==4||i==6||i==8) {
           
        
        string testName;
        string passWord;
        string hashName;
        string hashPassword;
        string hashEncPassword;

        testfile >> testName >> passWord;
        hashName= userTable.getName(testName);
        hashEncPassword= userTable.getEncryptedPassword(testName);

        for (int j=0; j<hashEncPassword.size(); j++) {

            char unencryptedChar= ((hashEncPassword.at(j)-'a') - (cipherKey.at(j)-'a') +26) %26 + 'a';
            hashPassword+= unencryptedChar;


        }

        cout<<"Testing user: " << testName << endl;
        cout<<"Test password: " << passWord << endl;

     
        hashPassword.at(3)='z'; //intentionally fail the test by changing one character

        if (hashName== testName && hashPassword == passWord) {

            cout<<"Test Passed for user: " << testName <<" File Password : "<< passWord<<  " Decrypted Hash Password : " << hashPassword<< endl;
            cout<<endl;

        }

        else {

            cout<<"Test Failed for user: " << testName <<" File Password : "<< passWord<<  " Decrypted Hash Password : " << hashPassword<< endl;
            cout<<endl;

        }


    }
    }

  

}