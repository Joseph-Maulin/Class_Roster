#include <iostream>
#include <string>
#include "degree.h"
#include "Student.h"
#include "networkStudent.h"
#include "securityStudent.h"
#include "softwareStudent.h"
using namespace std;

#include "roster.h"

//Constructor
Roster::Roster(){
    cout << "Constructing Roster..." << endl;
    PopulateRoster();
    cout << endl << endl;
}
   
//Destructor 
Roster::~Roster(){
    
    cout << "Destroying Roster..." << endl;
     for(int i=0; i<this->GetRosterUsed(); ++i){
         if(this->GetClassRoster()[i]){
            delete this->GetClassRoster()[i];
         }
    }
    cout << endl << endl;
}

int Roster::GetRosterUsed() {
	return RosterUsed;
}

void Roster::SetRosterUsed(int newRosterUsed) {
	RosterUsed = newRosterUsed;
}

Student** Roster::GetClassRoster(){
	return classPtr;
}

//Adds studentData to roster
void Roster::PopulateRoster(){
    cout << "Populating class roster..." << endl << endl;
	
     for(int i=0; i<this->GetRosterUsed(); ++i){
        Degrees deg = GetDegreeProgram(studentData[i]);
        if(deg == NETWORKING){
			this->GetClassRoster()[i] = new NetworkStudent(studentData[i]);
        }
        
        if(deg == SECURITY){
			this->GetClassRoster()[i] = new SecurityStudent(studentData[i]);
        }
        
        if(deg == SOFTWARE){
			this->GetClassRoster()[i] = new SoftwareStudent(studentData[i]);
        }
        
    }
}

//Convert string to enum Degree type
Degrees Roster::GetDegreeProgram(string input){
    int l = input.length()-1;
    string deg = "";
    string letter = "";
    
    
    while(letter != ","){
        letter = input[l];
        if (letter == ","){
            break;
        }
        deg = letter + deg;
        l--;
    }
    
    if(deg == "NETWORKING"){
        return NETWORKING;
    }
    
    else if(deg == "SECURITY"){
        return SECURITY;
    }
    
    if(deg == "SOFTWARE"){
        return SOFTWARE;
    }
}

//Add student to roster
void Roster::add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2,
                int daysInCourse3, Degrees degreeProgram){
    cout << "Adding student..." << endl;
	int rosterPos = this->GetRosterUsed();
    if(degreeProgram == NETWORKING){
		this->GetClassRoster()[rosterPos] = new NetworkStudent(studentID, firstName, lastName, emailAddress, age, daysInCourse1, daysInCourse2,
                                                 daysInCourse3, degreeProgram);
    }
        
    if(degreeProgram == SECURITY){
		this->GetClassRoster()[rosterPos] = new SecurityStudent(studentID, firstName, lastName, emailAddress, age, daysInCourse1, daysInCourse2,
                                                 daysInCourse3, degreeProgram);
    }
        
    if(degreeProgram == SOFTWARE){
		this->GetClassRoster()[rosterPos] = new SoftwareStudent(studentID, firstName, lastName, emailAddress, age, daysInCourse1, daysInCourse2,
                                                 daysInCourse3, degreeProgram);
    }
    
    this->SetRosterUsed(rosterPos+1);
}

//Remove student from roster
void Roster::remove(string studentID){
    cout << "Searching for " << studentID << "..."<< endl;
    bool found = false;
    for(int i=0; i<this->GetRosterUsed(); ++i){
        if(found == true){
			this->GetClassRoster()[i-1] = this->GetClassRoster()[i];
        }
        
        else if(this->GetClassRoster()[i]->GetStudentID() == studentID){
            delete this->GetClassRoster()[i];
            found = true;
        }
        
    }
    if(found == true){
        RosterUsed --;
        cout << endl;
    }
    else{
        cout << "Student with this ID was not found..." << endl <<endl;   
    }
}

