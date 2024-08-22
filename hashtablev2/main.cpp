#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

class HashMap{
public:
    HashMap();
    ~HashMap();
    void insert(const string &key, const vector<string> &value);
    void deleteKey(const string &key);
    void update(const string &key, const string &newKey, const vector<string> &newVal);
    void find(const string &key);
    void enumerate();

private:
    
    struct Node{
        string key;
        vector<string> val;
        Node *next;

        Node(const string& k, const vector<string>& vals){
            val = vals;
            key = k;
            next = nullptr;
        }

    };

    class linkedList{
    public:
            Node *head;
    };
    static const int numBuckets = 5;
    linkedList hashmap[numBuckets];
};

HashMap::HashMap(){
    for (int i = 0; i < numBuckets; i++)
    {
        hashmap[i].head = nullptr;
    }
}

HashMap::~HashMap(){
    for (int i = 0; i < numBuckets;i++){
        hashmap[i].head = nullptr;
    }
}
    void HashMap::update(const string &key, const string &newKey, const vector<string> &newVal){
        int hashIndex = hash<string>{}(key) % numBuckets;
        Node* curr = hashmap[hashIndex].head;
        while(curr && curr->key != key){
            curr = curr->next;
        }
        if(curr){
            curr->key = newKey;
            curr->val = newVal;
        }
    }

void HashMap::insert(const string& key, const vector<string>& value){
    int hashIndex = hash<string>{}(key) % numBuckets;
    Node *nn = new Node(key, value);

    if(!hashmap[hashIndex].head){
        hashmap[hashIndex].head = nn;
    }
    else{
        Node *tmp = hashmap[hashIndex].head;

        while(tmp->next){
            tmp = tmp->next;
        }
        tmp->next = nn;
    }
}

void HashMap::deleteKey(const string& key){
    int hashIndex = hash<string>{}(key) % numBuckets;
    Node *curr = hashmap[hashIndex].head;
    Node *prev = nullptr;

    while(curr && curr->key != key){
        prev = curr;
        curr = curr->next;
    }

    if(curr){
        prev->next = curr->next;
        delete curr;
    }
}

void HashMap::find(const string& key){
    int hashIndex = hash<string>{}(key) % numBuckets;

    Node *curr = hashmap[hashIndex].head;
    while(curr && curr->key != key){
        curr = curr->next;
    }
    if(curr){
        cout << "KEY (Movie Title): yuh " << left << setw(25) << curr->key << " ";
        cout << "DIRECTOR : " << left << setw(15) << curr->val[0] << " ";
        cout << "YEAR : " << left << setw(6) << curr->val[1] << " ";
        cout << "SCORE : " << left << setw(6) << curr->val[2] << " ";
        std::cout << "\n\n";
    }
}

void HashMap::enumerate(){
    int count = 0;
    for (int i = 0; i < numBuckets; i++){
        Node *curr = hashmap[i].head;
        while(curr){
            cout << "KEY (Movie Title): " << left << setw(25) << curr->key << " ";
            cout << "DIRECTOR : " << left << setw(15) << curr->val[0] << " ";
            cout << "YEAR : " << left << setw(6) << curr->val[1] << " ";
            cout << "SCORE : " << left << setw(6) << curr->val[2] << " ";
            curr = curr->next;
            std::cout << "\n";
            count++;
        }
    }
    cout << "Total Record: " << count << endl;
}

int main(){
    HashMap hashMap;

    hashMap.insert("The Lion King", { "Rob Minkoff", "2019", "3.50" });
    hashMap.insert("Beauty and the Beast", { "Bill Condon", "2017", "4.20" });
    hashMap.insert("Toy Story 4", { "Josh Cooley", "2019", "4.50" });
    hashMap.insert("Mission Impossible", { "Brad Bird", "2018", "5.00" });
    hashMap.insert("The Secret Life of Pets", { "Lake Bell", "2016", "3.90" });

    cout << "After insertion : \n";
    hashMap.enumerate();

    //delete
    hashMap.deleteKey("The Secret Life of Pets");
    cout << "After deletion : \n";
    hashMap.enumerate();
    //update
    hashMap.update("Toy Story 4", "Toy Story 3", { "Lee Unkrich", "2010", "5.00" });
    cout << "After updation : \n";
    hashMap.enumerate();
    //find
    cout << "Result of find Mission Impossible : \n";
    hashMap.find("Mission Impossible");
    //enumerate
    cout << "Result of enumerate : \n";
    hashMap.enumerate();

    return 0;

}