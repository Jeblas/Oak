#pragma once

#ifdef OAK_PLATFORM_WINDOWS
    #ifdef OAK_BUILD_DLL
        #define OAK_API __declspec(dllexport)
    #else
        #define OAK_API __declspec(dllimport)
    #endif 
#else 
    #error Only Windows is supported. 
#endif

#ifdef OAK_ENABLE_ASSERTS
    #define OAK_ASSERT(x, ...) {if(!(x)) { OAK_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
    #define OAK_CORE_ASSERT(x, ...) {if ((!x)) { OAK_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); }}
#else
    #define OAK_ASSERT(x, ...)
    #define OAK_CORE_ASSERT(x, ...)
#endif


#define BIT(x) (1 << x)