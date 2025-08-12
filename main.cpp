#include <iostream>
#include "Problem.h"
#include "ProblemFactory.h"


using namespace std;
int main() {
    ProblemFactory factory;
    registerAllProblems(factory);
    bool exit = true;
    string exitStatus;

    while (exit) {
        unsigned int id = 0;
        cout << "Enter problem ID" << endl;
        cin >> id;

        auto problem = factory.createProblem(id);
        if (problem) {
            cout << "";
        } else {
            cout << "Problem not solved yet" << endl;
        }

        do {
            cout << "Continue? [Y/N]" << endl;
            cin >> exitStatus;
            if (exitStatus == "n" || exitStatus == "N") {
                cout << "See you next time!" << endl;
                exit = false;
                break;
            } if (exitStatus != "y" && exitStatus != "Y") {
                cout << "I didn't quite catch that..." << endl;
            }
        } while (exitStatus != "y" && exitStatus != "Y");

    }

    return 0;
}
