#include <iostream> 
#include "gradebook.h"
#include <vector> 
using namespace std;

//constructor used if final exam is inputed
Gradebook::Gradebook(vector<int> labsInput, vector<int> assignmentsInput,  unsigned int review_projects_input, unsigned int final_project_input, unsigned int final_exam_input){
    this->labs = labsInput;
    this->assignments = assignmentsInput;
    this->review_project = review_projects_input;
    this->final_project = final_project_input;
    this->final_exam = final_exam_input;


}

//constructor used if final exam is not inputed
Gradebook::Gradebook(vector<int> labsInput, vector<int> assignmentsInput,  unsigned int review_projects_input, unsigned int final_project_input){
    this->labs = labsInput;
    this->assignments = assignmentsInput;
    this->review_project = review_projects_input;
    this->final_project = final_project_input;
    this->final_exam = 0;
 }

int Gradebook::lab_total(){
    int sum = 0;
    for(int i = 0; i < labs.size(); i++){
        sum += labs[i];
    }
    return sum;
}
int Gradebook::assignment_total(){
    int sum = 0;
    for(int i = 0; i < assignments.size(); i++){
        sum += assignments[i];
    }
    return sum;

}
//string has to be Lab or Assignment
//prints Lab/Assignment and its number plus the grade gotton from 
 void Gradebook::individual(string name,int number){
    if(name == "Lab"){
        cout << "Lab " << number << ": " << labs[number-1] << endl;

    }
    else if (name == "Assignment"){
        cout << "Assignment" << number << ": " << assignments[number-1] << endl;
    }
    else if (name == "Review Project"){
        cout << "Review Project: " << this->review_project << endl; 
    }
    else if(name == "Final Project"){
        cout << "Final Project: " << this->final_project << endl;
    }
    else if (name == "Final Exam"){
        cout << "Final Exam: " << this->final_exam << endl;
    }
 }
 
 void Gradebook::catagory(string name){
    if(name == "Lab"){
        for(int i = 0; i < labs.size(); i++){
        cout << "Lab " << (i +1) << ": " << labs[i] << endl;
    }
        cout<< "Lab Total:" << lab_total() << endl;
    }
    else if (name == "Assignment"){
        for(int i = 0; i < assignments.size(); i++){
        cout << "Assignment " << (i +1) << ": " << assignments[i] << endl;
    }
        cout<< "Assignment: " << assignment_total() << endl;
    }
    else if (name == "Review Project"){
        cout << "Review Project: " << this->review_project << endl; 
    }
    else if(name == "Final Project"){
        cout << "Final Project: " << this->final_project << endl;
    }
    else if (name == "Final Exam"){
        cout << "Final Exam: " << this->final_exam << endl;
    }

 }


 
