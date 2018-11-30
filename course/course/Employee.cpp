#include "User_admin.h"

Employee::~Employee(){}


Employee::Employee(int post, int title, int edication, int status, int salary){
	this->setPost(post);
	this->setTitle(title);
	this->setEdication(edication);
	this->setStatus(status);
	this->realSalary();
}

bool Employee::setPost(int choice) {
	switch (choice) {
	case 1: post = rector; break;
	case 2: post = dean; break;
	case 3: post = deputyDean; break;
	case 4: post = teacher; break;
	default: cout << "Выберете 1-4 должность!" << endl;
	}
	if (choice > 0 && choice < 5) return true;
	else return false;
}

bool Employee::setTitle(int choice) {
	switch (choice) {
	case 1: title = academician; break;
	case 2: title = phD; break;
	case 3: title = professor; break;
	case 4: title = docent; break;
	case 5: title = master; break;
	default: cout << "Выберете 1-5 учебное звание!" << endl;
	}
	if (choice > 0 && choice < 6) return true;
	else return false;
}

bool Employee::setEdication(int choice) {
	switch (choice) {
	case 1: edication = higher; break;
	case 2: edication = generalAverage; break;
	default: cout << "Выберете 1-2 образование!" << endl;
	}
	if (choice > 0 && choice < 4) return true;
	else return false;
}


bool Employee::setStatus(int choice) {
	switch (choice) {
	case 0: status = fired; break;
	case 1: status = working; break;
	default: cout << "Выберете 0-1 статус!" << endl;
	}
	if (choice >= 0 && choice < 2) return true;
	else return false;
}

void Employee::setSalary(int salary){
	int s = salary;
	this->salary[nowMonth] = s;
}

int Employee::calculateSalary(){
	double salary = 0.;
	salary += 60 / (post * 0.1);
	salary += 50 / (title * 0.1);
	salary += 50 / (edication * 0.1);
	salary *= status;
	salary = (int)salary;
	return salary;
}

void Employee::realSalary(int freeDay){
	int oclad = calculateSalary();
	int  NDFL;
	int month = 1;
	for (; month < 13 && month <= nowMonth; month++){
		if (month == 4 || month == 6 || month == 9 || month == 11){
			if (month == nowMonth) salary[month] = oclad / 22 * (21 - freeDay);
			else  salary[month] = oclad / 22 * 21;
		}
		if (month == 2){
			if (month == nowMonth) salary[month] = oclad / 22 * (20 - freeDay);
			salary[month] = oclad / 22 * 20;
		}
		if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12){
			if (month == nowMonth) salary[month] = oclad / 22 * (22 - freeDay);
			else  salary[month] = oclad;
		}
		NDFL = salary[month] / 100 * 13;
		salary[month] -= NDFL;
	}
	while (month < 13) {
		salary[month] = 0;
		month++;
	}

}



int Employee::getSalary(int month){
	return salary[month];
}

void Employee::showSalary(){
	cout << endl << setw(28) << setfill('-') << "-" << endl;
	cout << "| Номер месяца|    Зарплата|" << endl;
	cout << setw(28) << setfill('-') << "-" << endl;
	for (int month = 1; month < 13 && month <= nowMonth; month++){
		cout << "|" << setw(13) << setfill(' ') << month << "|" << setw(12) << salary[month] << "|";
		cout << endl << setw(28) << setfill('-') << "-" << endl;
	}
}

void Employee::createPostAndEtc(){
	int choice;
	cout << endl << "Должности:\n 1.Ректор\n 2.Декан\n 3.Замдекана\n 4.Преподаватель" << endl;
	while (true) {
		cout << "Ваш выбор > ";
		choice = testInput::test();
		if (this->setPost(choice)) break;
	}

	cout << endl << "Учёные степени:\n 1.Академик\n 2.Кандидат наук\n 3.Профессор\n 4.Доцент\n 5.Магистр" << endl;
	while (true) {
		cout << "Ваш выбор > ";
		choice = testInput::test();
		if (this->setTitle(choice)) break;
	}
	cout << endl << "Образование:\n 1.Высшее \n 2.Общее среднее" << endl;
	while (true) {
		cout << "Ваш выбор > ";
		choice = testInput::test();
		if (this->setEdication(choice)) break;
	}
	this->realSalary();
}

void Employee::createStatus(){
	int choice;
	cout << endl << "Статусы:\n 0.Уволен\n 1.Работаю" << endl;
	while (true) {
		cout << "Ваш выбор > ";
		choice = testInput::test();
		if (this->setStatus(choice)) break;
	}
	this->realSalary();
}



string Employee::getPost(){
	string res;
	switch (post) {
		case 1: res = "Ректор"; break;
		case 2: res = "Декан"; break;
		case 3: res = "Замдекан"; break;
		case 4: res = "Преподаватель"; break;
	}
	return res;
}


string Employee::getTitle(){
	string res;
	switch (title) {
		case 1: res = "Академик"; break;
		case 2: res = "Кандидат наук"; break;
		case 3: res = "Профессор"; break;
		case 4: res = "Доцент"; break;
		case 5: res = "Магистр"; break;
	}
	return res;
}

string Employee::getEdication(){
	string res;
	switch (edication) {
		case 1: res = "Высшее"; break;
		case 2: res = "Общее среднее"; break;
	}
	return res;
}

string Employee::getStatus(){
	string res;
	switch (status) {
		case 0: res = "Уволен"; break;
		case 1: res = "Работаю"; break;
	}
	return res;
}



int Employee::getPostForFile(){
	return post;
}

int Employee::getTitleForFile(){
	return title;
}

int Employee::getEdicationForFile(){
	return edication;
}

int Employee::getStatusForFile(){
	return status;
}