# Doomsday Algorithm Explanation

## Overview
The Doomsday algorithm, developed by John Conway, is a method for calculating the day of the week for any given date. It's based on the concept of "doomsdays" - dates that always fall on the same day of the week within a year.

## Key Concepts

### 1. Century Anchors
Each century has an "anchor day":
- 1700s: Friday (5)
- 1800s: Wednesday (3)
- 1900s: Tuesday (2)
- 2000s: Sunday (0)
- 2100s: Friday (5)

### 2. Doomsdays in Each Month
Memorable dates that fall on the same day (doomsday) in each year:
- January: 3rd (non-leap) / 4th (leap)
- February: Last day
- March: 0th (last day of February)
- April: 4th
- May: 9th
- June: 6th
- July: 11th
- August: 8th
- September: 5th
- October: 10th
- November: 7th
- December: 12th

Mnemonic: "Working 9 to 5 at the 7-11"

### 3. Algorithm Steps

1. **Find the Century Anchor**
   - Determine the anchor day for the century
   - Each century follows a pattern: 2, 0, 5, 3

2. **Calculate Year's Doomsday**
   ```
   a. Take last two digits of year (y)
   b. Add y/12 (floor division)
   c. Add remainder of y/12
   d. Add (remainder)/4 (floor division)
   e. Add century anchor
   f. Mod 7 gives doomsday
   ```

3. **Find Nearest Doomsday**
   - Identify the closest doomsday in the target month
   - Count days forward/backward to target date

4. **Calculate Final Day**
   - Add/subtract the difference from nearest doomsday
   - Take modulo 7 to get day of week

## Example Calculation

To find the day for July 4, 2023:

1. Century anchor for 2000s = 2 (Tuesday)
2. Year calculation:
   - Last two digits: 23
   - 23/12 = 1
   - Remainder = 11
   - 11/4 = 2
   - Sum = 1 + 11 + 2 + 2 = 16
   - 16 mod 7 = 2 (Tuesday)
3. July's doomsday is 11th
4. Count from July 11 (Tuesday) back 7 days to July 4
   - Result: Tuesday

## Practice Tips

1. **Memorize Century Anchors**
   - Use mnemonic: "2053" = 2000s(2), 1900s(0), 1800s(5), 1700s(3)

2. **Learn Monthly Patterns**
   - Even months are easy: 4/4, 6/6, 8/8, 10/10, 12/12
   - Odd months follow "Working 9 to 5 at the 7-11"

3. **Shortcuts**
   - Last day of February is always a doomsday
   - 7/11 and 11/7 are doomsdays
   - 9/5 and 5/9 are doomsdays

## Common Exam Question Types

1. **Direct Day Calculation**
   - "What day was July 4, 1776?"
   - "On what day will Christmas fall in 2024?"

2. **Day Pattern Questions**
   - "How many Sundays in October 2023?"
   - "What is the first Tuesday after a specific date?"

3. **Historical Events**
   - "What day was the Declaration of Independence signed?"
   - "What day was President Lincoln assassinated?"

4. **Date Arithmetic**
   - "What day will it be 100 days from now?"
   - "How many days between two dates?"

## Tips for Speed Solving

1. Use the nearest doomsday to your target date
2. Practice mental arithmetic for modulo 7 calculations
3. Remember key historical dates and their days
4. Learn to count forward and backward through days quickly
5. Memorize patterns in common dates (holidays, month ends, etc.)
