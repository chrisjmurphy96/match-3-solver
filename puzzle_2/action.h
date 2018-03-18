//Name: Chris Murphy
//Date: 1/31/18
//Assignment: AI Puzzle #1
//File: action.h
#ifndef ACTION_H
#define ACTION_H

#include <iostream>
#include <vector>


using namespace std;

//Stores the swap action that took place to reach the current node
class action
{
	private:
		int xCurr, yCurr;		//current grid space
		int xSwap, ySwap;		//grid space to swap with
	public:
		//Default constructor
		//Initializes all values to 0
		action();

		//Default constructor for action
		//x1 and y1 denote the current, x2 and y2 denote the grid space
		//that was swapped with
		action(int x1, int y1, int x2, int y2);

		//Array returns the coordinates in order of:
		//x1, y1, x2, y2
		vector<int> getAction();

		//Sets action to the corresponding passed coordinate actions
		void setAction(int x1, int y1, int x2, int y2);

		//Copies values from passed action into the current action
		void copy(action a);

		//Prints out the coordinates being swapped
		void printAction();
};

#endif
