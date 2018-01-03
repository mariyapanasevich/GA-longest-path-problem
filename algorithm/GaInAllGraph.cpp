#include "GaInAllGraph.h"
#include <ctime>
#include  <vector>
#include "Problem.h"
#include <iterator>
#include <random>
#include <algorithm>
#include <iostream>
//#include <cmath> 
#include <stdarg.h>

using namespace std;

GaInAllGraph::~GaInAllGraph()
{
	population.clear();
	visited.clear();
	tmp_visited.clear();
	index.clear();
	new_population.clear();
	//delete this;
}

vector<long long int>GaInAllGraph::DRS(int i, int i1, Problem &G, vector<vector<long long int> >&population, int number)
{
	vector<long long int>notVis;

	if (number == 1)
	{
		population[i].push_back(i1);
		visited[i][i1] = true;
	}

	if (number == 3)
	{
		population[i].insert(population[i].begin(), i1);
		visited[i][i1] = true;
	}

	int n = G.graph[i1].size();
	notVis.resize(n);

	int k = 0;

	for (size_t j = 0; j < n; j++)
	{
		int p = G.graph[i1][j];
		bool s = visited[i][p];
		if (!s)
		{
			notVis[k] = G.graph[i1][j];
			k++;
		}
	}

	int vertex = 0;
	if (k >= 1)
	{
		if (k > 1)
		{
			int p = k - 1;
			mt19937 gen(time(0));
			uniform_int_distribution<> uid(0, p);
			vertex = uid(gen);
		}

		if (k == 1)
		{
			vertex = 0;
		}

		int r = notVis[vertex];
		if (number == 2 || number == 1)
		{
			DRS(i, r, G, population, 1);
		}
		else if (number = 4 || number == 3) DRS(i, r, G, population, 3);
	}
	return population[i];
}

vector<vector<long long int> > GaInAllGraph::generateFirstGeneration(Problem &G)
{
	for (size_t i = 0; i < population.size(); i++)
	{
		visited[i].resize(G.n);
		for (size_t j = 0; j < G.n; j++)
		{
			visited[i][j] = false;
		}
		int l = rand() % (G.n - 1);
	//	population[i].push_back(l);
		population[i] = DRS(i, l, G, population, 1);
	}
	return population;
}

vector<vector<long long int> > GaInAllGraph::Unic(vector<vector<long long int> >&population1, int value, ...)
{
	vector<int>param_vec;
	va_list L;
	int val = value;
	bool n = false;
	va_start(L, value);
	if (value >= 1)
	{
		while (value--)
		{
			n=va_arg(L, bool);
		}

		va_end(L);
	}

	int count = 0;
	for (size_t j = 0; j < population1.size(); j++)
	{
		if (tmp_population.size() == 0)
		{
			tmp_population.push_back(population1[0]);
			if(n == false) tmp_visited.push_back(visited[0]);
		}
		else
		{
			count = 0;
			for (size_t k = 0; k < tmp_population.size(); k++)
			{
				vector<long long int>a;
				a.resize(population1[j].size());
				reverse_copy(population1[j].begin(), population1[j].end(), a.begin());
				if (population1[j] != tmp_population[k] && a != tmp_population[k])
					count++;
			}
		}


		if (count == tmp_population.size())
		{
			tmp_population.push_back(population1[j]);
			if (n == false) tmp_visited.push_back(visited[j]);
		}

	}

	return tmp_population;
}

