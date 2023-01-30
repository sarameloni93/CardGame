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

class Card;

class Player
{
private: 



public:
	string name;
	int health;

	//player constructor
	Player() {	};

	//pointer to the other player - opponent
	Player* opponent = NULL;

	vector <Card*> deck = createDeck(); //PainfulLesson, Spite, FullHeal, Switcheroo, Refresh, Peek { 5,6,1,2,2,4 }
	vector <Card*> hand;
	vector <Card*> discardPile;

	vector <Card*> createDeck() {
		vector <Card*> cardDeck;

		for (int i = 0; i < 5; i++) {
			cardDeck.push_back(new PainfulLesson());
		}
		

		for (int i = 0; i < 6; i++) {
			cardDeck.push_back(new Spite());
		}

		for (int i = 0; i < 1; i++) {
			cardDeck.push_back(new FullHeal());
		}

		for (int i = 0; i < 2; i++) {
			cardDeck.push_back(new Switcheroo());
		}

		for (int i = 0; i < 2; i++) {
			cardDeck.push_back(new Refresh());
		}

		for (int i = 0; i < 4; i++) {
			cardDeck.push_back(new Peek());
		}

		return cardDeck;
		
	}

	void printDeck();
	

	void printHand();

	void printDiscard();
		
	void printInfoPlayer();

	void printInfoComputer();

	void loseHealth(int i);

	bool drawCard();

	void playCard(Card* c);

	virtual void myTurn() {	}

	bool hasLost();
};

class HumanPlayer : public Player
{
private:

public:
	HumanPlayer() {
		name = "Player";
		health = 20;
	}

	void myTurn();
};

class ComputerPlayer : public Player
{
public:
	ComputerPlayer() {
		name = "Computer";
		health = 20;
	}


	void myTurn();

};