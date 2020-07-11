#include <iostream>
using namespace std;

struct node
{
  int data;
  node *parent;
  node *left;
  node *right;
  int color;
};

class redblacktree
{
    private:
    node *root;
    node *TNULL;
    
    void insertFix(node *k)
    {
        node *u;
        while (k->parent->color == 1)
        {
            if (k->parent == k->parent->parent->right) 
            {
                u = k->parent->parent->left;
                if (u->color == 1)
                {
                    u->color = 0;
                    k->parent->color = 0;
                    k->parent->parent->color = 1;
                    k = k->parent->parent;
                }
                else
                {
                    if (k == k->parent->left)
                    {
                        k = k->parent;
                        rightRotate(k);
                    }
                    k->parent->color = 0;
                    k->parent->parent->color = 1;
                    leftRotate(k->parent->parent);
                }
            }
            else
            {
                u = k->parent->parent->right;
                if (u->color == 1)
                {
                    u->color = 0;
                    k->parent->color = 0;
                    k->parent->parent->color = 1;
                    k = k->parent->parent;
                }
                else
                {
                    if (k == k->parent->right)
                    {
                        k = k->parent;
                        leftRotate(k);
                    }
                    k->parent->color = 0;
                    k->parent->parent->color = 1;
                    rightRotate(k->parent->parent);
                }
            }
            if (k == root)
                break;
        }
        root->color = 0;
    }

    void printHelper(node *root, string indent, bool last)
    {
        if (root != TNULL)
        {
            cout << indent;
            if (last)
            {
                cout << "R----";
                indent += "   ";
            }
            else
            {
                cout << "L----";
                indent += "|  ";
            }

            string sColor = root->color ? "RED" : "BLACK";
            cout << root->data << "(" << sColor << ")" << endl;
            printHelper(root->left, indent, false);
            printHelper(root->right, indent, true);
        }
    }

    public:
    
    redblacktree()
    {
        TNULL = new node;
        TNULL->color = 0;
        TNULL->left = NULL;
        TNULL->right = NULL;
        root = TNULL;
    }

    
    void leftRotate(node *x)
    {
        node *y = x->right;
        x->right = y->left;
    
        if (y->left != TNULL) 
            y->left->parent = x;
    
        y->parent = x->parent;
    
        if (x->parent == NULL)
            this->root = y;
    
        else if (x == x->parent->left)
            x->parent->left = y;
    
        else 
            x->parent->right = y;
    
        y->left = x;
        x->parent = y;
    }

  void rightRotate(node *x)
    {
        node *y = x->left;
        x->left = y->right;
    
        if (y->right != TNULL)
            y->right->parent = x;
    
        y->parent = x->parent;
    
        if (x->parent == NULL)
            this->root = y;

        else if (x == x->parent->right) 
            x->parent->right = y;
    
        else
            x->parent->left = y;
    
        y->right = x;
        x->parent = y;
    }

    void insert(int key)
    {
        node *temp = new node;
        temp->parent = NULL;
        temp->data = key;
        temp->left = TNULL;
        temp->right = TNULL;
        temp->color = 1;

        node *y = NULL;
        node *x = this->root;

        while (x != TNULL)
        {
            y = x;
            if (temp->data < x->data)
                x = x->left;
            
            else
                x = x->right;
        }

        temp->parent = y;
    
        if (y == NULL)
            root = temp;

        else if (temp->data < y->data)
            y->left = temp;
        
        else
            y->right = temp;

        if (temp->parent == NULL)
        {
            temp->color = 0;
            return;
        }

        if (temp->parent->parent == NULL) 
            return;
    
        insertFix(temp);
    }
    
    void printTree()
    {
        if (root)
            printHelper(this->root, "", true);
    }

};

int main() 
{
  redblacktree bst;
  bst.insert(55);
  bst.insert(40);
  bst.insert(65);
  bst.insert(60);
  bst.insert(75);
  bst.insert(57);

  bst.printTree();
}