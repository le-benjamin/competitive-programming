n = int(input())

d = {'A':'0', 'T':'0', 'G':'1', 'C':'1'}

for _ in range(n):
    s = "".join(list(map(lambda a:d[a], input())))
    
    for i in range(0, len(s)-6, 7):
        print(chr(int(s[i:i+7], 2)), end="");
    print()