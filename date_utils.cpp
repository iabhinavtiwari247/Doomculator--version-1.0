#include "../include/date_utils.h"
#include "../include/doomsday.h"
#include <iostream>

int daysInMonth(int month, int year) {
    int days[] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
    if (isLeapYear(year)) days[2] = 29;
    return days[month];
}

bool isValidDate(int day, int month, int year) {
    if (month < 1 || month > 12) return false;
    if (day < 1 || day > daysInMonth(month, year)) return false;
    return true;
}

void addDaysToDate(int day, int month, int year, int n) {
    day += n;

    while (day > daysInMonth(month, year)) {
        day -= daysInMonth(month, year);
        month++;
        if (month > 12) {
            month = 1;
            year++;
        }
    }

    while (day < 1) {
        month--;
        if (month < 1) {
            month = 12;
            year--;
        }
        day += daysInMonth(month, year);
    }

    std::string resultDay = getDayOfWeek(day, month, year);
    std::cout << "📆 New date: " << day << "/" << month << "/" << year
              << " (" << resultDay << ")" << std::endl;
}
