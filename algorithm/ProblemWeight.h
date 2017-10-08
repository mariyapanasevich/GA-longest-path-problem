#pragma once
#include <vector>
#include <iostream>
#include "Problem.h"

using namespace std;

class ProblemWeight :public Problem
{
public:
	vector<vector<long long >>weigth;
	ProblemWeight() :Problem(){};
	ProblemWeight(int n, int m) : Problem(n, m)
	{
		weigth.resize(n);

	}
	void graphAddWeight(int x, int y, int weigth);
};