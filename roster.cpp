#include "roster.h"
#include <iostream>
#include <sstream>

Roster::Roster() : lastIndex(-1) {
    for (int i = 0; i < numStudents; ++i) {
        classRosterArray[i] = nullptr;
    }
}

Roster::~Roster() {
    for (int i = 0; i < numStudents; ++i) {
        delete classRosterArray[i];
        classRosterArray[i] = nullptr;
    }
}

void Roster::add(std::string studentID,
                 std::string firstName,
                 std::string lastName,
                 std::string emailAddress,
                 int age,
                 int daysInCourse1,
                 int daysInCourse2,
                 int daysInCourse3,
                 DegreeProgram degreeProgram) {

    if (lastIndex >= numStudents - 1) {
        std::cout << "Roster is full; cannot add " << studentID << std::endl;
        return;
    }

    ++lastIndex;
    classRosterArray[lastIndex] = new Student(studentID, firstName, lastName,
                                              emailAddress, age,
                                              daysInCourse1, daysInCourse2, daysInCourse3,
                                              degreeProgram);
}

void Roster::parseAndAdd(const std::string& row) {
    std::stringstream ss(row);
    std::string token;

    std::string parts[9];
    int idx = 0;

    while (std::getline(ss, token, ',') && idx < 9) {
        parts[idx++] = token;
    }

    std::string id = parts[0];
    std::string first = parts[1];
    std::string last = parts[2];
    std::string email = parts[3];
    int age = std::stoi(parts[4]);
    int d1 = std::stoi(parts[5]);
    int d2 = std::stoi(parts[6]);
    int d3 = std::stoi(parts[7]);

    DegreeProgram dp = SOFTWARE;
    if (parts[8] == "SECURITY") dp = SECURITY;
    else if (parts[8] == "NETWORK") dp = NETWORK;
    else if (parts[8] == "SOFTWARE") dp = SOFTWARE;

    add(id, first, last, email, age, d1, d2, d3, dp);
}

void Roster::printAll() {
    for (int i = 0; i <= lastIndex; ++i) {
        if (classRosterArray[i] != nullptr) {
            classRosterArray[i]->print();
        }
    }
}

void Roster::printAverageDaysInCourse(std::string studentID) {
    for (int i = 0; i <= lastIndex; ++i) {
        if (classRosterArray[i] && classRosterArray[i]->getStudentID() == studentID) {
            const int* d = classRosterArray[i]->getDaysInCourse();
            double avg = (d[0] + d[1] + d[2]) / 3.0;
            std::cout << "Average days in course for " << studentID
                      << ": " << avg << std::endl;
            return;
        }
    }
    std::cout << "Student with ID " << studentID << " not found for average calculation."
              << std::endl;
}

void Roster::printInvalidEmails() {
    bool foundAny = false;

    for (int i = 0; i <= lastIndex; ++i) {
        if (!classRosterArray[i]) continue;

        std::string email = classRosterArray[i]->getEmailAddress();

        bool hasAt = (email.find('@') != std::string::npos);
        bool hasDot = (email.find('.') != std::string::npos);
        bool hasSpace = (email.find(' ') != std::string::npos);

        if (!hasAt || !hasDot || hasSpace) {
            std::cout << "Invalid email: " << email << std::endl;
            foundAny = true;
        }
    }

    if (!foundAny) {
        std::cout << "No invalid emails found." << std::endl;
    }
}

void Roster::printByDegreeProgram(DegreeProgram degreeProgram) {
    for (int i = 0; i <= lastIndex; ++i) {
        if (classRosterArray[i] && classRosterArray[i]->getDegreeProgram() == degreeProgram) {
            classRosterArray[i]->print();
        }
    }
}

void Roster::remove(std::string studentID) {
    for (int i = 0; i <= lastIndex; ++i) {
        if (classRosterArray[i] && classRosterArray[i]->getStudentID() == studentID) {

            delete classRosterArray[i];
            classRosterArray[i] = nullptr;

            for (int j = i; j < lastIndex; ++j) {
                classRosterArray[j] = classRosterArray[j + 1];
            }
            classRosterArray[lastIndex] = nullptr;
            --lastIndex;

            std::cout << "Removed student with ID: " << studentID << std::endl;
            return;
        }
    }

    std::cout << "ERROR: Student with ID " << studentID << " was not found." << std::endl;
}
