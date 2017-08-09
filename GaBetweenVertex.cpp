#include "GaBetweenVertex.h"
#include <vector>
#include <random> 
#include <ctime>
#include <algorithm>
#include <functional>
#include <utility>
#include <iterator>

using namespace std;

void GaBetweenVertex::startData(int s, int t, Problem graph)
{
	this->s = s;
	this->t = t;
	this->graph = graph;
}

vector<vector<long long>> GaBetweenVertex::Genetic(int Gm)
{
	srand(time(0));
	for (size_t i = 0; i < populationSize; i++)
	{
		vector<long long> path = RandomPath(s, t, graph);
		if (path.size() > 1 && path.end()[-1] == t - 1)
		{
			population.push_back(path);
		}
	}
	if (!population.empty())
	{
		population = Sort1(population);
		populationSize = population.size();
		int generation = 0;
		int lashchange = 0;
		vector<long long> p;

		while (generation < Gm && (generation - lashchange < Gm / 10) && population[0].size() > population.end()[-1].size())
		{
			for (int i = populationSize; i < 2 * populationSize; i++)
			{

				int p1 = RandomFromDist(populationSize);
				int p2 = RandomFromDist(populationSize);
				child = Crossover(population[p1], population[p2]);
				for (size_t j = 0; j < child.size(); j++)
				{
				  double Mutateprobe = (double)(2*child[j].size()) /(double)(populationSize * (populationSize + 1));
				   int rand01 = Random01();

				   if (rand01 < Mutateprobe)
					{
					   this->mutationMechanism(child[j], graph);
					}
				}
				copy(child.begin(), child.end(), back_inserter(population));
				child.clear();
			}
			population = Sort1(population);
			if (population[0].size() > p.size())
			{
				p.clear();
				copy(population[0].begin(), population[0].end(), back_inserter(p));
				lashchange = generation;
			}
			generation++;
		}
	}
	else
	{
		cout << "fail in find path";
	}
	return population;
}

vector<long long> GaBetweenVertex::RandomPath(int s, int t, Problem graph)
{
	s--;
	t--;
	vector<long long>newPopulation;
	newPopulation.push_back(s);
	int iter = 0;
	while (newPopulation.end()[-1] != t)
	{
		iter++;
		int fail = graph.n / 10;
		bool found = false;

		while (fail > 0 && !found)
		{
			bool valid = false;
			int subfail = (graph.n) / 2;
			int v;
			while (subfail > 0 && !valid)
			{
				v = rand() % graph.n + 0;
				if (s != v)
				{
					if (v == newPopulation.end()[-1] || !graph.relatedVertex(newPopulation.end()[-1], v))
					{
						subfail--;
					}
					else
					{
						valid = true;
					}
				}
			}

			if (subfail == 0)
			{
				fail--;
			}
			else
			{
				found = true;
				vector<long long>::iterator it = find(newPopulation.begin(), newPopulation.end(), v);
				if (it != newPopulation.end())
				{
					fail--;
					found = false;
					break;
				}
			}
			if (found)
			{
				newPopulation.push_back(v);
			}
			else
			{
				newPopulation.push_back(v);
				int tmp;
				do
				{
					tmp = 3 - rand() % 3;
				} while (tmp >= newPopulation.size());
				newPopulation.erase(newPopulation.end() - tmp, newPopulation.end());
			}
		}

		if (iter == graph.n * 4)
		{
			return newPopulation;
		}
	}
	return newPopulation;
}



vector<vector<long long> > GaBetweenVertex::Unic(vector<vector<long long> >population1)
{
	vector<vector<long long>>tmp_population;
	int count = 0;
	for (size_t j = 0; j < population1.size(); j++)
	{
		if (tmp_population.size() == 0)
		{
			tmp_population.push_back(population1[0]);
		}
		else
		{
			count = 0;
			for (size_t k = 0; k < tmp_population.size(); k++)
			{
				if (population1[j] != tmp_population[k])
					count++;
			}
		}
		if (count == tmp_population.size())
		{
			tmp_population.push_back(population1[j]);
		}
	}
	return tmp_population;
}

