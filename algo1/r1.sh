#/bin/bash

# Names: 
# Anthony Le | antlecsuf@csu.fullerton.edu
# Ryan Nishikawa | ryannishikawa48@csu.fullerton.edu
# Dylan Tran | dylanht341@csu.fullerton.edu
# Jasmine Youssef | JasmineYoussef@csu.fullerton.edu

#Program name "target_str.cpp"
#Author: R. Nishikawa
#This file is the script file that accompanies the "target_str.cpp" program.
#Prepare for execution in normal mode (not gdb mode).

#Delete some un-needed files
rm *.o
rm *.out

echo "Compile the source file target_str.cpp and make an executable file"
g++ -o target_str target_str.cpp

#give the program permission to execute
chmod +x target_str

#run the program
echo "Running the program 'target_str' with input from in2a.txt"
./target_str < in2a.txt

echo -e "\nThis bash script will now terminate."