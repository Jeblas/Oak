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

#define BIT(x) (1 << x)