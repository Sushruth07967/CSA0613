def binary_search(arr, key):
    low = 0
    high = len(arr) - 1

    while low <= high:
        mid = low + (high - low) // 2

        if arr[mid] == key:
            return mid
        elif arr[mid] < key:
            low = mid + 1
        else:
            high = mid - 1

    return -1


arr = [5, 10, 15, 20, 25, 30, 35]
key = 25

result = binary_search(arr, key)

if result != -1:
    print("Element found at index", result)
else:
    print("Element not found")