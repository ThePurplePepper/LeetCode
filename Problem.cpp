#include <iostream>
#include "Problem.h"

#include <cstring>
#include <map>
#include <vector>

using namespace std;

Problem::Problem(unsigned int ID, const string &name, const string &desc, Difficulty difficulty) :
    ID(ID), problemName(name), description(desc), difficulty(difficulty) {}
Problem::~Problem() = default;

string Problem::getDifficulty() {
    switch (difficulty) {
        case Difficulty::Easy:
            return "Easy";
        case Difficulty::Medium:
            return "Medium";
        case Difficulty::Hard:
            return "Hard";
        default:
            return "Null";
    }
}

string Problem::getProblemName() {
    return problemName;
}

unsigned int Problem::getID() {
    return ID;
}

string Problem::getDescription() {
    return description;
}



TwoSum::TwoSum() : Problem(1, "TwoSum",
    "Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.\n"
    "You may assume that each input would have exactly one solution, and you may not use the same element twice.\n"
    "You can return the answer in any order.\n",
        Difficulty::Easy) {}

void TwoSum::Solution(int *arr, int target, int len, int output[2]) {
    output[0] = -1;
    output[1] = -1;
    for (int i = 0; i < len; i++) {
        for (int j = 0; j < len; j++) {
            if (arr[i] + arr[j] == target) {
                output[0] = i;
                output[1] = j;
                return;
            }
        }
    }
}

void TwoSum::anotherSolution(int *arr, int target, int len, int output[2]) {
    std::map<int, int> pairs;
    for (int i = 0; i < len; i++) {     //place the index in the element's place
        if (pairs.find(arr[i]) == pairs.end()) {
            pairs[arr[i]] = i;
        }
    }
    for (int i = 0; i < len; i++) {
        int complement = target - arr[i];
        auto it = pairs.find(complement);
        if (it != pairs.end() && it->second != i) {
            output[0] = i;
            output[1] = it->second;
            return;
        }
        // if (pairs.at(arr[i])) {      Problematic because "at" throws exception
        //     output[0] = pairs[arr[i]];
        //     int temp = target - arr[i];
        //     output[1] = pairs[temp];
        // }
    }
    output[0] = output[1] = -1;
}

PalindromeNumber::PalindromeNumber() : Problem(9, "PalindromNumber",
    "Given an integer x, return true if x is a palindrome, and false otherwise.\n", Difficulty::Easy) {}

bool PalindromeNumber::Solution(int x) {
    if (x < 0) {
        return false;
    }
    std::vector<int> digits;
    while (x > 0) {
        digits.push_back(x % 10);
        x = x / 10;
    }
    for (int i = 0; i < int(digits.size() / 2); i++) {
        if (digits[i] != digits[digits.size() - 1 - i]) {
            return false;
        }
    }
    return true;
}

RomanToInteger::RomanToInteger() : Problem(13, "RomanToInteger",
    "Given a roman numeral, convert it to an integer.\n", Difficulty::Easy) {}

int RomanToInteger::Solution(const string& s) {
    int result = 0;
    size_t i = 0;
    while (i+1 <= s.length()) {
        if (s[i] == 'I') {
            if (s[i+1] == 'V') {
                result += 4;
                i++;
            } else if (s[i+1] == 'X') {
                result += 9;
                i++;
            } else {
                result += 1;
            }
        } else if (s[i] == 'X') {
            if (s[i+1] == 'L') {
                result += 40;
                i++;
            } else if (s[i+1] == 'C') {
                result += 90;
                i++;
            } else {
                result += 10;
            }
        } else if (s[i] == 'C') {
            if (s[i+1] == 'D') {
                result += 400;
                i++;
            } else if (s[i+1] == 'M') {
                result += 900;
                i++;
            } else {
                result += 100;
            }
        } else if (s[i] == 'V') {
            result += 5;
        } else if (s[i] == 'L') {
            result += 50;
        } else if (s[i] == 'D') {
            result += 500;
        } else if (s[i] == 'M') {
            result += 1000;
        }
        i++;
    }
    return result;
}

int RomanToInteger::anotherSolution(const string& s) {
    int result = 0;
    for (size_t i = 0; i < s.length(); i++) {
        switch (s[i]) {
            case 'I':
                result += 1;
                if (i+1 < s.length()) {
                    if (s[i+1] == 'V') {
                        result += 3;
                    } else if (s[i+1] == 'X') {
                        result += 8;
                    }
                }
            break;
            case 'V':
                result += 5;
            break;
            case 'X':
                result += 10;
                if (i+1 < s.length()) {
                    if (s[i+1] == 'L') {
                        result += 30;
                    } else if (s[i+1] == 'C') {
                        result += 80;
                    }
                }
            break;
            case 'L':
                result += 50;
            break;
            case 'C':
                result += 100;
            if (i+1 < s.length()) {
                if (s[i+1] == 'D') {
                    result += 300;
                } else if (s[i+1] == 'M') {
                    result += 800;
                }
            }
            break;
            case 'D':
                result += 500;
            break;
            case 'M':
                result += 1000;
            break;
            default:
                throw std::invalid_argument("Invalid argument");
        }
    }
    return result;
}

int RomanToInteger::bestSolution(const string& s) {
    std::map<char, int> pairs;
    pairs['I'] = 1;
    pairs['V'] = 5;
    pairs['X'] = 10;
    pairs['L'] = 50;
    pairs['C'] = 100;
    pairs['D'] = 500;
    pairs['M'] = 1000;
    int result = 0;
    for (size_t i = 0; i < s.length(); i++) {
        if (i+1 < s.length() && pairs[s[i]] < pairs[s[i+1]]) {
            result = result + pairs[s[i+1]] - pairs[s[i]];
            i++;
        } else {
            result += pairs[s[i]];
        }
    }
    return result;
}


