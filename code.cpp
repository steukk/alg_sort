//1)Сортировка выбором
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


//2)Сортировка слиянием 
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

//3)Сортировка слиянием
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

//4)Быстрая сортировка
#include <iostream>
#include <vector>

int partition(std::vector<int>& arr, int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; ++j) {
        if (arr[j] < pivot) {
            ++i;
            std::swap(arr[i], arr[j]);
        }
    }
    std::swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort(std::vector<int>& arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    std::vector<int> data = {10, 7, 8, 9, 1, 5};
    quickSort(data, 0, data.size() - 1);
    for (int num : data) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
    return 0;
}
//При запуске кода на C++ на примере массив [10, 7, 8, 9, 1, 5], получим отсортированный массив [1, 7, 8, 9, 10]

//5)Пирамидальная сортировка
#include <iostream>
#include <vector>

void heapify(std::vector<int>& arr, int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i) {
        std::swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

void heapSort(std::vector<int>& arr) {
    int n = arr.size();

    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    for (int i = n - 1; i > 0; i--) {
        std::swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

int main() {
    std::vector<int> arr = {12, 11, 13, 5, 6, 7};

    heapSort(arr);

    for (int i = 0; i < arr.size(); i++)
        std::cout << arr[i] << " ";
    std::cout << std::endl;

    return 0;
}

//При запуске кода на C++ на примере массив [12, 11, 13, 5, 6, 7], получим отсортированный массив [5, 6, 7, 11, 12, 13]
