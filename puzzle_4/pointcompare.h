//Name: Chris Murphy
//Date: 2/10/18
//Assignment: AI Puzzle #1
//File: pointcompare.h

#include <iostream>
#include <vector>
#include <queue>
#include "grid.h"
#include "treenode.h"

using namespace std;

#ifndef POINTCOMPARE_H
#define POINTCOMPARE_H


//A class that overloads the () operator for the purpose of passing to
//the standard C++ priority queue constructor
class Compare
{
	public:
		bool operator()(treeNode& lhs, treeNode& rhs) const;
};

#endif