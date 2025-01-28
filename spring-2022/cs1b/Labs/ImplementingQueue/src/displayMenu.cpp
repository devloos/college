#include "../include/header.h"

void displayMenu()
{
    std::cout << "\nQUEUE MENU:\n"; 
    std::cout << "1 ENQUEUE (Add a person)\n";
    std::cout << "2 DEQUEUE (Remove a person)\n";
    std::cout << "3 ISEMPTY (Is the queue empty?)\n";   
    std::cout << "4 FRONT   (Who is in front?)\n";
    std::cout << "5 SIZE    (How many people are there?)\n";
    std::cout << "6 Clear the Queue\n";
    std::cout << "0 Exit\n";
}