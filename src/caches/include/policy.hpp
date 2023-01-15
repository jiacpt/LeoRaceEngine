
#include <iostream>

class Policy
{
private:
    int version = 0;

public:
    Policy();
    Policy(int v);
    ~Policy();
    int GetVersion() { return version; };
};

Policy::Policy()
{
    
}
Policy::Policy(int v)
{
    version = v;
}

Policy::~Policy()
{
}
