#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include "degree.h"
using namespace std;

class Student {
    public:
        //Constructors
        Student(string input);
        Student(string newstudentID, string newfirstName, string newlastName, string newemailAddress, int newage, int newdaysInCourse1, 
                int newdaysInCourse2, int newdaysInCourse3);
        
        //Destructors
        ~Student();
        
        //daysToCompleteCourses size
        static const int COURSE_SIZE = 3;
        
        //virtual prints
		virtual void printStudentData() { return; };
		virtual void printDaysInCourse() { return; };
		virtual void printDegreeProgram() { return; };
       
        //Accessors
        string GetStudentID() const;
        string GetFirstName() const;
        string GetLastName() const;
        string GetEmail() const;
        int GetAge() const;
        int* GetDaysToCompleteCourses();
		virtual string GetDegreeProgram() { return "UNDECIDED"; };
       
        //Mutators
        void SetStudentId(string newID);
        void SetFirstName(string newFirstName);
        void SetLastName(string newLastName);
        void SetEmail(string newEmail);
        void SetAge(int newAge);
        void SetDaysToCompleteCourses(int* newDaysToCompleteCourses);

   
    protected:
        string studentID;
        string firstName;
        string lastName;
        string email;
        int age;
        int daysToCompleteCourses[COURSE_SIZE];
        Degrees degree;
};

#endif