int GaBetweenVertex::RandomFromDist(int &populationSize)
{
	vector<long long>cuttoffs;
	cuttoffs.push_back(2 * populationSize);

	for (int i = 1; i < populationSize; i++)
	{
		cuttoffs.push_back(cuttoffs[i - 1] + (populationSize - i) * 2);
	}

	int r = rand() % (populationSize*populationSize + populationSize);
	for (int i = 0; i < populationSize; i++)
	{
		if (r < cuttoffs[i])
		{
			return i;
		}
	}
}

vector<vector <long long>> GaBetweenVertex::Crossover(vector<long long> p1, vector<long long> p2)
{
	vector<long long> precandidatelist;
	for (size_t i = 1; i < p1.size(); i++)
	{
		precandidatelist.push_back(p1[i]);
	}

	vector<long long> candidatelist;

	for (size_t i = 1; i < p2.size(); i++)
	{
		vector<long long>::iterator it = find(precandidatelist.begin(), precandidatelist.end(), p2[i]);
		if (it != precandidatelist.end())
		{
			candidatelist.push_back(p2[i]);
		}
	}

	int number = returnRandVertex(candidatelist, true);

	int i1 = find(p1.begin(), p1.end(), candidatelist[number]) - p1.begin();
	int i2 = find(p2.begin(), p2.end(), candidatelist[number]) - p2.begin();

	child.resize(2);

	child[0].push_back(s - 1);
	child[1].push_back(s - 1);

	if (i1 == 0)
	{
		child[0].push_back(p1[i1]);
	}
	else
	{
		copy(p1.begin() + 1, p1.begin() + i1, back_inserter(child[0]));
	}

	copy(p2.begin() + i2, p2.end(), back_inserter(child[0]));

	if (i2 == 0)
	{
		child[1].push_back(p1[i2]);
	}
	else
	{
		copy(p2.begin() + 1, p2.begin() + i2, back_inserter(child[1]));
	}

	copy(p1.begin() + i1, p1.end(), back_inserter(child[1]));

	child[0] = RemoveCycles(child[0]);
	child[1] = RemoveCycles(child[1]);
	return child;
}

vector<long long> GaBetweenVertex::RemoveCycles(vector<long long> p)
{
	int rightpos = 0;
	int pos;
	for (size_t i = 1; i < p.size(); i++)
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
	for (size_t i = 1; i < p.size(); i++)
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

int GaBetweenVertex::rightmostindex(vector<long long> p, int elem)
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

int GaBetweenVertex::Random01()
{
	return rand() % 2;
}

vector<long long> GaBetweenVertex::mutationMechanism(vector<long long> p, Problem G)
{
	vector<long long> noInclude = findVectorNoIncVertex(p, G);
	int idx = returnRandVertex(noInclude, false);
	int x = noInclude[idx];

	for (int i = 1; i < p.size() - 1; i++)
	{
		if (graph.relatedVertex(p[i], x) && graph.relatedVertex(x, p[i + 1]))
		{
			p.insert(p.begin() + i + 1, x);
			noInclude.erase(noInclude.begin() + idx);
			break;
		}
	}

	idx = returnRandVertex(p, false);

	for (int i = 0; i < noInclude.size(); i++)
	{
		if (graph.relatedVertex(p[idx - 1], noInclude[i]) && graph.relatedVertex(noInclude[i], p[idx + 1]))
		{
			p[idx] = noInclude[i];
			break;
		}
	}

	for (int i = 2; i < p.size() - 2; i++)
	{
		if (graph.relatedVertex(p[i - 1], p[i + 1]) && graph.relatedVertex(p[i + 1],p[i]) &&
			graph.relatedVertex(p[i], p[i + 2]))
		{
			swap(p[i], p[i + 1]);
		}
	}

	return p;
} 

vector<long long> GaBetweenVertex::findVectorNoIncVertex(vector<long long>p, Problem graph)
{
	vector<long long> freeVertex;
		for (size_t i = 0; i < graph.n; i++)
		{
			vector<long long>::iterator it = find(p.begin(), p.end(), i);
			if (it == p.end())
			{
				freeVertex.push_back(i);
			}
		}
		return freeVertex;
}

int GaBetweenVertex::returnRandVertex(vector<long long> vec, bool ch)
{
	int tmp =0;
	if (vec.size() > 2 && ch==false)
	{
	   tmp = 1 + rand() % (vec.size() - 2);
	}		
	else if (ch == true && vec.size() > 1)
	{
		tmp = 0 + rand() % (vec.size() - 1);
	}

	return tmp;
}

