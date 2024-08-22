//George Paul Robert
#include <iostream>
#include <stack>

using namespace std;

template <typename T>
class BinarySearchTree {
    struct Node{
        T data;
        Node* left;
        Node* right;

        Node(const T& data, Node* left = nullptr, Node* right = nullptr) : data(data), left(left), right(right) {}
    };
    Node* root;

    public:

    BinarySearchTree() : root(nullptr) {}
    void insert(const T& newdata){
        root = insert(root, newdata);
    }
    Node* insert(Node* x,const T &newdata);
    void getPreOrder();
    void getInOrder();
    void getPostOrder();
};

// template <typename T>
// void BinarySearchTree<T>::insert(const T& newdata){
//     Node *newNode = new Node(newdata);

//     if(root == nullptr){
//         root = newNode;
//         return;
//     }
//     else{
//         Node* curr = root;
//         bool inserted = false;
//         while(!inserted){
//             if(newdata < curr->data){
//                 if(curr->left == nullptr){
//                     curr->left = newNode;
//                     inserted = true;
//                 }
//                 else{
//                     curr = curr->left;
//                 }
//             }
//             else{
//                 if(curr->right == nullptr){
//                     curr->right = newNode;
//                     inserted = true;
//                 }
//                 else{
//                     curr = curr->right;
//                 }
//             }
//         }
//     }
// }

template <typename T>
typename BinarySearchTree<T>::Node* BinarySearchTree<T>::insert(Node* x,const T &newdata){
    if(x == nullptr){
        x = new Node(newdata);
    }
    else if(newdata < x->data){
        x->left = insert(x->left, newdata);
    }
    else{
        x->right = insert(x->right, newdata);
    }
    return x;
}

template <typename T>
void BinarySearchTree<T>::getPreOrder(){
    stack<Node*> s;
    Node* curr = root;
    while(curr != nullptr || !s.empty()){
        while(curr != nullptr){
            cout << curr->data << " ";
            s.push(curr);
            curr = curr->left;
        }
        curr = s.top();
        s.pop();
        curr = curr->right;
    }
}

template <typename T>
void BinarySearchTree<T>::getInOrder(){
    stack<Node *> s;
    Node* curr = root;

    while (curr != nullptr || !s.empty())
    {
        while (curr != nullptr)
        {
            s.push(curr);
            curr = curr->left;
        }
        curr = s.top();
        s.pop();
        cout << curr->data << " ";
        curr = curr->right;
    }
}

template <typename T>
void BinarySearchTree<T>::getPostOrder(){
    stack<Node *> s;
    Node *curr = root;
    Node *prev = nullptr;

    while(curr != nullptr || !s.empty()){
        while(curr != nullptr){
            s.push(curr);
            curr = curr->left;
        }
        Node* top = s.top();
        if(top -> right == nullptr || top -> right == prev){
            cout << top->data << " ";
            s.pop();
            prev = top;
        }
        else{
            curr = top->right;
        }
    }
}

int main() {
    
    BinarySearchTree<string> locations;
    locations.insert("Milton");
    locations.insert("Ajax");
    locations.insert("Clarington");
    locations.insert("Brock");
    locations.insert("Oshawa");
    locations.insert("Pickering");
    locations.insert("Uxbridge");
    locations.insert("Whitby");
    locations.insert("Burlington");
    locations.insert("Oakville");
    locations.insert("Brampton");
    locations.insert("Caledon");
    locations.insert("Mississauga");
    locations.insert("Aurora");
    locations.insert("Georgina");

    BinarySearchTree<int> numbers;
    numbers.insert(95);
    numbers.insert(301);
    numbers.insert(501);
    numbers.insert(801);
    numbers.insert(90);
    numbers.insert(70);
    numbers.insert(80);
    numbers.insert(25);
    numbers.insert(67);
    numbers.insert(89);
    numbers.insert(11);

    BinarySearchTree<float> decimals;
    decimals.insert(84.8);
    decimals.insert(103.5);
    decimals.insert(67.8);
    decimals.insert(90.3);
    decimals.insert(23.5);
    decimals.insert(67.1);
    decimals.insert(44.5);
    decimals.insert(89.2);
    decimals.insert(100.5);
    decimals.insert(300.2);

    cout << "Pre order for strings: ";
    locations.getPreOrder();
    cout << endl;
    cout << endl;
    cout << "Pre order for int: ";
    numbers.getPreOrder();
    cout << endl;
    cout<< endl;
    cout << "Pre order traversal for decimals: ";
    decimals.getPreOrder();
    cout << endl;
    cout << endl;

    cout << endl;

    cout << "In order traversal strings: ";
    locations.getInOrder();
    cout << endl;
    cout << endl;
    cout << "In order traversal int: ";
    numbers.getInOrder();
    cout << endl;
    cout << endl;
    cout << "In order travrsal decimals: ";
    decimals.getInOrder();
    cout << endl;
    cout << endl;

    cout << endl;

    cout << "Post order traversal strings: ";
    locations.getPostOrder();
    cout << endl;
    cout << endl;
    cout << "Post order traversal int: ";
    numbers.getPostOrder();
    cout << endl;
    cout << endl;
    cout << "Post order traversal decimals: ";
    decimals.getPostOrder();
    cout << endl;
    cout << endl;
    return 0;
}
