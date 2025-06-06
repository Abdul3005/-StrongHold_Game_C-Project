#pragma once
#include<iostream>
#include<memory> 
#include<string>
#include <fstream>
#include <cmath>
#include <windows.h>

using namespace std;

class SocialClass {
	protected:
		string typeName;
		int population;  
		float happiness;
	public:  
		SocialClass(string n, int pop);
		void setPopulation(int pop) { population = pop; } 
		int getPopulation() const;
		void setHappiness(float h) { happiness = h; }
		float getHappiness() const { return happiness; }
		void display() const;
	};

class Peasant : public SocialClass
{
public:
	Peasant(int pop);
	void updatePeasant();
};

class Noble : public SocialClass
{
public:
	Noble(int pop);
	void updateNoble();
};

class Merchant : public SocialClass
{
public:
	Merchant(int pop);
	void updateMerchant();
};

class Resources {
private:
	int food;
	int wood;
	int stone;
	int iron;
public:
	Resources(int f, int w, int s, int i);
	bool consumeFood(int amount);
	void gatherFood(int amount);
	bool consumeWood(int amount);
	void gatherWood(int amount);
	void gatherStone(int amount);
	void gatherIron(int amount);
	bool consumeStone(int amount);
	bool consumeIron(int amount);
	void processSpoilage();
	void displayResources() const;

	void setFood(int f) { food = f; }
	void setWood(int w) { wood = w; }
	void setStone(int s) { stone = s; }
	void setIron(int i) { iron = i; }

	int getFood() const { return food; }
	int getWood() const { return wood; }
	int getStone() const { return stone; }   
	int getIron() const { return iron; }     
};

class Population
{
protected:
	int total, ill, births, deaths;
	int shelterCapacity;

public:
	Population(int t);
	void updatePop(const Resources& res, int shelter);
	void displayPop() const;
	bool isStable();

    void setTotal(int t) { total = t; }
    void setIll(int i) { ill = i; }
    void setBirths(int b) { births = b; }
    void setDeaths(int d) { deaths = d; }

	int getShelter() const { return shelterCapacity; }

	void setShelter(int s) { shelterCapacity = s; }
	int getTotal() const { return total; }
	int getIll() const { return ill; }
	int getBirths() const { return births; }
	int getDeaths() const { return deaths; }
};

class Army
{
protected:
	int recruit;
	int morale, corruption, trainedSoldiers, foodStock, salaryFund;
public:
	Army(int rec, int food, int gold);
	void recruitt(int newRecruit);
	void train(int days);
	void basicFeed(Resources& res);
	void manualFeed(Resources& res);
	void pay(int gold);
	void updateMorale(bool StableLeadership);
	void displayArmy() const;

	void setRecruits(int r) { recruit = r; }
    void setMorale(int m) { morale = m; }
    void setCorruption(int c) { corruption = c; }
    void setTrainedSoldiers(int t) { trainedSoldiers = t; }
    void setFoodStock(int f) { foodStock = f; }
    void setSalaryFund(int s) { salaryFund = s; }

	int getMorale() const;
	int getCorruption() const;
	int getRecruits() const { return recruit; }
	int getTrainedSoldiers() const;
	int getFoodStock() const { return foodStock; }
    int getSalaryFund() const { return salaryFund; }
};

class Economy {
	private:
		float treasury;
		float taxRate;
		float inflation;
	public:
		Economy(float initialGold);
		void collectTaxes(const Population& pop, const Peasant& peasants, const Merchant& merchants);  
		void payArmy(Army& army); 
		void adjustTaxRate(float newRate);
		void adjustTreasury(int amount);
		void applyInflation();
		void displayEconomy() const;

		void setTreasury(float t) { treasury = t; }
        void setTaxRate(float tr) { taxRate = tr; }
        void setInflation(float inf) { inflation = inf; }

		float getTaxRate() const { return taxRate; }
		float getTreasury() const { return treasury; }
        float getInflation() const { return inflation; }
	};

class Leadership {
	private:
		string rulerName;
		bool isStable;
	public:
		Leadership(string name);
		void attemptCoup(const Army& army);
		void displayLeadership() const;

		void setStability(bool s) { isStable = s; }
		bool getStability() const;
	};

class Bank {
	private:
		float interestRate;
		float corruptionLevel;
		float loanDebt;
	public:
		Bank();
		void takeLoan(Economy& economy, float amount);
		void repayLoan(Economy& economy, float amount);
		void processInterest();
		void conductAudit(Economy& economy);
		void commitFraud(Economy& economy);
		void displayBank() const;
	};

enum class EventType {
	NONE, FAMINE, PLAGUE, FLOOD, TORNADO,
	ECONOMIC_CRISIS, CORRUPTION_SCANDAL, REVOLT
};

class KingdomEvent {
private:
	time_t lastTrigger;
	int intervalMinutes;  
	EventType lastEvent;

public:
	KingdomEvent(int minutes);
	time_t getLastTrigger() const { return lastTrigger; }
	int getIntervalMinutes() const { return intervalMinutes; }
	EventType getLastEvent() const { return lastEvent; }
	void setLastTrigger(time_t lt) { lastTrigger = lt; }
	void setIntervalMinutes(int im) { intervalMinutes = im; }
	void setLastEvent(EventType le) { lastEvent = le; }

	bool shouldTrigger();
	EventType getRandomEvent() const;
	void executeEvent(EventType type, Population& pop, Army& army,
		Economy& econ, Resources& res,
		Peasant& p, Merchant& m, Noble& n);
	void applyEffects(EventType type, Population& pop, Army& army,
		Economy& econ, Resources& res, Peasant& p,
		Merchant& m, Noble& n);
};

class GameState {
private:
	const std::string SAVE_FILE = "stronghold_save.txt";

public:
	void saveGame(const Economy& econ, const Army& army, const Population& pop,
		const Resources& res, const Leadership& lead, const Peasant& p,
		const Merchant& m, const Noble& n, const KingdomEvent& events);

	bool loadGame(Economy& econ, Army& army, Population& pop,
		Resources& res, Leadership& lead, Peasant& p,
		Merchant& m, Noble& n, KingdomEvent& events);
};