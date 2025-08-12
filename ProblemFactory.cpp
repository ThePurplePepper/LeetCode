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
}