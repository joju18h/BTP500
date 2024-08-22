//George Paul Robert, 117928226

#include <iostream>
using namespace std;

int findPivot(int arr[], int start, int end){
    int pivot = arr[end];
    int i = start - 1;

    for (int j = start; j < end; j++){
        if(arr[j] < pivot){
            i++;
            swap(arr[j], arr[i]);
        }
    }
    swap(arr[i + 1], arr[end]);

    return i + 1;
}

void quickSort(int arr[], int start, int end){
    if(start < end){
        int pivot = findPivot(arr, start, end);
        quickSort(arr, start, pivot - 1);
        quickSort(arr, pivot + 1, end);
    }
}

int main(){
    const int SIZE = 7;
    int array[SIZE] = {8, 3, 12, 5, 1, 9, 4};

    cout << "Unsorted Array : ";
    for (int i = 0; i < SIZE; i++){
		cout << array[i] << " ";
	}

    quickSort(array, 0, SIZE - 1);

    cout << "Sorted Array: ";
    for (int i = 0; i < SIZE; i++){
		cout << array[i] << " ";
	}
}