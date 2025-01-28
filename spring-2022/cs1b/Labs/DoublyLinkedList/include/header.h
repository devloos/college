#ifndef HEADER_H_
#define HEADER_H_

#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>

struct MovieRec {
  std::string movieTitle;
  std::string genre;
  int releaseYear;
  MovieRec* next;
  MovieRec* prev;
};
enum Choice {
  EXIT = 0,
  ADD,
  REMOVE,
  DISPLAY
};

void readInput(MovieRec* &node, std::fstream &inFile);
void nodePlacement(MovieRec* &head, MovieRec* &tail, MovieRec* node, MovieRec* &currMovieRec);
void placeMovieRecFront(MovieRec* &head, MovieRec* &currMovieRec, MovieRec* &node);
void createList(MovieRec* &head, MovieRec* &tail);
void insertMovieRec(MovieRec* &node, MovieRec* &currMovieRec);
void placeMovieRecBack(MovieRec* &tail, MovieRec* &currMovieRec, MovieRec* &node);
void displayHeader();
void displayMenu();
void displayList(MovieRec* &head);
void validateInput(Choice &choice);
void removeMovieRec(MovieRec* &head, MovieRec* &tail, std::string searchKey);

#endif // HEADER_H_