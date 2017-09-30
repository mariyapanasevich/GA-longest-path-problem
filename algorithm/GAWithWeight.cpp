#include "GaInAllPath.h"
#include "ProblemWeight.h"
#include <vector>
#include <iostream>
#include "GAWithWeight.h"
#include <algorithm>

using namespace std;

vector <long long> GAWithWeight::setWeigthforStartPopulation(vector<vector<long long>> population, ProblemWeight graph)
{
	for (size_t i = 0; i < population.size(); i++)
	{
		weight.resize(weight.size() + 1);
		for (size_t j = 0; j < population[i].size() - 1; j++)
		{
			vector<long long>::iterator it = find(graph[population[i][j]].begin(), graph[population[i][j]].end(), population[i][j + 1]);
			weight[i] += graph.weigth[population[i][j]][it - graph[population[i][j]].begin()];
		}
	}
	return weight;
}

void GAWithWeight::SortForPopulationWeight()
{
	for (size_t i = 0; i < population.size(); i++)
	for (size_t j = i + 1; j < population.size(); j++)
	{     
		if (weight[i] < weight[j])
		{
			swap(weight[i], weight[j]);
			swap(population[i], population[j]);
			swap(visited[i], visited[j]);
		}
	}
}

void GAWithWeight::generateFirstGenerationWeight(ProblemWeight graph)
{
	generateFirstGeneration(graph);
	this->Sort1(population);
	population = tmp_population;
	visited = tmp_visited;
	tmp_population.clear();
	tmp_visited.clear();
	this->setWeigthforStartPopulation(population, graph);
	this->SortForPopulationWeight();
}
