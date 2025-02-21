#include <iostream>
#include <string>
#include "passwordChecker.h"

using std::cout;
using std::cin;
using std::endl;
using std::string;

PasswordChecker::PasswordChecker() {}

PasswordChecker::Strength PasswordChecker::checkPasswordStrength(const string& password)
{
    int lengthScore = scoreLength(password);
    if (lengthScore == 0)
    {
        return Strength::INVALID_LENGTH;
    }

    int varietyScore = scoreCharacterVariety(password);
    if (varietyScore == 0)
    {
        return Strength::INVALID_VARIETY;
    }

    int duplicateCountScore = scoreUseOfDuplicateConsecutiveCharacters(password);
    if (duplicateCountScore == 0)
    {
        return Strength::INVALID_DUPLICATE_COUNT;
    }

    int totalScore = lengthScore + varietyScore + duplicateCountScore;
    const int weakThreshold = 30, moderateThreshold = 40, strongThreshold = 50;

    if (totalScore <= weakThreshold) return Strength::WEAK;
    else if (totalScore <= moderateThreshold) return Strength::MODERATE;
    else if (totalScore <= strongThreshold) return Strength::STRONG;
    else return Strength::VERY_STRONG;
}

int PasswordChecker::scoreLength(const string& password)
{
    int length = password.length();
    const int invalidThreshold = 7, weakThreshold = 10, moderateThreshold = 12, strongThreshold = 15;

    if (length <= invalidThreshold) return 0;
    else if (length <= weakThreshold) return 5;
    else if (length <= moderateThreshold) return 10;
    else if (length <= strongThreshold) return 15;
    else return 20;
}

int PasswordChecker::scoreCharacterVariety(const string& password)
{
    int score = 0, lowerCaseCount = 0, upperCaseCount = 0, numberCount = 0, specialCharacterCount = 0;

    for (char c : password)
    {
        if (c >= 'a' && c <= 'z') lowerCaseCount++;
        if (c >= 'A' && c <= 'Z') upperCaseCount++;
        if (c >= '0' && c <= '9') numberCount++;
        if (isSpecialCharacter(c)) specialCharacterCount++;
    }

    if (lowerCaseCount == 0 || upperCaseCount == 0 || numberCount == 0 || specialCharacterCount == 0)
    {
        return 0;
    }
    if (lowerCaseCount > 0) score += 5;
    if (upperCaseCount > 0) score += 5;
    if (numberCount > 0) score += 5;
    if (specialCharacterCount > 0) score += 10;

    return score;
}

int PasswordChecker::scoreUseOfDuplicateConsecutiveCharacters(const string& password)
{
    int consecutiveRepeatCount = 0, score = 20, passwordLength = password.length();

    for (int i = 0; i < passwordLength - 1; i++)
    {
        if (password[i] == password[i + 1])
        {
            consecutiveRepeatCount ++;
        }
        else
        {  
            if(consecutiveRepeatCount > 0)
            {
                score -= (consecutiveRepeatCount) * 2;
                consecutiveRepeatCount = 0;
            }
        }
    }

    int countThreshold = passwordLength * 0.8;
    if (consecutiveRepeatCount >= (countThreshold))
    {
        return 0;
    }
    return score;
}

bool PasswordChecker::isSpecialCharacter(const char& c)
{
    if (c == '!' || c == '@' || c == '$' || c == '%' || c == '^' ||
    c == '&' || c == '*' || c == '+' || c == '#' || c == '~') return true;
    else return false;
}

int main(int argc, char* argv[])
{
    if (argc != 2) {
        cout << argv[0] << " Requires 1 argument: <password>\n";
        return 0;
    }

    string password = argv[1];
    PasswordChecker checker;
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
