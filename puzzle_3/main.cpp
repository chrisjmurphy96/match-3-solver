//Name: Chris Murphy
//Date: 1/31/18
//Assignment: AI Puzzle #1
//File: main.cpp

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <cstdlib>
#include <vector>
#include <ctime>
#include "greedy.h"
#include "treenode.h"

using namespace std;

int main(int argc, char* argv[])
{
	clock_t initTime = clock();
	float execTime;

	if(argc < 2)
	{
		cout << "Error!! Did you provide at least one .txt input file?" << endl;
		return 0;
	}
	//insert arg checking here
	//also loop this process for multiple files, since
	//the graders probably want to do all the test files in one batch
	int line = 0;

	ifstream gridSpecs(argv[1]);
	string read;
	int quota;
	int maxSwaps;
	int deviceNum;
	int width;
	int height;
	int poolHeight;
	int bonusRules;
	vector<vector<int> > initGrid;	//initial grid
	vector<int> gridRow;			//vector to be inserted into the grid

	string row;					//row last read in from the input file

	if(gridSpecs.is_open())
	{
		getline(gridSpecs, read);
		quota = atoi(read.c_str());
		cout << quota << endl;
		getline(gridSpecs, read);
		maxSwaps = atoi(read.c_str());
		cout << maxSwaps << endl;
		getline(gridSpecs, read);
		deviceNum = atoi(read.c_str());
		cout << deviceNum << endl;
		getline(gridSpecs, read);
		width = atoi(read.c_str());
		cout << width << endl;
		getline(gridSpecs, read);
		height = atoi(read.c_str());
		cout << height << endl;
		getline(gridSpecs, read);
		poolHeight = atoi(read.c_str());
		cout << poolHeight << endl;
		getline(gridSpecs, read);
		bonusRules = atoi(read.c_str());
		cout << bonusRules << endl;

		//initialize grid size
		for(int i = 0; i < height; i++)
		{
			for(int j = 0; j < width; j++)
			{
				gridRow.push_back(0);
			}
			initGrid.push_back(gridRow);
		}
		int c = 0;
		while(getline(gridSpecs, row))
		{
			for(int k = 0; k < width * 2; k += 2)
			{
				initGrid[line][c] = row[k] - '0';
				c++;
			}
			line++;
			c = 0;
		}
	}
	else
	{
		cout << "Error!! Could not open file: " << argv[1] << endl;
		return 0;
	}

	//Grid, treeNode, BFTS declarations and BFTS execution
	Grid grid(quota, maxSwaps, deviceNum, width, height, poolHeight, initGrid);
	grid.displayGrid();

	const treeNode t(grid);
	Greedy solver(t);
	solver.findGoal();

	clock_t timediff = clock() - initTime;
	execTime = (float)timediff / CLOCKS_PER_SEC;
	cout << execTime << endl << endl;

	return 0;
}