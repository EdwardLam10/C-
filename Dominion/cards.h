//Edward Lam
//July 19, 2018
//Dominion - Cards class

#include <vector>
#include <string>

using namespace std;

struct card{
	string name;
	int cost;
	int worth = 0;
	int VP = 0;

	bool treasure = 0;
	bool action = 0;
	bool attack = 0;
	bool victory = 0;
	bool reaction = 0;
	bool curse = 0;

	int pCard = 0;
	int pAction = 0;
	int pBuy = 0;

	void printStats() {
		cout << name << " " << cost << " " << worth << " " << VP << endl;
	}
};

class cards {
 public:
 	//Initializations
 	cards() {
 		if(initializeTreasures() != 0) {
 			cout << "Error initializing Treasures." << endl;
 		} else {
 			cout << "Treasures initialized properly." << endl;
 		}
 		if(initializeVP() != 0) {
 			cout << "Error initializing Victory Points." << endl;
 		} else {
 			cout << "Victory Points initialized properly." << endl;
 		}
 		if(initializeActions() != 0) {
 			cout << "Error initializing Action Cards." << endl;
 		} else {
 			cout << "Action Cards initialized properly." << endl;
 		}
 	}

 	//Which card to get?
 	vector<card> getCard(string cardName) {
 		if(cardName == "Copper") {
 			return getCopper();
 		} else if(cardName == "Silver") {
 			return getSilver();
 		} else if(cardName == "Gold") {
 			return getGold();
 		} else if(cardName == "Estate") {
 			return getEstate();
 		} else if(cardName == "Duchy") {
 			return getDuchy();
 		} else if(cardName == "Province") {
 			return getProvince();
 		} else if(cardName == "Curse") {
 			return getCurse();
 		}
 	}


 private:
 	//Treasures
 	vector<card> copperSupply;
 	vector<card> silverSupply;
 	vector<card> goldSupply;

 	//Victory Points
 	vector<card> estateSupply;
 	vector<card> duchySupply;
 	vector<card> provinceSupply;
 	vector<card> curseSupply;

 	//Action Cards
 	vector<card> ArtisanSupply;


 	//Private functions
 	int initializeTreasures() {
	 	card tmpTreasure;

	 	//Initializing the card to be Copper
	 	tmpTreasure.name = "Copper";
	 	tmpTreasure.cost = 0;
	 	tmpTreasure.worth = 1;
	 	tmpTreasure.treasure = 1;
	 	//Creating Copper Supply
 		for(int i = 0; i < 60; i++) {
 			copperSupply.push_back(tmpTreasure);
 		}

 		//Initialziing the card to be Silver
 		tmpTreasure.name = "Silver";
 		tmpTreasure.cost = 3;
 		tmpTreasure.worth = 2;
 		//Creating Silver Supply
 		for(int i = 0; i < 40; i++) {
 			silverSupply.push_back(tmpTreasure);
 		}

	 	//Initalizing the card to be Gold
	 	tmpTreasure.name = "Gold";
	 	tmpTreasure.cost = 6;
	 	tmpTreasure.worth = 3;
	 	//Creating Gold Supply
	 	for(int i = 0; i < 30; i++) {
	 		goldSupply.push_back(tmpTreasure);
	 	}

	 	//Checking
	 	if(copperSupply.size() != 60 || silverSupply.size() != 40 || goldSupply.size() != 30) {
	 		return -1;
	 	} else {
	 		return 0;
	 	}
	}
	int initializeVP() {
		card tmpVP;

		//Initializing card to be Estates
		tmpVP.name = "Estate";
		tmpVP.cost = 2;
		tmpVP.VP = 1;
		tmpVP.victory = 1;
		//Creating Estate Supply
		for(int i = 0; i < 24; i++) {
			estateSupply.push_back(tmpVP);
		}

		//Initializing card to be Duchy
		tmpVP.name = "Duchy";
		tmpVP.cost = 5;
		tmpVP.VP = 3;
		//Creating Duchy Supply
		for(int i = 0; i < 12; i++) {
			duchySupply.push_back(tmpVP);
		}

		//Initializing card to be Province
		tmpVP.name = "Province";
		tmpVP.cost = 8;
		tmpVP.VP = 6;
		//Creating Province Supply
		for(int i = 0; i < 12; i++) {
			provinceSupply.push_back(tmpVP);
		}

		//Initializing card to be Curse
		tmpVP.name = "Curse";
		tmpVP.cost = 0;
		tmpVP.VP = -1;
		tmpVP.treasure = 0;
		tmpVP.curse = 1;
		//Creating Curse Supply
		for(int i = 0; i < 30; i++) {
			curseSupply.push_back(tmpVP);
		}

		//Checking
		if(estateSupply.size() != 24 || duchySupply.size() != 12 ||
			 provinceSupply.size() != 12 || curseSupply.size() != 30) {
			return -1;
		} else {
			return 0;
		}
	}
	int initializeActions() {
		card tmpAction;

		//Initializing card to be Artisan
		tmpAction.name = "Artisan";
		tmpAction.cost = "6"
		tmpAction.action = 1;
	}


	//Gets
	vector<card> getCopper() {
		return copperSupply;
	}
	vector<card> getSilver() {
		return silverSupply;
	}
	vector<card> getGold() {
		return goldSupply;
	}
	vector<card> getEstate() {
		return estateSupply;
	}	
	vector<card> getDuchy() {
		return duchySupply;
	}
	vector<card> getProvince() {
		return provinceSupply;
	}
	vector<card> getCurse() {
		return curseSupply;
	}


};