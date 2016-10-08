/************************************************************************
* Name: Anton Kuzniatsou                                          CSC 155
* Date: 10/07/2016						                            Lab 5
*************************************************************************
* Statement: Displays headings for a payroll report.
* Specifications:
* Input  - none
* Output - Payroll report headings
************************************************************************/
#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
using namespace std;

ifstream fin;
ofstream fout;

class Employee {
	string name;
public:
	double rate, hours, tax, gross_sallary, net_sallary;
	void set_values ();
	double calc_gross_sallary (void);
	void display_values();
};

void Employee::set_values () {
	getline(fin, name, '#');
	fin >> rate >> hours >> tax;
	fin.ignore(100, '\n');
	gross_sallary = calc_gross_sallary(); 
	net_sallary = calc_gross_sallary() * (1 - tax / 100);
}

double Employee::calc_gross_sallary () {
	if (hours > 40)
		gross_sallary = (40 + (hours - 40) * 1.5) * rate;
	else gross_sallary = hours * rate;
	return gross_sallary;
}

void Employee::display_values () {
	cout << setprecision(2) << fixed << showpoint << left;
	cout << setw(20) << name << setw(10) << rate
             << setw(10) << hours << setw(10) << tax << setw(10)
             << gross_sallary << setw(10) << net_sallary << endl;
}

void instructions() {
	cout << "This payroll program calculates an individual "
		 << "employee pay and\ncompany totals "
		 << "using data from a data file payroll.txt.\n"
		 << "\n\nA payroll report showing payroll information "
		 << " is displayed.\n\n";
}

void reportTitle() {
	cout << setprecision(2) << fixed << showpoint << left;
	cout << setw(20) << "Employee" << setw(10) << "Hourly"
             << setw(10) << "Hours" << setw(10) << "Tax" << setw(10)
             << "Gross" << setw(10) << "Net" << endl;
	cout << setw(20) << "Name" << setw(10) << "Rate"
             << setw(10) << "Worked" << setw(10) << "Rate" << setw(10)
             << "Amount" << setw(10) <<"Amount" << endl << endl;
}

int main()
{
	vector<Employee> EmployeesList;
	// double total;
	// int priceCell = 4;

	instructions();
	reportTitle();
	
	fin.open("payroll.txt");

	if (!fin.is_open()) {
		cout << "404 Not Found" << endl;
		return 0;
	}


	// cout << "\nThis program will read each line of scan.txt and print a\n"
	//      << "statement indicating the item and its cost. When the file\n"
	//      << "is exhausted, it will print the sum of all of the costs.\n"
	//      << endl;

	for (int i = 0; !fin.eof(); i++) {
		Employee newItem;
		EmployeesList.push_back(newItem);
		EmployeesList[i].set_values();
		// total += EmployeesList[i].price;
	}
	cout << EmployeesList[0].gross_sallary << endl;
	cout << EmployeesList[0].net_sallary << endl;
	// if (total >= 100) {
	// 	int check = total;
	// 	do {
	// 		check = check / 10;
	// 		priceCell++;
	// 	} while (check > 100);
	// }

	// cout << setw(31) << left << "\nItem"
	//      << setw(++priceCell) << right << "Cost" << endl;

	// for (int i = 0; i < EmployeesList.size(); i++)
	// 	EmployeesList[i].display_values(priceCell);

	// cout << setw(30) << left << "\nTotal cost" << "$"
	//      << setw(--priceCell) << right << fixed
	//      << setprecision(2) << total << endl
	//      << setw(29) << left << "Number of Employees"
	//      << setw(++priceCell) << right << EmployeesList.size() << endl;

	fin.close();

	return 0;
}

//*********************************************************************//
// //header files I/O, formatting, strings
// #include <iostream>
// #include <fstream>
// #include <iomanip>
// #include <string>
// using namespace std;

// // function prototypes
// // instructions()- describes the program usage to the user
// void instructions();

// // reportTitle() displays the payroll report titles in columnar format
// void reportTitle();

// // displayEmployeeInfo() displays the information for each employee

// // totalAmounts() displays the total gross and net amounts

// int main()
// {

//   // 1) connect the input file object to payroll.txt

//   // 2) initialize accumulaton variables

// 	// 3) display a descriptive message
// 	instructions();

// 	// 4) display column headings
// 	reportTitle();

//         // 5) attempt to input the first input line

// 	// 6) test the eof() condition

//             // 7) input the remaining doubles on the input line

// 	    // 8) set ifstream beyond the current line

// 	    // 9) test hours >= 40

// 	      // 10) calculate gross & overtime

// 	      // 11) else calculate gross without overtime

// 	    // 12) calculate net pay

// 	    // 13) display info for this employee

// 	    // 14) update accumulation variables

//             // 15) input next name from payroll.txt

// 	// 16) display totals

// 	// 17) disconnect from the input file

// }

// // instructions() describes the program usage to the user
// void instructions()
// {
// 	// display program instructions
// 	cout << "This payroll program calculates an individual "
// 		 << "employee pay and\ncompany totals "
// 		 << "using data from a data file payroll.txt.\n"
// 		 << "\n\nA payroll report showing payroll information "
// 		 << " is displayed.\n\n";
// }


// // reportTitle() displays the payroll report titles in columnar format
// void reportTitle()
// {
// 	// set program formatting
// 	cout << setprecision(2) << fixed << showpoint << left;

// 	// display report titles
// 	cout << setw(20) << "Employee" << setw(10) << "Hourly"
//              << setw(10) << "Hours" << setw(10) << "Tax" << setw(10)
//              << "Gross" << setw(10) << "Net" << endl;

// 	cout << setw(20) << "Name" << setw(10) << "Rate"
//              << setw(10) << "Worked" << setw(10) << "Rate" << setw(10)
//              << "Amount" << setw(10) <<"Amount" << endl << endl;
// }

// // displayEmployeeInfor() displays payroll information for an employee

// // totalAmounts() displays total gross and total net for the input file

