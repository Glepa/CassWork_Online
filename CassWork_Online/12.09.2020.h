#pragma once
#include<iostream>
#include<vector>
#include<list>
#include<iomanip>

using namespace std;

vector<int> newColl(vector<int>::const_iterator iterVBeg, vector<int>::const_iterator iterVEnd,
	list<int>::const_iterator iterLBeg, list<int>::const_iterator iterLEnd) {
	vector<int> vect;
	for (; iterVBeg != iterVEnd && iterLBeg!=iterLEnd; ++iterVBeg, ++iterLBeg) {
		vect.push_back((*iterVBeg + *iterLBeg));
	}
	for (int &a : vect)
	{
		cout<<' '<<setw(5)<< a;
	}
	return vect;
}
vector<int> understudy(vector<int>::const_iterator iterVBeg, vector<int>::const_iterator iterVEnd,
	list<int>::const_iterator iterLBeg, list<int>::const_iterator iterLEnd)
{
	vector<int>vect;
	for (auto itV = iterVBeg;itV != iterVEnd; itV++) {
		bool n = true;
		for (auto itL=iterLBeg;itL != iterLEnd;itL++)
		{
			if (*itV == *itL) n = false;
		}
		if(n) vect.push_back(*itV);
	}
	for (auto itL = iterLBeg; itL != iterLEnd; itL++) {
		bool n = true;
		for (auto itV = iterVBeg; itV != iterVEnd; itV++)
		{
			if (*itV == *itL) n = false;
		}
		if (n) vect.push_back(*itL);
	}
	return vect;
}