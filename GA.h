#pragma once
#include <vector>
#include "Problem.h"
#include <algorithm>

class GA
{
public:
	GA(int populationSize) :populationSize(populationSize){};
	GA(GA &obj)
	{
		populationSize = obj.populationSize;
		population = obj.population;
	}
	double time1;
	int populationSize;
	vector<vector<long long>> population;
	virtual vector<vector<long long>> Unic(vector<vector<long long>>) = 0;
	vector<vector<long long>> Sort1(vector<vector<long long>> population)
	{
		sort(population.begin(), population.end(), sizecom);
		population = Unic(population);
		return population;
	}

private:
	bool static sizecom(const vector<long long>&v1, const vector<long long>& v2)
	{
		return v1.size() > v2.size();
	}
};
