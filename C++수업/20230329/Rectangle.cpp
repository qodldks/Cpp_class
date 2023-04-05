#include <iostream>
#include "Point.cpp"
using namespace std;

class Rectangle
{
	Point upLeft;
	Point lowRight;

public:
	Rectangle(const int &x1, const int &y1, const int &x2, const int &y2) : upLeft(x1, y1), lowRight(x2, y2) {}

	void ShowRecInfo() const
	{
		if (upLeft.SetX(upLeft.GetX()) && upLeft.SetY(upLeft.GetY()) && lowRight.SetX(lowRight.GetX()) && lowRight.SetY(lowRight.GetY()))
		{
			cout << "좌 상단: " << '[' << upLeft.GetX() << ", ";
			cout << upLeft.GetY() << ']' << endl;
			
			cout << "우 하단: " << '[' << lowRight.GetX() << ", ";
			cout << lowRight.GetY() << ']' << endl
				  << endl;
		}
	}
};