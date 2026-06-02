# Student Class Enrollment System (C++ OOP)

Manages student enrolment in courses using C++ OOP, modelling the relationship between students and classes with capacity constraints and enrolment rules.

## Tech Stack

- **Language:** C++17
- **Concepts:** OOP, composition, dynamic arrays, class relationships

## Class Design

- `Student`: stores student ID, name, list of enrolled classes
- `Class`: stores class ID, name, capacity, enrolled students list
- Enrolment logic: capacity checks, duplicate prevention, drop/add operations

## Project Structure

```
cpp-oop-student-class-enrollment/
├── main.cpp
├── class.h / class.cpp
└── todo.cpp    # Additional implementation tasks
```

## How to Build & Run

```bash
g++ -std=c++17 -o enrollment main.cpp class.cpp todo.cpp
./enrollment
```

## Features

- Enrol a student in a class (with capacity check)
- Drop a student from a class
- List all students in a class
- List all classes a student is enrolled in
- Check enrolment status

## Building

Requires a C++17-compatible compiler (GCC 9+ or Clang 10+).

```bash
# Compile
g++ -std=c++17 -O2 -Wall -o main main.cpp

# Or with CMake (if CMakeLists.txt is present)
cmake -B build && cmake --build build
```

No external libraries required — standard library only.
