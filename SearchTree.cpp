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

        
