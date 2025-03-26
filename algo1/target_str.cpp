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
//  Due date+time: March 26, 2025 11:59 PM
//  Date of last update: March 25, 2025
//  Programming language(s): C++
//  Files in this program: r1.sh, targer_str.cpp
//  
//  OS of the computer where the program was developed: Ubuntu 22.04.3 LTS
//  OS of the computer where the program was tested: Ubuntu 22.04.3 LTS
//  Status: done
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
//   https://en.cppreference.com/w/cpp/container/queue
//   https://en.cppreference.com/w/cpp/string/basic_string/getline
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
#include <queue>
#include <iomanip> //for quoted
#include <algorithm> //for replace

using namespace std;

//func to print a vector
template <typename T>
void print_arr(const string& name, const vector<T>& arr) {
    cout << name << " = [";
    for (int i = 0; i < arr.size() - 1; i++) { cout << '\"' << arr[i] << "\", "; }
    cout << '\"' << arr.back() << "\"]" << endl;
}

//parse a string into a vector of strings paired with the vector name
void handle_line(const string& line, queue<pair<string, vector<string>>>& arrays) {
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
    //have to check using isalnum bc the " " and ' ' in the txt file used for input is weird and not recognized as a char
    while (state == 1 && i < line.length()) {
        if (isalnum(line[i])) { city += line[i]; }
        else if (line[i] == ']') { state = 2; }
        else if (!city.empty()){ 
            cities.push_back(city); 
            city.clear(); 
        }
        i++;
    }
    if (state == 2 && !cities.empty()) {
        arrays.push({arr_name, cities});
    }
}

int main() {
    //get input from txt file
    queue<pair<string, vector<string>>> arrays;

    cout << "~to run this code with different input, edit \"in2a.txt\"\n\n";
    ifstream input("in2a.txt");
    if (input.is_open()) {
        string line = "";;

        while (getline(input, line)) {
            handle_line(line, arrays); //parse line into array name and vector of cities
        }
        input.close();
    } else { cerr << "Unable to open file" << endl; }

    //algo start
    while (!arrays.empty()) {
        vector<int> locs;
        vector<string> what;
        //input is 2 vectors so we take two from the queue and pop
        cout << "\nInput: \n";
        auto arr1 = arrays.front();
        print_arr(arr1.first, arr1.second);
        arrays.pop();
        auto arr2 = arrays.front();
        print_arr(arr2.first, arr2.second);

        cout << "\nOutput: \n";
        string search = arr1.second.front(); //get the string to search
        for (int i = 0; i < search.length(); i++) {
            for (int j = 0; j < arr2.second.size(); j++) {
                if (search[i] == arr2.second[j][0]) { //check if the first char of the string matches the current char of the search string
                    int peek = i;
                    while (peek < search.length()) {  //check if the rest of the string matches
                        if (search[peek] == arr2.second[j][peek - i]) {peek++; }
                        else { break; }
                    }
                    if ((peek - i) == arr2.second[j].length()) { //if the string matches, add the location and city name to the vectors
                        locs.push_back(i);
                        what.push_back(arr2.second[j]);
                    }
                }
            }
        }
        print_arr("Output_order", locs);
        print_arr("Output_array", what);
        arrays.pop();
    }
    return 0;
}