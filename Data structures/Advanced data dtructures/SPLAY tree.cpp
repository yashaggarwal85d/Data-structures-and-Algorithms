#include <bits/stdc++.h> 
using namespace std; 

struct node 
{ 
	public: 
	int key; 
	node *left, *right; 
}; 

class splaytree
{
    private:
    node *root;
    public:
    splaytree()
    {
        root=NULL;
    }
    auto returnroot()
    {
        return root;
    }
    node* newNode(int key) 
    { 
	    node* Node = new node(); 
	    Node->key = key; 
	    Node->left = Node->right = NULL; 
	    return (Node); 
    } 
    
    node *rightRotate(node *x) 
    { 
	    node *y = x->left; 
    	x->left = y->right; 
	    y->right = x; 
	    return y; 
    } 
    node *leftRotate(node *x) 
    { 
	    node *y = x->right; 
	    x->right = y->left; 
	    y->left = x; 
	    return y; 
    } 
    node *splay(node *root, int key) 
    {
	    if (root == NULL || root->key == key) 
		return root; 
	    if (root->key > key) 
	    {  
		    if (root->left == NULL) return root; 
     		if (root->left->key > key) 
	    	{ 
			root->left->left = splay(root->left->left, key); 
			root = rightRotate(root); 
    		} 
		    else
            if (root->left->key < key) // Zig-Zag (Left Right) 
		    {  
			    root->left->right = splay(root->left->right, key); 
			    if (root->left->right != NULL) 
				root->left = leftRotate(root->left); 
		    } 
		    return (root->left == NULL)? root: rightRotate(root); 
	    } 
	    else 
	    {  
		    if (root->right == NULL)
            return root;  // Zig-Zag (Right Left) 
		    if (root->right->key > key) 
		    {  
			    root->right->left = splay(root->right->left, key);  
			    if (root->right->left != NULL) 
				root->right = rightRotate(root->right); 
		    } 
		    else
            if (root->right->key < key)// Zag-Zag (Right Right) 
		    { 
			root->right->right = splay(root->right->right, key); 
			root = leftRotate(root); 
		    }  
		    return (root->right == NULL)? root: leftRotate(root); 
	    } 
    } 

    node *insert(node *root, int k) 
    { 
	    if (root == NULL)
        return newNode(k);  

	    root = splay(root, k);

	    if (root->key == k)
        return root; 
 
	    node *newnode = newNode(k); 
    
        if (root->key > k) 
	    { 
		    newnode->right = root; 
		    newnode->left = root->left; 
		    root->left = NULL; 
	    } 
        else
	    { 
		    newnode->left = root; 
		    newnode->right = root->right; 
		    root->right = NULL; 
	    } 

	    return newnode; 
    } 
    void splayinsert()
    {
        int k;
        cin>>k;
        root=insert(root,k);
    }
    node *search(node *root, int key)  
    {  
        return splay(root, key);  
    }
    void preOrder(node *root) 
    { 
	    if (root != NULL) 
	    { 
		    cout<<root->key<<" "; 
		    preOrder(root->left); 
		    preOrder(root->right); 
	    } 
    } 

};

int main() 
{ 
    splaytree t;
    while(1)
    {
        cout<<"\n1.insert\n2.display";
        int a;
        cin>>a;
        switch(a)
        {
            case 1:t.splayinsert();
            break;
            case 2:t.preOrder(t.returnroot());
            break;
            default:exit(0);
        }
    }
} 