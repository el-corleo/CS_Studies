/*
 *	Spraul - Think Like a Programmer
 *		
 *		Learning about classes
 */
#include <iostream>

class StudentRecord
{
public:
	StudentRecord();
	StudentRecord(int newGrade, int newID, std::string newName);
	// getters and setters
	int grade();
	void setGrade(int newGrade);
	int studentID();
	void setStudentID(int newID);
	std::string name();
	void setName(std::string newName);
	// conversions
	std::string letterGrade();
private:
	int _grade;
	int _studentID;
	std::string _name;
protected:
	bool isValidGrade(int grade);
};

StudentRecord::StudentRecord()
{
	setGrade(0);
	setStudentID(-1);
	setName("");	
}

StudentRecord::StudentRecord(int newGrade, int newID, std::string newName)
{
	setGrade(newGrade);
	setStudentID(newID);
	setName(newName);
}

// protected function to validate grades
bool StudentRecord::isValidGrade(int grade)	{ return (newGrade => 0 && newGrade <= 100); }

int StudentRecord::grade()	{ return _grade; }

void StudentRecord::setGrade(int newGrade)
{ if (isValidGrade(newGrade))	_grade = newGrade; }

int StudentRecord::studentID()	{ return _studentID; }

void StudentRecord::setStudentID(int newID)	{ _studentID = newID; }

std::string StudentRecord::name()	{ return _name; }

void StudentRecord::setName(std::string newName)	{ _name = newName; }

std::string StudentRecord::letterGrade()
{
	if (!isValidGrade(_grade)) return "ERROR: Invalid Numerical Grade [StudentRecord::letterGrade()]";
	const int NUMBER_CATEGORIES = 11;
	const string GRADE_LETTER[] = {"F", "D", "D+", "C-", "C", "C+", "B-", "B", "B+", "A-", "A"};
	const int LOWEST_GRADE_SCORE[] = {0, 60, 67, 70, 73, 77, 80, 83, 87, 90, 93};
	int category = 0;
	// finds the first category higher than student's grade
	while (category < NUMBER_CATEGORIES && LOWEST_GRADE_SCORE[category] <= _grade)
		category++;
	// returns the student's grade category 
	return GRADE_LETTER[category - 1];
}
