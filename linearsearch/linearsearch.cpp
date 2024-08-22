#include <iostream>
using namespace std;

int linearSearch(int arr[], int key){
    int rc = -1;
    for (int i = 0; i < 7 && rc == -1;i++){
        if(arr[i] == key){
            rc = i;
        }
    }

    return rc;
}

int main(){
    const int SIZE = 7;
    int k;

    int array[SIZE] = {8, 3, 12, 5, 1, 9, 4};

    cout << "Array : ";
    for (int i = 0; i < SIZE; i++){
		cout << array[i] << " ";
	}

    cout << "Enter a key";
    cin >> k;

    int index = linearSearch(array, k);
    if(index == -1){
        cout << "tf";
    }
    else{
        cout << "slay at " << index;
    }
}
