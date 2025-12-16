#pragma once

#include <memory>

#include "Core.h"
#include "spdlog/logger.h"

namespace Lithen
{
	class Log
	{
	public:
		LITHEN_API static void Init();

		LITHEN_API inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		LITHEN_API inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }

	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};
}

// Core log macros
#define LN_CORE_TRACE(...)       ::Lithen::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define LN_CORE_INFO(...)        ::Lithen::Log::GetCoreLogger()->info(__VA_ARGS__)
#define LN_CORE_WARN(...)        ::Lithen::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define LN_CORE_ERROR(...)       ::Lithen::Log::GetCoreLogger()->error(__VA_ARGS__)
#define LN_CORE_CRITICAL(...)    ::Lithen::Log::GetCoreLogger()->critical(__VA_ARGS__)

// Client log macros
#define LN_TRACE(...)            ::Lithen::Log::GetClientLogger()->trace(__VA_ARGS__)
#define LN_INFO(...)             ::Lithen::Log::GetClientLogger()->info(__VA_ARGS__)
#define LN_WARN(...)             ::Lithen::Log::GetClientLogger()->warn(__VA_ARGS__)
#define LN_ERROR(...)            ::Lithen::Log::GetClientLogger()->error(__VA_ARGS__)
#define LN_CRITICAL(...)         ::Lithen::Log::GetClientLogger()->critical(__VA_ARGS__)
