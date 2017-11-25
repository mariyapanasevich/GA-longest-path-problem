#pragma once
#include "Problem.h"
#include <vector>
#include "GA.h"

class GaInAllGraph :public GA
{
private:
	vector<vector<long long int>> index;
	vector<long long int> DRS(int, int, Problem &, vector<vector<long long int> >&, int);
	int st_status;
protected:
	vector<vector<long long int> > tmp_population;
	vector<vector<bool> > tmp_visited;
	vector<vector<long long int> > nonInterseptingPath(Problem&, vector<vector<long long int> >&);
	vector<vector<long long int> >  intersectingPath(Problem&, vector<vector<long long int> >&);
	vector <vector <long long int> >mutationMechanism(vector<vector<long long int> >&new_population, Problem&D);
	vector<vector<long long int> >selection(int, Problem&, vector<vector<long long int> >&);
	vector<vector<long long int> > Unic(vector<vector<long long int>>&, int val, ...);
public:
	vector<vector<bool> > visited;
	vector<vector<long long int> > new_population;
	bool testforVisited(vector<long long>&, Problem&);

	double percent;
	int type;
	GaInAllGraph(int populationSize) :GA(populationSize)
	{
		typeTask = 1;
		population.resize(populationSize);
		visited.resize(populationSize);
		st_status = 0;
	}

	GaInAllGraph(GaInAllGraph & obj) :GA(obj)
	{
		typeTask = obj.typeTask;
		visited = obj.visited;
		percent = obj.percent;
		type = obj.type;
	}

	~GaInAllGraph();
	void clear();
	vector<vector<long long int> > generateFirstGeneration(Problem &G);
	vector <vector <long long int>>  Result(vector<vector<long long int> >);
	vector< vector <long long int> > start_nonInterseptingPath(Problem&, int);
	vector <vector <long long int> >  start_intersectingPath(Problem&, int, int);
	vector <vector <long long int> > start_mutationMechanism(Problem&, int, int);
	vector <vector <long long int> > start_bothPairsOfPaths(Problem&, int, int);
};