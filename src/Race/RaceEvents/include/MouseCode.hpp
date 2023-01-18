#if !defined(__RACEEVENTS__MOUSECODE__HPP__)
#define __RACEEVENTS__MOUSECODE__HPP__

namespace Race
{
    // TODO： int跨平台会什么样的影响？
    using MouseCode = int;

    namespace Mouse
    {
        enum : MouseCode
        {
            // From glfw3.h
            Button0 = 0,
            Button1 = 1,
            Button2 = 2,
            Button3 = 3,
            Button4 = 4,
            Button5 = 5,
            Button6 = 6,
            Button7 = 7,

            ButtonLast = Button7,
            ButtonLeft = Button0,
            ButtonRight = Button1,
            ButtonMiddle = Button2
        };
    }
}

#endif // __RACEEVENTS__MOUSECODE__HPP__
