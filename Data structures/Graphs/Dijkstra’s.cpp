#include<bits/stdc++.h> 
using namespace std; 

class weighted_graph 
{ 
	int v;
	list<pair<int,int>>*adj; 
    priority_queue< pair<int, int>, vector <pair<int, int>> , greater<pair<int, int>> > pq; 

    public: 
	
    weighted_graph(int x)
    { 
	    this->v = x; 
	    adj = new list<pair<int,int>>[x]; 
    }
	
    void addEdge(int x, int y, int w)
    { 
	    adj[x].push_back(make_pair(y, w)); 
	    adj[y].push_back(make_pair(x, w)); 
    }

	void shortestPath(int src)
    {
	    vector<int> dist(v, INFINITY); 

        pq.push(make_pair(0, src)); 
	    dist[src] = 0; 
        while (!pq.empty()) 
	    { 
		    int u = pq.top().second; 
		    pq.pop(); 

		    for (auto i = adj[u].begin(); i != adj[u].end(); i++) 
		    { 
		        int x = (*i).first; 
			    int weight = (*i).second; 

			    if (dist[x] > dist[u] + weight) 
			    { 
				    dist[x] = dist[u] + weight; 
				    pq.push(make_pair(dist[x], x)); 
			    } 
		    } 
	    }    

	    cout<<"shortest distance from source"; 
	    for (int i = 0; i < v; ++i) 
        {
		    cout<<endl<<i<<"-"<<dist[i]; 
        }
    } 
 
}; 

int main() 
{ 
	int v = 9; 
	weighted_graph g(v); 
	g.addEdge(0, 1, 4); 
	g.addEdge(0, 7, 8); 
	g.addEdge(1, 2, 8); 
	g.addEdge(1, 7, 11); 
	g.addEdge(2, 3, 7); 
	g.addEdge(2, 8, 2); 
	g.addEdge(2, 5, 4); 
	g.addEdge(3, 4, 9); 
	g.addEdge(3, 5, 14); 
	g.addEdge(4, 5, 10); 
	g.addEdge(5, 6, 2); 
	g.addEdge(6, 7, 1); 
	g.addEdge(6, 8, 6); 
	g.addEdge(7, 8, 7); 

	g.shortestPath(0); 
	return 0; 
} 
