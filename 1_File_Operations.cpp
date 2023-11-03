/* File Operations */

#include <bits/stdc++.h>
#include <iostream>
#include <iomanip>
using namespace std;

int main (){

    string filename = "alphabet.txt";
    string w_line = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";   // String to be Written to Text Files


    FILE *pFile = fopen (filename.c_str(), "w");    // Opening A File Via FILE Method to Write
    char c;

    if(pFile!=NULL){                                // Before Reaching to the End of File
        for(c = 'A' ; c <= 'Z' ; c++)
            fputc (c, pFile);                       // Putting the Chars of Letters One by One
        fputc('\n', pFile);                         // Putting A New-Line (Enter) Char

        fputs((w_line+"\n").c_str(), pFile);        // Putting the String of the Whole Alphabet
    }fclose(pFile);                                 // Closing the File


    ///////////////////////////////////

    fstream fFile;                                  // Defining fFile as fstream
    fFile.open(filename, ios::in | ios::app);       // Re-Opening the File to Both Read and Append Data on It

    fFile << w_line << endl;                        // Writing the String of the Whole Alphabet and An Enter Char

    // After Reading/Writing/Appending Data, If the Whole Content of the File is Required to Be Read Again
    fFile.clear();                                  // Clearing eof and fail Flags
    fFile.seekg (0, ios::beg);                      // Going Back to the Beginning of the File to Read the Data


	size_t ind = filename.find_last_of('.');        // The Last Occurrence of Dot: "." in the Filename
    string savename = filename.substr(0, ind) + "_copy" + filename.substr(ind);

	fstream sFile;
	sFile.open(savename, ios::out);                 // Creating A New File to Rewrite All the Data in It

	string r_line;                                  // String Variable to Store the Lines from the First File
	while(getline(fFile, r_line)){                  // While Reading Each Line of the File
        cout << r_line << endl;                     // Printing Each Line to the Screen
		sFile << r_line << endl;					// Writing Each Line to the New File
    }

	fFile.close();                                  // Closing the First File
	sFile.close();                                  // Closing the Second File


cout << endl << "Written in: " << filename << endl;
cout << setw(12 + savename.length()) << savename << endl;


cout << endl << endl << "-------------" << endl;
system("pause");
return 0;
}
