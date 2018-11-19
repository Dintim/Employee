#include "Proger.h"





Proger::Proger(string name, int age, string sex, int workYears, int cntLang, bool hasEdu)
	:Employee(name, age, sex, workYears)
{
	this->cntLang = cntLang;
	this->hasEdu = hasEdu;
}

void Proger::setCntLang(int cntLang)
{
	this->cntLang = cntLang;
}

void Proger::setHasEdu(bool hasEdu)
{
	this->hasEdu = hasEdu;
}

void Proger::info() const
{
	Employee::info();
	cout << "count of languages: " << cntLang << "\nhas education: " << boolalpha << hasEdu << endl;
}

double Proger::getSalary() const
{
	double coef = cntLang * 0.1;
	coef += getWorkYears()*0.1;
	coef += hasEdu * 0.02;
	return coef;
}
