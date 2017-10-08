#include "GaInAllPath.h"
#include "ProblemWeight.h"
#include <vector>
#include <iostream>
#include "GAWithWeight.h"
#include <algorithm>
#include <random>
#include <ctime>
#include "GA.h"
#include <iterator>

using namespace std;

void GAWithWeight::setWeigth(vector<vector<long long>>&population, vector<long long>&weight, vector<vector<long long>>&weigthPath)
{
	for (size_t i = 0; i < population.size(); i++)
	{
		weigthPath.resize(weigthPath.size() + 1);
		weight.resize(weight.size() + 1);
		for (size_t j = 0; j < population[i].size() - 1; j++)
		{
			vector<long long>::iterator it = find(graph.graph[population[i][j]].begin(), graph.graph[population[i][j]].end(), population[i][j+1]);
			if (it != graph.graph[population[i][j]].end())
			{
				int tmp = it - graph.graph[population[i][j]].begin();
				weight[i] += graph.weigth[population[i][j]][tmp];
				weigthPath[i].push_back(graph.weigth[population[i][j]][tmp]);
			}
		}
	}
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
			swap(weigthPath[i], weigthPath[j]);
		}
	}
}

void GAWithWeight::generateFirstGenerationWeight()
{
	generateFirstGeneration(graph);
	this->Sort1(population);
	population = tmp_population;
//	visited = tmp_visited;
	tmp_population.clear();
	tmp_visited.clear();
	this->setWeigth(population, weight, weigthPath);
	this->SortForPopulationWeight();
}

void GAWithWeight::procedure(ProblemWeight &graph, int step)
{
	this->graph = graph;
	this->generateFirstGenerationWeight();

	int count = 0;
	while (count != step)
	{
		populationSize = population.size();
		for (int i = populationSize; i < 2 * populationSize; i++)
		{
			int p1 = RandomFromDist(populationSize);
			int p2 = RandomFromDist(populationSize);
			this->crossover(population[p1], population[p2]);
			this->mutation(this->new_population, this->newweigthPath, this->new_weight);
			
			
			
			
			
			copy(this->new_population.begin(), this->new_population.end(), back_inserter(population));
			copy(this->new_weight.begin(), this->new_weight.end(), back_inserter(weight));
			copy(this->newweigthPath.begin(), this->newweigthPath.end(), back_inserter(weigthPath));



			newweigthPath.clear();
			new_population.clear();
			new_weight.clear();
			
		}
 		this->SortForPopulationWeight();
		count++;
	}

}

void GAWithWeight::crossover(vector<long long>p1, vector<long long>p2)
{
	vector <long long> preCandidatelist;
	copy(p1.begin(), p1.end(), back_inserter(preCandidatelist));
	vector <long long> candidatelist;
	for (size_t i = 1; i < p2.size(); i++)
	{
		vector<long long>::iterator it = find(preCandidatelist.begin(), preCandidatelist.end(), p2[i]);
		if (it != preCandidatelist.end()) candidatelist.push_back(p2[i]);
	}
	if (candidatelist.size()==0) return;
	    int number = 0 + rand() % (candidatelist.size());
		int i1 = find(p1.begin(), p1.end(), candidatelist[number]) - p1.begin();
		int i2 = find(p2.begin(), p2.end(), candidatelist[number]) - p2.begin();

		new_population.resize(2);
		copy(p1.begin(), p1.begin() + i1, back_inserter(new_population[0]));
		copy(p2.begin() + i2, p2.end(), back_inserter(new_population[0]));
		new_population[0] = RemoveCycles(new_population[0],3);
		copy(p2.begin(), p2.begin() + i2, back_inserter(new_population[1]));
		copy(p1.begin() + i1, p1.end(), back_inserter(new_population[1]));
		new_population[1] = RemoveCycles(new_population[1],3);
		this->setWeigth(this->new_population,this->new_weight,this->newweigthPath);


}

