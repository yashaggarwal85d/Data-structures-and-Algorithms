#include <bits/stdc++.h>
using namespace std;

void printvect(vector<int> vect)
{
    for(auto x:vect)
    cout<<x<<"  ";
    cout<<endl;
}
int id(char y)
{
    if(y=='$')
    return 0;
    else
    return(y-'a'+1);
}
class suffix_array
{
    public:
    auto sort_characters(string s)
    {
        int i,n=s.size();
        vector<int>order(n,0);
        vector<int>count(27,0);
        
        for(i=0;i<n;i++)
            count[id(s[i])]++;
        
        for(i=1;i<27;i++)
            count[i]+=count[i-1];

        for(i=n-1;i>=0;i--)
        {
            int c=id(s[i]);
            count[c]--;
            order[count[c]]=i;
        }
        return order;
    }
    auto compute_char_classes(string s,vector<int> order)
    {
        int n=s.size();
        vector<int> rank(n,0);
        rank[order[0]]=0;
        for(int i=1;i<n;i++)
        {
            if(s[order[i]]!=s[order[i-1]])
                rank[order[i]]=rank[order[i-1]]+1;
            else
                rank[order[i]]=rank[order[i-1]];
        }
        return rank;
    }
    auto sort_doubled(string s,int l,vector<int> order,vector<int>rank)
    {
        int n=s.size();
        vector<int> count(n,0);
        vector<int> new_order(n,0);
        int i;
        for(i=0;i<n;i++)
            count[rank[i]]++;
        for(int j=1;j<n;j++)
            count[j]+=count[j-1];
        for(i=n-1;i>=0;i--)
        {
            int start=(order[i]-l+n)%n;
            int cl=rank[start];
            count[cl]--;
            new_order[count[cl]]=start;
        }
        return new_order;
    }
    auto update_classes(vector<int>new_order,vector<int>rank,int l)
    {
        int n=new_order.size();
        vector<int> new_rank(n,0);
        new_rank[new_order[0]]=0;

        for(int i=1;i<n;i++)
        {
            int cur=new_order[i];
            int prev=new_order[i-1];
            int mid=cur+l;
            int midprev=(prev+l)%n;

            if(rank[cur]!=rank[prev] || rank[mid]!=rank[midprev])
                new_rank[cur]=new_rank[prev]+1;
            else
                new_rank[cur]=new_rank[prev];

        }
        return new_rank;
    }
    auto build_suffix_array(string s)
    {
        vector<int> order=sort_characters(s);
        vector<int> rank=compute_char_classes(s,order);
        int l=1;

        while(l<s.size())
        {
            order=sort_doubled(s,l,order,rank);
            rank=update_classes(order,rank,l);
            l=2*l;
        }
        return order;
    }
};

int main()
{
    string s;
    cin>>s;
    suffix_array sa;
    s=s+'$';
    vector<int> result=sa.build_suffix_array(s);
    printvect(result);

} 