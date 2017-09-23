#pragma once
#include <libpq-fe.h>
#include <string>
#include "GA.h"
#include <typeinfo>
#include <windows.h>
#include "Problem.h"
#include "GaInAllPath.h"
#include <vector>
#include "GaBetweenVertex.h"

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
			GaInAllPath  data = dynamic_cast<GaInAllPath&>(elem);
			string result = "'" + vector_to_string(data.res_population)+"'";
			if (data.type == 1 || data.type == 2)
			{
				command = "INSERT INTO public.gainallgraph( id_task, vertex, edge, \"time\", sizenewpopulation, path, lengthpath, id_algorithm, persent, count) VALUES( 1 ," + to_string(G.n) + " , " +
					to_string(G.m) + " , " + to_string(data.time1) + " , " + to_string(data.populationSize) + " , " +
					result + " , " + to_string(data.res_population[0].size() - 1) + " , " + to_string(data.type) + " , " +
					to_string(data.percent * 100)+ " , " + to_string(data.res_population.size())+")";

			}
			else if (data.type == 3 || data.type == 4)
			{
			
				va_list ap;
				va_start(ap, nParamCount);
				int n = va_arg(ap, int);
				va_end(ap);
				command = "INSERT INTO public.gainallgraphwithstep( id_task, vertex, edge, \"time\", sizenewpopulation, path, lengthpath, id_algorithm, persent,  numstep, count) VALUES( 1 ," + to_string(G.n) + " , " +
					to_string(G.m) + " , " + to_string(data.time1) + " , " + to_string(data.populationSize) + " , " +
					result + " , " + to_string(data.res_population[0].size() - 1) + " , " + to_string(data.type) + " , " +
					to_string(data.percent * 100) + " , " + to_string(data.res_population.size()) + ")";
			}
		}
		else if (typeTask == 2)
		{
			GaBetweenVertex  data = dynamic_cast<GaBetweenVertex&>(elem);
			string result = "'" + vector_to_string(data.res_population) + "'";
			va_list ap;
			va_start(ap, nParamCount);
			int n = va_arg(ap, int);
			va_end(ap);

			command = "INSERT INTO public.gabetweenvertex( id_task, vertex, edge, \"time\", sizenewpopulation, path, lengthpath, firstvertex, secondvertex , numstep) VALUES( 2 ," + to_string(G.n) + " , " +
				to_string(G.m) + " , " + to_string(data.time1) + " , " + to_string(data.sizeStartPopulation) + " , " +
				result + " , " + to_string(data.res_population[0].size() - 1) + " , "  +
				to_string(data.s) + " , " + to_string(data.t) + " , " + to_string(n)+")";
		}
		res = PQexec(conn, command.c_str());
		if (PQresultStatus(res) != PGRES_COMMAND_OK)
		error(PQresultErrorMessage(res));
		return res;	
	}

	void error(string error);
	DatabaseWriter(){};

	string vector_to_string(vector<vector<long long>>vec)
	{
		string res = "";

		for (size_t i = 0; i < vec.size(); i++)
		{
			for (size_t j = 0; j < vec[i].size() - 1; j++)
			{
				res = res + "(" + to_string(vec[i][j]) + "," + to_string(vec[i][j + 1]) + ")";
			}
			if (i != vec.size() - 1) res = res + " ; ";
		}
		return res;
	}
};