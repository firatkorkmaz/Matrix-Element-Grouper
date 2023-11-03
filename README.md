# Matrix Element Grouper
This is a matrix grouper program that analyzes a given input matrix and groups its elements that have the same values and locational proximity to each other.

## General Information
Example of grouping a matrix:
```
(1) (1) (1) (1) [2] [2]
(1) (1) {3} [2] [2] <4>
(1) {3} {3} [2] <4> <4>
(1) (1) {3} {3} <4> |1|
(1) {3} {3} <4> <4> |1|
```
Here, there are 5 groups in this matrix according to the value equalities and locational proximities:
```
(1) (1) (1) (1)                       [2] [2]                  
(1) (1)               {3}         [2] [2]             <4>      
(1)               {3} {3}         [2]             <4> <4>      
(1) (1)               {3} {3}                     <4>        |1|
(1)               {3} {3}                     <4> <4>        |1|         
```

Since the two groups of 1s do not have locational proximity and different numbers are placed between them, they are considered as two different groups although they have value equality.\
There are 5 files in this project, the first 4 files can be considered as preparation programs before the main program, and the 5th file is the main program.
1. **1_File_Operations.cpp**: Some file operations: creating files and appending strings to them.
2. **2_Get_Matrix_from_File.cpp**: Reading matrix data from text files to print.
3. **3_Element_Addition_to_Vectors.cpp**: Unique element addition to vectors.
4. **4_Pair_Addition_to_Vector_of_Vectors.cpp**: Adding unique pairs to vector of vectors in groups.
5. **5_Matrix_Element_Grouper.cpp**: The main *Matrix Grouper* program.

## Setup & Run
Compile the files with a C++ compiler and run the executable/output files:
```
g++ filename.cpp
```