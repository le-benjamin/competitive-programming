tc = int(input())
for _ in range(tc):
    a, w = map(int, input().split())
    for i in range(w):
        s = input()
        sum = 0
        for c in s:
            # print(ord(c)-ord('A'), end=' ')
            sum += ((ord(c)-ord('A')+a))
            if (ord(c)-ord('A')+a) > 26: sum -= 26
        if sum == 100:
            print(f"WINNER {a}: {s}")