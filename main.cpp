#include <iostream>
#include <fstream>
#include <ostream>
#include <ctime>
#include <sstream>
#include <vector>
#include <string>


using namespace std;

struct node {
    string name;
    string pword;
    string encPword;
    node* next;
};

int main() {


    vector<string> nameList{};
    vector<string> passwordList{};
    vector<string> encryptedPasswordList{};

    string cipherKey= "passwords";

     srand(time(0));
    ifstream nameFile;

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
        nameList.push_back(nameExtract);
        for (int i=0; i<8; i++) {
            char randomChar = 'a' + rand() % 26;
            password+= randomChar;
        }
        passwordList.push_back(password);    
    }

    nameFile.close();


   for (int i = 0; i < nameList.size(); i++) {
        cout << nameList[i] <<endl;
    }


    cout<<nameList[0]<<endl;
    cout<<nameList.size()<<endl;

    string password;
    for (int i=0; i<8; i++) {
        char randomChar = 'a' + rand() % 26;
        password += randomChar;
    }
    cout<<password<<endl;
    cout<<passwordList[0]<<endl;    
    cout<<passwordList.size()<<endl;


    for (int i = 0; i < passwordList.size(); i++) {

        string encryptedPassword="";

        for (int j=0; j<passwordList[i].size(); j++) {
          
          cout<<"will do later"<<endl;

        }
        cout<<encryptedPassword<<endl;
        encryptedPasswordList.push_back(encryptedPassword);
        
    }
    cout<<passwordList[0]<<endl;
    char cipherChar= ((passwordList[0].at(0)-'a')+ (cipherKey.at(0)-'a')) %26 + 'a';
    cout<<cipherChar<<endl;
    return 0;
}
