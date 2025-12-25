#pragma once

#ifdef LN_PLATFORM_WINDOWS
#ifdef LN_BUILD_DLL
#define LITHEN_API __declspec(dllexport)
#else
#define LITHEN_API __declspec(dllimport)
#endif // LN_BUILD_DLL
#else
#error Lithen only supports Windows!
#endif // LN_PLATFORM_WINDOWS

#ifdef LN_ENABLE_ASSERTS
#define LN_CORE_ASSERT(x, ...) { if(!(x)) { LN_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#define LN_ASSERT(x, ...) { if(!(x)) { LN_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#else
#define LN_CORE_ASSERT(x, ...)
#define LN_ASSERT(x, ...)
#endif // LN_ENABLE_ASSERTS

#define BIT(x) (1 << x)
