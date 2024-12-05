#include "bruteforce.h"


std::string Bruteforce::bruteforce(
        bool (*pass_func)(std::string),
        unsigned max_password_size = 4, int max_try = 5,
        const bool digitals = true,const bool letters = true,const  bool caps_letters =true, 
        const  bool special_characters= true,const  bool spaces = true, bool isLogging = false)
{
    int availableCharactersSize = 0;
    int *availableCharacters = new int[200];

    char currect_password[max_password_size];

    int numTry = 0;
    srand(time(0));
    
    if (digitals)
    {
        addCharacters(availableCharacters, &availableCharactersSize,48, 57 );
        
    }if (letters)
    {
        addCharacters(availableCharacters, &availableCharactersSize, 97, 122 );
    }
    if (caps_letters)
    {
        addCharacters(availableCharacters, &availableCharactersSize, 65, 90 );
    }if(special_characters)
    {
        addCharacters(availableCharacters, &availableCharactersSize,58 , 64 );
        addCharacters(availableCharacters, &availableCharactersSize, 91, 96 );
    }if (spaces)
    {
        
        availableCharacters[availableCharactersSize]= 32;
        availableCharactersSize ++;
    }
    // printAvailableCharacters(availableCharacters, &availableCharactersSize);
    
    
    while (numTry <= max_try)
    {
        //Generated password
        generatedPasswordRandom(currect_password, max_password_size, availableCharacters,&availableCharactersSize);
        //result
        if ( (*pass_func)(currect_password)) return currect_password;
        if (isLogging) std::cout << currect_password << " is wrong." << std::endl;
        numTry++;
    }
    
    delete[] availableCharacters;
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
void Bruteforce::printAvailableCharacters(int *&availableCharacters, int *availableCharactersSize)
    {
        for (int i = 0; i < *availableCharactersSize; i ++)
        {
            std::cout << char(*availableCharacters+i);
        }
        std::cout << std::endl;
    }
void Bruteforce::generatedPasswordRandom(char* pass, int maxSize, int*& characters, int* availableCharactersSize)
    {
        
        for (int i = 0; i < maxSize;i++)
        {
            
            int randChar = rand()%(*availableCharactersSize);
            char newchar = char(*(characters +randChar ));
            *(pass+i) =  newchar;
            
        }

    }