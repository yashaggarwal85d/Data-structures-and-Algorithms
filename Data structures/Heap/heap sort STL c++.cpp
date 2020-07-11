#include<bits/stdc++.h>
using namespace std;

void heapsort(int *a,int n)
{
    int i;
    priority_queue<int> pq;
    for(i=0;i<n;i++)
    pq.push(a[i]);
    for(i=n-1;i>=0;i--)
    {
        a[i]=pq.top();
        pq.pop();
    }
}
int main()
{
    int ar[50],i;
    for(i=0;i<5;i++)
    cin>>ar[i];
    heapsort(ar,5);
    for(i=0;i<5;i++)
    cout<<endl<<ar[i];
}