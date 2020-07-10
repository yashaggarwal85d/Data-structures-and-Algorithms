#include<bits/stdc++.h> 
using namespace std; 

class hash 
{ 
	int capacity;
    list<int> *table; 

    public: 
	
    hash(int b) 
    { 
	    capacity = b; 
	    table = new list<int>[capacity]; 
    } 
	
    void insertItem() 
    { 
        int key;
        cin>>key;
	    int index = hashFunction(key); 
	    table[index].push_back(key);  
    }  

	void deleteItem() 
    { 
        int key;
        cin>>key;
        
        int index = hashFunction(key); 

        for (auto i = table[index].begin();i!= table[index].end(); i++)
        { 
	        if (*i == key) 
	        break; 
        } 

        if (i != table[index].end()) 
	    table[index].erase(i); 
    }  

	int hashFunction(int x)
    { 
		return (x % capacity); 
	} 

	void displayhash()
    {
        for (int i = 0; i < capacity; i++) 
        { 
	        cout << i; 
	        for (auto x : table[i]) 
	            cout << " --> " << x; 
	            cout << endl; 
        } 

    } 
}; 

int main() 
{
    int n;
    cout<<"enter the size of hash table";
    cin>>n;
    hash h(n);
    while(1)
    {
        cout<<"\n1.insert\n2.delete\n3.display";
        int a;
        cin>>a;
        switch (a)
        {
        case 1:h.insertItem();
            break;
        case 2:h.deleteItem();
            break;
        case 3:h.displayhash(); 
            break;   
        }
    }
} 
