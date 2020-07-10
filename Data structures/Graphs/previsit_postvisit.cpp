#include<bits/stdc++.h>
using namespace std;

class graph
{
    private:
            list<int> *l;
            int *pre;
            int *post;
            int v;
            bool *visited;
            int clock;
    public:

    void getvertices(int x)
    {
        v=x;
        l=new list<int>[v];
        visited=new bool[v];
        clock=1;
        pre=new int[v];
        post=new int[v];
        for(int i=0;i<=v;i++)
        {
            visited[i]=false;
        }
    }
    void addedge(int x,int y)
    {
        l[x].push_back(y);
        l[y].push_back(x);
    }
    void explore(int x)
    {
        if(visited[x]=true)
        previsit(x);
        list<int>::iterator i;
        for(i=l[x].begin();i!=l[x].end();i++)
        {
            if(visited[*i]==false)
            explore(*i);
        }
        postvisit(x);
    }
    void previsit(int x)
    {
        pre[x]=clock;
        clock++;
    }
    void postvisit(int x)
    {
        post[x]=clock;
        clock++;
    }
    void output()
    {
        for(int i=0;i<v;i++)
        {
            cout<<pre[i]<<"/"<<post[i]<<endl;
        }
    }
};

int main()
{
    graph g;
    cout<<"enter the number of vertices/elements";
    int x,num2,num1;
    cin>>x;
    g.getvertices(x);


    //genereting random graph
    srand(time(0));
    for(int i=0;i<20;i++)
    {
        num1=(rand()%x);
        num2=(rand()%x);
        cout<<num1<<num2<<" ";
        g.addedge(num1,num2);
    }
    //generating random graph end


    int m;
    cout<<"enter starting point";
    cin>>m;
    g.explore(m);
    g.output();
}