#include <string>
#include <iostream>
#include <sstream>
using namespace std;

#include "securityStudent.h"
#include "Student.h"
    
//Constructor with inputs
SecurityStudent::SecurityStudent(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, 
                   int daysInCourse2, int daysInCourse3, Degrees degreeProgram)
               :Student::Student(studentID, firstName, lastName, emailAddress, age, daysInCourse1, daysInCourse2, daysInCourse3){
                   
    degree = degreeProgram;
}

//Constructor with parsing
SecurityStudent::SecurityStudent(string input) : Student::Student(input){
    degree = SECURITY;
}

//Prints SecurityStudent data
void SecurityStudent::printStudentData(){
	cout << "Student ID: " << this->GetStudentID() << endl;
	cout << "First Name: " << this->GetFirstName() << endl;
	cout << "Last Name: " << this->GetLastName() << endl;
	cout << "Email: " << this->GetEmail() << endl;
	cout << "Age: " << this->GetAge() << endl;
	int* coursedays = this->GetDaysToCompleteCourses();
	cout << "Days to Complete Courses: " << coursedays[0] << " " <<
		coursedays[1] << " " << coursedays[2] << endl;
	cout << "Degree: " << this->GetDegreeProgram() << endl;
	return;
}

//Prints days in course
void SecurityStudent::printDaysInCourse(){
    cout << "Days to Complete Courses: " << daysToCompleteCourses[0] << " " <<
    daysToCompleteCourses[1]<< " "<< daysToCompleteCourses[2]<< endl;
}

//Prints degree
void SecurityStudent::printDegreeProgram(){
    cout << "SECURITY" << endl;
}

//Accessor
string SecurityStudent::GetDegreeProgram(){
	if (degree == NETWORKING) {
		return "NETWORKING";
	}
	else if (degree == SECURITY) {
		return "SECURITY";
	}
	else if (degree == SOFTWARE) {
		return "SOFTWARE";
	}
	else {
		return "UNDECIDED";
	}
}
    
//Mutator
void SecurityStudent::SetDegreeProgram(Degrees newDegree){
    degree = newDegree;
}