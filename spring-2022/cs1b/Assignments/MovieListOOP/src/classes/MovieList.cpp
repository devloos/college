#include "../../include/MovieList.h"
#include <fstream>
#include <iostream>
#include <iomanip>

void heading(std::ostream &os);

void MovieList::FileInput(std::fstream &inFile, DVDNode &node) {
  std::getline(inFile, node.title);
  std::getline(inFile, node.leadingActor);
  std::getline(inFile, node.supportingActor);
  std::getline(inFile, node.genre);
  std::getline(inFile, node.alternateGenre);
  inFile >> node.year;
  inFile.ignore(1000, '\n');
  inFile >> node.rating;
  inFile.ignore(1000, '\n');
  std::getline(inFile, node.synopsis);
  inFile.ignore(1000, '\n');
}

void MovieList::FileFormat(DVDNode &node) {
  node.title = node.title.substr(0, node.title.size() - 1);
  node.leadingActor = 
      node.leadingActor.substr(0, node.leadingActor.size() - 1);

  node.supportingActor = 
      node.supportingActor.substr(0, node.supportingActor.size() - 1);

  node.genre = node.genre.substr(0, node.genre.size() - 1);
  node.alternateGenre =
      node.alternateGenre.substr(0, node.alternateGenre.size() - 1);

  node.synopsis = node.synopsis.substr(0, node.synopsis.size() - 1);
  node.synopsis += " ";
}

MovieList::~MovieList() {
  for (int i = 0; i < stackCount; ++i)
    this->Pop();
}

std::string MovieList::wordWrap(std::string plot) {
  const int Max_Line_Length = 75;
  std::string line;
  std::string FormattedPlot;
  do {
    if (std::string(line + plot.substr(0, plot.find(' '))).size() < Max_Line_Length) {
      line += plot.substr(0, plot.find(' ') + 1);
      plot = plot.substr(plot.find(' ') + 1);
    } else {
      FormattedPlot += line + '\n';
      line.clear();
    }
  } while (!(plot.empty()));
  FormattedPlot += line;
  return FormattedPlot;
}

void MovieList::createList(const std::string &inFileInput) {
  DVDNode node;
  std::fstream inFile(inFileInput, std::ios::in);
  if (inFile.is_open()) {
    while (!inFile.eof()) {
      // PROCCESSING: READING DATA FROM FILE
      this->FileInput(inFile, node);
      // PROCCESSING: FORMATTING STRING
      this->FileFormat(node);
      this->Push(node);
    }
  } else {
    std::cerr << "\nERROR: [File " << inFileInput << " failed to open]\n"; 
  }
}

void MovieList::outputList(const std::string &oFileInput) {
  DVDNode* node = head;
  std::fstream oFile(oFileInput, std::ios::out);
  heading(oFile);
  if (oFile.is_open()) {
    for (int i = 0; i < stackCount; ++i) {
      oFile << std::left;
      oFile << "***************************************************************************\n";
      oFile << "MOVIE #: " << std::setw(9) << i+1 << "Title: " << node->title << "\n";
      oFile << "---------------------------------------------------------------------------\n";
      oFile << "Year: " << std::setw(12) << node->year << "Rating: " << node->rating << '\n';
      oFile << "---------------------------------------------------------------------------\n";
      oFile << "Leading Actor:    " << std::setw(22) << node->leadingActor << "Genre 1: " << node->genre << "\n";
      oFile << "Supporting Actor: " << std::setw(22) << node->supportingActor << "Genre 2: " << node->alternateGenre << "\n";
      oFile << "---------------------------------------------------------------------------\n";
      oFile << "PLOT:\n";
      oFile << this->wordWrap(node->synopsis) << '\n';
      oFile << "***************************************************************************\n";
      oFile << std::right;
      node = node->next;
    }
  } else {
    std::cerr << "\nERROR: [File " << oFileInput << " failed to open]\n"; 
  }

}