# Doomculator --version 1.0
# 🗓️ Doomsday Date Predictor and Aptitude Solver
#  An inspiration concept project from a Thanos's dialogue from movie Avengers : Infinity Wars and Avengers : Doomsday.

A practical C++ project that uses **John Conway’s Doomsday Algorithm** and **calendar mathematics** to determine the day of the week for any given date.  
It also computes **date differences**, useful for aptitude exams like **CAT**, **GATE**, or campus placements.  
![Dr DOOM](https://github.com/user-attachments/assets/451a6e13-a5fd-47e2-8a97-331423edd8ce)

---

## 🚀 Features
- Predicts the weekday for any date between 1600–2400.
- Calculates difference in days between two dates.
- Handles leap years accurately.
- Structured modular C++ design.
- Ready for both Linux (Makefile) and Visual Studio.

---

## 🧮 Core Concept
The Doomsday algorithm leverages **modular arithmetic** and **anchor day mapping** for centuries and years.  
For every year, it computes a “Doomsday” — a reference weekday that repeats monthly on fixed dates (e.g., 4/4, 6/6, 8/8).  
From this anchor, it determines the weekday for any date.

---

## ⚙️ Project Structure
Doomsday-Date-Predictor and Aptitude Solver/
│
├── src/
│   ├── main.cpp                    # Entry point
│   ├── doomsday.cpp                # Core algorithm implementation
│   ├── date_utils.cpp              # Mathematical date utilities
│
├── include/
│   ├── doomsday.h                  # Header for Doomsday functions
│   ├── date_utils.h                # Header for Date utility functions
│
├── tests/
│   ├── test_cases.cpp              # Unit tests for validation
│
├── docs/
│   ├── README.md                   # Project documentation (GitHub)
│   ├── algorithm_explanation.md    # Stepwise Doomsday math explanation
│
├── Makefile                        # For compiling on Linux/macOS
├── doomsday_project.sln            # Visual Studio project (optional)
└── LICENSE


## PROJECT OVERVIEW

This project implements John Conway’s Doomsday Algorithm to predict the day of the week for any given date, while also integrating calendar arithmetic and logical date manipulations (e.g., finding days after/before a given date, leap year analysis, difference between two dates).

The system can serve as:

A CS Aptitude and Competitive Exam (GATE/CAT) preparation tool.

A demonstration of algorithmic computation in C++.

A foundation module for future GUI or web-based calendar tools.

⚙️ FEATURES

✅ Implements Conway’s Doomsday Algorithm with modular design.
✅ Supports any valid Gregorian date (1600–9999).
✅ Computes:

Day of the week for any date.

Leap year checks.

Difference in days between two dates.

Days before/after a given date (like +100 days logic).
✅ Mathematical date shifts using modular arithmetic.
✅ Robust input validation.
✅ Structured for scalability and documentation.

Doomsday-Date-Predictor/
├── src/ # Source files
├── include/ # Header files
├── tests/ # Test cases
├── docs/ # Documentation
└── Makefile # Build instructions


---

## 🧩 How to Compile & Run

### Linux / macOS
```bash
g++ src/*.cpp -I include -o doomsday
./doomsday

Windows (MinGW)
g++ src/*.cpp -I include -o doomsday.exe
doomsday.exe
```

🧠 Algorithm Used

The project is based on Conway’s Doomsday Algorithm:

Each year has a “Doomsday” weekday.

Certain dates (like 4/4, 6/6, 8/8, etc.) always fall on that day.

Modular arithmetic determines the weekday shift for any given date.



🧮 Example Usage

Input:

Enter date (day month year): 26 1 2025


Output:

26/1/2025 falls on a Sunday.


Compact description:
A C++ command-line tool that uses John Conway’s Doomsday Algorithm and robust calendar arithmetic to compute the day of the week for any Gregorian date, together with complementary date utilities (date difference, add/subtract days, leap-year analysis). Built as a modular, testable codebase suitable for academic demonstration and extension to GUI/web interfaces.

Table of Contents

Project motivation

Key features

Supported range and limitations

Repository layout

Technology stack and dependencies

Build & run (step-by-step)

Usage examples

Implementation notes (algorithm + design decisions)

Test plan & sample test cases

How to extend (ideas for final-year demo)

Contribution & coding standards

License & acknowledgements

Contact

1. Project motivation

During aptitude tests and many competitive exams, date-based problems test a candidate’s logical reasoning and modular arithmetic skills. This project packages the Doomsday Algorithm into a developer-friendly tool so students can:

Learn the math behind date-calculation.

Test sample questions programmatically.

Extend the tool for GUI demos or exam-prep apps.

It also demonstrates clean software engineering practices (headers, modular cpp files, test harness, documentation).

2. Key features

Compute weekday for any valid Gregorian date (supported years 1600–9999).

Robust leap-year detection and validation.

Add or subtract N days from any date.

Compute difference in days between two dates.

Modular design: algorithm separated from utilities.

Unit-testable code with example test cases.

Clear command-line interaction for demo and evaluation.

3. Supported range & limitations

Designed for the proleptic Gregorian calendar (dates from year 1600 up to 9999).

Does not attempt Julian-to-Gregorian conversion for dates prior to 1582.

Inputs are expected as valid Gregorian dates; program performs validation and rejects impossible dates (e.g., 31 Feb).

Time-of-day and timezone handling are out of scope (the tool is date-only).




Further analysis:

Enter days to add/subtract: +100
📆 New date: 6/5/2025 (Tuesday)


📘 Future Enhancements

GUI version using Qt or Python Flask.

Historical calendar support (Julian to Gregorian).

Integration into competitive exam practice apps.



Technology stack & dependencies

Language: C++ (11 or later) — portable, efficient, and suitable for systems demos.

Build tools: g++ (GNU C++ compiler) on Linux/macOS; MinGW or Visual Studio on Windows.

No third-party libraries required for the core functionality; standard library only.

Optional (for tests): a lightweight test driver or C++ test framework (e.g., Catch2) can be added later.

6. Build & run (step-by-step)
Linux / macOS

Open a terminal in the repository root.

Build:

g++ -std=c++11 src/*.cpp -I include -o doomsday


Run:

./doomsday

Windows (MinGW)

From project root:

g++ -std=c++11 src/*.cpp -I include -o doomsday.exe
doomsday.exe


If you prefer a Makefile, run make after opening the repository (a simple Makefile target compiles src/*.cpp).

7. Usage examples
Example 1 — Basic weekday query
Enter date (day month year): 14 3 2032
Output:
14/3/2032 falls on a Sunday.

Example 2 — Add days
Enter date (day month year): 26 1 2025
Do you want to perform further date analysis? (y/n): y
Enter number of days to add/subtract (use negative for past): 100
Output:
New date: 6/5/2025 (Tuesday)

Example 3 — Difference between two dates (planned test function)

A helper test program computes days between:

Days between 01/01/2020 and 01/01/2021 = 366

8. Implementation notes (algorithm & design decisions)
Doomsday Algorithm (core idea)

Each year has a “Doomsday” weekday.

Predefined anchor dates (e.g., 4/4, 6/6, 8/8, 5/9, 9/5, 7/11, 11/7, 3/14, 12/12) all fall on the Doomsday in that year.

The Doomsday for the year is computed via:

Take last two digits of year → y.

a = floor(y/12), b = y % 12, c = floor(b/4).

doomsday = (a + b + c + century_anchor) mod 7.

Century anchor is computed using century % 4 mapping (2000s → Tuesday, etc.)

Date arithmetic

Days-in-month table is used with leap-year adjustments.

Adding/subtracting days loops across month/year boundaries until the final normalized date is reached; this approach is simple and robust for the scope required.

Validation uses per-month day limits; leap-year rules follow Gregorian standard.

Design considerations

Separation of concerns: doomsday.* contains algorithm and weekday mapping; date_utils.* contains validation and arithmetic.

The CLI (main.cpp) acts as a thin orchestration layer — ideal for later replacement by a GUI.

9. Test plan & sample test cases

Include tests/test_cases.cpp with assert-style checks you can run manually:

Basic known dates

14/3/2032 → Sunday

26/1/2025 → Sunday

1/1/2000 → Saturday

Leap years

29/2/2020 → Saturday

invalid 29/2/2019 → validation failure

Date arithmetic

Add 365 days to 1/1/2019 → 1/1/2020 (check weekday shift)

Subtract 30 days from 1/3/2020 → 31/1/2020

Run tests by compiling tests/test_cases.cpp with the project sources and running the test binary. Optionally integrate a test framework.

10. How to extend (ideas for final-year demo)

GUI: Qt (C++) or Electron/front-end + backend wrapper.

Web API: Provide endpoints (REST) that accept date and return JSON with weekday and meta-data.

Historical mode: Add Julian-to-Gregorian conversion / historical calendar handling.

Batch mode: Accept CSV input of many dates and write weekday outputs (useful for large datasets).

Explain mode: Output step-by-step Doomsday computation for teaching (show a, b, c, century anchor).

Interactive practice mode: Random date questions with scoring for exam-style practice.

11. Contribution & coding standards

Follow modern C++ style: meaningful names, clear header guards, modularization.

Keep functions small and testable.

Document public APIs in headers.

When contributing, include tests for new features and update docs/ as needed.

Use Git branches for features and pull requests for review.

12. License & acknowledgements

License: MIT (copy the MIT text into LICENSE).

Acknowledgements : John H. Conway for the Doomsday Algorithm; standard C++ library for conventional utilities.
🧑‍💻 Author
Developed by Abhinav Tiwari (B.Tech, Computer Science Engineering)
Inspired by John Conway’s Mathematical Legacy and 2 of Marvel Comics Studio's Avengers movies

