#include <iostream>
#include <string>
#include <cmath>

template <typename T>
class AVLNode {
public:
    T data;
    int height;
    AVLNode<T> *left;
    AVLNode<T> *right;

    AVLNode(T data) : data(data), height(1), left(nullptr), right(nullptr) {}
};

template <typename T>
class AVLTree {
public:
    AVLTree() : root(nullptr) {}

    void insert(T data);
    void deleteNode(T data);
    AVLNode<T>* search(T data);
    void printTree();

private:
    AVLNode<T>* root;

    int getHeight(AVLNode<T>* node);
    int getBalance(AVLNode<T>* node);
    AVLNode<T>* rightRotate(AVLNode<T>* y);
    AVLNode<T>* leftRotate(AVLNode<T>* x);
    AVLNode<T>* insertNode(AVLNode<T>* node, T data);
    AVLNode<T>* deleteNodeHelper(AVLNode<T>* root, T data);
    void printTreeHelper(AVLNode<T>* root);
    T minValue(AVLNode<T>* node);
};

template <typename T>
int AVLTree<T>::getHeight(AVLNode<T>* node) {
    if (node == nullptr) {
        return 0;
    }
    return node->height;
}

template <typename T>
int AVLTree<T>::getBalance(AVLNode<T>* node) {
    if (node == nullptr) {
        return 0;
    }
    return getHeight(node->left) - getHeight(node->right);
}

template <typename T>
AVLNode<T>* AVLTree<T>::rightRotate(AVLNode<T>* y) {
    AVLNode<T>* x = y->left;
    AVLNode<T>* T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = std::max(getHeight(y->left), getHeight(y->right)) + 1;
    x->height = std::max(getHeight(x->left), getHeight(x->right)) + 1;

    return x;
}

template <typename T>
AVLNode<T>* AVLTree<T>::leftRotate(AVLNode<T>* x) {
    AVLNode<T>* y = x->right;
    AVLNode<T>* T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = std::max(getHeight(x->left), getHeight(x->right)) + 1;
    y->height = std::max(getHeight(y->left), getHeight(y->right)) + 1;

    return y;
}

template <typename T>
AVLNode<T>* AVLTree<T>::insertNode(AVLNode<T>* node, T data) {
    if (node == nullptr) {
        return new AVLNode<T>(data);
    }

    if (data < node->data) {
        node->left = insertNode(node->left, data);
    } else if (data > node->data) {
        node->right = insertNode(node->right, data);
    } else {
        std::cout << "Duplicate data found: " << data << std::endl;
        return node;
    }

    node->height = 1 + std::max(getHeight(node->left), getHeight(node->right));

    int balance = getBalance(node);

    if (balance > 1 && data < node->left->data) {
        return rightRotate(node);
    }

    if (balance < -1 && data > node->right->data) {
        return leftRotate(node);
    }

    if (balance > 1 && data > node->left->data) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    if (balance < -1 && data < node->right->data) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}

