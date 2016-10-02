/************************************************************************
* Name: Anton Kuzniatsou                                          CSC 155
* Date: 10/01/2016			                                        Lab 4
*************************************************************************
* Statement: Echos the contents of an scan.txt and sums prices
* Specifications:
* Input  - string describing a tool in scan.txt
*        - price of the tool in scan.txt
* Output - Message indicating the item and the cost
*        - The sum of all costs and the number of items in scan.txt
************************************************************************/
#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
using namespace std;

ifstream fin;
ofstream fout;

class Tool {
	string name;
public:
	double price;
	void set_values ();
	void display_values(int);
};

void Tool::set_values () {
	fin >> name >> price;
}

void Tool::display_values (int z) {
	cout << setw(29) << left << name << "$"
	     << setw(z) << fixed << setprecision(2)
	     << right << price << endl;
}

int main()
{
	vector<Tool> toolsList;
	double total;
	int priceCell = 4;

	fin.open("scan.txt");

	if (!fin.is_open()) {
		cout << "404 Not Found" << endl;
		return 0;
	}

	cout << "\nThis program will read each line of scan.txt and print a\n"
	     << "statement indicating the item and its cost. When the file\n"
	     << "is exhausted, it will print the sum of all of the costs.\n"
	     << endl;

	for (int i = 0; !fin.eof(); i++) {
		Tool newItem;
		toolsList.push_back(newItem);
		toolsList[i].set_values();
		total += toolsList[i].price;
	}

	if (total >= 100) {
		int check = total;
		do {
			check = check / 10;
			priceCell++;
		} while (check > 100);
	}

	cout << setw(31) << left << "\nItem"
	     << setw(++priceCell) << right << "Cost" << endl;

	for (int i = 0; i < toolsList.size(); i++)
		toolsList[i].display_values(priceCell);

	cout << setw(30) << left << "\nTotal cost" << "$"
	     << setw(--priceCell) << right << fixed
	     << setprecision(2) << total << endl
	     << setw(29) << left << "Number of tools"
	     << setw(++priceCell) << right << toolsList.size() << endl;

	fin.close();

	return 0;
}