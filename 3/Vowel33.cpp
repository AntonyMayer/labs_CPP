/************************************************************************
* Name: Anton Kuzniatsou                                          CSC 155
* Date: 9/17/2016                                                   Lab 3
*************************************************************************
* Statement: Count the number of occurrences of a character in a string
* Specifications:
* Input  - search string
* Output - the string
*        - the number of characters
*        - the count of each vowel
************************************************************************/

#include <iostream>
#include <string>
using namespace std;

int main()
{
     string repeat, input_string;

     int a_count, e_count, i_count, o_count, u_count, pos_count;
          
     cout << "\nThis program asks the user for a sentence,\n"
          << "searches the sentence for all vowels,\n"
          << "and displays the number of times each\n"
          << "vowel appears in the sentence.\n" << endl;

     do {
          
          a_count = e_count = i_count = o_count = u_count = pos_count = 0;

          cout << "\nEnter the sentence to search: " << endl;
          
          getline(cin, input_string);

          cout << "\nThe sentence has " <<  input_string.length()
               << " characters.\n" << endl;

          while (pos_count <  input_string.length()) {
               switch (input_string[pos_count]) {
               case 'a':
               case 'A':
                    a_count++;
                    break;
               case 'e':
               case 'E':
                    e_count++;
                    break;
               case 'i':
               case 'I':
                    i_count++;
                    break;
               case 'o':
               case 'O':
                    o_count++;
                    break;
               case 'u':
               case 'U':
                    u_count++;
                    break;
               }
               pos_count++;
          }

          cout << "There are\n"
               << a_count << " a's,\n"
               << e_count << " e's,\n"
               << i_count << " i's,\n"
               << u_count << " u's.\n"
               << endl;

          cout << "Would you like to search another sentence? (y or n)" << endl;
          
          getline (cin, repeat);

     } while (repeat == "y");

     return 0;
}