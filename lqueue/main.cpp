#include <iostream>
#include <string>

class Queue{
    private:
        struct Node{
            std::string data;
            Node* next;
            Node(const std::string &data = "", Node *next_ptr = nullptr) : data(data), next(next_ptr){};
        };
        Node* front;
        Node* rear;
        int size;
    public:
        Queue(int size = 5){
            front = nullptr;
            rear = nullptr;
            size = size;
        }

    bool isFull(){
        int n = 0;
        Node* temp = front;
        while(temp != nullptr){
            n++;
            temp = temp->next;
        }
        return n == size - 1;
    }

    bool isEmpty(){
        return front == nullptr;
    }

    void enqueue(const std::string &data){
        if(isFull()){
            std::cout << "Error: Queue is full" << std::endl;
            return;
        }
        Node* newNode = new Node(data);
        if(isEmpty()){
            front = newNode;
            rear = newNode;
        }
        else{
            rear->next = newNode;
            rear = newNode;
        }
    }

    void dequeue(){
        if(isEmpty()){
            std::cout << "Error: Queue is empty" << std::endl;
            return;
        }
        Node* temp = front;
        front = front->next;
        delete temp;
    }

    std::string getFront(){
        if(isEmpty()){
            return "Error: Queue is empty";
        }
        return front->data;
    }

    void print(){
        Node* temp = front;
        while(temp != nullptr){
            std::cout << temp->data << " ";
            temp = temp->next;
        }
        std::cout << std::endl;
    }

    ~Queue(){
        while(front != nullptr){
            Node* temp = front;
            front = front->next;
            delete temp;
        }
    }
};

int main(){
    Queue q;
    q.enqueue("Apples");
    q.enqueue("Bananas");
    q.enqueue("Grapes");
    q.enqueue("Berries");
    q.enqueue("Oranges");
    q.print();
    q.dequeue();
    q.dequeue();
    q.print();
    std::cout << "Queue Empty? : ";
    if(q.isEmpty())
        std::cout << "Yes" << std::endl;
    else
        std::cout << "No" << std::endl;

    std::cout << "Queue Full? : ";
    if(q.isFull())
        std::cout << "Yes" << std::endl;
    else
        std::cout << "No" << std::endl;
    std::cout << "Front: " << q.getFront() << std::endl;

    return 0;
}