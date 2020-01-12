#ifndef MEETUP_H
#define MEETUP_H

#define NUMYEARS 1
#define DAYS_IN_WEEK 7

typedef enum Month
{
  Jan = 0,
  Feb = 1,
  Mar = 2,
  Apr = 3,
  May = 4,
  Jun = 5,
  Jul = 6,
  Aug = 7,
  Sep = 8,
  Oct = 9,
  Nov = 10,
  Dec = 11,
} Month;

//  the number of days in each month, in a non leap year
Month days_in_month[12] = {
  31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31
};

typedef struct first_day {
  int year;
  char *day_of_week;
} first_day;

first_day firstDays[] = {
  {.year = 2013, .day_of_week = "Tuesday"}
};

/**
 * Get the day of month from the given information
 */
int meetup_day_of_month(unsigned int year, unsigned int month, const char *week,
                        const char *day_of_week);

char *get_first_day_of_year(int year);

/**
 * 
 */
char *get_first_day_of_month(int num_days, char *first_day);

#endif
