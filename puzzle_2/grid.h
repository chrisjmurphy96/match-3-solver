//Name: Chris Murphy
//Date: 1/31/18
//Assignment: AI Puzzle #1
//File: grid.h
#ifndef GRID_H
#define GRID_H

#include <iostream>
#include <vector>
#include <cmath>
#include "action.h"


using namespace std;

//Functions as the mxn grid on which we play Mechanical Match
//Contains functions which generate the pool of values to be dropped
class Grid
{
	private:
		//Grid specifications
		int dNum;					//number of different types of devices
		int w;						//width
		int h;						//total height
		int poolh;					//pool height
		int bonus;					//bonus rules
		int quota;					//target number of points
		int maxSwaps;				//max number of swaps allowed
		int totalPoints;			//points from matches so far
		int totalSwaps;				//swaps taken so far
		//(only in this file until it's clear what bonus rules do)

		vector<vector<int> > g;		//grid vector


	public:
		//Empty constructor
		Grid();

		//Constructor for a grid of mxn dimensions
		Grid(const int pointGoal, const int swapGoal, const int deviceNum, const int width, const int height, const int poolHeight, vector<vector<int> > initGrid);

		//For resizing and filling an already existent grid;
		void gridMake(const int deviceNum, const int width, const int height, const int poolHeight, vector<vector<int> > initGrid);

		void gridCopy(const Grid& original);

		//Destructor for Grid
		//~Grid();

		//Getters
		int getWidth() {return w;}

		int getHeight() {return h;}

		int getPoolHeight() {return poolh;}

		int getPoints() {return totalPoints;}

		int getSwaps() {return totalSwaps;}

		//Scans the current grid coordinates for a match in the given direction
		//Returns true if there is a match
		//We ensure we are passed a valid action, so we only need to check
		//for matches
		action Action(int x, int y, string swap);

		//Updates the grid to match the action taken
		void State(action a);

		//Returns true if a swap to the right can result in a match
		bool scanHswap(int x, int y);

		//Returns true if a swap down can result in a match
		bool scanVswap(int x, int y);

		//Returns true if a match exists to the right of the current cell
		bool scanRight(int x, int y);

		//Returns true if a match exists to the left of the current cell
		bool scanLeft(int x, int y);

		//Returns true if a match exists with the current cell in the middle (horizontally)
		bool scanHmiddle(int x, int y);

		//Uses all three above horizontal scans and returns true if any one of them also returns true
		bool scanHori(int x, int y);

		//Returns true if a match exists below the current cell
		bool scanDown(int x, int y);

		//Returns true if a match exists above the current cell
		bool scanUp(int x, int y);

		//Returns true if a match exists with the current cell in the middle (vertically)
		bool scanVmiddle(int x, int y);

		//Uses all three above vertical scans and returns true if any one of them also returns true
		bool scanVert(int x, int y);

		//Returns a new device value to go at the top of the current column
		int deviceGen(int x, int cycleMatches);

		//Makes all devices above the current x and y fall one space,
		//and uses deviceGen to fill the blank in the pool
		void fall(int x, int y, int cycleMatches);

		//Updates the grid whenever a match occurs
		//Includes falling devices and the new device generation
		void update();

		//Generate a resultant grid from the action taken
		void result(const Grid& g, const action& a);

		//Displays the current grid on screen
		void displayGrid();

		//Returns true if we have reached a goal state
		bool goal();
};

#endif
