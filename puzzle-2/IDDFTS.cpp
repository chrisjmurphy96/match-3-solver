//Name: Chris Murphy
//Date: 2/10/18
//Assignment: AI Puzzle #1
//File: ID-DFTS.cpp

#include "IDDFTS.h"

using namespace std;

ID_DFTS::ID_DFTS(treeNode*& t)
{
	root = t;
	depth = 0;
}

bool ID_DFTS::evaluate(const int currDepth, treeNode* t)
{
	action a;

	//no need to check if it goes beyond depth limit
	if(t->getState().getSwaps() > currDepth)
	{
		return false;
	}

	else if( t->getState().goal() )
	{
		//We found a goal!
		aList.push_back(t->getAction());
		return true;
	}

	for(int i = t->getState().getPoolHeight(); i < t->getState().getHeight(); i++)
	{
		for(int j = 0; j < t->getState().getWidth(); j++)
		{
			//check for valid horizontal swap
			if(t->getState().scanHswap(j, i))
			{
				//If we find a valid swap, we need to generate
				//the corresponding action and child node, and
				//then recursively evaluate the new child node
				a.setAction(j, i, j+1, i);
				if( evaluate(currDepth, t->childNode(a, t)) )
				{
					aList.push_back(t->getAction());
					return true;
				}
			}
			if(t->getState().scanVswap(j, i))
			{
				a.setAction(j, i, j, i+1);
				if( evaluate(currDepth, t->childNode(a, t)) )
				{
					aList.push_back(t->getAction());
					return true;
				}
			}
		}
	}
	//if we don't find the goal node anywhere in the search,
	//we have failed, so we return false
	return false;
}

void ID_DFTS::findGoal()
{
	//Loop to find a goal state
	//Increase depth by 1 each time we fail
	//When evaluate returns true we know we have found a goal node
	while( !evaluate(depth, root) )
	{
		depth++;
	}

	//Print out the action list in reverse order
	for(int i = aList.size()-2; i >= 0; i--)
	{
		aList[i].printAction();
	}

	return;
}
