#include "Log.h"

namespace Bunny
{

	std::shared_ptr<spdlog::logger> Log::s_CoreLogger;
	std::shared_ptr<spdlog::logger> Log::s_ClientLogger;

	void Log::init()
	{					// color, timestamp, logger name, message
		spdlog::set_pattern("%^ [%T] %n: %v%$");

		s_CoreLogger = spdlog::stdout_color_mt("BUNNY");
		s_CoreLogger->set_level(spdlog::level::trace);
		s_ClientLogger = spdlog::stdout_color_mt("APP");
		s_ClientLogger->set_level(spdlog::level::trace);

	}

}