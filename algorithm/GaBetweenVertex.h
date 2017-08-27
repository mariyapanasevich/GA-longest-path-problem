#pragma once
#include <vector>
#include "Problem.h"
#include "GA.h"

class GaBetweenVertex :public GA
{
public:
	Problem graph;
	int s; //first vertex
	int t; //last vertex
	vector<vector <long long>> child;
	vector<long long> newChild;

	void print(vector<vector<long long>>  tmp);
	GaBetweenVertex(int populationSize) :GA(populationSize){}
	void startData(int s, int t, Problem graph);
	vector<vector<long long>> Genetic(int Gm);
	vector<long long> RandomPath(int s, int t, Problem g);
	vector<vector<long long>> Unic(vector<vector<long long>>);
	int RandomFromDist(int &populationSize);
	vector<vector <long long>> Crossover(vector <long long>, vector <long long>);
	int Random01();
	vector<long long> RemoveCycles(vector<long long> p);
	vector<long long>  mutationMechanism(vector <long long>, Problem);
	int rightmostindex(vector<long long>, int);
	vector<long long> findVectorNoIncVertex(vector<long long>, Problem);
	int returnRandVertex(vector<long long>, bool);
	int sizeStartPopulation;

	GaBetweenVertex(GaBetweenVertex & obj) :GA(obj)
	{
		typeTask = obj.typeTask;
		s = obj.s;
		t = obj.t;
		sizeStartPopulation = obj.sizeStartPopulation;
	}

};