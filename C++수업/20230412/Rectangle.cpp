#include <iostream>
using namespace std;

class Rectangle
{
private:
	int garo, sero;

public:
	Rectangle(int garo, int sero) : garo(garo), sero(sero)
	{
	}

	void show()
	{
		cout << garo * sero << endl;
	}
};

class Square : public Rectangle
{
private:
	int garo;

public:
	Square(int garo) : garo(garo), Rectangle(garo, garo)
	{
	}

	void showInfo()
	{
		cout << garo * garo << endl;
	}
};

int main(void)
{
	Rectangle rec(4, 3);
	rec.show();
	Square sqr(7);
	sqr.showInfo();

	return 0;
}