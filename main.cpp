#include "CGraph.h"

int main()
{
    CGraph *graph = new CGraph(30);
    graph->EnableGrid(true);
    graph->Set(6, 5, "&");
    graph->Set(2, 2, "*");
    graph->Print();

    delete graph;
	return 0;
}
