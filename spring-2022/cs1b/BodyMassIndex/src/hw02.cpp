/* Body Mass Index Calculation
 * Author Carlos Aguilera
 * Cs1b Drb
 * Modification Feb. 11
 */
#include "hw02.h"

int main()
{
    double A1, A2, A3, A4, A5;
    double B, fat, BFP, waist, hip, weight, height, forearm, wrist, BMI; //Measurement
    int gender; //if conditional declaration

    std::cout << "FIRST FORMULA!" << std::endl; // Kilo weight / Meters Height Squared = result
    std::cout << std::endl;

    std::cout << "Enter weight in Kilograms: ";
    std::cin >> weight;

    std::cout << "Enter height in meters: ";
    std::cin >> height;

    BMI = weight / (height * height); //formula

    std::cout << "BMI: " << BMI << std::endl;
    std::cout << std::endl;

    while (std::cin) {
        std::cout << "                SECOND FORMULA!" << std::endl;
        std::cout << std::endl;

        std::cout << "                     Menu" << std::endl;
        std::cout << "           Input Integer 1 for Women" << std::endl;
        std::cout << "           Input Integer 2 for Men" << std::endl;
        std::cout << "           Input Exit to End Program" << std::endl;

        std::cout << "Choice: ";
        std::cin >> gender;

        if(gender == 1)
        {
            std::cout << "Enter Weight: ";
            std::cin >> weight;
            A1 = (weight * 0.732) + 8.987;

            std::cout << "Enter Wrist Measurement: ";
            std::cin >> wrist;
            A2 = wrist / 3.140;

            std::cout << "Enter Waist Measurement: ";
            std::cin >> waist;
            A3 = waist * 0.157;

            std::cout << "Enter Hip Measurement: ";
            std::cin >> hip;
            A4 = hip * 0.249;

            std::cout << "Enter Forearm Measurement: ";
            std::cin >> forearm;
            A5 = forearm * 0.434;

            B = A1 + A2 + A3 + A4 + A5;
            fat = weight - B;
            BFP = fat * 100 / weight;

            std::cout << "BFP: " << BFP << std::endl;

        } else if(gender == 2)
        {
            std::cout << "Enter Weight: ";
            std::cin >> weight;
            A1 = (weight * 1.082) + 94.42;

            std::cout << "Enter Wrist Measurement: ";
            std::cin >> wrist;
            A2 = wrist / 4.15;

            B = A1 - A2;
            fat = weight - B;
            BFP = fat * 100 / weight;

            std::cout << "BFP: " << BFP << std::endl;

        } else
            break;
    }
    std::ofstream file_;
    file_.open("result.txt");
    file_ << "FIRST FORMULA   " << "   SECOND FORMULA" << std::endl;
    file_ << "---------------------------------" << std::endl;
    file_ << "  " << BMI << "              " << BFP;
    file_.close();
    std::cout << "Results saved in result.txt" << std::endl;
}
