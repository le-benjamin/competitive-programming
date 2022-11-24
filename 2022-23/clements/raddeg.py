import math
nums = list(map(float, input().split()))

for n in nums:
    if n == n//1:
        print(f"{int(n)} degrees = {'{:.2f}'.format(n*math.pi/180)} radians")
    else:
        print(f"{'{:.2f}'.format(n)} radians = {int(round(n*180/math.pi))} degrees")