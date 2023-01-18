#if !defined(__RACEEVENTS__EVENT__HPP__)
#define __RACEEVENTS__EVENT__HPP__

#include <string>
#include <functional>
#include "../../RaceCore/include/Base.hpp"
//#include "RaceCore/include/Log.hpp"

namespace Race
{

    // TIP：枚举类
    // 1.降低命名空间污染， Class::type 才可以使用
    // 2.避免发生隐式转换， Class::type 不可以隐式和int比较，使用static_cast
    // 3.可以前置声明      enum class Color;	//正确
    enum class EventType
    {
        None = 0,
        WindowClose,
        WindowResize,
        WindowFocus,
        WindowLostFocus,
        WindowMoved,
        AppTick,
        AppUpdate,
        AppRender,
        KeyPressed,
        KeyReleased,
        KeyTyped,
        MouseButtonPressed,
        MouseButtonReleased,
        MouseMoved,
        MouseScrolled
    };

    enum EventCategory
    {
        // TODO： 为什么用这种方法？
        None = 0,
        EventCategoryApplication = BIT(0),
        EventCategoryInput = BIT(1),
        EventCategoryKeyboard = BIT(2),
        EventCategoryMouse = BIT(3),
        EventCategoryMouseButton = BIT(4)
    };

// 获取事件类型
// TIP: virtual 是干嘛的? 在类中一次定义多个成员,静态函数
// ==> 这种写法让对象和类都可以获取事件类型
#define EVENT_CLASS_TYPE(type)                      \
    static EventType GetStaticType()                \
    {                                               \
        return EventType::type;                     \
    }                                               \
    virtual EventType GetEventType() const override \
    {                                               \
        return GetStaticType();                     \
    }                                               \
    virtual const char *GetName() const override    \
    {                                               \
        return #type;                               \
    } // 返回#type const char*

// Category
#define EVENT_CLASS_CATEGORY(category)            \
    virtual int GetCategoryFlags() const override \
    {                                             \
        return category;                          \
    }

    //*****************************************************************************************
    //
    class Event
    {
    public:
        // TIP：=default, 每当我们声明一个有参构造函数时，编译器就不会创建默认构造函数。
        // 在这种情况下，我们可以使用default说明符来创建默认说明符
        // =delete, 1.防止编译器生成不想要的特殊成员函数 2.防止有问题的非预期函数
        virtual ~Event() = default;
        bool Handled = false;

        // TIP: 纯虚函数， 1.该基类只能被继承不能被实例化     2.必须在派生类中被实现
        virtual EventType GetEventType() const = 0;
        virtual const char *GetName() const = 0;
        virtual int GetCategoryFlags() const = 0;
        virtual std::string ToString() const { return GetName(); }

        bool IsInCategory(EventCategory category)
        {
            return GetCategoryFlags() & category;
        }
    };

    //*****************************************************************************************
    //
    class EventDispatcher
    {
    public:
        EventDispatcher(Event &event) : m_Event(event)
        {
        }

        // F will be deduced by the compiler
        template <typename T, typename F>
        bool Dispatch(const F &func)
        {
            if (m_Event.GetEventType() == T::GetStaticType())
            {
                m_Event.Handled |= func(static_cast<T &>(m_Event));
                return true;
            }
            return false;
        }

    private:
        Event &m_Event;
    };

    inline std::ostream &operator<<(std::ostream &os, const Event &e)
    {
        return os << e.ToString();
    }
}

#endif // __RACEEVENTS__EVENT__HPP__
