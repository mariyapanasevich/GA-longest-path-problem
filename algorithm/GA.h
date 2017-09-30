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
		time1 = obj.time1;
		res_population = obj.res_population;
	}
	double time1;
	vector<vector<long long> > res_population;


	int populationSize;
	vector<vector<long long>> population;
	bool status;
	int typeTask;
	virtual vector<vector<long long>> Unic(vector<vector<long long>>) = 0;
	vector<vector<long long>> Sort1(vector<vector<long long>> population)
	{
		sort(population.begin(), population.end(), sizecom);
		population = Unic(population);
		return population;
	}
	vector <vector <long long>> Result(vector<vector<long long> > n_population)
	{
		vector <vector <long long> > tmp;

		for (size_t i = 0; i < n_population.size(); i++)
		{
			if (n_population[0].size() == n_population[i].size() || i == 0)
			{
				tmp.resize(tmp.size() + 1);
				for (size_t j = 0; j < n_population[i].size(); j++)
				{
					tmp[i].push_back(n_population[i][j] + 1);
				}
			}
		}

		return tmp;
	}

private:
	bool static sizecom(const vector<long long>&v1, const vector<long long>& v2)
	{
		return v1.size() > v2.size();
	}
};