#include<bits/stdc++.h> 
using namespace std; 

struct disjointset 
{ 
    int *parent, *rnk; 
    int n; 
  
    disjointset(int n) 
    { 
        this->n = n; 
        parent = new int[n+1]; 
        rnk = new int[n+1]; 
  
        for (int i = 0; i <= n; i++) 
        { 
            rnk[i] = 0; 
            parent[i] = i; 
        } 
    } 
   
    int find(int u) 
    { 
        if (u != parent[u]) 
            parent[u] = find(parent[u]); 
        return parent[u]; 
    }

    void merge(int x, int y) 
    { 
        x = find(x), y = find(y); 
        if (rnk[x] > rnk[y]) 
        parent[y] = x; 
        else  
        parent[x] = y; 
  
        if (rnk[x] == rnk[y]) 
        rnk[y]++; 
    } 

};

class weighted_graph 
{ 
	int v, e; 
	vector< pair<int, pair<int, int>>> edges; 

    public:
	weighted_graph(int x, int y) 
	{ 
		this->v = x; 
		this->e = y; 
	} 

	void addEdge(int x, int y, int w) 
	{ 
		edges.push_back({w, {x, y}}); 
	} 

	void kruskalMST()
    { 
        disjointset ds(v);
	    int weight = 0; 
        sort(edges.begin(), edges.end()); 
         

	    for (auto it=edges.begin(); it!=edges.end(); it++) 
	    { 
		    int x = it->second.first; 
		    int y = it->second.second; 

		    int findx = ds.find(x); 
		    int findy = ds.find(y); 

		    if (findx != findy) 
		    { 
			    cout << x << " - " << y << endl; 
                weight += it->first; 
                ds.merge(findx, findy); 
		    } 
	    } 
        cout << "\nWeight of MST is " << weight;  
    } 

}; 


int main() 
{ 
	int v = 9, e = 14; 
	weighted_graph g(v,e); 

	g.addEdge(0, 1, 4); 
	g.addEdge(0, 3, 2); 
	g.addEdge(0, 4, 1); 
	g.addEdge(1, 2, 8); 
	g.addEdge(1, 4, 5); 
	g.addEdge(1, 5, 6); 
	g.addEdge(2, 5, 1); 
	g.addEdge(3, 4, 3); 
	g.addEdge(4, 5, 9); 
	
	cout << "Edges of MST are \n"; 
	g.kruskalMST(); 
	return 0; 
} 
