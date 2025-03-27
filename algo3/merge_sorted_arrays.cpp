// Names: 
// Anthony Le | antlecsuf@csu.fullerton.edu
// Ryan Nishikawa | ryannishikawa48@csu.fullerton.edu
// Dylan Tran | dylanht341@csu.fullerton.edu
// Jasmine Youssef | JasmineYoussef@csu.fullerton.edu

//*********************************************************************************************************************************
//Program name: "merge_sorted_arrays".  This program solves the Run Encoding Problem. Copyright (C)*
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
//  Author names: Anthony Le
//  Author emails: antlecsuf@csu.fullerton.edu
//  Course ID: CPSC335
//
//Program information
//  Program name: merge_sorted_arrays
//  Due date+time: March 26, 2025 11:59 PM
//  Date of last update: March 26, 2025
//  Programming language(s): C++
//  Files in this program: r3.sh, merge_sorted_arrays.cpp
//  
//  OS of the computer where the program was developed: Ubuntu 22.04.3 LTS
//  OS of the computer where the program was tested: Ubuntu 22.04.3 LTS
//  Status: done
//
//References for this program
//   lectures, slides, cppreference.com, geekforgeeks.org, leetcode.com
//
//Purpose
//  Solves the Run Encoding Problem.
//
//This file
//   File name: merge_sorted_arrays.cpp
//   Language: C++
//   Compile: g++ -o merge_sorted_arrays merge_sorted_arrays.cpp
//
//References for this file
//   cppreference.com, geekforgeeks.org, leetcode.com (Merge k Sorted Lists)
//
//=======1=========2=========3=========4=========5=========6=========7=========8=========9=========0=========1=========2**
//
//
//
//
//===== Begin code area ================================================================================================

#include <iostream>
#include <vector>
#include <queue>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <cctype>
#include <string>
using namespace std;

struct Node {
    int value;
    int listIdx;
    int elementIdx;
    Node(int v, int l, int e) : value(v), listIdx(l), elementIdx(e) {}
};

struct CompareNode {
    bool operator()(const Node& a, const Node& b) {
        return a.value > b.value; // Min-heap based on value
    }
};

vector<int> mergeLists(vector<vector<int>> allLists) {
    vector<int> result;
    priority_queue<Node, vector<Node>, CompareNode> minHeap;

    for (int i = 0; i < allLists.size(); ++i) {
        if (!allLists[i].empty()) {
            minHeap.push(Node(allLists[i][0], i, 0));
        }
    }

    while (!minHeap.empty()) {
        Node current = minHeap.top();
        minHeap.pop();
        result.push_back(current.value);

        if (current.elementIdx + 1 < allLists[current.listIdx].size()) {
            int nextIdx = current.elementIdx + 1;
            minHeap.push(Node(allLists[current.listIdx][nextIdx], current.listIdx, nextIdx));
        }
    }

    return result;
}

vector<vector<int>> parseArrayString(const string& arrayStr) {
    vector<vector<int>> result;
    string s = arrayStr;

    // Remove all whitespace
    s.erase(remove_if(s.begin(), s.end(), ::isspace), s.end());

    if (s.empty() || s.front() != '[' || s.back() != ']') {
        cerr << "Invalid array format: " << arrayStr << endl;
        return result;
    }

    // Remove outer brackets
    s = s.substr(1, s.size() - 2);

    vector<string> innerArrays;
    size_t start = 0;
    size_t end;
    while ((end = s.find("],[", start)) != string::npos) {
        innerArrays.push_back(s.substr(start, end - start));
        start = end + 3;
        if (start >= s.size()) break;
    }
    innerArrays.push_back(s.substr(start));

    for (const string& inner : innerArrays) {
        string cleaned = inner;
        cleaned.erase(remove(cleaned.begin(), cleaned.end(), '['), cleaned.end());
        cleaned.erase(remove(cleaned.begin(), cleaned.end(), ']'), cleaned.end());

        if (cleaned.empty()) continue;

        vector<int> vec;
        stringstream ss(cleaned);
        string token;
        while (getline(ss, token, ',')) {
            if (!token.empty()) {
                vec.push_back(stoi(token));
            }
        }
        result.push_back(vec);
    }

    return result;
}

int main() {
    vector<pair<int, vector<vector<int>>>> allArrays; // Stores (array number, array data)
    ifstream file("in2c.txt");

    if (!file.is_open()) {
        cerr << "Failed to open input file." << endl;
        return 1;
    }

    string line;
    string currentArrayStr;
    int currentArrayNumber = -1;
    int bracketCount = 0;
    bool readingArray = false;

    while (getline(file, line)) {
        // Check if line starts with "Array_"
        if (line.find("Array_") == 0) {
            readingArray = true;
            currentArrayStr.clear();
            bracketCount = 0;

            // Extract array number (e.g., "Array_3" -> 3)
            size_t underscorePos = line.find('_');
            size_t spacePos = line.find_first_of(" =", underscorePos);
            string numStr = line.substr(underscorePos + 1, spacePos - underscorePos - 1);
            currentArrayNumber = stoi(numStr);

            size_t eqPos = line.find('=');
            if (eqPos == string::npos) {
                cerr << "Invalid line: " << line << endl;
                continue;
            }

            currentArrayStr = line.substr(eqPos + 1);
            currentArrayStr = currentArrayStr.substr(currentArrayStr.find_first_not_of(" \t"), string::npos);

            bracketCount += count(currentArrayStr.begin(), currentArrayStr.end(), '[');
            bracketCount -= count(currentArrayStr.begin(), currentArrayStr.end(), ']');

            if (bracketCount == 0) {
                allArrays.emplace_back(currentArrayNumber, parseArrayString(currentArrayStr));
                readingArray = false;
            }
        } else if (readingArray) {
            currentArrayStr += line;
            bracketCount += count(line.begin(), line.end(), '[');
            bracketCount -= count(line.begin(), line.end(), ']');

            if (bracketCount == 0) {
                allArrays.emplace_back(currentArrayNumber, parseArrayString(currentArrayStr));
                readingArray = false;
            }
        }
    }

    // Print merged lists in the order they appeared in the file, with correct labels. example edge case if there was 1 and 3 but no array_2
    for (const auto& entry : allArrays) {
        cout << "Merged list for Array_" << entry.first << ":\n";
        vector<int> merged = mergeLists(entry.second);
        for (int num : merged) {
            cout << num << " ";
        }
        cout << "\n\n";
    }

    return 0;
}