vector<vector<long long int> > GaInAllGraph::selection(int i, Problem &G, vector<vector<long long int> >&population1)
{

	new_population.clear();
	tmp_population.clear();
	tmp_visited.clear();
	status = false;
	if (visited.empty())
	{
		visited.resize(population1.size());
		for (size_t m = population1.size(); m > 0; m--)
		{
			visited[population1.size() - m].resize(G.n);
			for (size_t k = 0; k < population1[population1.size() - m].size(); k++)
			{
				visited[population1.size() - m][population1[population1.size() - m][k]] = true;
			}
		}
	}

	for (size_t i = 0; i < population1.size(); i++)
	for (size_t j = i + 1; j < population1.size(); j++)
	{
		if (population1[i].size() < population1[j].size())
		{
			swap(population1[i], population1[j]);
			swap(visited[i], visited[j]);
		}
	}

	Unic(population1, 1, false);
	int p = tmp_population.size()*percent;
	//tmp_population.resize(p);
	switch (i)
	{
	case 3:
	{
			  const size_t it = percent * population.size();
			  copy(tmp_population.begin(), tmp_population.begin() + ((tmp_population.size() < it) ? tmp_population.size() : it), back_inserter(new_population));
			  copy(tmp_visited.begin(), tmp_visited.begin() + ((tmp_population.size() < it) ? tmp_population.size() : it), back_inserter(visited));
			  break;
	}

	case 1:
	{
			  visited.clear();
			  int count;
			  size_t size1 = tmp_population.size();
			  int count_cross = 0;

			  for (size_t i = 0; i < tmp_population.size() / 2; i++)
			  {
				  for (size_t k = 0; k < tmp_population.size(); k++)
				  {
					  count = 0;
					  if (i != k)
					  {
						  for (int j = 0; j < G.n; j++)
						  {
							  if (tmp_visited[k][j] == tmp_visited[i][j] && (tmp_visited[k][j] == true)) count++;
							  if (count > 0) break;
						  }

						  if (count == 0)
						  {
							  new_population.push_back(tmp_population[i]);
							  visited.push_back(tmp_visited[i]);
							  new_population.push_back(tmp_population[k]);
							  visited.push_back(tmp_visited[k]);
							  count_cross++;
						  }

					  }

				  }

			  }

			  if (size1 == tmp_population.size() && count_cross == 0)
			  {
//				  cout << "There aren't non-intersepting paths.\n";
				  status = true;
				  return tmp_population;

				  break;
			  }

			  else
			  {
				  int i = new_population.size()*percent;
				  if (i % 2 == 0)
				  {
					  new_population.resize(i);
					  visited.resize(i);
				  }
				  else
				  {
					  new_population.resize(i + 1);
					  visited.resize(i + 1);
				  }
			  }
			  break;
	}

	case 2:
	{
			  visited.clear();
			  int count = 0;
			  size_t size1 = tmp_population.size();

			  index.clear();

			  for (size_t i = 0; i < tmp_population.size() / 2; i++)
			  {

				  for (size_t k = 0; k < tmp_population.size(); k++)
				  {
					  count = 0;
					  if (i != k && i < k)
					  {
						  for (size_t j = 0; j < G.n; j++)
						  {
							  if (tmp_visited[k][j] == tmp_visited[i][j] && tmp_visited[k][j] == true)
							  {
								  count++;
							  }
						  }

						  if (count > 0)
						  {
							  int beg1 = 0, beg2 = 0, end1 = 0, end2 = 0, ct = 0;

							  for (size_t m = 0; m < tmp_population[i].size(); m++)
							  {
								  for (size_t n = 0; n < tmp_population[k].size(); n++)
								  {

									  if (tmp_population[i][m] == tmp_population[k][n])
									  {
										  if (ct == 0)
										  {
											  beg1 = m;
											  beg2 = n;
											  end1 = m;
											  end2 = n;
											  ct++;
											  break;
										  }
										  else
										  {
											  if ((n - end2 == 1 || n - end2 == -1) && (m - end1 == 1))
											  {

												  end1 = m;
												  end2 = n;
												  ct++;
												  break;

											  }

											  else
											  {

												  if (beg1 != 0 && beg1 != tmp_population[i].size() - 1 && end1 != 0 && end1 != tmp_population[i].size() - 1
													  && beg2 != 0 && beg2 != tmp_population[k].size() - 1 && end2 != 0 && end2 != tmp_population[k].size() - 1

													  )
												  {
													  new_population.push_back(tmp_population[i]);
													  new_population.push_back(tmp_population[k]);
													  visited.push_back(tmp_visited[i]);
													  visited.push_back(tmp_visited[k]);
													  index.resize(index.size() + 1);
													  index[index.size() - 1].push_back(beg1);
													  index[index.size() - 1].push_back(beg2);
													  index[index.size() - 1].push_back(end1);
													  index[index.size() - 1].push_back(end2);

												  }
												  ct = 1;
												  beg1 = m;
												  beg2 = n;
												  end1 = m;
												  end2 = n;
												  break;
											  }

										  }
									  }
									  if (m == tmp_population[i].size() - 1 && n == tmp_population[k].size() - 1 && beg1 != 0 && beg1 != tmp_population[i].size() - 1 && end1 != 0 && end1 != tmp_population[i].size() - 1
										  && beg2 != 0 && beg2 != tmp_population[k].size() - 1 && end2 != 0 && end2 != tmp_population[k].size() - 1)

									  {
										  new_population.push_back(tmp_population[i]);
										  new_population.push_back(tmp_population[k]);
										  visited.push_back(tmp_visited[i]);
										  visited.push_back(tmp_visited[k]);
										  index.resize(index.size() + 1);
										  index[index.size() - 1].push_back(beg1);
										  index[index.size() - 1].push_back(beg2);
										  index[index.size() - 1].push_back(end1);
										  index[index.size() - 1].push_back(end2);
									  }

								  }
							  }
						  }
					  }
				  }
			  }
			  size_t size2 = (new_population.size()) ? new_population.size() : 0;

			  if (size2 == 0)
			  {
				  status = true;
				  return tmp_population;
				  break;

			  }
			  else
			  {
				  if (new_population.size() > 100)
				  {

					  if (i % 2 == 0)
					  {
						  new_population.resize(i);
						  visited.resize(i);
					  }
					  else
					  {
						  new_population.resize(i + 1);
						  visited.resize(i + 1);
					  }
				  }
				  break;
			  }
	}
	}
	return new_population;
}


