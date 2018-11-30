#include "User_admin.h"

int User::counter = 0;


User::User(int number, string login, string password) {
	this->number = number;
	this->login = login;
	this->password = password;
	this->incrementCounter();
}

User::User(string login, string password, int number, string surname, string name, int post, int title, int edication, int status, int salary) : Employee(post, title, edication, status, salary) {
	this->login = login;
	this->password = password;
	this->number = number;
	this->surname = surname;
	this->name = name;
	this->incrementCounter();
}



void User::setSurname(string surname){
	this->surname = surname;
}

void User::setName(string name){
	this->name = name;
}

User hospital(User us, int freeDay){
	us.realSalary(freeDay);
	int salary = us.getSalary();
	salary += int(us.calculateSalary() / 22 * freeDay * 0.9);
	us.setSalary(salary);
	return us;
}



string User::getSurname(){
	return surname;
}

string User::getName(){
	return name;
}

int User::getNumber(){
	return this->number;
}

string User::getLogin(){
	return login;
}

string User::getPassword(){
	return password;
}

void  User::incrementCounter() {
	counter++;
}

int User::getCounter() {
	return counter;
}





void User::createSurnameName(){
	string surname, name;
	cout << endl << "Введите фамилию > ";
	cin >> surname;
	cout << endl << "Введите имя > ";
	cin >> name;
	this->setSurname(surname);
	this->setName(name);

}

void User::createRecord(){
	cout << "***** Создание записи *****" << endl;
	this->createSurnameName();
	this->createPostAndEtc();
	this->createStatus();
	this->realSalary();
}



void User::showHeadRecord() {
	cout << endl << setw(106) << setfill('-') << "-" << endl;
	cout << "|  №|        Фамилия|       Имя|     Должность|     Учёная степень|    Образование|  Статус| Зарплата, p.|" << endl;
	cout << setw(106) << setfill('-') << "-" << endl;
}

void User::showRecord() {
	cout << "|" << setw(3) << setfill(' ') << number << "|";
	cout << setw(15) << setfill(' ') << surname << "|";
	cout << setw(10) << setfill(' ') << name << "|";
	cout << setw(14) << setfill(' ') << this->getPost() << "|";
	cout << setw(19) << setfill(' ')<< this->getTitle() << "|";
	cout << setw(15) << setfill(' ') << this->getEdication() << "|";
	cout << setw(8) <<  setfill(' ') << this->getStatus() << "|";
	cout << setw(13) << setfill(' ') << this->getSalary()  <<  "|" << endl;
	cout << setw(106) << setfill('-') << "-" << endl;
}

void  User::changeRecord(){
	int choice;
	while (true){
		system("cls");
		cout << "***** Изменение записи *****" << endl << endl;
		cout << "Какую часть записи Вы хотите изменить?" << endl;
		cout << "1)Фамилия и Имя" << endl;
		cout << "2)Должность и т.д." << endl;
		cout << "3)Статус (работает, уволен)" << endl;
		cout << "0)Назад" << endl;
		cout << "Выбор > ";
		choice = testInput::test();
		system("cls");
		if (choice == 0) return;
		switch (choice){
		case 1: this->createSurnameName();
			break;
		case 2: this->createPostAndEtc();
			break;
		case 3: this->createStatus();
			break;
		default: cout << "Выберите действие от 0 до 3." << endl;
			_getch();
		}
	}
}