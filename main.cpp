#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include "gradebook.h"

using namespace std;

int read_file(const string& file_name, vector<int> &labs, vector<int> &assignments, vector<int> &projects ,unsigned int &final_exam){

    fstream newfile;

    // Initiate line counter
    int line_count = 0;

    // Open file
    newfile.open(file_name, std::ios::in);

    // Check if the file is open, if open continue
    if (newfile.is_open()) {

        // Create a string to hold each line
        string line;

        // Loop through each line and assign values to the appropriate containers, increment line counter by one after each loop
        while (getline(newfile, line)) { //read data from file object and put it into string.
            // If reading the first line of the file, convert each number in the string to an int and pass to vector 'labs'
            if (line_count == 0) {
                string size;
                stringstream ss(line);
                while (ss >> size) {
                    int lab_grade = stoi(size);
                    labs.push_back(lab_grade);
                }
            }
            // If reading the second line of the file, convert each number in the string to an int and pass to vector 'assignments'
            if (line_count == 1) {
                string size;
                stringstream ss(line);
                while (ss >> size) {
                    int assignment_grade = stoi(size);
                    assignments.push_back(assignment_grade);
                }
            }
            // If reading the third line of the file, convert string to an integer and pass to 'review_project'
            if (line_count == 2) {
                string size;
                stringstream ss(line);
                while (ss >> size) {
                    int project_grade = stoi(size);
                    projects.push_back(project_grade);
                }
            }
            // If reading the fourth line of the file, convert string to an integer and pass to 'final_exam'
            if (line_count == 3) {
                final_exam = stoi(line);
            }

            // Count lines;
            line_count += 1;
        }
    }

    // If file does not open, output terminal text telling the user.
    else{
        cout << "File did not open, ensure the correct file name was input" << endl;
    }
    return line_count;

}

int main(int argc, char* argv[]) {
    // Ensure the user inputs only ONE command line argument - Output terminal text stating the abort otherwise
    Gradebook* gradebook;
    // Assign the command line argument to string file_name
    string file_name = argv[1];

    // Initiate all containers needed
    vector<int> labs;
    vector<int> assignments;
    vector<int> projects;
    unsigned int final_exam;

    // Read file and assign values to the appropriate containers
    int line_count = read_file(file_name, labs, assignments, projects, final_exam);

    // If line count is equal to four, run the constructor that does not include final exam
    if (line_count == 3){
        gradebook = new Gradebook (labs, assignments, projects);
    }

    // If line count is equal to five, run the constructor that does not include final exam
    if (line_count == 4){
        gradebook = new Gradebook (labs, assignments, projects, final_exam);
    }

    // Output all functions - specifics picked are hard coded, user not allowed to choose
    cout << gradebook->assignment_total() << endl;
    cout << gradebook->lab_total() << endl;
    cout << gradebook->course_total() << endl;
    gradebook->individual("Lab",4);
    gradebook->category("Lab", "Yes");
    gradebook->course(3);
    cout << gradebook->letter_grade() << endl;

    return 0;
}