/*
																			Group 40

															Ammar Moataz Saad Aly Mokhtar            18P6278
															Ahmed Adham Tawakol                      18P9139
															Ali Hesham Elgazzar                      18P7355
															Mostafa Hossameldeen Elsayed Sleem       16P8115
															Mohammed makram mahrous said Ahmed       19P2645
*/
#pragma once
	class Graph
	{
	public:
		class Edge {
		public:
			int src, dest, weight;
		};

		class subset {
			//
		public:
			int parent;
			int rank;
		};
		//Graph constructor takes V number of verticies and E number of edges
		Graph(int V, int E);
		//Funtions from Union-Find algorithm that will be used in kruskal later on
		//find() determines which subset an element is in
		int find(subset subsets[], int i);
		//merges 2 subsets into 1 subset
		void Union(subset subsets[], int x, int y);
		//Kruskal algorithm function that outputs the MST
		void KruskalMST();
		
		
		// V is the Number of vertices, E is the Number of edges
		int V, E;
		// graph is undirected and is represented as an array of edges.
		Edge* edge;



	};




