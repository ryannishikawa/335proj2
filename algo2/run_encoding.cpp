// Names: 
// Anthony Le | antlecsuf@csu.fullerton.edu
// Ryan Nishikawa | ryannishikawa48@csu.fullerton.edu
// Dylan Tran | dylanht341@csu.fullerton.edu
// Jasmine Youssef | JasmineYoussef@csu.fullerton.edu

//*********************************************************************************************************************************
//Program name: "run_encoding".  This program solves the Run Encoding Problem. Copyright (C)*
//2025                                                                                                                            *
//This program is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License       *
//version 3 as published by the Free Software Foundation.                                                                         *
//This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied              *
//warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.          *
//A copy of the GNU General Public License v3 is available here:  <https://www.gnu.org/licenses/>.                                *
//*********************************************************************************************************************************


//=======1=========2=========3=========4=========5=========6=========7=========8=========9=========0=========1=========2=========3**
//
//Author information
//  Author names: Dylan Tran
//  Author emails: dylanht341@csu.fullerton.edu
//  Course ID: CPSC335
//
//Program information
//  Program name: run_encoding
//  Due date+time: March 26, 2025 11:59 PM
//  Date of last update: March 25, 2025
//  Programming language(s): C++
//  Files in this program: r2.sh, run_encoding.cpp
//  
//  OS of the computer where the program was developed: Ubuntu 22.04.3 LTS
//  OS of the computer where the program was tested: Ubuntu 22.04.3 LTS
//  Status: done
//
//References for this program
//   lectures, slides, cppreference.com
//
//Purpose
//  Solves the Run Encoding Problem.
//
//This file
//   File name: run_encoding.cpp
//   Language: C++
//   Compile: g++ -o run_encoding run_encoding.cpp
//
//References for this file
//   cppreference.com
//
//=======1=========2=========3=========4=========5=========6=========7=========8=========9=========0=========1=========2**
//
//
//
//
//===== Begin code area ================================================================================================

#include <iostream>
#include <sstream>
#include <fstream>
#include <string>

using namespace std;

// Function that implements the Run Encoding problem
string runEncode(string str) {
    int len = str.length();
    string answer;

    for (int i = 0; i < len; ++i) {     // Starts the loop for each letter
        int count = 1;

        // Loops an n amount of times for each letter that appears n times
        while (i < len - 1 && str[i] == str[i + 1]) {
            // Increment count for each appearance of a letter
            count++;
            // Increment along the string
            i++;
        }
       
        // Only include counts that are greater than 1 inside the answer
        if (count > 1) {
            answer += to_string(count);
        }
        answer.push_back(str[i]);
    }

    return answer;
}

int main () {
    string line;

    // Read input
    while (getline(cin, line)) {
        // Compute and print results
        cout << runEncode(line) << endl;
    }

    return 0;
}