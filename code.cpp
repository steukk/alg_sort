//Сортировка выбором
#include <iostream>
using namespace std;

void printArray(int arr[], int size) {
	for (int i = 0; i < size; i++) {
    	cout << arr[i] << " ";
	}
	cout << endl;
}
void selectionSort(int arr[], int n) {

	for (int i = 0; i < n - 1; ++i) { 	
    	int minIndex = i;
    	for (int j = i + 1; j < n; ++j) {
        	if (arr[j] < arr[minIndex]) {   
            	minIndex = j;           	
        	}
    	}
    	swap(arr[i], arr[minIndex]);   
	}
}
int main() {
	int arr[] = {64, 25, 12, 22, 11};
	int n = sizeof(arr)/sizeof(arr[0]);
	cout << "Исходный массив:\n";
	printArray(arr, n);
	selectionSort(arr, n);             
	cout << "\nОтсортированный массив:\n";
	printArray(arr, n);

	return 0;
}
//При запуске кода на C++ на примере массив [64, 25, 12, 22, 11], получим отсортированный массив [11, 12, 22, 25, 64]


//Сортировка слиянием 
#include <iostream>
#include <vector>

void insertion_sort(std::vector<int>& arr) {
    int n = arr.size();
    for (int i = 1; i < n; ++i) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            --j;
        }
        arr[j + 1] = key;
    }
}

int main() {
    std::vector<int> arr = {12, 11, 13, 5, 6};
    insertion_sort(arr);
    for (int num : arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
    return 0;
}
//При запуске кода на C++ на примере массив [12, 11, 13, 5, 6], получим отсортированный массив [5, 6, 11, 12, 13] 

//Сортировка слиянием
#include <iostream>
#include <vector>

void merge(std::vector<int>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    std::vector<int> L(n1), R(n2);
    for (int i = 0; i < n1; ++i) L[i] = arr[left + i];
    for (int j = 0; j < n2; ++j) R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) arr[k++] = L[i++];
        else arr[k++] = R[j++];
    }
    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];
}

void merge_sort(std::vector<int>& arr, int left, int right) {
    if (left >= right) return;
    int mid = left + (right - left) / 2;
    merge_sort(arr, left, mid);
    merge_sort(arr, mid + 1, right);
    merge(arr, left, mid, right);
}

int main() {
    std::vector<int> arr = {12, 11, 13, 5, 6, 7};
    merge_sort(arr, 0, arr.size() - 1);
    for (int num : arr) std::cout << num << " ";
    std::cout << std::endl;
    return 0;
}
//При запуске кода на C++ на примере массив [12, 11, 13, 5, 6, 7], получим отсортированный массив [5, 6, 7, 11, 12, 13] 
