#include <iostream>

using namespace std;

struct Node
{
    int data;
    Node *next;
    Node(const int& data = 0, Node* nextptr = nullptr){
        this->data = data;
        next = nextptr;
    }
};

class Queue
{
    private:
        Node *head;
        Node *tail;
        int size;

    public:
        Queue(int size = 5){
            head = nullptr;
            tail = nullptr;
            this->size = size;
        }

        bool isFull();
        bool isEmpty();
        void enqueue(const int &value);
        void dequeue();
        int top();
        void print();
        ~Queue();
};

bool Queue::isFull(){
    Node *curr = head;
    int count;
    while (curr)
    {
        curr = curr->next;
        count++;
    }
    return count == size + 1;
}

bool Queue::isEmpty(){
    if(head == nullptr)
    {
        return true;
    }

    return false;
}

void Queue::enqueue(const int& value){
    if(!isFull()){
        Node* nn = new Node(value);
        if (isEmpty())
        {
            head = nn;
            tail = nn;
        }
        else{
            tail->next = nn;
            tail = nn;
        }
    }
    else{
        cout << "Queue Full!" << endl;
    }
}

void Queue::dequeue(){
    if(!(isEmpty())){
        Node *tmp = head;
        head = head->next;
        delete tmp;
    }
    else{
        cout << "Queue Underflow" << endl;
    }
}
void Queue::print(){
    Node *curr = head;
    while(curr){
        cout << curr->data << " ";
        curr = curr->next;
    }
    cout << endl;
}

int Queue::top(){
    if(!isEmpty())
        return head->data;

    return 0;
}

Queue::~Queue(){
    Node *curr = head;
    while(curr){
        curr = curr->next;
        dequeue();
    }
}

int main(){
    Queue s;
    s.enqueue(1);
    s.enqueue(2);
    s.enqueue(3);
    s.enqueue(4);
    s.enqueue(5);
    s.print();
    s.dequeue();
    s.dequeue();
    s.print();
    std::cout << "Queue Empty? : ";
    if(s.isEmpty())
        std::cout << "Yes" << std::endl;
    else
        std::cout << "No" << std::endl;

    std::cout << "Queue Full? : ";
    if(s.isFull())
        std::cout << "Yes" << std::endl;
    else
        std::cout << "No" << std::endl;

    std::cout << "Front: " << s.top() << std::endl;

    return 0;
}