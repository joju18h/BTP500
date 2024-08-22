#include <iostream>

using namespace std;

struct node
{
    int data;
    node* next;
};

class linked_list
{
private:
    node* head, * tail;
public:
    linked_list()
    {
        head = NULL;
        tail = NULL;
    }

    void add_node(int n)
    {
        node* tmp = new node;
        tmp->data = n;
        tmp->next = NULL;

        cout << "Add the code to add the new node tmp" << endl;

        if(head == NULL){
            head = tmp;
            tail = tmp;
        }
        else{
            tail->next = tmp;
            tail = tail->next;
        }
    }

    node* gethead()
    {
        return head;
    }
    node* gettail()
    {
        return tail;
    }
    static void displayHeadNode(node* head)
    {
        if (head == NULL)
        {
            cout << "NULL" << endl;
        }
        else
        {
            cout << endl<< "Head node data is :" << head->data;
        }
    }
        static void displayTailNode(node * tail)
        {
            if (tail == NULL)
            {
                cout << "NULL" << endl;
            }
            else
            {
                cout << endl<<"Tail node data is :" << tail->data;
            }
        }

    static void display(node* head)
    {
        if (head == NULL)
        {
            cout << "NULL" << endl;
        }
        else
        {
            cout << head->data << " -> ";
            display(head->next);
        }
        cout << endl;
    }

    void front(int n)
    {
        node* tmp = new node;
        tmp->data = n;
        tmp->next = head;
        head = tmp;
    }

    void after(node* a, int value)
    {
        cout << "Add code to add a node after the node pointer given" << endl;

        node *newNode = new node;
        newNode->data = value;

        node *tmp = a;
        newNode->next = a->next;

        a->next = newNode;
    }

    void del(node* del)
    {
        cout << "Add code to delete the node with the node pointer given" << endl;


    }
};

int main()
{
    linked_list a;
    int arr[3] = { 40,60,80 };
    cout << "Sample array to add to the linked_ list is : ";
    for (int j = 0; j < 3; j++) {
        cout << "arr[" << j << "]= " << arr[j]<<"  ";
    }
    
     
    cout << endl<<endl<<"Add the array to the empty linked_list [] with the data :  ";
    for (int j = 0; j < 3; j++) {
        cout <<  arr[j] << "  ";
        cout << "add code for this function" << endl;
        a.add_node(arr[j]);//add code for this function

    }

    cout <<endl<<endl<< "Display the data from the linked_list" << endl;
       
    linked_list::display(a.gethead());
 

    cout << endl << endl << "Display the head node";
    linked_list::displayHeadNode(a.gethead());



    cout << endl << endl << "Display the tail node";
    linked_list::displayTailNode(a.gettail());


    cout << endl << endl << "Add a node 100 after 60";
    a.after(a.gethead()->next, 100);

       cout << endl << endl << "Display the new data added to the linked_list" << endl;

    linked_list::display(a.gethead());


    cout << endl << endl << "Delete the node 100 from the linked_list" << endl;
    cout << "add code for this function" << endl;
   // a.del(a.gethead()->next);//add code for this function

    cout << endl << endl << "Display the data deleted from the linked_list" << endl;

    linked_list::display(a.gethead());


    //a.after(a.gethead()->next->next->next, 20);
    
    return 0;
}




