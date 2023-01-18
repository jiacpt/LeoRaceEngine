#if !defined(__RACECORE__LOG__HPP__)
#define __RACECORE__LOG__HPP__

#include <memory>
#include <spdlog/spdlog.h>
#include <spdlog/sinks/stdout_color_sinks.h>

namespace Race
{
    class Log
    {

    public:
        static void Init();
        inline static std::shared_ptr<spdlog::logger> &GetCoreLogger() { return s_CoreLogger; }
        inline static std::shared_ptr<spdlog::logger> &GetClientLogger() { return s_ClientLogger; }

    private:
        static std::shared_ptr<spdlog::logger> s_CoreLogger;
        static std::shared_ptr<spdlog::logger> s_ClientLogger;
    };

    void Log::Init()
    {
#ifdef _DEBUG
        spdlog::set_level(spdlog::level::trace);
        spdlog::set_pattern("%^[%T] %n: %v%$");
        s_CoreLogger = spdlog::stdout_color_mt("Race");
        s_CoreLogger->set_level(spdlog::level::trace);
        s_ClientLogger = spdlog::stdout_color_mt("App");
        s_ClientLogger->set_level(spdlog::level::trace);
#endif
    }

    std::shared_ptr<spdlog::logger> Log::s_CoreLogger = nullptr;
    std::shared_ptr<spdlog::logger> Log::s_ClientLogger = nullptr;
};

// define logger macros
// TIP: 使用空指针的成员函数会导致程序崩溃嘛？
// 如果在空指针上调用成员函数，只要不使用this指针，程序就不会崩溃。
#define RC_CORE_ERROR(...) ::Race::Log::GetCoreLogger()->error(__VA_ARGS__)
#define RC_CORE_INFO(...) ::Race::Log::GetCoreLogger()->info(__VA_ARGS__)
#define RC_CORE_TRACE(...) ::Race::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define RC_CORE_WARN(...) ::Race::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define RC_CORE_FATAL(...) ::Race::Log::GetCoreLogger()->fatal(__VA_ARGS__)

#define RC_ERROR(...) ::Race::Log::GetClientLogger()->error(__VA_ARGS__)
#define RC_INFO(...) ::Race::Log::GetClientLogger()->info(__VA_ARGS__)
#define RC_TRACE(...) ::Race::Log::GetClientLogger()->trace(__VA_ARGS__)
#define RC_WARN(...) ::Race::Log::GetClientLogger()->warn(__VA_ARGS__)
#define RC_FATAL(...) ::Race::Log::GetClientLogger()->fatal(__VA_ARGS__)

#endif // __RACECORE__LOG__HPP__
