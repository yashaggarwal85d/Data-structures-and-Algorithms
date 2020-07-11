#include<bits/stdc++.h>
using namespace std;

class dynamicarray
{
    private :
             int size,capacity,*arr;
    public:
            dynamicarray()
            {
                size=0;
                capacity=2;
                arr=new int[2];
            }
            void get()
            {
                int i;
                cin>>i;
                if(i>=0 && i<size)
                cout<<arr[i];
                else
                cout<<"out of range";
            }
            void set()
            {
                int i,value;
                cin>>i>>value;
                if(i>=0 && i<size)
                arr[i]=value;
                else
                cout<<"out of range";
            }
            void pushback()
            {
                int value;
                cin>>value;
                if(size==capacity)
                {
                    capacity=2*capacity;
                    int *temp,i;
                    temp=new int[capacity];
                    for(i=0;i<size;i++)
                    temp[i]=arr[i];
                    arr[i]=value;
                    free(arr);
                    arr=temp;
                }
                else
                {
                    arr[size]=value;
                    size++;
                }
            }
            void remove()
            {
                int i;
                cin>>i;
                if(i>=0 && i<size)
                {
                    int j;
                    for(j=i;j<size-1;j++)
                    arr[i]=arr[i+1];
                    size--;
                }
                else
                cout<<"out of range";
            }
            void returnsize()
            {
                cout<<"size="<<size<<"\ncapacity"<<capacity;
            }
};

int main()
{
    dynamicarray d;
    while(1)
    {
        int a;
        cout<<"\n 1.push back \n 2.get \n 3.set \n 4.remove \n 5.size";
        cin>>a;
        switch (a)
        {
        case 1:d.pushback();
            break;
        case 2:d.get();
            break;
        case 3:d.set();
            break;
        case 4:d.remove();
            break;
        case 5:d.returnsize();
            break;
        default:exit(0);
        }
    }
}