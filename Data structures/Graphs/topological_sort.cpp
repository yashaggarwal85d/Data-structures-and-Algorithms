#include<bits/stdc++.h>
using namespace std;

class graph
{
    private:
            list<int> *l;
            int v;
            bool *visited;
            stack<int> s;
    public:

    void getvertices(int x)
    {
        v=x;
        l=new list<int>[v];
        visited=new bool[v];
    }
    void addedge(int x,int y)
    {
        l[x].push_back(y);
    }
    void topological()
    {
        for(int i=0;i<v;i++)
        {
            visited[i]=false;
        }
        for(int i=0;i<v;i++)
        {
            if(visited[i]==false)
            explore(i);
        }
        while(s.empty()==false)
        {
            cout<<endl<<s.top();
            s.pop();
        }
    }
    void explore(int x)
    {
        visited[x]=true;
        cout<<x<<"-";
        list<int>::iterator i;
        for(i=l[x].begin();i!=l[x].end();i++)
        {
            if(visited[*i]==false)
            explore(*i);
        }
        s.push(x);
    }
};

int main()
{
    graph g;
    cout<<"enter the number of vertices/elements";
    int x,num2,num1;
    cin>>x;
    g.getvertices(x);

    g.addedge(5, 2); 
    g.addedge(5, 0); 
    g.addedge(4, 0); 
    g.addedge(4, 1); 
    g.addedge(2, 3); 
    g.addedge(3, 1); 
    
    //genereting random graph
    // srand(time(0));
    // for(int i=0;i<20;i++)
    // {
    //     num1=(rand()%x);
    //     num2=(rand()%x);
    //     cout<<num1<<num2<<" ";
    //     g.addedge(num1,num2);
    // }
    //generating random graph end

    g.topological();
}