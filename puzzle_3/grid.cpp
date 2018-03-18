//Name: Chris Murphy
//Date: 1/31/18
//Assignment: AI Puzzle #1
//File: grid.cpp
#include "grid.h"

using namespace std;

Grid::Grid()
{
	dNum = 0;
	w = 0;
	h = 0;
	poolh = 0;
	bonus = 0;
	quota = 0;
	maxSwaps = 0;
	totalPoints = 0;
	totalSwaps = 0;

}

//Checking for valid inputs is done when reading the input file,
//so we don't need to check again here
Grid::Grid(const int pointGoal, const int swapGoal, const int deviceNum, const int width, const int height, const int poolHeight, vector<vector<int> > initGrid)
{
	//Set class grid specifications
	quota = pointGoal;
	maxSwaps = swapGoal;
	dNum = deviceNum;
	w = width;
	h = height;
	poolh = poolHeight;
	totalPoints = 0;
	totalSwaps = 0;

	//function only declarations
	vector<int> row;	//row of values to be pushed back into the initial grid

	//Initialize 2D vector to represent the grid
	//All grid spaces will initialize to 0
	for(int i = 0; i < h; i++)
	{
		for(int j = 0; j < w; j++)
		{
			row.push_back(0);
		}
		g.push_back(row);
	}

	g = initGrid;
}

void Grid::gridMake(const int deviceNum, const int width, const int height, const int poolHeight, vector<vector<int> > initGrid)
{
	//Set class grid specifications
	dNum = deviceNum;
	w = width;
	h = height;
	poolh = poolHeight;

	//function only declarations
	vector<int> row;	//row of values to be pushed back into the initial grid

	//Initialize 2D vector to represent the grid
	//All grid spaces will initialize to 0
	for(int i = 0; i < h; i++)
	{
		for(int j = 0; j < w; j++)
		{
			row.push_back(0);
		}
		g.push_back(row);
	}

	g = initGrid;
}

void Grid::gridCopy(const Grid& original)
{
	dNum = original.dNum;
	w = original.w;
	h = original.h;
	poolh = original.poolh;
	quota = original.quota;
	maxSwaps = original.maxSwaps;
	totalPoints = original.totalPoints;
	totalSwaps = original.totalSwaps;

	vector<int> row;

	for(int i = 0; i < h; i++)
	{
		for(int j = 0; j < w; j++)
		{
			row.push_back(0);
		}
		g.push_back(row);
	}

	g = original.g;

	return;
}

action Grid::Action(int x, int y, string swap)
{
	if(swap == "up")
	{
		action u(x, y, x, y - 1);
		//Note to self: remember, a swap up means it is one less
		return u;
	}
	else if(swap == "down")
	{
		action d(x, y, x, y + 1);
		return d;
	}
	else if(swap == "left")
	{
		action l(x, y, x - 1, y);
		return l;
	}
	else if(swap == "right")
	{
		action r(x, y, x + 1, y);
		return r;
	}
	else
	{
		cout << "Error!! Did you pass a valid swap direction?" << endl;
		return action(0, 0, 0, 0);
	}
}

void Grid::State(action a)
{
	vector<int> swap(4);
	swap = a.getAction();

	//Update the grid to reflect the swap
	int temp = g[swap[1]][swap[0]];
	g[swap[1]][swap[0]] = g[swap[3]][swap[2]];
	g[swap[3]][swap[2]] = temp;

	return;
}


bool Grid::scanHswap(int x, int y)
{
	//We can't swap right if we're at the edge
	if(x == w-1)
	{
		return false;
	}

	State(Action(x, y, "right"));

	if(scanHori(x, y) || scanVert(x, y) || scanHori(x+1, y) || scanVert(x+1, y))
	{
		State(Action(x, y, "right"));
		return true;
	}

	State(Action(x, y, "right"));
	return false;
}

bool Grid::scanVswap(int x, int y)
{
	//We can't swap down if we're at the bottom
	if(y == h-1)
	{
		return false;
	}

	State(Action(x, y, "down"));

	if(scanHori(x, y) || scanVert(x, y) || scanHori(x, y+1) || scanVert(x, y+1))
	{
		State(Action(x, y, "down"));
		return true;
	}

	State(Action(x, y, "down"));
	return false;
}


bool Grid::scanRight(int x, int y)
{
	int currCell = abs(g[y][x]);

	//If we can't even go three to the right we know we can't get a match
	if(x + 3 > w)
	{
		return false;
	}
	//Scan for a match (two right)
	else if( (currCell == abs(g[y][x+1])) && (currCell == abs(g[y][x+2])) )
	{
		return true;
	}
	return false;
}

bool Grid::scanLeft(int x, int y)
{
	int currCell = abs(g[y][x]);

	//If we can't even go three to the right we know we can't get a match
	if(x - 3 < 0)
	{
		return false;
	}
	//Scan for a match (two left)
	else if( (currCell == abs(g[y][x-1])) && (currCell == abs(g[y][x-2])) )
	{
		return true;
	}
	return false;
}

