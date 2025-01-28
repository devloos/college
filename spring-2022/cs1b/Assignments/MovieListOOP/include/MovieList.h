#ifndef MOVIELIST_H_
#define MOVIELIST_H_
#include "StackList.h"
#include <fstream>

void heading();

class MovieList : public StackList {
 private:
  std::string wordWrap(std::string plot);
  void FileInput(std::fstream &inFile, DVDNode &node);
  void FileFormat(DVDNode &node);
 public:
  MovieList() : StackList() {}
  ~MovieList();
  void createList(const std::string &inFileName);
  void outputList(const std::string &oFileName);
};

#endif // MOVIELIST_H_