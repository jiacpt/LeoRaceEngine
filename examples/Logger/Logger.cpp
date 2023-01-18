#include <iostream>

#include "../../Engine/Source/Runtime/HEngine.h"

int main(int argc, char const *argv[])
{
    Race::Log::Init();
    RC_CORE_WARN("Initialized Log");
    RC_INFO("Hello!");

    std::cout << "Hello Logger!" << std::endl;
    auto *app = Race::CreateApplication();
    app->Run();
    delete app;

    return 0;
}
