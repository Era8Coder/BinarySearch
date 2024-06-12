n = int(input())
tgt = int(input())
v = []
for i in range(n):
    x = int(input())
    v.append(x)

def bin_srch(v, tgt):
    low = 0
    high= len(v) - 1
    # mid = (low + high)//2

    while low <= high :
        mid = (low + high)//2
        
        if v[mid] == tgt:
            return True
        elif v[mid] > tgt:
            high = mid - 1
        else:
            low = mid + 1
        
    return False

print(bin_srch(v, tgt))