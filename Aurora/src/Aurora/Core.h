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

#ifdef AURORA_ENABLE_ASSERTS
	#define AURORA_ASSERT(x, ...) { if(!(x)) { AURORA_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
	#define AURORA_CORE_ASSERT(x, ...) { if(!(x)) { AURORA_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#else
	#define AURORA_ASSERT(x, ...)
	#define AURORA_CORE_ASSERT(x, ...)
#endif

// bitfield creation
// this is a macro that takes an integer x and returns a bit shifted by x
#define BIT(x) (1 << (x))

#define AURORA_BIND_EVENT_FN(fn) std::bind(&fn, this, std::placeholders::_1)