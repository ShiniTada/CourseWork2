#include "User_admin.h"

void  User::Header(){
	system("cls");
	cout << endl << " ***** МЕНЮ ПОЛЬЗОВАТЕЛЯ *****" << endl << endl;
}


bool User::userMenu() {
	int i;
	int freeDay;
	cout << " 1)Просмотреть запись" << endl;
	cout << " 2)Взять выходные за свой счёт" << endl;
	cout << " 3)Взять больничный" << endl;
	cout << " 4)Посмотреть зарплату за последний год" << endl;
	cout << " 0)Назад\n" << endl;
	cout << " Выбор >> ";
	i = testInput::test();
	system("cls");
	if (i == 0) return false;
	switch (i)
	{
	case 1:	this->showHeadRecord();
		this->showRecord();
		_getch();
		break;
	case 2:	cout << "Введите количество дней > ";
		freeDay = testInput::test();
		this->realSalary(freeDay);
		break;
	case 3: cout << "Введите количество дней > ";
		freeDay = testInput::test();
		(*this) = hospital((*this), freeDay);
		//_getch();
		break;
	case 4: this->showSalary();
		_getch();
		break;
	default: cout << "Выберите действие от 0 до 4" << endl;
		_getch();
		break;
	}
	return true;
}