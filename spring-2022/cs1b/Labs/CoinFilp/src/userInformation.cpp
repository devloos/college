#include "../include/main.hpp"
#include <string>

void userInformation()
{
    std::string userName {};//IN -Name of user
    char userGender {};//IN      -Gender of user

    std::cout << std::left;
    std::cout << std::setw(28) << "What is your name?";
    std::getline(std::cin, userName);//gets entire line then resets buffer
    userName = userName.substr(userName.find(' ') + 1, userName.size());//calls method substr for userName starts at character ' ' and ends at the end of the string

    std::cout << std::setw(28) << "What is your gender (m/f):";
    std::cin.get(userGender);
    std::cin.ignore(100,'\n');//buffer reset always after .get is used

    std::cout << "\n\nTry to get 3 heads in a row. Good luck ";
    if(userGender == 'm' || userGender == 'M')//if userGender stores 'm' or 'M' then true
        std::cout << "Mr. " << userName << "\n\n";
    else if(userGender == 'f' || userGender == 'F')//else if userGender stores 'f' or 'F' then true
        std::cout << "Ms. " << userName << "\n\n";
    else //else run
        std::cout << userName << "\n\n";
    std::cout << std::right;
}