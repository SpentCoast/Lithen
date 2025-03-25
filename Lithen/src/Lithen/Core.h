#pragma once

#ifdef LN_PLATFORM_WINDOWS
#ifdef LN_BUILD_DLL
#define LITHEN_API __declspec(dllexport)
#else
#define LITHEN_API __declspec(dllimport)
#endif
#else
#error Lithen only supports Windows!
#endif

#define BIT(x) (1 << x)