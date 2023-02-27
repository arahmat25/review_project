#include <iostream>
#include <vector>

using namespace std;

class Gradebook{
private:
    // Initiate all constructor variables needed and constructor identifier
    vector<int> labs;
    vector<int> assignments;
    vector<int> projects;
    unsigned int final_exam;
    int construct_used;
    string file_name;

public:
    // Initiate all functions needed
    Gradebook(vector<int> labsInput, vector<int> assignmentsInput,  vector<int> projects, unsigned int final_exam_input, string fname);
    Gradebook(vector<int> labsInput, vector<int> assignmentsInput,  vector<int> projects,string fname);
    int lab_total();
    int assignment_total();
    int project_total();
    int course_total();
    void course(int number);
    void individual(string name,int number);
    void category(string name, string YN);
    string letter_grade();
    void write_file();
    void changeData(string name);

};