#pragma once
#include <fstream>

class FileLogging {
public:
	static void writeToTextFile(std::string s);
	static void clearLogFile();
};