/*************************************************************************
* Name: Anton Kuzniatsou
* Date: 09/02/2016 Lab 0
*************************************************************************
* Statement: Determine owner, selling cost and commission for house sale
* Specifications:
* Input - owner (string) and selling price (double)
* Output- owner (string), selling cost (double) and commission (double)
*************************************************************************/
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;
int main()
{
	string seller;
	double price, cost, commission;

	cout << "\nThis program calculates the cost to sell a home\n"
	     << "and the commission paid to an individual sales agent.\n\n";
	cout << "The user is asked for the last name of the seller and the\n"
	     << "sales price.\n\n";
	cout << "Please enter the owner’s last name: ";
	cin >> seller;
	cout << "\nPlease enter the sales price of the home: ";
	cin >> price;

	cost = 0.06 * price;
	commission = 0.015 * price;

	cout << setw(10) << left << "\nHome Owner" << right
	     << setw(16) << "Price of Home"
	     << setw(25) << "Seller’s Cost"
	     << setw(23) << "Agent’s Commission\n";

	cout << setw(10) << left << seller
	     << setw(16) << right << setfill('*')
	     << fixed << setprecision(2) << price
	     << setw(23) << cost
	     << setw(20) << commission
	     << endl;
}