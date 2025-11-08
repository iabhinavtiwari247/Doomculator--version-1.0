#ifndef DATE_UTILS_H
#define DATE_UTILS_H

#include <string>
#include <vector>

class DateUtils {
public:
    struct Date {
        int day;
        int month;
        int year;
        
        Date(int d, int m, int y) : day(d), month(m), year(y) {}
        bool operator==(const Date& other) const;
        bool operator<(const Date& other) const;
    };

    // Date validation
    static bool isValidDate(int day, int month, int year);
    static bool isLeapYear(int year);
    
    // Date arithmetic
    static Date addDays(const Date& date, int days);
    static Date subtractDays(const Date& date, int days);
    static int dateDifference(const Date& date1, const Date& date2);
    
    // Date formatting
    static std::string formatDate(const Date& date, const std::string& format = "DD/MM/YYYY");
    static Date parseDate(const std::string& dateStr, const std::string& format = "DD/MM/YYYY");
    
    // Date patterns
    static Date findNextWeekday(const Date& startDate, int weekday);
    static std::vector<Date> findAllWeekdaysInMonth(int month, int year, int weekday);
    static int countWeekdaysBetweenDates(const Date& start, const Date& end, int weekday);

    // Helper functions
    static int getDaysInMonth(int month, int year);
    static bool isWeekend(const Date& date);
    static int daysBetween(const Date& start, const Date& end);

private:
    static const int daysInMonth[13];
    static int calculateJulianDay(const Date& date);
};

#endif // DATE_UTILS_H
