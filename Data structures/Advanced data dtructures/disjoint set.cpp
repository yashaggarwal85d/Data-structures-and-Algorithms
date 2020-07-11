#include<bits/stdc++.h>
using namespace std;

class disjointset
{
    private:
            int parent[10],rank[10];
    public:
            void makeset()
            {
                int i;
                cin>>i;
                parent[i]=i;
                rank[i]=0;
            }
            int returni()
            {
                int i;
                cin>>i;
                return i;
            }
            int find(int i)
            {
                while(i!=parent[i])
                i=parent[i];
                return i;
            }
            void dunion()
            {
                int i,j;
                cin>>i>>j;
                int i_id=find(i);
                int j_id=find(j);
                if(i_id==j_id)
                cout<<"\n already joined";
                else
                if(rank[i_id]>rank[j_id])
                parent[j_id]=i_id;
                else
                {
                    parent[i_id]=j_id;
                    if(rank[i_id]==rank[j_id])
                    rank[j_id]=rank[j_id]+1;
                }
            }
            int compressionfind(int i)
            {
                if(i!=parent[i])
                parent[i]=compressionfind(parent[i]);
                return (parent[i]);
            }
};

int main()
{
    disjointset d;
    while(1)
    {
    int a;
    cout<<"\n 1.make set \n 2.find \n 3.union \n 4.compression find";
    cin>>a;
    switch(a)
    {
        case 1:d.makeset();
               break;
        case 2:cout<<d.find(d.returni());
               break;
        case 3:d.dunion();
               break;
        case 4:cout<<d.compressionfind(d.returni());
    }
    }
}
