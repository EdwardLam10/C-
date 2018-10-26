#include <iostream>
using namespace std;

//Player Structures
struct player
{
	string playername;
	int wins;	
};

//Showboard function shows the board in whatever state it is in.
void showboard(char one = '_', char two = '_' , char three = '_', char four = '_', char five = '_', char six = '_', char seven = '_', char eight = '_', char nine = '_')
{
	cout << one << " " << two << " " << three << endl << four << " " << five << " " << six << endl << seven << " " << eight << " " << nine << endl; 
}

//playerx function checks what number the user has inputed and checks if it is a valid space to place the X if it is valid it will write in and X.
//if the the place is invalid it will ask for another input.
char playerx(int input,
	char & one,
        char & two,
        char & three,
        char & four,
        char & five,
        char & six,
        char & seven,
        char & eight,
        char & nine)
{
    if(input == 1 && one == '_')
    {
        one = 'X';
    }
    else if(input == 2 && two == '_')
    {
        two = 'X';
    }
	else if(input == 3 && three == '_')
	{
		three = 'X';
	}
	else if(input == 4 && four == '_')
	{
		four = 'X';
	}
	else if(input == 5 && five == '_')
	{
		five = 'X';
	}
	else if(input  == 6 && six == '_')
	{
		six = 'X';
	}
	else if(input == 7 && seven == '_')
	{
		seven = 'X';
	}
	else if(input == 8 && eight == '_')
	{
		eight = 'X';
	}
	else if(input == 9 && nine == '_')
	{
		nine = 'X';
	}
    else
    {
        	cout << "That space has already been taken. Please enter a valid space: ";
        	cin >> input;
        	playerx(input, one, two, three, four, five, six, seven, eight, nine);
    }
}

//playero function checks what number the user has inputed and checks if it is a valid space to place the O if it is valid it will write in and O.
//if the the place is invalid it will ask for another input.
char playero(int input,
        char & one,
        char & two,
        char & three,
        char & four,
        char & five,
        char & six,
        char & seven,
        char & eight,
        char & nine)
{
        if(input == 1 && one == '_')
        {
                one = 'O';
        }
        else if(input == 2 && two == '_')
        {
                two = 'O';
        }
        else if(input == 3 && three == '_')
        {
                three = 'O';
        }
        else if(input == 4 && four == '_')
        {
                four = 'O';
        }
        else if(input == 5 && five == '_')
        {
                five = 'O';
        }
        else if(input  == 6 && six == '_')
        {
                six = 'O';
        }
        else if(input == 7 && seven == '_' )
        {
                seven = 'O';
        }
        else if(input == 8 && eight == '_')
        {
                eight = 'O';
        }
        else if(input == 9 && nine == '_')
        {
                nine = 'O';
        }
        else
        {
        		cout << "That space has already been taken. Please enter a valid space: ";
        		cin >> input;
        		playero(input, one, two, three, four, five, six, seven, eight, nine);
		}
}

//Structures for rounds
struct semifinalist
{
	int seminumber;
};

struct finalist
{
	int finalnumber;
};

