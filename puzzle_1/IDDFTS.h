//Name: Chris Murphy
//Date: 2/10/18
//Assignment: AI Puzzle #2
//File: ID-DFTS.h

#include <deque>
#include "treenode.h"
#include "grid.h"
#include "action.h"

#ifndef IDDFTS_H
#define IDDFTS_H

using namespace std;


class ID_DFTS
{
	private:
		treeNode* root;			//root of the IDDFTS tree
		int depth;				//current max depth
		vector<action> aList;	//list of actions taken to 
								//reach the goal node

	public:
		//Constructor for IDDFTS
		ID_DFTS(treeNode*& t);

		//Checks if the tree node t is a goal node. If not, it proceeds
		//to scan the current state and recursively search until either
		//a goal is found within the current depth limit or all children
		//nodes fail to reach a goal state.
		bool evaluate(const int currDepth, treeNode* t);

		//Calls evaluate and prints out the list of actions taken to reach
		//the goal node.
		void findGoal();

};

#endif