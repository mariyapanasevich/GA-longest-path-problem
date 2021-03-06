#pragma once
#include <libpq-fe.h>
#include <string>
#include "GA.h"
#include <typeinfo>
#include <windows.h>
#include "Problem.h"
#include "GaInAllGraph.h"
#include <vector>
#include "GaBetweenVertex.h"
#include "GAWithWeight.h"

using namespace std;

class DatabaseWriter
{
public:
	void CloseConn(PGconn *conn);
	PGconn* ConnectDB();
	bool statusConnect;
	PGresult *res;
	PGconn *conn;
	void GetData(PGconn *conn);
	vector<string> GetName(string DBname);

	template <class T> PGresult* insertData(int typeTask, T elem, Problem G, int nParamCount, ...)
	{
		string command = "";
		if (typeTask == 1)
		{
			GaInAllGraph  data = dynamic_cast<GaInAllGraph&>(elem);
			string result = "'" + vector_to_string(data.res_population, true) + "'";
			if (data.type == 1)
			{
				command = "INSERT INTO public.gainallgraph( id_task, vertex, edge, \"time\", sizenewpopulation, path, lengthpath, id_algorithm, persent, count) VALUES( 1 ," + to_string(G.n) + " , " +
					to_string(G.m) + " , " + to_string(data.time1) + " , " + to_string(data.populationSize) + " , " +
					result + " , " + to_string(data.res_population[0].size() - 1) + " , " + to_string(data.type) + " , " +
					to_string(data.percent * 100) + " , " + to_string(data.res_population.size()) + ")";

			}
			else if (data.type == 3 || data.type == 4 || data.type == 2)
			{

				va_list ap;
				va_start(ap, nParamCount);
				int n = va_arg(ap, int);
				va_end(ap);
				command = "INSERT INTO public.gainallgraphwithstep( id_task, vertex, edge, \"time\", sizenewpopulation, path, lengthpath, id_algorithm, persent,  numstep, count) VALUES( 1 ," + to_string(G.n) + " , " +
					to_string(G.m) + " , " + to_string(data.time1) + " , " + to_string(data.populationSize) + " , " +
					result + " , " + to_string(data.res_population[0].size() - 1) + " , " + to_string(data.type) + " , " +
					to_string(data.percent * 100) + " , " + to_string(n) + " , " + to_string(data.res_population.size()) + ")";
			}
		}
		else if (typeTask == 2)
		{
			GaBetweenVertex  data = dynamic_cast<GaBetweenVertex&>(elem);
			string result = "'" + vector_to_string(data.res_population,false) + "'";
			va_list ap;
			va_start(ap, nParamCount);
			int n = va_arg(ap, int);
			va_end(ap);

			command = "INSERT INTO public.gabetweenvertex( id_task, vertex, edge, \"time\", sizenewpopulation, path, lengthpath, firstvertex, secondvertex , numstep, count) VALUES( 2 ," + to_string(G.n) + " , " +
				to_string(G.m) + " , " + to_string(data.time1) + " , " + to_string(data.sizeStartPopulation) + " , " +
				result + " , " + to_string(data.res_population[0].size() - 1) + " , " +
				to_string(data.s) + " , " + to_string(data.t) + " , " + to_string(n)+" , " + to_string(data.res_population.size()) + ")";
		}
		else if (typeTask == 3)
		{
			GAWithWeight data = dynamic_cast<GAWithWeight&>(elem);
			va_list ap;
			va_start(ap, nParamCount);
			int n = va_arg(ap, int);
			va_end(ap);
			string result = "'" + vector_to_string(data.res_population, true) + "'";
			command = "INSERT INTO public.gawithweight( id_task, vertex, edge, \"time\", sizenewpopulation, path, lengthpath, \"probMutation\" , numstep, count) VALUES( 3 ," + to_string(G.n) + " , " + to_string(G.m) + " , " +
				to_string(data.time1) + " , " + to_string(data.sizeStartPopulation) + " , " + result + " , "
			+ to_string(data.resWeigth) + " , " + to_string(data.probabilityMutation) + " , " + to_string(n) + " , " + to_string(data.res_population.size()) + ")";


		}
		res = PQexec(conn, command.c_str());
		if (PQresultStatus(res) != PGRES_COMMAND_OK)
			error(PQresultErrorMessage(res));
		return res;
	}

	void error(string error);
	DatabaseWriter(){};

	string vector_to_string(vector<vector<long long>>vec, bool zn)
	{
		string res = "";

		for (size_t i = 0; i < vec.size(); i++)
		{
			for (size_t j = 0; j < vec[i].size() - 1; j++)
			{
				
				res = res + "(" + ((zn == false) ? to_string(vec[i][j]) : to_string(vec[i][j] + 1)) + "," + ((zn == false) ? to_string(vec[i][j + 1]) : to_string(vec[i][j + 1] + 1)) + ")";
			}
			if (i != vec.size() - 1) res = res + " ; ";
		}
		return res;
	}
};