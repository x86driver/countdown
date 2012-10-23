#include <stdio.h>
#include <time.h>

int main()
{
	struct tm now, future;
	time_t t = time(NULL);
	time_t fut;

	localtime_r(&t, &now);
	future = now;

	future.tm_year = 112;
	future.tm_mon = 9;
	future.tm_mday = 24;
	future.tm_hour = future.tm_min = future.tm_sec = 0;

	fut = mktime(&future);
	double diff = difftime(fut, t);
	unsigned int day = (diff / 86400) + 1;

	printf("%d/%02d/%02d %02d:%02d:%02d\n", now.tm_year+1900, now.tm_mon+1, now.tm_mday, now.tm_hour, now.tm_min, now.tm_sec);
	printf("%.0f seconds\n", diff);
	printf("%d days\n", day);
	return 0;
}

