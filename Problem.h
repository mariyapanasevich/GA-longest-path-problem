#ifndef PROBLEM_H
#define PROBLEM_H

#include <vector>
#include <iostream>

using namespace std;

class Problem
{

public:

	vector<vector<int> > graph; //список смежных вершин

	int n; //количество вершин в графе
	int m; // количество ребер в графе	
	Problem(int _n, int _m);
	void graph_add(int x, int y);
	~Problem();


};

#endif