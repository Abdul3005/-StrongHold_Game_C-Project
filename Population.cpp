#include "Stronghold.h"
#include<iostream>

using namespace std;

Population::Population(int t)
{
	total = t;
	deaths = 0;
	births = 0;
	ill = 0;
}



void Population::updatePop(const Resources& res, int shelter) {
    int foodSupply = res.getFood(); 
    if (foodSupply < total) {
        ill = (total - foodSupply) / 10;
		deaths = (total - foodSupply) / 20;
		total -= deaths;
	}
	else
	{
		deaths = 0;
		ill = 0;
	}
	if (shelterCapacity < total / 2)
		births = shelterCapacity / 20;
	else
		births = shelterCapacity / 10;

	total += births;
	total = max(0, total);
}

bool Population::isStable()
{
	return ill < total / 10 && deaths < total / 25;
}

void Population::displayPop() const
{
	cout << "Total Population: " << total << endl;
	cout << "Births: " << births << ", Ill: " << ill << ", Deaths: " << deaths << endl;
}