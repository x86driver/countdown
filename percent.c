#include <stdio.h>
#include <time.h>

/*
  diff1 = end - begin
  diff2 = now - begin
*/

int main()
{
	struct tm begin, end, now;
	time_t now_t = time(NULL);
	time_t begin_t, end_t;

	gmtime_r(&now_t, &now);
	begin = end = now;

	begin.tm_year = 112;
	begin.tm_mon = 1;
	begin.tm_mday = 10;
	begin.tm_hour = 20;
	begin.tm_min = begin.tm_sec = 0;

	end.tm_year = 112;
	end.tm_mon = 1;
	end.tm_mday = 12;
	end.tm_hour = 16;
	end.tm_min = end.tm_sec = 0;

	begin_t = mktime(&begin);
	end_t = mktime(&end);

	double diff1 = difftime(end_t, begin_t);
	double diff2 = difftime(now_t, begin_t);
	double percent = diff2 / diff1 * 100.0;

	printf("%.10lf%%\n", percent);

	return 0;
}

