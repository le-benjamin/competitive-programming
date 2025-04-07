for _ in range(int(input())):
    a = list(map(float, input().split(" ")))
    b = list(map(float, input().split(" ")))
    c = []
    ans = 0


    for x in range(0, len(a)):
        if a[x]>=0.60 and a[x]<=0.85 and b[x]>=0.60 and b[x]<=0.85:
            ans += 1
            c.append(x)
    
    if ans > 1:
        print(str(ans) + " multipaction events were detected at time indices: " + (" ".join([str(x) for x in c])) + ".")
    elif ans == 1:
        print("A multipaction event was detected at time index " + str(c[0]) + ".")
    else:
        print("No multipaction events detected.")