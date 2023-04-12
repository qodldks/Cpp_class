#include <iostream>
#include <cstring>
using namespace std;

class myFriend
{
private:
	string name;
	int age;

public:
	myFriend(string name, int age) : name(name), age(age)
	{
	}

	void show()
	{
		cout << name << endl;
		cout << age << endl;
	}
};

class myFriendInfo : public myFriend
{
private:
	string addr;
	string phone;

public:
	myFriendInfo(string name, int age, string addr, string phone) : addr(addr), phone(phone), myFriend(name, age)
	{
		showInfo();
	}
	void showInfo()
	{
		show();
		cout << addr << endl;
		cout << phone << endl;
	}
};

int main(void)
{
	myFriendInfo PJH("박제현", 20, "해운대", "1671");
	myFriendInfo PJS("박지성", 30, "동래", "7777");
	return 0;
}