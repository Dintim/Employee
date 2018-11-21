#include "Organization.h"




Organization::Organization(string name, int baseSalary)
{
	this->name = name;
	this->baseSalary = baseSalary;
}

void Organization::setName(string name)
{
	this->name = name;
}

void Organization::setBaseSalary(int baseSalary)
{
	this->baseSalary = baseSalary;
}

void Organization::addEmployee(Employee * emp)
{
	employees.push_back(unique_ptr<Employee>(emp));
}

void Organization::delEmployee(Employee * emp)
{
	for (size_t i = 0; i < employees.size(); i++)
	{
		if (employees[i].get() == emp) {
			employees.erase(begin(employees) + i);
			return;
		}
	}
}

bool Organization::removeEmployeeById(int id)
{
	for (size_t i = 0; i < employees.size(); i++)
	{
		if (employees[i]->getId() == id) {
			employees.erase(begin(employees) + i);
			return true;
		}
	}
	return false;
}

void Organization::getInfo() const
{
	for (size_t i = 0; i < employees.size(); i++)
	{
		cout << "position: " << string(typeid(*employees[i]).name()).substr(6) << endl;
		employees[i]->info();
		cout << "salary: " << employees[i]->getSalary()*baseSalary << endl << endl;
	}
}

double Organization::getSalaryFund() const
{
	double res = 0;
	for (size_t i = 0; i < employees.size(); i++)
	{
		res += employees[i]->getSalary()*baseSalary;
	}
	return res;
}
