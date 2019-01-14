#pragma once

#include <ctime>

class Time
{
public:
	Time() {};
	~Time() {};
	const char *GetDateAndTime();

private:
	static const size_t buff_size = 128;
	time_t system_time;
	tm *local_time;
	char time_str[buff_size];
};