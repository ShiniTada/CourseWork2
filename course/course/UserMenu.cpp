#include "User_admin.h"

void  User::Header(){
	system("cls");
	cout << endl << " ***** ���� ������������ *****" << endl << endl;
}


bool User::userMenu() {
	int i;
	int freeDay;
	cout << " 1)����������� ������" << endl;
	cout << " 2)����� �������� �� ���� ����" << endl;
	cout << " 3)����� ����������" << endl;
	cout << " 4)���������� �������� �� ��������� ���" << endl;
	cout << " 0)�����\n" << endl;
	cout << " ����� >> ";
	i = testInput::test();
	system("cls");
	if (i == 0) return false;
	switch (i)
	{
	case 1:	this->showHeadRecord();
		this->showRecord();
		_getch();
		break;
	case 2:	cout << "������� ���������� ���� > ";
		freeDay = testInput::test();
		this->realSalary(freeDay);
		break;
	case 3: cout << "������� ���������� ���� > ";
		freeDay = testInput::test();
		(*this) = hospital((*this), freeDay);
		//_getch();
		break;
	case 4: this->showSalary();
		_getch();
		break;
	default: cout << "�������� �������� �� 0 �� 4" << endl;
		_getch();
		break;
	}
	return true;
}