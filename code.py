#1) Функция сортировки пузырьком
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

#2)Сортировка вставками
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

#3)Сортировка Шелла (Shellsort) 
def insertion_sort_gap(arr, start, gap):
    for i in range(start + gap, len(arr), gap):
        temp = arr[i]
        j = i - gap
        while j >= start and arr[j] > temp:
            arr[j + gap] = arr[j]
            j -= gap
        arr[j + gap] = temp

def shell_sort(arr):
    n = len(arr)
    gap = n // 2
    while gap > 0:
        for start in range(gap):
            insertion_sort_gap(arr, start, gap)
        gap //= 2
    return arr

# Пример использования:
array = [12, 34, 54, 2]
sorted_array = shell_sort(array)
print(sorted_array)
#При запуске кода на Python на примере массив [12, 34, 54, 2] получим отсортированный массив [2, 12, 34, 52]

#4)Последовательный (линейный) поиск 
def linear_search(arr, target):
    for index in range(len(arr)):
        if arr[index] == target:
            return index
    return -1

# Создаем список из элементов
numbers = [10, 23, 35, 47, 58, 69, 78, 89, 90]

# Определяем элемент, который ищем
search_element = 58

# Вызов функции поиска
result_index = linear_search(numbers, search_element)

# Вывод результата
if result_index != -1:
    print(f"Элемент {search_element} найден на позиции {result_index}.")
else:
    print(f"Элемент {search_element} не найден в списке.")
#При запуске кода на Python вывело "Элемент 58 найден на позиции 4."

#5)Бинарный (двоичный, дихотомический) поиск
def binary_search(arr, target):
    left = 0
    right = len(arr) - 1
    
    while left <= right:
        mid = (left + right) // 2
        if arr[mid] == target:
            return mid
        elif arr[mid] < target:
            left = mid + 1
        else:
            right = mid - 1
    
    return -1
# Пример использования
if __name__ == "__main__":
    data = [1, 3, 5, 7, 9, 11, 13, 15]
    target_value = 7
    result = binary_search(data, target_value)
    
    if result != -1:
        print(f"Элемент {target_value} найден на позиции {result}")
    else:
        print(f"Элемент {target_value} не найден в списке")

#Вывод: Элемент 7 найден на позиции 3

#6)Поиск по Фибоначчи 
def fibonacci_search(arr, x):
    fib2 = 0
    fib1 = 1
    fib = fib1 + fib2
    n = len(arr)

    while fib < n:
        fib2 = fib1
        fib1 = fib
        fib = fib1 + fib2

    offset = -1

    while fib > 1:
        i = min(offset + fib2, n - 1)
        if arr[i] < x:
            fib = fib1
            fib1 = fib2
            fib2 = fib - fib1
            offset = i
        elif arr[i] > x:
            fib = fib2
            fib1 = fib1 - fib2
            fib2 = fib - fib1
        else:
            return i

    if fib1 and offset + 1 < n and arr[offset + 1] == x:
        return offset + 1

    return -1

arr = [10, 22, 35, 40, 45, 50, 80, 82, 85, 90, 100]
x = 85
result = fibonacci_search(arr, x)
if result != -1:
    print(f"Элемент найден на индексе: {result}")
else:
    print("Элемент не найден в массиве")

#Вывод: Элемент найден на индексе: 8
