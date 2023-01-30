#include <iostream>
#include <string>
#include <vector>
#include <random>
#include <algorithm>
#include <chrono>
#include <ctime>			
#include <cstdlib>

#include "Card.h"
#include "Player.h"

using namespace std;

int myrandom(int i) { return rand() % i; }
void shuffleCards(vector<Card*> &deck);


int main() {

	//create players inside a vector
	vector<Player*> players;
	players.push_back(new HumanPlayer());
	players.push_back(new ComputerPlayer());

	//opponent pointers
	players[0]->opponent = players[1];
	players[1]->opponent = players[0];

	///// print info about cards:
	cout << "____CARD GAME___" << endl;
	cout << "Cards and Description:  " << endl;

	players[0]->printDeck();

	srand(unsigned(time(0))); //with this every time is different random shuffle

	//shuffle cards
	shuffleCards(players[0]->deck);
	shuffleCards(players[1]->deck);


	/////print deck of player[0], but it will not be printed when playing
	//cout << "print deck: " << players[0]->name << endl ;
	//players[0]->printDeck();

	cout << endl << endl;

	//alternate players turns with a counter which is incremented at the end of each turn. Even numbers: Player. Odd numbers: Computer.
	int counter = 0;

	while (!players[0]->hasLost() && !players[1]->hasLost()) {

		if (counter % 2 == 0) {
			cout << endl;
			cout << "//// Player's turn: ////  #" << counter+1 << endl; 
			//if the last card in discard pile is Refresh, shuffle cards. But it will work also the next turn if the player doesn't play any cards.
			//it doesnt work on the same turn when this card is played, but it will done before the beginning of the next turn.
			if (players[0]->discardPile.size() > 0) {
				if (players[0]->discardPile.back()->getName() == "Refresh") {
					shuffleCards(players[0]->discardPile);
				}
			}

			//play turn
			players[0]->myTurn();

			
		}
		else {
			//if counter is an odd number. It's Opponent's turn.
			cout << endl;
			cout << "//// Opponent's turn: ////  #" << counter+1 << endl;

			if (players[1]->discardPile.size() > 0) {
				if (players[1]->discardPile.back()->getName() == "Refresh") {
					shuffleCards(players[1]->discardPile);
				}
			}

			//play opponent's turn
			players[1]->myTurn();

		}
		counter++;
	}

	//check if player has lost and display messages. Check if he lost because of health<=0 or deck.size() <= 0.
	if (players[0]->hasLost()) {
		cout << "You Lost!" << endl;
		if (players[0]->health <= 0) {
			cout << "Your health : 0";
		}
		else if (players[0]->deck.size() <= 0) {
			cout << "Your deck is empty.";
		}
	}
	else {
		cout << "You WON!!!" << endl;
		if (players[1]->health <= 0) {
			cout << "Opponent's health : 0";
		}
		else if (players[1]->deck.size() <= 0) {
			cout << "Opponent's deck is empty.";
		}
	}


	


	return 0;
}


void shuffleCards(vector<Card*>& deck) {
	//shuffle player's deck
	random_shuffle(deck.begin(), deck.end(), myrandom);  
}
