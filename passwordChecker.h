#ifndef PASSWORDCHECKER_H
#define PASSWORDCHECKER_H
/**
 * Password Strength Checker
 * 
 * Tests the strength of a password based on:
 *  1) Password length
 *  2) Character variety
 *  3) Avoidance of duplicate consecutive characters
 * 
 * then, assigns the password a strength:
 *  WEAK, MODERATE, STRONG, and VERY_STRONG
 * for valid passwords.
 * 
 * INVALID_LENGTH, INVALID_VARIETY, INVALID_DUPLICATE_COUNT
 * for invalid passwords.
 * 
 * Author: Sue Nielson
 * Date: February 20, 2025
 */
#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

class PasswordChecker
{
    private:
        /**
         * Scores the password based on length
         * 
         * @param password - the password to score
         * @return An integer score between 0 - 20
         */
        int scoreLength(const string& password);

        /**
         * Scores the password based on character variety.
         * 
         * Looks for:
         *  1) Uppercase letters
         *  2) Lowercase letters
         *  3) Special characters
         *  4) Numbers
         * 
         * 
         * @param password - the password to score
         * @return An integer score between 0 - 25
         */
        int scoreCharacterVariety(const string& password);

        /**
         * Scores the password based on usage of consecutive duplicate characters.abs
         * 
         * Removes 2 points for each consecutive duplicate character. Score returned
         * can be negative if enough points are lost. Max score is 20.
         * 
         * @param password - the password to score
         * @return An integer score
         */
        int scoreUseOfDuplicateConsecutiveCharacters(const string& password);

        /**
         * Determines if the given character is one of the following symbols:
         *  !@$%^&*+#~
         * 
         * @param c - the character to evaluate
         * @return true if it is a special character, false if not
         */
        bool isSpecialCharacter(const char& c);

    public:
        /**
         * Represents the different password strengths.
         * 
         * INVALID_LENGTH : password does not meet length requirements
         * INVALID_VARIETY : password does not contain the required types of characters
         * INVALID_DUPLICATE_COUNT : password contains too many duplicate consecutive characters
         * WEAK : easy to guess, not every secure
         * MODERATE : better than weak, but still ot very secure
         * STRONG : secure password with good character variety and length
         * VERY_STRONG : very secure password excelling in all strength criteria
         */
        enum class Strength
            {
                INVALID_LENGTH,
                INVALID_VARIETY,
                INVALID_DUPLICATE_COUNT,
                WEAK,
                MODERATE,
                STRONG,
                VERY_STRONG
            };

        /**
         * Constructs a PasswordChecker object.
         */
        PasswordChecker();

        /**
         * Evaluates the strength of the given password.
         * 
         * @param password - the password to evaluate
         * @return Strength - the strength of the password
         */
        Strength checkPasswordStrength(const string& password);
};
#endif