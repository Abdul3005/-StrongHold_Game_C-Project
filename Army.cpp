#include "Stronghold.h"
#include <iostream>

using namespace std;

Army::Army(int rec, int food, int gold)
{
	recruit = rec;
	foodStock = food;
	salaryFund = gold;
	trainedSoldiers = 15;
	corruption = 0;
	morale = 70; 
}

void Army::recruitt(int newRecruit)
{
	recruit += newRecruit;
	morale -= 2; 
	if (morale < 0)
		morale = 0;
}


void Army::train(int days)
{
	int newtrained = recruit * days / 20;
	if (newtrained > recruit)
		newtrained = recruit;
	trainedSoldiers += newtrained;
	recruit -= newtrained;
	morale += days / 2;
	if (morale > 100)
		morale = 100;
}

void Army::basicFeed(Resources& res) {
	int requireFood = trainedSoldiers + recruit;
	if (res.consumeFood(requireFood)) {
		morale += 5;
	}
	else {
		morale -= 10;
	}
	morale = max(0, min(100, morale));
}

void Army::manualFeed(Resources& res) {
	cout << "\n=== MANUAL ARMY FEEDING ===";
	cout << "\nAvailable food: " << res.getFood();
	cout << "\nTotal soldiers: " << (trainedSoldiers + recruit);
	cout << "\nEnter food amount to use: ";

	int foodAmount;
	cin >> foodAmount;

	if (res.consumeFood(foodAmount)) {
		int required = trainedSoldiers + recruit;
		if (foodAmount >= required * 2) {
			morale += 10;  
		}
		else if (foodAmount >= required) {
			morale += 5;   
		}
		else {
			morale -= 5;   
		}
		cout << "Fed army with " << foodAmount << " food units!\n";
	}
	else {
		cout << "Not enough food!\n";
		morale -= 15;
	}

	morale = max(0, min(100, morale));
}

void Army::pay(int gold)
{
	salaryFund += gold;
	int requireFund = trainedSoldiers * 3;
	if (salaryFund > requireFund)
	{
		salaryFund -= requireFund;
		morale += 10;
		corruption -= 5;
	}
	else
	{
		morale -= 13;
		corruption += 10;
	}

	if (morale > 100)
		morale = 100;
	if (morale < 0)
		morale = 0;
	if (corruption > 100)
		corruption = 100;
	if (corruption < 0)
		corruption = 0;
}

int Army::getMorale() const {
    return morale;
}

int Army::getCorruption() const {
    return corruption;
}

void Army::updateMorale(bool stableLeadership)
{
	if (stableLeadership)
	{
		morale += 5;
		corruption -= 5;
	}
	else
	{
		morale -= 8;
		corruption += 7;
	}

	if (morale > 100)
		morale = 100;
	if (morale < 0)
		morale = 0;
	if (corruption > 100)
		corruption = 100;
	if (corruption < 0)
		corruption = 0;
}

int Army::getTrainedSoldiers() const {
    return trainedSoldiers;
}

void Army::displayArmy() const {
	cout << "Recruits: " << recruit << endl;
	cout << "Trained Soldiers: " << trainedSoldiers << endl;
	cout << "Total Soldiers: " << (recruit + trainedSoldiers) << "\n";
	cout << "Morale: " << morale << "%\n";
	cout << "Corruption: " << corruption << "%\n";
	cout << "Food Stock: " << foodStock << "\n";
	cout << "Salary Fund: " << salaryFund << " gold\n";
}