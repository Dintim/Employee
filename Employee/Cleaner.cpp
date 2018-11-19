#include "Cleaner.h"




Cleaner::Cleaner(string name, int age, string sex, int workYears)
	:Employee(name, age, sex, workYears)
{
}

double Cleaner::getSalary() const
{
	double coef = 1;
	coef += getWorkYears()*0.02;
	return coef;
}
