//Name: Chris Murphy
//Date: 2/10/18
//Assignment: AI Puzzle #1
//File: greedy.h

#include <iostream>
#include <vector>
#include <queue>
#include "action.h"
#include "treenode.h"
#include "grid.h"
#include "pointcompare.h"

using namespace std;

#ifndef GREEDY_H
#define GREEDY_H

class Greedy
{
	private:
		treeNode node;
		vector<action> aList;
		priority_queue<treeNode, vector<treeNode>, Compare> queue;	//A priority queue
		vector<treeNode> explored; //A list of explored nodes
		vector<treeNode> tempList; //A list of child nodes to be added to
								   //the priority queue


	public:
		Greedy(const treeNode& t);

		//Inserts at queue position
		void insert();

		//If a node is equivalent to a node in the explored list, we
		//do not add the node. In this case we first check points and
		//swaps, then we check the actual grid.
		bool notExplored(treeNode& t);

		//Explore the current state for valid swaps and then add all
		//resulting child nodes to the priority queue to then be
		//examined.
		bool evaluate();

		//Loops evaluate until a goal node is found
		void findGoal();

};

#endif