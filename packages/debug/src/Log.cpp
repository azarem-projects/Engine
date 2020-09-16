#include "Log.h"

std::shared_ptr<spdlog::logger> api::debug::Log::coreLogger;
std::shared_ptr<spdlog::logger> api::debug::Log::clientLogger;

void api::debug::Log::init()
{
	spdlog::set_pattern("%^[%T] %n: %v%$");

	coreLogger = spdlog::stdout_color_mt("Engine");
	coreLogger->set_level(spdlog::level::trace);

	clientLogger = spdlog::stdout_color_mt("App");
	clientLogger->set_level(spdlog::level::trace);
}
