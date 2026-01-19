#ifndef DEGREE_H
#define DEGREE_H

#include <string>

enum DegreeProgram { SECURITY, NETWORK, SOFTWARE };

static inline std::string degreeProgramToString(DegreeProgram dp) {
    switch (dp) {
        case SECURITY: return "SECURITY";
        case NETWORK:  return "NETWORK";
        case SOFTWARE: return "SOFTWARE";
        default:       return "UNKNOWN";
    }
}

#endif
