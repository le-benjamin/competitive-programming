def getColor(theta):
    theta %= 360
    if theta < 90: return "GREEN"
    if theta < 180: return "RED"
    if theta < 270: return "YELLOW"
    return "BLUE"

for _ in range(int(input())):
    d, s, c = input().split()
    
    if s == "FAST": s = .4
    elif s == "MEDIUM_FAST": s = .7
    elif s == "MEDIUM": s = .3
    elif s == "MEDIUM_SLOW": s = .125
    else: s = .5
        
    if c == "GREEN": c = 45
    elif c == "RED": c = 135
    elif c == "YELLOW": c = 225
    else: c = 315
        
    if d == "CL":
        print(getColor(c+360*s))
    else:
        print(getColor(c+360-360*s))
        