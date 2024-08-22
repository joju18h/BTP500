#include <iostream>
#include <chrono>
#include <ctime>
#include <vector>
#include <iomanip>
using namespace std;

int operation_count = 0;

void mergesort(int arr[], int size);
void mergesortRecursive(int arr[], int l, int r);
void merge(int arr[], int left, int middle, int right);

int main()
{
    int arr[] = {5, 4, 3, 2, 1};
    int size = sizeof(arr) / sizeof(arr[0]);

    auto start = std::chrono::system_clock::now();
    mergesort(arr, size);
    auto end = std::chrono::system_clock::now();

    std::cout << "Sorted array of 5 values: ";
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << "Operation count: " << operation_count << "\n";
    operation_count = 0;

    std::chrono::duration<double> elapsed_seconds = end - start;
    std::time_t end_time = std::chrono::system_clock::to_time_t(end);

    std::cout << "finished computation at " << std::ctime(&end_time)
              << "elapsed time: " << std::fixed << std::setprecision(6) << elapsed_seconds.count() << "s"
              << std::endl;

    int arr2[] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    size = sizeof(arr2) / sizeof(arr2[0]);
    start = std::chrono::system_clock::now();
    mergesort(arr2, size);
    end = std::chrono::system_clock::now();

    std::cout << "Sorted array of 10 values: ";
    for (int i = 0; i < size; i++)
    {
        cout << arr2[i] << " ";
    }
    cout << "Operation count: " << operation_count << "\n";
    operation_count = 0;

    elapsed_seconds = end - start;
    end_time = std::chrono::system_clock::to_time_t(end);

    std::cout << "finished computation at " << std::ctime(&end_time)
              << "elapsed time: " << std::fixed << std::setprecision(6) << elapsed_seconds.count() << "s"
              << std::endl;

    int arr3[] = {20, 19, 18, 17, 16, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    size = sizeof(arr3) / sizeof(arr3[0]);
    start = std::chrono::system_clock::now();
    mergesort(arr3, size);
    end = std::chrono::system_clock::now();

    std::cout << "Sorted array of 20 values: ";
    for (int i = 0; i < size; i++)
    
    {
        cout << arr3[i] << " ";
    }
    cout << "Operation count: " << operation_count << "\n";
    operation_count = 0;

    elapsed_seconds = end - start;
    end_time = std::chrono::system_clock::to_time_t(end);

    std::cout << "finished computation at " << std::ctime(&end_time)
              << "elapsed time: " << std::fixed << std::setprecision(6) << elapsed_seconds.count() << "s"
              << std::endl;

    int arr4[] = {50, 49, 48, 47, 46, 45, 44, 43, 42, 41, 40, 39, 38, 37, 36, 35, 34, 33, 32, 31, 30, 29, 28, 27, 26, 25, 24, 23, 22, 21, 20, 19, 18, 17, 16, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    size = sizeof(arr4) / sizeof(arr4[0]);
    start = std::chrono::system_clock::now();
    mergesort(arr4, size);
    end = std::chrono::system_clock::now();

    std::cout << "Sorted array of 50 values: ";
    for (int i = 0; i < size; i++)
    {
        cout << arr4[i] << " ";
    }
    cout << "Operation count: " << operation_count << "\n";
    operation_count = 0;

    elapsed_seconds = end - start;
    end_time = std::chrono::system_clock::to_time_t(end);

    std::cout << "finished computation at " << std::ctime(&end_time)
              << "elapsed time: " << std::fixed << std::setprecision(6) << elapsed_seconds.count() << "s"
              << std::endl;

    return 0;
}

void mergesort(int arr[], int size)
{
    mergesortRecursive(arr, 0, size - 1);
    operation_count++;
}

void mergesortRecursive(int arr[], int l, int r)
{
    if (l < r)
    {
        int m = l + (r - l) / 2;
        operation_count = operation_count + 5;
        mergesortRecursive(arr, l, m);
        mergesortRecursive(arr, m + 1, r);
        operation_count++;
        merge(arr, l, m, r);
    }
}

void merge(int arr[], int left, int middle, int right)
{
    int i, j, k;
    int left_length = middle - left + 1;
    operation_count = operation_count + 3;
    int right_length = right - middle;
    operation_count = operation_count + 2;

    vector<int> temp_left(left_length);
    vector<int> temp_right(right_length);

    for (i = 0; i < left_length; i++)
    {
        temp_left[i] = arr[left + i];
        operation_count += 4;
    }
    for (i = 0; i < right_length; i++)
    {
        temp_right[i] = arr[middle + 1 + i];
        operation_count += 5;
    }

    for (i = 0, j = 0, k = left; k <= right; k++)
    {
        if (i < left_length && (j >= right_length || temp_left[i] <= temp_right[j]))
        {
            arr[k] = temp_left[i];
            i++;
            operation_count += 9;
        }
        else
        {
            arr[k] = temp_right[j];
            j++;
            operation_count += 9;
        }
    }
}
