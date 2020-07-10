#include<bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    node *parent;
    vector<node *> children;
};
class tree
{
    private:
           node *root;
    public:
            tree()
            {
                root=NULL;
            }
            auto returnroot()
            {
                return(root);
            }
            void addchild()
            {
                int x;
                cin>>x;
                node *temp =new node;
                temp->data =x;
                if(root==NULL)
                {
                root=temp;
                root->parent=NULL;
                }
                else
                {
                temp->parent=root;
                root->children.push_back(temp);
                }
            } 
            void setchildroot()
            {
                if(root==NULL)
                cout<<"no root";
                else
                if(root->children.size()==0)
                cout<<"no child";
                else
                {
                    int x;
                    cin>>x;
                    root=root->children[x-1];
                }
            }
            void setparentroot()
            {
                if(root->parent==NULL)
                cout<<"no parent";
                else
                root=root->parent;
            }
            void resetroot()
            {
                while(root->parent!=NULL)
                root=root->parent;
            }
            void display(node *temp)
            {
                cout<<temp->data;
                for(auto x:temp->children)
                {
                    display(x);
                    cout<<"\t";
                }
            }
            void popchildren()
            {
                int x;
                cout<<"\n enter the position of the child to be deleted";
                cin>>x;
                root->children.erase(root->children.begin()+x-1);
            }
};
int main()
{
    tree t;
    while(1)
    {
        int a;
        cout<<"\n \n \n \n 1.add child \n 2.make child parent \n 3.make parent child() \n 4.reset root \n 5.display \n 6.popchildren";
        cin>>a;
        switch(a)
        {
        case 1: t.addchild();
                break;
        case 2: t.setchildroot();
                break;
        case 3: t.setparentroot();
                break;
        case 4: t.resetroot();
                break;
        case 5: t.display(t.returnroot());
                break;
        case 6: t.popchildren();
                break;
        default : exit(0);
    }
    }
}
