#pragma once

#ifdef _MSC_VER
	#ifdef BUILD_LIB
		#define MCONF_API	__declspec(dllexport)
	#else
		#define MCONF_API	__declspec(dllimport)
	#endif
#elif defined(__GNUC__)
	#ifdef BUILD_LIB
		#define MCONF_API	__attribute__ ((visibility ("default")))
	#else
		#define MCONF_API 
	#endif
#else
	#error libmconf can only be built on MSBuild or GCC.
#endif

/*
	Actual lib functions.
*/
#include <map>
#include <string>

namespace LMConf
{
	class MCONF_API ConfLoader
	{
	public:
		void loadConfs(const char* filePath, std::map<std::string,std::string> &confs);
		
	};
}