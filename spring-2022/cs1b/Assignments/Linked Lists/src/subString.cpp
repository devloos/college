#include "../include/header.h"
/****************************************************************************
 * Title: subString
 * --------------------------------------------------------------------------
 * FUNCTION:
 *    This function formats the data to match all calculations made to it
 * --------------------------------------------------------------------------
 * NO Data Table
 * ----------
 ***************************************************************************/

void subString(DVD* head) {
   DVD* node = head;
   while (node->nextNode != NULL) {
      //cuts one character off the ends of each string
      node->title = node->title.substr(0, node->title.size() - 1);
      node->leadActor = node->leadActor.substr(0, node->leadActor.size() - 1);
      node->subActor = node->subActor.substr(0, node->subActor.size() - 1);
      node->genre= node->genre.substr(0, node->genre.size() - 1);
      node->altGenre= node->altGenre.substr(0, node->altGenre.size() - 1);
      node->synopsis= node->synopsis.substr(0, node->synopsis.size() - 1);
      node = node->nextNode;
   }
}