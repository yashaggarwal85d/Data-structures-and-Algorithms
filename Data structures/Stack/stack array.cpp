#include <bits/stdc++.h>
using namespace std; 
int stack_array[10];
int top=-1,n=10;
void push()
{
    int x;
    cout<<"\n insert value";
    cin>>x;
    if(top==n)
    cout<<"stack is full";
    else
    {
        top++;
        stack_array[top]=x;
    }
}
void pop()
{
    if(top==-1)
    cout<<"stack is empty";
    else
    top--;
}
void display()
{
    if(top==-1)
    cout<<"stack is empty";
    else
    {
        for(int i=0;i<=top;i++)
        cout<<stack_array[i]<<"-";
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