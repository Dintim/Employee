#pragma once
#include "Employee.h"
class Acounter :
	public Employee
{
	bool know1C;
public:
	Acounter(string name, int age, string sex, int workYears, bool know1C);
	void setKnow1C(bool know1C);
	bool getKnow1C()const { return know1C; }

	void info()const override;
	double getSalary()const override;
};

