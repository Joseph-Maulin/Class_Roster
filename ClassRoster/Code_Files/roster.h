#ifndef ROSTER_H
#define ROSTER_H

#include <string>
using namespace std;

//parsed student data to create roster in roster.cpp
const string studentData[] =
     {"A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
     "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORKING",
     "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
     "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY"};

class Roster{
    public:
        //Constructor
        Roster();
        
        //Destructor
        ~Roster();
        
        //class roster methods
        void add(string studentID, string firstName, string lastName,
                string emailAddress, int age, int daysInCourse1, int daysInCourse2,
                int daysInCourse3, Degrees degreeProgram);
        void remove(string studentID);
        Degrees GetDegreeProgram(string input);
        void PopulateRoster();
        
        //class print methods
        void printAll();
        void printDaysInCourse(string studentID);
        void printAverageDaysInCourse(string studentID);
        void printInvalidEmails();
        void printByDegreeProgram(Degrees degree);
   
		int GetRosterUsed();
		void SetRosterUsed(int newRosterUsed);

		Student** GetClassRoster();
    
    private:
        int RosterUsed = 4;
        Student* classRosterArray[10];
		Student** classPtr = classRosterArray;
};
    
int main();


#endif