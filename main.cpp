#include <math.h>
#include "CGraph.h"

int main()
{
    int size = 5;
    CGraph *graph = new CGraph(size);
    graph->EnableGrid(true);
    for(int i = size * -1; i < size; i++)
    {
        graph->Set(i*2, i, "*");
    }
    graph->Print();

    delete graph;
	return 0;
}
