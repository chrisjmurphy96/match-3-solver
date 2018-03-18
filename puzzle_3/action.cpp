//Name: Chris Murphy
//Date: 1/31/18
//Assignment: AI Puzzle #1
//File: action.h
#include "action.h"

using namespace std;

action::action()
{
	xCurr = 0;
	yCurr = 0;
	xSwap = 0;
	ySwap = 0;
}

action::action(int x1, int y1, int x2, int y2)
{
	xCurr = x1;
	yCurr = y1;
	xSwap = x2;
	ySwap = y2;
}

vector<int> action::getAction()
{
	//return int coords[4] = {xCurr, yCurr, xSwap, ySwap};
	vector<int> v(4);
	v[0] = xCurr;
	v[1] = yCurr;
	v[2] = xSwap;
	v[3] = ySwap;
	return v;
}

void action::setAction(int x1, int y1, int x2, int y2)
{
	xCurr = x1;
	yCurr = y1;
	xSwap = x2;
	ySwap = y2;

	return;
}

void action::copy(action a)
{
	xCurr = a.xCurr;
	yCurr = a.yCurr;
	xSwap = a.xSwap;
	ySwap = a.ySwap;
}

void action::printAction()
{
	cout << "(" << xCurr << "," << yCurr << "), ";
	cout << "(" << xSwap << "," << ySwap << ")" << endl;
}