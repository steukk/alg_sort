# Функция сортировки пузырьком
def bubble_sort(arr): 
    n = len(arr)      
    for i in range(n):
        for j in range(0, n - i - 1):
            if arr[j] > arr[j + 1]:
                arr[j], arr[j + 1] = arr[j + 1], arr[j]

arr = [64, 34, 25, 12, 22, 11, 90]  
print("Исходный массив:", arr)
bubble_sort(arr)  
print("Отсортированный массив:", arr)
#При запуске кода на python на примере массив [64, 34, 25, 12, 22, 11, 90], получим отсортированный массив  [11, 12, 22, 25, 34, 64, 90].

#Сортировка вставками
def insertion_sort(arr):
	for i in range(1, len(arr)):
    	key = arr[i]  
    	j = i - 1  
    	while j >= 0 and arr[j] > key:
        	arr[j + 1] = arr[j] 
        	j -= 1  
    	arr[j + 1] = key
	return arr
# Пример использования:
array = [5, 3, 8, 4, 2]
print("Исходный массив:", array)
sorted_array = insertion_sort(array)
print("Отсортированный массив:", sorted_array)

#При запуске кода на Python на примере массив [5, 3, 8, 4, 2] получим отсортированный массив [2, 3, 4, 5, 8]
