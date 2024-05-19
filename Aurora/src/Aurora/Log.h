#pragma once

// std
#include <memory>

#include "Core.h"
#include "spdlog/spdlog.h"

namespace aurora
{
    class AURORA_API Log
    {
    public:
        static void init();

        inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
        inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }

    private:
        static std::shared_ptr<spdlog::logger> s_CoreLogger;
        static std::shared_ptr<spdlog::logger> s_ClientLogger;
    };
}

// Core Log macros
#define AURORA_CORE_TRACE(...)  ::aurora::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define AURORA_CORE_INFO(...)   ::aurora::Log::GetCoreLogger()->info(__VA_ARGS__)
#define AURORA_CORE_WARN(...)   ::aurora::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define AURORA_CORE_ERROR(...)  ::aurora::Log::GetCoreLogger()->error(__VA_ARGS__)
#define AURORA_CORE_FATAL(...)  ::aurora::Log::GetCoreLogger()->fatal(__VA_ARGS__)

// Client Log macros
#define AURORA_TRACE(...)       ::aurora::Log::GetClientLogger()->trace(__VA_ARGS__)
#define AURORA_INFO(...)        ::aurora::Log::GetClientLogger()->info(__VA_ARGS__)
#define AURORA_WARN(...)        ::aurora::Log::GetClientLogger()->warn(__VA_ARGS__)
#define AURORA_ERROR(...)       ::aurora::Log::GetClientLogger()->error(__VA_ARGS__)
#define AURORA_FATAL(...)       ::aurora::Log::GetClientLogger()->fatal(__VA_ARGS__)
