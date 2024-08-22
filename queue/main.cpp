#include <iostream>
#include <string>

using namespace std;

const int MAX_SIZE = 5;

class Queue {
private:
    int front; // Front index of the queue
    int rear; // Rear index of the queue
    string arr[MAX_SIZE]; // Array to store queue elements

public:
    Queue() {
        front = -1; // Initialize front index to -1
        rear = -1; // Initialize rear index to -1
    }

    string printisFull() {
        // return (rear == MAX_SIZE - 1); // Check if the queue is full

        if (rear == MAX_SIZE - 1) {
            return "Yes, queue is full";
        }
        else return "No, queue is not full";
    }

    string printisEmpty() {
        //  return (front == -1 && rear == -1); // Check if the queue is empty

        if (front == -1 && rear == -1) {
            return "Yes, queue is empty";
        }
        else return "No, queue is not empty";
    }

    bool isFull() {
        return (rear == MAX_SIZE - 1); // Check if the queue is full

    }

    bool isEmpty() {
        return (front == -1 && rear == -1); // Check if the queue is empty

    }



    void enqueue(string x) {
        if (isFull()) {
            cout << "Error: Queue is full" << endl; // Display error message if queue is full
        }
        if (isEmpty()){
            front = 0;
        }
        rear++;
        arr[rear] = x;
        // If the queue is empty, update front to 0
         // If the queue is empty, update rear to 0
       
          // Increment rear index
       
         // Insert the element at the rear index
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Error: Queue is empty" << endl; // Display error message if queue is empty
            return;
        }
        else if (front == rear){
            front = -1;
            rear = -1;
        }
        else{
            front++;
        }

          // If the queue has only one element, update front to -1
           // If the queue has only one element, update rear to -1
    
            // Increment front index
       
    }
    string frontData() {
        if (isEmpty()) {
            cout << "Error: Queue is empty" << endl; // Display error message if queue is empty
            return NULL;
        }
        else{
            return arr[front];
        }
        // Return the element at the front of the queue
    }

    void display() {
        if (isEmpty()) {
            cout << "Error: Queue is empty" << endl; // Display error message if queue is empty
            return;
        }
        cout << "Queue elements are: ";
        for (int i = front; i <= rear; i++) {
            cout << arr[i] << " ->"; // Display all elements in the queue
        }
        cout << endl;
    }
};

int main() {
    cout << "Initialize a String Queue." << endl;
    cout<< "_________________________________________" << endl;
    Queue q;
    cout << "\nIs the Queue is empty? " << q.printisEmpty() << endl;

    cout << "_________________________________________" << endl;
    cout << "\nInsert some elements into the queue:" << endl;
    q.enqueue("apples");
    q.enqueue("pears");
    q.enqueue("oranges");
    q.enqueue("grapes");
    q.enqueue("bananas");
    cout << "_________________________________________" << endl;
    cout << "\nIs the Queue full?   " << q.printisFull() << endl;
    cout << "_________________________________________" << endl;
    cout << "\nIs the Queue is empty? " << q.printisEmpty() << endl;
    cout << "_________________________________________" << endl;
    q.display();
    cout << "_________________________________________" << endl;
    cout << "\nFront element is " << q.frontData() << endl;
    cout << "_________________________________________" << endl;
    cout << "\nRemove two elements from the Queue" << endl;
    cout << "_________________________________________" << endl;
    q.dequeue();
    q.dequeue();
    cout << "_________________________________________" << endl;
    q.display();
    cout << "_________________________________________" << endl;
    cout << "\nFront element is " << q.frontData() << endl;
    cout << "________________END OF QUEUES_________________________" << endl;
    return 0;
}