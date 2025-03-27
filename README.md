# Password Strength Checker
Evaluates the strength of passwords based on:
* Password length
* Character variety
    * Uppercase letters
    * Lowercase letters
    * Special Characters
    * Numbers
* Use of consecutive duplicate characters

Returns a strength from WEAK - VERY STRONG for valid passwords, or an informative
invalid password return.


## Installation
Requires a C++ compiler

### Clone the Repository
`git clone https://github.com/yourusername/password-checker.git`,
`cd password-checker`

### Compile the Program
`g++ -o pwdChecker main.cpp passwordChecker.cpp`

### Run the Program
`./pwdChecker`

## Usage
`Enter your password: `
`H39*drw8?`
`Password strength is: VERY STRONG`

## Limitations
* This program does NOT encrypt passwords or store them securely. It is only for strength evaluation purposes.
* The password checker does not handle Unicode passwords- it only supports ASCII characters.
* Some passwords may still be insecure despite receiving a high score.

## Responsible Use
This tool is intended for educational purposes only.
Do not use this tool for password cracking, hacking, or for any malicious activities.

## License
This project is licensed under the MIT license
