#include <iostream>
#include <vector>
#include <iomanip>

int main()
{
    int weightInput {};
    double totalShippingPrice {};
    std::vector <int> vecOfPackages {0,0,0,0};

    std::cout << "Enter a series of package weights or 0 to terminate program\n";
    do
    {
        std::cout << ": ";
        std::cin >> weightInput;

        if(weightInput == 0)
            continue;

        if(weightInput == 1 || weightInput == 2)
        {
            totalShippingPrice += 5.00;
            ++vecOfPackages.at(0);
        }else if(weightInput >= 3 && weightInput <= 12) 
        {
            totalShippingPrice += 8.50;
            ++vecOfPackages.at(1);
        }else if(weightInput >= 13 && weightInput <= 20) 
        {
            totalShippingPrice += 12.50;
            ++vecOfPackages.at(2);
        }else if(weightInput >= 21 && weightInput <= 40) 
        {
            totalShippingPrice += 18.00;
            ++vecOfPackages.at(3);
        }else
            std::cout << "Invalid weight!\n";
    } while (weightInput != 0);

    std::cout << "\n" << vecOfPackages.at(0) << " packages under 2 lbs.\n";
    std::cout << vecOfPackages.at(1) << " packages between 3 - 12 lbs.\n";
    std::cout << vecOfPackages.at(2) << " packages between 13 - 20 lbs.\n";
    std::cout << vecOfPackages.at(3) << " packages between 21 - 40 lbs.\n";
    std::cout << std::setprecision(2) << std::fixed << "The total shipping price is $" << totalShippingPrice << "\n";
    
    return 0;
}