//Edward Lam
//July 19, 2018
//Dominion - main.cpp

#include <iostream>
#include <string>
#include <vector>

#include "cards.h"
#include "players.h"

using namespace std;

int main() {
	int playerCT = 100;

	//Hello
	system("clear");
	cout << "Welcome to Dominion, how many players are there?" << endl;
	cout << "There can only be 2-4 players." << endl;
	while((playerCT >= 5) || (playerCT <= 1)) {
		cin >> playerCT;
		if((playerCT >= 5) || (playerCT <= 1)) {
			cout << playerCT << " is not between 2 and 4, dumbass." << endl;
		}
	}
	players playerList[playerCT];

	//What are your names?
	system("clear");
	for(int i = 0; i < playerCT; i++){
		cout << "What is the name of player " << i + 1 << "? ";
		string tmp;
		cin >> tmp;
		playerList[i].setName(tmp);
	}

	//Initializing decks and supply piles
	system("clear");
	cout << "Initializing decks and supply piles.." << endl;
	cards cardSupply; //Initializing Supply piles
	for(int i = 0; i < playerCT; i++) {
		playerList[i].pushDeck(cardSupply.getCard("Copper"), 7);
		playerList[i].pushDeck(cardSupply.getCard("Estate"), 3);
		// playerList[i].playersStats();
		if(playerList[i].getTotalCards() == 10) {
			cout << playerList[i].getName() << "'s deck initialized properly." << endl;
		} else {
			// cout << playerList[i].getName() << "s deck was not initialized properly." << endl; 
			cout << playerList[i].getTotalCards() << endl;
		}
	}
	system("clear");

	

	return 0;
}