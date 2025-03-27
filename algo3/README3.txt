# 335proj2
Names: 
Anthony Le | antlecsuf@csu.fullerton.edu
Ryan Nishikawa | ryannishikawa48@csu.fullerton.edu
Dylan Tran | dylanht341@csu.fullerton.edu
Jasmine Youssef | JasmineYoussef@csu.fullerton.edu

To run the program for algorithm 3:
    1) chmod +x r3.sh
        - to make sure the shell script has permission to execute.
    2) ./r3.sh
        - to run the shell script which compiles and runs the program.
        - compiles the code with g++ -o merge_sorted_arrays merge_sorted_arrays.cpp
    3) Because r3.sh uses in2c.txt for input, you can modify the in2c.txt file to test different inputs.

Input Format:
    The program reads the following inputs assuming the arrays are formated by 'Array_' followed by a number:
        Array_1 =[ [2, 5, 9, 21],
        [-1, 0, 2],
        [-10, 81, 121],
        [4, 6, 12, 20, 150] ]
        Array_2 =[ [10, 17, 18, 21, 29],
        [-3, 0, 3, 7, 8, 11],
        [81, 88, 121, 131],
        [9, 11, 12, 19, 29] ]
        Array_3 =[ [-4, -2, 0, 2, 7],
        [4, 6, 12, 14],
        [10, 15, 25],
        [5, 6, 10, 20, 24] ]

Expected Output:
    Merged list for Array_1:
    -10 -1 0 2 2 4 5 6 9 12 20 21 81 121 150

    Merged list for Array_2:
    -3 0 3 7 8 9 10 11 11 12 17 18 19 21 29 29 81 88 121 131

    Merged list for Array_3:
    -4 -2 0 2 4 5 6 6 7 10 10 12 14 15 20 24 25
