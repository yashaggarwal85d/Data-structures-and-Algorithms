#include <bits/stdc++.h>
using namespace std; 
int queue_array[10];
int front=-1,n=10,rear=-1;
void push()
{
    int x;
    cout<<"\n insert value";
    cin>>x;
    if(rear==n)
    cout<<"queue is full";
    else
    if(front==-1)
    front=0;
    rear++;
    queue_array[rear]=x;
}
void pop()
{
    if(rear==-1)
    cout<<"queue is empty";
    else
    if(rear==front)
    rear=front=-1;
    else
    front++;
}
void display()
{
    if(rear==-1)
    {
        cout<<"queue is empty";
        rear=front=-1;
    }
    else
    {
        for(int i=front;i<=rear;i++)
        cout<<queue_array[i]<<"-";
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