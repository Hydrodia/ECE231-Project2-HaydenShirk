#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class Student{
    protected:
	string firstName;
	string lastName;
	double gpa;
	int graduationYear;
	string graduationSemester;
	int enrolledYear;
	string enrolledSemester;
	string studentLevel;

    public:
	//default constuctor
	Student(){
	    firstName = "Unknown";
	    lastName = "Unknown";
	    gpa = 0.0;
	    graduationYear = 0;
	    graduationSemester = "Unkown";
	    enrolledYear = 0;
	    enrolledSemester = "Unknown";
	    studentLevel = "undergraduate";
	}
    
    virtual ~Student() = default;

    //setters
    void setName(string first, string last){
	firstName = first;
	lastName = last;
    }

    void setGPA(double value){
	gpa = value;
    }

    void setGradYear(int year){
	graduationYear = year;
    }

    void setGradSem(string gradSem){
	graduationSemester = gradSem;
    }

    void setEnrollYear(int year){
	enrolledYear = year;
    }

    void setEnrollSem(string enrollSem){
	enrolledSemester = enrollSem;
    }

    void setStudentLevel(string level){
	if(level == "Undergraduate" || level == "Graduate"){
	    studentLevel = level;
	}
    }

    //getters
    string getFirstName() const{
	return firstName;
    }

    string getLastName() const{
	return lastName;
    }

    double getGPA() const{
	return gpa;
    }

    int getGradYear() const{
	return graduationYear;
    }

    string getGradSem() const{
	return graduationSemester;
    }

    int getEnrollYear() const{
	return enrolledYear;
    }

    string getEnrollSem() const{
	return enrolledSemester;
    }

    string getStudentLevel() const{
	return studentLevel;
    }

    //write out common student info
    virtual void writeToFile(ostream& out) const{
	out << "Name: " << firstName << " " << lastName << "\n";
	out << "GPA: " << gpa << "\n";
	out << "Degree Level: " << studentLevel << "\n";
	out << "Enrolled: " << enrolledSemester << " " << enrolledYear << "\n";
	out << "Graduation: " << graduationSemester << " " << graduationYear << "\n";

    }
};

//derived class for art students
class Art_student : public Student{
    private:
	string artEmphasis = "Art Studio";

    public:
	Art_student() : Student(){
	    artEmphasis = "Art Studio";
	}

	~Art_student() override = default;

	void setArtEmphasis(string emphasis){
	    if(emphasis == "Art Studio" || emphasis == "Art History" || emphasis == "Art Education"){
		artEmphasis = emphasis;
	    }
	}

	string getArtEmphasis() const{
	   return artEmphasis;
	}

	void writeToFile(ostream& out){
	    out << "Program: Art\n";

	    Student::writeToFile(out);

	    out << "Art Emphasis: " << artEmphasis << "\n";
	}
};

//derived class for physics students
class Physics_student : public Student{
    private:
        string concentration = "Biophysics";

    public:
        Physics_student() : Student(){
            concentration = "Biophysics";
        }

        ~Physics_student() override = default;

        void setConcentration(string value){
            if(concentration == "Biophysics" || concentration == "Earth and Planetary Sciences"){
                concentration = value;
            }
        }

        string getConcentration() const{
           return concentration;
        }

        void writeToFile(ostream& out){
            out << "Program: Physics\n";

	    Student::writeToFile(out);

            out << "Concentration: " << concentration << "\n";
        }
};

#endif
