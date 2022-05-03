n = int(input())
vowels = ['a', 'e', 'i', 'o', 'u']

for _ in range(n):
    out = ""
    s = input()
    i = 1
    while i < len(s):
        if s[i-1] in vowels:
            out += s[i]
            i += 1
        i += 1
    print(out)