#pragma once
#include "Employee.h"
class Cleaner :
	public Employee
{
	bool harmCond;
public:
	Cleaner(string name, int age, string sex, int workYears, bool harmCond);
	void setHarmCond (bool cond);
	bool getHarmCond()const { return harmCond; }
	void info()const override;
	double getSalary()const override;
};

