/*учет зп отрудников вуза*/

#include "User_admin.h"

int main(void)
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	Administrator admin;
	User *pointerToAll;
	User mainUser;
	list<User> users;
	int findNumUser;
	bool noStop;

	//открытие файлов, считывание
	if (!(admin.readRecordsInFile(users))) cout << "Данные о записях не считаны" << endl;

	while (1)
	{
		system("cls");
		cout << endl  << " ***** ГЛАВНОЕ МЕНЮ *****" << endl << endl;
		
		cout << " 1)Вход администратора" << endl;
		cout << " 2)Вход пользователя" << endl;
		cout << " 0)Выход\n" << endl;
		cout << " Выбор >> ";
		int choice = testInput::test();
		system("cls");
		noStop = true;
		if (choice == 0) break;
		switch (choice){
		case 1: 
			pointerToAll = &admin;   //ПОЛИМОРФИЗМ  ВРЕМЕНИ ВЫПОЛНЕНИЯ
			if (admin.check()){
				while (noStop){
					pointerToAll->Header();
					noStop = admin.administratorMenu(users);
				}
			}
			else _getch();
			break;
		case 2: pointerToAll = &mainUser;  
			if ((findNumUser = mainUser.check(users)) != -1){
				list<User>::iterator iterUser = users.begin();
				advance(iterUser, findNumUser - 1);
				while (noStop){
					pointerToAll->Header();
					noStop = (*iterUser).userMenu();
				}
			}
			else _getch();
			break;
		default: cout<< " Выберите действие от 0 до 2" << endl;
			_getch();
		}
		admin.saveAllRecords(users);
	}
	return 0;
}

int testInput::test()
{
	int res2, i;
	do {
		res2 = scanf("%d", &i);
		while (getchar() != '\n');
		if (res2 != 1) cout << "Введите число!"<< endl;
	} while (res2 != 1);
	return i;
}