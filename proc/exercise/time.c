#include <time.h>
#include<stdio.h>

int main(){

	time_t cur_time;
	cur_time = time(NULL);
	printf("%ld", cur_time);	
	printf("%s", ctime(&cur_time));

	time_t t = time(NULL);
	struct tm tm = *localtime(&t);
  	printf("now: %d-%d-%d %d:%d:%d\n", tm.tm_year + 1900, tm.tm_mon + 1,tm.tm_mday, tm.tm_hour, tm.tm_min, tm.tm_sec);

	t -= 3600;
	tm = *localtime(&t);
	printf("now: %d-%d-%d %d:%d:%d\n", tm.tm_year + 1900, tm.tm_mon + 1,tm.tm_mday, tm.tm_hour, tm.tm_min, tm.tm_sec);

	
}
