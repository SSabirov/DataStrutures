// BinaryTree.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

struct Node {
    int key;
    Node* left;
    Node* right;
};



Node* root;
Node* create(int key);
Node* addNode(Node* root, int key);
void PrintInOrder(Node* root);
Node* returnNode(Node* root, int key);
int returnRootKey();
void PrintInfo(int key);
int findSmallest(Node* root);
void deleteNode(Node* root, int key);
void removeRootMatch();
void RemoveMatch(Node* root, Node* match, bool left);


int main()
{
    int n, j;
    int ch;
    cout << "1) Insert values to BT" << endl;
    cout << "2) Delete an elemnt from BT" << endl;
    cout << "3) Display elements in BT " << endl;
    cout << "4) To ge the information about node" << endl;
    cout << "5) To exit" << endl;
    do {
        cout << "Enter your choice : " << endl;
        cin >> ch;
        switch (ch) {
        case 1: cout << "how many element you would like to insert ?\t";
            cin >> j;
            for (int i = 0; i < j; i++) {
                cout << "insert intial value: \t";
                cin >> n;
                root = addNode(root, n);
            }
            break;
        case 2:cout << "Enter the value to delete\t";
            cin >> n;
            deleteNode(root, n);
            break;
        case 3: PrintInOrder(root);
            cout << endl;
            break;
        case 4: cout << "Enter the value to get an Information : \t";
            cin >> n;
            PrintInfo(n);
            break;
        case 5: cout << "Exit" << endl;
            break;
        default: cout << "Invalid choice" << endl;
        }
    } while (ch != 5);

}

Node* create(int key)
{
    Node* newNode = new Node;
    newNode->key = key;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

Node* addNode(Node* root, int key)
{
    Node* nodePtr;
    nodePtr = root;
    if (root == NULL)
    {
        root = create(key);
    }
    else if (key < nodePtr->key)
    {
        if (nodePtr->left != NULL)
        {
            addNode(nodePtr->left, key);
        }
        else
        {
            nodePtr->left = create(key);
        }
    }
    else if (key > nodePtr->key)
    {
        if (nodePtr->right != NULL)
        {
            addNode(nodePtr->right, key);
        }
        else
        {
            nodePtr->right = create(key);
        }
    }
    return root;
}


void PrintInOrder(Node* root)
{
    Node* nodePtr;
    nodePtr = root;
    if (root != NULL)
    {
        if (nodePtr->left != NULL)
        {
            PrintInOrder(nodePtr->left);
        }
        cout << nodePtr->key << " ";
        if (nodePtr->right != NULL)
        {
            PrintInOrder(nodePtr->right);
        }
    }
    else
    {
        cout << "Tree is empty";
    }
}

Node* returnNode(Node* root, int key)
{
    Node* nodePtr;
    nodePtr = root;
    if (nodePtr != NULL)
    {
        if (nodePtr->key == key)
        {
            return nodePtr;
        }
        else
        {
            if (key < nodePtr->key)
            {
                return returnNode(nodePtr->left, key);
            }
            else
            {
                return returnNode(nodePtr->right, key);
            }
        }
    }
    else
    {
        return NULL;
    }
}

int returnRootKey()
{
    if (root != NULL)
    {
        return root->key;
    }
    else
    {
        return -1000;
    }
}

void PrintInfo(int key)
{
    Node* nodePtr = returnNode(root, key);
    if (nodePtr != NULL)
    {
        cout << "Parent Node = " << nodePtr->key << endl;
        nodePtr->left == NULL ?
            cout << "left child = NULL \n" :
            cout << "left child = " << nodePtr->left->key << endl;
        nodePtr->right == NULL ?
            cout << "Right child = NULL \n" :
            cout << "Right child = " << nodePtr->right->key << endl;
    }
    else
    {
        cout << "Value" << key << "is not in the tree\n";
    }
}


int findSmallest(Node* root)
{
    Node* nodePtr;
    nodePtr = root;
    if (root == NULL)
    {
        cout << "the tree is empty";
        return 0;
    }
    else
    {
        if (nodePtr->left != NULL)
        {
            return findSmallest(nodePtr->left);
        }
        else
        {
            return nodePtr->key;
        }
    }
}

void deleteNode(Node* root, int key)
{
    Node* nodePtr;
    nodePtr = root;
    if (root != NULL)
    {
        if (root->key == key)
        {
            removeRootMatch();
        }
        else
        {
            if (key < nodePtr->key && nodePtr->left != NULL)
            {
                nodePtr->left->key == key ?
                    RemoveMatch(nodePtr, nodePtr->left, true) :
                    deleteNode(nodePtr->left, key);
            }
            else if (key > nodePtr->key && nodePtr->right != NULL)
            {
                nodePtr->right->key == key ?
                    RemoveMatch(nodePtr, nodePtr->right, false) :
                    deleteNode(nodePtr->right, key);
            }
            else
            {
                cout << "Value was not found in the tree";
            }
        }
    }
    else
    {
        cout << "the tree is empty";
    }
}

void removeRootMatch()
{
    Node* nodePtr;
    nodePtr = root;
    if (root != NULL)
    {
        int rootKey = root->key;
        int smallestInRightSubtree;
    
        if (root->left == NULL && root->right == NULL)
        {
            root = NULL;
            delete nodePtr;
        }
       
        else if (root->left == NULL && root->right != NULL)
        {
            root = root->right;
            nodePtr->right = NULL;
            delete nodePtr;
        }
        
        else if (root->left != NULL && root->right == NULL)
        {
            root = root->left;
            nodePtr->left = NULL;
            delete nodePtr;
        }
        
        else
        {
            smallestInRightSubtree = findSmallest(root->right);
            deleteNode(root, smallestInRightSubtree);
            root->key = smallestInRightSubtree;
        }
    }
    else
    {
        cout << "The tree is empty";
    }
}

void RemoveMatch(Node* parent, Node* match, bool left)
{
    if (root != NULL)
    {
        Node* nodePtr;
        int matchKey = match->key;
        int smallestInRightSubtree;
        
        if (match->left == NULL && match->right == NULL)
        {
            nodePtr = match;
            left = true ? parent->left = NULL : parent->right = NULL;
            delete nodePtr;
        }
        
        else if (match->left == NULL && match->right != NULL)
        {
            left == true ? parent->left = match->right : parent->right = match->right;
            match->right = NULL;
            nodePtr = match;
            delete nodePtr;
        }
       
        else if (match->left != NULL && match->right == NULL)
        {
            left == true ? parent->left = match->left : parent->right = match->left;
            match->left = NULL;
            nodePtr = match;
            delete nodePtr;
        }
        
        else
        {
            smallestInRightSubtree = findSmallest(match->right);
            deleteNode(match, smallestInRightSubtree);
            match->key = smallestInRightSubtree;
        }
    }
}