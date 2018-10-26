//Edward Lam
//July 19, 2018
//Dominion - Players class

#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <algorithm>

using namespace std;

int rng(int tmp) { return rand()%tmp; }

class players {
 public:
 	//---Player's details and stuff---//
 	void setName(string tmp) {
 		name = tmp;
 	}
 	string getName() {
 		return name;
 	}
 	/**************************************************************************************************
 		------------------------------------------------------------------------------------------------
 	**************************************************************************************************/


 	//---Get player's stats and stuff---//
 	//All functions will move all cards of a player's cards into the deck.
 	void playersStats() {	
 		deckSiphon();
 		statReset();
 		cout << name << "'s stats being calculated" << endl; //
 		for(int i = 0; i < deck.size(); i++) {
 			if(deck[i].victory == 1) {
 				VPcards += 1;
 				if(deck[i].name == "Estate") {
 					totalVP += 1;
 				} else if(deck[i].name == "Duchy") {
 					totalVP += 3;
 				} else if(deck[i].name == "Province") {
 					totalVP += 6;
 				} else if(deck[i].name == "Curse") {
 					totalVP -= 1;
 				} else {
 					cout << "Victory card that isn't Estate, Duchy, Province, or Curse???" << endl;
 					deck[i].printStats();
 				}
 			} else if(deck[i].treasure == 1) {
 				moneyCards += 1;
 				if(deck[i].name == "Copper") {
 					totalMoney += 1;
 				} else if(deck[i].name == "Silver") {
 					totalMoney += 2;
 				} else if(deck[i].name == "Gold") {
 					totalMoney += 3;
 				} else {
 					cout << "Treasure card that isn't Copper, Silver, or Gold???" << endl;
 					deck[i].printStats();
 				}
 			}
 		}
 		totalCards = deck.size();
 	}

 	//Players Stats get
 	int getTotalMoney() { return totalMoney; }
 	int getMoneyCards() { return moneyCards; }
 	int getTotalVP() { return totalVP; }
 	int getVPCards() { return VPcards; }
 	int getTotalCards() { return totalCards; }

 	/**************************************************************************************************
 		------------------------------------------------------------------------------------------------
 	**************************************************************************************************/


 	//---Card manipulation by player---//
 	//Push numCards of the card 'tmp' onto the top of the deck.
 	void pushDeck(vector<card> tmp, int numCards) {
 		moveCards(tmp, deck, numCards);
 	}
 	//Push numCards of the card 'tmp' onto the top of the deck.
 	void pushDiscard(vector<card> tmp, int numCards) {
 		moveCards(tmp, deck, numCards);
 	}
 	//Draws 'tmp' amount of cards.
 	//If deck is too small to draw 'tmp' cards then the discard pile will be shuffled into the deck
 	//TODO: If both deck and discard piles are empty.
 	void drawCards(int tmp) {
 		//Case: Not enough cards in deck to be drawn
 		if(deck.size() < tmp) {
 			moveCards(deck, hand, tmp);
 			cout << "Deck is now empty, shuffling discard pile into new Deck." << endl;
 			shuffle(discard);
 			moveCards(discard, deck, discard.size());
 		//Case: Just enough cards to be drawn, so a shuffle and move is neccesary after draw.
 		//Note: Not really neccesary since empty decks will be handled by previous case anyways
 		} else if(deck.size() == tmp) {
 			moveCards(deck, hand, tmp);
 			shuffle(discard);
 			moveCards(discard, deck, discard.size());
 		//Case: Nothing special
 		} else {
 			moveCards(deck, hand, tmp);
 		}
 	}
 	/**************************************************************************************************
 		------------------------------------------------------------------------------------------------
 	**************************************************************************************************/

 private:
 	//Player Details
 	string name;
 	int actions;
 	int buys;

 	//Player Stats
 	int totalMoney = 0;
 	int moneyCards = 0;
 	int totalVP = 0;
 	int VPcards = 0;
 	int totalCards = 0;

 	//Player's card piles
 	vector<card> deck;
 	vector<card> hand;
 	vector<card> discard;
 	vector<card> field;

 	//private functions
 	//Shuffles the vector tmp
 	void shuffle(vector<card> tmp) {
 		srand(unsigned(time(0)));
 		if(discard.size() == 0) {
 			cout << "Discard Pile is empty." << endl;
 		} else {
 			random_shuffle(tmp.begin(), tmp.end(), rng);
 		}
 	}

 	//Moves cards from origin vector into destination vector
 	//Number of cards to be moved can be specified with numCards
 	//NOTE: Cards that are moved will be deleted from the origin vector.
 	void moveCards(vector<card>& origin, vector<card>& destination, int numCards) {
 		for(int i = 0; i < numCards; i++) {
 			destination.push_back(origin.back());
 			origin.pop_back();
 		}
 	}

 	//Moves all cards from other piles into the deck.
 	void deckSiphon() {
 		moveCards(hand, deck, hand.size());
 		moveCards(discard, deck, hand.size());
 		moveCards(field, deck, hand.size());
 		}
 	//Resets all stats of the player.
 	void statReset() {
	  totalMoney = 0;
	 	moneyCards = 0;
	 	totalVP = 0;
	 	VPcards = 0;
	 	totalCards = 0;
	}

 };