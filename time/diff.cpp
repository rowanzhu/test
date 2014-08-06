#include <cstdio>
#include <cstdlib>

static const int SECONDS_PER_MINUTE = 60;
static const int SECONDS_PER_HOUR = 60 * SECONDS_PER_MINUTE;
static const int SECONDS_PER_DAY = 24 * SECONDS_PER_HOUR;
static const int SECONDS_PER_WEEK = 7 * SECONDS_PER_DAY;
static const int SECONDS_LOCAL_BEFORE_UTC_TIME = 28800;

inline int week_diff(const time_t old_time, const time_t new_time)
{
    return (new_time + 3 * SECONDS_PER_DAY + SECONDS_LOCAL_BEFORE_UTC_TIME) /SECONDS_PER_WEEK - (old_time + 3 * SECONDS_PER_DAY + SECONDS_LOCAL_BEFORE_UTC_TIME) / SECONDS_PER_WEEK;
}

inline int day_diff(const time_t old_time, const time_t new_time)
{
    return (new_time + SECONDS_LOCAL_BEFORE_UTC_TIME) / SECONDS_PER_DAY - ( old_time + SECONDS_LOCAL_BEFORE_UTC_TIME) / SECONDS_PER_DAY;
}

int main(int argc, char *argv[])
{
    unsigned int begin = 1402761600;
    unsigned int end = atoi(argv[1]);

    int week_of_what = week_diff(begin, end);
    int day_of_what = day_diff(begin, end);

    printf("week_diff|%u|%d\n", end, week_of_what);
    printf("day_diff|%u|%d\n", end, day_of_what);


    return 0;
}