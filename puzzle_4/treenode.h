//Name: Chris Murphy
//Date: 1/31/18
//Assignment: AI Puzzle #1
//File: tree.h
#include <vector>
#include "grid.h"
#include "action.h"

#ifndef TREENODE_H
#define TREENODE_H

using namespace std;

/*
old treeNode class for BFTS
class treeNode
{
	private:
		Grid state;				//current state
		int parent;				//index for parent node
		action act;				//the action that led to the current node
		bool goalState;			//true if the current node is a goal state
		
		//All other relevant information, including the total cost and score,
		//are stored in the Grid class.
	
	public:
		//Default constructor for the root node
		treeNode(const Grid& g);

		//Default constructor with arguments
		treeNode(const Grid& g, const action& a, int pIndex);

		//Getters
		bool getGoal() {return goalState;}

		action getAction() {return act;}

		int getParent() {return parent;}

		Grid getState() {return state;}

		//returns a child node which contains the grid resulting from the passed action
		treeNode* childNode(const action& act, int index);

};
*/


class treeNode
{
	private:
		Grid state;				//current state
		//treeNode* parent;				//index for parent node
		action act;				//the action that led to the current node
		vector<action> actList;
		bool goalState;			//true if the current node is a goal state
		
		//All other relevant information, including the total cost and score,
		//are stored in the Grid class.
	
	public:
		//Copy constructor
		treeNode(const treeNode& t);

		//Empty constructor
		treeNode(): goalState(false) {}

		//Default constructor for the root node
		treeNode(const Grid& g);

		//Default constructor with arguments
		//Currently not in use
		treeNode(const Grid& g, const action& a/*, treeNode* pPtr*/);

		//Constructor called in childNode
		treeNode(const treeNode& t, const action& a);

		//Default destructor
		~treeNode();

		//Copy a node
		void copyNode(treeNode t);

		//Getters
		bool getGoal() {return goalState;}

		action getAction() {return act;}

		//treeNode* getParent() {return parent;}

		Grid getState() {return state;}

		//Returns a function value based on:
		//g(n): the number of swaps taken
		//h(n): the number of swaps remaining based on the number
		//		of points remaining and a constant which is the
		//		average number of swaps needed per turn to complete
		//		the puzzle within the swap limit.
		//Thus f(n) = g(n) + h(n)
		//This returns an int since swaps are whole numbers. You
		//can't have half a swap (or A press)!
		int getF();

		//returns a child node which contains the grid resulting from the passed action
		treeNode childNode(const treeNode& t, const action& a);

		void printActList();

};

#endif