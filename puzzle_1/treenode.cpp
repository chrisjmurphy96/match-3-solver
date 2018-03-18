//Name: Chris Murphy
//Date: 1/31/18
//Assignment: AI Puzzle #1
//File: tree.cpp

#include "treenode.h"
#include "grid.h"
#include "action.h"

using namespace std;

/*
//Constructor for root node
treeNode::treeNode(const Grid& g)
{
	state.gridCopy(g);
	parent = -1;
	goalState = false;
}

//Constructor for all nodes besides the root
treeNode::treeNode(const Grid& g, const action& a, int pIndex)
{
	act.copy(a);			//action taken to generate child
	//previously state.resutl(g, a) and no gridCopy
	//state.gridCopy(g);
	//state.result(state, a);		//generate resulting state
	state.result(g, a);
	parent = pIndex;

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

treeNode* treeNode::childNode(const action& act, int index)
{
	/*returns a node with:
	STATE = problem.RESULT(parent.STATE,action)
	PARENT = parent
	ACTION = action
	PATH-COST = parent.PATH-COST + 
			problem.STEP-COST(parent.STATE,action)
	

	//treeNode* child = new treeNode(state, act, index);
	treeNode* child = new treeNode(state, act, index);

	return child;
}
*/

//Constructor for root node
treeNode::treeNode(const Grid& g)
{
	state.gridCopy(g);
	parent = NULL;
	goalState = false;
}

//Constructor for all nodes besides the root
treeNode::treeNode(const Grid& g, const action& a, treeNode* pPtr)
{
	act.copy(a);			//action taken to generate child
	//previously state.resutl(g, a) and no gridCopy
	//state.gridCopy(g);
	//state.result(state, a);		//generate resulting state
	state.result(g, a);
	parent = pPtr;

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

treeNode::~treeNode()
{
	parent = NULL;
	delete parent;
}

treeNode* treeNode::childNode(const action& act, treeNode* pPtr)
{
	/*returns a node with:
	STATE = problem.RESULT(parent.STATE,action)
	PARENT = parent
	ACTION = action
	PATH-COST = parent.PATH-COST + 
			problem.STEP-COST(parent.STATE,action)
	*/

	//treeNode* child = new treeNode(state, act, index);
	treeNode* child = new treeNode(state, act, pPtr);

	return child;
}