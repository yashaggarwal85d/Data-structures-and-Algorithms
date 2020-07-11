#include<bits/stdc++.h> 
using namespace std; 

struct node 
{ 
	public: 
	int key,height; 
	node *left; 
	node *right; 
}; 
class avltree
{
    private:
            node *root;

    public:
            avltree()
            {
                root=NULL;
            }        
            auto returnroot()
            {
                return root;
            }
            int height(node *N)  
            {  
                if (N == NULL)  
                return 0;  
                return N->height;  
            }  
            int max(int a, int b) 
            { 
	            return (a > b)? a : b; 
            } 
            node* newnode(int key) 
            { 
	            node* temp = new node(); 
	            temp->key = key; 
	            temp->left = NULL; 
	            temp->right = NULL; 
	            temp->height = 1; 
	            return(temp); 
            } 
        void adjustheight(node *n)
        {
            n->height=max(height(n->left),height(n->right))+1;
        }
        node *rightRotate(node *y) 
        { 
	        node *x = y->left; 
	        node *T2 = x->right; 
            x->right = y; 
	        y->left = T2; 
            adjustheight(y); 
            adjustheight(x);  
	        return x; 
        } 
        node *leftRotate(node *x) 
        { 
	        node *y = x->right; 
	        node *T2 = y->left; 
	        y->left = x; 
	        x->right = T2;
            adjustheight(x);
            adjustheight(y);
	        return y; 
        }  
        int getBalance(node *N) 
        { 
	        if (N == NULL) 
		    return 0; 
	        return height(N->left)-height(N->right); 
        }
        node* insert(node* temp, int key) 
        {
	        if (temp == NULL) 
		    return(newnode(key)); 
	        if (key < temp->key) 
		    temp->left = insert(temp->left, key); 
	        else
            if (key > temp->key) 
		    temp->right = insert(temp->right, key); 
	        else         
		    return temp; 

	        adjustheight(temp); 
	        int balance = getBalance(temp); 
            if (balance > 1 && key < temp->left->key) 
		    return rightRotate(temp);  
	        if (balance < -1 && key > temp->right->key) 
            return leftRotate(temp);  
	        if (balance > 1 && key > temp->left->key) 
	        { 
		        temp->left = leftRotate(temp->left); 
		        return rightRotate(temp); 
	        } 
	        if (balance < -1 && key < temp->right->key) 
	        { 
		        temp->right = rightRotate(temp->right); 
		        return leftRotate(temp); 
	        }  
	        return temp; 
        }  
        void avlinsert()
        {
            int k;
            cin>>k;
            root=insert(root,k);
        }
        node * minValuenode(node* temp)  
        {  
            node* current = temp;  
            while (current->left != NULL)  
            current = current->left;  
            return current;  
        }
        node* deletenode(node* root, int key)  
        {   
            if (root == NULL)  
            return root;    
            if ( key < root->key )  
            root->left = deletenode(root->left, key);   
            else if( key > root->key )  
            root->right = deletenode(root->right, key);  
            else
            {   
                if((root->left == NULL) || (root->right == NULL) )  
                {  
                    node *temp = root->left ? root->left :  root->right;  
                    if (temp == NULL)  
                    {  
                        temp = root;  
                        root = NULL;  
                    }  
                    else 
                    *root = *temp;  
                    free(temp);  
                }  
                else
                {
                    node* temp = minValuenode(root->right);    
                    root->key = temp->key;  
                    root->right = deletenode(root->right,temp->key);  
                }  
            }  
            if (root == NULL)  
            return root;
            adjustheight(root); 
            int balance = getBalance(root);    
            if (balance > 1 && getBalance(root->left) >= 0)  
            return rightRotate(root);
            if (balance > 1 && getBalance(root->left) < 0)  
            {  
                root->left = leftRotate(root->left);  
                return rightRotate(root);  
            }  
            if (balance < -1 && getBalance(root->right) <= 0)  
            return leftRotate(root);    
            if (balance < -1 && getBalance(root->right) > 0)  
            {  
                root->right = rightRotate(root->right);  
                return leftRotate(root);  
            }  
        return root;  
        }  
        void avldelete()
        {
            int k;
            cin>>k;
            root=deletenode(root,k);
        }
        void preOrder(node *root) 
        { 
	        if(root != NULL) 
	        { 
		        cout << root->key << " "; 
		        preOrder(root->left); 
		        preOrder(root->right); 
	        } 
        } 
};
int main() 
{ 
	avltree t;
    while(1)
    {
        cout<<"\n1.insert\n2.delete\n3.display";
        int a;
        cin>>a;
        switch(a)
        {
            case 1:t.avlinsert();
            break;
            case 2:t.avldelete();
            break;
            case 3:t.preOrder(t.returnroot());
            break;
            default:exit(0);
        }
    }
} 