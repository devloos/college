/*
* author: carlos aguilera
* class: cs1b
*/
#include "hw01.h"

int main()
{
   char name;
   char character[7];
   std::cout << "Enter a phone number written in characters: ";
 
   std::cin >> character;
   
   for(char name : character) 
   {   
      switch(name)
      {
         // case ' ' :
         // std::cout << "\0"; tried to get space to be ignored but its a no terminator value so it would cut the cstring short
         // break;
        
         case 'a' :  case 'A' :
         case 'b' :  case 'B' :
         case 'c' :  case 'C' :
           // return 2;
            std::cout << "2";
         break;

         case 'd' :  case 'D' :
         case 'e' :  case 'E' :
         case 'f' :  case 'F' :
           // return 3;
            std::cout << "3";
         break;

         case 'g' :  case 'G' :
         case 'h' :  case 'H' :
         case 'i' :  case 'I' :
           // return 4;
            std::cout << "4";
         break;

         case 'j' :  case 'J' :
         case 'k' :  case 'K' :
         case 'l' :  case 'L' :
           // return 5;
            std::cout << "5";
         break;

         case 'm' :  case 'M' :
         case 'n' :  case 'N' :
         case 'o' :  case 'O' :
           // return 6;
            std::cout << "6";
         break;

         case 'p' :  case 'P' :
         case 'q' :  case 'Q' :
         case 'r' :  case 'R' :
         case 's' :  case 'S' :
           // return 7;
            std::cout << "7";
         break;

         case 't' :  case 'T' :
         case 'u' :  case 'U' :
         case 'v' :  case 'V' :
           // return 8;
            std::cout << "8";
         break;

         case 'w' :  case 'W' :
         case 'x' :  case 'X' :
         case 'y' :  case 'Y' :
         case 'z' :  case 'Z' :
           // return 9;
            std::cout << "9";
         break;
      }

     }
     std::cout << std::endl;
   
   return 0;
}
