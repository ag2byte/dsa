// this is for a BST
#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int data, Node *left, Node *right)
    {
        this->data = data;
        this->left = left;
        this->right = right;
    }
};
class BST
{
private:
    int nCount = 0;
    Node *root = NULL;
    Node *add(Node *node, int n)
    {
        if (node == NULL)
            node = new Node(n, NULL, NULL);
        else
        {
            if (node->data < n) //move to right
                node->right = add(node, n);
            else if (node->data > n) // move to left
                node->left = add(node, n);
        }
        return node;
    }
    Node *remove(Node *node, int n)
    {
        if (node == NULL)
            return NULL;

        // finding
        if (node->data > n)
            node->left = remove(node, n);
        else if (node->data < n)
            node->right = remove(node, n);
        else
        {
            //found the value now remove it
            // right subtree present
            if (node->left == NULL)
            {
                Node *suc = node->right;
                node->data = NULL;
                node = NULL;
                return suc;
            }
            else if (node->right == NULL)
            {
                Node *suc = node->left;
                node->data = NULL;
                node = NULL;
                return suc;
            }
            else // both exisits
            {
                //successor can be both largest of left and smallest of right
                //let us choose smallest of right
                Node *suc = findSmallest(node->right); // returns as  the name
                node->data = suc->data;
                node->right = remove(node->right, suc->data);
            }
        }
        return node;
    }

    Node *findSmallest(Node *node)
    {
        Node *cur = node;
        while (cur->left != NULL)
            cur = cur->left;
        return cur;
    }
    bool contains(Node *node, int elem)
    {
        if (node == NULL)
            return false;
        else
        {
            if (node->data == elem)
                return true;
            else if (node->data > elem)
                return contains(node->left, elem);
            else
                return contains(node->right, elem);
        }
    }

public:
    int height(Node *node) //calculate height from this node
    {
        if (node == NULL)
            return 0;
        else
            return max(height(node->left), height(node->right)) + 1;
    }
    bool contains(int elem)
    {
        return (contains(root, elem));
    }
    bool isEmpty()
    {
        return tSize() == 0;
    }
    int tSize()
    {
        return nCount;
    }
    bool add(int n) // returns true if added successfully
    {
        if (contains(n))
            return false;
        else
        {
            root = add(root, n);
            nCount++;
            return true;
        }
    }
    bool remove(int n) //public method for removing
    {
        if (contains(n))
        {
            remove(root, n); //private method for removing
            nCount--;
            return true;
        }
        else
        {
            return false;
        }
    }
};