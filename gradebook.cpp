#include <iostream>
#include "gradebook.h"
#include <vector>
using namespace std;

// Constructor used to generate if there is final exam input
Gradebook::Gradebook(vector<int> labsInput, vector<int> assignmentsInput,  vector<int> projectsInput, unsigned int final_exam_input){
    this->labs = labsInput;
    this->assignments = assignmentsInput;
    this->projects = projectsInput;
    this->final_exam = final_exam_input;
    this->construct_used = 1;
}

// Constructor used to generate if there is no final exam input
Gradebook::Gradebook(vector<int> labsInput, vector<int> assignmentsInput, vector<int> projectsInput){
    this->labs = labsInput;
    this->assignments = assignmentsInput;
    this->projects = projectsInput;
    this->final_exam = 0;
    this->construct_used = 2;
}

// Returns total of all lab grades
int Gradebook::lab_total(){
    int sum = 0;
    for(int i = 0; i < labs.size(); i++){
        sum += labs[i];
    }
    return sum;
}

// Returns total of all assignment grades
int Gradebook::assignment_total(){
    int sum = 0;
    for(int i = 0; i < assignments.size(); i++){
        sum += assignments[i];
    }
    return sum;

}

// Returns total of both project grades
int Gradebook::project_total(){
    int sum = 0;
    for(int i = 0; i < this->projects.size(); i++){
        sum += projects[i];
    }
    return sum;
}

// Returns an individual grade from any of the categories
void Gradebook::individual(string name,int number){
    // Returns an individual lab grade
    if(name == "Lab"){
        cout << "Lab " << number << ": " << labs[number-1] << endl;
    }
    // Returns an individual assignment grade
    else if (name == "Assignment"){
        cout << "Assignment" << number << ": " << assignments[number-1] << endl;
    }
    // Returns an individual project grade
    else if (name == "Projects"){
        cout << "Project" << number << ": " << projects[number-1] << endl;
    }
    // Returns an final exam grade
    else if (name == "Final Exam"){
        cout << "Final Exam: " << this->final_exam << endl;
    }
}

// Returns a category's individual grades and has the option of returning the category total
void Gradebook::category(string name,string YN){
    //print all lab grades if YN equals No, only lab total when YN equals YES
    if(name == "Lab"){
        for(int i = 0; i < labs.size(); i++){
            cout << "Lab " << (i +1) << ": " << labs[i] << endl;
        }
        if(YN == "Yes"){
            cout<< "Lab Total: " << lab_total() << endl;
        }
    }

    else if (name == "Assignment"){
        //print all lab grades if YN equals No, only lab total when YN equals YES
        for(int i = 0; i < assignments.size(); i++){
            cout << "Assignment " << (i +1) << ": " << assignments[i] << endl;
        }
        if(YN == "Yes"){
            cout<< "Assignment: " << assignment_total() << endl;
        }
    }

    else if (name == "Projects"){
        for(int i = 0; i < projects.size(); i++){
            cout << "Project " << (i +1) << ": " << projects[i] << endl;
        }
        if(YN == "Yes"){
            cout<< "Projects: " << project_total() << endl;
        }
    }

    else if (name == "Final Exam"){
        cout << "Final Exam: " << this->final_exam << endl;
    }

}

// Returns total grade for entire course - adds all totals together and final
int Gradebook::course_total(){
    int cTotal = 0;
    cTotal = lab_total() + assignment_total() + project_total();
    if (construct_used == 1) {
        cTotal += this->final_exam;
    }

    return cTotal;
};

// Returns three different outputs, the user chooses based on an integer selection of 1, 2, or 3.
void Gradebook::course(int number){
    // Returns every grade in each category and course total - does NOT return category totals
    if(number == 1){
        category("Lab", "No");
        category("Assignment", "No");
        category("Projects", "No");
        if (construct_used == 1){
            category("Final Exam", "No");
        }
        //Course Overall
        cout << "Course Total: " << course_total() << endl;
    }
        // Returns only category and course totals
    else if(number == 2){
        cout << "Assignment Total: " << assignment_total() << endl;
        cout << "Lab Total: " << lab_total() << endl;
        cout << "Project Total: " <<project_total() << endl;
        cout << "Course Total: " << course_total() << endl;
    }
        // Returns only course total
    else if(number == 3){
        cout << "Course Total: " << course_total() << endl;
    }

}

char Gradebook::letter_grade(int cTotal) {

    // Initiate integer holder for final grade
    int final_grade = course_total() / 10;

    // Calculate final grade if student had to take final
    if (construct_used == 1){
        final_grade = course_total() / 10;
    }

    // Calculate final grade if student did not have to take final
    if (construct_used == 2){

    }
}