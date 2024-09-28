#ifndef USER_HPP
#define USER_HPP
#include <iostream>

using namespace std;

class User {
    public: 
    enum Month{JANUARY, FEBRUARY, MARCH, APRIL, MAY, JUNE, JULY, AUGUST, SEPTEMBER, OCTOBER, NOVEMBER, DECEMBER};
    void getUserChoice(char userChoice);
    
    private:
    char userChoice;
    string userName; // will be used for lookup when logging in

    // for if there are age rstrictions
    string password; // not encrypted
    Month birthMonth;
    int birthDate;
    int birthYear;


};

#endif  //USER_HPP