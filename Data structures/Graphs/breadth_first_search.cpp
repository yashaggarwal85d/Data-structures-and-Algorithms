#include <bits/stdc++.h>
using namespace std; 

class directed_graph 
{ 
	int v; 
	list<int> *l; 
    bool *visited;
    queue<int>q;
    int *dist;

    public:

    directed_graph(int x)
    {  
        v=x;
	    l = new list<int>[v]; 
        visited=new bool[v];
        dist=new int[v];
        for(int i = 0; i < v; i++) 
		{
            visited[i] = false; 
        }
    }
    
    void addedge(int x, int w)
    { 
	    l[x].push_back(w); 
    }
    void BFS()
    {
        cout<<"enter source";
        int x;
        cin>>x;
        dist[x]=1;
        visited[x] = true; 
        q.push(x); 
    
        list<int>::iterator i; 
  
        while(!q.empty()) 
        { 
            x=q.front(); 
            cout<<x<<"-"; 
            q.pop(); 

            for (i=l[x].begin();i!=l[x].end();i++) 
            { 
                if (!visited[*i]) 
                { 
                    visited[*i] = true; 
                    q.push(*i);
                    dist[*i]=dist[x]+1; 
                } 
            } 
        }
        for(int j=0;j<v;j++)
        {
            cout<<endl<<j<<"-"<<dist[j];
        }
    }  
	 
}; 

int main() 
{ 
	directed_graph g(4); 
	g.addedge(0, 1); 
    g.addedge(0, 2); 
    g.addedge(1, 2); 
    g.addedge(2, 0); 
    g.addedge(2, 3); 
    g.addedge(3, 3);
    g.BFS();
	return 0; 
} 
