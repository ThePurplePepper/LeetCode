#pragma once
#include "Problem.h"
#include <functional>
#include <map>
#include <memory>

using ProblemFactoryFunc = function<unique_ptr<Problem>()>;
class ProblemFactory {
    map<unsigned int, ProblemFactoryFunc> registry;
public:
    void registerProblem(unsigned int ID, ProblemFactoryFunc func);
    unique_ptr<Problem> createProblem(unsigned int ID) const;
};

void registerAllProblems(ProblemFactory& factory);
