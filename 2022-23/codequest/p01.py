n = int(input())
for _ in range(n):
    a = input().split()
    for i in range(len(a)):
        if a[i] == "Nimo":
            print(i+1)