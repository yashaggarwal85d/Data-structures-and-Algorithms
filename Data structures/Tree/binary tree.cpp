#include<bits/stdc++.h>
using namespace std;
struct node  
{ 
    int data; 
    node *left; 
    node *right; 
    node *parent;
}; 
class binarytree
{
    private:
            node *root;
    public:
           binarytree()
           {
               root=NULL;
           }
           auto add(int x)
           {
               node *temp=new node;
               temp->data=x;
               temp->left=NULL;
               temp->right=NULL;
               return (temp);
           }
           int height(node *temp)
           {
               if(temp==NULL)
               return 0;
               else
               return(1+max(height(temp->right),height(temp->left)));
           }
           int size(node *temp)
           {
               if(temp==NULL)
               return 0;
               else
               return(1+size(temp->left)+size(temp->right));
           }
           void inordertraversal(node *temp)
            {
                if(temp==NULL)
                {}
                else
                {
                    inordertraversal(temp->left);
                    cout<<temp->data;
                    inordertraversal(temp->right);
                }
            }
            void preordertraversal(node *temp)
            {
                if(temp==NULL)
                {}
                else
                {
                    cout<<temp->data;
                    preordertraversal(temp->left);
                    preordertraversal(temp->right);
                }
            }
            void postordertraversal(node *temp)
            {
                if(temp==NULL)
                {}
                else
                {
                    postordertraversal(temp->left);
                    postordertraversal(temp->right);
                    cout<<temp->data;
                }
            }
            void leveltraversal(node *temp)
            {
                if(temp==NULL)
                {}
                queue<node*> q;
                q.push(temp);
                while(!q.empty())
                {
                    node *ptr=new node;
                    ptr=q.front();
                    q.pop();
                    cout<<ptr->data;
                    if(ptr->left!=NULL)
                    q.push(ptr->left);
                    if(ptr->right!=NULL)
                    q.push(ptr->right);
                }
            }
           
};

int main()
{
    binarytree t;
    node *temp=new node;
    temp=t.add(1);
    temp->left=t.add(2);
    temp->right=t.add(3);
    temp->left->left=t.add(4);
    while(1)
    {
        cout<<"\n 1.calculate height \n 2.calculate size \n 3.level traversal display\n 4.post order traversal display \n 5.pre order traversal display \n 6.in order traversal display \n";
        int a;
        cin>>a;
        switch(a)
        {
            case 1:cout<<t.height(temp);
            break;
            case 2:cout<<t.size(temp);
            break;
            case 3:t.leveltraversal(temp);
            break;
            case 4:t.postordertraversal(temp);
            break;
            case 5:t.preordertraversal(temp);
            break;
            case 6:t.inordertraversal(temp);
            break;
            default:exit(0);
        }
    }
}