vector<vector<long long int> >GaInAllGraph::nonInterseptingPath(Problem&G, vector<vector<long long int> >&new_population)
{
	int v1;
	
	vector<int>pre_candidation;
	vector<pair<int, int>>pre_candidation_idx;
	size_t size = new_population.size();
	for (size_t i = 0; i < size; i = i + 2)
	{
		for (size_t j = 1; j < new_population[i].size() - 1; j++)
		{
			for (size_t k = 0; k < G.graph[new_population[i][j]].size() - 1; k++)
			{
				for (size_t l = 0; l < new_population[i + 1].size() - 1; l++)
				{
					if (G.graph[new_population[i][j]][k] == new_population[i + 1][l])
					{
						pre_candidation.push_back(G.graph[new_population[i][j]][k]);
						pre_candidation_idx.resize(pre_candidation_idx.size()+1);
						pre_candidation_idx[pre_candidation_idx.size() - 1].first = j;
						pre_candidation_idx[pre_candidation_idx.size() - 1].second = l;

					}
				}
			}
		}
		
		if (pre_candidation.size() > 0)
		{
			v1 = (pre_candidation.size() == 1)?0:(rand() % pre_candidation.size());
			visited.resize(new_population.size() + 4);
			new_population.resize(new_population.size() + 4);
			copy(new_population[i].begin(), new_population[i].begin() + pre_candidation_idx[v1].first , back_inserter(new_population[new_population.size() - 4]));
			copy(new_population[i + 1].begin() + pre_candidation_idx[v1].second, new_population[i + 1].end(), back_inserter(new_population[new_population.size() - 4]));
			copy(new_population[i + 1].begin(), new_population[i + 1].begin() + pre_candidation_idx[v1].second, back_inserter(new_population[new_population.size() - 3]));
			copy(new_population[i].begin() + pre_candidation_idx[v1].first, new_population[i].end(), back_inserter(new_population[new_population.size() - 3]));
			copy(new_population[i].begin(), new_population[i].begin() + pre_candidation_idx[v1].first , back_inserter(new_population[new_population.size() - 2]));
			vector<int>a;
			a.resize(pre_candidation_idx[v1].second + 1);
			reverse_copy(new_population[i + 1].begin(), new_population[i + 1].begin() + pre_candidation_idx[v1].second + 1, a.begin());
			copy(a.begin(), a.end(), back_inserter(new_population[new_population.size() - 2]));
			a.clear();
			a.resize(new_population[i].size() - pre_candidation_idx[v1].first);
			reverse_copy(new_population[i].begin() + pre_candidation_idx[v1].first, new_population[i].end(), a.begin());
			copy(a.begin(), a.end(), back_inserter(new_population[new_population.size() - 1]));
			copy(new_population[i + 1].begin() + pre_candidation_idx[v1].second, new_population[i + 1].end(), back_inserter(new_population[new_population.size() - 1]));

			for (size_t m = 4; m > 0; m--)
			{
				visited[new_population.size() - m].resize(G.n);
				for (size_t k = 0; k < new_population[new_population.size() - m].size(); k++)
				{
					visited[new_population.size() - m][new_population[new_population.size() - m][k]] = true;
				}
			}

			pre_candidation.clear();
			pre_candidation_idx.clear();
		}
			
	}

	return new_population;
}

