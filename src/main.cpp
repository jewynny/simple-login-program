#include <iostream>
#include <vector>
#include <string> // for comparing strings for password
#include <fstream> // read and write to file
#include <sstream>
#include "../header/User.hpp"

using namespace std;

//functions

void menu();
char choiceValidation(char choice);
string createPassword();
bool validPassword(string password, string passcheck);
string encrypt(string password);
void readCSV(ifstream& input, vector<User> userList);
void writeCSV(ofstream& output, User newUser);

int main() {

    //variables
    vector<User> userList;  // temporarily storing users, will delete when program terminates
    char choice;

    //load in data from csv file
    ifstream csvFileRead;   // open csv file for reading
    csvFileRead.open("users.csv");
    readCSV(csvFileRead, userList);

    // Check if the file is open, file validation <3
    if (!csvFileRead.is_open()) {
        cerr << "Error opening file!" << endl;
        return 1; // Exit with an error code
    }
    
    csvFileRead.close(); // Close file! we're done reading in existing users

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
                string password;
                string encryptedPassword;

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
                encryptedPassword = encrypt(password);

                //add DOB
                cout << "Enter your date of birth:" << endl;
                cout << "---------------------------" << endl;
                cout << "Enter your birth month using 1-12: ";
                cin.ignore();
                getline(cin, birthMonth);
                while (birthMonth < "1" || birthMonth > "12") { //input validation here for now
                    cout << "Input is not valid, please enter a choice between 1-12: ";
                    getline(cin, birthMonth);
                }

                cout << "Enter your birth date using 1-31: ";
                getline(cin, birthDate);
                while (birthDate < "1" || birthDate > "31") { //input validation here for now
                    cout << "Input is not valid, please enter a choice between 1-12: ";
                    getline(cin, birthDate);
                }

                cout << "Enter your birth year using a four digit number: ";
                getline(cin, birthYear);
                while (birthYear < "1000" || birthYear > "3000") { //input validation here for now
                    cout << "Input is not valid, please enter a choice between 1-12: ";
                    getline(cin, birthYear);
                }


                User.setUserUsername(username);
                User.setUserPassword(encryptedPassword);
                User.setUserBirthDate(birthDate);
                User.setUserBirthMonth(birthMonth);
                User.setUserBirthYear(birthYear);

                userList.push_back(User);   // so that user log is saved to program immediately

                // write to file here

                //open csv file to write into:
                ofstream csvFile("users.csv", ios::app); // append mode to not overwrite data in file
                // Check if the file is open, file validation <3
                if (!csvFile.is_open()) {
                    cerr << "Error opening file!" << endl;
                    return 1; // Exit with an error code
                }

                writeCSV(csvFile, User); // write to file!
                
                csvFile.close(); // Close file! we're done writing in existing users

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
    if (password == passcheck)
        return true;
    else
        return false;
}

string createPassword() {
    string password;
    string passCheck;
    bool validPasswordBool = false;

    cout << "Create your password: ";
    cin >> password;
    cout << "Enter password again: ";
    cin >> passCheck;

    //checks if passwords are valid
    validPasswordBool = validPassword(password, passCheck); //CALLIING FUNCTION FROM ANOTHER FUNCTION

    // password is not valid, enter validation
    while (validPasswordBool != true) {
        cout << "Second password does not match the first, try again." << endl;
        cout << "Create your password: ";
        cin >> password;
        cout << "Enter password again: ";
        cin >> passCheck;

        validPasswordBool = validPassword(password, passCheck);
    }

    cout << "You have created a valid password." << endl;
    
    return password;
}

string encrypt(string password) {
    //intialize empty string
    string encryptedPass(password.size(), ' ');
    int shift = 2;  // can change this value

    for (int i = 0; i < password.size(); ++i) {
        if (isalpha(password[i]))
        {
        	// if letter is capital, base used for shifting is A likewise for lowercase
            char base = islower(password[i]) ? 'a' : 'A'; 
            // shift and wrap with alphabet for simple caeser cipher :)
            encryptedPass[i] = (password[i] - base + shift) % 26 + base;
        } 
        else
        {
        	// skipping over special characters, only encrypting the alphabet
            encryptedPass[i] = password[i];
        }
    }
    return encryptedPass;
}

void readCSV(ifstream& input, vector<User> userList) 
{
    string line;
   // Skip Header Of CSV File
    getline(input, line);

    while (getline(input, line)) 
    {
        stringstream in(line);
        string username, password, birthMonth, birthYear, birthDate;
        getline(in, username, ',');
        getline(in, password, ',');
        getline(in, birthMonth, ',');
        getline(in, birthYear, ',');
        getline(in, birthDate);

        // initialize user object
        User newUser;
        newUser.setUserUsername(username);
        newUser.setUserPassword(password);
        newUser.setUserBirthDate(birthDate);
        newUser.setUserBirthMonth(birthMonth);
        newUser.setUserBirthYear(birthYear);
        
        // push into vector of users
        userList.push_back(newUser);
    }
}

void writeCSV(ofstream& output, User newUser) {
    output << newUser.getUserUsername() << ",";
    output << newUser.getUserPassword() << ",";
    output << newUser.getUserBirthDate() << ",";
    output << newUser.getUserBirthMonth() << ",";
    output << newUser.getUserBirthYear() << "\n";
}