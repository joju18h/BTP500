//George Paul Robert, 117928226


#include <iostream>
using namespace std;

int main(){
	const int SIZE = 7;
    int array[SIZE] = {8, 3, 12, 5, 1, 9, 4};

    cout << "Unsorted array : ";
    for (int i = 0; i < SIZE; i++){
		cout << array[i] << " ";
	}

	int i,j;
	int curr;
	for (i= 1; i < SIZE; i++){
		curr = array[i];
		for (j = i;j > 0 && array[j-1] > curr;j--){
			array[j] = array[j - 1];
		}
		array[j] = curr;
	}
    cout << "Sorted Array: ";
    for (int i = 0; i < SIZE; i++){
		cout << array[i] << " ";
	}
	return 0;
}