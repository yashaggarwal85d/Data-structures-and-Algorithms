#include <bits/stdc++.h> 
using namespace std; 

class graph
{
    int s,t,n;
    int *parent;
    vector<vector<int>> mat;
    vector<vector<int>> rmat;
    queue<int> q;

    public:

    graph(vector<vector<int>> vect,int s,int t)
    {
        n=6;
        this->s=s;
        this->t=t;
        parent=new int[n];
        mat=vect;
        rmat=mat;
    }

    bool bfs() 
    { 
        bool visited[n];
	    memset(visited, 0, sizeof(visited)); 
	    q.push(s); 
    	visited[s] = true; 
	    parent[s] = -1; 

	    while (!q.empty()) 
	    { 
		    int u = q.front(); 
		    q.pop(); 
    		for (int v=0; v<n; v++) 
	    	{ 
		    	if (visited[v]==false && rmat[u][v] > 0) 
			    { 
				    q.push(v); 
				    parent[v] = u; 
				    visited[v] = true; 
			    } 
		    } 
	    } 
        return (visited[t]); 
    } 

    int fordFulkerson() 
    { 
	    int u, v; 
        int max_flow = 0;
        
        while (bfs()) 
	    { 
            
		    int path_flow = INFINITY;
             
		    for (v=t; v!=s; v=parent[v]) 
		    { 

			    u = parent[v]; 
			    path_flow = min(path_flow, rmat[u][v]); 
		    } 

		    for (v=t; v != s; v=parent[v]) 
		    { 
			    u = parent[v]; 
			    rmat[u][v] -= path_flow; 
    			rmat[v][u] += path_flow; 
	    	} 

		    max_flow += path_flow; 
	    } 

	    return max_flow; 
    } 


};


int main() 
{ 
	vector<vector<int>> gr = { {0, 16, 13, 0, 0, 0}, 
						{0, 0, 10, 12, 0, 0}, 
						{0, 4, 0, 0, 14, 0}, 
						{0, 0, 9, 0, 0, 20}, 
						{0, 0, 0, 7, 0, 4}, 
						{0, 0, 0, 0, 0, 0} }; 

    graph g(gr,0,5);
	cout << "The maximum possible flow is "<<g.fordFulkerson(); 

	return 0; 
} 
