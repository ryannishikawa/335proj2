// Names: 
// Anthony Le | antlecsuf@csu.fullerton.edu
// Ryan Nishikawa | ryannishikawa48@csu.fullerton.edu
// Dylan Tran | dylanht341@csu.fullerton.edu
// Jasmine Youssef | JasmineYoussef@csu.fullerton.edu

//****************************************************************************************************************************
//Program name: "target_str".  This program solves the Array pattern and substrings Problem. Copyright (C)           *                                     *
//2025                                                                                                                       *
//This program is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License  *
//version 3 as published by the Free Software Foundation.                                                                    *
//This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied         *
//warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.     *
//A copy of the GNU General Public License v3 is available here:  <https://www.gnu.org/licenses/>.                           *
//****************************************************************************************************************************


//=======1=========2=========3=========4=========5=========6=========7=========8=========9=========0=========1=========2=========3**
//
//Author information
//  Author names: Ryan Nishikawa
//  Author emails: ryannishikawa48@csu.fullerton.edu
//  Course ID: CPSC335
//
//Program information
//  Program name: target_str
//  Due date+time: February 28, 2025 11:59 PM
//  Date of last update: February 27, 2025
//  Programming language(s): C++
//  Files in this program: r.sh, hamiltonian.cpp
//  
//  OS of the computer where the program was developed: Ubuntu 22.04.3 LTS
//  OS of the computer where the program was tested: Ubuntu 22.04.3 LTS
//  Status: WIP
//
//References for this program
//   lectures, slides
//
//Purpose
//  solve the Array pattern and substrings Problem
//
//This file
//   File name: target_str.cpp
//   Language: C++
//   Compile: g++ -o target target_str.cpp
//
//References for this file
//   lectures
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
#include <vector>
#include <string>
#include <cctype>
#include <map>
#include <iomanip> //for quoted
#include <algorithm> //for replace

using namespace std;

void print_arr(const string& name, const vector<string>& arr) {
    cout << name << " = [";
    for (int i = 0; i < arr.size() - 1; i++) { cout << '\"' << arr[i] << "\", "; }
    cout << '\"' << arr.back() << "\"]" << endl;
}

void handle_line(const string& line, map<string, vector<string>>& arrays) {
    int state = 0;
    int i = 0;
    bool ready = false;
    string arr_name = "";
    string city = "";
    vector<string> cities = {};
    //search for array name
    while (state == 0 && i < line.length()) {
        if (line[i] == '=') { state = 1; break; }
        if (!iswspace(line[i])) { 
            if (ready == true) {arr_name = "";}
            arr_name += line[i]; 
            ready = false;
        }
        else if (iswspace(line[i]) && arr_name.length() > 0) { ready = true; }
        i++;
    }
    //add cities to map
    while (state == 1 && i < line.length()) {
        if (isalnum(line[i])) { city += line[i]; }
        else if (line[i] == ']') { state = 2; }
        else if (!isalnum(line[i])){ 
            if (city != "") { 
                cities.push_back(city); 
                city = ""; 
            } 
        }
        i++;
    }
    if (state == 2) {
        print_arr(arr_name, cities);
        arrays.insert({arr_name, cities});
    }
}

int main() {
    //get input from txt file
    map<string, vector<string>> arrays;

    cout << "\n~running \"target_str.cpp\" with input from \"in2a.txt\"\n"
         << "~to run this code with different input, edit \"in2a.txt\"\n\n";
    ifstream input("in2a.txt");
    if (input.is_open()) {
        string line;

        cout << "\nInput: \n";
        while (getline(input, line)) {
            handle_line(line, arrays);
        }
        input.close();
    } else {
        cerr << "Unable to open file" << endl;
    }

    //algo start
    return 0;
}