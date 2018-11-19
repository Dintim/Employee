#pragma once
#include "Employee.h"
class Cleaner :
	public Employee
{
public:
	Cleaner(string name, int age, string sex, int workYears);
	
	double getSalary()const override;
};

