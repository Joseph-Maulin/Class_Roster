#include <string>
#include <iostream>
#include <sstream>
using namespace std;

#include "Student.h"

//Constructor with parsing
Student::Student(string input){
    cout << "Constructing Student..." << endl;
    
    string sub;
    int i = 0;
   
    //Student ID
    sub = input.substr(i, input.substr(i,input.length()).find(","));
    studentID = sub;
   
    i += sub.length()+1;
   
    //First Name
    sub = input.substr(i, input.substr(i,input.length()).find(","));
    firstName = sub;
   
    i += sub.length()+1;
   
    //Last Name
    sub = input.substr(i, input.substr(i,input.length()).find(","));
    lastName = sub;
   
    i += sub.length()+1;
   
    //Email
    sub = input.substr(i, input.substr(i,input.length()).find(","));
    email = sub;
   
    i += sub.length()+1;
   
    //Age
    sub = input.substr(i, input.substr(i,input.length()).find(","));
    int rage = stoi(sub);
    age = rage;
    
    i += sub.length()+1;
   
    //daysToCompleteCourse
    for(int j = 0; j<3; ++j){
        sub = input.substr(i, input.substr(i,input.length()).find(","));
        int rday = stoi(sub);
        daysToCompleteCourses[j] = rday;
       
        i += sub.length()+1;
    }
}

//Constructor with inputs
Student::Student(string newstudentID, string newfirstName, string newlastName, string newemailAddress, int newage, int newdaysInCourse1, 
                int newdaysInCourse2, int newdaysInCourse3){
    cout << "Constructing Student..." << endl << endl;
  
    studentID = newstudentID;
    firstName = newfirstName;
    lastName = newlastName;
    email = newemailAddress;
    age = newage;
    
    daysToCompleteCourses[0] = newdaysInCourse1;
    daysToCompleteCourses[1] = newdaysInCourse2;
    daysToCompleteCourses[2] = newdaysInCourse3;
}

//Destructor
Student::~Student(){
    cout << "Destroying ID: " << studentID << endl;
}


//Accessors
string Student::GetStudentID() const {
    return studentID;
}

string Student::GetFirstName() const{
    return firstName;
}

string Student::GetLastName() const{
    return lastName;
}

string Student::GetEmail() const{
    return email;
}

int Student::GetAge() const{
    return age;
}

int* Student::GetDaysToCompleteCourses(){
    return daysToCompleteCourses;
}

//Mutators

void Student::SetStudentId(string newID){
    studentID = newID;
}

void Student::SetFirstName(string newFirstName){
    firstName = newFirstName;
}

void Student::SetLastName(string newLastName){
    lastName = newLastName;
}

void Student::SetEmail(string newEmail){
    email = newEmail;
}

void Student::SetAge(int newAge){
    age = newAge;
}

void Student::SetDaysToCompleteCourses(int* newDaysToCompleteCourses){
    daysToCompleteCourses[0] = newDaysToCompleteCourses[0];
    daysToCompleteCourses[1] = newDaysToCompleteCourses[1];
    daysToCompleteCourses[2] = newDaysToCompleteCourses[2];
}

