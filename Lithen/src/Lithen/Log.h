#pragma once

#include <memory>

#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"

#ifdef _MSC_VER
#pragma warning(push)
#pragma warning(disable: 4251)
#endif

namespace Lithen
{
	class LITHEN_API Log
	{
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; };
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; };

	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};
}

#ifdef _MSC_VER
#pragma warning(pop)
#endif

// Core log macros
#define LN_CORE_TRACE(...)     ::Lithen::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define LN_CORE_INFO(...)      ::Lithen::Log::GetCoreLogger()->info(__VA_ARGS__)
#define LN_CORE_WARN(...)      ::Lithen::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define LN_CORE_ERROR(...)     ::Lithen::Log::GetCoreLogger()->error(__VA_ARGS__)
#define LN_CORE_CRITICAL(...)  ::Lithen::Log::GetCoreLogger()->critical(__VA_ARGS__)

// Client log macros
#define LN_TRACE(...)          ::Lithen::Log::GetClientLogger()->trace(__VA_ARGS__)
#define LN_INFO(...)           ::Lithen::Log::GetClientLogger()->info(__VA_ARGS__)
#define LN_WARN(...)           ::Lithen::Log::GetClientLogger()->warn(__VA_ARGS__)
#define LN_ERROR(...)          ::Lithen::Log::GetClientLogger()->error(__VA_ARGS__)