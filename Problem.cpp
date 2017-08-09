#include "Problem.h"
#include <vector>
#include <iostream>


Problem::Problem(int _n, int _m)
	{
		n = _n;
		m = _m;
		for (int v = 0; v<n; v++)
			graph.push_back(vector<int>());

	}

	void Problem::graph_add(int x, int y)
	{
		x--; y--;
		graph[x].push_back(y);
		graph[y].push_back(x);

	}

Problem::~Problem()
	{
		graph.clear();
	}



