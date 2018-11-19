#pragma once
#include "Human.h"
class Employee :
	public Human
{
	int workYears;
public:
	Employee(string name, int age, string sex, int workYears);
	void setWorkYears(int workYears);
	int getWorkYears()const { return workYears; }

	void info()const override;
	virtual double getSalary()const;
};

