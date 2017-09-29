#pragma once
#include <vector>
#include <iostream>
#include "Problem.h"

using namespace std;

class ProblemWeight :public Problem
{
public:
	vector<vector<int>>weight;
	ProblemWeight(int n, int m) : Problem(n, m)
	{
		weight.resize(n);

	}
	void graphAddWeight(int x, int y, int weigth);
};
