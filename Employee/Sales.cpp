#include "Sales.h"




Sales::Sales(string name, int age, string sex, int workYears, int clientBase)
	:Employee(name, age, sex, workYears)
{
	this->clientBase = clientBase;
}

void Sales::setClientBase(int clienBase)
{
	this->clientBase = clienBase;
}

void Sales::info() const
{
	Employee::info();
	cout << "base of clients: " << clientBase << endl;
}

double Sales::getSalary() const
{
	double coef = clientBase * 0.2;
	coef += getWorkYears()*0.05;
	return coef;
}
