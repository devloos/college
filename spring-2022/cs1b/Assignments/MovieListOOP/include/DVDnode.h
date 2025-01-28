#ifndef DVDNODE_H_
#define DVDNODE_H_
#include <string>

struct DVDNode { 
  DVDNode() : next(nullptr) {}

  std::string title;           // store movie's title 
  std::string leadingActor;    // store leading actor/actress 
  std::string supportingActor; // store supporting actor/actress 
  std::string genre;           // store movie’s genre 
  std::string alternateGenre;  // store movie’s alternate genre 
  int         year;            // store movie’s release year 
  int         rating;          // store movie’s rating 
  std::string synopsis;        // store movie’s synopsis 
  DVDNode     *next;           // linked list next pointer 
}; 

#endif // DVDNODE_H_