#include<iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

//Definition of Node for Binary search tree
struct Node
{
	int data; 
	Node* left;
	Node* right;
};

// Function to create a new Node in heap
Node* CreateNode(int data)
{
	Node* newNode = new Node();
	newNode->data = data;
	newNode->left = newNode->right = NULL;
	return newNode;
}

// To insert data in BST, returns address of root node 
Node* Insert(Node* root, int data)
{
	if(root == NULL) //If the tree is empty
		root = CreateNode(data);

	// if data to be inserted is lesser, insert in left subtree. 
	else if(data <= root->data)
		root->left = Insert(root->left, data);

	// else, insert in right subtree. 
	else
		root->right = Insert(root->right, data);

	return root;
}

/*
    Converting the BST to a linked list:
*/
void ConvertToLinkedList(Node *root, Node **head)
{
    //  If tree is empty do nothing
    if(root == NULL)
        return;

    static Node *prev = NULL;
    //First recursively convert the left subtree
    ConvertToLinkedList(root->left, head);
    if(prev == NULL)
        *head = root;
    else
    {
        root->left = prev;
        prev->right = root;
    }
    prev = root;
    //Convert the right subrtree
    ConvertToLinkedList(root->right, head);   
}


//  Printing functions

void printBST(Node *root) // Print by level
{
    if(root != NULL)
    {
        std::cout << root->data << " ";
        printBST(root->left);
        printBST(root->right);
    }
}

void printList(Node *node)
{
    while (node!=NULL)
    {
        std::cout << node->data << " ";
        node = node->right;
    }
}

int main()
{
    srand(time(nullptr));

    Node* tree = NULL;
    for(int i = 0; i < 15; i++)
    {
        //  Inserting random integers
        tree = Insert(tree, rand()%40+1);
    }

    cout << "Printing BST:" << endl;
    printBST(tree);
    cout << endl;
    Node* List = NULL;
    //Coverting to linked list
    ConvertToLinkedList(tree, &List);
    cout << "Printing List:" << endl;
    printList(List);
    cout << endl;

    return 0;
}