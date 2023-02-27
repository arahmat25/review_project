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
        gradebook = new Gradebook (labs, assignments, projects,file_name);
    }

    // If line count is equal to five, run the constructor that does not include final exam
    if (line_count == 4){
        gradebook = new Gradebook (labs, assignments, projects, final_exam, file_name);
    }

    // Initialize integer holder for option number;
    int option;

    // Loop through the option menu unless the user chooses to exit the program (option 7)
    while (option != 7) {
        // OPTION MENU
        cout << "Here are the options for this program: " << "\n"
             << "[1] - Output an individual deliverable and it's corresponding grade." << "\n"
             << "[2] - Output a category, all grades within that category, and it's total." << "\n"
             << "[3] - Output all individual grades, the course total, and it's corresponding letter grade." << "\n"
             << "[4] - Output all category totals, the course total, and it's corresponding letter grade." << "\n"
             << "[5] - Output the course total and it's corresponding letter grade." << "\n"
             << "[6] - Change a grade." << "\n"
             << "[7] - Exit the program." << "\n"
             << "\n" << "Which option would you like to choose? Please enter the number: ";

        // User inputs option
        cin >> option;

        // Option 1 - Output an individual deliverable and it's corresponding grade
        if (option == 1){
            string deliverable_name;
            int deliverable_num;
            cout << "Which category would you like? Options are 'Lab', 'Assignment', 'Projects', or 'Final Exam' . Please enter exactly as typed. " << endl;
            cin >> deliverable_name;
            cout << "Which deliverable would you like? Options are 1-12 for labs, 1-4 for assignments, 1-2 for projects, and 1 for final exam. Please do not exceed these ranges. " << endl;
            cin >> deliverable_num;
            gradebook->individual(deliverable_name, deliverable_num);
            cout << endl;
        }

        // Option 2 - Output a category, all grades within that category, and it's total
        else if (option == 2){
            string category;
            cout << "Which category would you like? Options are 'Lab', 'Assignment', 'Projects', or 'Final Exam' . Please enter exactly as typed. " << endl;
            cin >> category;
            gradebook->category(category, "Yes");
            cout << endl;
        }

        // Option 3 - Output all individual grades, the course total, and it's corresponding letter grade
        else if (option == 3){
            gradebook->course(1);
            cout << "Letter Grade: " << gradebook->letter_grade() << endl;
            cout << endl;
        }

        // Option 4 - Output all category totals, the course total, and it's corresponding letter grade
        else if (option == 4){
            gradebook->course(2);
            cout << "Letter Grade: " << gradebook->letter_grade() << endl;
            cout << endl;
        }

        // Option 5 - Output the course total and it's corresponding letter grade
        else if (option == 5){
            gradebook->course(3);
            cout << "Letter Grade: " << gradebook->letter_grade() << endl;
            cout << endl;
        }

        // Option 6 - Change a grade
        else if (option == 6){
            string category;
            cout << "Which category would you like to change? Options are 'Lab', 'Assignment', 'Projects', or 'Final Exam' . Please enter exactly as typed. " << endl;
            cin >> category;
            gradebook->changeData(category);
            cout << endl;
        }

        // Option 7 - Exit the program
        else if (option == 7){
            cout << "Exiting program, goodbye." << endl;
            cout << endl;
        }

        // Output if user does not enter an integer 1-7
        else {
            cout << "Invalid option, please try again." << endl;
            cout << endl;
        }
    }

    return 0;
}