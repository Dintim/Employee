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
		0. exit\n";
		cin >> ch;

		switch (ch)
		{
		case 0:
			cout << "Bye bye\n";
			return;
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
		default:
			unknownCommand();
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
		cout << "1. Accounter\n2. Proger\n3. Director\n4. Sales manager\n5. Office cleaner\n0. Go back\n";
		cin >> ch;
		if (ch > 5) {
			cout << "uknown position\n";
			system("pause");
		}
		else
			break;
	}
	if (ch == 0)
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
		bool cond;
		cout << "Has employee work in harmfull conditions? 1 or 0\n";
		cin >> cond;
		emp = new Cleaner(name, age, sex, exp, cond);
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
		showShortEmpInfo();
		cout << "Choose ID of employee to remove:\n" << endl;
		int ch;
		cin >> ch;
		if (!org.removeEmployeeById(ch)) {
			incorrectId();
			continue;
		}
		cout << "Employee dismissed!\n";
		system("pause");
		return;
	}
}

void OrganizationConsole::showInfo() const
{
	while (true) {
		system("cls");
		cout << "choose employee's id to show full information:\n";
		showShortEmpInfo();
		size_t ch;		
		cout << "0. go back\n";		
		cin >> ch;
		if (ch == 0)
			break;
		bool f=false;
		for (size_t i = 0; i < org.getCntEmployees(); i++)
		{
			if (org[i].getId() == ch) {
				f = true;
				org[i].info();
			}			
		}
		if (f == false) {
			incorrectId();
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
		cout << "choose employee's id to change information:\n";
		showShortEmpInfo();
		cout << setw(3) << left << "0 go back\n";
		int chEmp;
		cin >> chEmp;
		if (chEmp == 0)
			break;
		Employee*e = org.getEmployeeById(chEmp);
		if (e == nullptr) {
			incorrectId();
			continue;
		}
		editEmployeeMenu(e);
		
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

void OrganizationConsole::showShortEmpInfo() const
{
	for (size_t i = 0; i < org.getCntEmployees(); i++)
	{
		cout << setw(3) << left << org[i].getId()
			<< setw(10) << left << string(typeid(org[i]).name()).substr(6)
			<< setw(10) << left << org[i].getName() << endl;
	}
}

void OrganizationConsole::unknownCommand() const
{
	cout << "Unknown command\n";
	system("pause");
	//system("cls");
}

void OrganizationConsole::incorrectId() const
{
	cout << "incorrect id!\n";
	system("pause");
}

void OrganizationConsole::editEmployeeMenu(Employee * emp)
{
	while (true) {
		system("cls");		
		emp->info();
		salaryInfo(emp);
		cout << "\nchoose item:";
		cout << "\n1. change employee info";
		cout << "\n2. dismiss employee";
		cout << "\n3. change position";
		cout << "\n0. go back\n";
		int ch;
		cin >> ch;
		switch (ch)
		{
		case 0:
			return;
		case 1:
			editEmployeeInfo(emp);
			break;
		case 2:
			org.removeEmployeeById(emp->getId());
			cout << "\nEmployee dismissed!\n";
			system("pause");
			return;
		case 3:
			changePosition(emp);
			return;
		default:
			unknownCommand();
			break;
		}
	}
}

void OrganizationConsole::editEmployeeInfo(Employee * emp)
{
	while (true) {
		system("cls");
		emp->info();
		salaryInfo(emp);
		int index = 0;
		cout << "\nchoose information to change:\n";		
		cout << ++index << ". name\n";
		cout << ++index << ". age\n";
		cout << ++index << ". sex\n";
		cout << ++index << ". experience in years\n";
		int pos;
		if (typeid(*emp) == typeid(Proger)) {
			pos = 1;
			cout << ++index << ". count of known languages\n";
			cout << ++index << ". education\n";
		}
		if (typeid(*emp) == typeid(Acounter)) {
			pos = 2;
			cout << ++index << ". 1c experience\n";
		}
		if (typeid(*emp) == typeid(Sales)) {
			pos = 3;
			cout << ++index << ". numbers of active clients\n";
		}
		if (typeid(*emp) == typeid(Cleaner)) {
			pos = 4;
			cout << ++index << ". works in harmful conditions\n";
		}
		cout << "0. go back\n";
		int ch;
		cin >> ch;
		if (ch<0 || ch>index) {
			unknownCommand();
			continue;
		}
		switch (ch)
		{
		case 0:
			return;
		case 1: {
			cout << "\nEnter new name:\n";
			string name;
			cin >> name;
			emp->setName(name);
		}
			break;
		case 2: {
			cout << "\nEnter new age:\n";
			int age;
			cin >> age;
			emp->setAge(age);
		}
			break;
		case 3: {
			cout << "\nEnter new sex:\n";
			string sex;
			cin >> sex;
			emp->setSex(sex);
		}
			break;
		case 4: {
			cout << "\nEnter new experience in years:\n";
			int exp;
			cin >> exp;
			emp->setWorkYears(exp);
		}
			break;
		default: {
			switch (pos)
			{
			case 1:
				if (ch == 5) {
					cout << "\nEnter new count of known languages\n";
					int cnt;
					cin >> cnt;
					((Proger*)emp)->setCntLang(cnt);
				}
				else {					
					cout << "\nHas employee education? 1 or 0\n";
					bool edu;
					cin >> edu;
					((Proger*)emp)->setHasEdu(edu);
				}
				break;
			case 2:
				cout << "\nHas employee 1C experience? 1 or 0\n";
				bool k1c;
				cin >> k1c;
				((Acounter*)emp)->setKnow1C(k1c);
				break;
			case 3:
				cout << "\nEnter new numbers of active clients\n";
				int clients;
				cin >> clients;
				((Sales*)emp)->setClientBase(clients);
				break;
			case 4:
				cout << "\nDoes employee work in harmful conditions? 1 or 0\n";
				bool cond;
				cin >> cond;
				((Cleaner*)emp)->setHarmCond(cond);
				break;
			}
		}
			break;
		}
		system("pause");
	}
}

void OrganizationConsole::changePosition(Employee * emp)
{
	while (true) {
		system("cls");
		cout << "Choose new positin to " << emp->getPosition() << " " << emp->getName() << endl;
		int index = 0, curPos=0;
		if (typeid(*emp) == typeid(Proger)) {
			curPos = 1;
			cout << ++index << ". Accounter\n";
			cout << ++index << ". Director\n";
			cout << ++index << ". Sales manager\n";
			cout << ++index << ". Office cleaner\n";
		}
		if (typeid(*emp) == typeid(Acounter)) {
			curPos = 2;
			cout << ++index << ". Coder\n";
			cout << ++index << ". Director\n";
			cout << ++index << ". Sales manager\n";
			cout << ++index << ". Office cleaner\n";
		}
		if (typeid(*emp) == typeid(Director)) {
			curPos = 3;
			cout << ++index << ". Coder\n";
			cout << ++index << ". Accounter\n";
			cout << ++index << ". Sales manager\n";
			cout << ++index << ". Office cleaner\n";
		}
		if (typeid(*emp) == typeid(Sales)) {
			curPos = 4;
			cout << ++index << ". Coder\n";
			cout << ++index << ". Accounter\n";
			cout << ++index << ". Director\n";
			cout << ++index << ". Office cleaner\n";
		}
		if (typeid(*emp) == typeid(Cleaner)) {
			curPos = 5;
			cout << ++index << ". Coder\n";
			cout << ++index << ". Accounter\n";
			cout << ++index << ". Director\n";
			cout << ++index << ". Sales manager\n";
		}
		cout << "0. go back\n";
		int ch;
		cin >> ch;
		if (ch<0 || ch>index) {
			unknownCommand();
			continue;
		}
		Employee* e = nullptr;
		switch (ch)
		{
		case 0:
			return;
		case 1:
			if (curPos == 1)
				e = new Acounter(emp->getName(), emp->getAge(), emp->getSex(), emp->getWorkYears(), 0);
			else
				e = new Proger(emp->getName(), emp->getAge(), emp->getSex(), emp->getWorkYears(), 0, 0);
			break;
		case 2:
			if (curPos == 1 || curPos == 2)
				e = new Director(emp->getName(), emp->getAge(), emp->getSex(), emp->getWorkYears());
			else
				e = new Acounter(emp->getName(), emp->getAge(), emp->getSex(), emp->getWorkYears(), 0);
			break;
		case 3:
			if (curPos == 4 || curPos == 5)
				e = new Director(emp->getName(), emp->getAge(), emp->getSex(), emp->getWorkYears());
			else
				e = new Sales(emp->getName(), emp->getAge(), emp->getSex(), emp->getWorkYears(), 0);
			break;
		case 4:
			if (curPos == 5)
				e = new Sales(emp->getName(), emp->getAge(), emp->getSex(), emp->getWorkYears(), 0);
			else
				e = new Cleaner(emp->getName(), emp->getAge(), emp->getSex(), emp->getWorkYears(), 0);
			break;		
		}
		org.addEmployee(e);
		org.removeEmployeeById(emp->getId());
		return;
	}
}

void OrganizationConsole::salaryInfo(Employee * emp)const
{
	cout << "salary: " << org.getBaseSalary()*emp->getSalary() << endl;
}



