//Name: Chris Murphy
//Date: 2/10/18
//Assignment: AI Puzzle #1
//File: pointcompare.cpp

#include "pointcompare.h"

using namespace std;

bool Compare::operator()(treeNode& lhs, treeNode& rhs) const
{
	//Compare the heuristic values of lhs and rhs
	return ( lhs.getH() < rhs.getH() );
}