#include<bits/stdc++.h>
using namespace std;

void swap(int &x,int &y)
{
    int d;
    d=x;
    x=y;
    y=d;
}
class priorityqueue
{
    private:
            int h[20],size,maxsize;
    public:
            priorityqueue()
            {
                size=-1;
                maxsize=19;
            }
            int returnsize()
            {
                return size;
            }
            int parent(int i)
            {
                return((i-1)/2);
            }
            int leftchild(int i)
            {
                return(2*i+1);
            }
            int rightchild(int i)
            {
                return(2*i+2);
            }
            int shiftup(int i)
            {
                while(i>0 && h[parent(i)]<h[i])
                {
                    swap(h[parent(i)],h[i]);
                    i=parent(i);
                }
            }
            int shiftdown(int i)
            {
                int maxindex,l;
                maxindex =i;
                l=leftchild(i);
                if(l<=size && h[l]>h[maxindex])
                maxindex=l;

                int r;
                r=rightchild(i);
                if(r<=size && h[r]>h[maxindex])
                maxindex=r;

                if(i!=maxindex)
                {
                    swap(h[i],h[maxindex]);
                    shiftdown(maxindex);
                }
            }
            void insert()
            {
                int p;
                cin>>p;
                if(size==maxsize)
                cout<<"tree is full";
                else
                {
                    size++;
                    h[size]=p;
                    shiftup(size);
                }
            }
            void extractmax()
            {
                int result =h[0];
                h[0]=h[size];
                size--;
                shiftdown(0);
                cout<<result;
            }
            void remove()
            {
                int i;
                cin>>i;
                h[i]=h[0]+1;
                shiftup(i);
                extractmax();
            }
            void changepriority()
            {
                int i,p,oldp;
                cin>>i>>p;
                oldp=h[i];
                h[i]=p;
                if(p>oldp)
                shiftup(i);
                else
                shiftdown(i);
            }
            void display(int i)
            {
                for(int i=0;i<=size;i++)
                cout<<h[i];
            }
};
int main()
{
    priorityqueue q;
    while(1)
    {
        int a;
        cout<<"\n 1.insert \n 2.remove \n 3.extract max \n 4.change priority \n 5.display \n";
        cin>>a;
        switch(a)
        {
            case 1:q.insert();
            break;
            case 2:q.remove();
            break;
            case 3:q.extractmax();
            break;
            case 4:q.changepriority();
            break;
            case 5:q.display(q.returnsize());
        }
    }
}