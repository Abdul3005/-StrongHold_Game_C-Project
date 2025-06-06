#include "Stronghold.h"

using namespace std;

Leadership::Leadership(string name) : rulerName(name), isStable(true) {}

void Leadership::attemptCoup(const Army& army) {
    if (army.getMorale() < 40 || army.getCorruption() > 60) {
        isStable = false;
        cout << "\n⚔️ COUP! " << rulerName << " has been overthrown!\n";
    } else {
        isStable = true;
    }
}

void Leadership::displayLeadership() const {
    cout << "\n=== LEADERSHIP ===" << endl;
    cout << "Ruler: " << rulerName << endl;
    cout << "Stability: " << (isStable ? "Stable" : "Collapsing") << endl;
}

bool Leadership::getStability() const {
    return isStable;
}