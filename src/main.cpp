#include <iostream>
#include <vector>
#include <string> // for comparing strings for password
#include "../header/User.hpp"

using namespace std;

//functions

void menu();
char choiceValidation(char choice);
string createPassword();
bool validPassword(string password, string passcheck);

int main() {

    //variables
    vector<User> userList;  // temporarily storing users, will delete when program terminates
    char choice;

    menu();
    cin >> choice;
    choice = choiceValidation(choice);
    cout << endl;

    while (choice != '3') {
        switch(choice) {
            case '1': {
                //temp variables
                User User;
                string username;

                string birthMonth;
                string birthDate;
                string birthYear;

                // create username
                cout << "You have chosen to create an account." << endl;
                cout << "---------------------------" << endl;
                cout << "Create your username: ";
                cin >> username;

                // username validation will be done here

                // create password
                password = createPassword();

                //add DOB
                cout << "Enter your date of birth:" << endl;
                cout << "---------------------------" << endl;
                cout << "Enter your birth month using 1-12: "
                cin.ignore();
                getline(cin, birthmonth);
                while (birthMonth < "1" || birthMonth > "12") { //input validation here for now
                    cout << "Input is not valid, please enter a choice between 1-12: ";
                    getline(cin, birthMonth);
                }

                cout << "Enter your birth date using 1-31: ";
                getline(cin, birthDate);
                while (birthDate < '1' || birthDate > '31') { //input validation here for now
                    cout << "Input is not valid, please enter a choice between 1-12: ";
                    getline(cin, birthDate);
                }

                cout << "Enter your birth year using a four digit number: ";
                getline(cin, birthYear);
                while (birthYear < '1000' || birthYear > '3000') { //input validation here for now
                    cout << "Input is not valid, please enter a choice between 1-12: ";
                    getline(cin, birthYear);
                }


                User.setUserUsername(username);
                User.setUserPassword(password);
                User.setuserBirthDate(birthDate);
                User.setuserBirthMonth(birthMonth);
                User.setuserBirthYear(birthYear);

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
        choice = choiceValidation(choice);
    }
}

void menu() {
    cout << "Welcome to [COMPANY] Login." << endl ;
    cout << "---------------------------" << endl;
    cout << "Select an option:" << endl;
    cout << "1. Create Account" << endl;
    cout << "2. Log in" << endl;
    cout << "3. Exit" << endl;
    cout << "---------------------------" << endl;
    cout << "Enter choice by typing 1-3: ";
}

char choiceValidation(char choice) {
    while (choice < '1' || choice > '3') { //input validation here for now
        cout << "Input is not valid, please enter a choice between 1-3: ";
        cin >> choice;
    }
    return choice;
}

bool validPassword(string password, string passcheck) {
    if (password == passCheck)
        return true;
    else
        return false;
}

string createPassword() {
    string password;
    string passCheck;
    bool validPassword = false;

    cout << "Create your password: ";
    cin >> password;
    cout << "Enter password again: ";
    cin >> passCheck;

    //checks if passwords are valid
    validPassword = validPassword(password, passcheck); //CALLIING FUNCTION FROM ANOTHER FUNCTION

    // password is not valid, enter validation
    while (validPassword != true) {
        cout << "Second password does not match the first, try again." << endl;
        cout << "Create your password: ";
        cin >> password;
        cout << "Enter password again: ";
        cin >> passCheck;

        validPassword = validPassword(password, passcheck);
    }

    cout << "You have created a valid password." << endl;
    
    return password;
}