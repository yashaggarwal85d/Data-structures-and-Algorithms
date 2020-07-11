#include <bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    node *next;
};

class linked_list
{
 private:
         node *head,*tail;
 public:
        linked_list()
        {
            head=NULL;
        }
        void pushfront()
        {
            int x;
            cin>>x;
            node *temp =new node;
            temp->data=x;
            temp->next=head;
            head=temp;
        }
        void popfront()
        {
            if(head==NULL)
            cout<<"list is empty";
            else
            head=head->next;
        }
        void pushback()
        {
            int x;
            cin>>x;
            node *temp =new node;
            temp->data=x;
            temp->next=NULL;
            node *ptr =new node;
            if(head==NULL)
            head=temp;
            else
            {
            for(ptr=head;ptr->next!=NULL;ptr=ptr->next);
            ptr->next=temp;
            }
        }
        void popback()
        {
            if(head==NULL)
            cout<<"list is empty";
            else
            {
            node *ptr =new node;
            if(head->next==NULL)
            head=NULL;
            else
            {
            for(ptr=head;ptr->next->next!=NULL;ptr=ptr->next);
            ptr->next=NULL;
            }
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
            node *temp =new node;
            node *ptr =new node;
            ptr=returnode(n);
            temp->data=x;
            temp->next=ptr->next;
            ptr->next=temp;
        }
        void addbefore ()
        {
            int x,n;
            cout<<"enter position and data";
            cin>>n>>x;
            node *temp =new node;
            node *ptr =new node;
            temp->data=x;
            if(n==1)
            {
                temp->next=head;
                head=temp;
            }
            else
            {
            ptr=returnode(n-1);
            temp->next=ptr->next;
            ptr->next=temp;
            }
        }
        void display()
        {
            node *temp =new node;
            if(head==NULL)
            cout<<"list is empty";
            else
            {
            for(temp=head;temp!=NULL;temp=temp->next)
            cout<<temp->data<<"->";
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