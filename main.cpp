#include <iostream>
#include <string>
#include "headers/bruteforce.h"

bool set_password(std::string);



int main(int argc, char const *argv[])
{
    bool (*ptr_print)(std::string name) = &set_password;

    std::string password = Bruteforce::bruteforce(ptr_print, 3u,50,true,false,false,false,false,true);
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
    const std::string CURRECT_PASSWORD = "123";
    if( password == CURRECT_PASSWORD ) return true;
    return false;

}