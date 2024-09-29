#include "../header/User.hpp"

//GETTER FUNCTOINS
string User::getUserUsername() {
    return username;}

string User::getUserPassword() {
    return password;}

int User::getuserBirthDate() {
    return birthDate;}

int User::getUserBirthYear() {
    return birthYear;}

Month User::getUserBirthMonth() {
    return birthMonth;}


//SETTER FUNCTIONS
void User::setUserUsername(string username) {
    this->username = username;} // class username = inputted username

void User::setUserPassword(string password) {
    this->password = password;}

void User::setuserBirthDate(int birthDate) {
    this->birthDate = birthDate;}

void User::setUserBirthYear(int birthYear) {
    this->birthYear = birthYear;}

void User::setUserBirthMonth(Month birthMonth) {
    this->birthMonth = birthMonth;}
