for _ in range(int(input())):
    i = 1
    n = int(input())
    while n > 1:
        n /= i
        i += 1
    print(max(i-1, 1))