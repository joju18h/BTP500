// C++ program for Dijkstra's single source shortest path
// algorithm. The program is for adjacency matrix
// representation of the graph
#include <iostream>
#include <iomanip>
using namespace std;

#define INT_MAX       2147483647
// Number of vertices in the graph
#define V 8

// A utility function to find the vertex with minimum
// distance value, from the set of vertices not yet included
// in shortest path tree
int minDistance(int dist[], bool sptSet[])
{

    // Initialize min value
    int min = INT_MAX, min_index;
    //STEP 3
    //Go through the vertex to find the minimum values and min index
    for(int i = 0; i < V; i++)
    {
        if(sptSet[i] == false && dist[i] <= min)
        {
            min = dist[i];
            min_index = i;
        }
    }
   //4 LINES

    return min_index;
}

// A utility function to print the constructed distance
// array
void printSolution(int dist[], string city[], int src)
{
    cout << endl;

    //print the distance
    cout << "Vertex \t\t Distance from Source" << endl;
    for (int i = 0; i < V; i++) 
        cout << city[src] << " -> "<< city[i] << right << setw(25) << dist[i] << endl;
    // 3 LINES

    //STEP 4

}

// Function that implements Dijkstra's single source
// shortest path algorithm for a graph represented using
// adjacency matrix representation
void dijkstra(int graph[V][V], string city[], int src)
{
    int dist[V]; // The output array.  
    // dist[i] will hold the shortest distance from src to i

    bool sptSet[V]; // sptSet[i] will be true if vertex i is
    // included in shortest path tree or shortest distance from src to i is finalized

// Initialize all distances as INFINITE and stpSet[] as
// false
    for (int i = 0; i < V; i++)
        dist[i] = INT_MAX, sptSet[i] = false;

    // Distance of source vertex from itself is always 0
    dist[src] = 0;

    // Find shortest path for all vertices
    for (int count = 0; count < V - 1; count++) {
        // Pick the minimum distance vertex from the set of
        // vertices not yet processed. u is always equal to
        // src in the first iteration.
        int u = minDistance(dist, sptSet);

        // Mark the picked vertex as processed
        sptSet[u] = true;

        // Update dist value of the adjacent vertices of the
        // picked vertex.
        for (int v = 0; v < V; v++)

            // Update dist[v] only if is not in sptSet,
            // there is an edge from u to v, and total
            // weight of path from src to  v through u is
            // smaller than current value of dist[v]
            if (!sptSet[v] && graph[u][v]
                && dist[u] != INT_MAX
                && dist[u] + graph[u][v] < dist[v])
                dist[v] = dist[u] + graph[u][v];
    }

    // print the constructed distance array
    printSolution(dist, city, src);
}


int main()
{
    //declare and initialize a cities array for 8 nodes
   // string city[] ;
    //STEP 1;
    string city[] = { "Ajax", "Brampton", "Markham", "Missisauga", "Pickering", "Richmond Hill", "Toronto", "Vaughan" };

    /* Let us create the example graph discussed above */
  //  int graph[V][V] with the adjacency matrix given
    //STEP 2
    int graph[V][V] = { {0,0,30,0,10,25,0,0},
                        {0,0,0,25,0,15,40,30},
                        {30,0,0,0,15,15,25,20},
                        {0,25,0,0,0,25,40,0},
                        {10,0,15,0,0,16,20,20},
                        {25,30,15,25,16,0,35,13},
                        {0,43,30,45,20,35,0,30},
                        {0,25,20,0,20,13,30,0}
    };
    // Function call
    dijkstra(graph, city, 6);

    return 0;
}



//Pseudocode of Dijkstra�s Algorithm in C++
//function dijkstra(G, S)
//for each vertex V in G
//dist[V] < -infinite
//    prev[V] < -NULL
//    If V != S, add V to Priority Queue Q
//    dist[S] < -0
//
//    while Q IS NOT EMPTY
//        U < -Extract MIN from Q
//        for each unvisited neighbour V of U
//            temperoryDist < -dist[U] + edgeWeight(U, V)
//            if temperoryDist < dist[V]
//                dist[V] < -temperoryDist
//                prev[V] < -U
//                return dist[], prev[]