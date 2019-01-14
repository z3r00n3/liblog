#include "stdafx.h"
#include "log.h"
#include "time.h"
#include <cstdio>
#include <cstring>
#include <cstdarg>

Log::Log()
{
	fp = nullptr;
	filename_ = nullptr;
}

Log::Log(const char *filename)
{
	filename_ = new char[strlen(filename) + 1];
	strcpy(filename_, filename);

	fp = fopen(filename_, "a");
}

Log::~Log()
{
	if (fp)
	{
		fclose(fp);
		delete[] filename_;
	}
}

void Log::Message(const char *format, ...)
{
	va_list ap;
	const char *p;
	int ival;
	unsigned int uival;
	double dval;
	char cval;
	char *sval = nullptr;
	Time time;

	va_start(ap, format);
	
	fprintf(fp ? fp : stdout,"%s", time.GetDateAndTime());
	for (p = format; *p; p++) 
	{
		if (*p != '%')
		{
			fputc(*p, fp ? fp : stdout);
			continue;
		}
		switch (*++p)
		{
		case 'd':
			ival = va_arg(ap, int);
			fprintf(fp ? fp : stdout, "%d", ival);
			break;
		case 'x':
			uival = va_arg(ap, unsigned int);
			fprintf(fp ? fp : stdout, "0x%x", uival);
			break;
		case 'X':
			uival = va_arg(ap, unsigned int);
			fprintf(fp ? fp : stdout, "0x%X", uival);
			break;
		case 'f':
			dval = va_arg(ap, double);
			fprintf(fp ? fp : stdout, "%f", dval);
			break;
		case 'c':
			cval = va_arg(ap, char);
			fprintf(fp ? fp : stdout, "%c", cval);
			break;
		case 's':
			for (sval = va_arg(ap, char *); *sval; sval++)
				fputc(*sval, fp ? fp : stdout);
			break;
		default:
			fputc(*sval, fp ? fp : stdout);
			break;
		}
	}
	fputc('\n', fp ? fp : stdout);
	fflush(fp ? fp : stdout);

	va_end(ap);
}
