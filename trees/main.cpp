// C++ function to search a given key in a given BST

#include <iostream>

using namespace std;
#define COUNT 10
struct node {
    string data;
    struct node* left, * right;
};

// A utility function to create a new BST node
struct node* newNode(string item)
{
    struct node* temp
        = new struct node;
    temp->data = item;
    temp->left = temp->right = NULL;
    return temp;
}

// A Recursive function to insert
// a new node with given key in BST
struct node* insert(struct node* node, string key)
{
    // If the tree is empty, return a new node
    if (node == NULL)
        return newNode(key);

    // Otherwise, recur down the tree
    if (key < node->data)
        node->left = insert(node->left, key);
    else if (key > node->data)
        node->right = insert(node->right, key);

    // Return the (unchanged) node postringer
    return node;
}




// Function to prstring binary tree in 2D
// It does reverse inorder traversal
void prstringBST(struct node* root, int space)
{
    // Base case
    if (root == NULL)
        return;

    // Increase distance between levels
    space += COUNT;

    // Process right child first
    prstringBST(root->right, space);

    // Prstring current node after space
    // count
    cout << endl;
    for (int i = COUNT; i < space; i++)
        cout << " ";
    cout << root->data << "-->" << "\n";

    // Process left child
    prstringBST(root->left, space);
}



/* Given a binary search tree and a key, this function
   deletes the key and returns the new root */
struct node* deleteNode(struct node* root, string k)
{
    // Base case
    if (root == NULL)
        return root;

    // Recursive calls for ancestors of
    // node to be deleted
    if (root->data > k) {
        root->left = deleteNode(root->left, k);
        return root;
    }
    else if (root->data < k) {
        root->right = deleteNode(root->right, k);
        return root;
    }

    // We reach here when root is the node
    // to be deleted.

    // If one of the children is empty
    if (root->left == NULL) {
        struct node* temp = root->right;
        delete root;
        return temp;
    }
    else if (root->right == NULL) {
        struct node* temp = root->left;
        delete root;
        return temp;
    }

    // If both children exist
    else {

        struct node* succParent = root;

        // Find successor
        struct node* succ = root->right;
        while (succ->left != NULL) {
            succParent = succ;
            succ = succ->left;
        }

        // Delete successor.  Since successor
        // is always left child of its parent
        // we can safely make successor's right
        // right child as left of its parent.
        // If there is no succ, then assign
        // succ->right to succParent->right
        if (succParent != root)
            succParent->left = succ->right;
        else
            succParent->right = succ->right;

        // Copy Successor Data to root
        root->data = succ->data;

        // Delete Successor and return root
        delete succ;
        return root;
    }
}


// Recursive function to search a key in a BST
struct node* search(struct node* root, string key)
{
    // Base Cases: root is null or key is present at root
    if (root == NULL || root->data == key)
        return root;

    // Key is greater than root's key
    if (root->data < key)
        return search(root->right, key);

    // Key is smaller than root's key

    return search(root->left, key);

    return root;

}

// Main Code
int main()
{
    struct node* root = NULL;
    // root = insert(root, 50);
    // insert(root, 30);
    // insert(root, 20);
    // insert(root, 40);
    // insert(root, 70);
    // insert(root, 60);
    // insert(root, 80);

    root = insert(root, "Mango");
    insert(root, "Orange");
    insert(root, "Apple");
    insert(root, "Guava");
    insert(root, "Pineapple");
    insert(root, "Strawberry");
    insert(root, "Banana");

    


    prstringBST(root,0);
   
    // root = deleteNode(root, 80);
    // printf("Modified BST tree after deleting Leaf Node:\n");
    // prstringBST(root, 0);
    // printf("\n\nDelete Node with single child: 70\n");
    // root = deleteNode(root, 70);
    // printf("Modified BST tree after deleting single child Node:\n");
    // prstringBST(root, 0);

    // printf("\n\nDelete Node with both child: 50\n");
    // root = deleteNode(root, 30);
    // printf("Modified BST tree after deleting both child Node:\n");
    // prstringBST(root, 0);
  


    //Step1: Fix the search code for Binary search and 
    //step2: modify the code to the following string data  Mango, Orange, Apple,    Guava,        Pineapple,        Strawberry,        Banana


    string key = "Mango";
    if (search(root, key) == NULL)
       cout << key << " Not Found" << endl;
    else
       cout << key << " Found" << endl;

    // Key to be found
    key = "Pear";

    // Searching in a BST
    if (search(root, key) == NULL)
       cout << key << " not found" << endl;
    else
       cout << key << " found" << endl;
    return 0;


}