/* Adding Unique Pairs to Vector of Vectors in Groups */

#include <algorithm>
#include <iostream>
#include <vector>
#include <array>
using namespace std;


int main(int argc, char *argv[]){

    typedef pair<int, array<int,2>> pNode;  // Definition of Pair Type "pNode" as Having One Int and One Array of 2 Int Elements
    vector<pNode> temp;                     // pNode Type Vector (Pair of Int and Int[2])

    // Adding Random pNode Pairs to the pNode Vector: "temp"
    temp.push_back(pNode(3, {2, 0}));
    temp.push_back(pNode(1, {0, 0}));
    temp.push_back(pNode(2, {1, 0}));
    temp.push_back(pNode(4, {1, 2}));
    temp.push_back(pNode(2, {0, 1}));
    temp.push_back(pNode(1, {0, 2}));
    temp.push_back(pNode(3, {2, 1}));
    temp.push_back(pNode(2, {1, 1}));

    temp.push_back(pNode(4, {2, 2}));
    temp.push_back(pNode(4, {2, 2}));   // The Same pNode will Not Be Added Again!


    int element_1;              // For the 1st Element of Pairs
    int index_1;                // For the Index of Sub-Vectors

    array<int, 2> element_2;    // For the 2nd Element of Pairs
    int index_2;                // For the Index of pNodes in Sub-Vectors

    vector<vector<pNode>> nodes;

    for(int i=0; i<int(temp.size()); i++){
        element_1 = temp.at(i).first;       // Getting the First Element of the pNode Pair, which is A Single Int Value

		// index_1: Index of the pNode Sub-Vectors which Have pNodes with the First Elements (Integers) that are Equal to "element_1"
        index_1 = distance(nodes.begin(), find_if(begin(nodes), end(nodes),
                                                [element_1](vector<pNode> &item){return item.at(0).first == element_1;}));

        if(index_1 == int(nodes.size())){	    // If "nodes" does Not Have any pNode Vector which Has A pNode Pair with the First Element = "element_1"
            nodes.push_back(vector<pNode>());	// Adding New Empty pNode Sub-Vector to the "nodes" Vector and Now the "index_1" is the Index of This
        }

        else{									// This "else" Block Prevents Adding the Same pNode Element to any Sub-Vector in the "nodes" Vector
            element_2 = temp.at(i).second;      // Getting the Second Element of the pNode Pair, which is An Array of 2 Integers

            // index_2: Index of the pNode Pair which Has the Second Element (Array of 2 Integers) that is Equal to "element_2"
            index_2 = distance(nodes.at(index_1).begin(), find_if(begin(nodes.at(index_1)), end(nodes.at(index_1)),
                                                             [element_2](pNode &item){return item.second == element_2;}));

            if (index_2 < int(nodes.at(index_1).size()))    // If A pNode with the Second Element "element_2" is Already in the Related Sub-Vector
                continue;                                   // Do Not Add It Again to the Related Sub-Vector of "nodes"
        }

		nodes.at(index_1).push_back(temp.at(i));	// Add the Current pNode from the temp Vector to the pNode Sub-Vector of the "nodes" at index = "index_1"
    }

    // All the pNodes Have Been Added to the "nodes" Vector of pNode Vectors as Grouped by the 1st Elements of Pairs


    // Sorting the Elements (Pairs) of pNode Sub-Vectors by the 2nd Elements (Arrays of 2 Integers) of pNode Pairs
    for(int j=0; j<int(nodes.size()); j++){
        sort(nodes.at(j).begin(), nodes.at(j).end(), [](auto &left, auto &right){return left.second < right.second;});
    }
    // Sorting the Elements (Sub-Vectors) of "nodes" Vector by the 1st Elements (Integers) of the pNode Pairs in Each Sub-Vector
    sort(nodes.begin(), nodes.end(), [](auto &left, auto &right){return left.at(0).first < right.at(0).first;});


    // Printing the Content of "nodes" Vector
    for(int m=0; m<int(nodes.size()); m++){
        for(int n=0; n<int(nodes.at(m).size()); n++){
            cout << nodes.at(m).at(n).first << ": " << nodes.at(m).at(n).second[0] << ", " << nodes.at(m).at(n).second[1] << endl;
        }cout << endl;
    }



cout << endl << "-------------" << endl;
system("pause");
return 0;
}
