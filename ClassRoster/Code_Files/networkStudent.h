#ifndef networkStudent_H
#define networkStudent_H

#include <string>
#include "Student.h"
#include "degree.h"
using namespace std;

class NetworkStudent: public Student{
    
public:
    //Constructors
    NetworkStudent(string input);
    NetworkStudent(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, 
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
    Degrees degree = NETWORKING;
};


#endif