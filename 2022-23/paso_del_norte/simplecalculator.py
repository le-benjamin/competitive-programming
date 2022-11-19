for _ in range(int(input())):
    a, b = list(map(int, input().split()))
    s = f'{"{:.2f}".format(a/b)}'
    if s[0] == '0': s = s[1:]
    print(f'{a+b} {a*b} {a-b} {s}')