#include "ProblemFactory.h"

void ProblemFactory::registerProblem(unsigned int ID, ProblemFactoryFunc func) {
    registry[ID] = func;
}

unique_ptr<Problem> ProblemFactory::createProblem(unsigned int ID) const {
    auto it = registry.find(ID);
    if (it != registry.end()) {
        return it->second();
    }
    return nullptr;
}

void registerAllProblems(ProblemFactory &factory) {
    factory.registerProblem(1, []() { return make_unique<TwoSum>(); });
    factory.registerProblem(9, []() { return make_unique<PalindromeNumber>(); });
    factory.registerProblem(13, []() { return make_unique<RomanToInteger>(); });
    factory.registerProblem(14, []() { return make_unique<LongestCommonPrefix>(); });
    factory.registerProblem(20, []() { return make_unique<ValidParentheses>(); });
    factory.registerProblem(21, []() { return make_unique<MergeTwoSortedLists>(); });
    factory.registerProblem(26, []() { return make_unique<RemoveDuplicatesFromSortedArray>(); });
    factory.registerProblem(27, []() { return make_unique<RemoveElement>(); });
    factory.registerProblem(58, []() { return make_unique<LengthOfLastWord>(); });
}