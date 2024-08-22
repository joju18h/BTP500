//George Paul Robert
#include "lab3.h"
#include<iostream>
int main() {
    {
        DList<int> linkedList;
        linkedList.push_front(1);
        int data[1];
        int n= linkedList.getData(data);
        std::cout << "DList: push_front() starting with empty list: ";
        for (int i = 0; i < n; i++) {
            std::cout << data[i] << " ";
        }
        std::cout << std::endl;
    }
    {
        DList<int> linkedList;
        linkedList.push_back(2);
        int data[1];
        int n = linkedList.getData(data);
        std::cout << "DList: push_back() starting with empty list: ";
        for (int i = 0; i < n; i++) {
            std::cout << data[i] << " ";
        }
        std::cout << std::endl;
    }


    {
        DList<int> linkedList;
        linkedList.push_front(3);
        linkedList.push_front(1);
        linkedList.push_front(2);
        linkedList.push_back(5);
        linkedList.push_back(7);
        linkedList.push_back(6);
        int data[6];
        int n = linkedList.getData(data);
        std::cout << "DList: push_front() 3 times then push_back() 3 times: ";
        for (int i = 0; i < n; i++) {
            std::cout << data[i] << " ";
        }
        std::cout << std::endl;
    }
    {
        DList<int> linkedList;
        linkedList.push_back(3);
        linkedList.push_back(2);
        linkedList.push_back(4);
        linkedList.push_front(6);
        linkedList.push_front(9);
        linkedList.push_front(7);
        int data[6];
        int numData = linkedList.getData(data);
        std::cout << "DList: push_back() 3 times then push_front() 3 times: ";
        for (int i = 0; i < numData; i++) {
            std::cout << data[i] << " ";
        }
        std::cout << std::endl;
    }

    {

        DList<int> linkedList;
         linkedList.pop_front();
         linkedList.pop_back();
        int data[2];
        int n = linkedList.getData(data);
        std::cout << "DList: pop_front() and pop_back() on empty linkedList:";
        for (int i = 0; i < n; i++) {
            std::cout << data[i] << " ";
        }
        std::cout << std::endl;
       
    }
    {

        DList<int> linkedList;
        linkedList.push_front(4);
        linkedList.push_front(6);
        linkedList.push_front(5);
        linkedList.pop_front();

        int data[6];
        int n = linkedList.getData(data);
        std::cout << "DList: pop_front() on non-empty linkedList: ";
        for (int i = 0; i < n; i++) {
            std::cout << data[i] << " ";
        }
        std::cout << std::endl;
        
    }
    {
        DList<int> linkedList;
        linkedList.push_front(8);
        linkedList.push_front(3);
        linkedList.push_front(2);
        linkedList.pop_back();

        int data[6];
        int n = linkedList.getData(data);
        std::cout << "DList: pop_back() on non-empty linkedList: ";
        for (int i = 0; i < n; i++) {
            std::cout << data[i] << " ";
        }
        std::cout << std::endl;
    }
    {
        DList<int> linkedList;
        linkedList.push_front(3);
        linkedList.push_front(5);
        linkedList.push_front(1);
        linkedList.push_front(2);
        linkedList.push_front(9);
        linkedList.push_front(6);
        linkedList.pop_front();
        linkedList.pop_back();
        linkedList.pop_front();
        linkedList.pop_back();
        int data[10];
        int numData = linkedList.getData(data);
        std::cout << "DList: alternating pop_front()/pop_back() on non-empty linkedList: ";
        for (int i = 0; i < numData; i++) {
            std::cout << data[i] << " ";
        }
        std::cout << std::endl;
    }
    {
        DList<int> linkedList;
        linkedList.pop_front();
        linkedList.push_front(2);
        linkedList.pop_front();
        linkedList.push_front(4);
        linkedList.pop_front();
        linkedList.push_front(9);


        int data[10];
        int n = linkedList.getData(data);
        std::cout << "DList: calling push functions after pop functions: ";
        for (int i = 0; i < n; i++) {
            std::cout << data[i] << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}

