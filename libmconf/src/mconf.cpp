#include <iostream>
#include <fstream>
#include <string>
#include <map>

#include "libmconf.h"

using namespace LMConf;

void ConfLoader::loadConfs(const char* filePath, std::map<std::string,std::string> &confs) {
	std::ifstream pFile(filePath);
	
	while (!pFile.eof())
	{
		std::string line;
		std::getline(pFile, line);

		int nDelimiterPos = line.find('=');

		std::string key = line.substr(0, nDelimiterPos);
		std::string val = line.substr(++nDelimiterPos, line.length());

		confs[key] = val;
	}

	pFile.close();
}