#include <iostream>
#include <vector> 

using namespace std;

class Gradebook{
    private:
    vector<int> labs;
    vector<int> assignments;
    unsigned int review_project;
    unsigned int final_project;
    unsigned int final_exam;
    
    public:
    Gradebook(vector<int> labsInput, vector<int> assignmentsInput,  unsigned int review_projects_input, unsigned int final_project_input, unsigned int final_exam_input);
    Gradebook(vector<int> labsInput, vector<int> assignmentsInput,  unsigned int review_projects_input, unsigned int final_project_input);
    int lab_total();
    int assignment_total();
    int course_total();
    void individual(string name,int number);
    void catagory(string name);
    void course(int number);
    
};
