#pragma once
#include "GaInAllPath.h"
#include "ProblemWeight.h"
#include <vector>
#include <iostream>
#include "GaBetweenVertex.h"

class GAWithWeight :public  GaInAllPath
{
private:
	void setWeigth(vector<vector<long long>>&, vector<long long>&, vector<vector<long long>>&);
	void SortForPopulationWeight();
	ProblemWeight graph;
public:
	vector<vector<long long>> weigthPath;
	vector <long long> weight;
	vector<vector<long long>> newweigthPath;
	vector <long long> new_weight;
	void generateFirstGenerationWeight();
	GAWithWeight(int populationSize) :GaInAllPath(populationSize){}
	void SortForPopulationWeight(vector<vector<int>> population);
	void procedure(ProblemWeight &graph, int step);
	void mutation(vector<vector<long long>>&, vector<vector<long long>>&, vector<long long>&);
	void crossover(vector<long long>,vector<long long>);
	void mutationProb(int Persent, vector<vector<long long>>&, vector<vector<long long>>&, vector<long long>&);

};

