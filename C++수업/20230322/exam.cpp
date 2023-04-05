#include <iostream>
#include <cstring>
using namespace std;

namespace CAR_CONST
{
	enum
	{
		ID_LEN = 20,
		MAX_SPD = 200,
		FUEL_STEP = 2,
		ACC_STEP = 10,
		BRK_STEP = 10
	};
}

class Car
{
private:
	const char *id = new char[CAR_CONST::ID_LEN];
	int currentFuel;
	int currentSpeed;

public:
	void InitMembers(const char *id, int fuel)
	{
		this->id = id;
		currentFuel = fuel;
		currentSpeed = 0;
	}

	void Accel()
	{
		currentFuel -= CAR_CONST::FUEL_STEP;
		currentSpeed += CAR_CONST::ACC_STEP;
	}

	void Break()
	{
		currentSpeed -= CAR_CONST::BRK_STEP;
	}

	void ShowCarState()
	{
		cout << "소유자ID: " << id << endl;
		cout << "연료량: " << currentFuel << "%" << endl;
		cout << "현재속도: " << currentSpeed << "km/s" << endl
			  << endl;
	}
};