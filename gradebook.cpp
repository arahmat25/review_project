#include <iostream>
#include "gradebook.h"
#include <vector>
#include <fstream>
#include <sstream>
#include "algorithm"
using namespace std;

// Constructor used to generate if there is final exam input
Gradebook::Gradebook(vector<int> labsInput, vector<int> assignmentsInput,  vector<int> projectsInput, unsigned int final_exam_input,string fname){
    this->labs = labsInput;
    this->assignments = assignmentsInput;
    this->projects = projectsInput;
    this->final_exam = final_exam_input;
    // Constructor Identity Number
    this->construct_used = 1;
    this->file_name = fname;
}

// Constructor used to generate if there is no final exam input
Gradebook::Gradebook(vector<int> labsInput, vector<int> assignmentsInput, vector<int> projectsInput,string fname){
    this->labs = labsInput;
    this->assignments = assignmentsInput;
    this->projects = projectsInput;
    this->final_exam = 0;
    // Constructor Identity Number
    this->construct_used = 2;
    this->file_name = fname;
}

// Returns total of all lab grades
int Gradebook::lab_total(){
    int sum = 0;
    vector<int> copy =  labs;
    sort(copy.begin(), copy.end());
    for(int i = 0; i < labs.size(); i++){
        sum += labs[i];
    }

    sum = sum - copy[0] - copy[1];
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

    // Output all lab grades if YN equals 'No', Output category total if YN equals 'Yes'
    if(name == "Lab"){
        for(int i = 0; i < labs.size(); i++){
            cout << "Lab " << (i +1) << ": " << labs[i] << endl;
        }
        if(YN == "Yes"){
            cout<< "Lab Total: " << lab_total() << endl;
        }
    }

    // Output all assignment grades if YN equals 'No', Output category total if YN equals 'Yes'
    else if (name == "Assignment"){
        for(int i = 0; i < assignments.size(); i++){
            cout << "Assignment " << (i +1) << ": " << assignments[i] << endl;
        }
        if(YN == "Yes"){
            cout<< "Assignment: " << assignment_total() << endl;
        }
    }

    // Output all project grades if YN equals 'No', Output category total if YN equals 'Yes'
    else if (name == "Projects"){
        for(int i = 0; i < projects.size(); i++){
            cout << "Project " << (i +1) << ": " << projects[i] << endl;
        }
        if(YN == "Yes"){
            cout<< "Projects: " << project_total() << endl;
        }
    }

    // Output all final exam grade, ignore YN as there is only one exam grade
    else if (name == "Final Exam"){
        cout << "Final Exam: " << this->final_exam << endl;
    }

}

// Returns total grade for entire course - adds all totals together and final
int Gradebook::course_total(){

    // Initialize holder for total points and add up all category totals, excluding final
    int total_points = 0;
    total_points = lab_total() + assignment_total() + project_total();

    // If the first constructor is used, include final exam grade in the total points, otherwise ignore
    if (construct_used == 1) {
        total_points += this->final_exam;
    }

    return total_points;
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
        if (construct_used == 1){
            cout << "Exam Total: " << final_exam << endl;
        }
    }

    // Returns only course total
    else if(number == 3){
        cout << "Course Total: " << course_total() << endl;
    }

}

// Returns the corresponding letter grade of the course total depending on constructor used
string Gradebook::letter_grade() {

    // Initiate string holder for letter grade
    string letter_grade;
    // Calculate total points using course_total function
    double cTotal = course_total();
    // Initiate double holder for final grade
    double final_grade;

    // Calculate final grade if student had to take final
    if (construct_used == 1){
        final_grade = cTotal / 10;
    }

    // Calculate final grade if student did not have to take final
    if (construct_used == 2){
        final_grade = cTotal / 9;
    }

    // Calculate letter grade using final grade
    if (final_grade > 94){
        letter_grade = "A";
    }
    else if (final_grade >= 90){
        letter_grade = "A-";
    }
    else if (final_grade >= 87){
        letter_grade = "B+";
    }
    else if (final_grade >= 83){
        letter_grade = "B";
    }
    else if (final_grade >= 80){
        letter_grade = "B-";
    }
    else if (final_grade >= 77){
        letter_grade = "C+";
    }
    else if (final_grade >= 73){
        letter_grade = "C";
    }
    else if (final_grade >= 70){
        letter_grade = "C-";
    }
    else if (final_grade >= 67){
        letter_grade = "D+";
    }
    else if (final_grade >= 63){
        letter_grade = "D";
    }
    else if (final_grade >= 60){
        letter_grade = "D-";
    }
    else{
        letter_grade = "F";
    }

    return letter_grade;
}

// Writes all the grades to the original file
void Gradebook::write_file(){

    ofstream output_file(file_name);

    // Check if the file is open, if it is continue
    if (output_file.is_open()){
        // Write labs
        for(int i=0; i<labs.size(); i++){
            output_file<< labs[i]<<" ";
        }
        output_file << "\n";
        // Write assignments
        for(int i=0; i<assignments.size(); i++){
            output_file<< assignments[i]<<" ";
        }
        output_file << "\n";
        // Write projects
        for(int i=0; i<projects.size(); i++){
            output_file<< projects[i]<<" ";
        }
        output_file << "\n";

        // Write final if first constructor is used
        if(construct_used == 1){
            output_file << final_exam << "";
            output_file << "\n";
        }

        // Close the file
        output_file.close();

    }
}

void Gradebook::changeData(string name){

    // If the user picks assignment, prompt a number and grade to change
    if(name == "Assignment"){
        int num;
        int gradeChange;
        cout<<"Enter assignment number: "<<endl;
        cin>> num;
        cout<<"Enter new grade: "<<endl;
        cin>> gradeChange;
        assignments[num - 1] = gradeChange;
    }

    // If the user picks lab, prompt a number and grade to change
    if(name == "Lab"){
        int num2;
        int gradeChange2;
        cout<<"Enter lab number: "<<endl;
        cin>> num2;
        cout<<"Enter new grade: "<<endl;
        cin>> gradeChange2;
        labs[num2 - 1] = gradeChange2;
    }

    // If the user picks project, prompt a number and grade to change
    if(name == "Projects"){
        int num3;
        int gradeChange3;
        cout<<"Enter project number: "<<endl;
        cin>> num3;
        cout<<"Enter new grade: "<<endl;
        cin>> gradeChange3;
        projects[num3 - 1] = gradeChange3;
    }
    // If the user picks final, prompt a number and grade to change
    if(name == "Final Exam"){
        int gradeChange4;
        cout<<"Enter new grade: "<<endl;
        cin>> gradeChange4;
        final_exam = gradeChange4;
    }

    // Call the write file function and output change
    write_file();
}

