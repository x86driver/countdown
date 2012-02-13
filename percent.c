#include <stdio.h>
#include <time.h>

/*
  diff1 = end - begin
  diff2 = now - begin
*/

void init_tm(struct tm *t, int mon, int day, int hour, int min)
{
	struct tm now;
	time_t now_t = time(NULL);
	gmtime_r(&now_t, &now);
	*t = now;

	t->tm_year = 112;
	t->tm_mon = mon-1;
	t->tm_mday = day;
	t->tm_hour = hour;
	t->tm_min = min;
	t->tm_sec = 0;
}

double percent(struct tm *begin, struct tm *end)
{
	struct tm now;
	time_t now_t = time(NULL);
	time_t begin_t, end_t;

	gmtime_r(&now_t, &now);

	begin_t = mktime(begin);
	end_t = mktime(end);

	double diff1 = difftime(end_t, begin_t);
	double diff2 = difftime(now_t, begin_t);
	double percent = diff2 / diff1 * 100.0;

	return percent;
}

int main()
{
	struct tm begin, end;

	init_tm(&begin, 2, 12, 16, 0);
	init_tm(&end, 2, 17, 17, 0);

	printf("%.10lf%%\n", percent(&begin, &end));

	return 0;
}
