#include <iostream>
#include <vector>

using namespace std;

class Gradebook{
private:
    vector<int> labs;
    vector<int> assignments;
    vector<int> projects;
    unsigned int final_exam;
    int construct_used;

public:
    Gradebook(vector<int> labsInput, vector<int> assignmentsInput,  vector<int> projects, unsigned int final_exam_input);
    Gradebook(vector<int> labsInput, vector<int> assignmentsInput,  vector<int> projects);
    int lab_total();
    int assignment_total();
    int project_total();
    int course_total();
    void course(int number);
    void individual(string name,int number);
    void category(string name, string YN);
    string letter_grade();

};