#include "stdafx.h"
#include "time.h"

const char *Time::GetDateAndTime()
{
	system_time = time(NULL);
	local_time = localtime(&system_time);

	strftime(time_str, buff_size, "%b %d %Y / %X - ", local_time);

	return this->time_str;
}