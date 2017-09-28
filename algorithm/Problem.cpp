#include "Problem.h"
#include <vector>
#include <iostream>
#include <iterator>

Problem::Problem(int n, int m)
{
	this->n = n;
	this->m = m;
	graph.resize(n);
}

void Problem::graph_add(int x, int y)
{
	graph[--x].push_back(y);
	graph[--y].push_back(x);

}

Problem::~Problem()
{
	graph.clear();
}


Problem& Problem:: operator = (const Problem& g)
{
	this->n = g.n;
	this->m = g.m;
	copy(g.graph.begin(), g.graph.end(), std::back_inserter(this->graph));
	return *this;
}

bool Problem::relatedVertex(int v, int n)
{
	std::vector<int>::iterator it = std::find(graph[v].begin(), graph[v].end(), n);
	if (it != graph[v].end())
	{
		return true;
	}
	else
	{
		return false;
	}
}