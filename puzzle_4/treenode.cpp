//Name: Chris Murphy
//Date: 1/31/18
//Assignment: AI Puzzle #1
//File: tree.cpp

#include "treenode.h"
#include "grid.h"
#include "action.h"

using namespace std;


//Copy constructor
treeNode::treeNode(const treeNode& t)
{
	state.gridCopy(t.state);
	//parent = t.parent;	//in this case a shallow copy should be fine
	act.copy(t.act);
	for(int i = 0; i < t.actList.size(); i++)
	{
		actList.push_back(t.actList[i]);
	}
	goalState = t.goalState;
}

//Constructor for root node
treeNode::treeNode(const Grid& g)
{
	state.gridCopy(g);
	//parent = NULL;
	goalState = false;
}

//Constructor for all nodes besides the root
treeNode::treeNode(const Grid& g, const action& a)
{
	act.copy(a);			//action taken to generate child
	//previously state.resutl(g, a) and no gridCopy
	//state.gridCopy(g);
	//state.result(state, a);		//generate resulting state
	state.result(g, a);
	//parent = pPtr;

	//Check if the child is a goal node
	//Based total cost of swaps and the total score
	if(state.goal())
	{
		goalState = true;
	}
	else
	{
		goalState = false;
	}
}

//Constructor called in childNode
treeNode::treeNode(const treeNode& t, const action& a)
{
	state.result(t.state, a);
	act = a;
	//copy old action list
	for(int i = 0; i < t.actList.size(); i++)
	{
		actList.push_back(t.actList[i]);
	}
	//addend new action
	actList.push_back(a);
	goalState = state.goal();
}

treeNode::~treeNode()
{
	//empty for this version of treeNode
}

int treeNode::getF()
{
	//If the state is the goal the function should evalate to 0
	//since we are at the goal and no further moves should
	//be taken.
	if(goalState)
	{
		return 0;
	}

	//Here we define a constant based on the average number
	//of points necessary to guarantee finding a solution
	//within the necessary number of turns.
	int avgPts = state.getQuota() / state.getMaxSwaps();
	//The formula is:
	//f(n) = (swaps taken) + ( (remaining points) / avgPts) )
	//where avgPts was defined above
	return (state.getSwaps() + (state.remPoints() / avgPts) );
}

treeNode treeNode::childNode(const treeNode& t, const action& a)
{
	/*returns a node with:
	STATE = problem.RESULT(parent.STATE,action)
	PARENT = parent
	ACTION = action
	PATH-COST = parent.PATH-COST + 
			problem.STEP-COST(parent.STATE,action)
	*/

	//treeNode* child = new treeNode(state, act, index);
	treeNode child(t, a);

	return child;
}

void treeNode::printActList()
{
	for(int i = 0; i < actList.size(); i++)
	{
		actList[i].printAction();
	}
	return;
}