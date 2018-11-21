#include "Employee.h"

int Employee::idSeq = 0;

Employee::Employee(string name, int age, string sex, int workYears)
	:Human(name, age, sex)
{
	this->id = ++idSeq;
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

