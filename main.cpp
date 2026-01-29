#include <iostream>
#include <fstream>
#include <ostream>
#include <ctime>
#include <sstream>
#include <vector>
#include <string>
#include "fileReader.hpp"
#include "hash.hpp"



using namespace std;

//Main function that establishes a FilReader object (which reads and processes the file contents into other txt files and hashtable)
//Then calls the tester and failtester functions to test the class functionality and the hashtable
//Since this is a project that requires no user interations it is quite simple to look at.

int main() {

    FileReader fr("names.txt");
    fr.Tester("rawPasswords.txt");
    fr.FailTester("rawPasswords.txt");
    cout<<"File processing completed."<<endl;
    return 0;

}
