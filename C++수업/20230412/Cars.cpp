#include <iostream>
using namespace std;

class car
{
private:
	int gasoline;

public:
	car(int c) : gasoline(c)
	{
	}

	int getgas()
	{
		return gasoline;
	}
};

class hybridCar : public car
{
private:
	int electric;

public:
	hybridCar(int c, int h) : electric(h), car(c)
	{
	}

	int getelec()
	{
		return electric;
	}
};

class hybridWaterCar : public hybridCar
{
private:
	int watergauge;

public:
	hybridWaterCar(int c, int h, int hw) : watergauge(hw), hybridCar(c, h)
	{
	}

	void show()
	{
		cout << getgas() << endl;
		cout << getelec() << endl;
		cout << watergauge << endl;
	}
};

int main(void)
{
	// car c1(79);
	// hybridCar c2(65);
	hybridWaterCar c3(79, 65, 35);
	c3.show();

	return 0;
}