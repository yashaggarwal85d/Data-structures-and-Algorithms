#include <bits/stdc++.h>
using namespace std; 
int cqueue[5];
int front=-1,n=5,rear=-1;
void push()
{
    int x;
    cout<<"\n insert value";
    cin>>x;
    if((rear==n-1 && front==0) || front==rear+1)
    cout<<"queue is full";
    else
    {
        if(front==-1)
        {
            front=0;
            rear=0;
        }
        else
        {
            if(rear==n-1)
            rear=0;
            else
            rear++;
        }
        cqueue[rear]=x;   
    }
}
void pop()
{
    if(front==-1)
    cout<<"queue is empty";
    else
    {
        if(rear==front)
        rear=front=-1;
        else
        {
            if(front==n-1)
            front=0;
            else
            front++;
        }
    }
}
void display()
{
    int f = front, r = rear;
    if (front == -1) 
    {
        cout<<"Queue is empty"<<endl;
    }
    else
    {
        cout<<"Queue elements are :\n";
        if (f <= r) 
        {
            while (f <= r)
            {
            cout<<cqueue[f]<<" ";
            f++;
            }
        }   
        else 
        {
            while (f <= n - 1) 
            {
                cout<<cqueue[f]<<" ";
                f++;
            }
            f = 0;
            while (f <= r) 
            {
            cout<<cqueue[f]<<" ";
            f++;
            }
        }
        cout<<endl;
    }
}
int main()
{
    while(1)
    {
    int a;
    cout<<" 1.push \n 2.pop \n 3.display \n";
    cin>>a;
    switch(a)
    {
        case 1:push();
               break;
        case 2:pop();
               break;
        case 3:display();
               break;
    }
    }
}