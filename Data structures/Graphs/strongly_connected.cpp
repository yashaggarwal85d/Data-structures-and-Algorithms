#include <bits/stdc++.h>
using namespace std; 

class directed_graph 
{ 
	int v; 
	list<int> *l; 
    bool *visited;
    stack<int>s;

    public:

    directed_graph(int x)
    { 
	    v = x; 
	    l = new list<int>[v]; 
        visited=new bool[x];
        for(int i = 0; i < v; i++) 
		{
            visited[i] = false; 
        }
    }
    
    void addedge(int x, int w)
    { 
	    l[x].push_back(w); 
    } 

	void explore(int x)
    { 
    	visited[x] = true; 
        list<int>::iterator i; 
	    for(i = l[x].begin(); i != l[x].end(); ++i) 
		{
            if(visited[*i]==false) 
			explore(*i); 
        }
        s.push(x); 
    }
    
    void dfsexplore(int x, bool visited[])
    { 
	    visited[x] = true; 
	    cout << x << " "; 
        list<int>::iterator i; 
	    for (i = l[x].begin(); i != l[x].end(); ++i) 
		    {
                if (visited[*i]==false) 
			    dfsexplore(*i, visited);
            } 
    } 
	
    directed_graph reverseg()
    { 
	    directed_graph g(v); 
	    for (int x = 0; x < v; x++) 
	    { 
		    list<int>::iterator i; 
		    for(i = l[x].begin(); i != l[x].end(); ++i) 
		    { 
		    	g.l[*i].push_back(x); 
		    } 
	    } 
	    return g; 
    } 

    void printSCCs()
    { 
        for(int i = 0; i < v; i++) 
		{
            if(visited[i] == false) 
			    explore(i); 
        }
        directed_graph gr = reverseg(); 
        
        for(int i = 0; i < v; i++) 
		{
            visited[i] = false; 
        }
        
        while (s.empty() == false) 
	    { 
		    int x = s.top(); 
		    s.pop(); 

		    if (visited[x] == false) 
		    { 
			    gr.dfsexplore(x, visited); 
			    cout << endl; 
		    } 
	    } 
    } 
}; 

int main() 
{ 
	directed_graph g(9); 
	g.addedge(0, 1); 
	g.addedge(1, 4);
    g.addedge(1,5); 
	g.addedge(2, 1); 
	g.addedge(3,6); 
	g.addedge(3, 0);
    g.addedge(4,0);
    g.addedge(4,2);
    g.addedge(4,7);
    g.addedge(6,7);
    g.addedge(7,8);
    g.addedge(8,7); 
    g.addedge(8,5); 
	g.printSCCs(); 

	return 0; 
} 
