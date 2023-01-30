
#include "Card.h"
#include "Player.h"

void Player::printDeck() {
	//print player's deck with name of cards and their description
	int j = 0;

	for (Card* i : deck) {
		cout << j << " " << i->getName() << " " << i->description << endl;
		j++;
	}
}

void Player::printHand() {
	//print hand
	int j = 0;
	for (Card* i : hand) {
		cout << j << " " << i->getName() << ", ";
		//cout << i->description << endl;
		j++;
	}
	cout << endl;
}

void Player::printDiscard() {
	//print discard pile
	int j = 0;
	for (Card* i : discardPile) {
		cout << j << " " << i->getName() << ", ";
		j++;
	}
	cout << endl;
}

void Player::printInfoPlayer() {
	//print player's info. health, hand, discard, deck's size
	cout << "------------------------------" << endl;
	cout << "Health: " << health << endl;

	cout << "Hand: ";
	printHand();

	cout << "Discard Pile: ";
	printDiscard();

	cout << "Deck's size: " << deck.size() << endl;
	cout << "------------------------------" << endl;

}

void Player::printInfoComputer() {
	//print opponent's info. only health and deck's size
	cout << "------------------------------" << endl;
	cout << "Health: " << health << endl;

	//cout << "Hand: ";
	//printHand();

	//cout << "Discard Pile: ";
	//printDiscard();

	cout << "Deck's size: " << deck.size() << endl;
	cout << "------------------------------" << endl;

}

void Player::loseHealth(int i) {
	health -= i; //lose the i amount of health
}
	
bool Player::drawCard() {
	//try to add the top card from the deck to the hand. if deck is empty, returns false
	if (deck.size() <= 0) {
		return false;
	}
	else {
		return true;
	}
}

void Player::playCard(Card* c) {
	//play a card, apply his effects

	cout << endl;
	cout << opponent->opponent->name << " decided to play: " << c->getName() << endl;  //you/opponent decided to play:
	cout << endl;

	//apply effect
	c->effect(opponent);

}

bool Player::hasLost() {
	//check if the player has lost
	//if health <= 0 or drawCard() return false
	if (!drawCard() || health <= 0)
		return true;
	else return false;

}

void HumanPlayer::myTurn() {

	//draw a card
	if (drawCard()) {
		//add the first card on the deck to the hand
		hand.push_back(deck.back());
		deck.pop_back();
	}

	//print info about player
	printInfoPlayer();

	//check how many cards left 
	if (hand.size() > 5) {
		//if player has more than 5 cards, he needs to play a card

		int indexC;
		cout << "Which card do you want to play?" << endl;
		cin >> indexC;
		//check if user wants to play a valid card, if not ask again until indexC is one of the indexes of hand
		while (indexC < 0 || indexC > hand.size() - 1) {
			cout << "Which card do you want to play?" << endl;
			cin >> indexC;
		}

		cout << "." << endl << "." << endl << "." << endl << "." << endl << "." << endl << "." << endl;

		//if player wants to play switcheroo, i need to assign this card to a variable, so i can add it to discard pile and erase it from the hand before applying its effects
		if (hand[indexC]->getName() == "Switcheroo") {
			Card* switcherooCard = hand[indexC];
			discardPile.push_back(hand[indexC]);
			hand.erase(hand.begin() + indexC);
			playCard(switcherooCard);
		}
		else {   
			//if i am playing any other cards:
			
			//play a card applying its effects
			playCard(hand[indexC]);

			//move it to discard
			discardPile.push_back(hand[indexC]);

			//erase it after moving the card to discard (if i do it before i can't move it to discard pile)
			hand.erase(hand.begin() + indexC);
		}

		cout << endl;
	}

	//if player had less than 5 but more than 0 cards, ask if he wants to play a card or end their turn
	else if (hand.size() > 0) {
		int wantToPlay = 0;
		cout << "Do you want to play a card? (yes = 1, no = 0)" << endl;
		cin >> wantToPlay;
		//check if player entered 0 or 1. if not continue asking until he does
		while (wantToPlay < 0 || wantToPlay > 1) {
			cout << "Do you want to play a card? (yes = 1, no = 0)" << endl;
			cin >> wantToPlay;
		}

		cout << "." << endl << "." << endl << "." << endl << "." << endl << "." << endl << endl;

		//if player wants to play, ask which card
		if (wantToPlay) {
			int indexC = -1;
			cout << "Which card do you want to play?" << endl;
			cin >> indexC;

			//check if card is valid
			while (indexC < 0 || indexC > hand.size() - 1) {
				cout << "Which card do you want to play?" << endl;
				cin >> indexC;
			}

			cout << "." << endl << "." << endl << "." << endl << "." << endl << "." << endl << endl;

			//if player wants to play switcheroo, i need to assign this card to a variable, so i can add it to discard pile and erase it from the hand before applying its effects
			if (hand[indexC]->getName() == "Switcheroo") {
				Card* switcherooCard = hand[indexC];
				discardPile.push_back(hand[indexC]);
				hand.erase(hand.begin() + indexC);
				playCard(switcherooCard);
			}
			else {
				playCard(hand[indexC]);
				discardPile.push_back(hand[indexC]);
				hand.erase(hand.begin() + indexC);
			}

			cout << endl;
		}
		else {
			//display message if player didn't play any cards
			cout << "You didn't play any cards :(" << endl;
		}
	}
}

void ComputerPlayer::myTurn() {

	srand(time(NULL));





	if (drawCard()) {
		//if deck has cards inside, add the first card on the deck to the hand
		hand.push_back(deck.back());
		deck.pop_back();
	}

	//generate random numbers
	int randomPlay = rand() % 2;  //0 or 1 to decide if computer wants to play a card

	int randomCard = rand() % (0 + hand.size()); //from 0 to size of hand

	printInfoComputer();

	if (hand.size() > 5) {
		//if computer's deck has more than 5 cards, play one card RANDOM
		cout << "Computer's turn. he has more than 5 cards.  " << endl;


		playCard(hand[randomCard]);
		////move it to discard
		discardPile.push_back(hand[randomCard]);
		//delete from hand
		hand.erase(hand.begin() + randomCard);


	}
	else	if (hand.size() > 0 && hand.size() <= 5) {
		cout << "Computer's turn. Does he want to play?  ";

		//cout << randomPlay << " random card: " << randomCard << endl;

		switch (randomPlay)
		{
		case 0:
			cout << "NO" << endl;
			cout << "Computer didn't play any cards :(" << endl;
			break;

		case 1:
			cout << "YES" << endl;
			playCard(hand[randomCard]);
			////move it to discard
			discardPile.push_back(hand[randomCard]);
			//delete from hand
			hand.erase(hand.begin() + randomCard);
			cout << randomCard;

			break;
		default:
			break;
		}


	}



}




