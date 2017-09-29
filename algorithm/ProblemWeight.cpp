#pragma once
#include <vector>
#include <iostream>
#include "Problem.h"
#include "ProblemWeight.h"

using namespace std;

void ProblemWeight::graphAddWeight(int x, int y, int weight)
{
	this->graph_add(x, y);
	this->weight[--x].push_back(weight);
	this->weight[--y].push_back(weight);
}
