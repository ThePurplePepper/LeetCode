#include <iostream>
#include "Problem.h"

#include <cstring>
#include <limits>
#include <list>
#include <map>
#include <stack>
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

LongestCommonPrefix::LongestCommonPrefix() : Problem(14, "LongestCommonPrefix",
"Write a function to find the longest common prefix string amongst an array of strings.\n"
"If there is no common prefix, return an empty string\n", Difficulty::Easy) {}

string LongestCommonPrefix::Solution(vector<string> &strs) {
    size_t shortestStringLength = 0;
    string result;
    if (!strs.empty()) {
        shortestStringLength = strs[0].length();
    } else {
        return result;
    }
    for (size_t i = 1; i < strs.size(); i++) {
        if (strs[i].length() < shortestStringLength) {
            shortestStringLength = strs[i].length();
        }
    }
    const string& curr = strs[0];

    for (size_t i = 0; i < shortestStringLength; i++) {
        char curr_letter = curr[i];
        for (const string& str : strs) {
            if (str[i] != curr_letter) {
                return result;
            }
        }
        result += curr_letter;
    }
    return result;
}

ValidParentheses::ValidParentheses() : Problem(20, "ValidParentheses",
"Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.\n", Difficulty::Easy) { }

bool ValidParentheses::Solution(const string &s) {
    std::stack<char> stack;
    for (size_t i = 0; i < s.length(); i++) {
        if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
            stack.push(s[i]);
        } else if (!stack.empty() && stack.top() == '(' && s[i] == ')') {
            stack.pop();
        } else if (!stack.empty() && stack.top() == '[' && s[i] == ']') {
            stack.pop();
        } else if (!stack.empty() && stack.top() == '{' && s[i] == '}') {
            stack.pop();
        } else {
            return false;
        }
    }
    return stack.empty();
}

MergeTwoSortedLists::MergeTwoSortedLists() : Problem(21, "MergeTwoSortedLists",
"You are given the heads of two sorted linked lists list1 and list2.\n"
"Merge the two lists into one sorted list. The list should be made by splicing together the nodes of the first two lists.\n"
"Return the head of the merged linked list.\n", Difficulty::Easy) { }

MergeTwoSortedLists::ListNode *MergeTwoSortedLists::Solution(ListNode *list1, ListNode *list2) {
    ListNode dummy;                 //In order to use given nodes and not create new ones
    ListNode* current = &dummy;
    while (list1 && list2) {
        if (list1->val < list2->val) {
            current->next = list1;
            list1 = list1->next;
        } else {
            current->next = list2;
            list2 = list2->next;
        }
    }
    if (list1) {
        current->next = list1;
    } else {
        current->next = list2;
    }
    return dummy.next;
}


RemoveDuplicatesFromSortedArray::RemoveDuplicatesFromSortedArray() :Problem(26, "RemoveDuplicatesFromSortedArray",
"Given an integer array nums sorted in non-decreasing order, remove the duplicates in-place such that each unique element appears only once.\n"
"The relative order of the elements should be kept the same. Then return the number of unique elements in nums.\n"
"Consider the number of unique elements of nums to be k, to get accepted, you need to do the following things:\n"
"Change the array nums such that the first k elements of nums contain the unique elements in the order they were present in nums initially.\n"
"The remaining elements of nums are not important as well as the size of nums.\n"
"Return k.\n",Difficulty::Easy){ }

int RemoveDuplicatesFromSortedArray::Solution(vector<int> &nums) {
    if (nums.empty()) {
        return 0;
    }
    int currentMax = nums[0];
    int result = 1;
    int current = 1;
    while (current < nums.size()) {
        if (nums[current] > currentMax) {
            int temp = nums[result];
            nums[result] = nums[current];
            nums[current] = temp;
            currentMax = nums[result];
            result++;
        }
        else {
            current++;
        }
    }
    return result;
}

RemoveElement::RemoveElement() :Problem(27, "RemoveElement","Given an integer array nums and an integer val, remove all occurrences of val in nums in-place.\n"
                                                            "The order of the elements may be changed. Then return the number of elements in nums which are not equal to val.\n"
                                                            "Consider the number of elements in nums which are not equal to val be k, to get accepted, you need to do the following things:\n"
                                                            "Change the array nums such that the first k elements of nums contain the elements which are not equal to val.\n"
                                                            "The remaining elements of nums are not important as well as the size of nums.\n"
                                                            "Return k.\n", Difficulty::Easy) { }

