#include <iostream>
using namespace std;

int main(void)
{
	const int num1 = 12;
	const int *ptr = &num1;
	const int *(&ref) = ptr;

	cout << *ptr << ' ' << *ref << endl;

	return 0;
}