vector < vector <long long int > > GaInAllGraph::start_nonInterseptingPath(Problem&D, int i)
{
	type = 1;
	vector<vector<long long int> >sel;
	vector<vector<long long int> >disjoint;

	unsigned int start_time = clock();
	sel = selection(i, D, population);
	size_t count = (new_population.size()>0) ? new_population.size() : 0;
	int size1 = 0;
	int size2 = 0;

	if (count>0)
	{
		do
		{
			size1 = size2;
			disjoint = nonInterseptingPath(D, sel);
			sel.clear();
			sel = selection(i, D, disjoint);
			if (status == true) break;
			disjoint.clear();
			size2 = sel.size();
			if (sel.empty()) break;
		} while (size1 != size2);
	}

	unsigned int end_time = clock();
	time1 = (end_time - start_time) / 1000.0;
	visited.clear();
	copy(tmp_visited.begin(), tmp_visited.end(), back_inserter(visited));
	tmp_visited.clear();
	Unic(tmp_population, 1, false);
	res_population = Result(tmp_population);
	return res_population;
}

bool GaInAllGraph::testforVisited(vector<long long>&vec, Problem&G)
{
	vector<int>visitedPath;
	visitedPath.resize(G.n);
	bool visited = false;
	
	for (size_t k = 0; k < vec.size(); k++)
	{
		vector<long long int>::iterator it = find(vec.begin(), vec.end(), vec[k]);
		if (it != vec.end())
		{
			visitedPath[*it]++;
		}
	}

	for (size_t j = 0; j < visitedPath.size(); j++)
	{
		if (visitedPath[j] > 1)
		{
			visited = true;
			break;
		}
	}
	return visited;
}


