#include "OrganizationConsole.h"



OrganizationConsole::OrganizationConsole()
	:org("",0)
{
	startMenu();
}

void OrganizationConsole::start()
{
	mainMenu();
}

void OrganizationConsole::startMenu()
{
	system("cls");
	cout << "Welcome!\n";
	Sleep(2000);
	this->setOrgNameMenu();
	this->setSalaryMenu();
}

void OrganizationConsole::mainMenu()
{
	int ch = 0;
	while (ch != 5) {
		system("cls");
		cout << "Organization name: " << org.getName();
		cout << "\nSalary: " << org.getBaseSalary();
		cout << "\nCount of employee: " << org.getCntEmployees();
		cout << "\n\n-------------\n\n";
		cout << "\
		1. add new employee\n\
		2. dismiss employee\n\
		3. show employees info\n\
		4. set new employee's info\n\
		5. exit\n";
		cin >> ch;

		switch (ch)
		{
		case 1:
			addEmpMenu();
			break;
		case 2:
			removeEmpMenu();
			break;
		case 3:
			showInfo();
			break;
		case 4:
			setEmpInfoMenu();
			break;
		case 5:
			break;
		default:
			cout << "Unknown command\npress any key to continue\n";
			system("pause");
			system("cls");
			break;
		}
	}
	cout << "Bye bye\n";
}

void OrganizationConsole::addEmpMenu()
{
	string name;
	int age;
	string sex;
	int exp;
	system("cls");
	cout << "Set employee name\n";
	cin >> name;
	cout << "set employee age\n";
	cin >> age;
	cout << "set employee sex\n";
	cin >> sex;
	cout << "set employee experience\n";
	cin >> exp;
	size_t ch;
	while (true) {
		system("cls");
		cout << "choose position:\n";
		cout << "1. Accounter\n2. Proger\n3. Director\n4. Sales manager\n5. Office cleaner\n6. Main menu\n";
		cin >> ch;
		if (ch > 6) {
			cout << "uknown position\n";
			system("pause");
		}
		else
			break;
	}
	if (ch == 6)
		return;
	Employee*emp = nullptr;
	switch (ch)
	{
	case 1:
		bool know1C;
		cout << "Has employee 1c experience? 1 or 0\n";
		cin >> know1C;
		emp = new Acounter(name, age, sex, exp, know1C);
		break;
	case 2:
		int cntLang;
		bool hasEdu;
		cout << "How many languages employee knows?\n";
		cin >> cntLang;
		cout << "Has employee high education? 1 or 0\n";
		cin >> hasEdu;
		emp = new Proger(name, age, sex, exp, cntLang, hasEdu);
		break;
	case 3:
		emp = new Director(name, age, sex, exp);
		break;
	case 4:
		int clientBase;
		cout << "How many active clients employee has?\n";
		cin >> clientBase;
		emp = new Sales(name, age, sex, exp, clientBase);
		break;
	case 5:
		emp = new Cleaner(name, age, sex, exp);
		break;
	}
	org.addEmployee(emp);
	system("cls");
	cout << "Employee added!\n";
	system("pause");
}

void OrganizationConsole::removeEmpMenu()
{
	while (true) {
		system("cls");
		for (size_t i = 0; i < org.getCntEmployees(); i++)
		{
			cout << setw(3) << left << org[i].getId()
				<< setw(10) << left << string(typeid(org[i]).name()).substr(6)
				<< setw(10) << left << org[i].getName() << endl;
		}
		cout << "Choose ID of employee to remove:\n" << endl;
		int ch;
		cin >> ch;
		if (!org.removeEmployeeById(ch)) {
			cout << "incorrect id!\n";
			system("pause");
			continue;
		}
		cout << "Employee dismissed!\n";
		system("pause");
		return;
	}
}

void OrganizationConsole::showInfo() 
{
	while (true) {
		system("cls");
		for (size_t i = 0; i < org.getCntEmployees(); i++)
		{
			cout << setw(3) << left << org[i].getId()
				<< setw(10) << left << string(typeid(org[i]).name()).substr(6)
				<< setw(10) << left << org[i].getName() << endl;
		}
		size_t ch;
		cout << "choose employee's id to show full information:\n";
		cin >> ch;
		bool f=false;
		for (size_t i = 0; i < org.getCntEmployees(); i++)
		{
			if (org[i].getId() == ch) {
				f = true;
				org[i].info();
			}			
		}
		if (f == false) {
			cout << "incorrect id!\n";
			system("pause");
			continue;
		}
		system("pause");
		return;
	}

}

void OrganizationConsole::setEmpInfoMenu()
{
	while (true) {
		system("cls");
		for (size_t i = 0; i < org.getCntEmployees(); i++)
		{
			cout << setw(3) << left << org[i].getId()
				<< setw(10) << left << string(typeid(org[i]).name()).substr(6)
				<< setw(10) << left << org[i].getName() << endl;
		}
		cout << "\nchoose employee's id whum info you want change:\n";
		size_t chEmp;
		cin >> chEmp;
		bool f = false;
		for (size_t i = 0; i < org.getCntEmployees(); i++)
		{
			if (org[i].getId() == chEmp) {
				f = true;
				size_t ch=0;
				cout << "What you want to change?\n";
				cout << "1. Name\n2. Age\n3. Sex\n4. Working experience\n";
				string pos = string(typeid(org[i]).name()).substr(6);
				if (pos == "Acounter") 
					cout << "5. 1C experience\n";
				if (pos=="Proger")
					cout << "5. Numbers of languages\n6. Having high education\n";
				if (pos == "Sales")
					cout << "5. Numbers of clients\n";			
				cin >> ch;				

				if (ch == 1) {
					string newName;
					cout << "Enter new name:\n";
					cin >> newName;
					org[i].setName(newName);					
				}
				if (ch == 2) {
					int newAge;
					cout << "Enter new age:\n";
					cin >> newAge;
					org[i].setAge(newAge);					
				}
				if (ch == 3) {
					string newSex;
					cout << "Enter new sex:\n";
					cin >> newSex;
					org[i].setSex(newSex);					
				}
				if (ch == 4) {
					int newExp;
					cout << "Enter new years of experience:\n";
					cin >> newExp;
					org[i].setWorkYears(newExp);					
				}
				if (ch == 5) {
					cout << "error";
				}
				if (ch == 6) {
					cout << "error";
				}
				if (ch > 6) {
					cout << "Unknown command\npress any key to continue\n";
					system("pause");
					system("cls");					
				}				
			}
		}
		if (f == false) {
			cout << "incorrect id!\n";
			system("pause");
			continue;
		}
		system("pause");
		return;
	}
}

void OrganizationConsole::setOrgNameMenu()
{
	system("cls");
	cout << "Set organization name:\n";
	string name;
	cin >> name;
	org.setName(name);
}

void OrganizationConsole::setSalaryMenu()
{
	system("cls");
	cout << "Set base salary:\n";
	int salary;
	cin >> salary;
	org.setBaseSalary(salary);
}



