#include <gtest/gtest.h>
#include "date_utils.h"
#include "doomsday.h"

class DoomsdayTest : public ::testing::Test {
protected:
    void SetUp() override {
        // Setup code if needed
    }
};

TEST_F(DoomsdayTest, BasicDayOfWeek) {
    // Test some known dates
    EXPECT_EQ(Doomsday::getDayName(Doomsday::getDayOfWeek(1, 1, 2023)), "Sunday");
    EXPECT_EQ(Doomsday::getDayName(Doomsday::getDayOfWeek(4, 7, 2023)), "Tuesday");
    EXPECT_EQ(Doomsday::getDayName(Doomsday::getDayOfWeek(25, 12, 2023)), "Monday");
}

TEST_F(DoomsdayTest, LeapYearDates) {
    // Test leap year dates
    EXPECT_EQ(Doomsday::getDayName(Doomsday::getDayOfWeek(29, 2, 2024)), "Thursday");
    EXPECT_EQ(Doomsday::getDayName(Doomsday::getDayOfWeek(1, 3, 2024)), "Friday");
}

TEST_F(DoomsdayTest, HistoricalDates) {
    // Test some historical dates
    EXPECT_EQ(Doomsday::getDayName(Doomsday::getDayOfWeek(4, 7, 1776)), "Thursday");
    EXPECT_EQ(Doomsday::getDayName(Doomsday::getDayOfWeek(14, 4, 1865)), "Friday");
}

TEST_F(DoomsdayTest, InvalidDates) {
    // Test invalid dates
    EXPECT_THROW(Doomsday::getDayOfWeek(29, 2, 2023), std::invalid_argument);
    EXPECT_THROW(Doomsday::getDayOfWeek(31, 4, 2023), std::invalid_argument);
    EXPECT_THROW(Doomsday::getDayOfWeek(0, 1, 2023), std::invalid_argument);
}

TEST_F(DoomsdayTest, DateArithmetic) {
    DateUtils::Date start(1, 1, 2023);
    
    // Test adding days
    auto result = DateUtils::addDays(start, 7);
    EXPECT_EQ(result.day, 8);
    EXPECT_EQ(result.month, 1);
    EXPECT_EQ(result.year, 2023);
    
    // Test month rollover
    result = DateUtils::addDays(start, 31);
    EXPECT_EQ(result.day, 1);
    EXPECT_EQ(result.month, 2);
    EXPECT_EQ(result.year, 2023);
}

TEST_F(DoomsdayTest, LeapYearChecks) {
    EXPECT_TRUE(DateUtils::isLeapYear(2000));
    EXPECT_TRUE(DateUtils::isLeapYear(2024));
    EXPECT_FALSE(DateUtils::isLeapYear(2100));
    EXPECT_FALSE(DateUtils::isLeapYear(2023));
}

TEST_F(DoomsdayTest, DateDifference) {
    DateUtils::Date date1(1, 1, 2023);
    DateUtils::Date date2(1, 1, 2024);
    
    EXPECT_EQ(DateUtils::daysBetween(date1, date2), 365);
    
    date2 = DateUtils::Date(1, 3, 2024);
    EXPECT_EQ(DateUtils::daysBetween(date1, date2), 365 + 31 + 29); // Including January and February of leap year
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
