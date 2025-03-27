#/bin/bash

# Names: 
# Anthony Le | antlecsuf@csu.fullerton.edu
# Ryan Nishikawa | ryannishikawa48@csu.fullerton.edu
# Dylan Tran | dylanht341@csu.fullerton.edu
# Jasmine Youssef | JasmineYoussef@csu.fullerton.edu

#Program name "merge_sorted_arrays.cpp"
#Author: A. Le, adapted r1.sh from R. Nishikawa
#This file is the script file that accompanies the "merge_sorted_arrays.cpp" program.
#Prepare for execution in normal mode (not gdb mode).

# Delete some un-needed files
rm -f *.o
rm -f *.out

echo "Compiling the source file merge_sorted_arrays.cpp and creating an executable"
g++ -o merge_sorted_arrays merge_sorted_arrays.cpp

# Give the program permission to execute
chmod +x merge_sorted_arrays

# Run the program
echo "Running the program 'merge_sorted_arrays'"
./merge_sorted_arrays

echo -e "\nThis bash script will now terminate."