#include<bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    node *left;
    node *right;
    node *parent;
};
class binarysearchtreee
{
    private:
           node *root;
    public:
           binarysearchtreee()
           {
               root=NULL;
           } 
           auto returnroot()
           {
               return root;
           }
           int returnint()
           {
               int k;
               cin>>k;
               return k;
           }
           auto find(int k,node * r)
           {
               if(r->data==k)
               return r;
               else
               if(r->data>k)
               return find(k,r->left);
               else
               if(r->data<k)
               return find(k,r->right);
           }
           auto leftdescendant(node *n)
           {
               if(n->left==NULL)
               return n;
               else
               return leftdescendant(n->left);
           }
           auto rightancestor(node *n)
           {
               if((n->data)<(n->parent->data))
               return(n->parent);
               else
               return rightancestor(n->parent);
           }
           auto next(node * n)
           {
               if(n->right!=NULL)
               return leftdescendant(n->right);
               else
               return rightancestor(n);
           }
           void rangesearch()
           {
               int x,y;
               cin>>x>>y;
               list<int>l;
               node *n=find(x,root);
               while(n->data<=y)
               {
                   if(n->data>=x)
                   l.push_back(n->data);
                   n=next(n);
               }
               for(auto m:l)
               cout<<m;
           }
           node * insert(int x,node *t)
           {
                if(t == NULL)
                {
                    t = new node;
                    t->data = x;
                    t->left = t->right = NULL;
                }
                else if(x < t->data)
                {
                    t->left = insert(x, t->left);
                    t->left->parent=t;
                }
                else if(x > t->data)
                {
                    t->right = insert(x, t->right);
                    t->right->parent=t;
                }
                return t;
           }
           void add()
           {
               int x;
               cin>>x;
               root=insert(x,root); 
           }
           void remove(node *n)
           {
               
               if(n->right==NULL && n->left==NULL)
               {
                if(n->parent->data>n->data)
                n->parent->left=NULL;
                else
                n->parent->right=NULL;
                delete n;
               }
               else
               if(n->right==NULL)
               {
               cout<<"hi";
                n->data=n->left->data;
                remove(n->left);
               }
               else
               {
                node *x=next(n);
                n->data=x->data;
                remove(x);
               }
           }
           void deleten(int k)
           {
               node *n=find(k,root);
               remove(n);
           }
           void inordertraversal(node *temp)
            {
                if(temp!=NULL)
                {
                    inordertraversal(temp->left);
                    cout<<temp->data;
                    inordertraversal(temp->right);
                }
            }
};
int main()
{
    binarysearchtreee t;
    while(1)
    {
        cout<<"\n1.insert\n2.delete\n3.range search\n4.display";
        int a;
        cin>>a;
        switch(a)
        {
            case 1:t.add();
            break;
            case 2:t.deleten(t.returnint());
            break;
            case 3:t.rangesearch();
            break;
            case 4:t.inordertraversal(t.returnroot());
            break;
            default:exit(0);
        }
    }
}