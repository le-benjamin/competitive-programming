tc = int(input())
for _ in range(tc):
    c, t = map(int, input().split())
    m = {}
    for i in range(c):
        name, num = input().split()
        num = int(num)
        m[name] = num
    for i in range(t):
        name, op, num = input().split()
        num = int(num)
        if op == '+':
            print("YES")
            m[name] += num
        elif op == '-':
            if num > m[name]:
                print("NO")
            else:
                print("YES")
                m[name] -= num