int main()
{
	//Initializations
	int input;	
	int Owin = 0;
	int Xwin = 0;
	char one = '_';
	char two = '_';
	char three = '_';
	char four = '_';
	char five = '_';
	char six = '_';
	char seven = '_';
	char eight = '_';
	char nine = '_';
	int playerxcounter = 0;
	int playerycounter = 7;
	semifinalist semifinalist[4];
	int semix = 0;
	int semiy = 5;
	int semi = 0;
	finalist finalist[2];
	int matchcounter = 1;
	int playagain;
	
	//Welcome and Player Initializations
	cout << "Welcome to Tic Tac Toe Tournament!" << endl;
	player players[8];
	for(int counter = 0; counter < 8; counter++)
	{
		cout << "Who is Player" << counter + 1 << "?" << endl;
		cin >> players[counter].playername;
	}
		    		     
	
	//Instructions
	cout << "To play,enter the number that corresponds to the slot you want to put your X or O in." << endl
	     << "1 2 3" << endl << "4 5 6" << endl << "7 8 9" << endl << "====================" << endl;

	
	//Tournament loop
	while(matchcounter <= 7)
	{	
		cout << players[playerycounter].playername << " will be PlayerY." << endl;
		cout << players[playerxcounter].playername << " will be playerX." << endl;
		
		do
		{
			playagain = 0;
			
			//First turn
			cout << players[playerxcounter].playername << " can start: ";
			cin >> input;
			playerx(input, one, two, three, four, five, six, seven, eight, nine);
			showboard(one, two, three, four, five, six, seven, eight, nine);
			cout << "====================" << endl;
			
			//Rest of the turns
			for (int turncount = 1; turncount <= 4 && Owin != 1 && Xwin != 1; turncount++)
			{
				//Player O's regular turn
				cout << players[playerycounter].playername << "'s turn: ";
				cin >> input;
				playero(input, one, two, three, four, five, six, seven, eight, nine);
				showboard(one, two, three, four, five, six, seven, eight, nine);
				cout << "====================" << endl;
				
				//Check if Player O has won.
				if (one == 'O' && two == 'O' && three == 'O')
				{
					Owin = Owin + 1;
					turncount = 4;
				}
				else if(four == 'O' && five == 'O' && six == 'O')
				{
					Owin = Owin + 1;
					turncount = 4;
				}
				else if(seven == 'O' && eight == 'O' && nine == 'O')
				{
					Owin = Owin + 1;
					turncount = 4;
				}
				else if(one == 'O' && four == 'O' && seven == 'O')
				{
					Owin = Owin + 1;
					turncount = 4;
				}
				else if(two == 'O' && five == 'O' && eight == 'O')
				{
					Owin = Owin + 1;
					turncount = 4;
				}
				else if(three == 'O' && six == 'O' && nine == 'O')
				{
					Owin = Owin + 1;
					turncount = 4;
				}
				else if(one  == 'O' && five == 'O' && nine == 'O')
				{
					Owin = Owin + 1;
					turncount = 4;
				}
				else if(three == 'O' && five == 'O' && seven == 'O')
				{
					Owin = Owin + 1;
					turncount = 4;
				}
				
				if(Owin != 1)
				{
					//Player X's regular turn
					cout << players[playerxcounter].playername << "'s turn: ";
					cin >> input;
					playerx(input, one, two, three, four, five, six, seven, eight, nine);
					showboard(one, two, three, four, five, six, seven, eight, nine);
					cout << "====================" << endl;
					
					//Check if Player X has won
					if (one == 'X' && two == 'X' && three == 'X')
					{
						Xwin = Xwin + 1;
						turncount = 4;
					}
					else if (four == 'X' && five == 'X' && six == 'X')
					{
						Xwin = Xwin + 1;
						turncount = 4;
					}
					else if(seven == 'X' && eight == 'X' && nine == 'X')
					{
						Xwin = Xwin + 1;
						turncount = 4;
					}
					else if(one == 'X' && four == 'X' && seven == 'X')
					{
						Xwin = Xwin + 1;
						turncount = 4;
					}
					else if(two == 'X' && five == 'X' && eight == 'X')
					{
						Xwin = Xwin + 1;
						turncount = 4;
					}
					else if(three == 'X' && six == 'X' && nine == 'X')
					{
						Xwin = Xwin + 1;
						turncount = 4;
					}
					else if(one  == 'X' && five == 'X' && nine == 'X')
					{
						Xwin = Xwin + 1;
						turncount = 4;
					}
					else if(three == 'X' && five == 'X' && seven == 'X')
					{
						Xwin = Xwin + 1;
						turncount = 4;
					}
				}
			}
			
			//Who won?
			if(Xwin == 1)
			{
				if(matchcounter < 7)
				{
					cout << "Congratulations! " << players[playerxcounter].playername << " has won!" << endl;
				}
				else
				{
					cout << "Congratulations! " << players[playerxcounter].playername << " has won the TIC TAC TOE TOURNAMENT!!" <<
					cout << "Sadly there is not prize." << endl;
				}
				players[playerxcounter].wins += 1;
				semifinalist[semi].seminumber = playerxcounter;
				semi += 1;
				finalist[1].finalnumber = playerxcounter;
			}
			else if(Owin == 1)
			{
				if(matchcounter < 7)
				{
				cout << "Congratulations! " << players[playerycounter].playername << " has won!" << endl;
				}
				else
				{
					cout << "Congratulations! " << players[playerycounter].playername << " has won the TIC TAC TOE TOURNAMENT!!" <<
					cout << "Sadly there is not prize." << endl;
				}
				players[playerycounter].wins += 1;
				semifinalist[semi].seminumber = playerycounter;
				semi += 1;
				finalist[2].finalnumber = playerycounter;
			}
			else
			{
				cout << "No more spaces are available on the board. The game is tied and the victor will be determined by both player's past record." << endl;
				if(players[playerxcounter].wins > players[playerycounter].wins)
				{
					if(matchcounter < 7)
					{
						cout << "Congratulations! " << players[playerxcounter].playername << " has won!" << endl;
					}
					else
					{
						cout << "Congratulations! " << players[playerxcounter].playername << " has won the TIC TAC TOE TOURNAMENT!!" <<
						cout << "Sadly there is not prize." << endl;
					}
					players[playerxcounter].wins += 1;
					semifinalist[semi].seminumber = playerxcounter;
					semi += 1;
					finalist[1].finalnumber = playerxcounter;
				}
				else if(players[playerxcounter].wins < players[playerycounter].wins)
				{
					if(matchcounter < 7)
					{
						cout << "Congratulations! " << players[playerycounter].playername << " has won!" << endl;
					}
					else
					{
						cout << "Congratulations! " << players[playerycounter].playername << " has won the TIC TAC TOE TOURNAMENT!!" <<
						cout << "Sadly there is not prize." << endl;
					}
					players[playerycounter].wins += 1;
					semifinalist[semi].seminumber = playerycounter;
					semi += 1;
					finalist[2].finalnumber = playerycounter;
				}
				else
				{
					cout << "Both players have the same amount of wins on their record. The game will restart." << endl;
					playagain = 1;
				}
			}
			
			//resets the board and counter
			Owin = 0;
			Xwin = 0;
			one = '_';
			two = '_';
			three = '_';
			four = '_';
			five = '_';
			six = '_';
			seven = '_';
			eight = '_';
			nine = '_';
		}
		while(playagain == 1);
		
		cout << "Match finished" << endl;
		if(matchcounter <= 4)
		{
			playerxcounter -= 1;
			playerycounter +=1;
		}
		else if(matchcounter >= 5 && matchcounter <= 6)
		{
			semix -= 1;
			semiy -= 1;
			playerxcounter = semifinalist[semix].seminumber;
			playerycounter = semifinalist[semiy].seminumber;
		}
		else
		{
			playerxcounter = finalist[1].finalnumber;
			playerycounter = finalist[2].finalnumber;
		}
		matchcounter = matchcounter + 1;
		cout << "Values incremented" << endl;
	}	
	
	//endgame
	cout << endl << "====================" << endl << "Thank you for playing!" << endl << "====================" << endl;
		
	return 0;
}
	
