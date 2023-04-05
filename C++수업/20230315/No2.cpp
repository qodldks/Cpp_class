#include <iostream>
using namespace std;

void SwapByRef2(int &ref1, int &ref2)
{
	int temp = ref1;
	ref1 = ref2;
	ref2 = temp;
}

void SwapByRef1(int *ref1, int *ref2)
{
	int temp = *ref1;
	*ref1 = *ref2;
	*ref2 = temp;
}

void SwapByVal(int ref1, int ref2)
{
	int temp = ref1;
	ref1 = ref2;
	ref2 = temp;
}
int main(void)
{
	int val1 = 10;
	int val2 = 20;

	SwapByVal(val1, val2);
	cout << val1 << ' ' << val2 << endl;

	SwapByRef1(&val1, &val2);
	cout << val1 << ' ' << val2 << endl;

	SwapByRef2(val1, val2);
	cout << val1 << ' ' << val2 << endl;
	return 0;
}

// SwapByRef2(23,45);의 형태로 호출하면 컴파일 에러가 나는 이유
// -> SwapByRef2()는 매개변수를 참조자로 받고 있는데,
// 	변수가 아닌 값을 넘겨주면 참조자가 가져올 주소가 없어서 에러가 발생한다.