#include "Cleaner.h"




Cleaner::Cleaner(string name, int age, string sex, int workYears, bool harmCond)
	:Employee(name, age, sex, workYears)
{
	this->harmCond = harmCond;
}

void Cleaner::setHarmCond(bool cond)
{
	this->harmCond = cond;
}

void Cleaner::info() const
{
	Employee::info();
	cout << "works in harmfull conditions: " << boolalpha << harmCond << endl;
}

double Cleaner::getSalary() const
{
	double coef = harmCond*0.1;
	coef += getWorkYears()*0.02;
	return coef;
}
