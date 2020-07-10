#include <bits/stdc++.h>
using namespace std;

class Trie 
{
    public:
    struct Trie *child[100];
    bool endofstring;

    Trie *createNode()
    {
        Trie *tNode = new Trie;
        tNode->endofstring = false;
        for (int i = 0; i < 100; i++)
        {
            tNode->child[i] = NULL;
        }
        return tNode;
    }

    void insert(struct Trie *root, string key)
    {
        struct Trie *curr = root;
        for (int i = 0; i < key.length(); i++) 
        {
            int index = key[i] - 'A';
            if (!curr->child[index])
                curr->child[index] = createNode();
            curr = curr->child[index];
        }
        curr->endofstring= true;
    }

    bool search(struct Trie *root, string key)
    { 
        struct Trie *curr = root;
        for (int i = 0; i < key.length(); i++)
        {
            int index = key[i] - 'A';
            if (!curr->child[index])
                return false;
            curr = curr->child[index];
        }
        return (curr != NULL && curr->endofstring);
    }

    bool isEmpty(Trie* root)
    {
        for (int i = 0; i < 100; i++)
        {
            if (root->child[i])
                return false;
        }
        return true;
    }

    Trie* deletion(Trie* root, string key, int depth = 0) 
    {
        if (!root)
            return NULL;
        if (depth == key.size()) 
        {
            if (root->endofstring)
            root->endofstring = false;
            if (isEmpty(root))
            { 
                delete (root);
                root = NULL;
            }
            return root;
        }
        int index = key[depth] - 'A';
        root->child[index] =
        deletion(root->child[index], key, depth + 1);

        if (isEmpty(root) && root->endofstring == false)
        { 
            delete (root);
            root = NULL;
        }
        return root;
    }

};

int main()
{
    Trie t;
    string inputs[] = {"HELLOWORLD","HI","BYE", "THE","THENA"};
    int n = 5;
    struct Trie *root = t.createNode();

    for (int i = 0; i < n; i++)
        t.insert(root, inputs[i]);

    t.search(root, "HELLOWORLD")? cout << "Key is Found\n": cout << "Key is not Found\n";
    t.search(root, "HE")? cout << "Key is Found\n" : cout << "Key is not Found\n";
    t.deletion(root, "THEN")? cout << "Key is deleted\n" : cout << "Key is not Deleted\n";
    return 0;
}