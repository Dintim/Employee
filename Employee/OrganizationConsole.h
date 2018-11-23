#pragma once
#include "Organization.h"
#include <iostream>
#include "Acounter.h"
#include "Director.h"
#include "Proger.h"
#include "Cleaner.h"
#include "Sales.h"
#include <Windows.h>
#include <conio.h>
#include <iomanip>
using namespace std;

class OrganizationConsole
{

public:
	Organization org;
	OrganizationConsole();
	void start();
private:
	void startMenu();
	void mainMenu();
	void addEmpMenu();
	void removeEmpMenu();
	void showInfo()const;
	void setEmpInfoMenu();

	void setOrgNameMenu();
	void setSalaryMenu();
	void showShortEmpInfo()const;
	void unknownCommand()const;
	void incorrectId()const;

	void editEmployeeMenu(Employee* emp);
	void editEmployeeInfo(Employee* emp);
	void changePosition(Employee* emp);
	void salaryInfo(Employee* emp)const;
};

