#include<iostream>

using namespace std;

struct node
{
    int key;
    node* parent;
    char color;
    node* left;
    node* right;
};
class RBtree
{
    node* root;
    node* q;
public:
    RBtree()
    {
        q = NULL;
        root = NULL;
    }
    void insert();
    void insertfix(node*);
    void leftrotate(node*);
    void rightrotate(node*);
    void del();
    node* successor(node*);
    void delfix(node*);
    void disp();
    void display(node*);
    void search();
    void print_blackNodes(node* p);
    void print_redNodes(node *p);
    node* getRoot() {
        return root;
    }
};
void RBtree::insert()
{
    int z, i = 0;
    cout << "\nEnter key of the node to be inserted: ";
    cin >> z;
    node* p, * q;
    node* t = new node;
    t->key = z;
    t->left = NULL;
    t->right = NULL;
    t->color = 'r';
    p = root;
    q = NULL;
    if (root == NULL)
    {
        root = t;
        t->parent = NULL;
    }
    else
    {
        while (p != NULL)
        {
            q = p;
            if (p->key < t->key)
                p = p->right;
            else
                p = p->left;
        }
        t->parent = q;
        if (q->key < t->key)
            q->right = t;
        else
            q->left = t;
    }
    insertfix(t);
}
void RBtree::insertfix(node* t)
{
    node* u;
    if (root == t)
    {
        t->color = 'b';
        return;
    }
    while (t->parent != NULL && t->parent->color == 'r')
    {
        node* g = t->parent->parent;
        if (g->left == t->parent)
        {
            if (g->right != NULL)
            {
                u = g->right;
                if (u->color == 'r')
                {
                    t->parent->color = 'b';
                    u->color = 'b';
                    g->color = 'r';
                    t = g;
                }
            }
            else
            {
                if (t->parent->right == t)
                {
                    t = t->parent;
                    leftrotate(t);
                }
                t->parent->color = 'b';
                g->color = 'r';
                rightrotate(g);
            }
        }
        else
        {
            if (g->left != NULL)
            {
                u = g->left;
                if (u->color == 'r')
                {
                    t->parent->color = 'b';
                    u->color = 'b';
                    g->color = 'r';
                    t = g;
                }
            }
            else
            {
                if (t->parent->left == t)
                {
                    t = t->parent;
                    rightrotate(t);
                }
                t->parent->color = 'b';
                g->color = 'r';
                leftrotate(g);
            }
        }
        root->color = 'b';
    }
}



void RBtree::leftrotate(node* p)
{
    if (p->right == NULL)
        return;
    else
    {
        node* y = p->right;
        if (y->left != NULL)
        {
            p->right = y->left;
            y->left->parent = p;
        }
        else
            p->right = NULL;
        if (p->parent != NULL)
            y->parent = p->parent;
        if (p->parent == NULL)
            root = y;
        else
        {
            if (p == p->parent->left)
                p->parent->left = y;
            else
                p->parent->right = y;
        }
        y->left = p;
        p->parent = y;
    }
}
void RBtree::rightrotate(node* p)
{
    if (p->left == NULL)
        return;
    else
    {
        node* y = p->left;
        if (y->right != NULL)
        {
            p->left = y->right;
            y->right->parent = p;
        }
        else
            p->left = NULL;
        if (p->parent != NULL)
            y->parent = p->parent;
        if (p->parent == NULL)
            root = y;
        else
        {
            if (p == p->parent->left)
                p->parent->left = y;
            else
                p->parent->right = y;
        }
        y->right = p;
        p->parent = y;
    }
}

node* RBtree::successor(node* p)
{
    node* y = NULL;
    if (p->left != NULL)
    {
        y = p->left;
        while (y->right != NULL)
            y = y->right;
    }
    else
    {
        y = p->right;
        while (y->left != NULL)
            y = y->left;
    }
    return y;
}

void RBtree::disp()
{
    display(root);
}
void RBtree::display(node* p)
{
    if (root == NULL)
    {
        cout << "\nEmpty Tree.";
        return;
    }
    if (p != NULL)
    {
        cout << "\n\t NODE: ";
        cout << "\n Key: " << p->key;
        cout << "\n Colour: ";
        if (p->color == 'b')
            cout << "Black";
        else
            cout << "Red";
        if (p->parent != NULL)
            cout << "\n Parent: " << p->parent->key;
        else
            cout << "\n There is no parent of the node.  ";
        if (p->right != NULL)
            cout << "\n Right Child: " << p->right->key;
        else
            cout << "\n There is no right child of the node.  ";
        if (p->left != NULL)
            cout << "\n Left Child: " << p->left->key;
        else
            cout << "\n There is no left child of the node.  ";
        cout << endl;
        if (p->left)
        {
            cout << "\n\nLeft:\n";
            display(p->left);
        }
        /*else
         cout<<"\nNo Left Child.\n";*/
        if (p->right)
        {
            cout << "\n\nRight:\n";
            display(p->right);
        }
        /*else
         cout<<"\nNo Right Child.\n"*/
    }
}
void RBtree::search(){
    int key;
    cout << "Enter the key to search: ";
    cin >> key;
    node* p = root;
    while (p != NULL) {
        if (p->key == key) {
            cout << "Node found: " << p->key << " " << p->color << endl;
            return;
        } else if (p->key < key) {
            p = p->right;
        } else {
            p = p->left;
        }
    }
    cout << "Node not found" << endl;
}
void RBtree::print_blackNodes(node* p){
    if (p != NULL) {
        print_blackNodes(p->left);
        if (p->color == 'b') {
            cout << "Node: " << p->key << " " << p->color << endl;
        }
        print_blackNodes(p->right);
    }
}

void RBtree::print_redNodes(node* p)
{
    if (p != NULL) {
        print_redNodes(p->left);
        if (p->color == 'r') {
            cout << "Node: " << p->key << " " << p->color << endl;
        }
        print_redNodes(p->right);
    }
}

int main()
{
    int ch, y = 0;
    RBtree obj;
    do
    {
        cout << "\n\t RED BLACK TREE ";
        cout << "\n 1. Insert in the tree ";
        cout << "\n 2. Display the tree ";
        cout << "\n 3. Search a node";
        cout << "\n 4. Print black nodes";
        cout << "\n 5. Print red nodes";
        cout << "\n 6. Exit ";
        cout << "\nEnter Your Choice: ";
        cin >> ch;
        switch (ch)
        {
        case 1: obj.insert();
            cout << "\nNode Inserted.\n";
            break;
        case 2: obj.disp();
            break;
        case 3: obj.search();
            break;
        case 4: obj.print_blackNodes(obj.getRoot());
            break;
        case 5: obj.print_redNodes(obj.getRoot());
            break;
        case 6: y = 1;
            break;
        default: cout << "\nEnter a Valid Choice.";
        }
        cout << endl;

    } while (y != 1);
    return 1;
}

//Add the following nodes 99,88,55,101,120 and print them
//Write a search() function to find a node value 55 and print its color
 //Write print_blackNodes() function  code  to print only the black nodes in a red-black tree
 //Write print_redNodes() function  code  to print only the red nodes in a red-black tree
