// public; ��𼭵� ���� ���
// private; Ŭ���� �� (Ŭ���� ���� ���� �� �Լ�) ������ ���� ���
// protected; ��� ���迡 ������ �� ���� Ŭ���������� ���� ���

// Ŭ������ ������ ������ �׻� ���� ���� �������� �����ڸ� ���� �� ������ �Լ��� ���� ��� ������ �����ؾ��Ѵ�

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstring>
using namespace std;


namespace CAR_CONST
{
	enum
	{
		ID_LEN = 20, MAX_SPD = 200, FUEL_STEP = 2,
		ACC_STEP = 10, BRK_STEP = 10
	};
}

class Car
{
private:  // �������� �����ڰ� ���� �Ǹ� �� ���Ŀ� �����ϴ� ������ �Լ��� �ش� ���� ������ ������ �����ϴ�
	char gamerID[CAR_CONST::ID_LEN];
	int fuelGauge;
	int curSpeed;

public:  // ���ο� �������� �����ڰ� ���� �Ǹ� �� ���ķ� �����ϴ� ������ �Լ��� ���ο� �������� �������� ���� ������ ������ �����ϴ�
	void InitMembers(const char *ID, int fuel);
	void ShowCarState();
	void Accel();
	void Break();
};

void Car::InitMembers(const char *ID, int fuel)  // �Լ��� ���Ǹ� Ŭ���� ������ ���� �̴� Ŭ������ �Ϻ��̱� ������ �Լ� �������� private �� ���� �� ������ ������ �����ϴ�
{
	strcpy(gamerID, ID);
	fuelGauge = fuel;
	curSpeed = 0;
}

void Car::ShowCarState()
{
	cout << "owner ID: " << gamerID << endl;
	cout << "left fuel: " << fuelGauge << endl;
	cout << "current spped: " << curSpeed << endl << endl;
}

void Car::Accel()
{
	if (fuelGauge <= 0)
		return;
	else
		fuelGauge -= CAR_CONST::BRK_STEP;

	if ((curSpeed + CAR_CONST::ACC_STEP) >= CAR_CONST::MAX_SPD)
	{
		curSpeed = CAR_CONST::MAX_SPD;
		return;
	}

	curSpeed += CAR_CONST::ACC_STEP;
}

void Car::Break()
{
	if (curSpeed < CAR_CONST::BRK_STEP)
	{
		curSpeed = 0;
		return;
	}

	curSpeed -= CAR_CONST::BRK_STEP;
}

int main(void)
{
	Car run99;
	run99.InitMembers("run99", 100);
	run99.Accel();
	run99.Accel();
	run99.ShowCarState();
	run99.Break();
	run99.ShowCarState();

	return 0;
}

// struct �� �̿��Ͽ� ������ ����ü�� ������ �������� �����ڰ� ������ ���� public ���� ���� �ȴ�
// class �� �̿��Ͽ� ������ ����ü�� ������ �������� �����ڰ� ������ ���� private �� ���� �ȴ