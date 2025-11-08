#ifndef DOOMSDAY_H
#define DOOMSDAY_H

#include "date_utils.h"
#include <string>
#include <array>

class Doomsday {
public:
    enum class DayOfWeek {
        Sunday = 0,
        Monday = 1,
        Tuesday = 2,
        Wednesday = 3,
        Thursday = 4,
        Friday = 5,
        Saturday = 6
    };

    // Core Doomsday Algorithm functions
    static DayOfWeek getDayOfWeek(int day, int month, int year);
    static DayOfWeek getDayOfWeek(const DateUtils::Date& date);
    static std::string getDayName(DayOfWeek day);
    
    // Extended functionality
    static bool isSameWeekday(const DateUtils::Date& date1, const DateUtils::Date& date2);
    static DateUtils::Date findNextOccurrence(const DateUtils::Date& start, DayOfWeek targetDay);
    static std::vector<DateUtils::Date> findAllOccurrences(const DateUtils::Date& start, 
                                                          const DateUtils::Date& end, 
                                                          DayOfWeek targetDay);

    // Exam-specific utilities
    static std::string solveExamQuestion(const std::string& question);
    static std::vector<std::string> explainSolution(const DateUtils::Date& date);
    static std::string getMemorizationTip(int century);

private:
    static int getCenturyAnchor(int year);
    static int calculateYearDoomsday(int year);
    static int getMonthDoomsday(int month, bool isLeap);
    
    // Constants and lookup tables
    static const std::array<std::string, 7> dayNames;
    static const std::array<int, 13> monthDoomsdays;
    static const std::array<std::string, 7> doomsdayMnemonics;
};

#endif // DOOMSDAY_H
