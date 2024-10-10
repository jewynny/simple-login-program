#include "../header/User.hpp"

//GETTER FUNCTOINS
string User::getUserUsername() {
    return username;}

string User::getUserPassword() {
    return password;}

string User::getUserBirthDate() {
    return birthDate;}

string User::getUserBirthYear() {
    return birthYear;}

string User::getUserBirthMonth() {
    return birthMonth;}


//SETTER FUNCTIONS
void User::setUserUsername(string username) {
    this->username = username;} // class username = inputted username

void User::setUserPassword(string password) {
    this->password = password;}

void User::setUserBirthDate(string birthDate) {
    this->birthDate = birthDate;}

void User::setUserBirthYear(string birthYear) {
    this->birthYear = birthYear;}

void User::setUserBirthMonth(string birthMonth) {
    this->birthMonth = birthMonth;}
