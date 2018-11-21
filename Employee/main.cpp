#include "OrganizationConsole.h"

void main()
{
	OrganizationConsole e;
	e.org.addEmployee(new Acounter("Petya", 30, "male", 15, 1));
	e.org.addEmployee(new Proger("Masha", 40, "female", 20, 6, 1));
	e.org.addEmployee(new Director("Dinara", 35, "female", 15));
	e.start();
	system("pause");
}