#pragma once
#include "Employee.h"
#include <vector>
using namespace std;

class Organization
{
	string name;
	vector<unique_ptr<Employee>>employees;
	int baseSalary;
public:
	Organization(string name, int baseSalary);
	void setName(string name);
	string getName()const { return name; }
	void setBaseSalary(int baseSalary);
	int getBaseSalary()const { return baseSalary; }

	void addEmployee(Employee* emp);
	void delEmployee(Employee* emp);
	bool removeEmployeeById(int id);
	void getInfo()const;
	double getSalaryFund()const;
	int getCntEmployees()const { return employees.size(); }
	Employee& operator[](int index) { return *employees[index]; }
	const Employee& operator[](int index) const { return *employees[index]; }

	Employee* getEmployeeById(int id);
	const Employee* getEmployeeById(int id)const;
	
};

