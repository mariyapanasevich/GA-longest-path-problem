#pragma once
#include "GaInAllPath.h"
#include "ProblemWeight.h"
#include <vector>
#include <iostream>

class GAWithWeight :public GaInAllPath
{
private:
	vector <long long> setWeigthforStartPopulation(vector<vector<long long>>, ProblemWeight graph);
	void SortForPopulationWeight();

public:
	vector <long long> weight;
	GAWithWeight(int populationSize):GaInAllPath(populationSize){};
	void generateFirstGenerationWeight(ProblemWeight graph);
};

