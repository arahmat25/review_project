#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main(int argc, char* argv[]) {
    // Ensure the user inputs only ONE command line argument - Output terminal text stating the abort otherwise

    // Assign the command line argument to string file_name
    string file_name = argv[1];
    fstream newfile;
    newfile.open(file_name, std::ios::in);
    // Check if the file is open
    if (newfile.is_open()) {
        vector<int> labs;
        vector<int> assignments;
        unsigned int review_project;
        unsigned int final_project;
        unsigned int final_exam;
        int line_count = 0;
        string line;
        while (getline(newfile, line)) { //read data from file object and put it into string.
            // If reading the first line of the file, convert each number in the string to an int and pass to vector 'labs'
            if (line_count == 0){
                
            }
            // If reading the second line of the file, convert each number in the string to an int and pass to vector 'assignments'
            if (line_count == 1){

            }
            // If reading the third line of the file, convert string to an integer and pass to 'review_project'
            if (line_count == 2){

            }
            // If reading the fourth line of the file, convert string to an integer and pass to 'final_project'
            if (line_count == 3){

            }
            // If reading the fifth line of the file, convert string to an integer and pass to 'final_exam'
            if (line_count == 4){

            }

            // Count lines;
            line_count += 1;
        }
    }


    // If file does not open, output terminal text telling the user.
    else{
        cout << 'File did not open, ensure the correct file name was input' << endl;
    }


    return 0;
}
