#include "Employee.h"



Employee::Employee(string name, int age, string sex, int workYears)
	:Human(name, age, sex)
{
	this->workYears = workYears;
}

void Employee::setWorkYears(int workYears)
{
	this->workYears = workYears;
}

void Employee::info() const
{
	Human::info();
	cout << "working years: " << workYears << endl;
}

double Employee::getSalary() const
{
	return 0;
}
