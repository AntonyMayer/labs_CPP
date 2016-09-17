/************************************************************************
* Name: Anton Kuzniatsou                                          CSC 155
* Date: 09/10/2016                                                  Lab 2   
*************************************************************************
* Statement: Determine type of flooring for a new home
* Specifications:
* Input  - Flooring selector
* Output - Appropriate output message based upon selector value
************************************************************************/

#include <iostream>
#include <string>
using namespace std;

int main()
{
	const string OPTION1 = "Option 1: Scored concrete, costs $3000"; 
	const string OPTION2 = "Option 2: Carpeting comes with a $5000 allowance"; 
	const string OPTION3 = "Option 3: Wood floors in the living area,\n"
						   "carpeting in the bed rooms, tile in the bath areas,\n"
						   "and a $5000 carpeting allowance, totaling $10,000"; 
	const string OPTION4 = "Your selection is not available"; 
	int choice;
	string outputString;
	bool available = true;

	cout << "\nThis program asks a user to enter a choice of flooring for a new home.\n";
	cout << "\nEnter the number that matches your flooring choice:\n";
	cout << OPTION1 << endl << OPTION2 << endl
		 << OPTION3 << endl << endl;
	
	cin >> choice;

	switch(choice) {
	    case 1 : outputString = OPTION1;
	             break;
	    case 2 : outputString = OPTION2;
	             break;
	    case 3 : outputString = OPTION3;
	             break;
	    default: outputString = OPTION4;
	    		 available = false;
	             break;
	}

	if (available) cout << "You chose " + outputString << endl;
	else cout << outputString << endl;
	
	return 0;
}