# CardGame

 Objective:
The players take turns playing cards, trying to reduce each other’s health to 0.

 Overview of the game: 
The game is played by two players, one human and one controlled by the. Each player starts the game with 20 health and all their cards in their deck. On a player’s turn, they 
-	Draw a card from the deck, adding it to their hand
-	Play any number of cards from their hand, applying their effect and then adding them to their discard pile. They need to play enough cards to reduce the size of their hand to 5 or less. 

A player loses the game if:
-	Their health is 0 or less, or
-	They are supposed to draw a card but cannot because their deck is empty. 

Each player’s deck initially contains the following cards: 
-	“Painful lesson” – opponent loses 2 health and draws a card. The deck contains 5 of these.
-	“Spite” – both players lose 1 health. The deck contains 6 of these.  
-	“Full heal” – restores your health back to 20. The deck contains 1 of these.
-	“Switcheroo” – swaps the contents of your hand with your opponent’s (note that the switcheroo card being played is no longer in your hand at this time, so the opponent does not get it). The deck contains 2 of these. 
-	“Refresh” – lose 3 health and shuffle your discard pile back into your deck. The deck contains 2 of these. 
-	“Peek” – look at the top cards of both players’ decks. The deck contains 4 of these.
