#if !defined(__RACE__APPLiCATION__HPP__)
#define __RACE__APPLiCATION__HPP__

#include <iostream>

namespace Race
{

    class Application
    {
    private:
        int version = 0;

    public:
        Application();
        Application(int v);
        virtual ~Application();
        void Run();
    };

    Application::Application()
    {
    }

    Application::Application(int v)
    {
        version = v;
    }

    Application::~Application()
    {
    }

    void Application::Run()
    {

        while (true)
        {
            
        }
    }

    Application *CreateApplication()
    {
        return new Application();
    }

}

#endif // __RACE__APPLiCATION__HPP__
