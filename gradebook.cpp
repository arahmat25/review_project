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

int Gradebook::course_total(){
    int cTotal = 0;

    cTotal = lab_total() + assignment_total() + this-> review_project + this-> final_project + this-> final_exam;
    
    return cTotal;
};
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
 
 void Gradebook::category(string name,string YN){
    //print all lab grades if YN equals No, only lab total when YN equals YES
    if(name == "Lab"){
        if(YN == "No"){
        for(int i = 0; i < labs.size(); i++){
        cout << "Lab " << (i +1) << ": " << labs[i] << endl;
    }
        }
        if(YN == "Yes"){
        cout<< "Lab Total:" << lab_total() << endl;
        }
    }
    else if (name == "Assignment"){
        //print all lab grades if YN equals No, only lab total when YN equals YES
        if(YN == "No"){
        for(int i = 0; i < assignments.size(); i++){
        cout << "Assignment " << (i +1) << ": " << assignments[i] << endl;
    }
        }
        if(YN == "Yes"){
        cout<< "Assignment: " << assignment_total() << endl;
        }
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

 void Gradebook::course(int number){
    //all grades within their respective categories and a course overall
    if(number == 1){
       category("Lab", "No");
       category("Assignment", "No");
       category("Review Project", "No");
       category("Final Project", "No");
       category("Final Exam", "No");
        //Course Overall
       course_total();
    }
    //only category totals and course overall
    else if(number == 2){
       category("Lab", "Yes");
       category("Assignment", "Yes");
       category("Review Project", "Yes");
       category("Final Project", "Yes");
       category("Final Exam", "Yes");
       course_total();
    }
    //only the course overall
    else if(number == 3){
       course_total();
    }

 }

 
