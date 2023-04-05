#include <iostream>
using namespace std;

void plusOne(int &n)
{
	n += 1;
}

void changeSign(int &n)
{
	n *= -1;
}

int main(void)
{
	int a, b;
	cin >> a >> b;
	plusOne(a);
	changeSign(b);
	cout << a << ' ' << b << endl;
}