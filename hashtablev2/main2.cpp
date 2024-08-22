#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

struct Node{
    int key;
    vector<string> values;
    Node *next;
    Node(const int& Key, const vector<string>& values){
        key = Key;
        this->values = values;
        next = nullptr;
    }
};

class HashMap{
    private:
    class linkedList{
    public:
        Node *head;
    };
    const int static numbuckets = 5;
    linkedList hashmap[numbuckets];

    public:
        HashMap();
        ~HashMap();
        void insert(const int &key, const vector<string> &values);
        void deleteItem(const int &key);
        void update(const string &key, const string &newKey, const vector<string> &newVal);
        void find(const string &key);
        void enumerate();
};

HashMap::HashMap(){
    for (int i = 0; i < numbuckets; i++){
        hashmap[i].head = nullptr;
    }
}
HashMap::~HashMap(){
    for (int i = 0; i < numbuckets;i++){
        hashmap[i].head = nullptr;
    }
}

void insert(const int &key, const vector<string> &values){
    
}
