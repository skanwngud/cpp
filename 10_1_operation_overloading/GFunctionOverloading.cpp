#include <iostream>

class Point
{
    private:
        int xpos, ypos;

    public:
        Point(int x = 0, int y = 0)
            : xpos(x), ypos(y)
        { }

        void ShowPosition() const
        {
            std::cout << "[" << xpos << ", " << ypos << "]" << std::endl;
        }

        friend Point operator+(const Point &pos1, const Point &pos2);  // 전역함수에 대해 private 에 접근할 수 있도록 firend 선언
};

Point operator+(const Point &pos1, const Point &pos2)  // 연산자 오버로딩 전역함수
{
    Point pos(pos1.xpos + pos2.xpos, pos1.ypos + pos2.ypos);
    return pos;
}

int main(void)
{
    Point pos1(3, 4);
    Point pos2(10, 20);
    Point pos3 = pos1 + pos2;  // 멤버함수가 전역함수보다 더 우선시 되므로 멤버함수로 실행

    pos1.ShowPosition();
    pos2.ShowPosition();
    pos3.ShowPosition();

    return 0;
}