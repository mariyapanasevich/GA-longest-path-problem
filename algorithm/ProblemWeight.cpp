#pragma once
#include <vector>
#include <iostream>
#include "Problem.h"
#include "ProblemWeight.h"

using namespace std;

void ProblemWeight::graphAddWeight(int x, int y, int weigth)
{
	this->graph_add(x, y);
	this->weigth[--x].push_back(weigth);
	this->weigth[--y].push_back(weigth);
}