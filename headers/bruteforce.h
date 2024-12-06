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
        unsigned, int max_try,
        const bool digitals ,const bool letters ,const  bool caps_letters , 
        const  bool special_characters,const  bool spaces , bool isLogging );
    
private:
    //add characters from X to Y ACII-code 
    static void addCharacters(int *&availableCharacters, int *availableCharactersSize, int first_char, int last_char);
    //print all array available characters 
    static void printAvailableCharacters(int *&availableCharacters, int *availableCharactersSize);
    //generated random chars to pass, from characters 
    static void generatedPasswordRandom(std::string *, int maxSize, int*& characters, int* availableCharactersSize);
};