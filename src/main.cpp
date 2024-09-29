#include <iostream>
#include <vector>
#include <string> // for comparing strings for password
#include "../header/User.hpp"

using namespace std;

void menu();

int main() {

    vector<User> userList;  // temporarily storing users, will delete when program terminates
    char choice;

    menu();
    cin >> choice;
    while (choice < 1 || choice >3) { //input validation here for now
        cout << "Input is not valid, please enter a choice between 1-3: ";
        cin >> choice;
    }

    switch(choice) {
        case 1:
            //variables
            User User;
            string username;
            string password;
            string passCheck;
            bool validPassword = false;

            cout << "You have chosen to create an account." << endl;
            cout << "Create your username: ";
            cin >> username;

            // username validation will be done here

            cout << "Create your password: ";
            cin >> password;
            cout << "Enter password again: ";
            cin >> passCheck;
            
            while (validPassword != true) {
                // Checks if lengths are equal
                if (password.length() != passCheck.length())
                    validPassword = false;
                else    
                    validPassword = true;

                // after lengths are checked, individual characters are checked
                for(int i = 0; i < password.length(); i++){
                    if (password[i] != passCheck[i])
                        validPassword = false;
                }

                cout << "Second password does not match the first, try again." << endl;
                cout << "Create your password: ";
                cin >> password;
                cout << "Enter password again: ";
                cin >> passCheck;
            }

            User.setUserUsername(username);
            User.setUserPassword(password);

            userList.push_back(User);
            break;
        case 2:
            cout << "hey mamas" << endl;
            break;
        default:
            cout << "Exiting login." << endl;
    }
}

void menu() {
    cout << "Welcome to [COMPANY] Login." << endl ;
    cout << "---------------------------" << endl;
    cout << "Select an option:" << endl;
    cout << "1. Create Account" << endl;
    cout << "2. Log in" << endl;
    cout << "3. Exit" << endl;
    cout << "Enter choice by typing 1-3: ";
}