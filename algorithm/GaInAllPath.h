#pragma once
#include "Problem.h"
#include <vector>
#include "GA.h"

class GaInAllPath :public GA
{
private:
	vector<vector<bool> > tmp_visited;
	vector<vector<long long> > index;
	vector<long long> DRS(int, int, Problem &, vector<vector<long long> >&, int);
	vector<vector<long long> > nonInterseptingPath(Problem&, vector<vector<long long> >&);
	vector<vector<long long> > intersctingPaths(Problem&, vector<vector<long long> >&);
	vector<vector<long long> > tmp_population;
	vector <vector <long long> >mutationMechanism(vector<vector<long long> >&new_population, Problem&D);

public:
	vector<vector<bool> > visited;
	vector<vector<long long> > new_population;
	double percent;
	int type;
	GaInAllPath(int populationSize) :GA(populationSize)
	{
		typeTask = 1;
		population.resize(populationSize);
		visited.resize(populationSize);
	}

	~GaInAllPath();
	GaInAllPath(GaInAllPath & obj) :GA(obj)
	{
		typeTask = obj.typeTask;
		visited = obj.visited;
		percent = obj.percent;
		type = obj.type;	
	}
	void clear();
	vector<vector<long long> >selection(int, Problem&, vector<vector<long long> >&);
	vector<vector<long long> > Unic(vector<vector<long long>>);
	vector<vector<long long> > generateFirstGeneration(Problem&);
	vector <vector <long long>>  Result(vector<vector<long long> >);
	vector< vector <long long> > start_nonInterseptingPath(Problem&, int);
	vector <vector <long long> >  start_intersctingPaths(Problem&, int);
	vector <vector <long long> > start_mutationMechanism(Problem&, int, int);
	vector <vector <long long> > start_bothPairsOfPaths(Problem&, int, int);
};