#include "Log.h"

#include "spdlog/sinks/stdout_color_sinks.h"

namespace Aurora
{
	// spdlog::logger is a class that is used to log messages
	// in this piece of code i'm creating two loggers
	// the first one is the core logger and the second one is the client logger

    std::shared_ptr<spdlog::logger> Log::s_CoreLogger;
    std::shared_ptr<spdlog::logger> Log::s_ClientLogger;

    void Log::init()
    {
		// inside this function i'm setting the pattern of the loggers
		// setting the level of the loggers and initializing them
        spdlog::set_pattern("%^[%T] %n: %v%$");
        s_CoreLogger = spdlog::stdout_color_mt("AURORA");
        s_CoreLogger->set_level(spdlog::level::trace);

        s_ClientLogger = spdlog::stdout_color_mt("APP");
        s_ClientLogger->set_level(spdlog::level::trace);
    }
}
