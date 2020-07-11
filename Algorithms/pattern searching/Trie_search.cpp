#include <bits/stdc++.h>
using namespace std;

struct node
{
    char data;
    vector<node *> children;
};

class trie
{
    private:
           node *root;
    public:
            trie()
            {
                root=new node;
                root->data=' ';
            }
            auto returnroot()
            {
                return(root);
            }
            void trie_construction(string str)
            {
                node *temp;
                temp=root;

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
            }
            void trie_matching(string text)
            {
                while(!text.empty())
                {
                    prefix_matching(text);
                    text=text.substr(1,text.size()+1);
                }
            }
            void prefix_matching(string str)
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
                    
                    if(temp->children.empty())
                    cout<<result<<endl;
                }
            }
            void display_trie(node *temp)
            {
                cout<<temp->data;
                if(temp->children.empty())
                cout<<endl;
                for(auto &x : temp->children)
                {
                    cout<<x->data;
                    for(auto &y : x->children)
                    display_trie(y);
                }
            }
};

int main()
{
    trie t;
    char ch='y';
    while(ch=='y')
    {
        cout<<"enter the string - ";
        string s;
        cin>>s;
        t.trie_construction(s);
        cin>>ch;
    }

    cout<<"enter the text - ";
    string s;
    cin>>s;
    t.trie_matching(s);
    
}
