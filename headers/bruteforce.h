#pragma once

#include <iostream>
#include <ctime>

enum BRUTEFORCE_TYPE{
    RANDOM = 0,
    LINEAR
};

//This class has static func "bruteforce" use it
class Bruteforce 
{
public:
    Bruteforce(
        unsigned maxPasswordSize, int maxTry,
        const bool digitals ,const bool letters ,const  bool caps_letters , 
        const  bool special_characters,const  bool spaces);
    Bruteforce();
    ~Bruteforce();
    void setLogging(const bool);
    //That function returned founded password or empty string, you must pass a link to a function that returns a Boolean data type to which password options are passed
    std::string bruteforce(
        bool (*pass_func)(std::string),
        const BRUTEFORCE_TYPE
        );
    
protected:
    unsigned int maxPasswordSize = 3;
    int maxTry = 30;
    bool digitals = true; 
    bool letters = true;
    bool caps_letters = true;
    bool special_characters = false;
    bool spaces = false;
    bool isLogging = false;
    //add characters from X to Y ACII-code 
    void addCharacters(int *&availableCharacters, int *availableCharactersSize, int first_char, int last_char);
    void addCharacter(int *&availableCharacters, int *availableCharactersSize, int first_char);
    //print all array available characters 
    void printAvailableCharacters(int *&availableCharacters, int *availableCharactersSize);
    //generated random chars to pass, from characters 
    std::string generatedPasswordRandom( bool (*pass_func)(std::string), int*& characters, int* availableCharactersSize);
    std::string generatedPasswordLinear( bool (*pass_func)(std::string),int*& characters, int* availableCharactersSize);
    void generateLinearPasswords(int *&characters, int *availableCharactersSize,std::string *tempPasswords,std::string *tempPassword,unsigned indexChar);

};