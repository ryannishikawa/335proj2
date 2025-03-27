# 335proj2
Names: 
Anthony Le | antlecsuf@csu.fullerton.edu
Ryan Nishikawa | ryannishikawa48@csu.fullerton.edu
Dylan Tran | dylanht341@csu.fullerton.edu
Jasmine Youssef | JasmineYoussef@csu.fullerton.edu

To run the program for algorithm 1:
    1) chmod +x r1.sh
        - to make sure the shell script has permission to execute.
    2) ./r1.sh
        - to run the shell script which compiles and runs the program.
        - compiles the code with g++ -o target_str target_str.cpp
    3) Because target_str.cpp is hardcoded to use in2a.txt for input, you must modify the in2a.txt file to test different inputs.
    4) After running the program, the input with its matching output will be printed to the console.

Input format:
    array 3a = [“torranceoaklandrialtomarcooxnardchinofresnoirvineclovissimiorange”]
    array 3b = [‘oxnard’, ‘irvine’, ‘orange’, ‘marco’]

Expected Output:
    Input:
    3a = ["torranceoaklandrialtomarcooxnardchinofresnoirvineclovissimiorange"]
    3b = ["oxnard", "irvine", "orange", "marco"]

    Output:
    Output_order = ["21", "26", "43", "59"]
    Output_array = ["marco", "oxnard", "irvine", "orange"]


To run the program for algorithm 2:
    1) chmod +x r2.sh
        - to make sure the shell script has permission to execute.
    2) ./r2.sh
        - to run the shell script which compiles and runs the program.
        - compiles the code with g++ -o run_encoding run_encoding.cpp
    3) Because r2.sh uses input.txt for input, you can modify the input.txt file to test different inputs.

    4) If you want to enter input by hand you can run the program directly from the terminal using the following command: ./run_encoding < input.txt
        - if that doesn't work make sure the the file was compiled correctly by running the following command: g++ -o run_encoding run_encoding.cpp
        - also make sure the file has execute permissions by running the following command: chmod +x run_encoding

Input Format
    The program reads the following inputs:
        "ddd"
        "heloooooooo there"
        "choosemeeky and tuition-free"

Expected Output
    "3d"
    "hel8o there"
    "ch2osem2eky and tuition-fr2e"


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
