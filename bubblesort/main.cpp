//George Paul Robert, 117928226

#include <iostream>
using namespace std;


int main(){
    const int SIZE = 7;
    int array[SIZE] = {8, 3, 12, 5, 1, 9, 4};

    cout << "Unsorted Array : ";
    for (int i = 0; i < SIZE; i++){
		cout << array[i] << " ";
	}

    for (int i = 0; i < SIZE - 1; i++){
        for (int j = 0; j < SIZE - i - 1; j++){
            if(array[j+1] < array[j]){
                swap(array[j + 1], array[j]);
            }
        }
    }

    cout << "Sorted Array : ";
    for (int i = 0; i < SIZE; i++){
		cout << array[i] << " ";
	}

}