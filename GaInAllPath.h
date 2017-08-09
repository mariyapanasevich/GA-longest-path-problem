#pragma once
#include "Problem.h"
#include <vector>

class GaInAllPath
{
private:
	vector<vector<bool> > tmp_visited;
	vector<vector<long long> > index;
	vector<long long> DRS(int, int, Problem &, vector<vector<long long> >&, int);
	vector<vector<long long> > nonInterseptingPath(Problem&, vector<vector<long long> >&);
	vector<vector<long long> > intersctingPaths(Problem&, vector<vector<long long> >&);
	vector<vector<long long> > mutationMechanism(vector<vector<long long> >&, Problem&);
	vector<vector<long long> > tmp_population;

public:
	vector<vector<bool> > visited;
	vector<vector<long long> > population;
	vector<vector<long long> > new_population;
	vector<vector<long long> > res_population;
	double time1;
	double percent;
	GaInAllPath(int PopulationCount1);
	int PopulationCount;
	~GaInAllPath();
	vector<vector<long long> >selection(int, Problem&, vector<vector<long long> >&);
	vector<vector<long long> > unic(vector<vector<long long> >);
	vector<vector<long long> > generateFirstGeneration(Problem&);
	vector <vector <long long>>  Result(vector<vector<long long> >);	
	vector< vector <long long> > start_nonInterseptingPath(Problem&, int);
	vector <vector <long long> >  start_intersctingPaths(Problem&, int);
	vector <vector <long long> > start_mutationMechanism(Problem&, int, int);
	vector <vector <long long> > start_bothPairsOfPaths(GaInAllPath, Problem&, int, int);
};