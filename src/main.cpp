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
    while (choice < '1' || choice > '3') { //input validation here for now
        cout << "Input is not valid, please enter a choice between 1-3: ";
        cin >> choice;
    }
    while (choice != '3') {
        switch(choice) {
            case '1': {
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

                //checks if passwords are valid
                if (password == passCheck)
                        validPassword = true;
                    else
                        validPassword = false;

                // password is not valid, enter validation
                while (validPassword != true) {
                    cout << "Second password does not match the first, try again." << endl;
                    cout << "Create your password: ";
                    cin >> password;
                    cout << "Enter password again: ";
                    cin >> passCheck;

                    if (password == passCheck)
                        validPassword = true;
                    else
                        validPassword = false;
                }

                User.setUserUsername(username);
                User.setUserPassword(password);

                userList.push_back(User);
                break;
            }
            case '2': {

                string username;
                string password;
                bool userExists = false;
                int userPos;

                cout << "To login, enter username: ";
                cin >> username;

                //check if that username exists
                for (int i = 0; i < static_cast<int>(userList.size()); i++) {
                    if (userList.at(i).getUserUsername() == username) {
                        userExists = true;
                        userPos = i;
                    }
                    else
                        userExists = false;
                }

                if (userExists != true) {
                    cout << "Sorry, the username you have provided does not exist!" << endl;
                    cout << "You are not able to log in at this time." << endl;
                }
                else {
                    cout << "Enter password: ";
                    cin >> password;
                    if (userList.at(userPos).getUserPassword() != password)
                        cout << "Incorrect password, you are not able to log in at this time." << endl;
                    else  
                        cout << "Correct password, you are now logged in." << endl;
                }

                break;
            }
            default: {
                cout << "Exiting login." << endl;
                break;
            }
        }
        // Call menu again to see if user would still like to use the program
        menu();
        cin >> choice;
        while (choice < '1' || choice > '3') { //input validation here for now
            cout << "Input is not valid, please enter a choice between 1-3: ";
            cin >> choice;
        }
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