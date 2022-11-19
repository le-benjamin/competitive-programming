for _ in range(int(input())):
    a, b = list(map(eval, input().split(" = ")))
    print(str(a==b).lower())