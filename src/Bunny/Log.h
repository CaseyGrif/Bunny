#pragma once

#include "Core.h"
#include "spdlog\spdlog.h"
#include "spdlog\sinks\stdout_color_sinks.h"

namespace Bunny {

	class BUNNY_API Log
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

// core log macros

#define B_CORE_TRACE(...)   ::Bunny::Log::GetCoreLogger()->error(__VA_ARGS__)
#define B_CORE_INFO(...)    ::Bunny::Log::GetCoreLogger()->error(__VA_ARGS__)
#define B_CORE_WARN(...)    ::Bunny::Log::GetCoreLogger()->error(__VA_ARGS__)
#define B_CORE_ERROR(...)   ::Bunny::Log::GetCoreLogger()->error(__VA_ARGS__)
#define B_CORE_FATAL(...)   ::Bunny::Log::GetCoreLogger()->error(__VA_ARGS__)

// client log macros

#define B_TRACE(...)   ::Bunny::Log::GetClientLogger()->error(__VA_ARGS__)
#define B_INFO(...)    ::Bunny::Log::GetClientLogger()->error(__VA_ARGS__)
#define B_WARN(...)    ::Bunny::Log::GetClientLogger()->error(__VA_ARGS__)
#define B_ERROR(...)   ::Bunny::Log::GetClientLogger()->error(__VA_ARGS__)
#define B_FATAL(...)   ::Bunny::Log::GetClientLogger()->error(__VA_ARGS__)