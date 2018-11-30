#include "User_admin.h"

void  Administrator::Header(){
	system("cls");
	cout << endl << " ***** ���� �������������� *****" << endl << endl;
}

bool  Administrator::administratorMenu(list<User>& users){
	int choice, findNum;
	cout << " 1)�������� ������" << endl;
	cout << " 2)����������� ��� ��������" << endl;
	cout << " 3)����������� ��� ������" << endl;
	cout << " 4)����� ������" << endl;
	cout << " 5)���������� ������" << endl;

	cout << " 6)����������� �������� �� ������������ �����" << endl;

	cout << " 7)����������� ������" << endl;
	cout << " 8)����������� ������" << endl;

	cout << " 9)������� ������" << endl;
	cout << " 10)������� ��� ������" << endl;
	cout << " 0)�����\n" << endl;
	cout << " ����� >> ";

	choice = testInput::test();
	system("cls");
	if (choice == 0) return false;
	switch (choice){
	case 1: 
		if (this->createAccount(users)) {
			list<User>::iterator iterUser = users.begin();
			advance(iterUser, haveUsers - 1);
			(*iterUser).createRecord();
			cout << "������������ ��������." << endl;
		}
		else cout << "������������ � ����� ������� ��� ������." << endl;
		break;

	case 2: 
		if (haveUsers != 0) {
			this->showHeadAccount();
			this->showAllAccounts(users);
	    }
		else cout << "�� ���� ������� �� ������." << endl;
		break;

	case 3:	
		if (haveUsers != 0) {
			this->showHeadRecord();
			this->showAllRecords(users);
		}
		else cout << "������ �����������." << endl;
		break;

	case 4:	
		if ((findNum = this->menufindRecord(users)) == -1) cout << "������ �� �������." << endl;
		else {
			list<User>::iterator iterUser = users.begin();
			advance(iterUser, findNum - 1);
			(*iterUser).showHeadRecord();
			(*iterUser).showRecord();
		}
		break;

	case 5:	
		if (haveUsers != 0) {
			if ((findNum = this->menufindRecord(users)) == -1) cout << "������ �� �������." << endl;
			else {
				list<User>::iterator iterUser = users.begin();
				advance(iterUser, findNum - 1);
				(*iterUser).changeRecord();
			}
		}
		else cout << "������ �����������." << endl;
		break;

	case 6: 
		cout << "������� ����� ������ > ";
		findNum = testInput::test();
		if (findNum <1 || findNum > 12) {
			cout << "������� �������� ��������!" << endl;
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
		else cout << "������ �����������." << endl;
		break;

	case 8:	this->menuFilter(users);
		break;

	case 9:	
		if (haveUsers != 0) {
				if ((findNum = this->menufindRecord(users)) == -1) cout << "������ �� �������." << endl;
				else {
					list<User>::iterator iterUser = users.begin();
					advance(iterUser, findNum - 1);
					users.erase(iterUser);
					cout << "������ �������." << endl;;
					this->saveAllRecords(users);

				}
			}
			else cout << "������ �����������." << endl;
			break;

	case 10:
		this->deleteAllRecords(users);
		break;
	default: cout << "�������� �������� �� 0 �� 10";
	}
	_getch();
	return true;
}