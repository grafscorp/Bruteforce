#include "bruteforce.h"

Bruteforce::Bruteforce(unsigned maxPasswordSize = 3, int max_try = 30, const bool digitals = true, const bool letters=true, const bool caps_letters=true, const bool special_characters=false, const bool spaces=false)
{
    this->maxPasswordSize = maxPasswordSize;
    this->maxTry = max_try;
    this->digitals = digitals; 
    this->letters =letters;
    this->caps_letters = caps_letters; 
    this->special_characters = special_characters;
    this->spaces = spaces;
}

Bruteforce::Bruteforce() {}

Bruteforce::~Bruteforce() {}

void Bruteforce::setLogging(const bool isLogging) {
    this->isLogging = isLogging;
}

std::string Bruteforce::bruteforce(bool (*pass_func)(std::string), const BRUTEFORCE_TYPE bruteforceType)
{

    int availableCharactersSize = 0;
    
    //An array containing ascii character codes
    int *availableCharacters = new int[200];

    std::string currect_password;

    int numTry = 0;



    //I add certain ASCII character codes to the list of available characters
    if (this->digitals)addCharacters(availableCharacters, &availableCharactersSize,48, 57 );
    if (this->letters) addCharacters(availableCharacters, &availableCharactersSize, 97, 122 );
    if (this->caps_letters)addCharacters(availableCharacters, &availableCharactersSize, 65, 90 );
    if(this->special_characters)
    {
        addCharacters(availableCharacters, &availableCharactersSize,58 , 64 );
        addCharacters(availableCharacters, &availableCharactersSize, 91, 96 );
    }if (spaces)
    {
        
        addCharacter(availableCharacters, &availableCharactersSize,32);
    }
    // printAvailableCharacters(availableCharacters, &availableCharactersSize);
    
    
    switch (bruteforceType)
    {
    case BRUTEFORCE_TYPE::RANDOM:
        srand(time(time_t(0)));
        currect_password= generatedPasswordRandom(*pass_func,availableCharacters,&availableCharactersSize );
        break;
    
    default:
        currect_password = "";
        break;
    }
    
    // while (numTry <= max_try)
    // {
    //     //*TODO to finalize the algorithm options
    //     //Generated password
    //     generatedPasswordRandom(&currect_password, max_password_size, availableCharacters,&availableCharactersSize);
    //     //generatedPasswordLinear(&currect_password, max_password_size, availableCharacters,&availableCharactersSize, &tempPassword,max_try)
    //     //result
    //     if ( (*pass_func)(currect_password)) return currect_password;
    //     if (isLogging) std::cout << currect_password << " is wrong." << std::endl;
    //     numTry++;
    //     currect_password = "";
    // }
    delete[] availableCharacters;
    return currect_password;
    
}

std::string Bruteforce::generatedPasswordRandom(bool (*pass_func)(std::string), int*& characters, int* availableCharactersSize)
{
    unsigned nowTry = 0;
    std::string temppassword ="";
    while (nowTry < this->maxTry)
    {
        for (int i = 0; i < this->maxPasswordSize;i++)
        {
            int randChar = rand()%(*availableCharactersSize);
            char newchar = char(*(characters +randChar ));
            temppassword += newchar;
        }
        if ((*pass_func)(temppassword)) return temppassword;
        nowTry++;
        if (isLogging) std::cout << temppassword<< " is wrong." << std::endl;
        temppassword = "";
    }
    return "";


}

std::string Bruteforce::generatedPasswordLinear(bool (*pass_func)(std::string), int *&characters, int *availableCharactersSize)
{
    //std::string tempPasswords[maxTry];
    unsigned nowTry = 0;





    // if (sizeof(tempPass)/sizeof(tempPass[0]) == 0)
    // {
    //     for (int i = 0; i < maxTry; i++)
    //     {
    //         std::string tempPassFromList;
            
            
    //         *tempPass[i] = tempPassFromList; 
    //     }
    // }
    // *currect_password =  *tempPass[0];
    return "";
}




void Bruteforce::addCharacters(int *&availableCharacters, int *availableCharactersSize, int first_char, int last_char)
    {
        for (int i  = first_char; i<=last_char;i++) 
        {
            *(availableCharacters+ (*availableCharactersSize)) = i;
            (*availableCharactersSize) ++;
        }

    }
void Bruteforce::addCharacter(int *&availableCharacters, int *availableCharactersSize, int newChar)
{
    *(availableCharacters+ (*availableCharactersSize)) = newChar;
    (*availableCharactersSize) ++;
}
void Bruteforce::printAvailableCharacters(int *&availableCharacters, int *availableCharactersSize)
{
    for (int i = 0; i < *availableCharactersSize; i ++)
    {
        std::cout << char(*availableCharacters+i);
    }
    std::cout << std::endl;
}