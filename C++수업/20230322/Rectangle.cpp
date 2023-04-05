#include <iostream>
#include "Point.cpp"
using namespace std;

class Rectangle
{
private:
	int leftTop[2], rightBottom[2];

public:
	bool InitMembers(Point &p1, Point &p2)
	{
		if (p1.x >= p2.x || p1.y >= p2.y)
		{
			cout << "잘못된 위치정보 전달" << endl;
			return false;
		}
		else
		{
			leftTop[0] = p1.x;
			leftTop[1] = p1.y;
			rightBottom[0] = p2.x;
			rightBottom[1] = p2.y;
			return true;
		}
	}

	void ShowRecInfo()
	{
		cout << "좌 상단: [" << leftTop[0] << ", " << leftTop[1] << "]" << endl;
		cout << "우 하단: [" << rightBottom[0] << ", " << rightBottom[1] << "]" << endl;
	}
};