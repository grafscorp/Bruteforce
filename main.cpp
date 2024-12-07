#include <iostream>
#include <string>
#include "headers/bruteforce.h"

bool set_password(std::string);


int main(int argc, char const *argv[])
{

    bool (*ptr_print)(std::string name) = &set_password;

    const int PASSWORD_MAX_SIZE = 3;
    const int MAX_TRY = 999;
    const bool DIGITALS_IN_PASS = true;
    const bool LETTERS_IN_PASS = false;
    const bool CAPS_LETTERS_IN_PASS = false;
    const bool SPEC_SYMBOLS_IN_PASS = false;
    const bool SPACES_IN_PASS = false;

    Bruteforce bruteforce (PASSWORD_MAX_SIZE,MAX_TRY,DIGITALS_IN_PASS,LETTERS_IN_PASS,CAPS_LETTERS_IN_PASS,SPEC_SYMBOLS_IN_PASS,SPACES_IN_PASS);
    bruteforce.setLogging(true);



    std::string password = bruteforce.bruteforce(ptr_print, BRUTEFORCE_TYPE::RANDOM);
    if (password != "")
    {
        std::cout << "PASSWORD IS FOUNDED : " << password << std::endl;
    }else{
        std::cout << "Failed\n";
    }
    return 0;
}

//Test function
bool set_password(std::string password)
{
    const std::string CURRECT_PASSWORD = "024";
    if( password == CURRECT_PASSWORD ) return true;
    return false;

}