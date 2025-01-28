/*****************************************************************************
 * AUTHOR      : Carlos Aguilera
 * STUDENT ID  : 1152562
 * LAB # 1     : Theme Park Day Planner
 * CLASS       : CS1B
 * SECTION     : M-W
 * DUE DATE    : 01.26.22
 ****************************************************************************/

#include <iostream>
#include <iomanip>
#include <string>

/****************************************************************************
 * Theme Park Day Planner
 * --------------------------------------------------------------------------
 * This program will output the class heading
 * --------------------------------------------------------------------------
 * INPUT:
 * name = name of the kid
 * boolDetermination = whether user chose yes or no
 * age = age of kid
 * OUTPUT:
 * totalCost = total cost of the day
 ***************************************************************************/
void foodLogic(double *totalCost, bool isVegetarian, bool eatsCheese, const std::string &name)
{
    if(isVegetarian == false && eatsCheese == true) {//is not vegetarian and eats cheese
        std::cout << "Pack a cheeseburger for " << name << "\n";
        *totalCost += 3.50;
    }
    else if(isVegetarian == false && eatsCheese == false) {//is not vegetarian and doesn't eat cheese
        std::cout << "Pack a hamburger for " << name << "\n";
        *totalCost += 3.25;
    }
    else if(isVegetarian == true && eatsCheese == true) {//is vegetarian and eats cheese
        std::cout << "Pack a cheese pizza for " << name << "\n";
        *totalCost += 2.50;
    }
    else if(isVegetarian == true && eatsCheese == false) {//is vegetarian and doesn't eat cheese
        std::cout << "Pack a Happy Garden meal for " << name << "\n";
        *totalCost += 1.75;
    }
}

void ageLogic(double *totalCost, const int &age, const std::string &name)
{
    if(age > 0 && age < 5)//if age is greater than 0 and less than 5
        std::cout << name << " will be going on the Ferris Wheel and will be visiting the Sheep Petting Zoo.\n";
    else if(age > 4 && age < 13) {//if age is greater than 4 and less than 13
        std::cout << name << " will be going on the Tea Cups and will be playing Lazer Tag.\n";
        *totalCost += 15;
    }else if(age > 12) {//if age is greater than 12
        std::cout << name << " will be going on the Roller Coaster and the Zip line.\n";
        *totalCost += 20;
    }else
        std::cout << "Invalid Age\n";//exception handling if invalid age
}
int main() {
	 /***********************************************************************
	  * CONSTANTS
	  * ---------------------------------------------------------------------
	  * OUTPUT - USED FOR CLASS HEADING
	  * ---------------------------------------------------------------------
	  * PROGRAMMER : Programmer's Name
	  * CLASS      : Student's Course
	  * SECTION    : Class Days and Times
	  * LAB_NUM    : Lab Number (specific to this lab)
	  * LAB_NAME   : Title of the Lab
	  **********************************************************************/
	const char PROGRAMMER[] = "Carlos Aguilera";
	const char CLASS[]      = "CS1B";
	const char SECTION[]    = "MW: 7:30p - 9:50p";
	const int LAB_NUM       = 1;
	const char LAB_NAME[]   = "Theme Park Day Planner";

    std::string name {};
    char boolDetermination {};
    int age {};
    bool isVegetarian {}, eatsCheese {};
    double totalCost {};


	/************************************************************************
	 * OUTPUT - Class Heading
	 ***********************************************************************/
	std::cout << std::left;
	std::cout << "****************************************************\n";
	std::cout << "*   PROGRAMMED BY : " << PROGRAMMER << std::endl;
	std::cout << "*   " << std::setw(14) <<"CLASS" << ": " << CLASS << std::endl;
	std::cout << "*   " << std::setw(14) <<"SECTION" << ": " << SECTION << std::endl;
	std::cout << "*   LAB #" << std::setw(9) << LAB_NUM << ": " << LAB_NAME << std::endl;
	std::cout << "****************************************************\n\n";
	std::cout << std::right;

    for(size_t i {1}; i <= 10; i++)
    {
        std::cout << "Kid #:" << i << "\n";
        std::cout << std::left;
        if(i != 1)
            std::cin.ignore(100,'\n');//this is for the buffer but after its ran once
        std::cout << std::setw(27) << "What is your kid's name?";
        std::getline(std::cin,name);
        name = name.substr(0, name.find(" "));//using the substr method to cut the string after first name
        std::cout << std::setw(27) << "How old is the kid? ";
        std::cin >> age;
        std::cin.ignore(100,'\n');//an ignore for .get
        std::cout << std::setw(27) << "Vegetarian (Y/N) ";
        std::cin.get(boolDetermination);

        if(boolDetermination == 'Y' || boolDetermination == 'y')
            isVegetarian = true;
        else
            isVegetarian = false;

        std::cin.ignore(100,'\n');
        std::cout << std::setw(27) << "Does he/she like cheese? ";
        std::cin.get(boolDetermination);
        std::cout << std::right << "\n";

        if(boolDetermination == 'Y' || boolDetermination == 'y')
            eatsCheese = true;
        else
            eatsCheese = false;
        
        ageLogic(&totalCost, age, name);
        foodLogic(&totalCost, isVegetarian, eatsCheese, name);
        std::cout << "\n\n";
    }
    std::cout << "The total cost of the day is: " << std::fixed << std::setprecision(2) << totalCost << "\n";
    std::cout << "The average cost per kid is:  " << totalCost/10 << "\n";
}