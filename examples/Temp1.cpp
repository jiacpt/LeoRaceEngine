
#include <iostream>
#include <string>

// 临时对象class演示
class A
{

public:
    static const int V_S = 0;

private:
    int V_A = 0;

public:
    explicit A(int x);
    ~A();
    A GetA() const;
    A GetAHasTemp() const; // 定义const表示不可修改A对象的成员变量
};

A::A(int x)
{
    V_A = x;
}

A::~A()
{
}

A A::GetAHasTemp() const
{
    A TA = A(3);

    return TA;
}

A A::GetA() const
{
    return A(1);
}

class B
{
private:
    int V_B = 0;

public:
    B(int x);
    ~B();
};

B::B(int x)
{
    V_B = x;
}

B::~B()
{
}

int main(int argc, char const *argv[])
{

    // A a = 3; 禁止隐式类型转换构造函数
    B b = 4;
    B b1 = 'B';
    A a = A(2);
    // const char * const str = "Hello World!";
    //*str = 'a';
    // str++;

    A a1 = a.GetAHasTemp();
    A a2 = a.GetA();

    return 0;
}
