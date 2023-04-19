#include <iostream>
#include <cstring>
using namespace std;

class Employee
{
private:
	string name;

public:
	Employee(string name)
	{
		this->name = name;
	}
	virtual int GetPay() const
	{
	}
	void ShowYourName() const
	{
		cout << "name: " << name << endl;
	}
	virtual void ShowSalaryInfo() const
	{
		ShowYourName();
		cout << "salary: " << GetPay() << endl
				 << endl;
	}
};

class PermanentWorker : public Employee
{
private:
	int salary;
	string typeOfEmployment;
public:
	PermanentWorker(string name, int money)
			: Employee(name), salary(money),typeOfEmployment("PermanentWorker")
	{
		
	}
	virtual int GetPay() const
	{
		return salary;
	}
};

class TemporaryWorker : public Employee
{
private:
	int workHour, payPerHour;

public:
	TemporaryWorker(string name, int money) : Employee(name), payPerHour(money)
	{
	}

	void AddWorkTime(int time)
	{
		workHour += time;
	}

	virtual int GetPay() const override
	{
		return workHour * payPerHour;
	}
	void ShowSalaryInfo() const override
	{
		ShowYourName();
		cout << "pay per hour: " << payPerHour << endl
				 << "worked hour: " << workHour << endl
				 << "salary: " << GetPay() << endl
				 << endl;
	}
};

class SalesWorker : public PermanentWorker
{
private:
	int salesRecord;
	double bonusRatio;

public:
	SalesWorker(string name, int money, double ratio) : PermanentWorker(name, money), salesRecord(0), bonusRatio(ratio)
	{
	}
	void AddSalesResult(int result)
	{
		salesRecord += result;
	}
	virtual int GetPay() const override
	{
		return PermanentWorker::GetPay() + (int)(salesRecord * bonusRatio);
	}
	void ShowSalaryInfo() const override
	{
		ShowYourName();
		cout << "default salary " << PermanentWorker::GetPay() << endl
				 << "sales result: " << salesRecord << endl
				 << "bonus ratio: " << bonusRatio << endl
				 << "salary: " << GetPay() << endl
				 << endl;
	}
};

class EmployeeHandler
{
private:
	Employee *empList[50];
	int empNum;

public:
	EmployeeHandler() : empNum(0)
	{
	}
	void AddEmployee(Employee *emp)
	{
		empList[empNum++] = emp;
	}
	void ShowAllSalaryInfo() const
	{

		for (int i = 0; i < empNum; i++)
			empList[i]->ShowSalaryInfo();
	}
	void ShowTotalSalary() const
	{
		int sum = 0;

		for (int i = 0; i < empNum; i++)
			sum += empList[i]->GetPay();

		cout << "salary sum: " << sum << endl;
	}
	~EmployeeHandler()
	{
		for (int i = 0; i < empNum; i++)
			delete empList[i];
	}
};

int main(void)
{
	// 직원관리를 목적으로 설계된 컨트롤 클래스의 객체생성
	EmployeeHandler handler;

	// 정규직 등록
	handler.AddEmployee(new PermanentWorker("KIM", 1000));
	handler.AddEmployee(new PermanentWorker("LEE", 1500));

	// 임시직 등록
	TemporaryWorker *alba = new TemporaryWorker("Jung", 700);
	alba->AddWorkTime(5); // 5시간 일한결과 등록
	handler.AddEmployee(alba);

	// 영업직 등록
	SalesWorker *seller = new SalesWorker("Hong", 1000, 0.1);
	seller->AddSalesResult(6000); // 영업실적 7000
	handler.AddEmployee(seller);

	// 이번 달에 지불해야 할 급여의 정보
	handler.ShowAllSalaryInfo();

	// 이번 달에 지불해야 할 급여의 총합
	handler.ShowTotalSalary();
	return 0;
}