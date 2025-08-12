#include <iostream>
#include "Problem.h"
#include "ProblemFactory.h"


using namespace std;
int main() {
    ProblemFactory factory;
    registerAllProblems(factory);

    unsigned int id;
    cout << "Enter problem ID" << endl;
    cin >> id;

    auto problem = factory.createProblem(id);
    if (problem) {

    } else {
        cout << "Problem not solved yet" << endl;
    }
    return 0;
}
