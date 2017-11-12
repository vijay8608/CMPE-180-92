#include <string>
#include "Word.h"
using namespace std;

/***** Modify this file as needed. *****/

Word::Word() : text(""), count(0) {}
Word::Word(string text) : text(text), count(1) {}

Word::~Word() {}

bool Word::operator !=( Word &temp)
{
   if (text != temp.text)
      return true;
   else
   {
	   if (count != temp.count)
		   return true;
   }

   return false;
}
