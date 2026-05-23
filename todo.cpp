#include "class.h"
#include <iostream>
#include <cstring>
using namespace std;

Student::Student(const char *name) {
    this->name = new char[strlen(name) + 1];
    strcpy(this->name, name);
    classCount = 0; classCapacity = 2;
    classes = new Class*[classCapacity];
    cout << "Student: " << name << " initialized!" << endl;
}

Student::~Student() {
    int cnt = this->classCount;
    Class** classesToDrop = new Class*[cnt];
    for (int i = 0; i < cnt; i++) classesToDrop[i] = classes[i];
    for (int i = 0; i < cnt; i++) classesToDrop[i]->dropStudent(this);
    cout << "Student: " << name << " destroyed!" << endl;
    delete[] classesToDrop;
    delete[] name; name = nullptr;
    delete[] classes; classes = nullptr;
}

Class::Class(const char *name, int capacity) {
    this->name = new char[strlen(name) + 1];
    strcpy(this->name, name);
    this->capacity = capacity;
    students = new Student*[capacity];
    studentCount = 0;
    cout << "Class: " << name << " created with capacity " << capacity << "." << endl;
}

Class::~Class() {
    cout << "Class: " << name << " destroyed." << endl;
    delete[] name; name = nullptr;
    delete[] students; students = nullptr;
}

bool Class::enrollStudent(Student *student) {
    if (studentCount >= capacity) { cout << "Class " << name << " is full. Cannot enroll student!" << endl; return false; }
    students[studentCount++] = student;
    student->enrollInClass(this);
    cout << "Student " << student->getName() << " enrolled in class " << name << "." << endl;
    return true;
}

bool Class::dropStudent(Student *student) {
    int index = -1;
    for (int i = 0; i < studentCount; i++) if (students[i] == student) { index = i; break; }
    if (index == -1) { cout << "Student " << student->getName() << " is not in class " << name << "." << endl; return false; }
    for (int i = index; i < studentCount - 1; i++) students[i] = students[i + 1];
    students[studentCount - 1] = nullptr; studentCount--;
    student->dropClass(this);
    cout << "Student " << student->getName() << " dropped from class " << name << "." << endl;
    return true;
}
