#include <iostream>
#include <string>
#include <cmath>
#include "../include/doomsday.h"
#include "../include/date_utils.h"

int main() {
    int day, month, year;
    std::cout << "==============================" << std::endl;
    std::cout << "   DOOMSDAY DATE PREDICTOR   " << std::endl;
    std::cout << "==============================" << std::endl;

    std::cout << "Enter date (day month year): ";
    std::cin >> day >> month >> year;

    if (!isValidDate(day, month, year)) {
        std::cout << "❌ Invalid date entered. Please try again." << std::endl;
        return 1;
    }

    std::string dayOfWeek = getDayOfWeek(day, month, year);
    std::cout << "\n📅 " << day << "/" << month << "/" << year << " falls on a " << dayOfWeek << "." << std::endl;

    // Additional computations
    std::cout << "\nDo you want to perform further date analysis? (y/n): ";
    char choice;
    std::cin >> choice;

    if (choice == 'y' || choice == 'Y') {
        int n;
        std::cout << "Enter number of days to add/subtract (use negative for past): ";
        std::cin >> n;
        addDaysToDate(day, month, year, n);
    }

    return 0;
}
