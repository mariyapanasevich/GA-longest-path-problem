#pragma once
#include "Problem.h"
#include <vector>
#include "GA.h"

class GaInAllGraph :public GA
{
private:
	vector<vector<long long> > index;
	vector<long long> DRS(int, int, Problem &, vector<vector<long long> >&, int);
	
protected:
	vector<vector<long long> > tmp_population;
	vector<vector<bool> > tmp_visited;
	vector<vector<long long> > nonInterseptingPath(Problem&, vector<vector<long long> >&);
	vector<vector<long long> >  intersectingPath(Problem&, vector<vector<long long> >&);
	vector <vector <long long> >mutationMechanism(vector<vector<long long> >&new_population, Problem&D);
	vector<vector<long long> >selection(int, Problem&, vector<vector<long long> >&);
	vector<vector<long long> > Unic(vector<vector<long long>>&, int val, ...);
public:
	vector<vector<bool> > visited;
	vector<vector<long long> > new_population;
	double percent;
	int type;
	GaInAllGraph(int populationSize) :GA(populationSize)
	{
		typeTask = 1;
		population.resize(populationSize);
		visited.resize(populationSize);
	}

	~GaInAllGraph();
	GaInAllGraph(GaInAllGraph & obj) :GA(obj)
	{
		typeTask = obj.typeTask;
		visited = obj.visited;
		percent = obj.percent;
		type = obj.type;
	}
	void clear();
	vector<vector<long long> > generateFirstGeneration(Problem &G);
	vector <vector <long long>>  Result(vector<vector<long long> >);
	vector< vector <long long> > start_nonInterseptingPath(Problem&, int);
	vector <vector <long long> >  start_intersectingPath(Problem&, int);
	vector <vector <long long> > start_mutationMechanism(Problem&, int, int);
	vector <vector <long long> > start_bothPairsOfPaths(Problem&, int, int);
};