#pragma once

#include <spdlog/spdlog.h>
#include <spdlog/sinks/stdout_color_sinks.h>
#include <spdlog/fmt/ostr.h>

namespace api
{
    namespace debug
    {
        class Log
        {
        public:
            static void init();

            inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return coreLogger; }
            inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return clientLogger; }

        private:
            static std::shared_ptr<spdlog::logger> coreLogger;
            static std::shared_ptr<spdlog::logger> clientLogger;
        };
    }
}

#define DEBUG_LOG(...)    ::api::debug::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define DEBUG_INFO(...)   ::api::debug::Log::GetCoreLogger()->info(__VA_ARGS__)
#define DEBUG_WARN(...)   ::api::debug::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define DEBUG_ERROR(...)  ::api::debug::Log::GetCoreLogger()->error(__VA_ARGS__)
#define DEBUG_FATAL(...)  ::api::debug::Log::GetCoreLogger()->fatal(__VA_ARGS__)

#define ENGINE_TRACE(...) ::api::debug::Log::GetClientLogger()->trace(__VA_ARGS__)
#define ENGINE_INFO(...)  ::api::debug::Log::GetClientLogger()->info(__VA_ARGS__)
#define ENGINE_WARN(...)  ::api::debug::Log::GetClientLogger()->warn(__VA_ARGS__)
#define ENGINE_ERROR(...) ::api::debug::Log::GetClientLogger()->error(__VA_ARGS__)
#define ENGINE_FATAL(...) ::api::debug::Log::GetClientLogger()->fatal(__VA_ARGS__)
