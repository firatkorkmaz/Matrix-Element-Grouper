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

Since the two groups of 1s do not have locational proximity and different numbers are placed between them, they are considered as two different groups although they have value equality.

By using this data, the program analyzes all the elements of the given matrix and divides them into groups. All the results are written in a new text file. This input example gives that output:
```
Matrix:

1 1 1 1 2 2 
1 1 3 2 2 4 
1 3 3 2 4 4 
1 1 3 3 4 1 
1 3 3 4 4 1 

Value Groups in the Matrix:
value: index_row, index_col

1: 0, 0
1: 0, 1
1: 0, 2
1: 0, 3
1: 1, 0
1: 1, 1
1: 2, 0
1: 3, 0
1: 3, 1
1: 4, 0

1: 3, 5
1: 4, 5

2: 0, 4
2: 0, 5
2: 1, 3
2: 1, 4
2: 2, 3

3: 1, 2
3: 2, 1
3: 2, 2
3: 3, 2
3: 3, 3
3: 4, 1
3: 4, 2

4: 1, 5
4: 2, 4
4: 2, 5
4: 3, 4
4: 4, 3
4: 4, 4

----------------
The Input Matrix Has 5 Groups of Data.

```
There are 5 files in this project, the first 4 files can be considered as preparation programs before the main program, and the 5th file is the main program.

1. **1_File_Operations.cpp**: Some file operations: creating files and appending strings to them.
2. **2_Get_Matrix_from_File.cpp**: Reading matrix data from text files to print.
3. **3_Element_Addition_to_Vectors.cpp**: Unique element addition to vectors.
4. **4_Pair_Addition_to_Vector_of_Vectors.cpp**: Adding unique pairs to vector of vectors in groups.
5. **5_Matrix_Element_Grouper.cpp**: The main *Matrix Grouper* program.

Along with the given input example in **matrix0.txt** file, there are also 3 additional input files in this project with **matrix#.txt** filenames to test the program.

## Setup & Run
Compile the files with a C++ compiler and run the executable/output files:
```
g++ filename.cpp
```
