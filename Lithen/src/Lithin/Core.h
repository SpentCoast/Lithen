#pragma once

#ifdef LN_PLATFORM_WINDOWS
#ifdef LN_BUILD_DLL
#define LITHIN_API __declspec(dllexport)
#else
#define LITHIN_API __declspec(dllimport)
#endif
#else
#error Lithin only supports Windows!
#endif
