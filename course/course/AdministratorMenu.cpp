#include "User_admin.h"

void  Administrator::Header(){
	system("cls");
	cout << endl << " ***** МЕНЮ АДМИНИСТРАТОРА *****" << endl << endl;
}

bool  Administrator::administratorMenu(list<User>& users){
	int choice, findNum;
	cout << " 1)Добавить запись" << endl;
	cout << " 2)Просмотреть все аккаунты" << endl;
	cout << " 3)Просмотреть все записи" << endl;
	cout << " 4)Поиск записи" << endl;
	cout << " 5)Измененить запись" << endl;

	cout << " 6)Просмотреть зарплату за определенный месяц" << endl;

	cout << " 7)Сортировать записи" << endl;
	cout << " 8)Фильтровать записи" << endl;

	cout << " 9)Удалить запись" << endl;
	cout << " 10)Удалить все записи" << endl;
	cout << " 0)Назад\n" << endl;
	cout << " Выбор >> ";

	choice = testInput::test();
	system("cls");
	if (choice == 0) return false;
	switch (choice){
	case 1: 
		if (this->createAccount(users)) {
			list<User>::iterator iterUser = users.begin();
			advance(iterUser, haveUsers - 1);
			(*iterUser).createRecord();
			cout << "Пользователь добавлен." << endl;
		}
		else cout << "Пользователь с таким логином уже создан." << endl;
		break;

	case 2: 
		if (haveUsers != 0) {
			this->showHeadAccount();
			this->showAllAccounts(users);
	    }
		else cout << "Ни один аккаунт не создан." << endl;
		break;

	case 3:	
		if (haveUsers != 0) {
			this->showHeadRecord();
			this->showAllRecords(users);
		}
		else cout << "Записи отсутствуют." << endl;
		break;

	case 4:	
		if ((findNum = this->menufindRecord(users)) == -1) cout << "Запись не найдена." << endl;
		else {
			list<User>::iterator iterUser = users.begin();
			advance(iterUser, findNum - 1);
			(*iterUser).showHeadRecord();
			(*iterUser).showRecord();
		}
		break;

	case 5:	
		if (haveUsers != 0) {
			if ((findNum = this->menufindRecord(users)) == -1) cout << "Запись не найдена." << endl;
			else {
				list<User>::iterator iterUser = users.begin();
				advance(iterUser, findNum - 1);
				(*iterUser).changeRecord();
			}
		}
		else cout << "Записи отсутствуют." << endl;
		break;

	case 6: 
		cout << "Введите номер месяца > ";
		findNum = testInput::test();
		if (findNum <1 || findNum > 12) {
			cout << "Введено неверное значение!" << endl;
			break;
		}
		this->showHeadSalaryByMonth();
		this->showSalaryByMonth(users, findNum);
		break;

	case 7: 
		menuSort(users);
		system("cls");
		if (haveUsers != 0) {
			this->showHeadRecord();
			this->showAllRecords(users);
		}
		else cout << "Записи отсутствуют." << endl;
		break;

	case 8:	this->menuFilter(users);
		break;

	case 9:	
		if (haveUsers != 0) {
				if ((findNum = this->menufindRecord(users)) == -1) cout << "Запись не найдена." << endl;
				else {
					list<User>::iterator iterUser = users.begin();
					advance(iterUser, findNum - 1);
					users.erase(iterUser);
					cout << "Запись удалена." << endl;;
					this->saveAllRecords(users);

				}
			}
			else cout << "Записи отсутствуют." << endl;
			break;

	case 10:
		this->deleteAllRecords(users);
		break;
	default: cout << "Выберите действие от 0 до 10";
	}
	_getch();
	return true;
}