//Prints all student data for roster
void Roster::printAll(){
    cout << "Printing student data..." << endl <<endl;
    for(int i=0; i<this->GetRosterUsed(); ++i){
        if(this->GetClassRoster()[i] != nullptr){
			this->GetClassRoster()[i]->printStudentData();
            cout << endl;
        }
    }

    cout << endl;
}

//Prints all days in courses for studentID
void Roster::printDaysInCourse(string studentID){
    cout << "Printing days in course for " << studentID << "..." << endl;
    for(int i=0; i< this->GetRosterUsed(); ++i){
        if(this->GetClassRoster()[i]->GetStudentID() == studentID){
			this->GetClassRoster()[i]->printDaysInCourse();
            cout << endl;
            return;
        }
     }
     cout << "Student with this ID was not found..." << endl << endl;
}

//Prints average days in courses for studentID
void Roster::printAverageDaysInCourse(string studentID){
    cout << "Printing average days in course for " << studentID << "..." << endl;
    for(int i=0; i<this->GetRosterUsed(); ++i){
        if(this->GetClassRoster()[i]->GetStudentID() == studentID){
            
            int *days = this->GetClassRoster()[i]->GetDaysToCompleteCourses();
         
            //double avgDays = ((days[0]-'0') + (days[1]-'0') + (days[2]-'0')) / 3.0;
            cout << "Average days to complete courses: " << days <<endl << endl;
            return;
        }
     }
     cout << "Student with this ID was not found..." << endl << endl;
}

//Prints invalid emails in roster
void Roster::printInvalidEmails(){
    cout << "Printing invalid emails..." << endl << endl;
    for(int i=0; i<this->GetRosterUsed(); ++i){
        string email = this->GetClassRoster()[i]->GetEmail();
        if(!(email.find("@") != string::npos)){
            cout << "No '@' found" <<endl;
            cout << "Invalid Email for StudentID " << this->GetClassRoster()[i]->GetStudentID() << ": ";
            cout << email << endl << endl;
        }  
        
        else if(!(email.find(".") != string::npos)){
            cout << "No '.' found" << endl;
            cout << "Invalid Email for StudentID " << this->GetClassRoster()[i]->GetStudentID() << ": ";
            cout << email << endl << endl;
        }
        
        else if(email.find(" ")<string::npos){
            cout << "Space ' ' found" << endl;
            cout << "Invalid Email for StudentID " << this->GetClassRoster()[i]->GetStudentID() << ": ";
            cout << email << endl << endl;
        }
    }
}

//Prints all students in roster with degree
void Roster::printByDegreeProgram(Degrees degree){
	string degString;
    if(degree==NETWORKING){
        cout << "Printing degree program NETWORKING..." << endl << endl;
		degString = "NETWORKING";
    }
    else if(degree==SECURITY){
        cout << "Printing degree program SECURITY..." << endl << endl;
		degString = "SECURITY";
    }
    else if(degree==SOFTWARE){
        cout << "Printing degree program SOFTWARE..." << endl << endl;
		degString = "SOFTWARE";
    }
    
    bool found = false;
    for(int i=0; i<this->GetRosterUsed(); ++i){
        if(this->GetClassRoster()[i]->GetDegreeProgram() == degString){
			this->GetClassRoster()[i]->printStudentData();
            cout << endl;
            found = true;
        }
     }
     
     if(found==false){
         cout <<"No student with degree program found...";
     }
}

//main
int main(){
    cout << "Course Title : Scripting and Programming - Applications – C867" <<endl;
    cout << "Programming Language: C++" << endl;
    cout << "StudentID: 001118042" << endl;
    cout << "Name: Joseph Maulin" << endl << endl;
    
    //creating instance of Roster
    //adds students from global studentData (roster.h)
    Roster* classRoster = new Roster();
    
    //main function calls
    classRoster->printAll();
    classRoster->printInvalidEmails();
    classRoster->printAverageDaysInCourse("A1");
    classRoster->printByDegreeProgram(SOFTWARE);
    
    //remove tests
    classRoster->remove("A3");
    classRoster->remove("A3");
    
    //delete roster and call Destructors
    delete classRoster;

    return 0;
}