vector<vector<long long int> >GaInAllGraph::intersectingPath(Problem&G, vector<vector<long long int> >&new_population)
{

	int size = new_population.size();
	for (size_t i = 0; i < size; i = i + 2)
	{
		int count = 0;
		for (size_t j = 0; j < visited[i].size(); j++)
		{
			if (visited[i][j] == visited[i + 1][j] && visited[i][j] == true)
			{
				count++;
			}
		}
		if ((index[i / 2][0] == index[i / 2][2]) && (index[i / 2][1] == index[i / 2][3]))
		{
			int size = new_population.size() + 4;
			new_population.resize(size);
			//1 child
			copy(new_population[i].begin(), new_population[i].begin() + index[i / 2][0], back_inserter(new_population[new_population.size() - 4]));
			copy(new_population[i + 1].begin() + index[i / 2][1], new_population[i + 1].end(), back_inserter(new_population[new_population.size() - 4]));
			if (testforVisited(new_population[new_population.size() - 4], G))   new_population[new_population.size() - 4] = RemoveCycles(new_population[new_population.size() - 4], 1);

			//2 child
			copy(new_population[i].begin(), new_population[i].begin() + index[i / 2][0], back_inserter(new_population[new_population.size() - 3]));
			vector<int>a;
			a.resize(new_population[i + 1].size());
			reverse_copy(new_population[i + 1].begin(), new_population[i + 1].end(), a.begin());
			int end2 = find(a.begin(), a.end(), new_population[i + 1][index[i / 2][1]]) - a.begin();
			copy(a.begin(), a.begin() + end2, back_inserter(new_population[new_population.size() - 3]));

			if (testforVisited(new_population[new_population.size() - 3], G)) new_population[new_population.size() - 3] = RemoveCycles(new_population[new_population.size() - 3], 1);

			//3 child
			copy(a.begin(), a.begin() + new_population[i + 1].size() - index[i / 2][1], back_inserter(new_population[new_population.size() - 2]));
			copy(new_population[i].begin() + index[i / 2][0], new_population[i].end(), back_inserter(new_population[new_population.size() - 2]));

			if (testforVisited(new_population[new_population.size() - 2], G)) new_population[new_population.size() - 2] = RemoveCycles(new_population[new_population.size() - 2], 1);

			//4 child
			copy(new_population[i + 1].begin(), new_population[i + 1].begin() + index[i / 2][1], back_inserter(new_population[new_population.size() - 1]));
			copy(new_population[i].begin() + index[i / 2][0], new_population[i].end(), back_inserter(new_population[new_population.size() - 1]));


			if (testforVisited(new_population[new_population.size() - 1], G)) new_population[new_population.size() - 1] = RemoveCycles(new_population[new_population.size() - 1], 1);

			for (size_t m = 4; m >0; m--)
			{
				visited.resize(visited.size() + 1);
				visited[new_population.size() - m].resize(G.n);
				for (size_t k = 0; k < new_population[new_population.size() - m].size(); k++)
				{
					visited[new_population.size() - m][new_population[new_population.size() - m][k]] = true;
				}
			}

		}
		else if ((index[i / 2][0] != index[i / 2][2]) && (index[i / 2][1] != index[i / 2][3]))
		{
			if ((index[i / 2][0] < index[i / 2][2] && index[i / 2][1] < index[i / 2][3]) || (index[i / 2][0] < index[i / 2][2] && index[i / 2][1] > index[i / 2][3]))
			{
				new_population.resize(new_population.size() + 2);
				copy(new_population[i].begin(), new_population[i].begin() + index[i / 2][2], back_inserter(new_population[new_population.size() - 2]));
				copy(new_population[i + 1].begin() + index[i / 2][3], new_population[i + 1].end(), back_inserter(new_population[new_population.size() - 2]));
			
				if (testforVisited(new_population[new_population.size() - 2], G))  new_population[new_population.size() - 2] = RemoveCycles(new_population[new_population.size() - 2], 1);
				copy(new_population[i + 1].begin(), new_population[i + 1].begin() + index[i / 2][3], back_inserter(new_population[new_population.size() - 1]));
				copy(new_population[i].begin() + index[i / 2][2], new_population[i].end(), back_inserter(new_population[new_population.size() - 1]));	
				if (testforVisited(new_population[new_population.size() - 1], G))  new_population[new_population.size() - 1] = RemoveCycles(new_population[new_population.size() - 1], 1);

			}
			else
			{
				new_population.resize(new_population.size() + 2);
				size_t idx = index[i / 2][2];
				copy(new_population[i].begin(), new_population[i].begin() + idx, back_inserter(new_population[new_population.size() - 2]));

				vector<long long int>a;
				a.resize(new_population[i + 1].size());
				reverse_copy(new_population[i + 1].begin(), new_population[i + 1].end(), a.begin());
				int end2 = find(a.begin(), a.end(), new_population[i + 1][index[i / 2][3]]) - a.begin();

				copy(a.begin() + end2, a.end(), back_inserter(new_population[new_population.size() - 2]));
				if (testforVisited(new_population[new_population.size() - 2], G))  new_population[new_population.size() - 2] = RemoveCycles(new_population[new_population.size() - 2], 1);
				idx = end2 + 1;

				copy(a.begin(), a.begin() + idx, back_inserter(new_population[new_population.size() - 1]));
				copy(new_population[i].begin(), new_population[i].begin() + index[i / 2][2], back_inserter(new_population[new_population.size() - 1]));
				if (testforVisited(new_population[new_population.size() - 1], G))  new_population[new_population.size() - 1] = RemoveCycles(new_population[new_population.size() - 1], 1);			
			}

			for (size_t m = 2; m > 0; m--)
			{
				visited.resize(visited.size() + 1);
				visited[new_population.size() - m].resize(G.n);
				for (size_t k = 0; k < new_population[new_population.size() - m].size(); k++)
				{
					visited[new_population.size() - m][new_population[new_population.size() - m][k]] = true;
				}
			}
		}
	}

	return new_population;
}

