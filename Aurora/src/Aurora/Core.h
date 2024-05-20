#pragma once

// this is a macro that checks if the platform is windows
// and then checks if the build is a dll
// and if so it exports the class

#ifdef AURORA_PLATFORM_WINDOWS
	#ifdef AURORA_BUILD_DLL
		#define AURORA_API __declspec(dllexport)
	#else
		#define AURORA_API __declspec(dllimport)
	#endif
#else
	#error Aurora only supports Windows!
#endif

// bitfield creation
// this is a macro that takes an integer x and returns a bit shifted by x
#define BIT(x) (1 << (x))