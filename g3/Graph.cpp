/*
                                                                            Group 40

                                                            Ammar Moataz Saad Aly Mokhtar            18P6278
                                                            Ahmed Adham Tawakol                      18P9139
                                                            Ali Hesham Elgazzar                      18P7355
                                                            Mostafa Hossameldeen Elsayed Sleem       16P8115
                                                            Mohammed makram mahrous said Ahmed       19P2645
*/
#include "Graph.h"
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <cstdlib>
using namespace std;
//Definition of the constructor
Graph::Graph(int V, int E) :V(V), E(E)
{
    this->edge = new Edge[E];
}
//Definition of Function find() using path compression method
int Graph::find(subset subsets[], int i)
{
    // find root and make root as parent of i
    if (subsets[i].parent != i)
        subsets[i].parent
        = find(subsets, subsets[i].parent);

    return subsets[i].parent;
}
//Definition of Function Union() using union by rank method
void Graph::Union(subset subsets[], int x, int y)
{
    int xroot = find(subsets, x);
    int yroot = find(subsets, y);

    // Attach smaller rank tree under root of high
    // rank tree (Union by Rank)
    if (subsets[xroot].rank < subsets[yroot].rank)
        subsets[xroot].parent = yroot;
    else if (subsets[xroot].rank > subsets[yroot].rank)
        subsets[yroot].parent = xroot;

    // If ranks are same, then make one as root and
    // increment its rank by one
    else {
        subsets[yroot].parent = xroot;
        subsets[xroot].rank++;
    }
}
//Compare function to be used in qsort
int myComp(const void* a, const void* b)
{
    Graph :: Edge* a1 = (Graph::Edge*)a;
    Graph::Edge* b1 = (Graph::Edge*)b;
    return a1->weight > b1->weight; //if true return 1 if false return 0 (integer boolean values in c++)
}

void Graph::KruskalMST()
{

    int V = this->V;
    Edge result[5]; //Array of edges to store MST result edges. We change size of results manually according to number of Veticies (V) in the graph
    int e = 0; // An index for result[]
    int i = 0; // An index for the edges of the graph after sorting

    // Step 1: Sort the edges according to their weight ascendingly
    qsort(this->edge, this->E, sizeof(this->edge[0]),
        myComp);
    // Allocate memory for creating V subsets
    subset* subsets = new subset[(V * sizeof(subset))];

    // Create V subsets with its self as a parent
    // for example if V=1 then make subset with parent=1
    for (int v = 0; v < V; ++v)
    {
        subsets[v].parent = v;
        subsets[v].rank = 0;
    }

    // Rule of MST: Number of edges to be taken must be equal to V-1 
    while (e < V - 1 && i < this->E)
    {
        // Step 2: Pick the smallest edge (edge[0] after sorting) and increment
        // the index i for next iteration
        Edge next_edge = this->edge[i++];

        //Store absolute root of src and dest in integers x and y
        //If they are the same then this cause a cycle
        int x = find(subsets, next_edge.src);
        int y = find(subsets, next_edge.dest);
        
        // If the absolute roots are not the same then this doesnt cause a cycle,
        // include it in result and increment the index e of result for next edge
        if (x != y) {
            result[e++] = next_edge;
            Union(subsets, x, y);
        }
        // Else do nothing since it cause a cycle
    }

    //Step 3: print the contents of result[] to display MST of the graph
    cout << "Following are the edges in the constructed "
        "MST\n";
    int minimumCost = 0;
    for (i = 0; i < e; ++i)
    {
        cout << result[i].src << " -- " << result[i].dest
            << " == " << result[i].weight << endl;
        minimumCost = minimumCost + result[i].weight;
    }
    cout << "Minimum Cost Spanning Tree: " << minimumCost
        << endl;
}
