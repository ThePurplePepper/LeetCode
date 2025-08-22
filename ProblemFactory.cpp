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
    factory.registerProblem(66, []() { return make_unique<PlusOne>(); });
    factory.registerProblem(67, []() { return make_unique<AddBinary>(); });
    factory.registerProblem(69, []() { return make_unique<SqrtX>(); });
    factory.registerProblem(83, []() { return make_unique<RemoveDuplicatesFromSortedList>(); });
    factory.registerProblem(88, []() { return make_unique<MergeSortedArray>(); });
    factory.registerProblem(94, []() { return make_unique<BinaryTreeInorderTraversal>(); });
    factory.registerProblem(100, []() { return make_unique<SameTree>(); });
    factory.registerProblem(101, []() { return make_unique<SymmetricTree>(); });
    factory.registerProblem(104, []() { return make_unique<MaximumDepthOfBinaryTree>(); });
}