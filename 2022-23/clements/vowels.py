vowels = ['A', 'P', 'L', 'U', 'S']

n = int(input())

for _ in range(n): 
    s = input()
    if (s[-1] in vowels and s[-2] in vowels and s[-3] in vowels):
        m = 0
        for i in range(len(s)-1, -1, -1):
            if (s[i] not in vowels):
                m = i+1
                break;
        print(s[0:m] + s[m+1:] + "Y")

    elif (s[-1] not in vowels and s[-2] not in vowels and s[-3] not in vowels):
        m = 0
        for i in range(len(s)-1, -1, -1):
            if (s[i] in vowels):
                m = i+1
                break;
        print(s[0:m] + s[m+1:] + "Y")
            
    elif (s[-1] in vowels and s[-2] in vowels) or (s[-1] not in vowels and s[-2] not in vowels):
        print(s + s[-1] + "Y")
    elif s[-1] in vowels:
        print(s[:-1]+"X")
    else:
        print(s+"XY")
        