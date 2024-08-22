#include <iostream>
#include <string>

class Stack{
    private:
        struct Node{
            std::string data;
            Node* next;
            Node(const std::string &data = "", Node *next_ptr = nullptr) : data(data), next(next_ptr){};
        };
        Node* front;
        int size;
    public:
        Stack(int size = 5){
            front = nullptr;
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

    void push(const std::string &data){
        if(!isFull()){
            Node* newNode = new Node(data, front);
            front = newNode;
        }
        else{
            std::cout << "Error: Stack is full" << std::endl;
        }

    }

    void pop(){
        if(isEmpty()){
            std::cout << "Error: Stack is empty" << std::endl;
            return;
        }
        Node* temp = front;
        front = front->next;
        delete temp;
    }

    std::string top(){
        if(isEmpty()){
            return "Error: stack is empty";
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

    ~Stack(){
        while(front != nullptr){
            Node* temp = front;
            front = front->next;
            delete temp;
        }
    }
};

int main(){
    Stack s;
    s.push("Apples");
    s.push("Bananas");
    s.push("Grapes");
    s.push("Berries");
    s.push("Oranges");
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