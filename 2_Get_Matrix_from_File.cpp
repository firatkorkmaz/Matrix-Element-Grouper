/* Reading Matrix Data from Text Files to Print */

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
using namespace std;


int main(int argc, char* argv[]){

    string filename;

    if(argv[1]){             // If the Filename is Provided as An Input Argument to Run the Program
        istringstream inputfile(argv[1]);
        inputfile >> filename;
    }
    else{	                                // If the Filename is Not Provided as an Input Argument
        cout << "Enter the Filename to Read: ";               //  Ask the User to Enter It Manually
        cin >> filename;
    }

    cout << endl;

    ifstream infile(filename);
    if(!infile){                             // If There is No Test File with the Entered File Name
        cout << "There is No Such File as: " << filename << endl;
        cout << endl << endl << "-------------" << endl;
        system("pause");
        return 0;
    }


    int x;                                  // Integer to Carry Each Element to Vectors/Lambda Expressions
    string lines;                           // String Variable To Get Lines From The Input File
    vector<int> data;                       // Int Vector to Fill the Values in the Matrix
    vector<vector<int>> matrix;             // 2D Int Vector to Store the Given Matrix

    cout << "Matrix:\n" << endl;
    while(getline(infile, lines)){          // While Getting Lines From the File
        istringstream first(lines);
        while(!first.eof()){
            first >> x;
            cout << x << " ";
            data.push_back(x);              // Getting Single Row Values of the Matrix
        }
        matrix.push_back(data);             // Adding This Row to the 2d Matrix Vector
        data.clear();
        cout << endl;
    }infile.close();                        // After Getting the Full Matrix, the File is Closed



cout << endl << endl << "-------------" << endl;
system("pause");
return 0;
}
