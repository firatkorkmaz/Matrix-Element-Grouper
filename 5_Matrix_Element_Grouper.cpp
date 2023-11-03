/* Matrix Element Grouper: Gives the Groups of Values Which Have the Same Values and Locational Proximity to Each Other. */

#include <algorithm>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <array>
using namespace std;


// Checking the Distance of Two Elements in A Matrix by Using Their Index Values to Return True If the Distance is 1
bool distance(array<int, 2> x, array<int, 2> y){
    if( (abs(x[0]-y[0])==0 && abs(x[1]-y[1])==1) || (abs(x[0]-y[0])==1 && abs(x[1]-y[1])==0) )
        return true;
    else
        return false;
}


int main(int argc, char *argv[]){

    // Defining New Data Type for Each Matrix Element: (value, {index_row, index_col})
    typedef pair<int, array<int,2>> pNode;


    string filename;

    if(argv[1]){             // If the Filename is Provided as An Input Argument to Run the Program
        istringstream inputfile(argv[1]);
        inputfile >> filename;
    }
    else{	                                // If the Filename is Not Provided as An Input Argument
        cout << "\nEnter the Filename to Read: ";             //  Ask the User to Enter It Manually
        cin >> filename;
    }

    cout << endl;

    ifstream infile(filename);
    if(!infile){                             // If There is No Test File With the Entered File Name
        cout << "There is No Such File as: " << filename << endl;
        cout << endl << endl << "-------------" << endl;
        system("pause");
        return 0;
    }


    /////////////////////////////////////////////////////////////////////////////////////////////
    // NOTE: Let's Create A New Text File which will Also Store All the Printed Results
    size_t ind = filename.find_last_of('.');        // The Last Occurrence of '.' in the Filename
    string savename = filename.substr(0, ind) + "_results" + filename.substr(ind);

	fstream sFile;
	sFile.open(savename, ios::out);            // Create A New File to Rewrite All the Data to It
    /////////////////////////////////////////////////////////////////////////////////////////////


    int x;                                  // Integer to Carry Each Element to Vectors/Lambda Expressions
    string lines;                           // String Variable to Get Lines from the Input File
    vector<int> data;                       // Int Vector to Fill the Values in the Matrix
    vector<vector<int>> matrix;             // 2d Int Vector to Store the Given Matrix

    cout << "Matrix:\n" << endl;
    sFile << "Matrix:\n" << endl;
    while(getline(infile, lines)){          // While Getting Lines from the File
        istringstream first(lines);
        while(!first.eof()){
            first >> x;
            cout << x << " ";
            sFile << x << " ";
            data.push_back(x);              // Getting Single Row Values of the Matrix
        }
        matrix.push_back(data);             // Adding This Row to the 2d Matrix Vector
        data.clear();
        cout << endl;
        sFile << endl;
    }infile.close();                        // After Getting the Full Matrix, the File is Closed
    cout << endl;
    sFile << endl;


    int dist;                               // Integer to Get the Index of Each Matrix Element
    vector<vector<pNode>> nodes;            // "nodes" Vector will Store pNodes Grouped by Only Different Values (No Locational Group)

    for(int i=0; i<int(matrix.size()); i++){
        for(int j=0; j<int(matrix.at(0).size()); j++){
            x = matrix.at(i).at(j);
            dist = distance(nodes.begin(), find_if(begin(nodes), end(nodes), [x](vector<pNode> &item){return item.at(0).first == x;}));

            if(dist == int(nodes.size())){ 		// If "nodes" Vector Has No Sub-Vector which Contains pNodes with matrix[i][j] Value
                nodes.push_back(vector<pNode>());          		// Add New Empty Sub-Vector to the "nodes" Vector for the New pNodes
            }

            nodes.at(dist).push_back(pNode(matrix.at(i).at(j), {i, j}));	 // Add the Current pNode to the "nodes" at "dist" Index
        }
    }


    // Sort Sub-Vectors Of The "Nodes" Vector by Their Values
    sort(nodes.begin(), nodes.end(), [](vector<pNode> &left, vector<pNode> &right){return left.at(0).first < right.at(0).first;});
    // Sort the Contents (pNodes) of each Sub-Vector by Their Index Coordinates
    for(int i=0; i<int(nodes.size()); i++){
        sort(nodes.at(i).begin(), nodes.at(i).end(), [](pNode &left, pNode &right){return left.second < right.second;});
    }


    vector<pNode> temp;
    vector<vector<pNode>> groups;            // Final Vector will Store pNodes Grouped by both Value Equality and Locational Proximity

    for(int i=0; i<int(nodes.size()); i++){  // For Each pNode Vector in the 2D "nodes" Vector

        innerloop:          // To Restart the Inner Loops If There are any Elements Left with the Same Values but out of the Current Group
            temp.clear();                   // Clear the Temp Vector to Prepare A New Vector of pNodes Which are Placed in the Same Groups
            temp.push_back(nodes.at(i).at(0));     // At the Beginning, Get the 1st pNode Value of the Current pNode Vector in the "nodes"
            nodes.at(i).erase(nodes.at(i).begin());           // Remove the First Value Taken from the Current pNode Vector in the "nodes"
			// erase(nodes.at(i), nodes.at(i).at(0));		  // This Method Requires Additional -std=c++20/23 Flag on Compiling
			
            for(int j=0; j<int(temp.size()); j++){            // For Each pNode Element in the "temp" Vector

                int k=0;
                for(; k<int(nodes.at(i).size()); k++){        // For Each pNode Element in the Current pNode Vector of the "Nodes" Vector

                    if(distance(nodes.at(i).at(k).second, temp.at(j).second)){		// If Their Distance is 1
                        temp.push_back(nodes.at(i).at(k));							// Push It to the "temp" Vector
                        nodes.at(i).erase(nodes.at(i).begin() + k);					// Remove It from the pNode Sub-Vector of the "nodes"
						// erase(nodes.at(i), nodes.at(i).at(k));	   // This Method Requires Additional -std=c++20/23 Flag on Compiling
                        k=-1;   // After Removing the Current pNode, Start the Next Checking of the Current Sub-Vector from Its 1st pNode
                    }
                }
            }

            sort(temp.begin(), temp.end(), [](pNode &left, pNode &right){return left.second < right.second;}); // Sorting the Temp Vector
            groups.push_back(temp);          // Push the Finalized "temp" Vector to the 2D "groups" Vector
            if(int(nodes.at(i).size())!=0){  // If There are pNodes Left without Being Assigned Due to Not Belonging to the Current Group
                goto innerloop;              // Go Back to the "innerloop:" to Analyze the Remaining pNodes and Create a New Group for Them
            }
    }


    cout << "Value Groups in the Matrix:\nvalue: index_row, index_col" << endl << endl;
    sFile << "Value Groups in the Matrix:\nvalue: index_row, index_col" << endl << endl;
    for(int m=0; m<int(groups.size()); m++){        // Printing the pNode Groups that are Placed in the Same Regions with the Same Values
        for(int n=0; n<int(groups.at(m).size()); n++){
            cout << groups.at(m).at(n).first << ": " << groups.at(m).at(n).second[0] << ", " << groups.at(m).at(n).second[1] << endl;
            sFile << groups.at(m).at(n).first << ": " << groups.at(m).at(n).second[0] << ", " << groups.at(m).at(n).second[1] << endl;
        }cout << endl; sFile << endl;
    }
    cout << "----------------" << endl;
    sFile << "----------------" << endl;
    cout << "The Input Matrix Has " << int(groups.size()) << " Groups of Data." << endl;
    sFile << "The Input Matrix Has " << int(groups.size()) << " Groups of Data." << endl;

    sFile.close();							// Close the New File of Results Data

    cout << endl << "Written in: " << savename << endl;


cout << endl << endl << "-------------" << endl;
system("pause");
return 0;
}
