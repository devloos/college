#pragma once
#include <iostream>
#include <iomanip>
#include <string>
#include <unistd.h>

const unsigned int ONE_SECOND {1000000}; 

void displayBoard(const char boardAr[][3]);//displays TicTacToe board when called returns nothing
void displayHeader();//displays class header
void displayInstructions();//displays instructions for player
void initBoard(char boardAr[][3]);//initializes TicTacToe board to spaces
void setPlayerNames(std::string &playerX, std::string &playerO);//sets player names defaults will take place if not specified
void getAndCheckInp(const std::string difficulty, const char menuChoice, char boardAr[][3], const char token, const std::string &playerX, const std::string &playerO);
//Get and check input - gets user input and checks to see if spot is take, if move is valid then fills spot with current token
char winLogic(char boardAr[][3]);//checks all 8 win conditions and returns winning token or returns 'c' for continue with game
void switchToken(char &token);//switches token which intern switches player 
void displayWinner(const char boardAr[][3], const char &whoWon, const std::string &playerX, const std::string &playerO);//once a player has won this function displays winner and board
bool checkAiInput(const std::string difficulty, char boardAr[][3], const char token);//checks Ai input and depending on what difficulty was selected thats what the Ai's input will be
bool easyAi(char boardAr[][3], const char token);//random move on the board is placed
bool normalAiBlocking(char boardAr[][3], const char token);//specific blocking move is placed if option is available 
void thinking(char boardAr[][3]);//displays thinking timer
bool normalWinConditionsAi(char boardAr[][3], const char token);//specific move is win condition is available for Ai
bool hardWinConditionsAi(char boardAr[][3], const char token);//specific move is win condition is available for Ai
bool hardAiBlocking(char boardAr[][3], const char token);//specific blocking move is placed if option is available