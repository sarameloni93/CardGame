

#include "Card.h"
#include "Player.h"

//p is the opponent and p->opponent is the player, (p->opponent : the opponent of the opponent is the player)

void PainfulLesson::effect(Player* p) {
	p->loseHealth(damage);
	if (p->drawCard()) {
		//add the first card on the deck to the hand
		p->hand.push_back(p->deck.back());
		p->deck.pop_back();
	}
	else p->hasLost();
}

void Spite::effect(Player* p) {

	//both players lose 1 health

	p->loseHealth(damage);
	p->opponent->loseHealth(damage);
}

void FullHeal::effect(Player* p) {
	//restore health back to 20
	p->opponent->health = 20;

}

void Switcheroo::effect(Player* p) {

	vector<Card*> opponentCards = p->hand;
	p->hand = p->opponent->hand;  //opponent's hand is equal to player's
	p->opponent->hand = opponentCards; //player's hand is equal to opponent's
	  
	//the switcheroo card that is played needs to be deleted when player's hand swap with opponent's

}

void Refresh::effect(Player* p) {
	p->opponent->loseHealth(damage);

	//shuffle discard pile and push it in the deck
	for (Card* i : p->opponent->discardPile) {
		p->opponent->deck.push_back(i);
	}

	p->opponent->discardPile.clear();
}

void Peek::effect(Player* p) {
	//look at cards of both players decks

	cout << "Top Card on the opponent's deck: " << p->deck.back()->getName() << endl;
	cout << "Top Card on your deck: " << p->opponent ->deck.back()->getName() << endl;

}