int RemoveElement::Solution(vector<int> &nums, int val) {
    if (nums.empty()) {
        return 0;
    }
    int i = 0;
    int k = nums.size()-1;
    while (i < k) {
        if (nums[i] == val) {
            nums[i] = nums[k];
            k--;
        } else {
            i++;
        }
    }
    return k;
}

LengthOfLastWord::LengthOfLastWord() :Problem(58, "LengthOfLastWord", "Given a string s consisting of words and spaces, return the length of the last word in the string.\n"
"A word is a maximal substring consisting of non-space characters only.\n",Difficulty::Easy){ }

int LengthOfLastWord::Solution(string s) {
    int i = s.size()-1;
    while (i >= 0 && s[i] == ' ') {
        i--;
    }
    int counter = 0;
    if (i < 0) {
        return 0;
    }
    while (i >= 0 && s[i] != ' ') {
        i--;
        counter++;
    }
    return counter;
}

PlusOne::PlusOne() : Problem(66,"PlusOne", "You are given a large integer represented as an integer array digits, where each digits[i] is the ith digit of the integer.\n"
    "The digits are ordered from most significant to least significant in left-to-right order. The large integer does not contain any leading 0's.\n"
"Increment the large integer by one and return the resulting array of digits.\n", Difficulty::Easy){ }

vector<int> PlusOne::Solution(vector<int> &digits) {
    int i = digits.size() - 1;
    while (i >= 0 && digits[i] == 9) {
        i--;
    }
    if (i >= 0) {
        digits[i++]++;
        while (i < digits.size()) {
            digits[i] = 0;
            i++;
        }
        return digits;
    }
    for (int k = 0; k < digits.size(); k++) {
        digits[k] = 0;
    }
    digits.insert(digits.begin(), 1);
    digits.push_back(0);
    return digits;
}

vector<int> PlusOne::anotherSolution(vector<int> &digits) {
    for (int i = digits.size() - 1; i >= 0; i--) {
        if (digits[i] < 9) {
            digits[i]++;
            return digits;
        }
        digits[i] = 0;
    }
    digits.insert(digits.begin(), 1);
    return digits;
}

AddBinary::AddBinary() : Problem(67,"AddBinary", "Given two binary strings a and b, return their sum as a binary string.\n"
    Difficulty::Easy) { }

string AddBinary::Solution(string a, string b) {
    if (a.length() > b.length()) {
        b = string(a.length() - b.length(), '0') + b;
    } else if (b.length() > a.length()) {
        a = string(b.length() - a.length(), '0') + a;
    }
    int carry = 0;
    string sum = '';
    for (int i = a.length() - 1; i >= 0; i--) {
        int a_digit = a[i] - '0';
        int b_digit = b[i] - '0';
        int sum_digit = a_digit + b_digit + carry;
        sum.push_back(sum_digit % 2 + '0');
        carry = sum_digit / 2;
    }
    if (carry == 1) {
        sum.push_back('1');
    }
    sum.reserve();
    return sum;
}

SqrtX::SqrtX() : Problem(69, "Sqrt(x)", "Given a non-negative integer x, return the square root of x rounded down to the nearest integer.\n"
                                        "The returned integer should be non-negative as well.", Difficulty::Easy) { }

int SqrtX::Solution(int x) {
    for (int i = 0; i < x / 2; i++) {
        if (i*i == x) {
            return i;
        }
        if (i*i > x) {
            return i - 1;
        }
    }
}

int SqrtX::betterSolution(int x) {
    if (x < 2) {
        return x;
    }
    if (x < 4) {
        return 1;
    }
    int top = x / 2;
    int bottom = 0;
    int current = (top + bottom) / 2;
    while (top > bottom + 1) {
        if (current * current > x) {
            top = current;
            current = (bottom + top) / 2;
        } else if (current * current < x) {
            bottom = current;
            current = (bottom + top) / 2;
        } else {
            return current;
        }
    }
    return current;
}







