#include <iostream>
#include "ProblemWeight.h"
#include <conio.h>
#include "GaInAllPath.h"
#include "GAWithWeight.h"

using namespace std;

int main()
{
	ProblemWeight graph(10, 15);
	
	graph.graphAddWeight(1, 2, 15);
	graph.graphAddWeight(1, 10, 10);
	graph.graphAddWeight(2, 9, 3);
	graph.graphAddWeight(2, 10, 2);
	graph.graphAddWeight(3, 4, 2);
	graph.graphAddWeight(3, 5, 100);
	graph.graphAddWeight(3, 6, 19);
	graph.graphAddWeight(3, 10, 29);
	graph.graphAddWeight(4, 10, 21);
	graph.graphAddWeight(5, 6, 7);
	graph.graphAddWeight(6, 10, 11);
	graph.graphAddWeight(7, 8, 12);
	graph.graphAddWeight(7, 9, 21);
	graph.graphAddWeight(7, 10, 33);
	graph.graphAddWeight(8, 9, 35);

  
	GAWithWeight g(100);
	g.probabilityMutation = 0.9;
	g.procedure(graph, 10);
	



	_getch();
	return 0;
}