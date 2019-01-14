#pragma once

#include <cstdio>

class Log
{
public:
	Log();
	Log(const char *filename);
	~Log();

	void Message(const char *format, ...);

private:
	FILE *fp;
	char *filename_;
};

