#include <iostream>
#include <cstring>
using namespace std;

class Point
{
public:
	int x, y;

	bool InitMembers(int p1, int p2)
	{
		if (p1 < 0 || p2 < 0)
		{
			cout << "벗어난 범위의 값 전달" << endl;
			return false;
		}
		else
		{
			x = p1;
			y = p2;
			return true;
		}
	}
};