bool Grid::scanHmiddle(int x, int y)
{
	int currCell = abs(g[y][x]);

	//If we can't even go three to the right we know we can't get a match
	if( (x + 2 > w) || (x - 2 < 0) )
	{
		return false;
	}
	//Scan for a match (one right and one left)
	else if( (currCell == abs(g[y][x+1])) && (currCell == abs(g[y][x-1])) )
	{
		return true;
	}
	return false;
}

bool Grid::scanHori(int x, int y)
{
	if(scanRight(x, y) || scanLeft(x, y) || scanHmiddle(x, y))
	{
		return true;
	}
	return false;
}

bool Grid::scanDown(int x, int y)
{
	int currCell = abs(g[y][x]);
	
	//If we can't even go three down we know we can't get a match
	if(y + 3 > h)
	{
		return false;
	}
	//Scan for a match (two down)
	else if( (currCell == abs(g[y+1][x])) && (currCell == abs(g[y+2][x])) )
	{
		return true;
	}
	return false;
}

bool Grid::scanUp(int x, int y)
{
	int currCell = abs(g[y][x]);

	//If we can't even go three down we know we can't get a match
	if(y - 2 < poolh)
	{
		return false;
	}
	//Scan for a match (two up)
	else if( (currCell == abs(g[y-1][x])) && (currCell == abs(g[y-2][x])) )
	{
		return true;
	}
	return false;
}

bool Grid::scanVmiddle(int x, int y)
{
	//cout << "Entered scanDown" << endl;
	int currCell = abs(g[y][x]);
	
	//If we can't even go three down we know we can't get a match
	if( (y + 2 > h) || (y - 2) < poolh )
	{
		return false;
	}
	//Scan for a match (two up)
	else if( (currCell == abs(g[y+1][x])) && (currCell == abs(g[y-1][x])) )
	{
		return true;
	}
	return false;
}

bool Grid::scanVert(int x, int y)
{
	if(scanDown(x, y) || scanUp(x, y) || scanVmiddle(x, y))
	{
		return true;
	}
	return false;
}

int Grid::deviceGen(int x, int cycleMatches)
{
	return ( ( (g[1][x]) + x + cycleMatches ) % dNum ) + 1;
}


void Grid::fall(int x, int y, int cycleMatches)
{
	//iterate up the column from the passed y value
	for(int i = y; i > 0; i--)
	{
		g[i][x] = g[i-1][x];
	}

	//Use deviceGen to fill in the blank in the pool
	g[0][x] = deviceGen(x, cycleMatches);

	return;
}


void Grid::update()
{
	bool notSettled = false;
	int currCell;
	int itr = 0;
	bool match = false;
	int cycleMatches = 0; //devices matched in current cycle
						  //used in deviceGen()

 	do
 	{
 	notSettled = false; //We assume it is settled until a match is found
	//First we identify all matches that exist in the board
	for(int i = poolh; i < h; i++)
	{
		for(int j = 0; j < w; j++)
		{
			currCell = abs(g[i][j]);
			//Check for matches to the right and below
			if( scanDown(j, i) )
			{
				notSettled = true;
				match = true;
				while( (i+itr) < h  && match )
				{
					if(currCell != abs(g[i+itr][j]))
					{
						match = false;
					}
					else
					{
						g[i+itr][j] = -currCell;
						itr++;
					}
				}
			}
			match = false;
			itr = 0; //reset iterator
			if ( scanRight(j, i) )
			{
				notSettled = true;
				match = true;
				while( (j+itr) < w && match )
				{
					if(currCell != abs(g[i][j+itr]))
					{
						match = false;
					}
					else
					{
						g[i][j+itr] = -currCell;
						itr++;
					}
				}
			}
			match = false;
			itr = 0;
		}
	}

	//Now we allow pieces to fall into new positions based on matches
	//We start at the first line of the board
	//lines of the grid where an empty spot might exist
	for(int i = poolh; i < h; i++)
	{
		for(int j = 0; j < w; j++)
		{
			if(g[i][j] < 0)
			{
				cycleMatches++;
				fall(j, i, cycleMatches);
			}
		}
	}
	totalPoints = totalPoints + cycleMatches; //update total points
	cycleMatches = 0; //reset cycleMatches before the next cycle
	} while(notSettled);
	
	return;
}


void Grid::result(const Grid& g, const action& a)
{
	//Copy g into an empty Grid vector
	gridCopy(g);

	//Perform the action on the new grid (thus updating to a new state)
	State(a);

	//Update the new grid according to the matches that occur
	//This generates the end state of the swap
	update();

	totalSwaps++;
	//cout << "This grids total swaps: " << totalSwaps << endl;
	//cout << "g's total swaps: " << g.totalSwaps << endl;
}

void Grid::displayGrid()
{
	for(int i = 0; i < h; i++)
	{
		//commented out divider line for output file
		/*
		if(i == poolh)
		{
			for(int k = 0; k < w; k++)
			{
				cout << "--";
			}
			cout << endl;
		}
		*/
		
		for(int j = 0; j < w; j++)
		{
			cout << g[i][j] << " ";
		}
		cout << endl;
	}
}

bool Grid::goal()
{
	if( (totalPoints >= quota) && (totalSwaps <= maxSwaps) )
	{
		return true;
	}
	return false;
}

bool Grid::operator==(const Grid& rhs)
{
	return (g == rhs.g);
}