void GAWithWeight::mutation(vector<vector<long long>>&population, vector<vector<long long>>&weigthPath, vector<long long>&weight)
{
	int size = population.size();
	for (size_t i = 0; i < size; i++)
	{
		vector<long long> freeVertex;
		for (size_t j = 0; j < graph.n; j++)
		{
			vector<long long>::iterator it = find(population[i].begin(), population[i].end(), j);
			if (it == population[i].end())
			{
				freeVertex.push_back(j);
			}
		}

		if (freeVertex.size() == 0) break;
		int idx = (freeVertex.size()> 1) ? (0 + rand() % freeVertex.size()):0;
		int x = freeVertex[idx];

		for (int j = 0; j < population[i].size()-1; j++)
		{
			if (graph.relatedVertex(population[i][j], x) && graph.relatedVertex(x, population[i][j+1]))
			{
				int weigthP1 = 0;
				int weigthP2 = 0;

				vector < long long>::iterator it = find(graph.graph[population[i][j]].begin(), graph.graph[population[i][j]].end(), x);
				if (it != graph.graph[population[i][j]].end())
				{
					weigthP1 = graph.weigth[population[i][j]][it - graph.graph[population[i][j]].begin()];
				}
				
				it = find(graph.graph[population[i][j+1]].begin(), graph.graph[population[i][j+1]].end(), x);
				if (it != graph.graph[population[i][j+1]].end())
				{
					weigthP2 = graph.weigth[population[i][j+1]][it - graph.graph[population[i][j+1]].begin()];
				}

				if (weigthPath[i][j] < weigthP1+weigthP2)
				{
					population[i].insert(population[i].begin() + j + 1, x);
					weigthPath[i][j]= weigthP1;
					weigthPath[i].insert(weigthPath[i].begin() + j + 1, weigthP2);

					weight[i] += (weigthP1 + weigthP2);
					freeVertex.erase(freeVertex.begin() + idx);
					break;
				}

			}
		}
		
		idx = (population[i].size() > 1) ? (0 + rand() % population[i].size()) : 0;
		int y = population[i][idx];

		if (freeVertex.size() > 0 && idx != 0 && idx!=population[i].size()-1)
		{

			for (int j = 0; j < freeVertex.size(); j++)
			{
				if (graph.relatedVertex(population[i][idx - 1], freeVertex[j]) && graph.relatedVertex(freeVertex[j], population[i][idx + 1]))
				{
					int weigthP1 = 0;
					vector < long long>::iterator it = find(graph.graph[population[i][idx - 1]].begin(), graph.graph[population[i][idx - 1]].end(), y);
					if (it != graph.graph[population[i][idx - 1]].end())
						weigthP1 = graph.weigth[population[i][idx - 1]][it - graph.graph[population[i][idx - 1]].begin()];

					int weigthP2 = 0;
					it = find(graph.graph[population[i][idx + 1]].begin(), graph.graph[population[i][idx + 1]].end(), y);
					if (it != graph.graph[population[i][idx + 1]].end())
						weigthP2 = graph.weigth[population[i][idx + 1]][it - graph.graph[population[i][idx + 1]].begin()];

					int weigthP3 = weigthP2 + weigthP1;

					int weigthfree1 = 0;
					it = find(graph.graph[population[i][idx - 1]].begin(), graph.graph[population[i][idx - 1]].end(), freeVertex[j]);
					if (it != graph.graph[population[i][idx - 1]].end())
						weigthfree1 = graph.weigth[population[i][idx - 1]][it - graph.graph[population[i][idx - 1]].begin()];

					int weigthfree2 = 0;

					it = find(graph.graph[population[i][idx + 1]].begin(), graph.graph[population[i][idx + 1]].end(), freeVertex[j]);
					if (it != graph.graph[population[i][idx + 1]].end())
						weigthfree2 = graph.weigth[population[i][idx + 1]][it - graph.graph[population[i][idx + 1]].begin()];

					int weigthfree3 = weigthfree2 + weigthfree1;

					if (weigthP3 < weigthfree3)
					{
						weight[i] -= weigthP3;
						weight[i] += weigthfree3;
						population[i][idx] = freeVertex[j];
						weigthPath[i][idx-1] = weigthfree1;
						weigthPath[i][idx] = weigthfree2;
						break;
					}

				}
			}
		}


		if (population[i].size() >= 4)
		{
			for (int j = 1; j < population[i].size() - 2; j++)
			{
				if (graph.relatedVertex(population[i][j - 1], population[i][j + 1]) && graph.relatedVertex(population[i][j + 1], population[i][j]) &&
					graph.relatedVertex(population[i][j], population[i][j + 2]))
				{
					int path = 0;
					int path1 = 0;
					int path2 = 0;
					int path3 = 0;

					vector < long long>::iterator it = find(graph.graph[population[i][j - 1]].begin(), graph.graph[population[i][j - 1]].end(), population[i][j + 1]);
					if (it != graph.graph[population[i][j - 1]].end())
					{
						path1 = graph.weigth[population[i][j - 1]][it - graph.graph[population[i][j - 1]].begin()];
					}

					it = find(graph.graph[population[i][j + 1]].begin(), graph.graph[population[i][j + 1]].end(), population[i][j]);
					if (it != graph.graph[population[i][j + 1]].end())
					{
						path2 = graph.weigth[population[i][j + 1]][it - graph.graph[population[i][j + 1]].begin()];
					}
					it = find(graph.graph[population[i][j]].begin(), graph.graph[population[i][j]].end(), population[i][j + 2]);
					if (it != graph.graph[population[i][j]].end())
					{
						path3 = graph.weigth[population[i][j]][it - graph.graph[population[i][j]].begin()];
					}

					int all = weigthPath[i][j - 1] + weigthPath[i][j] + weigthPath[i][j + 1];

					if (all < path1 + path2 + path3)
					{
						swap(population[i][j], population[i][j + 1]);
						weight[i] -= all;
						weight[i] += (path1 + path2 + path3);
						weigthPath[i][j - 1] = path1;
						weigthPath[i][j] = path2;
						weigthPath[i][j + 1] = path3;
					}
				}
			}
		}
	}
}