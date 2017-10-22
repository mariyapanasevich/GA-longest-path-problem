#pragma once
#include <vector>
#include "Problem.h"
#include <algorithm>
#include <iterator>
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
	virtual vector<vector<long long>> Unic(vector<vector<long long>>&, int val, ...) = 0;
	vector<long long> operator[] (int pos)
	{
		return population[pos];
	}


	vector<vector<long long>> Sort1(vector<vector<long long>> population)
	{
		sort(population.begin(), population.end(), sizecom);
		population = Unic(population, 0);
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
	

	vector<long long> RemoveCycles(vector<long long> p, int type)
	{
		int rightpos = 0;
		int pos;
		int number = (type == 2) ? 1:0;
		for (size_t i = number; i < p.size(); i++)
		{
			pos = rightmostindex(p, i);
			if (pos > i && pos > rightpos)
			{
				rightpos = pos;
			}
		}

		if (rightpos == 0)
		{
			return p;
		}

		int leftpos = 0;
		for (size_t i = number; i < p.size(); i++)
		{
			if (p[i] == p[rightpos])
			{
				leftpos = i;
				break;
			}
		}

		vector<long long> new_pop;
		copy(p.begin(), p.begin() + leftpos, back_inserter(new_pop));
		copy(p.begin() + rightpos, p.end(), back_inserter(new_pop));
		return new_pop;
	}

	int rightmostindex(vector<long long> p, int elem)
	{
		int idx = elem;
		for (size_t i = elem + 1; i < p.size(); i++)
		{
			if (p[elem] == p[i])
			{
				idx = i;
			}
		}
		return idx;
	}
private:
	bool static sizecom(const vector<long long>&v1, const vector<long long>& v2)
	{
		return v1.size() > v2.size();
	}
};