#include "Stronghold.h"
#include <iostream>

using namespace std;

Bank::Bank() : interestRate(0.1f), corruptionLevel(0.0f), loanDebt(0.0f) {}

void Bank::takeLoan(Economy& economy, float amount) {
    if (amount > 0 && loanDebt == 0) {
        economy.adjustTaxRate(economy.getTaxRate() + 0.02f); 
        economy.applyInflation();
        loanDebt = amount * 1.2f; 
        economy.adjustTreasury(static_cast<int>(amount)); 
        corruptionLevel += 5.0f;
    }
}

void Bank::repayLoan(Economy& economy, float amount) {
    if (amount >= loanDebt) {
        economy.adjustTaxRate(economy.getTaxRate() - 0.02f);
        loanDebt = 0;
    } else {
        loanDebt -= amount;
        corruptionLevel -= 2.0f;
    }
    if (corruptionLevel < 0) corruptionLevel = 0;
}

void Bank::processInterest() {
    loanDebt *= (1.0f + interestRate); 
    corruptionLevel += 1.0f;
}

void Bank::conductAudit(Economy& economy) {
    if (corruptionLevel > 30.0f) {
        economy.adjustTreasury(-500);
        corruptionLevel *= 0.5f; 
    }
}

void Bank::commitFraud(Economy& economy) {
    if (corruptionLevel > 20.0f) {
        economy.adjustTreasury(1000); 
        corruptionLevel += 15.0f;
    }
}

void Bank::displayBank() const {
    cout << "\n=== BANK SYSTEM ===" << endl;
    cout << "Active Loan: " << loanDebt << " gold\n";
    cout << "Interest Rate: " << (interestRate * 100) << "%\n";
    cout << "Corruption Level: " << corruptionLevel << "%\n";
}