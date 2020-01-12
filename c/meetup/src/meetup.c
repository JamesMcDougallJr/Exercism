#include "meetup.h"

/**
 * meetup_day_of_month returns the date of the month from the given info
 * Param year is the year
 * Param month is the month in that year
 * Param week is the week within the month
 * Param day_of_week is the name of the day of the week
 */
int meetup_day_of_month(unsigned int year, unsigned int month, const char *week,
                        const char *day_of_week)
{
  int first_day = get_first_day(year); // first "day of week" of the year
  Month current_month = Jan;
  int number_of_days_passed = 0;
  while (current_month != (Month) month) {
    number_of_days_passed += days_in_month(current_month);
    current_month += 1;
  }

  /**
   * Get the first "day of week" of the given month so I can count up from
   * there
   */
  char *first_day_of_month = get_first_day_of_month(number_of_days_passed, first_day);

  return -1;
}

/**
 * Get the first day of the given month
 * Param num_days is the number of days since the beginning of the year
 * Param first_day is the "day of the week" of the first day of the year
 */
char *get_first_day_of_month(int num_days, char *first_day) {
  int num_weeks = num_days / DAYS_IN_WEEK;
  int remaining_days = num_days % DAYS_IN_WEEK;
  // TODO Compute the "day of week" of the first day in the month
}

/**
 * Get the first day's day_of_week for the given year
 * Param year is the integer year, e.g. 2016, 2017, 2018
 */
char *get_first_day_of_year(int year) {
  for(int i = 0; i < NUMYEARS; i++) {
    if(firstDays[0].year == year) {
      return firstDays[0].day_of_week;
    }
  }
  return 0;
}

