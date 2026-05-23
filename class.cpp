#include "class.h"
#include <iostream>
#include <cstring>
using namespace std;

const char* Class::getName() const { return name; }

void Class::listStudents() const {
    if (studentCount == 0) { cout << "No students enrolled in class " << name << "." << endl; return; }
    cout << "Students in class " << name << ":" << endl;
    for (int i = 0; i < studentCount; ++i)
        if (students[i] != nullptr) cout << "- " << students[i]->getName() << endl;
}

const char* Student::getName() const { return name; }

void Student::enrollInClass(Class* classObj) {
    if (classCount >= classCapacity) {
        classCapacity *= 2;
        Class** newClasses = new Class*[classCapacity];
        for (int i = 0; i < classCount; ++i) newClasses[i] = classes[i];
        delete[] classes;
        classes = newClasses;
    }
    classes[classCount++] = classObj;
}

void Student::dropClass(Class* classObj) {
    for (int i = 0; i < classCount; ++i) {
        if (classes[i] == classObj) {
            for (int j = i; j < classCount - 1; ++j) classes[j] = classes[j + 1];
            --classCount;
            return;
        }
    }
}

void Student::listClasses() const {
    if (classCount == 0) { cout << "Student: " << name << " is not enrolled in any classes." << endl; return; }
    cout << "Classes for student " << name << ":" << endl;
    for (int i = 0; i < classCount; ++i) cout << "- " << classes[i]->getName() << endl;
}
