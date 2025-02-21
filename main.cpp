#include <iostream>
#include <string>
#include "passwordChecker.h"

using std::cout;
using std::cin;
using std::endl;
using std::string;

int main()
{   
    PasswordChecker checker;
    string password;

    cout << "Enter a password: " << endl;
    cin >> password;


    PasswordChecker::Strength strength = checker.checkPasswordStrength(password);

    string strengthString;
    switch (strength)
    {
        case PasswordChecker::Strength::INVALID_LENGTH: strengthString = "Your password must be at least 8 characters"; break;
        case PasswordChecker::Strength::INVALID_VARIETY: strengthString = 
            "Your password must include at least one uppercase letter, one lowercase letter, one number, and one special character"; break;
        case PasswordChecker::Strength::INVALID_DUPLICATE_COUNT: strengthString = 
            "Your password contains too many repeated characters in a row. Try adding more variety!"; break;
        case PasswordChecker::Strength::WEAK: strengthString = "WEAK"; break;
        case PasswordChecker::Strength::MODERATE: strengthString = "MODERATE"; break;
        case PasswordChecker::Strength::STRONG: strengthString = "STRONG"; break;
        case PasswordChecker::Strength::VERY_STRONG: strengthString = "VERY STRONG"; break;
    }

    cout << ((strength >= PasswordChecker::Strength::WEAK) ? "Password strength is: " + strengthString : strengthString) << endl;
    return 0;
}