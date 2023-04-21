#include <iostream>
#include <cstring>
using namespace std;

class Person  // 클래스 선언
{
private:  // private 멤버 변수
    char * name;
    int age;
public:  // public 멤버 변수
    Person(char * myname, int myage)  // 생성자
    {
        int len = strlen(myname) + 1;  // 문자열의 길이를 동적으로 받는다
        name = new char[len];  // 입력 받은 문자열을 동적 할당
        strcpy(name, myname);  // 입력 받은 문자열을 멤버 변수로 복사
        age = myage;
    }

    void ShowPersonInfo() const  // 단순 정보 출력 함수, 단순 출력을 하기 때문에 const 를 사용하여 변수 등의 변화를 방지
    {
        cout << "Name: " << name << endl;
        cout << "Age : " << age << endl;
    }

    ~Person()  // 소멸자
    {
        delete []name;  // 동적 할당 받은 변수를 메모리에서 해제한다
        cout << "called destructor" << endl;  // 클래스가 소멸하면서 출력 될 예정인 문구
    }
};

int main2(void)
{
    Person man1("Yoo Ju Hyeong", 31);  // 객체 생성
    Person man2 = man1;  // 이미 생성 된 객체를 복사

    man1.ShowPersonInfo();  // 출력
    man2.ShowPersonInfo();  // 출력

    return 0;
}

// 위 코드는 멤버 대 멤버 복사를 '얕은 복사'를 실시했기 때문에 포인터 변수가 서로 같은 객체를 가르키고 있기 때문에 실제로는 하나의 객체만이 생성 된다
// 위 코드에는 복사 생성자를 따로 추가하지 않았기 때문에 디폴트 복사 생성자가 수행이 되었는데, 이를 통해 디폴트 복사 생성자는 '얕은 복사'를 한다고 생각 할 수 있다
// man1.name 과 man2.name 이 서로 같은 주소를 가르키고 있기 때문에 delete []name; 이 수행 되는 순간 man2.name 이 먼저 사라지고 man1.name 이 사라질 차례인데
// 이미 man1.name 이 참조하고 있어야 할 주소는 삭제가 되었으므로 문제가 발생한다