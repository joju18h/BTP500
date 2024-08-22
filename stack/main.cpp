#include <iostream>

using namespace std;

struct Node
{
    int data;
    Node *prev;
    Node *next;
    Node(const int& data = 0, Node* nextptr = nullptr, Node* prevptr = nullptr){
        this->data = data;
        prev = prevptr;
        next = nextptr;
    }
};

class Stack
{
    private:
        Node *head;
        int size;
    
    public:
        Stack(int size = 5){
            head = nullptr;
            this->size = size;
        }

        bool isFull();
        bool isEmpty();
        void push(const int &value);
        void pop();
        int top();
        void print();
        ~Stack();
};

bool Stack::isFull(){
    Node *curr = head;
    int count;
    while (curr)
    {
        curr = curr->next;
        count++;
    }
    return size + 1 == count;
}

bool Stack::isEmpty(){
    if(head == nullptr)
    {
        return true;
    }

    return false;
}

void Stack::push(const int& value){
    if(!(isFull())){
        Node *nn = new Node (value);
        nn->next = head;
        head = nn;
    }
    else{
        cout << "Stack is full!" << endl;
    }
}

void Stack::pop(){
    if(!(isEmpty())){
        Node *tmp = head;
        head = head->next;
        delete tmp;
    }
    else{
        cout << "Stack Underflow" << endl;
    }
}
void Stack::print(){
    Node *curr = head;
    while(curr){
        cout << curr->data << endl;
        curr = curr->next;
    }
}

int Stack::top(){
    if(!isEmpty())
        return head->data;

    return 0;
}

Stack::~Stack(){
    Node *curr = head;
    while(curr){
        curr = curr->next;
        pop();
    }
}

int main(){
    Stack s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    s.print();
    s.pop();
    s.pop();
    s.print();
    std::cout << "Stack Empty? : ";
    if(s.isEmpty())
        std::cout << "Yes" << std::endl;
    else
        std::cout << "No" << std::endl;

    std::cout << "Stack Full? : ";
    if(s.isFull())
        std::cout << "Yes" << std::endl;
    else
        std::cout << "No" << std::endl;

    std::cout << "Front: " << s.top() << std::endl;

    return 0;
}