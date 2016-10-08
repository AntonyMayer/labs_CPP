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

double total_gross, total_net;

/************************************************************************/
class Employee {
public:
	string name;
	double rate, hours, tax, gross_sallary, net_sallary;
	void set_values ();
	double calc_gross_sallary (void);
	void display_values(int);
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

void Employee::display_values (int z) {
	cout << setprecision(2) << fixed << showpoint << left;
	cout << setw(z) << name << setw(10) << rate
	     << setw(10) << hours << setw(10) << tax << setw(10)
	     << gross_sallary << setw(10) << net_sallary << endl;
}
/************************************************************************/
void instructions() {
	cout << "\nThis payroll program calculates an individual "
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
	     << "Amount" << setw(10) << "Amount" << endl << endl;
}
void displayEmployeeInfo(vector<Employee> list) {
	for (int i = 0; i < list.size(); i++) {
		int width = 20;
		if (i > 0) width = 21;
		list[i].display_values(width);
		total_gross += list[i].gross_sallary;
		total_net += list[i].net_sallary;
	}
}
void totalAmounts() {
	cout << setprecision(2) << fixed << showpoint << left;
	cout << setw(20) << "\nTotal" << setw(31) << " " << setw(10)
	     << total_gross << setw(10) << total_net << endl;
}
/************************************************************************/

int main()
{
	vector<Employee> EmployeesList;
	
	instructions();
	reportTitle();

	fin.open("payroll.txt");
	if (!fin.is_open()) {
		cout << "404 Not Found" << endl;
		return 0;
	}
	for (int i = 0; !fin.eof(); i++) {
		Employee newItem;
		EmployeesList.push_back(newItem);
		EmployeesList[i].set_values();
	}
	fin.close();

	displayEmployeeInfo(EmployeesList);
	totalAmounts();

	return 0;
}