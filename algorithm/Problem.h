#ifndef PROBLEM_H
#define PROBLEM_H

#include <vector>
#include <iostream>

using namespace std;

class Problem
{

public:

	vector<vector<long long> > graph;
	Problem(){};
	int n; 
	int m; 
	Problem(int _n, int _m);
	void graph_add(int x, int y);
	~Problem();
	Problem& operator = (const Problem& g);
	bool relatedVertex(int v, int end);
	vector<long long> operator[] (int pos);
};

#endif