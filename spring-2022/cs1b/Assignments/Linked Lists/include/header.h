#ifndef HEADER_H_
#define HEADER_H_
#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <unistd.h>

struct DVD {
   std::string title;
   std::string leadActor;
   std::string subActor;
   std::string genre;
   std::string altGenre;
   int year;
   int rating;
   std::string synopsis;
   DVD *nextNode;
};
enum MenuOptions { Exit = 0, OutputEntireList, TitleSearch, GenreSearch, ActorSearch, YearSearch, RatingSearch};
void heading();//outputs heading
DVD *readInput();//reads data from file and stores it in heap using linked list
void dispMenu();//displays menu
MenuOptions switchValidation();//validates switch input and returns enum MenuOptions
void searchKeyLogic(
   DVD *head,
   std::fstream &oFile, 
   const int &key, 
   int &index);//searches for year or rating

void searchKeyLogic(
   DVD *head, 
   std::fstream &oFile, 
   const std::string &key, 
   int &index);//searches for genre or actor

void outputList(
   DVD *head, 
   std::fstream &oFile, 
   int &index);//outputs entire list to outfile

//testing which format of protype is more used if you can give me some help

void multiMoviePrint(std::fstream &oFile, DVD* node, int &index);//prints multi movies
void switchOption(const MenuOptions &option, DVD* head, std::fstream &oFile);//directs user on there choice
void subString(DVD *head);//formats data
void genreSearch(DVD* head, std::fstream &oFile, int &index);//genre search output
void actorSearch(DVD* head, std::fstream &oFile, int &index);//actor search output
void yearSearch(DVD* head, std::fstream &oFile, int &index);//year search output
void ratingSearch(DVD* head, std::fstream &oFile, int &index);//rating search output
void yearValidation(int &keyInt);//validates year using try catch
void ratingValidation(int &keyInt);//validates rating using try catch
void printSingleMovie(DVD* node, std::fstream &oFile);//prints single movie
void titleSearch(DVD* head, std::fstream &oFile);//title search output
void titleSearchLogic(DVD* head, std::fstream &oFile, std::string strKey);//searches linked list for title
void deallocate(DVD* head);//dallocates memory

#endif