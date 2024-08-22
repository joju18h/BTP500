#include <iostream>
#include <string>

using namespace std;

template<typename T>
struct node {
    T key;
    node<T>* parent;
    char color;
    node<T>* left;
    node<T>* right;
};

template<typename T>
class RBtree {
    node<T>* root;

    void insertfix(node<T>*);
    void delfix(node<T>*);
    node<T>* successor(node<T>*);
    void leftrotate(node<T>*);
    void rightrotate(node<T>*);
    void transplant(node<T>*, node<T>*);
    node<T>* minimum(node<T>*);
    void display(node<T>*, int space = 0);
    int height(node<T> *node); 
    T getParentData(node<T> *node);

public:
    RBtree() : root(nullptr) {}

    void insert(T);
    void del(T);
    void disp();
    void search(T key);
    node<T>* getRoot() { return root; }
    void searchAndPrintInfo(T key);
};

template<typename T>
void RBtree<T>::leftrotate(node<T>* x) {
    node<T>* y = x->right;
    x->right = y->left;
    if (y->left != nullptr)
        y->left->parent = x;
    y->parent = x->parent;
    if (x->parent == nullptr)
        root = y;
    else if (x == x->parent->left)
        x->parent->left = y;
    else
        x->parent->right = y;
    y->left = x;
    x->parent = y;
}

template<typename T>
void RBtree<T>::rightrotate(node<T>* y) {
    node<T>* x = y->left;
    y->left = x->right;
    if (x->right != nullptr)
        x->right->parent = y;
    x->parent = y->parent;
    if (y->parent == nullptr)
        root = x;
    else if (y == y->parent->right)
        y->parent->right = x;
    else
        y->parent->left = x;
    x->right = y;
    y->parent = x;
}

template<typename T>
void RBtree<T>::insertfix(node<T>* z) {
    while (z != root && z->parent != nullptr && z->parent->color == 'r') {
        if (z->parent == z->parent->parent->left) {
            node<T>* y = z->parent->parent->right;
            if (y != nullptr && y->color == 'r') {
                z->parent->color = 'b';
                y->color = 'b';
                z->parent->parent->color = 'r';
                z = z->parent->parent;
            } else {
                if (z == z->parent->right) {
                    z = z->parent;
                    leftrotate(z);
                }
                z->parent->color = 'b';
                z->parent->parent->color = 'r';
                rightrotate(z->parent->parent);
            }
        } else {
            node<T>* y = z->parent->parent->left;
            if (y != nullptr && y->color == 'r') {
                z->parent->color = 'b';
                y->color = 'b';
                z->parent->parent->color = 'r';
                z = z->parent->parent;
            } else {
                if (z == z->parent->left) {
                    z = z->parent;
                    rightrotate(z);
                }
                z->parent->color = 'b';
                z->parent->parent->color = 'r';
                leftrotate(z->parent->parent);
            }
        }
    }
    root->color = 'b';
}

template<typename T>
void RBtree<T>::insert(T z) {
    node<T>* t = new node<T>;
    t->key = z;
    t->left = nullptr;
    t->right = nullptr;
    t->color = 'r';

    node<T>* y = nullptr;
    node<T>* x = root;

    while (x != nullptr) {
        y = x;
        if (t->key < x->key)
            x = x->left;
        else
            x = x->right;
    }

    t->parent = y;
    if (y == nullptr)
        root = t;
    else if (t->key < y->key)
        y->left = t;
    else
        y->right = t;

    insertfix(t);
}

template<typename T>
void RBtree<T>::transplant(node<T>* u, node<T>* v) {
    if (u->parent == nullptr)
        root = v;
    else if (u == u->parent->left)
        u->parent->left = v;
    else
        u->parent->right = v;
    if (v != nullptr)
        v->parent = u->parent;
}

template<typename T>
node<T>* RBtree<T>::minimum(node<T>* x) {
    while (x->left != nullptr)
        x = x->left;
    return x;
}

template<typename T>
node<T>* RBtree<T>::successor(node<T>* x) {
       if (x->right != nullptr)
        return minimum(x->right);
    node<T>* y = x->parent;
    while (y != nullptr && x == y->right) {
        x = y;
        y = y->parent;
    }
    return y;
}

template<typename T>
void RBtree<T>::delfix(node<T>* x) {
    while (x != root && (x == nullptr || x->color == 'b')) {
        if (x == x->parent->left) {
            node<T>* w = x->parent->right;
            if (w->color == 'r') {
                w->color = 'b';
                x->parent->color = 'r';
                leftrotate(x->parent);
                w = x->parent->right;
            }
            if ((w->left == nullptr || w->left->color == 'b') && (w->right == nullptr || w->right->color == 'b')) {
                w->color = 'r';
                x = x->parent;
            } else {
                if (w->right == nullptr || w->right->color == 'b') {
                    w->left->color = 'b';
                    w->color = 'r';
                    rightrotate(w);
                    w = x->parent->right;
                }
                w->color = x->parent->color;
                x->parent->color = 'b';
                w->right->color = 'b';
                leftrotate(x->parent);
                x = root;
            }
        } else {
            node<T>* w = x->parent->left;
            if (w->color == 'r') {
                w->color = 'b';
                x->parent->color = 'r';
                rightrotate(x->parent);
                w = x->parent->left;
            }
            if ((w->right == nullptr || w->right->color == 'b') && (w->left == nullptr || w->left->color == 'b')) {
                w->color = 'r';
                x = x->parent;
            } else {
                if (w->left == nullptr || w->left->color == 'b') {
                    w->right->color = 'b';
                    w->color = 'r';
                    leftrotate(w);
                    w = x->parent->left;
                }
                w->color = x->parent->color;
                x->parent->color = 'b';
                w->left->color = 'b';
                rightrotate(x->parent);
                x = root;
            }
        }
    }
    if (x != nullptr)
        x->color = 'b';
}

