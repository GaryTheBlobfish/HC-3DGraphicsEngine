#include "WriteToFile.h"


void FileLogging::writeToTextFile(std::string s)
{
	/*
		At somepoint, consider using a different time getting system
		because this one requires supressing a warning which cannot
		be good. -_-
	*/

	time_t rawtime;
	struct tm* timeinfo;
	char buffer[80];

	time(&rawtime);
	#pragma warning(suppress : 4996)
	timeinfo = localtime(&rawtime);


	strftime(buffer, sizeof(buffer), "%d-%m-%Y %H:%M:%S", timeinfo);
	std::string timeStr(buffer);

	std::ofstream logFile("logs/latest.log", std::ios_base::app);

	logFile << timeStr << " :    " << s << "\n";
	logFile.flush();
	//logFile.close();
}

void FileLogging::clearLogFile()
{

	time_t rawtime;
	struct tm* timeinfo;
	char buffer[80];

	time(&rawtime);
	#pragma warning(suppress : 4996)
	timeinfo = localtime(&rawtime);


	strftime(buffer, sizeof(buffer), "%d-%m-%Y %H:%M:%S", timeinfo);
	std::string timeStr(buffer);

	std::ofstream clearFile("logs/latest.log");
	clearFile << "LOGGING STARTED AT: " << timeStr << "\n";

}
