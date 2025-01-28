#include "main.hpp"

int main()
{
    char selection {};
    do
    {
        std::cout << "1. Square\n";
        std::cout << "2. Right Triangle\n";
        std::cout << "3. Triangle\n";
        std::cout << "4. Upside Down Triangle\n";
        std::cout << "q. Quit!\n";

        std::cout << "Enter Selection: ";
        std::cin >> selection;

        int dimension {};
        char character {};
        if(selection != 'q')
        {
            do {
                std::cout << "Dimension: ";
                std::cin >> dimension;
            } while (dimension <= 1);
            std::cout << "Character: ";
            std::cin >> character;
        }

        switch (selection)
        {
            case '1': {
                square(dimension, character);
                break;
            }
            case '2': {
                rightTriangle(dimension, character);
                break;
            }
            case '3': {
                triangle(dimension, character);
                break;
            }
            case '4': {
                upsideDownTriangle(dimension, character);
                break;
            }
            case 'q': {
                std::cout << "Thank you!\n";
                break;
            }
            default: {
                std::cout << "invalid choice!\n";
                break;
            }
        }
    } while (selection != 'q');
    
}