#include <iostream>
#include <cstring>
using namespace std;

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

        Person(const Person& copy) : age(copy.age)  // 복사 생성자를 명시하여 멤버를 복사할 때 포인터 변수를 새로 생성하게끔 함.
        {
            name = new char[strlen(copy.name) + 1];
            strcpy(name, copy.name);
        }

        void ShowPersonInfo() const
        {
            cout << "Name: " << name << endl;
            cout << "Age: " << age << endl;
        }

        ~Person()
        {
            delete []name;
            cout << "called destructor" << endl;
        }
};

int main3(void)
{
    Person man1("Yoo Ju Hyeong" , 31);
    Person man2 = man1;

    man1.ShowPersonInfo();
    man2.ShowPersonInfo();

    return 0;
}