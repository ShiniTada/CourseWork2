#include "User_admin.h"


void Administrator::showHeadAccount() {
	cout << endl << setw(33) << setfill('-') << "-" << endl;
	cout << "|  №|        Логин|       Пароль|" << endl;
	cout << setw(33) << setfill('-') << "-" << endl;
}

void Administrator::showAllAccounts(list<User> users){
	list<User>::iterator iterUser = users.begin();
	while (iterUser != users.end()){
		cout << "|" << setw(3) << setfill(' ') << (*iterUser).getNumber() << "|";
		cout << setw(13) << setfill(' ') << (*iterUser).getLogin() << "|";
		cout << setw(13) << setfill(' ') << (*iterUser).getPassword() << "|" << endl;
		cout << setw(33) << setfill('-') << "-" << endl;
		iterUser++;
	}
}

void Administrator::showAllRecords(list<User> users){
	list<User>::iterator iterUser = users.begin();
	while (iterUser != users.end()){
		(*iterUser).showRecord();
		iterUser++;
	}
}

void Administrator::showHeadSalaryByMonth(){
	cout << endl << setw(45) << setfill('-') << "-" << endl;
	cout << "|  №|        Фамилия|       Имя| Зарплата, p.|" << endl;
	cout << setw(45) << setfill('-') << "-" << endl;
}

void Administrator::showSalaryByMonth(list<User> users, int month){
	list<User>::iterator iterUser = users.begin();
	while (iterUser != users.end()){
		cout << "|" << setw(3) << setfill(' ') << (*iterUser).getNumber() << "|";
		cout << setw(15) << setfill(' ') << (*iterUser).getSurname() << "|";
		cout << setw(10) << setfill(' ') << (*iterUser).getName() << "|";
		cout << setw(13) << setfill(' ') << (*iterUser).getSalary(month) << "|" << endl;
		cout << setw(45) << setfill('-') << "-" << endl;
		iterUser++;
	}
	this->getSalary(month);
}



int  Administrator::menufindRecord(list<User> users){
	
	int choice, number = -1;
	system("cls");
	cout << "***** Поиск записи *****" << endl << endl;
	cout << "Формы поиска" << endl;
	cout << "1)Номер" << endl;
	cout << "2)Фамилия и Имя" << endl;
	cout << "0)Назад" << endl;
	cout << "Выбор > ";
	choice = testInput::test();
	system("cls");
	if (choice == 0) return number;
	switch (choice){
	case 1: number = this->findRecordByNum(users);
			break;
	case 2: number = this->findRecordByName(users);
			break;
	default: cout << "Выберите действие от 0 до 2." << endl;
	}
	return number;
}

int  Administrator::findRecordByNum(list<User> users){
	int number;
	cout << endl << "Введите № > ";
	number = testInput::test();
	
	list<User>::iterator iterUser = users.begin();
	while (iterUser != users.end()){
		if ((*iterUser).getNumber() == number) return (*iterUser).getNumber();
		iterUser++;
	}
	return -1;
}

int  Administrator::findRecordByName(list<User> users){
	string surname, name;
	cout << endl << "----Предупреджение! Найдется только первый пользователь с введёнными значениями!----" << endl;
	cout << endl << "Введите фамилию > ";
	cin >> surname;
	cout << endl << "Введите имя > ";
	cin >> name;

	list<User>::iterator iterUser = users.begin();
	while (iterUser != users.end()){
		if ((*iterUser).getSurname() == surname && (*iterUser).getName() == name) return (*iterUser).getNumber();
		iterUser++;
	}
	return -1;  
}


void Administrator::menuFilter(list<User> users)
{
	int choice;
	cout << "***** Фильтрация записей *****" << endl;
	cout << "1)Деканы" << endl;
	cout << "2)Замдеканы" << endl;
	cout << "3)Зарплата > 600" << endl;
	cout << "0)Назад" << endl;
	cout << "Выбор >> ";
	choice = testInput::test();
	system("cls");
	if (choice == 0) return;
	switch (choice)
	{
	case 1: if (!filter(users, 2)) cout << "Записей по параметру не найдено." << endl;
		break;
	case 2:	if (!filter(users, 3)) cout << "Записей по параметру не найдено." << endl;
		break;
	case 3:if (!filter(users)) cout << "Записей по параметру не найдено." << endl;
		break;
	default: cout<<"Выберите действие от 0 до 3"<< endl;
		_getch();
	}
}

bool  Administrator::filter(list<User> users, int post){
	bool first = true;
	list<User>::iterator iterUser = users.begin();
	while (iterUser != users.end()){
		if (((*iterUser).getPostForFile() == post)){
			if (first) {
				(*iterUser).showHeadRecord();
				first = false;
			}
			(*iterUser).showRecord();
		}
		iterUser++;
	}
	if (first) return false;
	return true;
}

bool  Administrator::filter(list<User> users){
	bool first = true;
	list<User>::iterator iterUser = users.begin();
	while (iterUser != users.end()){
		if (((*iterUser).getSalary() > 600)){
			if (first) {
				(*iterUser).showHeadRecord();
				first = false;
			}
			(*iterUser).showRecord();
		}
		iterUser++;
	}
	if (first) return false;
	return true;
}

void Administrator::menuSort(list<User>& users){
	int choice;
	cout << "***** Сортировка записей *****" << endl;
	cout << "1)Фамилия" << endl;
	cout << "2)Номер" << endl;
	cout << "3)Зарплата" << endl;
	cout << "0)Назад" << endl;
	cout << "Выбор >> ";
	choice = testInput::test();
	system("cls");
	if (choice == 0) return;
	switch (choice){
	case 1: users.sort(SortingBySurname<User&>());
		break;
	case 2:users.sort(SortingByNumber<User&>());
		break;
	case 3:users.sort(SortingBySalary<User&>());
		break;
	default:cout << "Выберите действие от 0 до 3" << endl;
	}
}
