#pragma once

#include "Core.h"

#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"


namespace Engine {

    class ENGINE_API Log
    {
    public:
        static void Init();

        inline static std::shared_ptr<spdlog::logger> GetCoreLogger() { return s_CoreLogger; }
        inline static std::shared_ptr<spdlog::logger> GetAppLogger() { return s_AppLogger; }

    private:
        static std::shared_ptr<spdlog::logger> s_CoreLogger;
        static std::shared_ptr<spdlog::logger> s_AppLogger;
    };

}

// Core engine logging macros
#define LOG_CORE_TRACE(...) ::Engine::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define LOG_CORE_INFO(...)  ::Engine::Log::GetCoreLogger()->info(__VA_ARGS__)
#define LOG_CORE_WARN(...)  ::Engine::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define LOG_CORE_ERROR(...) ::Engine::Log::GetCoreLogger()->error(__VA_ARGS__)
#define LOG_CORE_FATAL(...) ::Engine::Log::GetCoreLogger()->fatal(__VA_ARGS__)

// App logging macros
#define LOG_TRACE(...) ::Engine::Log::GetAppLogger()->trace(__VA_ARGS__)
#define LOG_INFO(...)  ::Engine::Log::GetAppLogger()->info(__VA_ARGS__)
#define LOG_WARN(...)  ::Engine::Log::GetAppLogger()->warn(__VA_ARGS__)
#define LOG_ERROR(...) ::Engine::Log::GetAppLogger()->error(__VA_ARGS__)
#define LOG_FATAL(...) ::Engine::Log::GetAppLogger()->fatal(__VA_ARGS__)