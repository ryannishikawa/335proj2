Names: 
Anthony Le | antlecsuf@csu.fullerton.edu
Ryan Nishikawa | ryannishikawa48@csu.fullerton.edu
Dylan Tran | dylanht341@csu.fullerton.edu
Jasmine Youssef | JasmineYoussef@csu.fullerton.edu

To run the program:
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
