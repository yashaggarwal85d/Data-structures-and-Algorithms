#include <bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    node *next,*pre;
};

class linked_list
{
 private:
         node *head,*tail;
 public:
        linked_list()
        {
            head=NULL;
            tail=NULL;
        }
        void pushfront()
        {
            int x;
            cin>>x;
            node *temp =new node;
            temp->data=x;
            if(head==NULL)
            {
                head=tail=temp;
            }
            else
            {
                temp->next=head;
                head->pre=temp;
                head=temp;
                head->pre=NULL;
            }
        }
        void popfront()
        {
            if(head==NULL)
            cout<<"list is empty";
            else 
            if(head==tail)
            tail=head=NULL;
            else
            {
            head=head->next;
            head->pre=NULL;
            }
        }
        void pushback()
        {
            int x;
            cin>>x;
            node *temp =new node;
            temp->data=x;
            temp->next=NULL;
            if(tail==NULL)
            {
             head=tail=temp;
             temp->pre=NULL;
            }
            else
            {
                tail->next=temp;
                temp->pre=tail;
                tail=temp;
            }
        }
        void popback()
        {
            if(head==NULL)
            cout<<"list is empty";
            else
            if(head==tail)
            head=tail=NULL;
            else
            {
                tail=tail->pre;
                tail->next=NULL;
            }
        }
        auto returnode(int x)
        {
            node *temp =new node;
            temp=head;
            x--;
            while (x--)
            temp=temp->next;
            return temp;
        }
        void addafter ()
        {
            int x,n;
            cout<<"enter position and data";
            cin>>n>>x;
            node *node2 =new node;
            node *node1 =new node;
            node1=returnode(n);
            node2->data=x;
            node2->next=node1->next;
            node2->pre=node1;
            node1->next=node2;
            node1->next=node2;
            if(node2->next!=NULL)
            node2->next->pre=node2;
            if(node1==tail)
            tail=node2;
        }
        void addbefore ()
        {
            int x,n;
            cout<<"enter position and data";
            cin>>n>>x;
            node *node2 =new node;
            node *node1 =new node;
            node2->data=x;
            node1=returnode(n);
            node2->pre=node1->pre;
            node2->next=node1;
            node1->pre=node2;
            if(node2->pre!=NULL)
            node2->pre->next=node2;
            if(head==node1)
            head=node2;
        }
        void display()
        {
            node *temp =new node;
            if(head==NULL)
            cout<<"list is empty";
            else
            {
            for(temp=head;temp!=tail;temp=temp->next)
            cout<<temp->data<<"->";
            cout<<tail->data;
            }
        }
};
int main()
{
    linked_list a;
    while(1)
    {
    cout<<" 1.push front \n 2.popfront \n 3.push back \n 4.pop back \n 5.add after \n 6. add before \n 7.display \n";
    int x;
    cin>>x;
    switch(x)
    {
        case 1:a.pushfront();
               break;
        case 2:a.popfront();
               break;
        case 3:a.pushback();
               break;
        case 4:a.popback();
               break;
        case 5:a.addafter();
               break;
        case 6:a.addbefore();
               break;
        case 7:a.display();
               break;        
    }
    }
    return 0;
}