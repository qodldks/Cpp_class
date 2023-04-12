#include <iostream>
#include <cstring>
using namespace std;

class Book
{
private:
	string title;
	string isbn;
	int price;

public:
	Book(string title, string isbn, int price) : title(title), isbn(isbn), price(price)
	{
		cout << title << endl;
		cout << isbn << endl;
		cout << price << endl;
	}
};

class Ebook : public Book
{
private:
	string dkey; // 인증키
public:
	Ebook(string title, string isbn, int price, string dkey) : dkey(dkey), Book(title, isbn, price)
	{
		cout << dkey << endl;
	}
};

int main(void)
{
	Book gunJinam("c++", "111-111", 20000);
	cout << endl;
	Ebook chongJinam("java", "222-222", 20000, "pjhnice");
	return 0;
}