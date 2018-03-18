//Name: Chris Murphy
//Date: 2/10/18
//Assignment: AI Puzzle #1
//File: greedy.cpp

#include "greedy.h"

using namespace std;


//Notes:
//Need to explore the whole node before popping, so we need to have
//a tree node which serves as the current node being expanded and
//not try and do it in the queue, since we will be modifying it
//as we expand the current node.



//Put initial treeNode in the queue
Greedy::Greedy(const treeNode& t)
{
	queue.push(t);
}

bool Greedy::notExplored(treeNode& t)
{
	bool e = true;
	for(int i = 0; i < explored.size(); i++)
	{
		if(t.getState().getPoints() == explored[i].getState().getPoints() &&
		   t.getState().getSwaps() == explored[i].getState().getSwaps() )
		{
			if(t.getState() == explored[i].getState())
				e = false;
		}
	}
	return e;
}

bool Greedy::evaluate()
{
	node = queue.top();
	//treeNode* ptr = new treeNode(queue.top()); //to pass to childNode()
	action a;

	//check for goal state
	if(node.getState().goal())
	{
		//We found a goal!!
		node.printActList();
		return true;
	}

	//scan current grid for possible swaps and add children
	//to the temporary list
	for(int i = node.getState().getPoolHeight(); i < node.getState().getHeight(); i++)
	{
		for(int j = 0; j < node.getState().getWidth(); j++)
		{
			if(node.getState().scanHswap(j, i))
			{
				a.setAction(j, i, j+1, i);
				tempList.push_back(node.childNode(node, a));
			}
			if(node.getState().scanVswap(j, i))
			{
				a.setAction(j, i, j, i+1);
				tempList.push_back(node.childNode(node, a));
			}
		}
	}

	//add to explored list
	explored.push_back(queue.top());

	//pop the current top
	queue.pop();

	int maxSwaps = node.getState().getMaxSwaps();
	int currSwaps;

	//add new nodes to queue
	for(int k = 0; k < tempList.size(); k++)
	{
		currSwaps = tempList[k].getState().getSwaps();
		//If the node has already been explored, we don't add it to the
		//queue, otherwise we add it.
		//Unless it has too many swaps, then we also discard it
		if( notExplored(tempList[k]) && (currSwaps < maxSwaps) )
			queue.push(tempList[k]);
	}

	//empty tempList for next batch
	tempList.clear();

	//we finished exploring a non-goal state, so we return false
	//so that we can iterate to the next state to be checked
	return false;	
}

void Greedy::findGoal()
{
	treeNode node;

	//loop while goal is not found
	while( !evaluate() )
	{
		//keep looping
	}

	return;
}