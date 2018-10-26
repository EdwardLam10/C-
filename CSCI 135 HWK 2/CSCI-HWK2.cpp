#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

//WOLF CLASS
struct newwolf
{
	int energy;
	int wx;
	int wy;
	int wreproduction;
	bool walive;
	void move()
	{
		srand(time(NULL));
        int xoffset = ( rand() % 3 ) - 1;
        int yoffset = ( rand() % 3 ) - 1;
        wx = wx + xoffset;
        wy = wy + yoffset;
	}
};

//SHEEP CLASS
struct newsheep
{
	int sx;
	int sy;
	int sreproduction;
	bool salive;
	void move()
	{
		srand(time(NULL));
        int xoffset = ( rand() % 3 ) - 1;
        int yoffset = ( rand() % 3 ) - 1;
        sx = sx + xoffset;
        sy = sy + yoffset;
	}
};

int main()
{
	char input;
	do
	{
		//INITIALIZATIONS AND USER INPUTS
		int gridsize;
		int initial_wolf;
		int initial_sheep;
		int wolf_energy;
		int energy_gain;
		int wolf_reproduction;
		int sheep_reproduction;
		int gridturn;
		int totalsheep;
		int totalwolf;
		int moves = 0;
		srand (time(NULL));
		cout << "GRID SIZE: ";
		cin >> gridsize;
		cout << "INITIAL NUMBER OF WOLVES: ";
		cin >>  initial_wolf;
		totalwolf = initial_wolf;
		cout << "INITIAL NUMBER OF SHEEP: ";
		cin >> initial_sheep;
		totalsheep = initial_sheep;
		cout << "INITIAL WOLF ENERGY: ";
		cin >> wolf_energy;
		cout << "WOLF ENERGY GAINED FROM FOOD: ";
		cin >> energy_gain;
		cout << "WOLF REPRODUCTION RATE: ";
		cin >> wolf_reproduction;
		cout << "SHEEP REPRODUCTION RATE: ";
		cin >> sheep_reproduction; 
		cout << "How many turns per grid: ";
		cin >> gridturn;
		cout << "-INITIAL POSITIONS OF WOLVES AND SHEEP-" << endl;
		
		//CREATING AN EMPTY GRID
		char grid[gridsize][gridsize];
		for(int f = 0; f < gridsize; f++)
		{
			for(int g = 1; g <= gridsize; g++)
			{
				grid[f][g] = '_';
			}
		}
		
		//CREATING WOLVES AND ADDING THEM ONTO THE GRID
		newwolf wolf[initial_wolf];
		for(int a = 0; a < initial_wolf; a++)
		{
			wolf[a] = {wolf_energy, rand()%gridsize, rand()%gridsize+1, wolf_reproduction, true};
			if(grid[wolf[a].wx][wolf[a].wy] == '_')
			{
				grid[wolf[a].wx][wolf[a].wy] = 'W';
			}
			else
			{
				do
				{
					wolf[a].wx = rand()%gridsize;
					wolf[a].wy = rand()%gridsize;
				}
				while(grid[wolf[a].wx][wolf[a].wy] != '_');
				grid[wolf[a].wx][wolf[a].wy] = 'W';
			}
		}
		
		//CREATING SHEEP AND ADDING THEM ONTO THE GRID
		newsheep sheep[initial_sheep];
		for(int b = 0; b < initial_sheep; b++)
		{
			sheep[b] = {rand()%gridsize, rand()%gridsize, sheep_reproduction, true};
			if(grid[sheep[b].sx][sheep[b].sy] == '_')
			{
				grid[sheep[b].sx][sheep[b].sy] = 'S';
			}
			else
			{
				do
				{
					sheep[b].sx = rand()%gridsize;
					sheep[b].sy = rand()%gridsize;
				}
				while(grid[sheep[b].sx][sheep[b].sy] != '_');
				grid[sheep[b].sx][sheep[b].sy] = 'S';
			}
			
		}
		
		//SHOWING THE GRID
		for(int f = 0; f < gridsize; f++)
		{
			for(int g = 1; g <= gridsize; g++)
			{
				cout << grid[f][g] << " ";
			}
			cout << endl;
		}
		
		cout << "Do not continue repeatedly or the program might crash." << endl;
		system("pause");
		
		//MOVING AND SEX AND MORE!
		do
		{
			moves += 1;
			//MOVING THE WOLF AND WOLF SEX
			for(int d = 0; d < totalwolf; d++)
			{

				//CLEAN UP AFTER YOU LEAVE
				grid[wolf[d].wx][wolf[d].wy] = '_';

				//ARE YOU TRYING TO MOVE A DEAD WOLF?
				if(wolf[d].walive == true)
				{
					wolf[d].move();
					wolf[d].energy -= 1;
					if(grid[wolf[d].wx][wolf[d].wy] = 'S')
					{
						grid[wolf[d].wx][wolf[d].wy] = 'W';
						wolf[d].energy += energy_gain;
						totalsheep -= 1;
					}
					else
					{
						grid[wolf[d].wx][wolf[d].wy] = 'W';
					}
				}

				//DID YOUR WOLF STARVE TO DEATH?
				if(wolf[d].energy == 0)
				{
					wolf[d].walive = false;
				}

				//DID THE WOLF GET LUCKY?
				if((rand()%100)+1 <= wolf[d].wreproduction)
				{
					newwolf wolf[totalwolf];
					wolf[totalwolf] = {wolf_energy, wolf[d].wx, wolf[d].wy, wolf_reproduction, true};
				}
			}
			//MOVING THE SHEEP AND SHEEP SEX
			for(int c = 0; c < totalsheep; c++)
			{
				//CLEAN UP AFTER YOU LEAVE
				grid[sheep[c].sx][sheep[c].sy] = '_';
				
				//ARE YOU TRYING TO MOVE A SHEEP INSIDE A WOLF?
				if(sheep[c].salive == true)
				{
					sheep[c].move();
					if(grid[sheep[c].sx][sheep[c].sy] = 'W')
					{
						sheep[c].salive = false;
					}
					else
					{
						grid[sheep[c].sx][sheep[c].sy] = 'S';
					}
				}

				//DID THE SHEEP GET LUCKY?
				if((rand()%100)+1 <= sheep[c].sreproduction)
				{
					totalsheep = totalsheep + 1;
					newsheep sheep[totalsheep];
					sheep[totalsheep] = {sheep[c].sx, sheep[c].sy, sheep_reproduction, true};
				}
			}
			if(moves%gridturn == 0)
			{
				//MOVE COUNT AND DISPLAY
				cout << "-New grid after " << moves << " turn(s)-" << endl;
				for(int f = 0; f < gridsize; f++)
				{
					for(int g = 0; g < gridsize; g++)
					{
						cout << grid[f][g] << " ";
					}
					cout << endl;
				}
				system("pause");
			}
		}
		while(totalsheep != 0 && totalwolf != 0);
		cout << "Your parameters do not create a stable ecosystem. Would you like to try again? (y/n)";
		cin >> input;
	}
	while(input == 'y');
	
	return 0;
}
