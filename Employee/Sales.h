#pragma once
#include "Employee.h"
class Sales :
	public Employee
{
	int clientBase;
public:
	Sales(string name, int age, string sex, int workYears, int clientBase);
	void setClientBase(int clienBase);

	int getClientBase()const { return clientBase; }

	void info()const override;
	double getSalary()const override;
};

