#include <iostream>

template <typename T> class DList {
    struct Node {
        T data_;
        Node *next_;
        Node *prev_;
        Node(const T &data = T{}, Node *next = nullptr, Node *prev = nullptr) {
            data_ = data;
            next_ = next;
            prev_ = prev;
        }
    };
    Node *front_;
    Node *back_;

  public:
    DList() {
        front_ = nullptr;
        back_ = nullptr;
    }
    void push_front(const T &data);
    void push_back(const T &data);
    void pop_front();
    void pop_back();
    int getData(int data[]) const;
    int getReverseData(int data[]) const;
    ~DList();
};

template <typename T> void DList<T>::push_front(const T &data) {
    
    Node *nn = new Node(data, front_, nullptr);
    if (front_)
	// problem ????
        front_->prev_ = nn;
    else
        back_ = nn;

    front_ = nn;
}

template <typename T> void DList<T>::push_back(const T &data) {
    Node *nn = new Node(data, nullptr, back_);
    if (back_)
        back_->next_ = nn;
    else
        front_ = nn;

    back_ = nn;
}

template <typename T> void DList<T>::pop_front() {
    if (front_) {
        Node *temp = front_;
        front_ = front_->next_;
        if (front_)
            front_->prev_ = nullptr;
        else
            back_ = nullptr;

        delete temp;
    }
}

template <typename T> void DList<T>::pop_back() {
    if (back_) {
        Node *temp = back_;
        back_ = back_->prev_;
        if (back_)
            back_->next_ = nullptr;
		else 
			front_ = nullptr;

        delete temp;
    }
}
template <typename T> int DList<T>::getData(int data[]) const {
    Node *curr = front_;
    int numData = 0;
    while (curr != nullptr) {
        data[numData++] = curr->data_;
        curr = curr->next_;
    }
    return numData;
}
template <typename T> int DList<T>::getReverseData(int data[]) const {
    Node *curr = back_;
    int numData = 0;
    while (curr != nullptr) {
        data[numData++] = curr->data_;
        curr = curr->prev_;
    }
    return numData;
}
template <typename T> DList<T>::~DList() {
    Node *temp;
    while (front_) {
        temp = front_->next_;
        delete front_;
        front_ = temp;
    }
}

