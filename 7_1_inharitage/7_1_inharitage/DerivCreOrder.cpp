// 유도 클래스의 객체 생성 과정

#include <iostream>

class SoBase
{
private:
	int baseNum;

public:
	SoBase() : baseNum(20)  // default initializer
	{
		std::cout << "SoBase()" << std::endl;
	}

	SoBase(int n) : baseNum(n)  // args initiailizer
	{
		std::cout << "SoBase(int n)" << std::endl;
	}

	void ShowBaseData()  // initialize super class
	{
		std::cout << baseNum << std::endl;
	}
};

class SoDerived : public SoBase
{
private:
	int derivNum;

public:
	SoDerived() : derivNum(30)
	{
		std::cout << "SoDerived()" << std::endl;
	}

	SoDerived(int n) : derivNum(n)
	{
		std::cout << "SoDerived(int n)" << std::endl;
	}

	SoDerived(int n1, int n2) : SoBase(n1), derivNum(n2)
	{
		std::cout << "SoDerived(int n1, int n2)" << std::endl;
	}

	void ShowDerivData()
	{
		ShowBaseData();
		std::cout << derivNum << std::endl;
	}
};

int main2(void)
{
	std::cout << "case1....." << std::endl;
	SoDerived dr1;
	dr1.ShowDerivData();
	std::cout << "----------------------------" << std::endl;

	std::cout << "case2....." << std::endl;
	SoDerived dr2(12);
	dr2.ShowDerivData();
	std::cout << "----------------------------" << std::endl;

	std::cout << "case3....." << std::endl;
	SoDerived dr3(23, 24);
	dr3.ShowDerivData();
	
	return 0;
}