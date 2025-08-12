#pragma once
#include <iostream>

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
    Difficulty getDifficulty();
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