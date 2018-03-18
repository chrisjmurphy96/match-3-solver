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
	copyNode(t);
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

void treeNode::copyNode(treeNode t)
{
	state.gridCopy(t.state);
	act.copy(t.act);
	for(int i = 0; i < t.actList.size(); i++)
	{
		actList.push_back(t.actList[i]);
	}
	goalState = t.goalState;
}

int treeNode::getH()
{
	return (state.getPoints()) / (state.getSwaps());
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