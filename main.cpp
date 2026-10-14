#include <iostream>
#include <fstream>
#include <vector>
#include "student.h"

using namespace std;

int main(){
    vector<Art_student*> art_students;
    vector<Physics_student*> physics_students;

    //create 5 art and physics students
    for(int i = 0; i < 5; i++){
	art_students.push_back(new Art_student);
	physics_students.push_back(new Physics_student);
    }

    art_students[0]->setName("John", "Smith");
    art_students[0]->setGPA(3.5);
    art_students[0]->setGradYear(2028);
    art_students[0]->setGradSem("Fall");
    art_students[0]->setEnrollYear(2023);
    art_students[0]->setEnrollSem("Fall");
    art_students[0]->setStudentLevel("Undergraduate");
    art_students[0]->setArtEmphasis("Art History");

    art_students[1]->setName("Bobby", "Adams");
    art_students[1]->setGPA(2.6);
    art_students[1]->setGradYear(2029);
    art_students[1]->setGradSem("Spring");
    art_students[1]->setEnrollYear(2025);
    art_students[1]->setEnrollSem("Fall");
    art_students[1]->setStudentLevel("Undergraduate");
    art_students[1]->setArtEmphasis("Art Studio");

    art_students[2]->setName("Edward", "Jenkins");
    art_students[2]->setGPA(4.1);
    art_students[2]->setGradYear(2027);
    art_students[2]->setGradSem("Spring");
    art_students[2]->setEnrollYear(2023);
    art_students[2]->setEnrollSem("Fall");
    art_students[2]->setStudentLevel("Undergraduate");
    art_students[2]->setArtEmphasis("Art Education");

    art_students[3]->setName("Suzie", "Brown");
    art_students[3]->setGPA(3.1);
    art_students[3]->setGradYear(2030);
    art_students[3]->setGradSem("Spring");
    art_students[3]->setEnrollYear(2026);
    art_students[3]->setEnrollSem("Fall");
    art_students[3]->setStudentLevel("Undergraduate");
    art_students[3]->setArtEmphasis("Art Studio");

    art_students[4]->setName("John", "Smith");
    art_students[4]->setGPA(2.9);
    art_students[4]->setGradYear(2028);
    art_students[4]->setGradSem("Fall");
    art_students[4]->setEnrollYear(2026);
    art_students[4]->setEnrollSem("Spring");
    art_students[4]->setStudentLevel("Graduate");
    art_students[4]->setArtEmphasis("Art History");

    physics_students[0]->setName("James", "Smith");
    physics_students[0]->setGPA(4.0);
    physics_students[0]->setGradYear(2030);
    physics_students[0]->setGradSem("Spring");
    physics_students[0]->setEnrollYear(2028);
    physics_students[0]->setEnrollSem("Fall");
    physics_students[0]->setStudentLevel("Graduate");
    physics_students[0]->setConcentration("Biophysics");

    physics_students[1]->setName("Carol", "Jones");
    physics_students[1]->setGPA(3.3);
    physics_students[1]->setGradYear(2026);
    physics_students[1]->setGradSem("Spring");
    physics_students[1]->setEnrollYear(2022);
    physics_students[1]->setEnrollSem("Fall");
    physics_students[1]->setStudentLevel("Undergraduate");
    physics_students[1]->setConcentration("Earth and Planetary Sciences");

    physics_students[2]->setName("Lauren", "Davis");
    physics_students[2]->setGPA(3.0);
    physics_students[2]->setGradYear(2030);
    physics_students[2]->setGradSem("Spring");
    physics_students[2]->setEnrollYear(2026);
    physics_students[2]->setEnrollSem("Fall");
    physics_students[2]->setStudentLevel("Undergraduate");
    physics_students[2]->setConcentration("Biophysics");

    physics_students[3]->setName("Andrew", "Anderson");
    physics_students[3]->setGPA(2.5);
    physics_students[3]->setGradYear(2029);
    physics_students[3]->setGradSem("Spring");
    physics_students[3]->setEnrollYear(2024);
    physics_students[3]->setEnrollSem("Fall");
    physics_students[3]->setStudentLevel("Undergraduate");
    physics_students[3]->setConcentration("Earth and Planetary Sciences");

    physics_students[4]->setName("David", "Wilson");
    physics_students[4]->setGPA(2.9);
    physics_students[4]->setGradYear(2026);
    physics_students[4]->setGradSem("Spring");
    physics_students[4]->setEnrollYear(2022);
    physics_students[4]->setEnrollSem("Fall");
    physics_students[4]->setStudentLevel("Undergraduate");
    physics_students[4]->setConcentration("Earth and Planetary Sciences");

    //write to file
    ofstream outfile("student_info.dat");

    if(!outfile.is_open()){
	cerr << "Error opening student_info.dat\n";

	//free allocated memory
	for(int i = 0 ;i < 5; i++ ){
	    delete art_students[i];
	    delete physics_students[i];
	}

	return 1;
    }

    //write art students to file
    outfile << "ART STUDENTS:\n";

    for(int i = 0; i < art_students.size(); i++){
	art_students[i]->writeToFile(outfile);
    }

    //write physics students to same file
    outfile << "PHYSICS STUDENTS:\n";

    for(int i = 0; i < physics_students.size(); i++){
	physics_students[i]->writeToFile(outfile);
    }

    //close file
    outfile.close();

    //print out that the file output was successful
    cout << "Students written to file student_info.dat\n" << endl;

    //free memory
    for(int i = 0; i < 5; i++){
	delete art_students[i];
        delete physics_students[i];
    }

    return 0;
}
