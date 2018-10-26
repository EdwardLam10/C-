#include <iostream>
using namespace std;

//Inputting the board along with instructions//
void inputboard(int board[9][9])
{
	cout << "Enter the uncompleted board from left to right, top to bottom" << endl << "Enter '0' as an empty cell" << endl;
	for (int x = 1; x <= 9; x++)
	{
		for (int y = 1; y <= 9; y++)
		{
			cout << x << y;
			int input;
			cin >> input;
			if(input < 10)
			{
				board[x][y] = input;
			}
			else
			{
				while(input >= 10)
				{
					cout << "Please enter a number smaller than 10!" << endl;
					cin >> input;
				}
				board[x][y] = input;
			}
		}
	}
}

//Shows the board
void showboard(int board[9][9])
{
		for (int x = 1; x <= 9; x++)
	{
		if (x == 4 || x == 7)
		{
			cout << "=============================" << endl;
		}
		for (int y = 1; y <= 9; y++)
		{
			if (y < 9)
			{
				if (y == 3 || y == 6)
				{
					cout << board[x][y] << " || ";
				}
				else
				{
					cout << board[x][y] << "  ";
				}
			}
			else
			{			
				cout << board[x][y] << endl;
			}
		}
	}
}

//Function that checks the rows for a number and returns true if it is not there or false if it is.
bool checkrow(int board[9][9], int row, int number)
{
	int a = row;
	for(int y = 1; y <= 9; y++)
	{
		cout << "Inside for loop of checkrow function" << endl;
		if (board[y][a] == number)
		{
			return false;
		}
		else
		{
			return true;
		}
	}
}

//Function that checks the column for a number and returns true if it is not there and false if it is.
bool checkcolumn(int board[9][9], int column, int number)
{
	int a = column;
	for(int y = 1; y <= 9; y++)
	{
		cout << "Inside for loop of checkrow function" << endl;
		if (board[a][y] == number)
		{
			return false;
		}
		else
		{
			return true;
		}
	}
}

//Function that checks teh column for a number and returns true if it is not there and false if it is
bool checkbox(int board[9][9], int row, int column, int number)
{
	if(row > 0 && row < 4);
	{
		if(column > 0 && column < 4);
		{
			for (int x = 1; x < 4; x++)
			{
				for(int y = 1; y < 4; y++)
				{
					if(board[x][y] == number)
					{
						return true;
					}
					else
					{
						return false;
					}
				}
			}
		}
	}
	if(row > 0 && row < 4);
	{
		if(column > 3 && column < 7);
		{
			for (int x = 1; x < 4; x++)
			{
				for(int y = 4; y < 7; y++)
				{
					if(board[x][y] == number)
					{
						return true;
					}
					else
					{
						return false;
					}
				}
			}
		}
	}
	if(row > 0 && row < 4);
	{
		if(column > 6 && column < 10);
		{
			for (int x = 1; x < 4; x++)
			{
				for(int y = 7; y < 10; y++)
				{
					if(board[x][y] == number)
					{
						return true;
					}
					else
					{
						return false;
					}
				}
			}
		}
	}
	if(row > 3 && row < 7);
	{
		if(column > 0 && column < 4);
		{
			for (int x = 4; x < 6; x++)
			{
				for(int y = 1; y < 4; y++)
				{
					if(board[x][y] == number)
					{
						return true;
					}
					else
					{
						return false;
					}
				}
			}
		}
	}
	if(row > 3 && row < 7);
	{
		if(column > 3 && column < 7);
		{
			for (int x = 4; x < 7; x++)
			{
				for(int y = 4; y < 7; y++)
				{
					if(board[x][y] == number)
					{
						return true;
					}
					else
					{
						return false;
					}
				}
			}
		}
	}
	if(row > 3 && row < 7);
	{
		if(column > 6 && column < 10);
		{
			for (int x = 4; x < 7; x++)
			{
				for(int y = 7; y < 10; y++)
				{
					if(board[x][y] == number)
					{
						return true;
					}
					else
					{
						return false;
					}
				}
			}
		}
	}
	if(row > 0 && row < 4);
	{
		if(column > 6 && column < 10);
		{
			for (int x = 1; x < 4; x++)
			{
				for(int y = 7; y < 10; y++)
				{
					if(board[x][y] == number)
					{
						return true;
					}
					else
					{
						return false;
					}
				}
			}
		}
	}
	if(row > 3 && row < 7);
	{
		if(column > 6 && column < 10);
		{
			for (int x = 4; x < 7; x++)
			{
				for(int y = 7; y < 10; y++)
				{
					if(board[x][y] == number)
					{
						return true;
					}
					else
					{
						return false;
					}
				}
			}
		}
	}
	if(row > 6 && row < 10);
	{
		if(column > 6 && column < 10);
		{
			for (int x = 7; x < 10; x++)
			{
				for(int y = 7; y < 10; y++)
				{
					if(board[x][y] == number)
					{
						return true;
					}
					else
					{
						return false;
					}
				}
			}
		}
	}
};

int main()
{
	//Initialization
	int board[9][9];
	inputboard (board);
	showboard (board);
	cout << "Is this the correct board?" << endl << "Press 'Y' to continue or 'N' to re-enter your board" << endl;
	char a;
	cin >> a;
	//Is the board right cycle?
	while (a == 'n')
	{
		inputboard (board);
		showboard (board);
		cout << "Is this the correct board?" << endl << "Press 'Y' to continue or 'N' to re-enter your board" << endl;
		char a;
		cin >> a;
	}
	
	//3D array as possible answer key
	int possible[9]9][9];
	
	//Begin solving the board
	bool row, column, box;
	for (int x = 1; x <= 9; x++)
	{
		for (int y = 1; y <= 9; y++)
		{
			if (board[x][y] == 0)
			{
				for (int z = 1; z <= 9; z++)
				{
					row = checkrow (board, x, z);
					column = checkcolumn (board, y, z);
					box = checkbox (board, x, y, z);
					if (row == false && column == false && box == false)
					{
						possible[x][y][z] = z;
						board[x][y] = z;
					}
				}
			}
		}
	}
	cout << "It worked!!" << endl;
	return 0;
};
