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
         node *head;
 public:
        linked_list()
        {
            head=NULL;
        }
        void push()
        {
            int x;
            cin>>x;
            node *temp =new node;
            temp->data=x;
            temp->next=head;
            head=temp;
        }
        void pop()
        {
            if(head==NULL)
            cout<<"stack is empty";
            else
            {
                head=head->next;
            }
        }
        void display()
        {
            node *temp =new node;
            if(head==NULL)
            cout<<"stack is empty";
            else
            {
            for(temp=head;temp!=NULL;temp=temp->next)
            cout<<temp->data<<"->";
            }
        }
        void returnhead()
        {
            if(head==NULL)
            cout<<"null";
            else
            cout<<head->data;   
        }
        void empty()
        {
            if(head==NULL)
            cout<<"yes";
            else
            cout<<"no";
        }
};
int main()
{
    linked_list a;
    while(1)
    {
    cout<<"\n 1.push \n 2.pop \n 3.display \n 4.return head \n 5.check empty ";
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
        case 4:a.returnhead();
               break;
        case 5:a.empty();
               break;        

    }
    }
    return 0;
}