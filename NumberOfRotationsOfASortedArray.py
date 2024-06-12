m = int(input("Enter the Size of Array:-> "))
arr = []
for _ in range(m):
    x = int(input())
    arr.append(x)

def count_rotations(arr):
    n = len(arr)
    low = 0
    high= n - 1

    if arr[low] <= arr[high]:
        return 0                        # Answer is the First Index Only -> Array is Sorted
    
    while low <= high:
        mid = low + (high - low)//2
        prev= (mid + n - 1)%n
        next= (mid + 1)%n

        if arr[mid] <= arr[prev] and arr[mid] <= arr[next]:
            return mid
        elif arr[mid] <= arr[high]:
            high = mid - 1
        elif arr[mid] >= arr[0]:
            low  = mid + 1

    return -1

print(count_rotations(arr)) 