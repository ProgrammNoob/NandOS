#ifndef TIME_H
#define TIME_H

typedef int clock_t
typedef int time_t


char *asctime(const struct tm* tmptr);
clock_t clock(void);
char* ctime(const time_t* timer);
double difftime(time_t timer2, time_t timer1);
struct tm* gmtime(const time_t* timer);
struct tm* localtime(const time_t* timer);
time_t mktime(struct tm* ptm);
size t strftime(char* s, size t n, const char* format, const struct tm* tptr);
time_t time(time_t* timer);


#endif