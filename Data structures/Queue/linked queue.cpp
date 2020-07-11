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
            tail=NULL;
        }
        void pop()
        {
            if(head==NULL)
            cout<<"list is empty";
            else 
            if(head==tail)
            tail=head=NULL;
            else
            head=head->next;
            
        }
        void push()
        {
            int x;
            cin>>x;
            node *temp =new node;
            temp->data=x;
            temp->next=NULL;
            if(tail==NULL)
            head=tail=temp;
            else
            {
                tail->next=temp;
                tail=temp;
            }
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
    cout<<"\n 1.push \n 2.pop \n 3.display \n";
    int x;
    cin>>x;
    switch(x)
    {
        case 1:a.push();
               break;
        case 2:a.pop();
               break;
        case 3:a.display();
               break;        
    }
    }
    return 0;
}