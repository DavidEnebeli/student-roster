#include "student.h"
#include <iostream>

Student::Student()
    : studentID(""),
      firstName(""),
      lastName(""),
      emailAddress(""),
      age(0),
      degreeProgram(SOFTWARE) {
    daysInCourse[0] = daysInCourse[1] = daysInCourse[2] = 0;
}

Student::Student(std::string studentID,
                 std::string firstName,
                 std::string lastName,
                 std::string emailAddress,
                 int age,
                 int daysInCourse1,
                 int daysInCourse2,
                 int daysInCourse3,
                 DegreeProgram degreeProgram)
    : studentID(studentID),
      firstName(firstName),
      lastName(lastName),
      emailAddress(emailAddress),
      age(age),
      degreeProgram(degreeProgram) {
    daysInCourse[0] = daysInCourse1;
    daysInCourse[1] = daysInCourse2;
    daysInCourse[2] = daysInCourse3;
}

Student::~Student() = default;

// Getters
std::string Student::getStudentID() const { return studentID; }
std::string Student::getFirstName() const { return firstName; }
std::string Student::getLastName() const { return lastName; }
std::string Student::getEmailAddress() const { return emailAddress; }
int Student::getAge() const { return age; }
const int* Student::getDaysInCourse() const { return daysInCourse; }
DegreeProgram Student::getDegreeProgram() const { return degreeProgram; }

// Setters
void Student::setStudentID(const std::string& id) { studentID = id; }
void Student::setFirstName(const std::string& fn) { firstName = fn; }
void Student::setLastName(const std::string& ln) { lastName = ln; }
void Student::setEmailAddress(const std::string& email) { emailAddress = email; }
void Student::setAge(int a) { age = a; }

void Student::setDaysInCourse(int d1, int d2, int d3) {
    daysInCourse[0] = d1;
    daysInCourse[1] = d2;
    daysInCourse[2] = d3;
}

void Student::setDegreeProgram(DegreeProgram dp) { degreeProgram = dp; }

void Student::print() const {
    std::cout << studentID << "\t"
              << "First Name: " << firstName << "\t"
              << "Last Name: " << lastName << "\t"
              << "Email: " << emailAddress << "\t"
              << "Age: " << age << "\t"
              << "daysInCourse: {" << daysInCourse[0] << ", "
                                  << daysInCourse[1] << ", "
                                  << daysInCourse[2] << "} "
              << "Degree Program: " << degreeProgramToString(degreeProgram)
              << std::endl;
}
