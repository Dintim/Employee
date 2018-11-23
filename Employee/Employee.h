#pragma once
#include "Human.h"
class Employee :
	public Human
{
	static int idSeq;
	int id;
	int workYears;
public:
	Employee(string name, int age, string sex, int workYears);
	void setWorkYears(int workYears);
	int getWorkYears()const { return workYears; }

	void info()const override;
	virtual double getSalary()const=0;
	int getId()const { return id; }
	string getPosition()const { return string(typeid(*this).name()).substr(6); }
	
};

