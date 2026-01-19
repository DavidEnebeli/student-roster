#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include "degree.h"

class Student {
private:
    std::string studentID;
    std::string firstName;
    std::string lastName;
    std::string emailAddress;
    int age;
    int daysInCourse[3];
    DegreeProgram degreeProgram;

public:
    // Constructors / Destructor
    Student();
    Student(std::string studentID,
            std::string firstName,
            std::string lastName,
            std::string emailAddress,
            int age,
            int daysInCourse1,
            int daysInCourse2,
            int daysInCourse3,
            DegreeProgram degreeProgram);
    ~Student();

    // Getters
    std::string getStudentID() const;
    std::string getFirstName() const;
    std::string getLastName() const;
    std::string getEmailAddress() const;
    int getAge() const;
    const int* getDaysInCourse() const;
    DegreeProgram getDegreeProgram() const;

    // Setters 
    void setStudentID(const std::string& studentID);
    void setFirstName(const std::string& firstName);
    void setLastName(const std::string& lastName);
    void setEmailAddress(const std::string& emailAddress);
    void setAge(int age);
    void setDaysInCourse(int days1, int days2, int days3);
    void setDegreeProgram(DegreeProgram degreeProgram);

    
    void print() const;
};

#endif