vector <vector <long long int> > GaInAllGraph::start_intersectingPath(Problem&D, int i, int n)
{
	type = 2;
	vector<vector<long long int> >sel;
	vector<vector<long long int> >join;
	int size1 = 0;
	int size2 = 0;
	int size3 = 0;
	unsigned int search_time;
	unsigned int start_time = clock();
	sel = selection(i, D, population);
	size_t count = (new_population.size()>0) ? new_population.size() : 0;
	size_t z = 0;
	if (count>0)
	{
		int ct = 0;
		do
		{
	     	if (ct >= n) break;
			size3 = size1;
			join = intersectingPath(D, sel);
			size1 = size2;
			sel = selection(i, D, join);
			if (sel.empty()) break;
			size2 = tmp_population.size();
			ct++;
			if (size1 == size2) break;
			else if (size2 == size3) break;

		} while (size1!=size2 || size2!=size3 || ct < n);

	}

	if (count == 0)
	{
		visited.clear();
		for (size_t m = sel.size(); m >0; m--)
		{
			visited.resize(visited.size() + 1);
			visited[sel.size() - m].resize(D.n);
			for (size_t k = 0; k < sel[sel.size() - m].size(); k++)
			{
				visited[sel.size() - m][sel[sel.size() - m][k]] = true;
			}
		}
	}

	unsigned int end_time = clock();
	time1 = (end_time - start_time) / 1000.0;
	Unic(tmp_population, 1, false);
	res_population = Result(tmp_population);
	return res_population;

}

vector<vector<long long int>> GaInAllGraph::mutationMechanism(vector<vector<long long int> >&new_population, Problem &G)
{
	int v1;
	int v2;
	int m = new_population.size();
	for (size_t g = 0; g < m; g++)
	{
		int r1 = (new_population[g].size() / 2);
		int p1 = 0;
		do {
			v1 = rand() % r1;
			p1++;
			if (G.graph[v1].size() < 3) break;
		} while (p1 < r1);

		int r2 = r1 + 1;
		int p2 = 0;
		do {
			v2 = rand() % (new_population[g].size() - r1) + r1;
			p2++;
			if (G.graph[v2].size() < 3) break;
		} while (p2 < r2);

		int j = new_population.size();
		new_population.resize(j + 2);
		visited.resize(j + 2);
		copy((new_population[g].begin() + v1 + 1), new_population[g].end(), back_inserter(new_population[j]));
		visited[j].resize(G.n);

		for (size_t k = v1 + 1; k < new_population[g].size(); k++)
		{
			int r = new_population[g][k];
			visited[j][r] = true;
		}
		copy(new_population[g].begin(), (new_population[g].begin() + v2), std::back_inserter(new_population[j + 1]));
		visited[j + 1].resize(visited[j - 1].size());

		for (size_t k = 0; k < v2; k++)
		{
			int r = new_population[g][k];
			visited[j + 1][r] = true;
		}

		DRS(j + 1, new_population[j + 1][new_population[j + 1].size() - 1], G, new_population, 2);
		DRS(j, new_population[j][0], G, new_population, 4);
	}
	return new_population;
}

