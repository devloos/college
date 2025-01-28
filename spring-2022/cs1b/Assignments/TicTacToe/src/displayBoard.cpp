/****************************************************************************
 * Title: displayBoard
 * --------------------------------------------------------------------------
 * function displays updated board 
 * outer for loop is in charge of displaying this ->
 *    [1][1] | [1][2] | [1][3]
 *           |        |        
 * & and controls when this line gets displayed (only twice)
 *    --------------------------  
 * & also changing the values
 * 
 * inner for loop controls ->
 *  1        |         |            
 * --------------------------------------------------------------------------
 * No Data Table
 * ----------
 ***************************************************************************/

#include "main.h"
using namespace std;

void displayBoard(const char boardAr[][3]) 
{ 
    cout << setw(10) << "1" << setw(8) << "2" << setw(9) << "3\n"; 
    for (int i = 0; i < 3; i++) 
    { 
    
        cout << setw(7) << "[" << i+1 << "][1] | " << "[" << i+1;  
        cout << "][2] | " << "[" << i+1 << "][3]" << endl; 
        cout << setw(14) << "|" << setw(9) << "|" << endl; 
        
        for (int j = 0; j < 3; j++) 
        { 
            switch(j) 
            { 
                case 0:  cout << i + 1 << setw(9) << boardAr[i][j]; 
                    cout  << setw(4) << "|"; 
                    break; 
            
                case 1:  cout << setw(4) << boardAr[i][j]; 
                    cout << setw(5) << "|"; 
                    break; 
            
                case 2:  cout << setw(4) << boardAr[i][j] << endl; 
                    break; 
            
                default: cout <<"ERROR!\n\n"; 
            } 
        } 
        cout << setw(14)<< "|" << setw(10) << "|\n"; 
        
        if (i != 2) 
            cout << setw(32) << "--------------------------\n"; 
    } 
    cout << endl << endl; 
} 
