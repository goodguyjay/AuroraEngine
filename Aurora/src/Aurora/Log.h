#pragma once

#include "Aurora/Core.h"
#include "Events/Event.h"
#include <spdlog/spdlog.h>
#include <spdlog/fmt/bundled/core.h>
#include <spdlog/fmt/ostr.h>

namespace Aurora {
    class AURORA_API Log {
    public:
        static void init();

        inline static std::shared_ptr<spdlog::logger>& getCoreLogger() { return s_CoreLogger; }
        inline static std::shared_ptr<spdlog::logger>& getClientLogger() { return s_ClientLogger; }

    private:
        static std::shared_ptr<spdlog::logger> s_CoreLogger;
        static std::shared_ptr<spdlog::logger> s_ClientLogger;
    };
}

// Core Log macros
#define AURORA_CORE_TRACE(...)  ::Aurora::Log::getCoreLogger()->trace(__VA_ARGS__)
#define AURORA_CORE_INFO(...)   ::Aurora::Log::getCoreLogger()->info(__VA_ARGS__)
#define AURORA_CORE_WARN(...)   ::Aurora::Log::getCoreLogger()->warn(__VA_ARGS__)
#define AURORA_CORE_ERROR(...)  ::Aurora::Log::getCoreLogger()->error(__VA_ARGS__)
#define AURORA_CORE_FATAL(...)  ::Aurora::Log::getCoreLogger()->fatal(__VA_ARGS__)

// Client Log macros
#define AURORA_TRACE(...)       ::Aurora::Log::getClientLogger()->trace(__VA_ARGS__)
#define AURORA_INFO(...)        ::Aurora::Log::getClientLogger()->info(__VA_ARGS__)
#define AURORA_WARN(...)        ::Aurora::Log::getClientLogger()->warn(__VA_ARGS__)
#define AURORA_ERROR(...)       ::Aurora::Log::getClientLogger()->error(__VA_ARGS__)
#define AURORA_FATAL(...)       ::Aurora::Log::getClientLogger()->fatal(__VA_ARGS__)

// Formatter specialization for Aurora::Event
namespace fmt {
    template <>
    struct formatter<Aurora::Event> {
        constexpr auto parse(format_parse_context& ctx) -> decltype(ctx.begin()) {
            return ctx.end();
        }

        template <typename FormatContext>
        auto format(const Aurora::Event& e, FormatContext& ctx) -> decltype(ctx.out()) {
            return fmt::format_to(ctx.out(), "{}", e.toString());
        }
    };
}
