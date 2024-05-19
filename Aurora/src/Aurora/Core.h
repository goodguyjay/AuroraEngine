#pragma once

#ifdef AURORA_PLATFORM_WINDOWS
	#ifdef AURORA_BUILD_DLL
		#define AURORA_API __declspec(dllexport)
	#else
		#define AURORA_API __declspec(dllimport)
	#endif
#else
	#error Aurora only supports Windows!
#endif