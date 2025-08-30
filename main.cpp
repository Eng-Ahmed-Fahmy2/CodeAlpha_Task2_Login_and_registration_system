#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void registerUser(){
    string user, pass;
    cout << "Enter username: "; cin >> user;
    cout << "Enter password: "; cin >> pass;

    ofstream file(user + ".txt");
    file << user << endl << pass;
    file.close();

    cout << "Registration successful!\n";
}

bool loginUser(){
    string user, pass, u, p;
    cout << "Enter username: "; cin >> user;
    cout << "Enter password: "; cin >> pass;

    ifstream file(user + ".txt");
    if(file.is_open()){
        getline(file, u);
        getline(file, p);
        file.close();
        if(u == user && p == pass){
            cout << "Login successful!\n";
            return true;
        }
    }
    cout << "Invalid username or password.\n";
    return false;
}

int main(){
    int choice;
    cout << "1. Register\n2. Login\nChoice: ";
    cin >> choice;

    if(choice == 1) registerUser();
    else if(choice == 2) loginUser();
    else cout << "Invalid choice!\n";
}
