#include "../include/header.h"

int main() {
  MovieRec* head = nullptr;
  MovieRec* tail = nullptr;
  createList(head, tail);

  Choice choice = EXIT;
  do {
    displayMenu();
    validateInput(choice);
    switch (choice) {
      case EXIT: {
        break;
      }
      case ADD: {
        MovieRec* node = new MovieRec;

        std::cout << "Enter Movie details\n";
        std::cout << "Movie Title: ";
        std::cin.ignore(1000, '\n');
        std::getline(std::cin, node->movieTitle);
        std::cout << "Movie Genre: ";
        std::getline(std::cin, node->genre);
        std::cout << "Release Year: ";
        std::cin >> node->releaseYear;
        std::cin.ignore(1000, '\n');

        nodePlacement(head, tail, nullptr, node);
        node = nullptr;
        std::cout << "\n";
        break;
      }
      case REMOVE: {
        std::string key;
        std::cout << "Enter Movie to remove\n";
        std::cout << "Movie Title: ";
        std::cin.ignore(1000, '\n');
        std::getline(std::cin, key);
        removeMovieRec(head, tail, key);
        break;
      }
      case DISPLAY: {
        displayList(head);
        break;
      }
      default: {
        std::cout << "Enter number between 0 - 3\n";
        break;
      }
    }
  }while (choice != EXIT);
  return 0;
}