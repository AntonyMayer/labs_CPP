/*************************************************************************
* Name: Anton Kuzniatsou
* Date: 09/02/2016 Lab 0
****************************************************************************************
* Statement: Determine owner, selling cost and commission for house sale
* Specifications:
* Input - owner (string) and selling price (double) << Realtor11.inp
* Output- owner (string), selling cost (double) and commission (double) >> Realtor11.out
****************************************************************************************/
#include <fstream>
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;
int main()
{
	string seller;
	double price, cost, commission;

	ifstream fin;
	ofstream fout;

	fin.open("Realtor11.inp");
	fout.open("Realtor11.out");

	fin >> seller >> price;
	fout << "This program calculates the cost to sell a home\n"
	     << "and the commission paid to an individual sales agent.\n\n";
	fout << "The user is asked for the last name of the seller and the\n"
	     << "sales price.\n\n";
	fout << "Input is read from the file Realtor11.inp\n";
	fout << "Output is printed to the file Realtor11.out\n\n";

	cost = 0.06 * price;
	commission = 0.015 * price;

	fout << setw(10) << left << "\nHome Owner" << right
	     << setw(16) << "Price of Home"
	     << setw(25) << "Seller’s Cost"
	     << setw(23) << "Agent’s Commission\n";

	fout << setw(10) << left << seller
	     << setw(16) << right << setfill('*')
	     << fixed << setprecision(2) << price
	     << setw(23) << cost
	     << setw(20) << commission
	     << endl;

	fin.close();
	fout.close();

	cout << "\nInput is read from the file Realtor11.inp\n"
	     << "Output is printed to the file Realtor11.out\n" << endl;
}