#define _CRT_SECURE_NO_WARNINGS
#define nowMonth  11
#include<iostream> 
#include <string>
#include <Windows.h>
#include <iomanip> 
#include <conio.h>
#include <string>
#include <list>  
#include <iterator>
#include <fstream>
#include <cstdlib> 
#include <algorithm>

using namespace std;
namespace testInput{
	int test();
}
//using namespace testInput;


enum posts { rector = 1, dean, deputyDean, teacher,   };			//ректор, декан, замдекан, преподаватель.
enum titles { academician = 1, phD, professor, docent, master };	//академммик, кандидат наук, профессор,  доцент,  магистр. 
enum edications { higher = 1, generalAverage};
enum statuses{ fired = 0, working };

class  Employee{  
private:
	posts post;				//должность
	titles title;			//учёная степень
	edications edication;	//образование
	statuses status;		//работает / уволен
	int salary[13];
public:
	Employee(){}
	Employee(int post, int title, int edication, int status, int salary);

	bool setPost(int choice);
	bool setTitle(int choice);
	bool setEdication(int choice);
	bool setStatus(int choice);

	void setSalary(int salary);
	int calculateSalary();
	void realSalary(int freeDay = 0);
	void showSalary();


	void createPostAndEtc();
	void createStatus();

	string getPost();
	string getTitle();
	string getEdication();
	string getStatus();
	int getSalary(int month = nowMonth) ;

	int getPostForFile();
	int getTitleForFile();
	int getEdicationForFile();
	int getStatusForFile();
	virtual ~Employee() = 0;
};


class  User : public  Employee{
private:
	string surname;
	int number;
	string name ;
	static int counter;
protected:
	string login;
	string password;

public:
	User(){}
	User(int number, string login, string password);
	User(string login, string password, int number, string surname, string name, int post, int title, int edication, int status, int salary);
	
	int check(list<User>);   
	virtual void Header();		//ПОЛИМОРФИЗМ ВРЕМЕНИ ВЫПОЛНЕНИЯ
	bool userMenu();

	void setSurname(string surname);
	void setName(string name);
	friend User hospital(User us, int freeDay);
	friend string encryption( string login, string password);
	friend string decryption(string login, string password);

	string getSurname();
	string getName();
	int getNumber();
	string getLogin();
	string getPassword();

	static void incrementCounter();
	static int getCounter();

	void createSurnameName();
	void createRecord();

	void showHeadRecord();
	void showRecord();
	void changeRecord();

	void saveRecord();
};


class Administrator : public User {
private: 
	int haveUsers;
public:
	bool check();  
	void Header();

	bool administratorMenu(list<User>&);
	void nowHaveUsers(list<User>);

	bool readRecordsInFile(list<User> &);
	bool createAccount(list<User>&);

	void showHeadAccount();
	void showAllAccounts(list<User> );
	void showAllRecords(list<User>);
	void showHeadSalaryByMonth();
	void showSalaryByMonth(list<User>, int month);

	int menufindRecord(list<User> );
	int findRecordByNum(list<User>);
	int findRecordByName(list<User> );
	
	void deleteAllRecords(list<User>&);
		
	void menuFilter(list<User>);
	bool filter(list<User>, int post);
	bool filter(list<User>);
	void menuSort(list<User>& users);
	
	void saveAllRecords(list<User>);
};

template<class T>
struct SortingBySalary
{
	bool operator()(const T& head, const T& tail) {
		return head.getSalary() > tail.getSalary();
	}
};

template<class T>
struct SortingBySurname
{
	bool operator()(const T& head, const T& tail) {
		return head.getSurname() < tail.getSurname();
	}
};

template<class T>
struct SortingByNumber
{
	bool operator()(const T& head, const T& tail) {
		return head.getNumber() < tail.getNumber();
	}
};