#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <random>
#include <algorithm>
#include <chrono>
#include <ctime>			
#include <cstdlib>

using namespace std;

class Player;

class Card
{
private: 
	string name;

public: 
	string description;
	
	//constructor
	Card() : name("Default") {}

	void setName(string n) {
		name = n;
	}

	//virtual methods
	virtual string getName() {
		return name;
	}

	virtual void effect(Player* p) {	}

};

class PainfulLesson : public Card
{
private:
	string name = "Painful Lesson";
	int damage = 2;

public:
	PainfulLesson() {
		string n = name;
		description = "( Opponent loses 2 health and draws a card )";
	}

	string getName() {
		return name;
	}

	virtual void effect(Player* p);
};

class Spite : public Card
{
private:
	string name = "Spite";
	int damage = 1;


public:
	Spite() {
		string n = name;
		description = "( Both players lose 1 health )";
	}


	string getName() {
		return name;
	}

	virtual void effect(Player* p);	
};

class FullHeal : public Card
{
private:
	string name = "Full Heal";

public:
	FullHeal(){
		string n = name;
		description = "( Restores your health back to 20 )";
	}

	string getName() {
		return name;
	}

	virtual void effect(Player* p);
};

class Switcheroo : public Card
{
private:
	string name = "Switcheroo";

public:
	Switcheroo() {
		string n = name;
		description = "( Swaps the contents of your hand with your opponent's )";
	}

	string getName() {
		return name;
	}

	virtual void effect(Player* p);
};

class Refresh : public Card
{
private:
	string name = "Refresh";
	int damage = 3;

public:
	Refresh() {
		string n = name;
		description = "( Lose 3 health and shuffle your discard pile back into your deck )";
	}

	string getName() {
		return name;
	}

	virtual void effect(Player* p);
};

class Peek : public Card
{
private:
	string name = "Peek";

public:
	Peek() {
		string n = name;
		description = "( Look at the top cards of both players decks )";
	}

	string getName() {
		return name;
	}

	virtual void effect(Player* p);
};


