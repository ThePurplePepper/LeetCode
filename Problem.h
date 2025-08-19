#pragma once
#include <iostream>
#include <vector>

using namespace std;

enum class Difficulty {
    Easy,
    Medium,
    Hard
};

class Problem {
    unsigned int ID;
    string problemName;
    string description;
    Difficulty difficulty;
public:
    Problem(unsigned int ID, const string& name, const string& desc, Difficulty difficulty);
    virtual ~Problem();
    unsigned int getID();
    string getProblemName();
    string getDifficulty();
    string getDescription();
};

class TwoSum : public Problem {
public:
    TwoSum();
    void Solution(int* arr, int target, int len, int output[2]);
    void anotherSolution(int* arr, int target, int len, int output[2]);
};

class PalindromeNumber : public Problem {
public:
    PalindromeNumber();
    bool Solution(int x);
};

class RomanToInteger : public Problem {
public:
    RomanToInteger();
    int Solution(const string& s);
    int anotherSolution(const string& s);
    int bestSolution(const string& s);
};

class LongestCommonPrefix : public Problem {
public:
    LongestCommonPrefix();
    string Solution(vector<string>& strs);
};

class ValidParentheses : public Problem {
public:
    ValidParentheses();
    bool Solution(const string& s);
};

class MergeTwoSortedLists : public Problem {
public:
    struct ListNode {
        int val;
        ListNode *next;
        ListNode() : val(0), next(nullptr) {}
        ListNode(int x) : val(x), next(nullptr) {}
        ListNode(int x, ListNode *next) : val(x), next(next) {}
    };

    MergeTwoSortedLists();
    ListNode* Solution(ListNode* list1, ListNode* list2);
};

class RemoveDuplicatesFromSortedArray : public  Problem {
public:
    RemoveDuplicatesFromSortedArray();
    int Solution(vector<int>& nums);
};

class RemoveElement : public Problem {
public:
    RemoveElement();
    int Solution(vector<int>& nums, int val);
};

class LengthOfLastWord : public Problem {
public:
    LengthOfLastWord();
    int Solution(string s);
};

class PlusOne : public Problem {
public:
    PlusOne();
    vector<int> Solution(vector<int>& digits);
    vector<int> anotherSolution(vector<int>& digits);
};

class AddBinary : public Problem {
    AddBinary();
    string Solution(string a, string b);
};

class SqrtX : public Problem {
    SqrtX();
    int Solution(int x);
    int betterSolution(int x);
};