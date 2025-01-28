#include "../include/header.h"
/****************************************************************************
 * Title: titleSearchLogic
 * --------------------------------------------------------------------------
 * FUNCTION:
 *    handles the title search logic has a while loop the iterates until
 * end of linked list or until found
 * --------------------------------------------------------------------------
 * Data Table
 * ----------
 * DVD* node = head CALC - use it not to mess with head
 * bool found CALC - false until found
 ***************************************************************************/

void titleSearchLogic(DVD* head, std::fstream &oFile, std::string strKey) {
   DVD *node = head;
   bool found = false;
   while (node->nextNode != NULL && !found) {

      if (node->title == strKey) {//current strKey being a title of course
         std::cout << "Found the movie " << strKey << "!\n";
         printSingleMovie(node, oFile);
         found = true;
      }

      node = node->nextNode;
      if (node->nextNode == NULL)//output statement if not found
         std::cout << "Sorry, the movie \" " << strKey <<  " \" was not found.\n";
   }
}
/****************************************************************************
 * Title: searchKeyLogic
 * --------------------------------------------------------------------------
 * FUNCTION:
 *    These are 2 overloaded functions that handle searches for year, rating
 * genre, and lead actor
 * --------------------------------------------------------------------------
 * NO Data Table
 * ----------
 ***************************************************************************/

void searchKeyLogic(DVD *head, std::fstream &oFile, const int &key, int &index) {
   DVD *node = head;
   while (node->nextNode != NULL) {

      if (node->year == key) {
         if (index == 0)
            oFile << "Search by year for " << key << " found:\n";
         multiMoviePrint(oFile, node, index);
      } else if (node->rating == key) {
         if (index == 0)
            oFile << "Search by rating for " << key << " found:\n";
         multiMoviePrint(oFile, node, index);
      }

      node = node->nextNode;
   }
}
void searchKeyLogic(DVD *head, std::fstream &oFile, const std::string &key, int &index) {
   DVD *node = head;
   while (node->nextNode != NULL) {

      if (node->genre == key || node->altGenre == key) {
         if (index == 0)
            oFile << "Search by genre for " << key << " found:\n";
         multiMoviePrint(oFile, node, index);
      } else if (node->leadActor == key || node->subActor == key) {
         if (index == 0)
            oFile << "Search by actor for " << key << " found:\n";
         multiMoviePrint(oFile, node, index);
      }

      node = node->nextNode;
   }
}