#ifndef securityStudent_H
#define securityStudent_H

#include <string>
#include "Student.h"
#include "degree.h"
using namespace std;

class SecurityStudent: public Student{
    
public:
    //Constructors
    SecurityStudent(string input);
    SecurityStudent(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, 
                   int daysInCourse2, int daysInCourse3, Degrees degreeProgram);
                   
    //print methods
    void printStudentData();
    void printDaysInCourse();
    void printDegreeProgram();

    //accessor
    string GetDegreeProgram();
    
    //mutator
    void SetDegreeProgram(Degrees newDegree);
    
private:
    Degrees degree;
};


#endif