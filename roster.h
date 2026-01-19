#ifndef ROSTER_H
#define ROSTER_H

#include <string>
#include "student.h"

class Roster {
public:
    static const int numStudents = 5;

private:
    Student* classRosterArray[numStudents];
    int lastIndex;

public:
    Roster();
    ~Roster();

    void parseAndAdd(const std::string& row);

    void add(std::string studentID,
             std::string firstName,
             std::string lastName,
             std::string emailAddress,
             int age,
             int daysInCourse1,
             int daysInCourse2,
             int daysInCourse3,
             DegreeProgram degreeProgram);

    void remove(std::string studentID);
    void printAll();
    void printAverageDaysInCourse(std::string studentID);
    void printInvalidEmails();
    void printByDegreeProgram(DegreeProgram degreeProgram);
};

#endif
