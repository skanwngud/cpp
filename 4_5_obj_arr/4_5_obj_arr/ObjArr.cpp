#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstring>

class Person
{
private:
	char * name;
	int age;

public:
	Person(char * myname, int myage)
	{
		int len = strlen(myname) + 1;
		name = new char[len];
		strcpy(name, myname);

		age = myage;
	}

	Person()
	{
		name = NULL;
		age = 0;

		std::cout << "called Person()" << std::endl;
	}

	void SetPersonInfo(char * myname, int myage)
	{
		name = myname;
		age = myage;
	}

	void ShowPersonInfo() const
	{
		std::cout << "이름: " << name << ", ";
		std::cout << "나이: " << age << std::endl;
	}

	~Person()
	{
		delete[]name;
		std::cout << "called destructor!" << std::endl;
	}
};

int main(void)
{
	Person parr[3];  // 객체 배열 3개 생성
	char namestr[100];
	char * strptr;
	int age;
	int len;

	for (int i = 0; i < 3; i++)  // 생성 된 배열 3개를 채우기 위한 반복문
	{
		std::cout << "이름: ";
		std::cin >> namestr;
		std::cout << "나이: ";
		std::cin >> age;

		len = strlen(namestr) + 1;
		strptr = new char[len];
		strcpy(strptr, namestr);
		parr[i].SetPersonInfo(strptr, age);
	}

	parr[0].ShowPersonInfo();
	parr[1].ShowPersonInfo();
	parr[2].ShowPersonInfo();

	return 0;
}