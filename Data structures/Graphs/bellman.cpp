#include <bits/stdc++.h> 
using namespace std;

struct Edge
{ 
	int src, dest, weight; 
}; 

class graph 
{ 
    public:
	int v, e; 
    int *dist;
    struct Edge* edge; 

    graph(int x,int y)
    {
        v=x;
        e=y;
        edge=new Edge[e];
        dist=new int[v];
    }
    void addedge(int i,int s,int d,int w)
    {
        edge[i].src=s;
        edge[i].dest=d;
        edge[i].weight=w;
    }
    void BellmanFord(int src) 
    { 
	    for (int i = 0; i < v; i++) 
		dist[i] = INFINITY; 
	    dist[src] = 0; 
    
    	for (int i = 1; i <= v - 1; i++) 
        { 
		    for (int j = 0; j < e; j++)
            { 
			    int u = edge[j].src; 
			    int v = edge[j].dest; 
			    int weight = edge[j].weight; 
			    if (dist[v]> dist[u] + weight) 
				    dist[v] = dist[u] + weight; 
		    } 
	    } 
        for (int i = 0; i < e; i++)
        { 
		    int u = edge[i].src; 
		    int v = edge[i].dest; 
		    int weight = edge[i].weight; 
		    if (dist[u] != INFINITY && dist[u] + weight < dist[v]) 
            { 
			    printf("Graph contains negative weight cycle"); 
			    return; 
		    } 
	    } 
        cout<<"Vertex Distance from Source\n"; 
	    for (int i = 0; i < v; ++i) 
		    cout<<endl<<i<<"-"<<dist[i];
} 


}; 

int main() 
{ 
	int v = 5;  
	int e = 9;  
	graph g(v,e);

    //edge list representation
    g.addedge(0,0,1,4);
	g.addedge(1,0,2,2);
	g.addedge(2,1,2,3);
	g.addedge(3,1,3,2);
	g.addedge(4,1,4,3);
	g.addedge(5,2,1,1);
	g.addedge(6,2,3,4);
	g.addedge(7,2,4,5);
	g.addedge(8,4,3,-5);

    g.BellmanFord(0); 

	return 0; 
} 
