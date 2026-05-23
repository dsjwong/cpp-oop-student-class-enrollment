#ifndef CLASS_H
#define CLASS_H

class Class;

class Student {
private:
    char* name;
    Class** classes;
    int classCount;
    int classCapacity;
public:
    Student(const char* name);
    ~Student();
    const char* getName() const;
    void enrollInClass(Class* classObj);
    void dropClass(Class* classObj);
    void listClasses() const;
};

class Class {
private:
    char* name;
    Student** students;
    int studentCount;
    int capacity;
public:
    Class(const char* name, int capacity);
    ~Class();
    const char* getName() const;
    bool enrollStudent(Student* student);
    bool dropStudent(Student* student);
    void listStudents() const;
};

#endif
