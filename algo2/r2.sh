#/bin/bash

# Names: 
# Anthony Le | antlecsuf@csu.fullerton.edu
# Ryan Nishikawa | ryannishikawa48@csu.fullerton.edu
# Dylan Tran | dylanht341@csu.fullerton.edu
# Jasmine Youssef | JasmineYoussef@csu.fullerton.edu

#Program name "run_encoding.cpp"
#Author: D. Tran, adapted from  r1.sh from R. Nishikawa
#This file is the script file that accompanies the "run_encoding.cpp" program.
#Prepare for execution in normal mode (not gdb mode).

#Delete some un-needed files
rm *.o
rm *.out

echo "Compile the source file run_encoding.cpp and make an executable file"
g++ -o run_encoding run_encoding.cpp

#give the program permission to execute
chmod +x run_encoding

#run the program
echo "Running the program 'run_encoding' with input from in2a.txt"
./run_encoding < input.txt

echo -e "\nThis bash script will now terminate."