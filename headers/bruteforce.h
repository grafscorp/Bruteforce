#pragma once

#include <iostream>
#include <ctime>
//This class has static func "bruteforce" use it
class Bruteforce 
{
public:
    //That function returned founded password or empty string, you must pass a link to a function that returns a Boolean data type to which password options are passed
    static std::string bruteforce(
        bool (*pass_func)(std::string),
        unsigned max_password_size = 4, int max_try = 5,
        const bool digitals = true,const bool letters = true,const  bool caps_letters =true, 
        const  bool special_characters= true,const  bool spaces = true, bool isLogging = false);
    
private:
    //add characters from X to Y ACII-code 
    static void addCharacters(int *&availableCharacters, int *availableCharactersSize, int first_char, int last_char);
    //print all array available characters 
    static void printAvailableCharacters(int *&availableCharacters, int *availableCharactersSize);
    //generated random chars to pass, from characters 
    static void generatedPasswordRandom(char* pass, int maxSize, int*& characters, int* availableCharactersSize);
};