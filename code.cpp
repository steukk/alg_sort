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
