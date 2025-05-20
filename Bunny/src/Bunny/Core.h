#pragma once

#ifdef B_PLATFORM_WINDOWS
	#ifdef B_BUILD_DLL
		#define BUNNY_API __declspec(dllexport)
	#else
		#define BUNNY_API __declspec(dllimport)
	#endif
	#else
		#error Hazel only supports Windows!
#endif // B_PLATFORM_WINDOWS
