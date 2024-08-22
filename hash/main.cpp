#include <vector>
#include <iostream>
#include <string>
using namespace std;
template <typename keyType, typename valueType>
class HashMap {
public:
    HashMap();
    ~HashMap();
    void Insert(const keyType& key, const valueType& value);
    valueType GetValue(const keyType& key);
    void Remove(const keyType& key);
    void GetAllValue();
private:
    int numBuckets;
    vector<vector<pair<keyType, valueType>>> buckets;
};
// Constructor
template <typename keyType, typename valueType>
HashMap<keyType, valueType>::HashMap() {
    numBuckets = 16;
    buckets.resize(numBuckets);
}
// Destructor
template <typename keyType, typename valueType>
HashMap<keyType, valueType>:: ~HashMap() {
    for (auto& bucket : buckets) {
        bucket.clear();
    }
}
// Insert
template <typename keyType, typename valueType>
void HashMap<keyType, valueType>::Insert(const keyType& key, const valueType& value) {
    int hashIndex = hash<keyType>{}(key) % numBuckets; // Compute hash index
    for (auto& pair : buckets[hashIndex]) {
        if (pair.first == key) { // If pair already exists, update to new value
            pair.second = value;
            return;
        }
    }
    buckets[hashIndex].push_back(make_pair(key, value)); // Otherwise, insert the pair into the hash map
}
// GetValue
template <typename keyType, typename valueType>
valueType HashMap<keyType, valueType>::GetValue(const keyType& key) {
    int hashIndex = hash<keyType>{}(key) % numBuckets;
    for (const auto& pair : buckets[hashIndex]) {
        if (pair.first == key) {
            return pair.second;
        }
    }
    return valueType(); // If key is not found, return default constructor outside of the loop
}
// Remove
template <typename keyType, typename valueType>
void HashMap<keyType, valueType>::Remove(const keyType& key) {
    int hashIndex = hash<keyType>{}(key) % numBuckets;
    for (auto it = buckets[hashIndex].begin(); it != buckets[hashIndex].end(); ++it) {
        if (it->first == key) {
            buckets[hashIndex].erase(it); // If pair is found, erase it
            return;
        }
    }
}


// Remove
template <typename keyType, typename valueType>
void HashMap<keyType, valueType>::GetAllValue() {


   //Iterate through the buckets hashindex to display all key,value pair
    
    for (int i = 0; i < numBuckets; ++i) {
        for (const auto& pair : buckets[i]) {
            cout << "Key: " << pair.first << ", Value: " << pair.second << endl;
        }
    }
}


int main() {
 

//Declare a Hash Map
// 
//     1. Add code here to declare
// 

    HashMap<string, string> map;

    //Add the following pairs


    //     2. Add code here to to call function add

    map.Insert("AB", "Calgary");
    map.Insert("BC", "Vancouver");
    map.Insert("ON", "Scarborough");
    map.Insert("MB", "Winnipeg");
//"AB"->"Calgary"
//"BC"->"Vancouver";
//"ON"-> "Scarborough";
//"MB"->"Winnipeg";
  


    //Display the key values for AB, BC, ON,MB



//     3. Add code here    to display each value



    //Display all values in Hash Map
    cout << map.GetValue("AB") ;
    cout << map.GetValue("BC");
    cout << map.GetValue("ON");
    cout << map.GetValue("MB");
    //     4. Add code here to call function display


    cout << "   Add the code to o call function display all" << endl;
    map.GetAllValue();
    return 0;

}
