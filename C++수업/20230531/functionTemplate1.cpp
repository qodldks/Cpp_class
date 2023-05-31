#include <iostream>
using namespace std;

class point
{
private:
	int xpos, ypos;

public:
	point(int x = 0, int y = 0) : xpos(x), ypos(y) {}

	void show() const
	{
		cout << xpos << ' ' << ypos << endl;
	}
};

template <class T>
void swapData(T &data1, T &data2)
{
	T temp = data1;
	data1 = data2;
	data2 = temp;
}

int main(void)
{
	point P1(10,20);
	point P2(30,40);
	swapData(P1,P2);
	P1.show();
	P2.show();
	return 0;
}