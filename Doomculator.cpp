#include "../include/doomsday.h"
#include <cmath>
#include <string>

int getCenturyAnchor(int year) {
    int century = year / 100;
    int anchors[] = {2, 0, 5, 3}; // 2000s=2 (Tue), 2100s=0 (Sun), 1900s=3 (Wed), 1800s=5 (Fri)
    return anchors[(century % 4)];
}

bool isLeapYear(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

int getMonthDoomsday(int month, bool leap) {
    int doomsdays[] = {0, 3, 28, 14, 4, 9, 6, 11, 8, 5, 10, 7, 12};
    if (leap && month == 1) return 4;
    if (leap && month == 2) return 29;
    return doomsdays[month];
}

int calculateYearDoomsday(int year) {
    int y = year % 100;
    int a = y / 12;
    int b = y % 12;
    int c = b / 4;
    int anchor = getCenturyAnchor(year);
    int doomsday = (a + b + c + anchor) % 7;
    return doomsday;
}

std::string getDayOfWeek(int day, int month, int year) {
    std::string days[] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
    bool leap = isLeapYear(year);
    int doomsday = calculateYearDoomsday(year);
    int ref = getMonthDoomsday(month, leap);
    int diff = (day - ref) % 7;
    if (diff < 0) diff += 7;
    int result = (doomsday + diff) % 7;
    return days[result];
}
