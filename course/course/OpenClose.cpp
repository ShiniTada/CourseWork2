#include "User_admin.h"


bool Administrator::check(){
	char *login_adm = new char[20];
	char *password_adm = new char[20]; // динамически
	string login_admin, password_admin;

	ifstream fin("admin.txt");
	ofstream fout("admin.txt", ios::app);
	system("cls");
	if (!fin){
		cout << "В программе нет администратора. Задайте логин и пароль для администратора" << endl << endl;
		cout << "Введите логин: ";
	
		cin >> login_admin;
		cout << "Введите пароль: ";
		cin >> password_admin;
		fout << login_admin.c_str() << "\t" << encryption(login_admin, password_admin);
		fout.close();
		this->login= login_admin;
		this->password= password_admin;
		cout << endl << "Логин и пароль для администратора успешно созданы" << endl;
		return false; 
	}

	fout.close();
	cout << endl << setw(10) << setfill('*') << "*" << " Вход для администратора " << setw(10) << setfill('*') << "*" << endl << endl;

	cout << "Введите логин: ";
	int i = 0;
	while (true){
		login_adm[i] = _getch();
		if (login_adm[i] == '\r') break;
		if (login_adm[i] == '\b'){
			cout << "\b\b";
			i--;
		}
		else{
			cout << "*";
			i++;
		}
	}
	login_adm[i] = '\0';
	cout << endl;
	i = 0;
	printf("Введите пароль: ");
	while (true){
		password_adm[i] = _getch();
		if (password_adm[i] == '\r') break;
		if (password_adm[i] == '\b'){
			cout << "\b\b";
			i--;
		}
		else{
			cout << "*";
			i++;
		}
	}
	password_adm[i] = '\0';
	cout << endl;
	login_admin = (const char*)login_adm;
	password_admin = (const char*)password_adm;

	delete[] login_adm;
	delete[] password_adm;

	string  login_in_file, password_in_file;
	fin >> login_in_file >> password_in_file;
	string truePassword = decryption(login_in_file, password_in_file);
	this->login = login_in_file;
	this->password = truePassword;
	fin.close();
	if (this->login == login_admin && this->password == password_admin)  return true;
	else
	{
		cout << "Логин или пароль введён неверно.";
		return false;
	}
}

int User::check(list<User> users){
	int i = 0;
	char login_us[20], password_us[20];
	system("cls");
	cout << endl <<setw(10) << setfill('*') << "*" << " Вход для пользователя " << setw(10) << setfill('*') << "*" << endl << endl;
	printf("Введите логин: ");
	while (true){
		login_us[i] = _getch();
		if (login_us[i] == '\r') break;
		if (login_us[i] == '\b'){
			printf("%s", "\b\b");
			i--;
		}
		else{	
			printf("%c", '*');
			i++;
		}
	}
	login_us[i] = '\0';
	cout << endl;
	i = 0;
	printf("Введите пароль: ");
	while (true){
		password_us[i] = _getch();
		if (password_us[i] == '\r') break;
		if (password_us[i] == '\b'){
			printf("%s", "\b\b");
			i--;
		}
		else{
			printf("%c", '*');
			i++;
		}
	}
	password_us[i] = '\0';
	cout << endl;

	string password_user, login_user;
	login_user = (const char*)login_us;
	password_user = (const char*)password_us;

	list<User>::iterator iterUser = users.begin();
	while (iterUser != users.end()){
		if (login_user == (*iterUser).getLogin() && password_user == (*iterUser).getPassword())	return (*iterUser).number;
		*iterUser++;
	}
	cout<<"Логин или пароль введён неверно."<< endl;
	return -1;
}

string encryption(string login, string password)
{
	string encryptedPW = password;
	for (int i = 0; i < password.length(); i++)
	{
		encryptedPW[i] = (password[i] + login[0]);
	}
	return encryptedPW;
}

string decryption(string login, string password)
{
	string decryptedPW = password;
	for (int i = 0; i < password.length(); i++)
	{
		decryptedPW[i] = (password[i] - login[0]);
	}
	//cout << decryptedPW << endl;
	return decryptedPW;
}




void Administrator::nowHaveUsers(list<User> users){
	string login_in_file, password_in_file;
	int ignor;
	ifstream fin("account.txt");
	this->haveUsers = 0;
	if (!fin){
		fin.close();
		return;
	}
	while (!fin.eof()){
		fin >> ignor >> login_in_file >> password_in_file;
		haveUsers++;
	}
	fin.close();
}

bool Administrator::createAccount(list<User>& users){
	string login, password;
	int have;
	cout << endl << "***** Создание аккаунта *****" << endl << endl;
	this->nowHaveUsers(users);

	cout << "Введите имя аккаунта > ";
	cin >> login;
	cout << "Введите для него пароль > ";
	cin >> password;

	haveUsers++;
	
	string password_user, login_user, truePassword;
	ifstream fin("account.txt", ios_base::app); //дозапись в конец файла
	ofstream fout("account.txt", ios_base::app);
	while (!fin.eof())
	{
		fin >> have >> login_user >> password_user;
		truePassword = decryption(login_user, password_user);
		if (login == login_user &&  password == truePassword) return false;
	}
	fout << endl << haveUsers << " " << login.c_str() << "\t" << encryption(login, password);
		fout.close();
		fin.close();
	users.push_back(User(haveUsers, login, password));
	cout << endl;
	return true;
}



bool Administrator::readRecordsInFile(list<User> &users){
	this->nowHaveUsers(users);
	ifstream fin("account.txt");
	
	if (!fin){
		fin.close();
		return false;
	}
	string login_in_file, password_in_file, truePassword;
	int ignor;

	ifstream finRec("records.txt");
	if (!finRec){
		finRec.close();
		return false;
	}
	string surname, name;
	int post, title, edication, status, salary;
	int counter = 1;
	list<User>::iterator iterUser = users.begin();
	while ((!fin.eof()) || (!finRec.eof())){
		fin >> ignor >> login_in_file >> password_in_file;
		truePassword = decryption(login_in_file, password_in_file);
		finRec >> ignor >> surname >> name >> post >> title >> edication >> status >> salary;
		if (counter <= haveUsers){
			users.push_back(User(login_in_file, truePassword, counter, surname, name, post, title, edication, status, salary));
		}
	counter++;
	}
	finRec.close();
	fin.close();
	return true;
}

void User::saveRecord(){
	ofstream fout("account.txt", ios::app);
	fout << endl << " " << this->number << " " << this->login.c_str() << "\t" << encryption(this->login, this->password);
	fout.close();

	ofstream foutRec("records.txt", ios::app);
	foutRec << endl << " " << this->number << " " << surname.c_str() << "\t" << name.c_str() << "\t" << this->getPostForFile() << "\t" << this->getTitleForFile();
	foutRec << "\t" << this->getEdicationForFile() << "\t" << this->getStatusForFile() << "\t" << this->getSalary();
	foutRec.close();
}

void Administrator::saveAllRecords(list<User> users){
	ofstream fout("account.txt", ios::out);
	ofstream foutRec("records.txt", ios::out);
	list<User>::iterator iterUser = users.begin();
	while (iterUser != users.end()){
		(*iterUser++).saveRecord();
	}
	fout.close();
	foutRec.close();
}

void  Administrator::deleteAllRecords(list<User>& users){
	users.clear();
	this->haveUsers = 0;
	this->saveAllRecords(users);
	cout << "Все записи удалены." << endl;
}