template<typename T>
AVLNode<T>* AVLTree<T>::deleteNodeHelper(AVLNode<T>* root, T data) {
    if (root == nullptr) {
        return root;
    }

    if (data < root->data) {
        root->left = deleteNodeHelper(root->left, data);
    } else if (data > root->data) {
        root->right = deleteNodeHelper(root->right, data);
    } else {
        if (root->left == nullptr) {
            AVLNode<T>* temp = root->right;
            delete root;
            return temp;
        } else if (root->right == nullptr) {
            AVLNode<T>* temp = root->left;
            delete root;
            return temp;
        }

        root->data = minValue(root->right);

        root->right = deleteNodeHelper(root->right, root->data);
    }

    root->height = 1 + std::max(getHeight(root->left), getHeight(root->right));

    int balance = getBalance(root);

    if (balance > 1 && getBalance(root->left) >= 0) {
        return rightRotate(root);
    }

    if (balance > 1 && getBalance(root->left) < 0) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    if (balance < -1 && getBalance(root->right) <= 0) {
        return leftRotate(root);
    }

    if (balance < -1 && getBalance(root->right) > 0) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

template <typename T>
void AVLTree<T>::deleteNode(T data) {
    root = deleteNodeHelper(root, data);
}

template<typename T>
T AVLTree<T>::minValue(AVLNode<T>* node) {
    T minValue = node->data;

    while (node->left != nullptr) {
        minValue = node->left->data;
        node = node->left;
    }

    return minValue;
}

template <typename T>
void AVLTree<T>::insert(T data) {
    root = insertNode(root, data);
}

template <typename T>
AVLNode<T>* AVLTree<T>::search(T data) {
    AVLNode<T>* node = root;

    while (node != nullptr) {
        if (data < node->data) {
            node = node->left;
        } else if (data > node->data) {
            node = node->right;
        } else {
            return node;
        }
    }

    return nullptr;
}

template <typename T>
void AVLTree<T>::printTreeHelper(AVLNode<T>* root) {
    if (root == nullptr) {
        return;
    }

    printTreeHelper(root->left);
    std::cout << root->data << " (" << root->height << ") " << std::endl;
    printTreeHelper(root->right);
}

template <typename T>
void AVLTree<T>::printTree() {
    printTreeHelper(root);
}

int main() {
    AVLTree<std::string> stringTree;
    AVLTree<int> intTree;
    AVLTree<float> floatTree;

    std::string stringData[] = {"Milton", "Ajax", "Clarington", "Brock", "Oshawa", "Pickering", "Uxbridge", "Whitby", "Burlington", "Oakville", "Brampton", "Caledon", "Mississauga", "Aurora", "Georgina"};
    int intData[] = {95,301,501,801,90,70,80,25,67,89,11};
    float floatData[] = {84.8,103.5,67.8,90.3,23.5,67.1,44.5,89.2,100.5,300.2};

    for (const auto& data : stringData) {
        stringTree.insert(data);
    }

    std::cout << "String Tree Data:" << std::endl;
    stringTree.printTree();
    std::cout << std::endl;

    stringTree.insert("Stouffville");
    std::cout << "Inserting Stouffville:" << std::endl;
    stringTree.printTree();
    std::cout << std::endl;

    for (int i = 0; i < sizeof(intData) / sizeof(intData[0]); i++) {
        intTree.insert(intData[i]);
    }


    std::cout << "Integer Tree Data:" << std::endl;
    intTree.printTree();
    std::cout << std::endl;

    intTree.insert(506);
    std::cout << "Inserting 506:" << std::endl;
    intTree.printTree();
    std::cout << std::endl;

    for (int i = 0; i < 9; i++) {
        floatTree.insert(floatData[i]);
    }

    std::cout << "Float Tree Data:" << std::endl;
    floatTree.printTree();
    std::cout << std::endl;


    floatTree.insert(88.5);
    std::cout << "Inserting 88.5:" << std::endl;
    floatTree.printTree();
    std::cout << std::endl;


    stringTree.deleteNode("Caledon");
    std::cout << "Deleting Caledon:" << std::endl;
    stringTree.printTree();
    std::cout << std::endl;

    intTree.deleteNode(89);
    std::cout << "Deleting 89:" << std::endl;
    intTree.printTree();
    std::cout << std::endl;

    floatTree.deleteNode(23.5);
    std::cout << "Deleting 23.5:" << std::endl;
    floatTree.printTree();
    std::cout << std::endl;


    AVLNode<std::string>* stringNode = stringTree.search("Whitby");
    if (stringNode != nullptr) {
        std::cout << "Whitby Height: " << stringNode->height << std::endl;
    } else {
        std::cout << "Whitby not found." << std::endl;
    }
    std::cout << std::endl;


    AVLNode<int>* intNode = intTree.search(11);
    if (intNode != nullptr) {
        std::cout << "11 Height: " << intNode->height << std::endl;
    } else {
        std::cout << "11 not found." << std::endl;
    }


    AVLNode<float>* floatNode = floatTree.search(90.3);
    if (floatNode != nullptr) {
        std::cout << "90.3 Height: " << floatNode->height << std::endl;
    } else {
        std::cout << "90.3 not found." << std::endl;
    }

    return 0;
}
