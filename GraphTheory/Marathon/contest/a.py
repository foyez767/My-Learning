
tc = int(input())

while tc:
    n, m = map(int, input().split())
    a = input()
    b = input()
    
    i, j, k = 0, 0, 0
    
    for j in range (m):
        if (i >= n):
            break;
        
        if (a[i] == b[j]):
            k += 1
            i += 1
        
        j += 1
            
    print(f"{k}")
    tc -= 1