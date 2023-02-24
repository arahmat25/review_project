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