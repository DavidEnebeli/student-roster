#include <iostream>
#include <string>
#include "roster.h"

int main() {
    std::cout << "Course Title: Scripting and Programming - Applications" << std::endl;
    std::cout << "Programming Language: C++" << std::endl;
    std::cout << "WGU Student ID: 012511325 " << std::endl;
    std::cout << "Name: David Enebeli" << std::endl;
    std::cout << std::endl;

    const std::string studentData[] = {
        "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
        "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
        "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
        "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
        "A5,David,Enebeli,denebe1@wgu.edu,23,10,20,30,SOFTWARE"
    };

    Roster classRoster;

    for (int i = 0; i < Roster::numStudents; ++i) {
        classRoster.parseAndAdd(studentData[i]);
    }

    std::cout << "Displaying all students:" << std::endl;
    classRoster.printAll();
    std::cout << std::endl;

    std::cout << "Displaying invalid emails:" << std::endl;
    classRoster.printInvalidEmails();
    std::cout << std::endl;

    std::cout << "Displaying average days in course for each student:" << std::endl;
    for (int i = 0; i < Roster::numStudents; ++i) {
        std::string id = studentData[i].substr(0, studentData[i].find(','));
        classRoster.printAverageDaysInCourse(id);
    }
    std::cout << std::endl;

    std::cout << "Displaying students by degree program (SOFTWARE):" << std::endl;
    classRoster.printByDegreeProgram(SOFTWARE);
    std::cout << std::endl;

    std::cout << "Removing A3:" << std::endl;
    classRoster.remove("A3");
    std::cout << std::endl;

    std::cout << "Displaying all students after removing A3:" << std::endl;
    classRoster.printAll();
    std::cout << std::endl;

    std::cout << "Removing A3 again (should show not found message):" << std::endl;
    classRoster.remove("A3");
    std::cout << std::endl;

    return 0;
}
