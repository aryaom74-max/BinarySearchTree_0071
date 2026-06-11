#include <iostream>
#include <string>
using namespace std;

class Node
{
    public:
    string info;
    Node *leftchild;
    Node *righchild;

    //constructor for the node class
    Node (string i, Node *l, Node *r)
    {
        info = i;
        leftchild = l;
        righchild = r;
    }
};

class BinaryTree 
{
    public:
    Node *ROOT;

    BinaryTree()
    {
        ROOT = NULL; //initially set the ROOT to null
    }

    //Insert a Node in the binary search tree
    void insert (string element)
    {
        Node *newNode = new Node (element, NULL, NULL);

        newNode->info = element;
        newNode->leftchild = NULL;
        newNode->righchild = NULL;

        Node *parent = NULL;
        Node *currentNode = NULL;

        search (element, parent, currentNode);

        if (parent == NULL)
        {
            ROOT = newNode;
            return;
        }

        if (element < parent -> info)
        {
           parent -> leftchild = newNode; 
        }
        else
        {
            parent -> righchild = newNode;
        }
    }

    //this function searches the current node of the spicfied node
    //as well as the current node of its parent
    void search (string element, Node *&parent, Node *&currentNode)
    {
        currentNode = ROOT;
        parent = NULL;

        while (currentNode != NULL && currentNode -> info != element)
        {
            parent = currentNode;

            if (element < currentNode -> info)
            {
                currentNode = currentNode -> leftchild;
            }
            else
            {
                currentNode = currentNode -> righchild;
            }
        }
    }

    void inorder (Node *ptr)
    {
        if (ROOT == NULL)
        {
            cout << "tree is empty" << endl;
            return;
        }

        if (ptr != NULL)
        {
            inorder(ptr->leftchild);
            cout << ptr->info << " ";
            inorder(ptr->righchild);
        }
    }
    void preorder (Node *ptr)
    {
        if (ROOT == NULL)
        {
            cout << "tree is empty" << endl;
            return;
        }

        if (ptr != NULL)
        {
            cout << ptr->info << " ";
            preorder(ptr->leftchild);
            preorder(ptr->righchild);
        }
    }
    void postorder (Node *ptr)
    {
        if (ROOT == NULL)
        {
            cout << "tree is empty" << endl;
            return;
        }

        if (ptr != NULL)
        {
            postorder(ptr->leftchild);
            postorder(ptr->righchild);
            cout << ptr->info << " ";
        }
    }
};

int main()
{
    BinaryTree obj;

    while (true)
    {
        cout << "\nMenu" << endl;
        cout << "1. implement insert operation" << endl;
        cout << "2. perform inorder traversal" << endl;
        cout << "3. perform preorder traversal" << endl;
        cout << "4. perform postorder traversal" << endl;
        cout << "5. exit" << endl;
        cout << "Enter your choice: (1-5) ";
        
        
