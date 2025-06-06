#include "Stronghold.h"

using namespace std;

Economy::Economy(float initialGold) : treasury(initialGold), taxRate(0.15f), inflation(0.02f) {}

void Economy::collectTaxes(const Population& pop, const Peasant& peasants,const Merchant& merchants) { 
    
    if (taxRate < 0) taxRate = 0;
    if (taxRate > 0.5f) taxRate = 0.5f;

    float peasantTax = peasants.getPopulation() * taxRate * 0.5f;  
    float merchantTax = merchants.getPopulation() * taxRate * 2.0f; 
    treasury += peasantTax + merchantTax;
    inflation += 0.005f; 
}

void Economy::payArmy(Army& army) {
    int salaryNeeded = army.getTrainedSoldiers() * 3;
    if (treasury >= salaryNeeded) {
        treasury -= salaryNeeded;
        army.pay(salaryNeeded);
    } else {
        army.pay(0);
    }
}

void Economy::adjustTreasury(int amount) {
    treasury += amount;
}

void Economy::adjustTaxRate(float newRate) {
    taxRate = (newRate < 0) ? 0 : (newRate > 0.5f) ? 0.5f : newRate;
}

void Economy::applyInflation() {
    treasury *= (1.0f - inflation);
}

void Economy::displayEconomy() const {
    cout << "\n=== ECONOMY STATUS ===" << endl;
    cout << "Treasury: " << treasury << " gold" << endl;
    cout << "Tax Rate: " << (taxRate * 100) << "%" << endl;
    cout << "Inflation: " << (inflation * 100) << "%\n" << endl;
}