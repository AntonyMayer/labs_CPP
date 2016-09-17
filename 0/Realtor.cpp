/*************************************************************************
* Name: Anton Kuzniatsou
* Date: 09/02/2016 Lab 0
*************************************************************************
* Statement: Determine owner, selling cost and commission for house sale
* Specifications:
* Input - owner (string) and selling price (double)
* Output- owner (string), selling cost (double) and commission (double)
*************************************************************************/
// header files for I/O and string objects
#include <iostream>
#include <string>
using namespace std;
int main()
{
// declaration of objects used to store data
string seller; // seller’s name
// price of the house, cost to sell the house and commission on the sale
double price, cost, commission;
// 1. Output descriptive messages
cout << "This program calculates the cost to sell a home\n"
<< "and the commission paid to an individual sales agent.\n\n";
cout << "The user is asked for the last name of the seller and the\n"
<< "sales price.\n\n";
// 2. Prompt for and input the seller’s name
cout << "Please enter the owner’s last name: ";
cin >> seller;
// 3. Prompt for and input the sales price
cout << "\nPlease enter the sales price of the home: ";
cin >> price;
// 4.-5. calculate the cost and the commission
cost = 0.06 * price;
commission = 0.015 * price;
// 6.-7. display the input and results
cout << "\nThe " << seller << "’s home sold for $" << price << endl;
cout << "The cost to sell the home was $" << cost << endl;
cout << "The selling or listing agent earned $" << commission << endl;
}