vector <vector <long long int> > GaInAllGraph::start_mutationMechanism(Problem&D, int i, int n)
{
	type = 3;
	vector<vector<long long int> >sel;
	vector<vector<long long int> >mut;
	unsigned int start_time = clock();
	sel = selection(i, D, population);
	mut = mutationMechanism(sel, D);

	if (mut.size() != 0)
	{

		int count = 1;
		while (count != n)
		{
			sel = selection(i, D, mut);
			mut = mutationMechanism(sel, D);
			count++;
		}

		sel = selection(i, D, mut);
	}
	unsigned int end_time = clock();
	time1 = (end_time - start_time) / 1000.0;
	Unic(tmp_population, 1, false);
	res_population = Result(tmp_population);
	return res_population;
}

vector <vector <long long int>>  GaInAllGraph::Result(vector<vector<long long int> > n_population)
{
	vector <vector <long long int> > tmp;
	tmp.push_back(n_population[0]);

	for (size_t i = 1; i < n_population.size(); i++)
	{
		if (n_population[0].size() == n_population[i].size())
		{
			tmp.push_back(n_population[i]);
		}
	}

	return tmp;
}

void GaInAllGraph::clear()
{
	tmp_visited.clear();
	index.clear();
	tmp_population.clear();
	visited.clear();
	new_population.clear();
	res_population.clear();
	population.clear();
	visited.clear();
}

vector <vector <long long int> > GaInAllGraph::start_bothPairsOfPaths(Problem&D, int i, int n)
{
	type = 4;
	vector<vector<long long int> >sel1;
	vector<vector<long long int> >disjoint1;
	vector<vector<long long int> >sel2;
	vector<vector<long long int> >disjoint2;
	vector<vector<long long int> > save;
	vector<vector<bool> > save_vis;
	save.resize(population.size());
	copy(population.begin(), population.end(), back_inserter(save));
	copy(visited.begin(), visited.end(), back_inserter(save_vis));


	GaInAllGraph met1(*this);
	GaInAllGraph met2(*this);

	unsigned int search_time;
	unsigned int start_time = clock();

	int ct = 0;
	bool old1 = false;
	bool old2 = false;

	while (ct < n )
	//while (ct > n || (old1 == true && old2 == true) || ((clock() - start_time) / 1000.0) < 3000)
	{
	    if (!met1.population.empty()) sel1 = met1.selection(1, D, met1.population);
		if (!met2.population.empty()) sel2 = met2.selection(2, D, met2.population);

		this->clear();

	
		if (met1.status == false)
		{
			disjoint1 = met1.nonInterseptingPath(D, met1.new_population);
			copy(disjoint1.begin(), disjoint1.end(), back_inserter(population));
			copy(met1.visited.begin(), met1.visited.end(), back_inserter(visited));
		}

		if (met2.status == false)
		{
			disjoint2 = met2.intersectingPath(D, met2.new_population);
			copy(disjoint2.begin(), disjoint2.end(), back_inserter(population));
			copy(met2.visited.begin(), met2.visited.end(), back_inserter(visited));
		}

	    old1 = met1.status;
		old2 = met2.status;
 		met1.clear();
		met2.clear();
		met1 = *this;
		met2 = *this;
		ct++;
	}
	
	if (!population.empty())
	{
		this->Sort1(population);
		res_population = Result(Unic(population, 1, false));
		
	}
	else
	{
		this->status = true;
		this->Sort1(save);
		res_population = Result(Unic(save, 1, true));
	}
	unsigned int end_time = clock();
	time1 = (end_time - start_time) / 1000.0;
	this->population.clear();
	this->visited.clear();
	this->tmp_visited.clear();
	this->index.clear();
	this->new_population.clear();
	this->tmp_population.clear();
	this->tmp_visited.clear();
	return res_population;
}