#include "Acounter.h"





Acounter::Acounter(string name, int age, string sex, int workYears, bool know1C)
	:Employee(name, age, sex, workYears)
{
	this->know1C = know1C;
}

void Acounter::setKnow1C(bool know1C)
{
	this->know1C = know1C;
}

void Acounter::info() const
{
	Employee::info();
	cout << "knowing of 1C: " << boolalpha << know1C << endl;
}

double Acounter::getSalary() const
{
	double coef = getWorkYears()*0.15;
	coef += know1C * 0.05;
	return coef;
}
