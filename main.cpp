#include <iostream>
#include <limits>

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
        if (!cin) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input\n";
            continue;
        }

        auto problem = factory.createProblem(id);
        if (problem) {
            cout << "Problem ID: " << problem->getID() << endl;
            cout << "Problem's Name: " << problem->getProblemName() << endl;
            cout << "Problem's Difficulty: " << problem->getDifficulty() << endl;
            cout << "Problem's Description: " << problem->getDescription() << endl;
        } else {
            cout << "Problem not solved yet" << endl;
        }

        do {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
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
