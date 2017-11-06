#pragma once
#include "GaInAllGraph.h"
#include "ProblemWeight.h"
#include <vector>
#include <iostream>
#include "GaBetweenVertex.h"

class GAWithWeight :public GaInAllGraph
{
private:
	ProblemWeight graph;
	vector<vector<long long>> weigthPath;
	vector <long long> weight;
	vector<vector<long long>> newweigthPath;
	vector <long long> new_weight;
	void setWeigth(vector<vector<long long>>&, vector<long long>&, vector<vector<long long>>&);
	void SortForPopulationWeight();
	bool mutationProb();
	void SortForPopulationWeight(vector<vector<int>> population);
	int selection(vector<vector<long long>>&, vector <long long>&, int param...);
	void crossover(vector<long long>, vector<long long>);
	void mutation(vector<vector<long long>>&, vector<vector<long long>>&, vector<long long>&);
	int randomRepeat(int size, int param ...);
	void generateFirstGenerationWeight();
	void resultPaths(vector<vector<long long>>&, vector<long long>&, vector<vector<long long>>&);
	void clear();

public:
    int resWeigth;
	vector<vector<long long>> resWeigthPath;

	double probabilityMutation;
	GAWithWeight(int populationSize) :GaInAllGraph(populationSize){
		typeTask = 3;
	}
	void procedure(ProblemWeight &graph, int step);
};

