/*
                                                                            Group 40

                                                            Ammar Moataz Saad Aly Mokhtar            18P6278
                                                            Ahmed Adham Tawakol                      18P9139
                                                            Ali Hesham Elgazzar                      18P7355
                                                            Mostafa Hossameldeen Elsayed Sleem       16P8115
                                                            Mohammed makram mahrous said Ahmed       19P2645
*/
#include <iostream>
#include "Graph.h"
#include <stdio.h>
int main()
{
    int V = 5; // Number of vertices in graph
    int E = 7; // Number of edges in graph
    Graph* graph = new Graph(V, E);

    //add edge 0-1 wegiht 4
    graph->edge[0].src = 0;
    graph->edge[0].dest = 1;
    graph->edge[0].weight = 4;
    //add edge 0-2 weight 4
    graph->edge[1].src = 0;
    graph->edge[1].dest = 2;
    graph->edge[1].weight = 4;
    //add edge 1-2 weight 2
    graph->edge[2].src = 1;
    graph->edge[2].dest = 2;
    graph->edge[2].weight = 2;
    //add edge 0-3 weight 6
    graph->edge[3].src = 0;
    graph->edge[3].dest = 3;
    graph->edge[3].weight = 6;
    //add edge 0-4 weight 6
    graph->edge[4].src = 0;
    graph->edge[4].dest = 4;
    graph->edge[4].weight = 6;
    //add edge 4-3 weight 9
    graph->edge[5].src = 4;
    graph->edge[5].dest = 3;
    graph->edge[5].weight = 9;
    //add edge 3-2 weight 8
    graph->edge[6].src = 3;
    graph->edge[6].dest = 2;
    graph->edge[6].weight = 8;

    /*// add edge 0-1 with weight 9
    graph->edge[0].src = 0;
    graph->edge[0].dest = 1;
    graph->edge[0].weight = 9;

    // add edge 0-2 with weight 75
    graph->edge[1].src = 0;
    graph->edge[1].dest = 2;
    graph->edge[1].weight = 75;

    // add edge 2-1 with weight 95
    graph->edge[2].src = 2;
    graph->edge[2].dest = 1;
    graph->edge[2].weight = 95;

    // add edge 2-3 with weight 51
    graph->edge[3].src = 2;
    graph->edge[3].dest = 3;
    graph->edge[3].weight = 51;

    // add edge 1-3 with weight 19
    graph->edge[4].src = 1;
    graph->edge[4].dest = 3;
    graph->edge[4].weight = 19;

    //add edge 1-4 with weight 42
    graph->edge[5].src = 1;
    graph->edge[5].dest = 4;
    graph->edge[5].weight = 42;

    //add edge 3-4 with weight 31
    graph->edge[6].src = 3;
    graph->edge[6].dest = 4;
    graph->edge[6].weight = 31;*/

    //Call kruskal algorithm function
    graph->KruskalMST();

    return 0;
}

