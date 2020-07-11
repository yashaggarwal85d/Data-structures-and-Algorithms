#include <bits/stdc++.h>
using namespace std;

struct node
{
    char data;
    vector<node *> children;
};

class suffix_trie
{
    private:
           node *root;
    public:
            suffix_trie()
            {
                root=new node;
                root->data=' ';
            }
            auto returnroot()
            {
                return(root);
            }
            void suffix_trie_construction(string text)
            {
                string str=text;
                node *temp;
                int i=0;
                while(!str.empty())
                {
                    temp=root;
                    i++;
                    for(auto s : str )
                    {
                        int f=1;
                        for( auto &x : temp->children)
                        {
                            if(s==x->data)
                            {
                                temp=x;
                                f=0;
                            }
                        }
                        if(f)
                        {
                            node *newnode= new node;
                            newnode->data=s;
                            temp->children.push_back(newnode);
                            temp=newnode;
                        }
                    }
                    str=str.substr(1,str.size()+1);
                }

            }
            void suffix_trie_matching(string str)
            {
                string result="";
                node *temp=root;
                for(auto s : str)
                {
                    int f=1;
                    for(auto &x:temp->children)
                    {
                        if(x->data==s)
                        {
                            result.push_back(s);
                            f=0;
                            temp=x;
                        }
                    }
                    if(f)
                    return;
                }
                cout<<"\nfound\n";
            }
};

int main()
{
    suffix_trie t;
    t.suffix_trie_construction("panamabananas");
    while(1)
    {
        cout<<"enter the text - ";
        string s;
        cin>>s;
        t.suffix_trie_matching(s);
    }
}
