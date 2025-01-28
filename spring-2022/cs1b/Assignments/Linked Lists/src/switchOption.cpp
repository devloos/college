#include "../include/header.h"
/****************************************************************************
 * Title: switchOption
 * --------------------------------------------------------------------------
 * FUNCTION:
 *    Switch function handles the choice of user
 * --------------------------------------------------------------------------
 * Data Table
 * ----------
 * int index CALC - used to determine index of linked list
 ***************************************************************************/

void switchOption(const MenuOptions &option, DVD* head, std::fstream &oFile) {
   int index = 0;
   switch (option) {
      case OutputEntireList:
         std::cout << "\nCOMPLETE MOVIE LISTING!\n\n";
         oFile << "All Movies Found:\n";
         outputList(head, oFile, index);
         oFile << "\n";
         break;
      case TitleSearch:
         titleSearch(head, oFile);
         break;
      case GenreSearch:
         genreSearch(head, oFile, index);
         break;
      case ActorSearch:
         actorSearch(head, oFile, index);
         break;
      case YearSearch:
         yearSearch(head, oFile, index);
         break;
      case RatingSearch:
         ratingSearch(head, oFile, index);
         break;
      case Exit:
         std::cout << "\nThank You!!\n";
         break;
      default:
         std::cout << "Enter A Valid Option\n";
         break;
   }

}
/****************************************************************************
 * Title: titleSearch
 * --------------------------------------------------------------------------
 * FUNCTION:
 *    handles the output for title search
 * --------------------------------------------------------------------------
 * Data Table
 * ----------
 * std::strKey IN & CALC input key and searches linked list for it 
 ***************************************************************************/

void titleSearch(DVD* head, std::fstream &oFile) {
   std::string strKey;

   std::cout << "Which Title are you looking for? ";
   std::cin.ignore(1000, '\n');
   std::getline(std::cin, strKey);

   titleSearchLogic(head, oFile, strKey);
}
/****************************************************************************
 * Title: genreSearch
 * --------------------------------------------------------------------------
 * FUNCTION:
 *    Handles the output for genreSearch
 * --------------------------------------------------------------------------
 * Data Table
 * ----------
 * std::string strKey IN & CALC - holds user genre input 
 ***************************************************************************/

void genreSearch(DVD* head, std::fstream &oFile, int &index) {
   std::string strKey;

   std::cout << "\nWhich Genre are you looking for? ";
   std::cin.ignore(1000, '\n');
   std::getline(std::cin, strKey);
   std::cout << "\nSearching for the genre " << strKey << "\n";

   searchKeyLogic(head, oFile, strKey, index);

   if (index == 0)//if after going through the linked list the index still is 0 then movie was not found
      std::cout << "Sorry, no movies for the genre " << strKey << " were found.\n";
   else {
      std::cout << "Found " << index << " movies for the genre " << strKey << "!\n";
      oFile << "\n";
   }
}
/****************************************************************************
 * Title: actorSearch
 * --------------------------------------------------------------------------
 * FUNCTION:
 *    handles actor search output
 * --------------------------------------------------------------------------
 * Data Table
 * ----------
 * std::string strKey IN & CALC - holds actor name
 ***************************************************************************/

void actorSearch(DVD* head, std::fstream &oFile, int &index) {
   std::string strKey;

   std::cout << "\nWhich Actor are you looking for? ";
   std::cin.ignore(1000, '\n');
   std::getline(std::cin, strKey);
   std::cout << "\nSearching for the actor " << strKey << "\n";

   searchKeyLogic(head, oFile, strKey, index);

   if (index == 0)
      std::cout << "Sorry, no movies for the actor " << strKey << " were found.\n";
   else {
      std::cout << "Found " << index << " movies for the actor " << strKey << "!\n";
      oFile << "\n";
   }
}
/****************************************************************************
 * Title: yearSearch
 * --------------------------------------------------------------------------
 * FUNCTION:
 *    handles year search output
 * --------------------------------------------------------------------------
 * Data Table
 * ----------
 * int keyInt IN & CALC - user year input and then we validate it 
 ***************************************************************************/

void yearSearch(DVD* head, std::fstream &oFile, int &index) {
   int keyInt;
   yearValidation(keyInt);

   std::cout << "\nSearching for the year " << keyInt << "\n";
   searchKeyLogic(head, oFile, keyInt, index);

   if (index == 0)
      std::cout << "Sorry, no movies for the year " << keyInt << " were found.\n";
   else {
      std::cout << "Found " << index << " movies for the year " << keyInt << "!\n";
      oFile << "\n";
   }
}
/****************************************************************************
 * Title: ratingSearch
 * --------------------------------------------------------------------------
 * FUNCTION:
 *    handles rating search output
 * --------------------------------------------------------------------------
 * Data Table
 * ----------
 * int keyInt IN & CALC - user rating input and then we validate it
 ***************************************************************************/

void ratingSearch(DVD* head, std::fstream &oFile, int &index) {
   int keyInt;
   ratingValidation(keyInt);

   std::cout << "\nSearching for the rating " << keyInt << "\n";
   searchKeyLogic(head, oFile, keyInt, index);

   if (index == 0)
      std::cout << "Sorry, no movies for the rating " << keyInt << " were found.\n";
   else {
      std::cout << "Found " << index << " movies for the rating " << keyInt << "!\n";
      oFile << "\n";
   }
}
/****************************************************************************
 * Title: outputList
 * --------------------------------------------------------------------------
 * FUNCTION:
 *    handles entire output of movies
 * --------------------------------------------------------------------------
 * NO Data Table
 * ----------
 ***************************************************************************/

void outputList(DVD *head, std::fstream &oFile, int &index) {
   DVD *node = head;
   while (node->nextNode != NULL) {

      multiMoviePrint(oFile, node, index);
      node = node->nextNode;
   }
}