template<typename T>
void RBtree<T>::del(T z) {
    node<T>* x;
    node<T>* y;
    node<T>* z_node = root;

    while (z_node != nullptr) {
        if (z_node->key == z)
            break;
        if (z_node->key < z)
            z_node = z_node->right;
        else
            z_node = z_node->left;
    }

    if (z_node == nullptr) {
        cout << "Node not found" << endl;
        return;
    }

    if (z_node->left == nullptr || z_node->right == nullptr)
        y = z_node;
    else
        y = successor(z_node);

    if (y->left != nullptr)
        x = y->left;
    else
        x = y->right;

    if (x != nullptr)
        x->parent = y->parent;

    if (y->parent == nullptr)
        root = x;
    else if (y == y->parent->left)
        y->parent->left = x;
    else
        y->parent->right = x;

    if (y != z_node)
        z_node->key = y->key;

    if (y->color == 'b')
        delfix(x);

    delete y;
}

template<typename T>
void RBtree<T>::disp() {
    display(root, 0);
}

template<typename T>
void RBtree<T>::display(node<T>* root, int space) {
    if (root == nullptr)
        return;
    
    space += 5;
    display(root->right, space);

    std::cout << std::endl;
    for (int i = 5; i < space; i++)
        std::cout << " ";

    std::cout << root->key << "(" << ((root->color == 'r') ? "RED" : "BLACK") << ")" << std::endl;

    display(root->left, space);
}


template<typename T>
void RBtree<T>::search(T key) {
    node<T>* p = root;
    while (p != nullptr) {
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

template<typename T>
int RBtree<T>::height(node<T>* node) {
    if (node == nullptr)
        return 0;
    else {
        int left_height = height(node->left);
        int right_height = height(node->right);

        return 1 + max(left_height, right_height);
    }
}


template<typename T>
T RBtree<T>::getParentData(node<T>* node) {
    if (node != nullptr && node->parent != nullptr)
        return node->parent->key;
    else
        return T();
}

template<typename T>
void RBtree<T>::searchAndPrintInfo(T key) {
    node<T>* p = root;
    int height = 0;

    while (p != nullptr) {
        if (p->key == key) {
            cout << "Node found: " << p->key << ", Height: " << height << ", Parent Data: " << getParentData(p) << endl;
            return;
        } else if (p->key < key) {
            p = p->right;
        } else {
            p = p->left;
        }
        height++;
    }

    cout << "Node not found" << endl;
}


int main() {
    RBtree<string> stringTree;
    RBtree<int> intTree;
    RBtree<double> doubleTree;

    string strings[] = { "Milton", "Ajax", "Clarington", "Brock", "Oshawa", "Pickering", "Uxbridge", "Whitby", "Burlington", "Oakville", "Brampton", "Caledon", "Mississauga", "Aurora", "Georgina" };
    int integers[] = { 95, 301, 501, 801, 90, 70, 80, 25, 67, 89, 11 };
    double decimals[] = { 84.8, 103.5, 67.8, 90.3, 23.5,67.1, 44.5, 89.2, 100.5, 300.2 };

    cout << "inserting elements into the trees\n";
    for (const auto &str : strings)
        stringTree.insert(str);
    for (const auto& num : integers)
        intTree.insert(num);
    for (const auto& dec : decimals)
        doubleTree.insert(dec);

    cout << "String Data:" << endl;
    stringTree.disp();
    cout << endl << endl;

    cout << "Integer Data:" << endl;
    intTree.disp();
    cout << endl << endl;

    cout << "Decimal Data:" << endl;
    doubleTree.disp();
    cout << endl << endl;

    cout << "inserting new elements into the trees\n";
    stringTree.insert("Stouffville");
    intTree.insert(506);
    doubleTree.insert(88.5);

    cout << "After new insertion:" << endl;
    cout << "with String Data:" << endl;
    stringTree.disp();
    cout << endl << endl;

    cout << "with Integer Data:" << endl;
    intTree.disp();
    cout << endl << endl;

    cout << "with Decimal Data:" << endl;
    doubleTree.disp();
    cout << endl << endl;

    stringTree.del("Caledon");
    intTree.del(89);
    doubleTree.del(23.5);

    cout << "After deletion:" << endl;
    cout << "with String Data:" << endl;
    stringTree.disp();

    cout << endl << endl;

    cout << "with Integer Data:" << endl;
    intTree.disp();

    cout << endl << endl;

    cout << "with Decimal Data:" << endl;
    doubleTree.disp();

    cout << endl << endl;

    stringTree.searchAndPrintInfo("Whitby");
    intTree.searchAndPrintInfo(11);
    doubleTree.searchAndPrintInfo(90.3);


    return 0;
}


