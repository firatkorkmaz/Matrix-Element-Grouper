/* Unique Element Addition to Vectors */

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;


int main(int argc, char *argv[]){

    vector<string> words;

    //word.push_back("abc");
    words.push_back("def");
    words.push_back("ghi");
    //words.push_back("jkl");
    words.push_back("mno");
    words.push_back("pqr");

    cout << "Vector of Unique Strings:" << endl << endl;
    for(int k=0; k<int(words.size()); k++){
        cout << words.at(k) << endl;
    }cout << endl;

    //string e = "abc";
    string e;
    cout << "Enter A Word to Add: ";
    cin >> e;

    if(distance(words.begin(), find_if(begin(words), end(words), [e](string &item)      // Using Lambda Expressions
                                    {return item == e;} ) ) == int(words.size()) ){     // If e is Not Found in "words" Vector
        words.push_back(e);                                                             // Add "e" String to the "words" Vector
        cout << endl << e << " is Added!" << endl << endl;
    }
    else{
        cout << endl << e << " Already Exists!" << endl << endl;
    }

    // Sort "words" in Ascending Order (Optional).
    sort(words.begin(), words.end(), [](string &left, string &right){return left < right;});

    for(int k=0; k<int(words.size()); k++){
        cout << words.at(k) << endl;
    }



cout << endl << endl << "-------------" << endl;
system("pause");
return 0;
}
