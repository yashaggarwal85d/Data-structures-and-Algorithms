#include<bits/stdc++.h> 
using namespace std; 

class graph
{
    int v;
    list<pair<int,int>> *adj;
    priority_queue<pair<int,int>,vector <pair<int,int>>,greater<pair<int,int>>>pq; 

    public:

    graph(int x)
    {
        v=x;
        adj=new list<pair<int,int>>[v];
    }

    void addedge(int u,int v,int wt) 
    { 
	    adj[u].push_back(make_pair(v, wt)); 
	    adj[v].push_back(make_pair(u, wt)); 
    } 

    void primMST() 
    { 
	    int src = 0;
        vector<int> key(v, INFINITY); 
        vector<int> parent(v, -1); 
        vector<bool> inMST(v, false); 
        pq.push(make_pair(0, src)); 
	    key[src] = 0; 
        while (!pq.empty()) 
	    { 
		    int u = pq.top().second; 
		    pq.pop(); 
            inMST[u] = true; 
        
            for (auto x : adj[u]) 
		    { 
			    int y = x.first; 
			    int weight = x.second; 

			    if (inMST[y] == false && key[y] > weight) 
			    { 
				    key[y] = weight; 
				    pq.push(make_pair(key[y],y)); 
				    parent[y] = u; 
			    } 
		    } 
	    } 

	    for (int i = 1; i < v; ++i) 
		{
			if(parent[i]>=0)
	    	cout<<parent[i]<<"-"<<i<<endl; 
    	} 
	}

};

int main() 
{ 
	int v = 9;
    graph g(v); 
	g.addedge(0, 1, 4); 
	g.addedge(0, 3, 2); 
	g.addedge(0, 4, 1); 
	g.addedge(1, 2, 8); 
	g.addedge(1, 4, 5); 
	g.addedge(1, 5, 6); 
	g.addedge(2, 5, 1); 
	g.addedge(3, 4, 3); 
	g.addedge(4, 5, 9); 

	g.primMST(); 

	return 0; 
} 
