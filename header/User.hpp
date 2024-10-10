#ifndef USER_HPP
#define USER_HPP
#include <iostream>

using namespace std;

enum Month{ JANUARY, FEBRUARY, MARCH, APRIL, MAY, JUNE, JULY, AUGUST, SEPTEMBER, OCTOBER, NOVEMBER, DECEMBER};

class User {
    public: 
    // enum Month{JANUARY, FEBRUARY, MARCH, APRIL, MAY, JUNE, JULY, AUGUST, SEPTEMBER, OCTOBER, NOVEMBER, DECEMBER};
    // void getUserChoice(char userChoice);

    string getUserUsername();
    string getUserPassword();
    string getUserBirthDate();
    string getUserBirthYear();
    string getUserBirthMonth();

    void setUserUsername(string username);
    void setUserPassword(string password);
    void setUserBirthDate(string birthDate);
    void setUserBirthYear(string birthYear);
    void setUserBirthMonth(string birthMonth);
    
    private:
    char userChoice;
    string username; // will be used for lookup when logging in

    // for if there are age rstrictions
    string password; // not encrypted
    string birthMonth;
    string birthDate;
    string birthYear;


};

#endif  //USER_HPP